<?php
/**
 * @file
 * erpal_mail.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_mail_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "finder" && $api == "finder_default") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_mail_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function erpal_mail_node_info() {
  $items = array(
    'erpal_mail' => array(
      'name' => t('Mail'),
      'base' => 'node_content',
      'description' => t('A generic mail.'),
      'has_title' => '1',
      'title_label' => t('Subject'),
      'help' => '',
    ),
  );
  return $items;
}
