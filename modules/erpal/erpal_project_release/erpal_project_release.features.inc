<?php
/**
 * @file
 * erpal_project_release.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_project_release_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function erpal_project_release_node_info() {
  $items = array(
    'erpal_project_release' => array(
      'name' => t('Project release'),
      'base' => 'node_content',
      'description' => t('A node to create project releases in ERPAL'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
