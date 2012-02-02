<?php
/**
 * @file
 * erpal_project_spec.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_project_spec_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function erpal_project_spec_node_info() {
  $items = array(
    'erpal_project_spec' => array(
      'name' => t('erpal_project_spec'),
      'base' => 'node_content',
      'description' => t('Content type to create project specifications'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
