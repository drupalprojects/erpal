<?php
/**
 * @file
 * erpal_crm_tasks_ui.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_crm_tasks_ui_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
