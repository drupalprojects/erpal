<?php

function erpal_project_reports_active_projects_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Report updated'));
}

function erpal_project_reports_active_projects_report_form() {
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
  
  $form['status'] = _erpal_project_reports_form_field_for_project_status();

  $form['scaling'] = _erpal_reports_form_field_for_scaling();

  $form['customers'] = _erpal_reports_form_field_for_customer(t('Customers'));

  $form['customer_categories'] = _erpal_reports_form_field_for_customer_category(t('Service categories'));

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

function erpal_project_reports_active_projects_report_view() {
  $form_state = array();
  $form = drupal_build_form('erpal_project_reports_active_projects_report_form', $form_state);
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

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['dim_customer'] = $form_state['values']['dim_customer'] == 1 ? TRUE : FALSE;
    $report_options['dim_customercategory'] = $form_state['values']['dim_customercategory'] == 1 ? TRUE : FALSE;    
    $report_options['status'] = !empty($form_state['values']['status']) ? $form_state['values']['status'] : array();
    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
  }

  $report_data = ErpalProjectReportsActiveProjects::load($report_options);

  $data = !empty($report_data['data']) ? $report_data['data'] : array();
  $data = _erpal_reports_flatten_and_sort_data_for_charts($data, $report_options);

  if ($data) {
    $build[] = _erpal_reports_visualize($report_data['report_id'], $data, 'ErpalCrmReportsSales');
  }

  return $build;
}

function erpal_project_reports_management_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('UPdate report'));
}

function erpal_project_reports_management_report_form() {
  $form['projects'] = _erpal_reports_form_field_for_projects(t('Projekt(e)'));

  _erpal_reports_add_report_basic_form($form);

  return $form;
}

function erpal_project_reports_management_report_view() {
  $form_state = array();
  $form = drupal_build_form('erpal_project_reports_management_report_form', $form_state);
  $build['form'] = $form;

  $report_options = array();
  if ($form_state['submitted']) {
    if (count($form_state['values']['projects']) > 0) {
      $report_options['projects'] = array_keys($form_state['values']['projects']);
    }
    
    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
  }

  $report_data = ErpalProjectReportsManagementReport::load($report_options);
  $data = !empty($report_data['data']) ? $report_data['data'] : array();
  if ($data) {
    $data = (array)$data;
    $build ['column'] = array (
        '#theme' => 'table',
        '#header' => array('Typ', 'Anzahl'),
        '#rows' => array(array(t('Open tasks'), $data['open']),
                         array(t('Overdue tasks'), $data['overdue']),
                         array(t('Not assigned tasks'), $data['not_assigned']),
                         array(t('Tasks without time estimation'), $data['no_time_estimate']))
    );
  }

  return $build;
}

function erpal_project_reports_time_tracking_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Report updated'));
  
  //save the POST parameters in order to restore the form after the batch process
  $_SESSION['erpal_reports']['values'] = $form_state['values'];  
}

function erpal_project_reports_time_tracking_report_form() {
  $format = _erpal_basic_helper_date_format_date_only();

  $format = _erpal_basic_helper_date_format_date_only();

  $form['date_from'] = array(
      '#title' => t('Date from'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );

  $form['date_till'] = array(
      '#title' => t('Date till'),
      '#type' => 'date_popup',
      '#date_format' => $format,
  );
  
  $profit_options = array('' => t('Ignore'), 'profitable' => t('Profitable'), 'non_profitable' => t('Non-Profitable'));
  $margin_report_need_run = _erpal_project_reports_margin_report_needs_rerun();
  $description = t('Report only projects with respect to their profit and if their was any activity within the last month.');
  if ($margin_report_need_run) {
    $description .= '<br/>'.t('Please !re_run of project margins.', array('!re_run' => l(t('re-run the calculation'), 'reports/project/profit/calculate-all', array('query' => array('destination' => $_GET['q'])))));
  }
  $form['profit_status'] = array(
    '#title' => t('Profit status'),
    '#type' => 'select',
    '#options' => $profit_options,
    '#description' => $description,
  );
  
  $form['profit_treshold'] = array(
    '#title' => t('Profit treshold'),
    '#type' => 'textfield',
    '#description' => t('Projects above this value are profitable, the ones below are not profitable'),
  );
  
  $form['task_categories'] = _erpal_reports_form_field_for_task_category(t('Task categories'));

  $form['projects'] = _erpal_reports_form_field_for_projects(t('Projects'));
  //$form['projects']['#multiple'] = FALSE;

  $form['status'] = _erpal_project_reports_form_field_for_project_status();

  $form['dim_project'] = array(
      '#title' => t('Dimension: Project'),
      '#type' => 'checkbox'
  );

  _erpal_reports_add_report_basic_form($form);

  return $form;
}

function erpal_project_reports_time_tracking_report_view() {
  $form_state = array();
  $form_state_old = array();
  module_load_include('inc', 'erpal_reports', 'includes/erpal_reports.batch');  
  erpal_report_restore_form_post_data($form_state_old);

  if (!empty($form_state_old['values'])) {
    $form_state = $form_state_old;
  }
  
  $form = drupal_build_form('erpal_project_reports_time_tracking_report_form', $form_state);
  $build['form'] = $form;

  if (!empty($form_state_old['values'])) {  //indicates that the form has already been submitted 
    $form_state['values']['no_cache'] = FALSE;  //otherwise the report will be created again and again
  } 
  
  $report_options = array();
  if ($form_state['submitted']) {
    if (count($form_state['values']['task_categories']) > 0) {
      $report_options['task_categories'] = array_keys($form_state['values']['task_categories']);
    }

    if (count($form_state['values']['projects']) > 0) {
      $report_options['projects'] = array_keys($form_state['values']['projects']);
    }

    $report_options['dim_project'] = $form_state['values']['dim_project'] == 1 ? TRUE : FALSE;
    $report_options['status'] = !empty($form_state['values']['status']) == 1 ? $form_state['values']['status'] : array();
    $report_options['profit_status'] = !empty($form_state['values']['profit_status']) ? $form_state['values']['profit_status'] : false;
    $report_options['profit_treshold'] = !empty($form_state['values']['profit_treshold']) ? $form_state['values']['profit_treshold'] : false;    
    $report_options['date_from'] = !empty($form_state['values']['date_from']) ? strtotime($form_state['values']['date_from'].' 00:00:00') : false;
    $report_options['date_till'] = !empty($form_state['values']['date_till']) ? strtotime($form_state['values']['date_till'].' 23:59:59') : false;
    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
  }

  $report_options['use_batch'] = TRUE;
  $report_data = ErpalProjectReportsTimeTracking::load($report_options);

  $data = !empty($report_data['data']) ? $report_data['data'] : array();
  $data = _erpal_reports_flatten_and_sort_data_for_charts($data, $report_options);

  if ($data) {
    $build[] = _erpal_reports_visualize($report_data['report_id'], $data, 'ErpalProjectReportsTimeTracking');
  }

  return $build;
}


function erpal_project_reports_profit_margin_report_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
  drupal_set_message(t('Report updated'));

  //save the POST parameters in order to restore the form after the batch process
  $_SESSION['erpal_reports']['values'] = $form_state['values'];
}

function erpal_project_reports_profit_margin_report_form() {
  $form['projects'] = _erpal_reports_form_field_for_projects(t('Projects'));

  $form['customers'] = _erpal_reports_form_field_for_customer(t('Customers'));
  
  $form['status'] = _erpal_project_reports_form_field_for_project_status();
  
  $profit_options = array('' => t('Ignore'), 'profitable' => t('Profitable'), 'non_profitable' => t('Non-Profitable'));
  $description = t('Report only projects with respect to their profit and if their was any activity within the last month.');

  $form['profit_status'] = array(
    '#title' => t('Profit status'),
    '#type' => 'select',
    '#options' => $profit_options,
    '#description' => $description,
  );
  
  $form['profit_treshold'] = array(
    '#title' => t('Profit treshold'),
    '#type' => 'textfield',
    '#description' => t('Projects above this value are profitable, the ones below are not profitable'),
  );
  
  _erpal_reports_add_report_basic_form($form);

  return $form;
}

/**
* Menu page callback for profit margin report view
*/
function erpal_project_reports_profit_margin_report_view() {

  $form_state = array();
  $form_state_old = array();
  module_load_include('inc', 'erpal_reports', 'includes/erpal_reports.batch');  
  erpal_report_restore_form_post_data($form_state_old);

  if (!empty($form_state_old['values'])) {
    $form_state = $form_state_old;
  }

  $form = drupal_build_form('erpal_project_reports_profit_margin_report_form', $form_state);
  $build['form'] = $form;
   
  if (!empty($form_state_old['values'])) {  //indicates that the form has already been submitted 
    $form_state['values']['no_cache'] = FALSE;  //otherwise the report will be created again and again
  }   
   
  $report_options = array();
  if ($form_state['submitted'] || !empty($form_state_old['values'])) {
    if (count($form_state['values']['projects']) > 0) {
      $report_options['projects'] = array_keys($form_state['values']['projects']);
    }

    if (count($form_state['values']['customers']) > 0) {
      $report_options['customers'] = array_keys($form_state['values']['customers']);
    }

    $report_options['profit_status'] = !empty($form_state['values']['profit_status']) ? $form_state['values']['profit_status'] : false;
    $report_options['profit_treshold'] = !empty($form_state['values']['profit_treshold']) ? $form_state['values']['profit_treshold'] : false;        
    $report_options['status'] = !empty($form_state['values']['status']) ? $form_state['values']['status'] : array();
    _erpal_reports_add_report_basic_form_submit($report_options, $form_state);
  }

  $skip_recreate = erpal_reports_skipp_recreate($form_state, $form_state_old);
  
  
  $report_options['use_batch'] = TRUE;
  $report_data = ErpalProjectReportsProfitMargin::load($report_options, $skip_recreate);

  $data = !empty($report_data['data']) ? $report_data['data'] : array();
  $data = _erpal_reports_flatten_and_sort_data_for_charts($data, $report_options);

  if ($data) {
    $build[] = _erpal_reports_visualize($report_data['report_id'], $data, 'ErpalCrmReportsExpense');    
  }

  return $build;
}