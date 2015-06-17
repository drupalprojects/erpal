<?php
/**
 * @file
 * erpal_crm_ui.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_crm_ui_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'all_activities_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'All activities tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'crm_activities',
      'display' => 'panel_pane_3',
      'args' => '',
      'title' => 'Missed',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'crm_activities',
      'display' => 'panel_pane_2',
      'args' => '',
      'title' => 'Next',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'crm_activities',
      'display' => 'panel_pane_5',
      'args' => '',
      'title' => 'All',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('All');
  t('All activities tabs');
  t('Missed');
  t('Next');

  $export['all_activities_tabs'] = $quicktabs;

  return $export;
}
