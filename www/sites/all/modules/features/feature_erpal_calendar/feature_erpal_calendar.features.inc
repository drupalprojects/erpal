<?php
/**
 * @file
 * feature_erpal_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_calendar_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_erpal_calendar_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_date_item_field_config().
 */
function feature_erpal_calendar_default_date_item_field_config() {
  $items = array();
  $items['13'] = entity_import('date_item_field_config', '{
    "date_item_field_config_id" : "13",
    "field_name" : "field_date_repeat",
    "entity_type" : "node",
    "bundle" : "erpal_date",
    "date_item_type" : "simple_date",
    "settings" : "a:2:{s:16:\\u0022create_date_item\\u0022;i:1;s:14:\\u0022date_item_type\\u0022;s:11:\\u0022simple_date\\u0022;}",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_calendar_node_info() {
  $items = array(
    'erpal_date' => array(
      'name' => t('Date'),
      'base' => 'node_content',
      'description' => t('A content type for calendar dates in ERPAL'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
