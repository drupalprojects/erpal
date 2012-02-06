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
  if ($module == "features_plumber" && $api == "features_plumber_records") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
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
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_project_basic_node_info() {
  $items = array(
    'erpal_project' => array(
      'name' => t('erpal_project'),
      'base' => 'node_content',
      'description' => t('A Project in ERPAL'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'erpal_task' => array(
      'name' => t('erpal_task'),
      'base' => 'node_content',
      'description' => t('Basic content type for tasks'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
