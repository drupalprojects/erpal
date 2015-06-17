<?php

/**
 * Erpal CRM Lead Report
 *
 * creates a report comparing activities in progress and activites completed
 *
 * contrator_id => the contractor id (_erpal_basic_helper_get_own_company_nid(FALSE))
 * date_from => unix timestamp
 * date_to => unix timestamp
 * scaling => monthly or year
 * activities => list of activity terms
 * dim_customercategory => add customer category dimension
 * no_cache => ignore caching
 *
 * @author Manuel Pistner
 */
class ErpalCrmReportsLead {
  /**
   * create data for crm lead report, returns false if no
   * data available
   *
   * @param array $options
   * @return mixed
   */
  static function create($options = array()) {
    // flag for no result, if TRUE, query has no value (e.g. selected customer group has no customer)
    $noresult = FALSE;

    $options = array_merge(self::defaults(), $options);
    $query = self::getActivitiesQuery($options);
    $result = $query->execute();
    
    $data = array();
    $details = array();

    while ($row = $result->fetchAssoc()) {      
      $series_title = t('CRM activities');
      $node_base = erpal_lib_helper_node_base_data(array($row['nid']), true);
    
      $node_base = $node_base[$row['nid']];
      
      
      if (!empty($options['dim_activity_status'])) {
        //get the term name of the activity status
        $term_name = taxonomy_term_load($row['field_activity_status_term_tid']);
        $series_title = $term_name->name;
      }
      
      self::addEntryToResult($node_base, $options, $data, $series_title, $row['timestamp'], $details);
    }    

    //build extended report data
    $report_data = array(
      'data' => $data,
      'extended' => array(), //not yet needed
      'details' => $details,
      'options' => $options,
      'class_name' => self::class_name(),
    );
    
    self::save_report($report_data, $options);
    
    return $report_data;

  }

  static function save_report($report_data, $options) {    
    erpal_reports_save_report_final(self::report_type(), self::class_name(), $report_data, $options);
  }
  
  /**
   * add entry to result data
   *
   * @param array options
   * @param array data
   * @param string series_title
   * @param integer node_date
   * @param array details
   */
  private static function addEntryToResult($node, $options, &$data, $series_title, $node_date, &$details) {
    if ($options['date_from'] > 0 && $options['date_from'] > $node_date) {
      return;
    }

    if ($options['date_to'] > 0 && $options['date_to'] < $node_date) {
      return;
    }

    $date = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $node_date);

    if (empty($data[$series_title])) {
      $data[$series_title] = array ();
      $details[$series_title] = array ();
    }

    if (empty($data[$series_title][$date])) {
      $data[$series_title][$date] = 0;
      $details[$series_title][$date] = array();
    }

    $data[$series_title][$date]++;
    $details[$series_title][$date][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $date, 'value' => 1);
  }

  /**
   * get default options for crm lead report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
      'contrator_id' => _erpal_basic_helper_get_own_company_nid(FALSE),
      'date_from' => - 1,
      'date_to' => - 1,
      'scaling' => ERPAL_REPORT_DATE_SCALING_MONTH,
      'activity_status' => array (),
      'dim_activity_status' => FALSE,
      'no_cache' => FALSE
    );
  }

  /**
   * load cached erpal report object for crm lead report from database
   * if none available or dirty, new object is created and stored
   *
   * @param array $options
   * @return array
   */
  static function load($options = array(), $skip_create=false) {
    $options = array_merge(self::defaults(), $options);
    $report_type = self::report_type();
    $class_name = self::class_name();
   
    $entity = erpal_reports_get_report_entity($report_type, $options, $class_name);

    if (!empty($entity) && !$options['no_cache']) {
      $retval = erpal_reports_prepare_output($entity);        
      return $retval;
    }

    //generate the report data, this can implement a bulk operation
    if (!$skip_create) {             
      $report_data = erpal_reports_create_report_data($report_type, $options, $class_name); 
 
      return $report_data;
    }       
  }

  /**
   * returns all activities with respect to the filter
   *
   * @return array of 
   */
  static function getActivitiesQuery($options) {
    $query = new EntityFieldQuery();
    //We want to get all activities by status. We want them with the date when the status appeared first. Therefore we need to query the
    //the revisions of the status field, group it by status and entity id and order by changed date of the node revision table
    $query = db_select('node_revision', 'nr')
      ->fields('activity_status', array('field_activity_status_term_tid'))
      ->fields('nr', array('timestamp'))
      ->fields('nr', array('nid'));
    
    $query->leftjoin('field_revision_field_activity_status_term', 'activity_status', 'activity_status.revision_id=nr.vid');
      
    $query->condition('activity_status.entity_type', 'node')
      ->groupBy('nr.nid')
      ->groupBy('activity_status.field_activity_status_term_tid')
      ->orderBy('nr.timestamp', 'ASC');

    
    if ($options['activity_status']) {
      $query->condition('activity_status.field_activity_status_term_tid', $options['activity_status']);
    }
    
    if ($options['date_from'] > 0) {
      $query->condition('nr.timestamp', $options['date_from'], '>=');
    }
    
    if ($options['date_to'] > 0) {
      $query->condition('nr.timestamp', $options['date_to'], '<=');
    }

    return $query;
    
  }
  
    /**
   * create list of process status tids from activity status term taxonomy
   * ATTENTION: This function is also needed by other classes
   *
   * @param array $tid_aborted
   * @param array $tid_in_progress
   * @param array $tid_completed
   */
  static function taxonomyIdlistCreate() {
    $taxonomy = taxonomy_vocabulary_machine_name_load('activity_status_terms');

    foreach(taxonomy_get_tree($taxonomy->vid) as $term) {
      $term_dataset = taxonomy_term_load($term->tid);
      $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term_dataset);
      $process_status = $term_wrapper->field_simple_process_status->value();
      switch($process_status) {
        case 'aborted':
          $tid_aborted[] = $term_wrapper->tid->value();
          break;
        case 'in_progress':
          $tid_in_progress[] = $term_wrapper->tid->value();
          break;
        case 'completed':
          $tid_completed[] = $term_wrapper->tid->value();
          break;
      }
    }

    return array('aborted' => $tid_aborted, 'in_progress' => $tid_in_progress, 'completed' => $tid_completed);
  }
  
  /**
   * create entity field query for crm activity selection
   * ATTENTION: This function is also needed by other classes
   *
   * @param array $options
   * @param array $tidList
   * @return EntityFieldQuery
   */
  static function entityFieldQueryCreate($options) {
    $query = new EntityFieldQuery();
    // need to add pseudo condition for created and changed for hook_TAG_alter to work correctly
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'erpal_crm_activity')
      ->propertyCondition('created', time(), '<=')
      ->propertyCondition('changed', time(), '<=')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.;

    if (count($options ['activities']) > 0) {
      $query->fieldCondition('field_activity_status_term', 'tid', $options['activities'], 'IN');
    }

    if (count($options ['customers']) > 0) {
      $query->fieldCondition('field_customer_ref', 'target_id', $options ['customers'], 'IN');
    }

    if ($options ['date_from'] > - 1) {
      $query->addTag('dateregion');
      $query->addMetaData('date_from', $options ['date_from']);
    }

    if ($options ['date_to'] > - 1) {
      $query->addTag('dateregion');
      $query->addMetaData('date_to', $options ['date_to']);
    }

    return $query;
  }
  
  static function report_type() {
    return 'erpal_crm_lead_reports';
  }
  
  static function class_name() {
    return 'ErpalCrmReportsLead';
  }

  /**
  * Return this report's title
  */
  static function report_title() {
    return t('CRM Lead Report');
  }
}
