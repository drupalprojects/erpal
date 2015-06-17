<?php
/**
 * @file
 * erpal_crm_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_crm_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'activities_view_breadcrumb';
  $path_breadcrumb->name = 'Activities view breadcrumb';
  $path_breadcrumb->path = 'activities';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Activities',
    ),
    'paths' => array(
      0 => 'activities',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -98;
  $export['activities_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'activity_node_breadcrumb';
  $path_breadcrumb->name = 'Activitiy node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Activities',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'activities',
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
              'erpal_crm_activity' => 'erpal_crm_activity',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -97;
  $export['activity_node_breadcrumb'] = $path_breadcrumb;

  return $export;
}
