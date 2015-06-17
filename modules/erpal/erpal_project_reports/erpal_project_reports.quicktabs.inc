<?php
/**
 * @file
 * erpal_project_reports.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_project_reports_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'project_report_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Project Report Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'path' => 'reports/project/activeprojects',
      'title' => 'Active Projects',
      'weight' => '-100',
      'type' => 'callback',
    ),
    1 => array(
      'path' => 'reports/project/managementreport',
      'title' => 'Management Report',
      'weight' => '-99',
      'type' => 'callback',
    ),
    2 => array(
      'path' => 'reports/project/profitmargin',
      'title' => 'Profit Margin',
      'weight' => '-98',
      'type' => 'callback',
    ),
    3 => array(
      'path' => 'reports/project/timetracking',
      'title' => 'Timetracking',
      'weight' => '-97',
      'type' => 'callback',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Active Projects');
  t('Management Report');
  t('Profit Margin');
  t('Project Report Tabs');
  t('Timetracking');

  $export['project_report_tabs'] = $quicktabs;

  return $export;
}
