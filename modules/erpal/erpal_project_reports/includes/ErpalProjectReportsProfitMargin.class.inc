<?php

/**
 * Erpal Project Profit Margin Report
 *
 * creates a scaled profit margin report with the following options:
 *
 * date_from => unix timestamp
 * date_to => unix timestamp
 * scaling => monthly or year
 * projects => list of projects
 * customers => list of customers
 * customer_categories => list of customer categories
 * service_categories => list of service categories
 * users => list of users
 * status => list of project status term id to filter for
 * dim_project => add project dimension
 * dim_customer => add customer dimension
 * dim_customercategory => add customer category dimension
 * dim_servicecategory => add service category dimension
 * dim_user => add user dimension
 * no_cache => ignore caching
 *
 * @author Yann Karl
 */
class ErpalProjectReportsProfitMargin {
  /**
   * create data for project report, returns false if no
   * data available
   *
   * @param array $options
   * @return mixed
   */
  static function create($options = array()) {
    $options = array_merge(self::defaults(), $options);

    $profit_title = t('Real profit');
    $revenue_title = t('Real revenue');
    $expense_title = t('Real expenses');
    
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'erpal_task')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.;

    $noresult = FALSE;

    $has_project_subquery = FALSE;
    $subquery_projects = array();

    if (count($options['customers']) > 0 || $options['status'] || !empty($options['profit_status'])) {
      $query_project = new EntityFieldQuery();
      $query_project->entityCondition('entity_type', 'node')->entityCondition('bundle', 'erpal_project');      
      $query_project->addMetaData('account', user_load(1)); // Run the query as user 1.
      
      if (!empty($options['customers'])) {
        $query_project->fieldCondition('field_customer_ref', 'target_id', $options ['customers'], 'IN');
      }
      
      if (count($options['status']) > 0) {    
        $query_project->fieldCondition('field_project_status_term', 'tid', $options['status'], 'IN');
      }
      
      //if profit status is select, we need to filter later by this option, this is why we need the projects here
      
      $result = $query_project->execute();

      if (count($result) > 0) {
        $has_project_subquery = TRUE;
        $subquery_projects = array_keys($result ['node']);
      } else {
        $noresult = TRUE;
      }
    }

    if (count($options['customer_categories']) > 0) {
      $query_group = new EntityFieldQuery();
      $query_group->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'erpal_contact')
        ->fieldCondition('field_customer_category', 'value', $options ['customer_categories'], 'IN')
        ->addMetaData('account', user_load(1)); // Run the query as user 1.;

      $result = $query_group->execute();

      if (count($result) > 0) {
        $query_project = new EntityFieldQuery();
        $query_project->entityCondition('entity_type', 'node')->entityCondition('bundle', 'erpal_project');
        $query_project->fieldCondition('field_customer_ref', 'target_id', array_keys($result['node']), 'IN');

        $result = $query_project->execute();

        if (count($result) > 0) {
          $has_project_subquery = TRUE;

          $subquery_projects = count($subquery_projects) == 0 ? array_keys($result ['node']) : array_intersect($subquery_projects, array_keys($result ['node']));
        } else {
          $noresult = TRUE;
        }
      } else {
        $noresult = TRUE;
      }
    }

    // @TODO: if user filter is set, filter user by task, not project
    // users: field_task_assigned_users
    if (count($options ['users']) > 0) {
      $query->fieldCondition('field_task_assigned_users', 'target_id', $options['users'], 'IN');
    }
    
    // project: field_project_ref
    if (count($options ['projects']) > 0) {
      $subquery_projects = count($subquery_projects) == 0 ? $options ['projects'] : array_intersect($subquery_projects, $options ['projects']);
    }

    if (count($subquery_projects)) {
      $query->fieldCondition('field_project_ref', 'target_id', $subquery_projects, 'IN');
    }

    $result = $query->execute();
    $data = array();
    $details = array();
    if (!isset($result ['node']) || count($result ['node']) == 0) {
      $noresult = TRUE;      
    }
    
    $project_nids_processed = array();
    if (empty($noresult)) {
      $nids = array_keys($result['node']);
      $options['config_options']['revenue_title'] = $revenue_title;
      $options['config_options']['expense_title'] = $expense_title;
      $options['config_options']['profit_title'] = $profit_title;
            
      if (!empty($options['use_batch'])) {        
        $batch_variables = array(
          'ids' => $nids,
          'options' => $options,
          'project_nids_processed' => &$project_nids_processed,
          'data' => &$data,
          'details' => &$details,
          'class' => 'ErpalProjectReportsProfitMargin',
          'process_callback' => 'process_item_batch',
          'finish_callback' => 'finalize_report_save',
        );                        
        erpal_reports_batch_start($batch_variables);        
      } else {           
        foreach($nids as $nid) {            
          self::process_item($nid, $options, $project_nids_processed, $data, $details);
        }        
        $report = self::finalize_report($options, $data, $details, false);        
        return $report;
      }

    }
    return false;
  }
  
  static function finalize_report_save($options, $data, $details) {     
    self::finalize_report($options, $data, $details, FALSE);    
  }
  
  static function finalize_report($options, $data, $details, $skipp_save_report = FALSE) {
    //add profit for each project
    $revenue_title = $options['config_options']['revenue_title'];
    $expense_title = $options['config_options']['expense_title'];
    $profit_title = $options['config_options']['profit_title'];
    
    foreach ($data as $project_title => $sub_data) {
      $revenue = !empty($sub_data[$revenue_title]) ? $sub_data[$revenue_title] : 0;
      $expense = !empty($sub_data[$expense_title]) ? $sub_data[$expense_title] : 0;
      $profit = $revenue - $expense;
      $profit_percent = !empty($revenue) ? round(($profit / $revenue) * 100, 2) : 0;
      
      //should we filter by profit status?
      $profit_status = !empty($options['profit_status']) ? $options['profit_status'] : false;
      $profit_treshold = !empty($options['profit_treshold']) ? $options['profit_treshold'] : 0;
      $add_data = false;
      if ($profit_status == 'profitable') {
        if ($profit_percent >= $profit_treshold) {              
          $add_data = true;
        }
      } elseif ($profit_status ==  'non_profitable') {            
        if ($profit_percent < $profit_treshold) {              
          $add_data = true;
        }
      } else {
        //no filter required, so add anyway.
        $add_data = true;
      }
      
      if ($add_data) {
        $data[$project_title][$profit_title] = $profit;
        //add profit percent to details
        $details[$project_title]['profit']['profit_percent'] = $profit_percent;
        $details[$project_title]['profit']['profit_absolute'] = round($profit, 2);  

        $project_nid = !empty($details[$project_title]['project_nid']) ? $details[$project_title]['project_nid'] : false;
        //add rules integration
        if (module_exists('rules') && $project_nid) { 
          $project_node = node_load($project_nid);      
          if (!empty($project_node->nid)) {
            rules_invoke_event('project_profit_calcualted', 
              $project_node, 
              $revenue,
              $expense,
              $profit,
              $profit_percent
            );
          }
        }        
      } else {
        //unset the data
        unset($data[$project_title]);
        unset($details[$project_title]);
      }
    }
    
    
    //build extended report data
    $report_data = array(
      'data' => $data,
      'extended' => array(), //not yet needed
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
  * Callback to process the report with a batch process
  */
  static function process_item_batch(&$context) {
    
    $nids = $context['sandbox']['variables']['ids'];
    $start = $context['start'];
    $length = $context['length'];

    for ($i = $start; $i < $start + $length; $i++) {
      if (empty($nids[$i]))
        return;  //no more elements are available
      $nid = $nids[$i];
      $data = &$context['sandbox']['variables']['data'];
      $details = &$context['sandbox']['variables']['details'];
      $options = $context['sandbox']['variables']['options'];
      $project_nids_processed = &$context['sandbox']['variables']['project_nids_processed']; 
      
      if (empty($context['sandbox']['processed_nids']))
        $context['sandbox']['processed_nids'] = array();
              
      if (empty($context['sandbox']['processed_nids'][$nid]))
        self::process_item($nid, $options, $project_nids_processed, $data, $details);
        
      $context['sandbox']['processed_nids'][$nid] = TRUE; //avoid adding duplicate items
    }
  }
  
  /**
  * This is the function that processes one item  for the report
  */
  static function process_item($nid, $options, &$project_nids_processed, &$data, &$details) {
    $node = node_load($nid);
    $node_wrapper = entity_metadata_wrapper('node', $node);

    $expense_title = $options['config_options']['expense_title'];
    $revenue_title = $options['config_options']['revenue_title'];
    
    $field_project = $node_wrapper->field_project_ref->value();

    $project_title = $field_project->title;

    //get timetrackings of this task
    $timetracking_nids = _erpal_projects_helper_get_direct_timetrackings(array($node->nid));

    // get all billables of task and its timetrackings
    $nids = $timetracking_nids;
    $nids[] = $node->nid;
    
    //we may have direct billables to the project so at the project nid if not yet done
    if (!in_array($field_project->nid, $nids) && !in_array($field_project->nid, $project_nids_processed)) {
      $nids[] = $field_project->nid;
      $project_nids_processed[] = $field_project->nid;
      
      //also add a project fixed price if available also add expected expenses from tasks and projects in purchasing settings
      self::add_fixed_pricing_information($field_project, $data, $project_title, $details); 
      
    }
    
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'billable')
      ->entityCondition('bundle', array('unbillable', 'billable'), 'IN')
      ->propertyCondition('subject_nid', $nids, 'IN')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.;

    $result = $query->execute();
 
    if (isset($result ['billable']) && count($result ['billable']) > 0) {
      if (empty($data[$project_title])) {
        $data[$project_title] = array();
        $details[$project_title] = array();
      }

      foreach($result['billable'] as $id => $obj) {
        $billable = entity_load('billable', array($obj->billable_id));
        $billable = !empty($billable[$obj->billable_id]) ? $billable[$obj->billable_id] : false;
    
        if (!$billable)
          continue;
  
        //continue if this billable is part of a canceled (2) invoice
        $invoice_node = _erpal_invoice_helper_get_invoice_by_billable($billable);
        $invoice_node = reset($invoice_node);
        if (!empty($invoice_node)) {
          $invoice_w = entity_metadata_wrapper('node', $invoice_node);
          $paid_status = $invoice_w->field_payed->value();
          if ($paid_status == 2)
            continue;
        }              

        $price = $billable->total_price_no_vat;

        if ($billable->contractor_nid == _erpal_basic_helper_get_own_company_nid(FALSE)) {
          // billable is revenue
          $title = $revenue_title;         
        } else {
          // billable is expense
          $title = $expense_title;          
        }
        
        if (empty($data[$project_title][$title])) {
          $data[$project_title][$title] = 0;
          $details[$project_title][$title] = array();
        }
        
        $data[$project_title][$title] += $price;
        $details[$project_title]['project_nid'] = $field_project->nid;
        $details[$project_title][$title][] = array('entity_type' => 'billable', 'id' => $billable->billable_id, 'title' => $billable->subject, 'date' => $title, 'value' => $price, 'project_nid' => $field_project->nid);          
      }
    }

    //check if the task has a fixed price and if so, add this price to the "Expected revenue"
    self::add_fixed_pricing_information($node, $data, $project_title, $details); 
  
  }

  /**
   * get default options for project profit margin report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
      'date_from' => - 1,
      'date_to' => - 1,
      'scaling' => ERPAL_REPORT_DATE_SCALING_MONTH,
      'task_categories' => array (),
      'projects' => array (),
      'customers' => array (),
      'customer_categories' => array (),
      'service_categories' => array(),
      'users' => array (),
      'status' => array(),
      'no_cache' => FALSE
    );
  }
  
  static function add_fixed_pricing_information($node, &$data, $data_title, &$details) {
    //check if the task has a fixed price and if so, add this price to the "Expected revenue"
    $price_info = _erpal_projects_billable_subject_billable_information_subject($node);
    
    //we will not add this price if the task is already closed
    if ($node->type == 'erpal_project') {
      $semantic_field = 'field_project_status_term';
    } 
    if ($node->type == 'erpal_task') {
      $semantic_field = 'field_task_status_term';
    }
    
    $status = _erpal_basic_helper_get_tid_semantic($node, $semantic_field); 
    if ($status == 'completed')
      return;

    $fixed_price = $price_info['price_mode'] == 'fixed_price' ? $price_info['price'] : false;
    if ($fixed_price) {
      $label = t('Expected Revenue');
      if (!isset($data[$data_title][$label])) {
        $data[$data_title][$label] = 0;
        $details[$data_title][$label] = array();
      }
      // billable is expense
      $data[$data_title][$label] += $fixed_price;
      $details[$data_title][$label][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $label, 'value' => $fixed_price);
    }
    
    //add expected expenses
    $fixed_expense = $price_info['buy_price'] ? $price_info['buy_price'] : false;
    if ($fixed_expense) {
      $label = t('Expected Expense');
      if (!isset($data[$data_title][$label])) {
        $data[$data_title][$label] = 0;
        $details[$data_title][$label] = array();
      }
      // billable is expense
      $data[$data_title][$label] += $fixed_expense;
      $details[$data_title][$label][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $label, 'value' => $fixed_expense);
    }
  }
  
  /**
   * load cached erpal report object for project profit margin report from database
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
    
    $retval = erpal_reports_prepare_output($entity);

    return $retval;
  }
  
  static function save_report($report_data, $options) {
    erpal_reports_save_report_final(self::report_type(), self::class_name(), $report_data, $options);    
  } 
  
  
  static function report_type() {
    return 'erpal_project_profit_margin_reports';
  }
  
  static function class_name() {
    return 'ErpalProjectReportsProfitMargin';
  }
  
  /**
  * Return this report's title
  */
  static function report_title() {
    return t('CRM Expense Report');
  }
}