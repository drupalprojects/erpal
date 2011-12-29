<?php
/**
 * @file
 * erpal_docs_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_docs_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
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
function erpal_docs_feature_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function erpal_docs_feature_node_info() {
  $items = array(
    'erpal_file' => array(
      'name' => t('erpal_file'),
      'base' => 'node_content',
      'description' => t('A file from the global asset file pool'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
