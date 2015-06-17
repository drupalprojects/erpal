<?php
/**
 * @file
 * erpal_docs_ui.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_docs_ui_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cat" && $api == "cat") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_docs_ui_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
