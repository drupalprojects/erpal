<?php
/**
 * @file
 * erpal_contract_ui.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_contract_ui_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'contract_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Contract tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'contracts',
      'display' => 'panel_pane_2',
      'args' => '',
      'title' => 'In progress',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'contracts',
      'display' => 'panel_pane_4',
      'args' => '',
      'title' => 'Closed',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'contracts',
      'display' => 'panel_pane_3',
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
  t('Closed');
  t('Contract tabs');
  t('In progress');

  $export['contract_tabs'] = $quicktabs;

  return $export;
}
