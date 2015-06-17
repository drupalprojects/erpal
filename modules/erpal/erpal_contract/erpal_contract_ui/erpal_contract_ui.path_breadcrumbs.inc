<?php
/**
 * @file
 * erpal_contract_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_contract_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'contract_node_breadcrumb';
  $path_breadcrumb->name = 'Contract node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contracts',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'contracts',
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
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'erpal_contract' => 'erpal_contract',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -76;
  $export['contract_node_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'contracts_view_breadcrumb';
  $path_breadcrumb->name = 'Contracts view breadcrumb';
  $path_breadcrumb->path = 'contracts';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contracts',
    ),
    'paths' => array(
      0 => 'contracts',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -75;
  $export['contracts_view_breadcrumb'] = $path_breadcrumb;

  return $export;
}
