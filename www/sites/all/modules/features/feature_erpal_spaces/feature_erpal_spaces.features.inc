<?php
/**
 * @file
 * feature_erpal_spaces.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_spaces_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_erpal_spaces_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_spaces_node_info() {
  $items = array(
    'erpal_space' => array(
      'name' => t('Space'),
      'base' => 'node_content',
      'description' => t('This is a working space for erpal.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
