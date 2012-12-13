<?php
/**
 * @file
 * feature_erpal_employee.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_employee_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_employee_node_info() {
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
  return $items;
}
