<?php
/**
 * @file
 * erpal_invoice.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_invoice_ctools_plugin_api() {
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
 * Implements hook_node_info().
 */
function erpal_invoice_node_info() {
  $items = array(
    'erpal_invoice' => array(
      'name' => t('Invoice'),
      'base' => 'node_content',
      'description' => t('Content type for creating an invoice'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
