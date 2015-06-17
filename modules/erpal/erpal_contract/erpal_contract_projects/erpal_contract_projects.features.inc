<?php
/**
 * @file
 * erpal_contract_projects.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_contract_projects_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
