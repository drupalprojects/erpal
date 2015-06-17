<?php

function erpal_project_reports_active_projects_report_block_form_validate($form, &$form_state){
}

function erpal_project_reports_active_projects_report_block_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
}

function erpal_project_reports_active_projects_report_block_form()
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
      '#title' => t('Daten neu erzeugen'),
      '#type' => 'checkbox'
  );
  $form['submit'] = array(
      '#value' => t('Aktualisieren'),
      '#ajax' => array(
          'callback' => 'erpal_project_reports_active_projects_report_block_ajax_callback',
          'wrapper' => 'erpal-project-reports-active-projects-report-block',
          'effect' => 'fade',
      ),
      '#type' => 'submit',
  );

  return $form;
}

function erpal_project_reports_active_projects_report_block_ajax_callback($form, &$form_state)
{
  $render = drupal_render(erpal_project_reports_active_projects_report_block($form_state));

  return $render;
}

function erpal_project_reports_active_projects_report_block($form_state = array()) {
  $build = array();
  $form = drupal_build_form('erpal_project_reports_active_projects_report_block_form', $form_state);
  $build['#prefix'] = '<div id="erpal-project-reports-active-projects-report-block">';
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

  $data = _erpal_reports_flatten_and_sort_data_for_charts(ErpalProjectReportsActiveProjects::load($report_options), $report_options);

  if ($data !== FALSE) {
    $options_column = array (
        'title' => t('Active Projects Report'),
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

    for ($i = 0; $i < count($data['titles']); $i ++) {
      $options_column ['fields'] ['values_' . $i] = array (
          'enabled' => TRUE,
          'label' => $data['titles'][$i]
      );
    }

    $build ['column'] = array (
        '#theme' => 'visualization',
        '#options' => $options_column
    );
  }

  return $build;
}

function erpal_project_reports_management_report_block_form_validate($form, &$form_state){
}

function erpal_project_reports_management_report_block_form_submit($form, &$form_state) {
  $form_state['#redirect'] = FALSE;
  $form_state['rebuild'] = TRUE;
}

function erpal_project_reports_management_report_block_form()
{
  $form['projects'] = _erpal_reports_form_field_for_projects(t('Projekt(e)'));

  $form['no_cache'] = array(
      '#title' => t('Daten neu erzeugen'),
      '#type' => 'checkbox'
  );

  $form['submit'] = array(
      '#value' => t('Aktualisieren'),
      '#ajax' => array(
          'callback' => 'erpal_project_reports_management_report_block_ajax_callback',
          'wrapper' => 'erpal-project-reports-management-report-block',
          'effect' => 'fade',
      ),
      '#type' => 'submit',
  );

  return $form;
}

function erpal_project_reports_management_report_block_ajax_callback($form, &$form_state)
{
  $render = drupal_render(erpal_project_reports_management_report_block($form_state));

  return $render;
}

function erpal_project_reports_management_report_block($form_state = array()) {
  $build = array();
  $form = drupal_build_form('erpal_project_reports_management_report_block_form', $form_state);
  $build['#prefix'] = '<div id="erpal-project-reports-management-report-block">';
  $build['#suffix'] = '</div>';
  $build['form'] = $form;

  $report_options = array();
  if ($form_state['submitted']) {
    if (count($form_state['values']['projects']) > 0) {
      $report_options['projects'] = array_keys($form_state['values']['projects']);
    }

    $report_options['no_cache'] = $form_state['values']['no_cache'] == 1 ? TRUE : FALSE;
  }

  $data = ErpalProjectReportsManagementReport::load($report_options);

  if ($data !== FALSE) {
    $build ['column'] = array (
        '#theme' => 'table',
        '#header' => array('Typ', 'Anzahl'),
        '#rows' => array(array(t('Offene Aufgaben'), $data['open']),
                         array(t('Überfällige Aufgaben'), $data['overdue']),
                         array(t('Nicht zugewiesene Aufgaben'), $data['not_assigned']),
                         array(t('Aufgabe ohne Zeitschätzung'), $data['no_time_estimate']))
    );
  }

  return $build;
}


function erpal_project_reports_profit_margin_report_block() {

}

function erpal_project_reports_time_tracking_report_block() {

}