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
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "pm_existing_pages" && $api == "pm_existing_pages") {
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
function feature_erpal_calendar_views_api() {
  return array("version" => "3.0");
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
