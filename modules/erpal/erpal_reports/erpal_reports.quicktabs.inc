<?php
/**
 * @file
 * erpal_reports.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_reports_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'report_dashboard';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Report dashboard';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'report_dashboard',
      'display' => 'panel_pane_3',
      'args' => '',
      'title' => 'Personal',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'report_dashboard',
      'display' => 'panel_pane_1',
      'args' => '',
      'title' => 'Global',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Global');
  t('Personal');
  t('Report dashboard');

  $export['report_dashboard'] = $quicktabs;

  return $export;
}
