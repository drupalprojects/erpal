<?php
/**
 * @file
 * erpal_employee.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_employee_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cat" && $api == "cat") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function erpal_employee_node_info() {
  $items = array(
    'erpal_working_time' => array(
      'name' => t('Working time'),
      'base' => 'node_content',
      'description' => t('This node type is for adding working time'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
