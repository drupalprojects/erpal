<?php

/**
 * Erpal CRM Sales Forecast Report
*
* creates a scaled sales forecast report with the following options:
*
* contrator_id => the contractor id (_erpal_basic_helper_get_own_company_nid(FALSE))
* date_to => unix timestamp
* scaling => monthly or year
* customers => list of customers
* customer_categories => list of customer categories
* calculate_safe_sales => calculate safe future sales values
* calculate_probable_sales => calculate probable future sales values
* min_probability => min probability for future probable sales
* dim_customer => add customer dimension
* dim_customercategory => add customer category dimension
* no_cache => ignore caching
*
* @author Yann Karl
*/

class ErpalCrmReportsSalesForecast {
  /**
   * create data for crm sales forecast report, returns false if no
   * data available
   *
   * @param array $options
   * @return mixed
   */
  static function create($options = array()) {
    error_reporting(E_ALL);
    // flag for no result, if TRUE, query has no value (e.g. selected customer group has no customer)
    $noresult = FALSE;

    $service_categories = array();
    $customer_nids = array();
    $sales_by_service_category = array();
    
    $options = array_merge(self::defaults(), $options);

    // init return values
    $retval = array('titles' => array(), 'data' => array());
    $data = array();
    $details = array();
    if ($options['calculate_sales_to_bill'] === TRUE) {
      //get all billables that are billables where the contractor is "own company" and that are not yet billed.
      $billable_sum = 0;
      $query = new EntityFieldQuery();
      $own_company_nid = _erpal_basic_helper_get_own_company_nid(false);
      
      $query->entityCondition('entity_type', 'billable')
        ->entityCondition('bundle', 'billable')
        ->propertyCondition('customer_nid', $own_company_nid, '<>')
        ->propertyCondition('billed', 1, '<>')
        ->propertyCondition('parent_billable', 0, '=')
        ->addMetaData('account', user_load(1)); // Run the query as user 1.;
      
      if ($options ['date_to'] > - 1) {
        $date_to_unix = strtotime(date('Y-m-d 23:59:59', $options ['date_to']));
        $query->propertyCondition('date_delivery', $date_to_unix, '<=');
      }
      $result = $query->execute();

      if (isset($result ['billable']) && count($result ['billable']) > 0) {
        $noresult = FALSE;

        $billable_idlist = array_keys($result['billable']);

        foreach($billable_idlist as $billable_id) {
          $billable = billable_load($billable_id);
          $billable_price = $billable->total_price_no_vat;
          $series_title = t('Sales volume to bill');
          $customer_nid = $billable->customer_nid;
          
          //billables that are not yet billed will be 
          $billable_date = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $billable->date_delivery);
          
          if ($options ['dim_customercategory'] === TRUE) {
            //load the customer
            $customer_node = node_load($customer_nid);
            $category_name = t("No Customer Category Set");
            $customer = entity_metadata_wrapper('node', $customer_node);            
            $customer_category = $customer->field_customer_category->value();

            if (count($customer_category) > 0) {
              $category_name = $customer_category[0];
            }
            $series_title = sprintf('%s - %s', $series_title, $category_name);
          } else if ($options ['dim_customer'] === TRUE) {            
            $customer = node_load($customer_nid);
            $series_title = sprintf('%s - %s', $series_title, $customer->title);
          }

          if (empty($data[$series_title][$billable_date])) {
            $data[$series_title][$billable_date] = 0;
            $details[$series_title][$billable_date] = array();
          }
          $data[$series_title][$billable_date] += $billable_price;
          $details[$series_title][$billable_date][] = array('entity_type' => 'billable', 'id' => $billable->billable_id, 'title' => $billable->subject, 'date' => $billable_date, 'value' => $billable_price);
          
          $billable_wrapper = entity_metadata_wrapper('billable', $billable);
          $service_category = $billable_wrapper->field_service_category_term->value();
          if ($service_category) {
            $service_category_id = $service_category->tid;
            $service_category_name = $service_category->name;
          } else  {
            $service_category_id = 0;
            $service_category_name = t('No service category selected');
          }
          
          $customer_nids[$series_title][$billable_date] = $customer_nid;
          $service_categories[$series_title][$billable_date] = array('id' => $service_category_id, 'name' => $service_category_name, 'customer_nid' => $customer_nid);
          if (empty($sales_by_service_category[$series_title] [$billable_date][$service_category_id]))
            $sales_by_service_category[$series_title] [$billable_date][$service_category_id] = 0;
          $sales_by_service_category[$series_title] [$billable_date][$service_category_id] += $billable_price; //this will add the sales volume by service category                       
        }
      }
    }
    
    if ($options['calculate_safe_sales'] === TRUE)
    {
      $project_status_terms = self::projectStatusTaxonomyIdlistCreate();
      $project_in_progress_status_terms = $project_status_terms['in_progress'];

      /*
       * - Task und Projekte mit pricing mode fixed price die noch nicht abgenommen sind. Wir nehmen das Datum der Abnahme des Projekts oder Tasks und addieren das Zahlungsziel des Kunden. Hat er noch kein Zahlungsziel, verwenden wir das Default Zahlungsziel aus den ERPAL Settings. Das werten wir mit 100%
       */
      // load all field_pricing elements with fixed price
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'field_collection_item')
        ->entityCondition('bundle', 'field_pricing')
          ->fieldCondition('field_price_mode', 'value', 'fixed_price', '=')
          ->addMetaData('account', user_load(1)); // Run the query as user 1.;

      $result = $query->execute();

      if (isset($result ['field_collection_item']) && count($result ['field_collection_item']) > 0) {
        $noresult = FALSE;

        $field_collection_idlist = array_keys($result['field_collection_item']);

        // get all project ids with matching field_pricing
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'erpal_project')
          ->fieldCondition('field_pricing', 'value', $field_collection_idlist, 'IN')
          ->addMetaData('account', user_load(1)); // Run the query as user 1.;

        $query->fieldCondition('field_project_status_term', 'tid', $project_in_progress_status_terms, 'IN');

        if ($options ['date_to'] > - 1) {
          $query->fieldCondition('field_date', 'value2', date('Y-m-d 23:59:59', $options ['date_to']), '<=');
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
          } else {
            $noresult = TRUE;
          }
        }

        if ($noresult === FALSE) {
          // load project nodes
          $result = $query->execute();

          if (isset($result['node']) && count($result ['node']) > 0) {
            $nodes = node_load_multiple(array_keys($result ['node']));
            foreach ($nodes as $node) {
              $node_wrapper = entity_metadata_wrapper('node', $node);
              $price_field_collection = field_collection_item_load($node->field_pricing[LANGUAGE_NONE][0]["value"]);

              // recheck if project is fixed_price
              if ($price_field_collection->field_price_mode[LANGUAGE_NONE][0]["value"] == 'fixed_price') {
                $project_price = $price_field_collection->field_price[LANGUAGE_NONE][0]["value"];

                $project_date = $node_wrapper->field_date->value();
                $project_date = (isset($date['value2']) ? $project_date['value2'] : $project_date['value']);

                $project_date_from_array = date_parse_from_format(DATE_FORMAT_DATETIME, $project_date);
                if (count($project_date_from_array['errors']) == 0) {
                  $project_date = mktime(0, 0, 0, $project_date_from_array['month'], $project_date_from_array['day'], $project_date_from_array['year']);
                }

                $customer_invoice_defaults = _erpal_invoice_helper_get_customer_defaults($node_wrapper->field_customer_ref->value(), false);
                //$project_date += $customer_invoice_defaults['credit_period'] * 24 * 3600;

                $project_date = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $project_date);

                // first result: $project_price | $project_date
                $series_title = t('Expected volume');

                if ($options ['dim_customercategory'] === TRUE) {
                  $category_name = t("No Customer Category Set");
                  $customer = $node_wrapper->field_customer_ref->value();
                  $customer = entity_metadata_wrapper('node', $customer);
                  $customer_category = $customer->field_customer_category->value();

                  if (count($customer_category) > 0) {
                    $category_name = $customer_category[0];
                  }
                  $series_title = sprintf('%s - %s', $series_title, $category_name);
                } else if ($options ['dim_customer'] === TRUE) {
                  $customer = $node_wrapper->field_customer_ref->value();
                  $series_title = sprintf('%s - %s', $series_title, $customer->title);
                }

                if (! isset($data [$series_title])) {
                  $data[$series_title] = array();
                  $etails[$series_title] = array();
                }

                if (! isset($data [$series_title] [$project_date])) {
                  $data[$series_title][$project_date] = 0;
                  $details[$series_title][$project_date] = array();
                }

                //get the service category
                $price_wrapper = entity_metadata_wrapper('field_collection_item', $price_field_collection);
                $service_category = $price_wrapper->field_service_category_term->value();
                if ($service_category) {
                  $service_category_id = $service_category->tid;
                  $service_category_name = $service_category->name;
                } else  {
                  $service_category_id = 0;
                  $service_category_name = t('No service category selected');
                }
            
                $data[$series_title][$project_date] += $project_price;
                $details[$series_title][$billable_date][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $project_date, 'value' => $project_price);
                
                $customer_nid = $node_wrapper->field_customer_ref->value()->nid;
                $customer_nids[$series_title][$project_date] = $customer_nid;
                $service_categories[$series_title] [$project_date] = array('id' => $service_category_id, 'name' => $service_category_name, 'customer_nid' => $customer_nid);
                if (empty($sales_by_service_category[$series_title] [$project_date][$service_category_id]))
                  $sales_by_service_category[$series_title] [$project_date][$service_category_id] = 0;
                $sales_by_service_category[$series_title] [$project_date][$service_category_id] += $project_price; //this will add the sales volume by service category
              }
            }
          }
        }

        // get all task ids with matching field_pricing
        $task_status_terms = self::taskStatusTaxonomyIdlistCreate();
        $task_in_progress_status_terms = $task_status_terms['in_progress'];

        $noresult = FALSE;
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'erpal_task')
          ->fieldCondition('field_pricing', 'value', $field_collection_idlist, 'IN')
          ->addMetaData('account', user_load(1)); // Run the query as user 1.;

        $query->fieldCondition('field_task_status_term', 'tid', $task_in_progress_status_terms, 'IN');

        if ($options ['date_to'] > - 1) {
          $query->fieldCondition('field_date', 'value', date('Y-m-d 23:59:59', $options ['date_to']), '<=');
        }

        if (count($options ['customers']) > 0 || count($options ['customer_categories']) > 0) {
          $query_project = new EntityFieldQuery();
          $query_project->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'erpal_project')
            ->addMetaData('account', user_load(1)); // Run the query as user 1.;

          if (count($options ['customers']) > 0) {
            $query_project->fieldCondition('field_customer_ref', 'target_id', $options ['customers'], 'IN');
          }

          if (count($options ['customer_categories']) > 0) {
            $query_group = new EntityFieldQuery();
            $query_group->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'erpal_contact')
                ->fieldCondition('field_customer_category', 'value', $options ['customer_categories'], 'IN')
                ->addMetaData('account', user_load(1)); // Run the query as user 1.;

            $result = $query_group->execute();

            if (count($result) > 0) {
              $query_project->fieldCondition('field_customer_ref', 'target_id', array_keys($result ['node']), 'IN');
            } else {
              $noresult = TRUE;
            }
          }

          if ($noresult === FALSE) {
            $result = $query_project->execute();

            if (count($result) > 0) {
              $query->fieldCondition('field_project_ref', 'target_id', array_keys($result ['node']), 'IN');
            } else {
              $noresult = TRUE;
            }
          }
        }

        if ($noresult === FALSE) {
          $result = $query->execute();

          // load tasks nodes
          if (isset($result['node']) && count($result ['node']) > 0) {
            $nodes = node_load_multiple(array_keys($result ['node']));
            
            foreach ($nodes as $node) {
              $node_wrapper = entity_metadata_wrapper('node', $node);
              $price_field_collection = field_collection_item_load($node->field_pricing[LANGUAGE_NONE][0]["value"]);

              // recheck if task is fixed_price
              if ($price_field_collection->field_price_mode[LANGUAGE_NONE][0]["value"] == 'fixed_price') {
                $task_price = $price_field_collection->field_price[LANGUAGE_NONE][0]["value"];

                $task_date = $node_wrapper->field_date->value();
                $task_date = (isset($date['value2']) ? $task_date['value2'] : $task_date['value']);

                $task_date_from_array = date_parse_from_format(DATE_FORMAT_DATETIME, $task_date);
                if (count($task_date_from_array['errors']) == 0) {
                  $task_date = mktime(0, 0, 0, $task_date_from_array['month'], $task_date_from_array['day'], $task_date_from_array['year']);
                }

                $project = $node_wrapper->field_project_ref->value();
                $project = entity_metadata_wrapper('node', $project);
                $customer = $project->field_customer_ref->value();

                $customer_invoice_defaults = _erpal_invoice_helper_get_customer_defaults($customer, false);
                //$task_date += $customer_invoice_defaults['credit_period'] * 24 * 3600;

                $task_date = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $task_date);

                // second result: $task_price | $task_date
                $series_title = t('Expected volume');

                if ($options ['dim_customercategory'] === TRUE) {
                  $category_name = t("No Customer Category Set");
                  $customer = entity_metadata_wrapper('node', $customer);
                  $customer_category = $customer->field_customer_category->value();

                  if (count($customer_category) > 0) {
                    $category_name = $customer_category[0];
                  }
                  $series_title = sprintf('%s - %s', $series_title, $category_name);
                } else if ($options ['dim_customer'] === TRUE) {
                  $series_title = sprintf('%s - %s', $series_title, $customer->title);
                }

                if (empty($data [$series_title])) {
                  $data[$series_title] = array ();
                  $details[$series_title] = array();
                }

                if (empty($data [$series_title] [$task_date])) {
                  $data[$series_title][$task_date] = 0;
                  $details[$series_title][$task_date] = array();
                }                
                
                //get the service category
                $price_wrapper = entity_metadata_wrapper('field_collection_item', $price_field_collection);
                $service_category = $price_wrapper->field_service_category_term->value();
                if ($service_category) {
                  $service_category_id = $service_category->tid;
                  $service_category_name = $service_category->name;
                } else  {
                  $service_category_id = 0;
                  $service_category_name = t('No service category selected');
                }
                
                $data[$series_title][$task_date] += $task_price;
                $details[$series_title][$task_date][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $task_date, 'value' => $task_price);
                
                $customer_nids[$series_title][$task_date] = $customer->nid;
                $service_categories[$series_title][$task_date] = array('id' => $service_category_id, 'name' => $service_category_name, 'customer_nid' => $customer->nid);
                
                if (empty($sales_by_service_category[$series_title] [$task_date][$service_category_id]))
                  $sales_by_service_category[$series_title] [$task_date][$service_category_id] = 0;
                $sales_by_service_category[$series_title] [$task_date][$service_category_id] += $task_price; //this will add the sales volume by service category
              }
            }
          }
        }
      }

      /*
       - Dann nehmen wir noch die Budgets die budget_timetracking_billing auf always billable stehen haben. Den Rest des Budgets, das noch vorhanden ist brechen wir auf die verbleibende Anzahl der Monate herab bis das Budget endet. Endet es nie, wird auf die nächsten 6 Monate gleichmäßig aufgetilt. Diese 6 Monate sollten im Report parametrisierbar sein
      */
      // Tabelle budget
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'field_collection_item')
        ->entityCondition('bundle', 'field_pricing')
        ->fieldCondition('field_price_mode', 'value', 'budget', '=')
        ->fieldCondition('field_budget_time_billing', 'value', 'billable', '=')
        ->addMetaData('account', user_load(1)); // Run the query as user 1.
      $result = $query->execute();

      if (isset($result ['field_collection_item']) && count($result ['field_collection_item']) > 0) {
        $noresult = FALSE;

        $field_collection_idlist = array_keys($result['field_collection_item']);

        // get all project ids with matching field_pricing
        $query = new EntityFieldQuery();
        $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'erpal_project')
          ->fieldCondition('field_pricing', 'value', $field_collection_idlist, 'IN')
          ->addMetaData('account', user_load(1)); // Run the query as user 1.;
        $result = $query->execute();

        if (isset($result['node']) && count($result ['node']) > 0) {
          $nodes = node_load_multiple(array_keys($result ['node']));
          foreach ($nodes as $node) {
            $node_wrapper = entity_metadata_wrapper('node', $node);
            $budgets = _erpal_projects_helper_get_budget($node, false);
            
            $price_field_collection = field_collection_item_load($node->field_pricing[LANGUAGE_NONE][0]["value"]);
            
            foreach($budgets['budgets'] as $budget) {
              if ($budget->available_hours > 0) {
                $series_title = t('Expected volume');

                if ($options ['dim_customercategory'] === TRUE) {
                  $category_name = t("No Customer Category Set");
                  $customer = $node_wrapper->field_customer_ref->value();
                  $customer = entity_metadata_wrapper('node', $customer);
                  $customer_category = $customer->field_customer_category->value();

                  if (count($customer_category) > 0) {
                    $category_name = $customer_category[0];
                  }
                  $series_title = sprintf('%s - %s', $series_title, $category_name);
                } else if ($options ['dim_customer'] === TRUE) {
                  $customer = $node_wrapper->field_customer_ref->value();
                  $series_title = sprintf('%s - %s', $series_title, $customer->title);
                }

                $current_date = mktime(0, 0, 0, date('m', $budget->date_from), 1, date('Y', $budget->date_from));
                // if budget started in the past, use current timestamp as start for calculation
                if ($current_date < time()) {
                  $current_date = mktime(0, 0, 0, date('m'), 1, date('Y'));
                }

                // @TODO: sometimes price is too high for estimation, maybe fixed in future version
                $budget_sum = $budget->available_hours * (float)($node_wrapper->field_pricing->value()->field_price[LANGUAGE_NONE][0]['value']);
                $budget_end_date = NULL;

                if ($budget->date_till > 0) {
                  $budget_end_date = $budget->date_till;
                }

                // calculate budget end date, either end date or current_date + 6 months
                if ($budget_end_date == NULL) {
                  // calc days of next 6 months
                  $days_6_months = 0;
                  $calc_next_date = time();
                  for ($i = 0; $i < 6; $i++) {
                    $calc_next_date = $current_date + 32 * 24 * 3600;
                    $days_6_months += cal_days_in_month(CAL_GREGORIAN, date('d', $calc_next_date), date('Y', $calc_next_date));
                  }

                  $budget_end_date = $current_date + $days_6_months * 24 * 3600;
                  $budget_partial_sum = $budget_sum / 6;
                } else {
                  $diff = $budget_end_date - $current_date;
                  $months = floor($diff / (30.5 * 24 * 3600));
                  if (!$months)
                    $months = 1; //otherwise we get devision by 0
                  $budget_partial_sum = $budget_sum / $months;
                }

                while ($current_date < $budget_end_date) {
                  if ($options ['date_to'] > - 1 && $options ['date_to'] < $current_date) {
                    break;
                  }

                  $budget_partial_date_literal = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $current_date);

                  if (empty($data [$series_title])) {
                    $data[$series_title] = array();
                    $details[$series_title] = array();
                  }

                  if (empty($data [$series_title] [$budget_partial_date_literal])) {
                    $data[$series_title][$budget_partial_date_literal] = 0;
                    $details[$series_title][$budget_partial_date_literal] = array();
                  }

                  $data[$series_title] [$budget_partial_date_literal] += $budget_partial_sum;
                  $details[$series_title][$task_date][] = array('entity_type' => 'budget', 'id' => $budget->budget_id, 'title' => $budget->defaultLabel(), 'date' => $budget_partial_date_literal, 'value' => $budget_partial_sum);
                  
                  $price_wrapper = entity_metadata_wrapper('field_collection_item', $price_field_collection);
                  $service_category = $price_wrapper->field_service_category_term->value();
                  if ($service_category) {
                    $service_category_id = $service_category->tid;
                    $service_category_name = $service_category->name;
                  } else  {
                    $service_category_id = 0;
                    $service_category_name = t('No service category selected');
                  }
                  
                  $customer_nid = $node_wrapper->field_customer_ref->value()->nid;
                  $customer_nids[$series_title][$budget_partial_date_literal] = $customer_nid;
                  $service_categories[$series_title][$budget_partial_date_literal] = array('id' => $service_category_id, 'name' => $service_category_name, 'customer_nid' => $customer_nid);
                  if (empty($sales_by_service_category[$series_title] [$budget_partial_date_literal][$service_category_id]))
                    $sales_by_service_category[$series_title] [$budget_partial_date_literal][$service_category_id] = 0;
                  $sales_by_service_category[$series_title] [$budget_partial_date_literal][$service_category_id] += $budget_partial_sum; //this will add the sales volume by service category

                  $calc_next_date = $current_date + 35 * 24 * 3600;
                  $current_date += cal_days_in_month(CAL_GREGORIAN, date('d', $calc_next_date), date('Y', $calc_next_date)) * 24 * 3600;
                }
              }
            }
          }
        }
      }

      // calculate contracts
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'field_collection_item')
        ->entityCondition('bundle', 'field_contract_payment')
        ->fieldCondition('field_contractor_ref', 'target_id', $options ['contrator_id'], '=')
        ->addMetaData('account', user_load(1)); // Run the query as user 1.;


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
        } else {
          $noresult = TRUE;
        }
      }

      if ($noresult === FALSE) {
        $result = $query->execute();

        if (isset($result ['field_collection_item']) && count($result ['field_collection_item']) > 0) {
          $field_collection_idlist = array_keys($result['field_collection_item']);

          // get all project ids with matching field_pricing
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'erpal_contract')
            ->fieldCondition('field_contract_payment', 'value', $field_collection_idlist, 'IN')
            ->addMetaData('account', user_load(1)); // Run the query as user 1.;

          $result = $query->execute();

          if (isset($result['node']) && count($result['node']) > 0) {
            $nodes = node_load_multiple(array_keys($result ['node']));
            foreach ($nodes as $node) {
              $node_wrapper = entity_metadata_wrapper('node', $node);

              // filter ended contracts
              $date = $node_wrapper->field_date->value();
              $contract_end_date = NULL;

              if ($date['value'] != $date['value2']) { //this means the contract has not yet been canceled
                $contract_end_date_from_array = date_parse_from_format(DATE_FORMAT_DATETIME, $date['value2']);
                if (count($contract_end_date_from_array['errors']) == 0) {
                  $contract_end_date = mktime(0, 0, 0, $contract_end_date_from_array['month'], $contract_end_date_from_array['day'], $contract_end_date_from_array['year']);
                  if ($contract_end_date < time()) {
                    continue;
                  }
                }
              }

              $field_contract_payment = $node_wrapper->field_contract_payment->value();
              $contract_payment_w = entity_metadata_wrapper('field_collection_item', $field_contract_payment);
              $customer = node_load($field_contract_payment->field_customer_ref[LANGUAGE_NONE][0]["target_id"]);

              $customer_invoice_defaults = _erpal_invoice_helper_get_customer_defaults($customer, false);

              $next_payment_date = $field_contract_payment->field_next_booking_date[LANGUAGE_NONE][0]["value"];
              //$next_payment_date += $customer_invoice_defaults['credit_period'] * 24 * 3600;

              $contract_price = $field_contract_payment->field_price[LANGUAGE_NONE][0]["value"];
              $payment_period = $contract_payment_w->field_payment_period->value();

              $contract_price = $contract_price * $payment_period;
              
              // first result: $contract_price | $next_payment_date
              $series_title = t('Forcasted sales');

              $customer_wrapper = entity_metadata_wrapper('node', $customer);
              if ($options ['dim_customercategory'] === TRUE) {
                $category_name = t("No Customer Category Set");                
                $customer_category = $customer_wrapper->field_customer_category->value();

                if (count($customer_category) > 0) {
                  $category_name = $customer_category[0];
                }
                $series_title = sprintf('%s - %s', $series_title, $category_name);
              } else if ($options ['dim_customer'] === TRUE) {
                $series_title = sprintf('%s - %s', $series_title, $customer->title);
              }

              // calculate last payment date, either end date or next_payment_date + 6 months
              if ($contract_end_date != NULL) {
                $last_payment_date = $contract_end_date;
              } else {
                $last_payment_date = $next_payment_date + 6 * 30.5 * 24 * 3600;
              }

              while ($next_payment_date < $last_payment_date) {
                $next_payment_date_literal = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $next_payment_date);

                if (empty($data[$series_title])) {
                  $data[$series_title] = array();
                  $details[$series_title] = array();
                }

                if (empty($data[$series_title][$next_payment_date_literal])) {
                  $data[$series_title][$next_payment_date_literal] = 0;
                  $details[$series_title][$next_payment_date_literal] = array();
                }
                             
                //get the service category
                $field_contract_payment = entity_metadata_wrapper('field_collection_item', $field_contract_payment);
                $service_category = $field_contract_payment->field_service_category_term->value();
                if ($service_category) {
                  $service_category_id = $service_category->tid;
                  $service_category_name = $service_category->name;
                } else  {
                  $service_category_id = 0;
                  $service_category_name = t('No service category selected');
                }
                
                $data[$series_title][$next_payment_date_literal] += $contract_price;
                $details[$series_title][$next_payment_date_literal][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $next_payment_date_literal, 'value' => $contract_price);
                
                $customer_nids[$series_title][$next_payment_date_literal] = $customer->nid;
                $service_categories[$series_title][$next_payment_date_literal] = array('id' => $service_category_id, 'name' => $service_category_name, 'customer_nid' => $customer->nid);
                
                if (empty($sales_by_service_category[$series_title][$next_payment_date_literal][$service_category_id]))
                  $sales_by_service_category[$series_title][$next_payment_date_literal][$service_category_id] = 0;
                $sales_by_service_category[$series_title][$next_payment_date_literal][$service_category_id] += $contract_price; //this will add the sales volume by service category

                $next_payment_date += $field_contract_payment->field_payment_period->value() * 30.5 * 24 * 3600;
              }
            }
          }
        }
      }
    }

    if ($options['calculate_probable_sales'] === TRUE)
    {
      //@TODO: extend taxonomy with probability value to add min_probability functionality
      /*
      - Sales Chancen. Activities, an denen ein Volume eingetragen ist, werden mit dem zur Warscheinlichkeit hinterlegten Prozentwert (muss noch in die Taxonomy hinzugefügt werden als Feld) angenommen. Als Umsatztag wird das Datum Expected Date verwendet. Der Umsatz kommt ja nur dann an diesem Tag zu Stande, wenn wir auch wirklich mit Anzahlung arbeiten. Sonst kommt es auf die Projektdauer an.
        Hier sollte das Volume mit dem Prozentwert der Anzahlung (soll im Report für diesen Sales Chancen Teil einstellbar sein) multipliziert werden.
       */
      // create process status mapping for taxonomy
      $taxonomy_idlist = ErpalCrmReportsLead::taxonomyIdlistCreate();

      $lead_options = array('activities' => $taxonomy_idlist ['in_progress'],
                            'customers' => $options ['customers'],
                            'customer_categories' => $options ['customer_categories']);

      $lead_options = array_merge(ErpalCrmReportsLead::defaults(), $lead_options);
      $query = ErpalCrmReportsLead::entityFieldQueryCreate($lead_options);
      $result = $query->execute();

      if (!empty($result['node'])) {        
        foreach($result['node'] as $node) {
          $node = node_load($node->nid);
          $node_wrapper = entity_metadata_wrapper('node', $node);

          $expected_date = (int)$node_wrapper->field_expected_date->value();
          $expected_volume = (float)$node_wrapper->field_volume->value();
          $expected_chance = $node_wrapper->field_chance->value();

          if ($expected_date == 0 || $expected_volume == 0 || ($options ['date_to'] > -1 && $expected_date > $options ['date_to'])) {
            continue;
          }

          $expected_date = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $expected_date);

          // last result: $expected_volume | $expected_date
          $series_title = t('Expected volume');

          if ($options ['dim_customercategory'] === TRUE) {
            $category_name = t("No Customer Category Set");
            $customer = $node_wrapper->field_customer_ref->value();
            $customer = entity_metadata_wrapper('node', $customer);
            $customer_category = $customer->field_customer_category->value();

            if (count($customer_category) > 0) {
              $category_name = $customer_category[0];
            }
            $series_title = sprintf('%s - %s', $series_title, $category_name);
          } else if ($options ['dim_customer'] === TRUE) {
            $customer = $node_wrapper->field_customer_ref->value();
            $series_title = sprintf('%s - %s', $series_title, $customer->title);
          }

          if (empty($data[$series_title])) {
            $data[$series_title] = array();
            $details[$series_title] = array();
          }

          if (empty($data[$series_title][$expected_date])) {
            $data[$series_title][$expected_date] = 0;
            $details[$series_title][$expected_date] = array();
          }

          
          $service_category_id = 0;
          $service_category_name = t('No service category selected');
          
          //calculate the volume with respect to the chance
          $partial_expected_volume = $expected_volume;
          if (!$expected_chance) {
            $partial_expected_volume = 0;
          } else {
            $partial_expected_volume = round(($partial_expected_volume / 100), 2) * (25 * $expected_chance);            
          }
          
          $data[$series_title][$expected_date] += $partial_expected_volume;
          $details[$series_title][$expected_date][] = array('entity_type' => 'node', 'id' => $node->nid, 'title' => $node->title, 'date' => $expected_date, 'value' => $expected_volume);
          
          $customer_nid = $node_wrapper->field_customer_ref->value()->nid;
          $customer_nids[$series_title][$expected_date] = $customer_nid;
          $service_categories[$series_title][$expected_date] = array('id' => $service_category_id, 'name' => $service_category_name, 'customer_nid' => $customer_nid);
          
          if (empty($sales_by_service_category[$series_title][$expected_date][$service_category_id]))
            $sales_by_service_category[$series_title][$expected_date][$service_category_id] = 0;
          $sales_by_service_category[$series_title][$expected_date][$service_category_id] += $expected_volume; //this will add the sales volume by service category
        }
      }
    }

    if (is_array($data) && count($data) == 0) {
      $data = false;
    }

        
    //build extended report data
    $report_data = array(
      'data' => $data,
      'extended' => array('service_categories' => $service_categories, 'customer_nids' => $customer_nids, 'sales_by_service_category' => $sales_by_service_category),
      'details' => $details,
      'options' => $options,
      'class_name' => self::class_name(),
    );
    
    self::save_report($report_data, $options);

    return $report_data;
  
  }

  /**
   * get default options for crm sales forecast report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
        'contrator_id' => _erpal_basic_helper_get_own_company_nid(FALSE),
        'date_to' => -1,
        'scaling' => ERPAL_REPORT_DATE_SCALING_MONTH,
        'customers' => array (),
        'customer_categories' => array (),
        'calculate_safe_sales' => TRUE,
        'calculate_sales_to_bill' => TRUE,
        'calculate_probable_sales' => TRUE,
        'min_probability' => 0,
        'dim_customer' => FALSE,
        'dim_customercategory' => FALSE,
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

  static function save_report($report_data, $options) {
    erpal_reports_save_report_final(self::report_type(), self::class_name(), $report_data, $options);
  }
  
  /**
   * create list of project status tids from activity status term taxonomy
   *
   * @param array $tid_aborted
   * @param array $tid_in_progress
   * @param array $tid_completed
   */
  static function projectStatusTaxonomyIdlistCreate() {
    $taxonomy = taxonomy_vocabulary_machine_name_load('project_status_terms');

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
   * create list of task status tids from activity status term taxonomy
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
    return 'erpal_crm_sales_forecast_reports';
  }
  
  static function class_name() {
    return 'ErpalCrmReportsSalesForecast';
  }
  
  /**
  * Return this report's title
  */
  static function report_title() {
    return t('CRM Sales Forecast Report');
  }
}
