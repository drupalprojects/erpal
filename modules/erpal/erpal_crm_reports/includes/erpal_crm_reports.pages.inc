<?php
/**
* @file Forms for the reports
*/

function erpal_crm_reports_sales_forecast_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Report updated'));
}

function erpal_crm_reports_sales_forecast_report_form() {
  $format = _erpal_basic_helper_date_format_date_only();

  $form['date_to'] = array(
      '#title' => t('Date till'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['scaling'] = _erpal_reports_form_field_for_scaling();

  $form['customers'] = _erpal_reports_form_field_for_customer(t('Customers'));

  $form['customer_categories'] = _erpal_reports_form_field_for_customer_category(t('Customer categories'));

  $form['calculate_safe_sales'] = array(
      '#title' => t('To deliver output volume'),
      '#type' => 'checkbox',
      '#default_value' => TRUE
  );

  $form['calculate_probable_sales'] = array(
      '#title' => t('Estimated sales volume'),
      '#type' => 'checkbox',
      '#default_value' => TRUE
  );
  
  $form['calculate_sales_to_bill'] = array(
      '#title' => t('Delivered output'),
      '#type' => 'checkbox',
      '#default_value' => TRUE
  );

  //get the crm_activity nodes chance field's allowed values
  $field_chance = field_info_field('field_chance');
  $allowed_chance_values = list_allowed_values($field_chance); 
  $form['min_probability'] = array(
      '#title' => t('Minimum chance'),
      '#type' => 'select',
      '#options' => $allowed_chance_values, 
  );

  $form['dim_customer'] = array(
      '#title' => t('Dimension: Customer'),
      '#type' => 'checkbox'
  );
  $form['dim_customercategory'] = array(
      '#title' => t('Dimension: Customer category'),
      '#type' => 'checkbox'
  );

  _erpal_reports_add_report_basic_form($form);  

  return $form;
}

function erpal_crm_reports_sales_forecast_report_view() {
  $form_state = array();
  $form = drupal_build_form('erpal_crm_reports_sales_forecast_report_form', $form_state);
  $build['form'] = $form;

  $report_options = array();
  if ($form_state['submitted']) {
    if (!empty($form_state['values']['date_to'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_to']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_to'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (count($form_state['values']['customers']) > 0) {
      $report_options['customers'] = array_keys($form_state['values']['customers']);
    }

    if (count($form_state['values']['customer_categories']) > 0) {
      $report_options['customer_categories'] = array_keys($form_state['values']['customer_categories']);
    }

    $report_options['calculate_safe_sales'] = $form_state['values']['calculate_safe_sales'] == 1 ? TRUE : FALSE;
    $report_options['calculate_probable_sales'] = $form_state['values']['calculate_probable_sales'] == 1 ? TRUE : FALSE;
    $report_options['calculate_sales_to_bill'] = $form_state['values']['calculate_sales_to_bill'] == 1 ? TRUE : FALSE;

    if (!empty($form_state['values']['min_probability']) && intval($form_state['values']['min_probability']) > 0) {
      $report_options['min_probability'] = intval($form_state['values']['min_probability']);
    }

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['dim_customer'] = $form_state['values']['dim_customer'] == 1 ? TRUE : FALSE;
    $report_options['dim_customercategory'] = $form_state['values']['dim_customercategory'] == 1 ? TRUE : FALSE;

    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
  }

  $report_data = ErpalCrmReportsSalesForecast::load($report_options);

  $data = !empty($report_data['data']) ? $report_data['data'] : array();
  $data = _erpal_reports_flatten_and_sort_data_for_charts($data, $report_options);

  if ($data) {
    $build[] = _erpal_reports_visualize($report_data['report_id'], $data, 'ErpalCrmReportsSalesForecast'); 
  }

  return $build;
}

function erpal_crm_reports_sales_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Report updated'));
}

function erpal_crm_reports_sales_report_form() {
  $format = _erpal_basic_helper_date_format_date_only();

  $form['date_from'] = array(
      '#title' => t('Date from'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['date_to'] = array(
      '#title' => t('Date till'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['scaling'] = _erpal_reports_form_field_for_scaling();

  $form['customers'] = _erpal_reports_form_field_for_customer(t('Kunde(n)'));

  $form['customer_categories'] = _erpal_reports_form_field_for_customer_category(t('Customer categories'));

  $form['service_categories'] = _erpal_reports_form_field_for_service_category(t('Service categories'));

  $form['dim_customer'] = array(
      '#title' => t('Dimension: Customer'),
      '#type' => 'checkbox'
  );
  $form['dim_customercategory'] = array(
      '#title' => t('Dimension: Customer category'),
      '#type' => 'checkbox'
  );
  $form['dim_servicecategory'] = array(
      '#title' => t('Dimension: Service category'),
      '#type' => 'checkbox'
  );
  
  _erpal_reports_add_report_basic_form($form);

  return $form;
}

function erpal_crm_reports_sales_report_view() {
  
  $form_state = array();
  $form = drupal_build_form('erpal_crm_reports_sales_report_form', $form_state);
  $build['form'] = $form;

  $report_options = array();
  if ($form_state['submitted']) {
    if (!empty($form_state['values']['date_from'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_from']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_from'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (!empty($form_state['values']['date_to'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_to']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_to'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (count($form_state['values']['customers']) > 0) {
      $report_options['customers'] = array_keys($form_state['values']['customers']);
    }

    if (count($form_state['values']['customer_categories']) > 0) {
      $report_options['customer_categories'] = array_keys($form_state['values']['customer_categories']);
    }

    if (count($form_state['values']['service_categories']) > 0) {
      $report_options['service_categories'] = array_keys($form_state['values']['service_categories']);
    }

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['dim_customer'] = $form_state['values']['dim_customer'] == 1 ? TRUE : FALSE;
    $report_options['dim_customercategory'] = $form_state['values']['dim_customercategory'] == 1 ? TRUE : FALSE;
    $report_options['dim_servicecategory'] = $form_state['values']['dim_servicecategory'] == 1 ? TRUE : FALSE;
    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
    
  }

  $report_data = ErpalCrmReportsSales::load($report_options);

  $data = !empty($report_data['data']) ? $report_data['data'] : array();
  
  $data = _erpal_reports_flatten_and_sort_data_for_charts($data, $report_options);

  if ($data) {
    $build[] = _erpal_reports_visualize($report_data['report_id'], $data, 'ErpalCrmReportsSales');       
  }

  return $build;
}

function erpal_crm_reports_expense_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Report updated'));
  
  //save the POST parameters in order to restore the form after the batch process
  $_SESSION['erpal_reports']['values'] = $form_state['values'];
}

function erpal_crm_reports_expense_report_form() {
  $format = _erpal_basic_helper_date_format_date_only();
  
  $form = array();
  $form['date_from'] = array(
    '#title' => t('Date from'),
    '#type' => 'date_popup',
    '#date_format' => $format,  
  );

  $form['date_to'] = array(
      '#title' => t('Date till'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['scaling'] = _erpal_reports_form_field_for_scaling();

  $form['contractors'] = _erpal_reports_form_field_for_customer(t('Contractors'));

  $form['expense_categories'] = _erpal_reports_form_field_for_expense_category(t('Expense categories'));

  $form['dim_contractor'] = array(
      '#title' => t('Dimension: Contractor'),
      '#type' => 'checkbox'
  );

  $form['dim_expensecategory'] = array(
      '#title' => t('Dimension: Expense category'),
      '#type' => 'checkbox'
  );
  
  _erpal_reports_add_report_basic_form($form);

  return $form;
}

function erpal_crm_reports_expense_report_view() {
  $form_state = array();
  $form_state_old = array();
  module_load_include('inc', 'erpal_reports', 'includes/erpal_reports.batch');
  erpal_report_restore_form_post_data($form_state_old);

  if (!empty($form_state_old['values'])) {    
    $form_state = $form_state_old;    
  }

  $form = drupal_build_form('erpal_crm_reports_expense_report_form', $form_state);
  
  $build['form'] = $form;

  if (!empty($form_state_old['values'])) {  //indicates that the form has already been submitted 
    $form_state['values']['no_cache'] = FALSE;  //otherwise the report will be created again and again
  }
  
  $report_options = array();
  if ($form_state['submitted']) {
    if (!empty($form_state['values']['date_from'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_from']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_from'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (!empty($form_state['values']['date_to'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_to']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_to'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (!empty($form_state['values']['contractors'])) {
      $report_options['contractors'] = array_keys($form_state['values']['contractors']);
    }

    if (!empty($form_state['values']['expense_categories'])) {
      $report_options['expense_categories'] = array_keys($form_state['values']['expense_categories']);
    }

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['dim_contractor'] = $form_state['values']['dim_contractor'] == 1 ? TRUE : FALSE;
    $report_options['dim_expensecategory'] = $form_state['values']['dim_expensecategory'] == 1 ? TRUE : FALSE;   
    
    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
  }

  $report_options['use_batch'] = TRUE;      
  $report_data = ErpalCrmReportsExpense::load($report_options);

  $data = !empty($report_data['data']) ? $report_data['data'] : array();  
  $data = _erpal_reports_flatten_and_sort_data_for_charts($data, $report_options);

  if ($data) {
    $build[] = _erpal_reports_visualize($report_data['report_id'], $data, 'ErpalCrmReportsExpense');    
  }

  return $build;
}

function erpal_crm_reports_lead_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Report updated'));
}

function erpal_crm_reports_lead_report_form() {
  $format = _erpal_basic_helper_date_format_date_only();

  $form['date_from'] = array(
      '#title' => t('Date from'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['date_to'] = array(
      '#title' => t('Date till'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['scaling'] = _erpal_reports_form_field_for_scaling();

  $activity_status_terms = _erpal_crm_reports_get_activity_status_terms();
  $form['activity_status'] = array(
    '#title' => t('Activity status'),
    '#type' => 'select',
    '#options' => $activity_status_terms,
    '#multiple' => true,
  );
  
  $form['dim_activity_status'] = array(
      '#title' => t('Dimension: Activity status'),
      '#type' => 'checkbox'
  );
  
  _erpal_reports_add_report_basic_form($form);

  return $form;
}

function erpal_crm_reports_lead_report_view($form_state = array()) {
  $form = drupal_build_form('erpal_crm_reports_lead_report_form', $form_state);
  $build['form'] = $form;

  $report_options = array();
  if ($form_state['submitted']) {
    if (!empty($form_state['values']['date_from'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_from']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_from'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (!empty($form_state['values']['date_to'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_to']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_to'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (count($form_state['values']['activity_status']) > 0) {
      $report_options['activity_status'] = array_keys($form_state['values']['activity_status']);
    }

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['dim_activity_status'] = $form_state['values']['dim_activity_status'] == 1 ? TRUE : FALSE;    
    
    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
  }

  $report_data = ErpalCrmReportsLead::load($report_options);

  $data = !empty($report_data['data']) ? $report_data['data'] : array();
  $data = _erpal_reports_flatten_and_sort_data_for_charts($data, $report_options);

  if ($data) {
    $build[] = _erpal_reports_visualize($report_data['report_id'], $data, 'ErpalCrmReportsLead');    
  }

  return $build;
}

function erpal_crm_reports_customer_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Report updated'));
}

function erpal_crm_reports_customer_report_form() {
  $format = _erpal_basic_helper_date_format_date_only();

  $form['date_from'] = array(
      '#title' => t('Date from'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['date_to'] = array(
      '#title' => t('Date till'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['scaling'] = _erpal_reports_form_field_for_scaling();

  $form['customers'] = _erpal_reports_form_field_for_customer(t('Customers'));

  $form['min_orders'] = array(
      '#title' => t('Minimum amount of orders in the date range'),
      '#type' => 'textfield'
  );
  $form['min_sales'] = array(
      '#title' => t('Minimum sales volume in the date range'),
      '#type' => 'textfield'
  );
  $form['dim_customercategory'] = array(
      '#title' => t('Dimension: Customer category'),
      '#type' => 'checkbox'
  );
  $form['dim_customer'] = array(
      '#title' => t('Dimension: Customer'),
      '#type' => 'checkbox'
  );
  
  _erpal_reports_add_report_basic_form($form);

  return $form;
}

function erpal_crm_reports_customer_report_view() {
  $form_state = array();
  $form = drupal_build_form('erpal_crm_reports_customer_report_form', $form_state);
  $build['form'] = $form;

  $report_options = array();
  if ($form_state['submitted']) {
    if (!empty($form_state['values']['date_from'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_from']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_from'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (!empty($form_state['values']['date_to'])) {
      $date_from_array = date_parse_from_format(DATE_FORMAT_DATE, $form_state['values']['date_to']);
      if (count($date_from_array['errors']) == 0) {
        $report_options['date_to'] = mktime(0, 0, 0, $date_from_array['month'], $date_from_array['day'], $date_from_array['year']);
      }
    }

    if (count($form_state['values']['customers']) > 0) {
      $report_options['customers'] = array_keys($form_state['values']['customers']);
    }

    if (!empty($form_state['values']['min_sales']) && intval($form_state['values']['min_sales']) > 0) {
      $report_options['min_sales'] = intval($form_state['values']['min_sales']);
    }

      if (!empty($form_state['values']['min_orders']) && intval($form_state['values']['min_orders']) > 0) {
      $report_options['min_orders'] = intval($form_state['values']['min_orders']);
    }

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['dim_customercategory'] = $form_state['values']['dim_customercategory'] == 1 ? TRUE : FALSE;
    $report_options['dim_customer'] = $form_state['values']['dim_customer'] == 1 ? TRUE : FALSE;
    
    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
  }

  $report_data = ErpalCrmReportsCustomerReport::load($report_options);
  $data = !empty($report_data['data']) ? $report_data['data'] : array();
  $data = _erpal_reports_flatten_and_sort_data_for_charts($data, $report_options);

  if ($data) {
    $build[] = _erpal_reports_visualize($report_data['report_id'], $data, 'ErpalCrmReportsCustomerReport'); 
  }

  return $build;
}
