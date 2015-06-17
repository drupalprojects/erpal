<?php

/**
 * Erpal CRM Expense Report
 *
 * creates a scaled expense report with the following options:
 *
 * contrator_id => the contractor id (_erpal_basic_helper_get_own_company_nid(FALSE))
 * date_from => unix timestamp
 * date_to => unix timestamp
 * scaling => monthly or year
 * contractors => list of contractors
 * expense_categories => list of expense categories
 * dim_contractor => add contractor dimension
 * dim_expensecategory => add expense category dimension
 * no_cache => ignore caching
 *
 * @author Yann Karl
 */
class ErpalCrmReportsExpense {
  
  /**
   * create data for crm expense report, returns false if no
   * data available
   *
   * @param array $options
   * @param boolean $extended if true, the returned array will have another structure that will also contain the categories which are calculated in the method
   * @return mixed
   */    
  static function create($options = array()) {    
    $expense_categories = array();
    $contractor_nids = array();
    
    $options = array_merge(self::defaults(), $options);

    //take all billables BUT not the unbillables and only billables without a parent billable
    $own_company_nid = _erpal_basic_helper_get_own_company_nid(FALSE);
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'billable')   
      ->entityCondition('bundle', 'billable')
      ->propertyCondition('customer_nid', $own_company_nid, '=')
      ->propertyCondition('parent_billable', 0, '=')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.

    if ($options['date_from'] > - 1) {
      $query->propertyCondition('date_delivery', $options ['date_from'], '>=');
    }

    if ($options['date_to'] > - 1) {
      $query->propertyCondition('date_delivery', $options ['date_to'], '<=');
    }
    
    if (intval(count($options['contractors'])) > 0) {
      $query->propertyCondition('contractor_nid', $options['contractors'], 'IN');
    }
    
    if (intval(count($options['expense_categories'])) > 0) {      
      $query->fieldCondition('field_expense_category', 'tid', $options['expense_categories']);
    }

    $result = $query->execute();
    $noresult = FALSE;
    if (!isset($result['billable']) || count($result['billable']) == 0) {
      $noresult = TRUE;      
    }

    $data = array();
    $details = array();
    $extended = array();
    if (!$noresult) {      
      $billable_ids = array_keys($result['billable']);      
      $billable_ids_processed = array();
      if (!empty($options['use_batch'])) {
        $batch_variables = array(
          'ids' => $billable_ids,
          'options' => $options,
          'billable_ids_processed' => &$billable_ids_processed,
          'data' => &$data,
          'extended' => &$extended,
          'details' => &$details,
          'class' => self::class_name(),
          'process_callback' => 'process_item_batch',
          'finish_callback' => 'finalize_report_save',
        );                        
        erpal_reports_batch_start($batch_variables);        
      } else {           
        foreach($billable_ids as $id) {            
          self::process_item($id, $options, $billable_ids_processed, $data, $details, $extended);
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
        
      $billable_id = $ids[$i];
      $data = &$context['sandbox']['variables']['data'];
      $details = &$context['sandbox']['variables']['details'];
      $extended = &$context['sandbox']['variables']['extended'];
      $options = $context['sandbox']['variables']['options'];
      $billable_ids_processed = &$context['sandbox']['variables']['billable_ids_processed']; 
    
      if (empty($context['sandbox']['processed_ids']))
        $context['sandbox']['processed_nids'] = array();
              
      if (empty($context['sandbox']['processed_ids'][$billable_id]))
        self::process_item($billable_id, $options, $billable_ids_processed, $data, $details, $extended);
        
      $context['sandbox']['processed_ids'][$billable_id] = TRUE; //avoid adding duplicate items
    }
  }
  
  /**
  * This is the function that processes one item  for the report
  */
  static function process_item($billable_id, $options, &$billable_ids_processed, &$data, &$details, &$extended) {
    $billable = billable_load($billable_id);
        
    //no billables with parent ID, ensure this again
    if (!empty($billable->parent_billable)) {
      return;
    }
    
    $billable_w = entity_metadata_wrapper('billable', $billable);
    $currency = $billable->currency;

    $billable_date = date($options['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $billable->date_delivery);
    $series_title = $billable->currency;
    
    $expense_category = $billable_w->field_expense_category->value();

    if (count($options['expense_categories']) > 0 && ($expense_category == null || !in_array($expense_category->tid, $options['expense_categories']))) {         
      return; //we only want specific expense categories that this billable does not have.
    }
    
    $expense_category_name = t('No expenses category selected');
    $expense_category_id = 0;
    if ($expense_category != NULL) {
      $expense_category_name = $expense_category->name;
      $expense_category_id = $expense_category->tid;
    }
  
    $series_title = sprintf('%s', $currency);

    if ($options ['dim_contractor']) {
      $contractor_nid = $billable->contractor_nid;
      $node_base_data = erpal_lib_helper_node_base_data(array($contractor_nid), true);
      $contractor = $node_base_data[$contractor_nid];
      $contractor = $contractor->title;

      $series_title = sprintf('%s - %s', $currency, $contractor);
    } elseif ($options['dim_expensecategory']) {
      $series_title = sprintf('%s : %s', $currency, $expense_category_name);
    }

    $series_title = trim($series_title);

    if (! isset($data [$series_title])) {
      $data[$series_title] = array ();
      $details[$series_title] = array ();
    }

    if (! isset($data [$series_title] [$billable_date])) {
      $data[$series_title][$billable_date] = 0;
    }
    
    $extended['contractor_nids'][$series_title][$billable_date] = $billable->contractor_nid;
    $extended['expense_categories'][$series_title] [$billable_date] = array('id' => $expense_category_id, 'name' => $expense_category_name);
    $data[$series_title][$billable_date] += $billable_w->total_price_no_vat->value();          
    
    $subject = substr($billable->subject, 0, 50); //limit billable subject to 50 chars, the json string must not be longer than 255 in total
    $details[$series_title][$billable_date][] = array('entity_type' => 'billable', 'id' => $billable->billable_id, 'title' => $subject, 'date' => $billable_date, 'value' => $billable_w->total_price_no_vat->value());
  }
  
  static function finalize_report_save($options, $data, $details, $extended=array()) {     
    self::finalize_report($options, $data, $details, $extended, FALSE);    
  }
  
  static function finalize_report($options, $data, $details, $extended, $skipp_save_report = FALSE) {
    //add profit for each project
   
    //build extended report data
    $report_data = array(
      'data' => $data,
      'extended' => array('expense_categories' => $extended['expense_categories'], 'contractor_nids' => $extended['contractor_nids']),
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
  
  static function save_report($report_data, $options) {
    erpal_reports_save_report_final(self::report_type(), self::class_name(), $report_data, $options);
  }

  /**
   * get default options for crm expense report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
        'contrator_id' => _erpal_basic_helper_get_own_company_nid(FALSE),
        'date_from' => -1,
        'date_to' => -1,
        'scaling' => ERPAL_REPORT_DATE_SCALING_MONTH,
        'contractors' => array (),        
        'expense_categories' => array (),
        'dim_contractor' => FALSE,
        'dim_contractorcategory' => FALSE,
        'dim_expensecategory' => FALSE,
        'no_cache' => FALSE
    );
  }

  /**
   * load cached erpal report object for crm expense report from database
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
  
  static function report_type() {
    return 'erpal_crm_expense_reports';
  }
  
  static function class_name() {
    return 'ErpalCrmReportsExpense';
  }
  
  /**
  * Return this report's title
  */
  static function report_title() {
    return t('CRM Expense Report');
  }
}
