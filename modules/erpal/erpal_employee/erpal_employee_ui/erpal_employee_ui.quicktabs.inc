<?php
/**
 * @file
 * erpal_employee_ui.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_employee_ui_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'all_timekeeping_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'All timekeeping tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'working_time',
      'display' => 'panel_pane_2',
      'args' => '',
      'title' => 'Day',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'working_times',
      'display' => 'panel_pane_5',
      'args' => '',
      'title' => 'Month',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'working_times',
      'display' => 'panel_pane_4',
      'args' => '',
      'title' => 'Year',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('All timekeeping tabs');
  t('Day');
  t('Month');
  t('Year');

  $export['all_timekeeping_tabs'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'timekeeping_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'User timekeeping tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'working_time',
      'display' => 'panel_pane_1',
      'args' => '',
      'title' => 'Day',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'working_times',
      'display' => 'panel_pane_2',
      'args' => '',
      'title' => 'Month',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'working_times',
      'display' => 'panel_pane_1',
      'args' => '',
      'title' => 'Year',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Day');
  t('Month');
  t('User timekeeping tabs');
  t('Year');

  $export['timekeeping_tabs'] = $quicktabs;

  return $export;
}
