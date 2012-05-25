<?php
/**
 * @file
 * feature_erpal_crm.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_crm_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
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
function feature_erpal_crm_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_crm_node_info() {
  $items = array(
    'erpal_crm_activity' => array(
      'name' => t('erpal_crm_activity'),
      'base' => 'node_content',
      'description' => t('This is a activity with a contact, e.g a proposal, project request and other conversations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
