<?php
/**
 * @file
 * erpal_basic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_basic_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_basic_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function erpal_basic_node_info() {
  $items = array(
    'erpal_contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => t('This is the basic content type for contacts in ERPAL'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => '',
    ),
  );
  return $items;
}
