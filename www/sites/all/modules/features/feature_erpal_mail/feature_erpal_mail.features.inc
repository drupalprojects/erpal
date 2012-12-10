<?php
/**
 * @file
 * feature_erpal_mail.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_mail_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_mail_node_info() {
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
