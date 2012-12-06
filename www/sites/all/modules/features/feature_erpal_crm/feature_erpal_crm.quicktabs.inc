<?php
/**
 * @file
 * feature_erpal_crm.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function feature_erpal_crm_quicktabs_default_quicktabs() {
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

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'contact_content_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Contact content tabs';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_contact_details_panel',
      'hide_title' => 0,
      'title' => 'Details',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'vid' => 'relations_view',
      'display' => 'panel_pane_1',
      'args' => '%1',
      'title' => 'Relations',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'crm_activities',
      'display' => 'panel_pane_1',
      'args' => '%1',
      'title' => 'Activities',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'invoices',
      'display' => 'panel_pane_1',
      'args' => '%1',
      'title' => 'Invoices',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'contracts',
      'display' => 'panel_pane_2',
      'args' => '%1',
      'title' => 'Contracts',
      'weight' => '-96',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Activities');
  t('Contact content tabs');
  t('Contracts');
  t('Details');
  t('Invoices');
  t('Relations');

  $export['contact_content_tabs'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'customer_activities_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Customer activities tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'crm_activities',
      'display' => 'panel_pane_1',
      'args' => '%1',
      'title' => 'Activities as customer',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'crm_activities',
      'display' => 'panel_pane_6',
      'args' => '%1',
      'title' => 'Activities involved',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Activities as customer');
  t('Activities involved');
  t('Customer activities tabs');

  $export['customer_activities_tabs'] = $quicktabs;

  return $export;
}
