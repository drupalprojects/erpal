<?php
/**
 * @file
 * erpal_employee_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_employee_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'general_page_view';
  $path_breadcrumb->name = 'Timekeeping view breadcrumbs';
  $path_breadcrumb->path = 'timekeeping';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Timekeeping',
    ),
    'paths' => array(
      0 => 'timekeeping',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -73;
  $export['general_page_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'timekeeping_all_view_breadcrumb';
  $path_breadcrumb->name = 'Timekeeping all view breadcrumb';
  $path_breadcrumb->path = 'timekeeping/all';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Timekeeping',
    ),
    'paths' => array(
      0 => 'timekeeping/all',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -74;
  $export['timekeeping_all_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'timekeeping_node_breadcrumb';
  $path_breadcrumb->name = 'Timekeeping node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Timekeeping',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'timekeeping',
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
              'erpal_working_time' => 'erpal_working_time',
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
  $export['timekeeping_node_breadcrumb'] = $path_breadcrumb;

  return $export;
}
