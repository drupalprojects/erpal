<?php
/**
 * @file
 * erpal_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_calendar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_date_item_type().
 */
function erpal_calendar_default_date_item_type() {
  $items = array();
  $items['simple_date'] = entity_import('date_item_type', '{
    "name" : "simple_date",
    "label" : "simple date",
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function erpal_calendar_node_info() {
  $items = array(
    'erpal_date' => array(
      'name' => t('date'),
      'base' => 'node_content',
      'description' => t('A content type for calendar dates in ERPAL'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
