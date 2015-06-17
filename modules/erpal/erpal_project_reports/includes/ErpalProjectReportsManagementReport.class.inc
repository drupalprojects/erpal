<?php

/**
 * Erpal Project Time Tracking Report
 *
 * creates project management report with the following options:
 *
 * projects => list of projects
 * no_cache => ignore caching
 *
 * @author Yann Karl
 */
class ErpalProjectReportsManagementReport {
  /**
   * create data for project management report, returns false if no
   * data available
   *
   * @param array $options
   * @return mixed
   */
  static function create($options = array()) {
    $taxonomy_idlist = self::taskStatusTaxonomyIdlistCreate();

    $options = array_merge(self::defaults(), $options);

    $details = array();
    $retval = array('open' => 0, 'overdue' => 0, 'not_assigned' => 0, 'no_time_estimate' => 0);

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')->entityCondition('bundle', 'erpal_task');
    $query->fieldCondition('field_task_status_term', 'tid', $taxonomy_idlist['in_progress'], 'IN');
    $query->addMetaData('account', user_load(1)); // Run the query as user 1.

    if (count($options ['projects']) > 0) {
      $query->fieldCondition('field_project_ref', 'target_id', $options ['projects'], 'IN');
    }

    $retval['open'] = (int)($query->count()->execute());

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')->entityCondition('bundle', 'erpal_task');
    $query->fieldCondition('field_task_status_term', 'tid', $taxonomy_idlist['in_progress'], 'IN');
    $query->fieldCondition('field_date', 'value', sprintf('%s, 23:59:59', date(DATE_FORMAT_DATE, time())), '<=');
    $query->addMetaData('account', user_load(1)); // Run the query as user 1.

    if (count($options ['projects']) > 0) {
      $query->fieldCondition('field_project_ref', 'target_id', $options ['projects'], 'IN');
    }

    $retval['overdue'] = (int)($query->count()->execute());

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')->entityCondition('bundle', 'erpal_task');
    $query->addTag('filter_task_no_assigned_users');
    $query->addMetaData('account', user_load(1)); // Run the query as user 1.

    if (count($options ['projects']) > 0) {
      $query->addTag('filter_projects');
      $query->addMetaData('projects', $options ['projects']);
    }

    $retval['not_assigned'] = (int)($query->count()->execute());

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')->entityCondition('bundle', 'erpal_task');
    $query->addTag('filter_task_no_estimated_time');
    $query->addMetaData('account', user_load(1)); // Run the query as user 1.
    
    if (count($options ['projects']) > 0) {
      $query->addTag('filter_projects');
      $query->addMetaData('projects', $options['projects']);
    }

    $retval['no_time_estimate'] = (int)($query->count()->execute());
    $retval['data'] = array();  
    $retval['details'] = array();      
    
    //build extended report data
    $report_data = array(
      'data' => $retval,
      'extended' => array(), //Not yet needed
      'details' => array(),
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
   * get default options for project management report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
      'projects' => array(),
      'no_cache' => FALSE
    );
  }

  /**
   * load cached erpal report object for project management report from database
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
   * create list of task status tids from task status term taxonomy
   *
   * @param array $tid_aborted
   * @param array $tid_in_progress
   * @param array $tid_completed
   */
  static function taskStatusTaxonomyIdlistCreate() {
    $taxonomy = taxonomy_vocabulary_machine_name_load('task_status_terms');

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
  
  static function report_type() {
    return 'erpal_project_management_reports';
  }
  
  static function class_name() {
    return 'ErpalProjectReportsManagementReport';
  }
  
  /**
  * Return this report's title
  */
  static function report_title() {
    return t('Projects overview');
  }
}

