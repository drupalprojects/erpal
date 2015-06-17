<?php
/**
 * @file
 * erpal_invoice.features.inc
 */

/**
 * Implements hook_default_billable_type().
 */
function erpal_invoice_default_billable_type() {
  $items = array();
  $items['billable'] = entity_import('billable_type', '{
    "type" : "billable",
    "label" : "Billable",
    "weight" : 0,
    "description" : "A billable that represents output to bill or expenses to pay."
  }');
  $items['unbillable'] = entity_import('billable_type', '{
    "type" : "unbillable",
    "label" : "Unbillable",
    "weight" : 0,
    "description" : "These are billables to track expenses or revenues that are not billable directly."
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_invoice_ctools_plugin_api($module = NULL, $api = NULL) {
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
  drupal_alter('node_info', $items);
  return $items;
}
