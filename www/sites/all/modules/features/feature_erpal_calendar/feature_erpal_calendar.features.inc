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
 * Implements hook_node_info().
 */
function feature_erpal_calendar_node_info() {
  $items = array(
    'date' => array(
      'name' => t('Date'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
