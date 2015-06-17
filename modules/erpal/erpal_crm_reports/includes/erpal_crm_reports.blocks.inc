<?php

function erpal_crm_reports_sales_report_block_form_validate($form, &$form_state){
}

function erpal_crm_reports_sales_report_block_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
}

function erpal_crm_reports_sales_report_block_form()
{
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

  $form['no_cache'] = array(
      '#title' => t('Re-create data'),
      '#type' => 'checkbox'
  );
  $form['submit'] = array(
      '#value' => t('Update'),
      '#ajax' => array(
          'callback' => 'erpal_crm_reports_sales_report_block_ajax_callback',
          'wrapper' => 'erpal-crm-reports-sales-report-block',
          'effect' => 'fade',
      ),
      '#type' => 'submit',
  );

  return $form;
}

function erpal_crm_reports_sales_report_block_ajax_callback($form, &$form_state)
{
  $render = drupal_render(erpal_crm_reports_sales_report_block($form_state));

  return $render;
}

function erpal_crm_reports_sales_report_block($form_state = array())
{
  $build = array();
  $form = drupal_build_form('erpal_crm_reports_sales_report_block_form', $form_state);
  $build['#prefix'] = '<div id="erpal-crm-reports-sales-report-block">';
  $build['#suffix'] = '</div>';
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

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['no_cache'] = $form_state['values']['no_cache'] == 1 ? TRUE : FALSE;
  }

  $data = _erpal_reports_flatten_and_sort_data_for_charts(ErpalCrmReportsSales::load($report_options), $report_options);

  if ($data !== FALSE) {
    $options_column = array (
      'title' => t('CRM Sales Report'),
      'fields' => array (
        'date' => array (
          'label' => t('Date')
        )
      ),
      'xAxis' => array (
        'labelField' => 'date'
      ),
      'data' => $data['data'],
      'type' => 'column',
      'height' => '600px'
    );

    for ($title_index = 0; $title_index < count($data['titles']); $title_index ++) {
      $options_column ['fields'] ['values_' . $title_index] = array (
        'enabled' => TRUE,
        'label' => $data['titles'][$title_index]
      );
    }

    $build ['column'] = array (
        '#theme' => 'visualization',
        '#options' => $options_column
    );
  }

  return $build;
}

function erpal_crm_reports_lead_report_block_form_validate($form, &$form_state){
}

function erpal_crm_reports_lead_report_block_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
}

function erpal_crm_reports_lead_report_block_form()
{
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

  $form['no_cache'] = array(
      '#title' => t('Re-create data'),
      '#type' => 'checkbox'
  );
  $form['submit'] = array(
      '#value' => t('Update'),
      '#ajax' => array(
          'callback' => 'erpal_crm_reports_lead_report_block_ajax_callback',
          'wrapper' => 'erpal-crm-reports-lead-report-block',
          'effect' => 'fade',
      ),
      '#type' => 'submit',
  );

  return $form;
}

function erpal_crm_reports_lead_report_block_ajax_callback($form, &$form_state)
{
  $render = drupal_render(erpal_crm_reports_lead_report_block($form_state));

  return $render;
}

function erpal_crm_reports_lead_report_block($form_state = array())
{
  $build = array();
  $form = drupal_build_form('erpal_crm_reports_lead_report_block_form', $form_state);
  $build['#prefix'] = '<div id="erpal-crm-reports-lead-report-block">';
  $build['#suffix'] = '</div>';
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

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['no_cache'] = $form_state['values']['no_cache'] == 1 ? TRUE : FALSE;
  }

  $data = _erpal_reports_flatten_and_sort_data_for_charts(ErpalCrmReportsLead::load($report_options), $report_options);

  if ($data !== FALSE) {
    $options_column = array (
        'title' => t('CRM Lead Report'),
        'fields' => array (
            'date' => array (
                'label' => t('Date')
            )
        ),
        'xAxis' => array (
            'labelField' => 'date'
        ),
        'data' => $data['data'],
        'type' => 'column',
        'height' => '600px'
    );

    for ($title_index = 0; $title_index < count($data['titles']); $title_index ++) {
      $options_column ['fields'] ['values_' . $title_index] = array (
          'enabled' => TRUE,
          'label' => $data['titles'][$title_index]
      );
    }

    $build ['column'] = array (
        '#theme' => 'visualization',
        '#options' => $options_column
    );
  }

  return $build;
}

function erpal_crm_reports_customer_report_block_form_validate($form, &$form_state){
}

function erpal_crm_reports_customer_report_block_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
}

function erpal_crm_reports_customer_report_block_form()
{
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

  $form['no_cache'] = array(
      '#title' => t('Re-create data'),
      '#type' => 'checkbox'
  );
  $form['submit'] = array(
      '#value' => t('Update'),
      '#ajax' => array(
          'callback' => 'erpal_crm_reports_customer_report_block_ajax_callback',
          'wrapper' => 'erpal-crm-reports-customer-report-block',
          'effect' => 'fade',
      ),
      '#type' => 'submit',
  );

  return $form;
}

function erpal_crm_reports_customer_report_block_ajax_callback($form, &$form_state)
{
  $render = drupal_render(erpal_crm_reports_customer_report_block($form_state));

  return $render;
}

function erpal_crm_reports_customer_report_block($form_state = array())
{
  $build = array();
  $form = drupal_build_form('erpal_crm_reports_customer_report_block_form', $form_state);
  $build['#prefix'] = '<div id="erpal-crm-reports-customer-report-block">';
  $build['#suffix'] = '</div>';
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

    $report_options['scaling'] = $form_state['values']['scaling'];
    $report_options['no_cache'] = $form_state['values']['no_cache'] == 1 ? TRUE : FALSE;
  }

  $data = _erpal_reports_flatten_and_sort_data_for_charts(ErpalCrmReportsCustomerReport::load($report_options), $report_options);

  if ($data !== FALSE) {
    $options_column = array (
        'title' => t('CRM Customer Report'),
        'fields' => array (
            'date' => array (
                'label' => t('Date')
            )
        ),
        'xAxis' => array (
            'labelField' => 'date'
        ),
        'data' => $data['data'],
        'type' => 'column',
        'height' => '600px'
    );

    for ($title_index = 0; $title_index < count($data['titles']); $title_index ++) {
      $options_column ['fields'] ['values_' . $title_index] = array (
          'enabled' => TRUE,
          'label' => $data['titles'][$title_index]
      );
    }

    $build ['column'] = array (
        '#theme' => 'visualization',
        '#options' => $options_column
    );
  }

  return $build;
}