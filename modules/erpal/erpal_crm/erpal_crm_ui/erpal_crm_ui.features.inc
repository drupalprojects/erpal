<?php
/**
 * @file
 * erpal_crm_ui.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_crm_ui_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_crm_ui_views_api() {
  return array("api" => "3.0");
}
