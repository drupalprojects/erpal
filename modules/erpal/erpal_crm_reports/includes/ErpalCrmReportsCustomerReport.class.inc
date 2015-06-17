<?php

/**
 * Erpal CRM Customer Report
 *
 * creates a report displaying active customers
 *
 * contrator_id => the contractor id (_erpal_basic_helper_get_own_company_nid(FALSE))
 * date_from => unix timestamp
 * date_to => unix timestamp
 * scaling => monthly or year
 * customer_categories => list of customer categories
 * min_orders => min amount of completed activities
 * min_sales => min sum of sales
 * dim_customercategory => add customer category dimension
 * no_cache => ignore caching
 *
 * @author Yann Karl
 */
class ErpalCrmReportsCustomerReport {
  /**
   * create data for crm customer report, returns false if no
   * data available
   *
   * @param array $options
   * @return mixed
   */
  static function create($options = array()) {
    // flag for no result, if TRUE, query has no value (e.g. selected customer group has no customer)
    $noresult = FALSE;

    $options = array_merge(self::defaults(), $options);

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'erpal_invoice')
      ->fieldCondition('field_payed', 'value', '2', '!=')
      ->fieldCondition('field_contractor_ref', 'target_id', $options ['contrator_id'], '=')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.;

    if ($options ['date_from'] > - 1) {
      $query->fieldCondition('field_invoice_date', 'value', $options ['date_from'], '>=');
    }

    if ($options ['date_to'] > - 1) {
      $query->fieldCondition('field_invoice_date', 'value', $options ['date_to'], '<=');
    }

    if (count($options ['customers']) > 0) {
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
      }
      else {
        $noresult = TRUE;
      }
    }

    $result = $query->execute();

    if (!isset($result['node']) || count($result['node']) == 0) {
      $noresult = TRUE;
    }

    $data = array();
    $details = array();
    if ($noresult === FALSE) {
      $nodes = node_load_multiple(array_keys($result ['node']));
      // setup cache for min_order count
      $min_order_cache = array();

      foreach ($nodes as $node) {
        $node_wrapper = entity_metadata_wrapper('node', $node);

        $currency = $node_wrapper->field_currency->value();

        $invoice_date = date($options['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $node_wrapper->field_invoice_date->value());

        $invoice_value = $node_wrapper->field_invoice_total->value();
        $currency = $node_wrapper->field_currency->value();

        $customer = $node_wrapper->field_customer_ref->value();
        $customer = entity_metadata_wrapper('node', $customer);
        $customer_category = $customer->field_customer_category->value();

        if ($options ['min_orders'] > 0) {
          if (!isset($min_order_cache[$customer->nid->value()])) {
            $subquery_options = ErpalCrmReportsLead::defaults();
            if ($options ['date_from'] > - 1) {
              $subquery_options['date_from'] = $options ['date_from'];
            }

            if ($options ['date_to'] > - 1) {
              $subquery_options['date_to'] = $options ['date_to'];
            }

            $taxonomy_idlist = ErpalCrmReportsLead::taxonomyIdlistCreate();
            $subquery_options['activities'] = $taxonomy_idlist['completed'];
            $subquery_options['customers'] = array($customer->nid->value());
            $subquery = ErpalCrmReportsLead::entityFieldQueryCreate($subquery_options);

            $subquery_result = $subquery->execute();

            $subquery_count = $subquery_result == null ? 0 : count($subquery_result['node']);

            $min_order_cache[$customer->nid->value()] = $subquery_count;
          }

          if ($min_order_cache[$customer->nid->value()] < $options ['min_orders']) {
            continue;
          }
        }

        if ($options ['dim_customercategory']) {
          $category_name = t("No Customer Category Set");
          if (count($customer_category) > 0) {
            $category_name = $customer_category[0];
          }
          $series_title = sprintf('%s %s', $currency, $category_name);
        } elseif ($options ['dim_customer']) {
          $series_title = sprintf('%s %s', $currency, $customer->title->value());
        } else {
          $series_title = sprintf('%s', $currency);
        }

        if (empty($data [$series_title])) {
          $data[$series_title] = array ();
          $details[$series_title] = array ();
        }

        if (empty($data [$series_title] [$invoice_date])) {
          $data[$series_title][$invoice_date] = 0;
          $details[$series_title][$invoice_date] = array();
        }

        $data[$series_title][$invoice_date] += $invoice_value;
        $details[$series_title][$invoice_date][] = array('entity_type' => 'node', 'id' => $node_wrapper->nid->value(), 'title' => $node_wrapper->title->value(), 'date' => $invoice_date, 'value' => $invoice_value);
        
      }

      // first iteration, remove customers below min_sales if value set
      // @todo: min-sales calculation only applies to sum of one currency, may lead to false positives
      if ($options ['min_sales'] > 0) {
        foreach($data as $index => $value) {
          if (array_sum($value) < (float)$options ['min_sales']) {
            unset($data[$index]);
          }
        }
      }
    } else {
      $data = FALSE;
    }

    if (is_array($data) && count($data) == 0) {
      $data = false;
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
   * get default options for crm customer report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
      'contrator_id' => _erpal_basic_helper_get_own_company_nid(FALSE),
      'date_from' => - 1,
      'date_to' => - 1,
      'scaling' => ERPAL_REPORT_DATE_SCALING_MONTH,
      'customers' => array (),
      'customer_categories' => array (),
      'min_orders' => 0,
      'min_sales' => 0,
      'dim_customercategory' => FALSE,
      'no_cache' => FALSE
    );
  }

  /**
   * load cached erpal report object for crm customer report from database
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
    return 'erpal_crm_customer_reports';
  }
  
  static function class_name() {
    return 'ErpalCrmReportsCustomerReport';
  }
  
  /**
  * Return this report's title
  */
  static function report_title() {
    return t('CRM Customer Report');
  }
}
