<?php
/**
 * @file
 * erpal_crm.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_crm_ctools_plugin_api($module = NULL, $api = NULL) {
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
function erpal_crm_node_info() {
  $items = array(
    'erpal_crm_activity' => array(
      'name' => t('Activity'),
      'base' => 'node_content',
      'description' => t('This is an activity with a contact, e.g a proposal, project request and other conversations.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
