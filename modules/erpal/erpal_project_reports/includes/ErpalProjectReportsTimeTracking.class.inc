<?php

/**
 * Erpal Project Time Tracking Report
 *
 * creates a scaled time tracking report with the following options:
 *
 * projects => list of projects
 * customers => list of customers
 * customer_categories => list of customer categories
 * service_categories => list of service categories
 * users => list of users
 * dim_project => add project dimension
 * dim_customer => add customer dimension
 * dim_customercategory => add customer category dimension
 * dim_servicecategory => add service category dimension
 * dim_user => add user dimension
 * no_cache => ignore caching
 *
 * @author Manuel Pistner
 */
class ErpalProjectReportsTimeTracking {
  /**
   * create data for project report, returns false if no
   * data available
   *
   * @param array $options
   * @return mixed
   */
  static function create($options = array()) {
    $options = array_merge(self::defaults(), $options);

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'erpal_task')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.

    $noresult = FALSE;

    $has_project_subquery = FALSE;
    $subquery_projects = array();

    if (!empty($options['status']) || !empty($options['profit_status'])) {  //filter in projects with the selected status
      $query_project = new EntityFieldQuery();
      $query_project->entityCondition('entity_type', 'node')->entityCondition('bundle', 'erpal_project');      
      $query_project->addMetaData('account', user_load(1)); // Run the query as user 1.
      
      if (!empty($options['status'])) {
        $query_project->fieldCondition('field_project_status_term', 'tid', $options['status'], 'IN');
      }
      
      $result = $query_project->execute();

      //check if we want to group by profitable or none profitable projects
      $project_nids = array();
      if (!empty($options['profit_status'])) {
        foreach ($result['node'] as $project_nid=>$query_data) {
          $margin_options = array('projects' => array($project_nid), 'no_cache' => FALSE);
          
          $profit_margin_report = ErpalProjectReportsProfitMargin::load($margin_options, true);
          
          if (!$profit_margin_report || empty($profit_margin_report['details']))
            continue;

          $profit_status = $options['profit_status'];          
          $profit_treshold = intval($options['profit_treshold']);
          $profit_arr = (array)$profit_margin_report['details']; //profit in percent
          $profit_arr = reset($profit_arr);

          $profit = $profit_arr->profit->profit_percent; 

          if ($profit_status == 'profitable') {
            if ($profit >= $profit_treshold) {              
              $project_nids[$project_nid] = $project_nid;
            }
          } elseif ($profit_status ==  'non_profitable') {            
            if ($profit < $profit_treshold) {              
              $project_nids[$project_nid] = $project_nid;
            }
          }
        }
      }
          
      if (count($project_nids) > 0) {
        $has_project_subquery = TRUE;
        $subquery_projects = $project_nids;
      } else {
        $noresult = TRUE;
      }
    }

    //set the date range for the timetracking bookings
    $date_from = !empty($options['date_from']) ? $options['date_from'] : false;
    $date_till = !empty($options['date_till']) ? $options['date_till'] : false;
    
    // categories: field_project_tags
    if (count($options['task_categories']) > 0) {
      $query->fieldCondition('field_project_tags', 'tid', $options ['task_categories'], 'IN');
    }

    // project: field_project_ref
    if (count($options['projects']) > 0) {
      $subquery_projects = count($subquery_projects) == 0 ? $options ['projects'] : array_intersect($subquery_projects, $options ['projects']);
    }

    if (count($subquery_projects)) {
      $query->fieldCondition('field_project_ref', 'target_id', $subquery_projects, 'IN');
    }

    $result = $query->execute();
    
    if (!isset($result ['node']) || count($result ['node']) == 0) {
      $noresult = TRUE;
    }

    $data = array();
    $details = array();
    if (!$noresult) {
      $nids = array_keys($result ['node']);
      $nids_processed = array();
      if (!empty($options['use_batch'])) {
        $batch_variables = array(
          'ids' => $nids,
          'options' => $options,
          'nids_processed' => &$nids_processed,
          'data' => &$data,
          'extended' => &$extended,
          'details' => &$details,
          'class' => self::class_name(),
          'process_callback' => 'process_item_batch',
          'finish_callback' => 'finalize_report_save',
        );                        
        erpal_reports_batch_start($batch_variables);        
      } else {           
        foreach($nids as $nid) {            
          self::process_item($nid, $options, $nids_processed, $data, $details, $extended);
        }        
        $report = self::finalize_report($options, $data, $details, $extended, false);        
        return $report;
      }
    } else {
      $data = FALSE;
    }
  }
  
  /**
  * Callback to process the report with a batch process
  */
  static function process_item_batch(&$context) {
    
    $ids = $context['sandbox']['variables']['ids'];
    $start = $context['start'];
    $length = $context['length'];

    for ($i = $start; $i < $start + $length; $i++) {
      if (empty($ids[$i]))
        return;  //no more elements are available
        
      $nid = $ids[$i];
      $data = &$context['sandbox']['variables']['data'];
      $details = &$context['sandbox']['variables']['details'];
      $extended = &$context['sandbox']['variables']['extended'];
      $options = $context['sandbox']['variables']['options'];
      $nids_processed = &$context['sandbox']['variables']['nids_processed']; 
    
      if (empty($context['sandbox']['processed_nids']))
        $context['sandbox']['processed_nids'] = array();
              
      if (empty($context['sandbox']['processed_nids'][$nid])) {        
        self::process_item($nid, $options, $nids_processed, $data, $details, $extended);
      }
        
      $context['sandbox']['processed_nids'][$nid] = TRUE; //avoid adding duplicate items
    }
  }
  
  /**
  * This is the function that processes one item  for the report
  */
  static function process_item($nid, $options, &$billable_ids_processed, &$data, &$details, &$extended) {
    $node = node_load($nid);
    $node_wrapper = entity_metadata_wrapper('node', $node);
    
    $date_from = $options['date_from'];
    $date_till = $options['date_till'];
    
    $tag = $node_wrapper->field_project_tags->value();

    if ($tag != NULL) {
      $tag_name = $tag->name;
    } else {
      $tag_name = t('No Category');
    }

    $field_date = $node_wrapper->field_date->value();
    $field_project = $node_wrapper->field_project_ref->value();

    $series_estimated_title = t("Estimated");
    $series_duration_title = t("Duration");
    $series_addon = array();

    if ($options['dim_project'] == TRUE) {
      $series_addon[] = $field_project->title;
    }

    if (count($series_addon) > 0){
      $series_estimated_title .= sprintf(' - %s', implode(', ', $series_addon));
      $series_duration_title .= sprintf(' - %s', implode(', ', $series_addon));
    }

    if (empty($data[$series_estimated_title])) {
      $data[$series_estimated_title] = array();
      $details[$series_estimated_title] = array ();
    }

    if (empty($data[$series_estimated_title][$tag_name])) {
      $data[$series_estimated_title][$tag_name] = 0;
      $details[$series_estimated_title][$tag_name] = array();
    }

    if (empty($data[$series_duration_title])) {
      $data[$series_duration_title] = array();
      $details[$series_duration_title] = array();
    }

    if (empty($data[$series_duration_title][$tag_name])) {
      $data[$series_duration_title][$tag_name] = 0;
      $details[$series_duration_title][$tag_name] = array();
    }

    $time_information = _erpal_projects_helper_direct_time_information($node->nid, false, $date_from, $date_till);        
    
    $estimated_time = $time_information['estimation'];
    $total_time = $time_information['summed_time'];
    
    $data[$series_estimated_title][$tag_name] += $estimated_time;
    $data[$series_duration_title][$tag_name] += $total_time;
    
    $details[$series_duration_title][$tag_name][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $tag_name, 'value' => $total_time);
    
    $details[$series_estimated_title][$tag_name][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $tag_name, 'value' => $estimated_time);
    
  }
  
  static function finalize_report_save($options, $data, $details, $extended=array()) {     
    self::finalize_report($options, $data, $details, $extended, FALSE);    
  }
  
  static function finalize_report($options, $data, $details, $extended, $skipp_save_report = FALSE) {
    //add profit for each project
   
    //build extended report data
    $report_data = array(
      'data' => $data,
      'extended' => array(),
      'details' => $details,
      'options' => $options,
      'class_name' => self::class_name(),
    );

    if (!$skipp_save_report) {       
      //may be get an existing entity               
      self::save_report($report_data, $options);      
    } 

    return $report_data;
  }

  
  /**
   * get default options for project time tracking report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
        'task_categories' => array(),
        'projects' => array(),
        'customers' => array (),
        'customer_categories' => array (),
        'users' => array(),
        'dim_project' => FALSE,
        'dim_customer' => FALSE,
        'dim_customercategory' => FALSE,
        'dim_user' => FALSE,
        'no_cache' => FALSE
    );
  }

  /**
   * load cached erpal report object for project time tracking report from database
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
  
  static function save_report($report_data, $options) {
    erpal_reports_save_report_final(self::report_type(), self::class_name(), $report_data, $options);
  }
  
  static function report_type() {
    return 'erpal_project_timetracking_reports';
  }
  
  static function class_name() {
    return 'ErpalProjectReportsTimeTracking';
  }
  
  /**
  * Return this report's title
  */
  static function report_title() {
    return t('Project timetracking report');
  }
}
