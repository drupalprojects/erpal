<?php
/**
 * @file
 * erpal_docs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_docs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function erpal_docs_node_info() {
  $items = array(
    'erpal_file' => array(
      'name' => t('File'),
      'base' => 'node_content',
      'description' => t('A file from the global asset file pool'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
