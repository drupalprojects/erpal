<?php

/**
 * Erpal CRM Sales Report
 *
 * creates a scaled sales report with the following options:
 *
 * contrator_id => the contractor id (_erpal_basic_helper_get_own_company_nid(FALSE))
 * date_from => unix timestamp
 * date_to => unix timestamp
 * scaling => monthly or year
 * customers => list of customers
 * customer_categories => list of customer categories
 * service_categories => list of service categories
 * dim_customer => add customer dimension
 * dim_customercategory => add customer category dimension
 * dim_servicecategory => add service category dimension
 * no_cache => ignore caching
 *
 * @author Manuel Pistner
 */
class ErpalCrmReportsSales {
  
  /**
   * create data for crm sales report, returns false if no
   * data available
   *
   * @param array $options
   * @param boolean $extended if true, the returned array will have another structure that will also contain the categories which are calculated in the method
   * @return mixed
   */    
  static function create($options = array(), $planned_sales = array()) {
    // flag for no result, if TRUE, query has no value (e.g. selected customer group has no customer)
    $noresult = FALSE;

    $service_categories = array();
    $customer_nids = array();
    
    $options = array_merge(self::defaults(), $options);

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'erpal_invoice')
      ->fieldCondition('field_payed', 'value', '2', '!=')
      ->fieldCondition('field_contractor_ref', 'target_id', $options['contrator_id'], '=')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.

    if ($options ['date_from'] > - 1) {
      $query->fieldCondition('field_invoice_date', 'value', $options ['date_from'], '>=');
    }

    if ($options ['date_to'] > - 1) {
      $query->fieldCondition('field_invoice_date', 'value', $options ['date_to'], '<=');
    }

    if (intval(count($options ['customers'])) > 0) {
      $query->fieldCondition('field_customer_ref', 'target_id', $options ['customers'], 'IN');
    }

    
    if (count($options ['customer_categories']) > 0) {
      $query_group = new EntityFieldQuery();
      $query_group->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'erpal_contact')
        ->fieldCondition('field_customer_category', 'value', $options ['customer_categories'], 'IN')
        ->addMetaData('account', user_load(1)); // Run the query as user 1.;

      $result = $query_group->execute();

      if (count($result) > 0) {
        $query->fieldCondition('field_customer_ref', 'target_id', array_keys($result ['node']), 'IN');
      } else {
        $noresult = TRUE;
      }
    }

    $result = $query->execute();

    if (!isset($result ['node']) || count($result ['node']) == 0) {
      $noresult = TRUE;
    }

    $retval = array('titles' => array(), 'data' => array());

    $data = array();
    $details = array();
    if ($noresult === FALSE) {
      $nodes = node_load_multiple(array_keys($result ['node']));

      foreach ($nodes as $node) {

        $node_wrapper = entity_metadata_wrapper('node', $node);
       
        $currency = $node_wrapper->field_currency->value();

        $invoice_date = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $node_wrapper->field_invoice_date->value());
        $series_title = $currency;
        $invoice_year = date('Y', $node_wrapper->field_invoice_date->value());
        
        $is_unplanned = FALSE;
        if ($options['dim_servicecategory']) {
          $billables = $node_wrapper->field_billables_ref->value();

          foreach($billables as $billable) {
            $billable_w = entity_metadata_wrapper('billable', $billable);

            $service_category = $billable_w->field_service_category_term->value();
 
            if (count($options['service_categories']) > 0 && ($service_category == null || !in_array($service_category->tid, $options['service_categories']))) {
              continue;
            }

            $service_category_name = t('No service category selected');
            $service_category_id = 0;
            if ($service_category != NULL) {
              $service_category_name = $service_category->name;
              $service_category_id = $service_category->tid;
            }
            
            $series_title = sprintf('%s - %s', $currency, $service_category_name);
            $customer = $node_wrapper->field_customer_ref->value();
            
            //check if this is a planned sales volume due to the forecasts or not           
            $unplanned_contact = _erpal_crm_reports_get_unplanned_contact_node();
            if ($unplanned_contact) {
              $unplanned_customer_w = entity_metadata_wrapper('node', $unplanned_contact);
              $unplanned_contact_title = $unplanned_contact->title;
              if (!empty($planned_sales)) {
                if (!empty($planned_sales[$invoice_year])) {
                  if (!in_array($customer->nid, $planned_sales[$invoice_year])) {
                    //this customer has no sales plan node, at least not in the current year.                  
                    $is_unplanned = TRUE;
                  }
                }
              }
            }
            
            if ($options ['dim_customer'] == TRUE) {              
              $customer = $customer->title;
              $series_title = sprintf('%s - %s: %s', $currency, $customer, $service_category_name);
              
              if ($is_unplanned) {
                $series_title_unplanned = sprintf('%s - %s: %s', $currency, $unplanned_contact_title, $service_category_name);
              }
            } else if ($options ['dim_customercategory'] == TRUE) {              
              $customer_w = entity_metadata_wrapper('node', $customer);
              $customer_category = $customer_w->field_customer_category->value();

              $category_name = t("No Customer Category Set");
              
              if (count($customer_category) > 0) {
                $category_name = $customer_category[0];
              }

              $series_title = sprintf('%s - %s: %s', $currency, $category_name, $service_category_name);
              
              if ($is_unplanned) {
                $unlanned_category_name = t("No Customer Category Set");
                
                $unplanned_customer_category = $unplanned_customer_w->field_customer_category->value();
                if (count($unplanned_customer_category) > 0) {
                  $unlanned_category_name = $unplanned_customer_category[0];
                }
                
                $series_title_unplanned = sprintf('%s - %s: %s', $currency, $unlanned_category_name, $service_category_name);
              }
            }

            $series_title = trim($series_title);
            if (! isset($data [$series_title])) {
              $data [$series_title] = array ();
            }

            if (! isset($data [$series_title] [$invoice_date])) {
              $data [$series_title] [$invoice_date] = 0;
            }

            $customer_nid = $node_wrapper->field_customer_ref->value()->nid;
            $customer_nids[$series_title][$invoice_date] = $customer_nid;
            $service_categories[$series_title][$invoice_date] = array('id' => $service_category_id, 'name' => $service_category_name, 'customer_nid' => $customer_nid);
            $data[$series_title][$invoice_date] += $billable_w->total_price_no_vat->value();
            $details[$series_title][$invoice_date][] = array('entity_type' => 'billable', 'id' => $billable->billable_id, 'date' => $invoice_date, 'value' => $billable_w->total_price_no_vat->value());

            //add for unplanned revenue
            if ($is_unplanned) {
              $series_title_unplanned = trim($series_title_unplanned);
              if (! isset($data [$series_title_unplanned])) {
                $data [$series_title_unplanned] = array ();
              }

              if (! isset($data [$series_title_unplanned] [$invoice_date])) {
                $data [$series_title_unplanned] [$invoice_date] = 0;
              } 
              
              $unplanned_customer_nid = $unplanned_contact->nid;
              $customer_nids[$series_title_unplanned][$invoice_date] = $unplanned_customer_nid;
              $service_categories[$series_title_unplanned][$invoice_date] = array('id' => $service_category_id, 'name' => $service_category_name, 'customer_nid' => $unplanned_customer_nid);
              $data[$series_title_unplanned][$invoice_date] += $billable_w->total_price_no_vat->value();
              $details[$series_title_unplanned][$invoice_date][] = array('entity_type' => 'billable', 'id' => $billable->billable_id, 'date' => $invoice_date, 'value' => $billable_w->total_price_no_vat->value());
            }
          }                   
  
        } else {
          $invoice_value = 0;
          $detail_data = array();
          if (count($options ['service_categories']) > 0) {
            $billables = $node_wrapper->field_billables_ref->value();

            foreach($billables as $billable) {
              $billable_w = entity_metadata_wrapper('billable', $billable);

              $service_category = $billable_w->field_service_category_term->value();

              if ($service_category == null || !in_array($service_category->tid, $options['service_categories'])) {
                continue;
              }

              $invoice_value += $billable_w->total_price_no_vat->value();
              $detail_data[] = array('entity_type' => 'billable', 'id' => $billable->billable_id, 'title' => $billable->subject, 'date' => $invoice_date, 'value' => $invoice_value);
            }
          } else {
            $invoice_value = $node_wrapper->field_price_no_vat->value();
            $detail_data[] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $invoice_date, 'value' => $invoice_value);
          }

          if ($options ['dim_customer'] == TRUE) {
            $customer = $node_wrapper->field_customer_ref->value();

            $series_title = sprintf('%s - %s', $currency, $customer->title);
            
            if ($is_unplanned) {
              $series_title_unplanned = sprintf('%s - %s', $currency, $unplanned_contact_title);              
            }
          } else if ($options ['dim_customercategory'] == TRUE) {
            $customer = $node_wrapper->field_customer_ref->value();
            $customer_w = entity_metadata_wrapper('node', $customer);
            $customer_category = $customer_w->field_customer_category->value();

            $category_name = t("No Customer Category Set");
            if (count($customer_category) > 0)
            {
              $category_name = $customer_category[0];
            }

            $series_title = sprintf('%s - %s', $currency, $category_name);
            
            if ($is_unplanned) {
              $unlanned_category_name = t("No Customer Category Set");
              
              $unplanned_customer_category = $unplanned_customer_w->field_customer_category->value();
              if (count($unplanned_customer_category) > 0) {
                $unlanned_category_name = $unplanned_customer_category[0];
              }
              
              $series_title_unplanned = sprintf('%s - %s', $currency, $unlanned_category_name);              
            }
            
          }

          $series_title = trim($series_title);

          if (! isset($data[$series_title])) {
            $data[$series_title] = array ();
            $details[$series_title] = array ();
          }

          if (! isset($data [$series_title] [$invoice_date])) {
            $data[$series_title][$invoice_date] = 0;
            $details[$series_title][$invoice_date] = array();
          }

          $data[$series_title][$invoice_date] += $invoice_value;
          $details[$series_title][$invoice_date] = array_merge($details[$series_title][$invoice_date], $detail_data);
          
          //add details for unplanned revenue as well
          if ($is_unplanned) {
            $series_title_unplanned = trim($series_title_unplanned);

            if (! isset($data[$series_title_unplanned])) {
              $data[$series_title_unplanned] = array ();
              $details[$series_title_unplanned] = array ();
            }

            if (! isset($data [$series_title_unplanned] [$invoice_date])) {
              $data[$series_title_unplanned][$invoice_date] = 0;
              $details[$series_title_unplanned][$invoice_date] = array();
            }

            $data[$series_title_unplanned][$invoice_date] += $invoice_value;
            $details[$series_title_unplanned][$invoice_date] = array_merge($details[$series_title_unplanned][$invoice_date], $detail_data);
          }
        }
      
      }

    } else {
      $data = FALSE;
    }

    if (is_array($data) && count($data) == 0) {
      $data = false;
    }

    $report_data = array(
      'data' => $data,
      'extended' => array('service_categories' => $service_categories, 'customer_nids' => $customer_nids),        
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
   * get default options for crm sales report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
        'contrator_id' => _erpal_basic_helper_get_own_company_nid(FALSE),
        'date_from' => -1,
        'date_to' => -1,
        'scaling' => ERPAL_REPORT_DATE_SCALING_MONTH,
        'customers' => array (),
        'customer_categories' => array (),
        'service_categories' => array (),
        'dim_customer' => FALSE,
        'dim_customercategory' => FALSE,
        'dim_servicecategory' => FALSE,
        'no_cache' => FALSE
    );
  }

  /**
   * load cached erpal report object for crm sales report from database
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
  
  static function report_type() {
    return 'erpal_crm_sales_reports';
  }
  
  static function class_name() {
    return 'ErpalCrmReportsSales';
  }
  
  /**
  * Return this report's title
  */
  static function report_title() {
    return t('CRM Sales Report');
  }
}