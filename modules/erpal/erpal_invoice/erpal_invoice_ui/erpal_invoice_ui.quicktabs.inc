<?php
/**
 * @file
 * erpal_invoice_ui.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_invoice_ui_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'billables_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Billables tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'billables',
      'display' => 'panel_pane_3',
      'args' => '',
      'title' => 'Customers',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'billables',
      'display' => 'panel_pane_4',
      'args' => '',
      'title' => 'Contractors',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Billables tabs');
  t('Contractors');
  t('Customers');

  $export['billables_tabs'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'invoice_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Invoice tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'invoices',
      'display' => 'panel_pane_4',
      'args' => '',
      'title' => 'Not paid',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'invoices',
      'display' => 'panel_pane_3',
      'args' => '',
      'title' => 'Paid',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'invoices',
      'display' => 'panel_pane_5',
      'args' => '',
      'title' => 'Canceled',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'invoices',
      'display' => 'panel_pane_2',
      'args' => '',
      'title' => 'All',
      'weight' => '-97',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('All');
  t('Canceled');
  t('Invoice tabs');
  t('Not paid');
  t('Paid');

  $export['invoice_tabs'] = $quicktabs;

  return $export;
}
