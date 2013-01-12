<?php
/**
 * @file
 * erpal_contract.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_contract_ui_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_contract_ui_views_api() {
  return array("api" => "3.0");
}
