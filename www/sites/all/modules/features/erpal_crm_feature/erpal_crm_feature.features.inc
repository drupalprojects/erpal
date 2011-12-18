<?php
/**
 * @file
 * erpal_crm_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_crm_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_crm_feature_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function erpal_crm_feature_node_info() {
  $items = array(
    'erpal_contact' => array(
      'name' => t('erpal_contact'),
      'base' => 'node_content',
      'description' => t('This is the basic content type for contacts in ERPAL'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'help' => '',
    ),
  );
  return $items;
}
