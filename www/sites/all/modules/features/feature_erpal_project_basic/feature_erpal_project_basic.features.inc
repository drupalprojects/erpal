<?php
/**
 * @file
 * feature_erpal_project_basic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_project_basic_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "features_plumber" && $api == "features_plumber_records") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "rel" && $api == "rel") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_erpal_project_basic_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_date_item_field_config().
 */
function feature_erpal_project_basic_default_date_item_field_config() {
  $items = array();
  $items['2'] = entity_import('date_item_field_config', '{
    "date_item_field_config_id" : "2",
    "field_name" : "field_date",
    "entity_type" : "node",
    "bundle" : "erpal_task",
    "settings" : "a:1:{s:16:\\u0022create_date_item\\u0022;i:1;}",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_project_basic_node_info() {
  $items = array(
    'erpal_project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A Project in ERPAL'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'erpal_task' => array(
      'name' => t('Task'),
      'base' => 'node_content',
      'description' => t('Basic content type for tasks'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'erpal_timetracking' => array(
      'name' => t('Timetracking'),
      'base' => 'node_content',
      'description' => t('Content type to create timetracking to nodes'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
