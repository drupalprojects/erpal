<?php
/**
 * @file
 * erpal_invoice_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_invoice_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'billables_entity_breadcrumb';
  $path_breadcrumb->name = 'Billables entity breadcrumb';
  $path_breadcrumb->path = 'billable/%billable_id';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Invoices',
      1 => 'Billables',
      2 => 'billable/%billable_id',
    ),
    'paths' => array(
      0 => 'invoice/invoices',
      1 => 'invoice/billables',
      2 => '%billable_id:subject',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'billable_id' => array(
        'position' => 1,
        'argument' => 'entity_id:billable',
        'settings' => array(
          'identifier' => 'Billable: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['billables_entity_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'billables_view_breadcrumb';
  $path_breadcrumb->name = 'Billables view breadcrumb';
  $path_breadcrumb->path = 'invoice/billables';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Invoices',
      1 => 'Billables',
    ),
    'paths' => array(
      0 => 'invoice/invoices',
      1 => 'invoice/billables',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['billables_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'invoice_node_breadcrumbs';
  $path_breadcrumb->name = 'Invoice node breadcrumbs';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Invoices',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'invoice/invoices',
      1 => 'node/%nide:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'erpal_invoice' => 'erpal_invoice',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -79;
  $export['invoice_node_breadcrumbs'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'invoices_view_breadcrumb';
  $path_breadcrumb->name = 'Invoices view breadcrumb';
  $path_breadcrumb->path = 'invoice/invoices';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Invoices',
    ),
    'paths' => array(
      0 => 'invoice/invoices',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -80;
  $export['invoices_view_breadcrumb'] = $path_breadcrumb;

  return $export;
}
