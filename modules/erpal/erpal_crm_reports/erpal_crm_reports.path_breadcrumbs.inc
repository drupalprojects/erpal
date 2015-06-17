<?php
/**
 * @file
 * erpal_crm_reports.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_crm_reports_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'report_node_breadcrumbs';
  $path_breadcrumb->name = 'Report node breadcrumbs';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'CRM Reports',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'reports/crm',
      1 => 'node/%node:nid',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_customer_forecast' => 'erpal_customer_forecast',
              'erpal_expense_forecast' => 'erpal_expense_forecast',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['report_node_breadcrumbs'] = $path_breadcrumb;

  return $export;
}
