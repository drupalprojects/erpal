<?php

/**
 * Erpal Project Active Projects Report
 *
 * creates a scaled active project report with the following options:
 *
 * date_from => unix timestamp
 * date_to => unix timestamp
 * scaling => monthly or year
 * customers => list of customers
 * customer_categories => list of customer categories
 * dim_customer => add customer dimension
 * dim_customercategory => add customer category dimension
 * no_cache => ignore caching
 *
 * @author Yann Karl
 */
class ErpalProjectReportsActiveProjects {
  /**
   * create data for active projects report, returns false if no
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
    $query->entityCondition('entity_type', 'node')->entityCondition('bundle', 'erpal_project');

    if ($options ['date_from'] > - 1) {
      $query->fieldCondition('field_date', 'value2', sprintf('%s 00:00:00', date(DATE_FORMAT_DATE, $options ['date_from'])), '>=');
    }

    if ($options ['date_to'] > -1) {
      $query->fieldCondition('field_date', 'value', sprintf('%s 23:59:59', date(DATE_FORMAT_DATE, $options ['date_to'])), '<=');
    }

    if (count($options ['customers']) > 0) {
      $query->fieldCondition('field_customer_ref', 'target_id', $options['customers'], 'IN');
    }
    
    if (count($options ['customers']) > 0) {
      $query->fieldCondition('field_customer_ref', 'target_id', $options['customers'], 'IN');
    }
    
    if (count($options['status']) > 0) {
      $query->fieldCondition('field_project_status_term', 'tid', $options['status'], 'IN');
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
    
    $query->addMetaData('account', user_load(1)); // Run the query as user 1.
    $result = $query->execute();

    if (!isset($result ['node']) || count($result ['node']) == 0) {
      $noresult = TRUE;
    }

    $retval = array('titles' => array(), 'data' => array());

    $data = array();
    $details = array();
    if ($noresult === FALSE) {
      $nodes = node_load_multiple(array_keys($result ['node']));

      foreach($nodes as $node) {
        $node_wrapper = entity_metadata_wrapper('node', $node);
        $date_value = $node_wrapper->field_date->value();

        // filter projects without start and end date set
        if ($date_value == NULL || !isset($date_value['value']) || !isset($date_value['value2'])) {
          continue;
        }

        $start = date_parse_from_format(DATE_FORMAT_DATE, $date_value['value']);
        $start = mktime(0, 0, 0, $start['month'], $start['day'], $start['year']);

        if ($options ['date_from'] != -1 && $start < $options ['date_from']) {
          $start = $options ['date_from'];
        }

        $end = date_parse_from_format(DATE_FORMAT_DATE, $date_value['value2']);
        $end = mktime(0, 0, 0, $end['month'], $end['day'], $end['year']);

        if ($options ['date_to'] != -1 && $end > $options ['date_to']) {
          $end = $options ['date_to'];
        }

        $series_title = t('Active Projects');
        $series_addon = array();

        if ($options['dim_customer']) {
          $field_customer = $node_wrapper->field_customer_ref->value();
          $series_addon[] = $field_customer->title;
        } else if ($options['dim_customercategory']) {
          $field_customer = $node_wrapper->field_customer_ref->value();

          $customer_category = t('No customer category');
          if (count($field_customer->field_customer_category) > 0) {
            $customer_category = $field_customer->field_customer_category[LANGUAGE_NONE][0]['value'];
          }

          $series_addon[] = $customer_category;
        }

        if (count($series_addon) > 0) {
          $series_title .= sprintf(' - %s', implode(',', $series_addon));
        }

        $project_start_date = date($options ['scaling'] == ERPAL_REPORT_DATE_SCALING_YEAR ? _erpal_reports_date_format_year() : _erpal_reports_date_format_month(), $start);

        if (empty($data [$series_title])) {
          $data[$series_title] = array ();
          $details[$series_title] = array ();
        }

        if (empty($data [$series_title] [$project_start_date])) {
          $data[$series_title][$project_start_date] = 0;
          $details[$series_title][$project_start_date] = array();
        }

        $data[$series_title][$project_start_date] += 1;
        $details[$series_title][$project_start_date][] = array('entity_type' => 'node', 'id' => $node_wrapper->nid->value(), 'title' => $node_wrapper->title->value(), 'date' => $project_start_date, 'value' => 1);
        
        // start calculating if start and end date are not on the same month.year
        if (date('m.Y', $start) != date('m.Y', $end)) {
          switch($options['scaling']) {
            case ERPAL_REPORT_DATE_SCALING_YEAR:
              while(true) {
                $start = strtotime("+1 year", $start);
                $current_date = date(_erpal_reports_date_format_year(), $start);
                if ($start < $end) {
                  if (empty($data [$series_title] [$current_date])) {
                    $data[$series_title][$current_date] = 0;
                    $details[$series_title][$current_date] = array();
                  }

                  $data[$series_title][$current_date] += 1;
                  $details[$series_title][$current_date][] = array('entity_type' => 'node', 'id' => $node_wrapper->nid->value(), 'title' => $node_wrapper->title->value(), 'date' => $current_date, 'value' => 1);
                } else {
                  break;
                }
              }
              break;

            default:
            case ERPAL_REPORT_DATE_SCALING_MONTH:
              while(true) {
                $start = strtotime("+1 month", $start);
                $current_date = date(_erpal_reports_date_format_month(), $start);
                if ($start < $end) {
                  if (! isset($data [$series_title] [$current_date])) {
                    $data[$series_title][$current_date] = 0;
                    $details[$series_title][$current_date] = array();
                  }

                  $data[$series_title][$current_date] += 1;
                  $details[$series_title][$current_date][] = array('entity_type' => 'node', 'id' => $node_wrapper->nid->value(), 'title' => $node_wrapper->title->value(), 'date' => $current_date, 'value' => 1);
                } else {
                  break;
                }
              }
              break;
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
      'extended' => array(), //Not yet needed
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
   * get default options for active projects report creation
   *
   * @return array
   */
  static function defaults() {
    return array (
      'date_from' => - 1,
      'date_to' => - 1,
      'scaling' => ERPAL_REPORT_DATE_SCALING_MONTH,
      'customers' => array (),
      'status' => array(),
      'customer_categories' => array (),
      'dim_customer' => FALSE,
      'dim_customercategory' => FALSE,
      'no_cache' => FALSE
    );
  }

  /**
   * load cached erpal report object for active projects report from database
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
    return 'erpal_project_active_projects_reports';
  }
  
  static function class_name() {
    return 'ErpalProjectReportsActiveProjects';
  }
  
  /**
  * Return this report's title
  */
  static function report_title() {
    return t('Active projects report');
  }
}
