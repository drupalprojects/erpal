<?php
/**
 * @file
 * erpal_heartbeat.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_heartbeat_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_heartbeat';
  $cat_item->name = 'Erpal Heartbeat (default)';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Heartbeat';
  $cat_item->path = 'heartbeat/all';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'heartbeat/all',
    'arguments' => array(),
    'name' => 'Erpal Heartbeat (default)',
    'path' => 'heartbeat/all',
    'category' => 'Heartbeat',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'heartbeat/all',
        'path_router' => 'heartbeat/all',
        'path_original' => 'heartbeat/all',
        'path_pattern' => 'heartbeat/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Heartbeat',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => TRUE,
        'machine_name' => 'heartbeat_all',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      1 => array(
        'path' => 'heartbeat',
        'path_router' => 'heartbeat',
        'path_original' => 'heartbeat',
        'path_pattern' => 'heartbeat',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Own heartbeat',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'heartbeat_own',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_heartbeat',
    'path_original' => 'heartbeat/all',
    'path_pattern' => 'heartbeat/%',
    'path_query' => array(),
    'path_router' => 'heartbeat/all',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -7;
  $export['erpal_heartbeat'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_heartbeat_own_heartbeat';
  $cat_item->name = 'Erpal Heartbeat: Own heartbeat';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Heartbeat';
  $cat_item->path = 'heartbeat';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'heartbeat/all',
    'arguments' => array(),
    'name' => 'Erpal Heartbeat: Own heartbeat',
    'path' => 'heartbeat',
    'category' => 'Heartbeat',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'heartbeat/all',
        'path_router' => 'heartbeat/all',
        'path_original' => 'heartbeat/all',
        'path_pattern' => 'heartbeat/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Heartbeat',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_heartbeat|heartbeat_all',
      ),
      1 => array(
        'path' => 'heartbeat',
        'path_router' => 'heartbeat',
        'path_original' => 'heartbeat',
        'path_pattern' => 'heartbeat',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Own heartbeat',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_heartbeat|heartbeat_own',
      ),
    ),
    'machine_name' => 'erpal_heartbeat_own_heartbeat',
    'path_original' => 'heartbeat',
    'path_pattern' => 'heartbeat',
    'path_query' => array(),
    'path_router' => 'heartbeat',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -6;
  $export['erpal_heartbeat_own_heartbeat'] = $cat_item;

  return $export;
}
