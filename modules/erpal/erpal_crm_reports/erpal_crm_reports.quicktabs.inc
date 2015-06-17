<?php
/**
 * @file
 * erpal_crm_reports.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_crm_reports_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'crm_report_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'CRM Report Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'path' => 'reports/crm/sales',
      'title' => 'Sales',
      'weight' => '-100',
      'type' => 'callback',
    ),
    1 => array(
      'path' => 'reports/crm/expense',
      'title' => 'Expense',
      'weight' => '-99',
      'type' => 'callback',
    ),
    2 => array(
      'path' => 'reports/crm/lead',
      'title' => 'Lead',
      'weight' => '-98',
      'type' => 'callback',
    ),
    3 => array(
      'path' => 'reports/crm/customer',
      'title' => 'Customer',
      'weight' => '-97',
      'type' => 'callback',
    ),
    4 => array(
      'path' => 'reports/crm/salesforecast',
      'title' => 'Sales Forecast',
      'weight' => '-96',
      'type' => 'callback',
    ),
    5 => array(
      'vid' => 'customer_forecast',
      'display' => 'panel_pane_1',
      'args' => '',
      'title' => 'Sales Plan',
      'weight' => '-95',
      'type' => 'view',
    ),
    6 => array(
      'vid' => 'expense_forecast',
      'display' => 'panel_pane_1',
      'args' => '',
      'title' => 'Expense Plan',
      'weight' => '-94',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('CRM Report Tabs');
  t('Customer');
  t('Expense');
  t('Expense Plan');
  t('Lead');
  t('Sales');
  t('Sales Forecast');
  t('Sales Plan');

  $export['crm_report_tabs'] = $quicktabs;

  return $export;
}
