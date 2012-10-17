<?php
/**
 * @file
 * feature_erpal_basic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_basic_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "features_plumber" && $api == "features_plumber_records") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
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
function feature_erpal_basic_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_date_item_type().
 */
function feature_erpal_basic_default_date_item_type() {
  $items = array();
  $items['simple_date'] = entity_import('date_item_type', '{
    "name" : "simple_date",
    "label" : "simple date",
    "locked" : "0",
    "weight" : "0",
    "data" : null,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_basic_node_info() {
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
