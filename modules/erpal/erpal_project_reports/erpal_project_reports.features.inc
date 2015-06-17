<?php
/**
 * @file
 * erpal_project_reports.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_project_reports_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cat" && $api == "cat") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_erpal_reports_type().
 */
function erpal_project_reports_default_erpal_reports_type() {
  $items = array();
  $items['erpal_project_active_projects_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_project_active_projects_reports",
    "name" : "Erpal Project Active Projects Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  $items['erpal_project_management_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_project_management_reports",
    "name" : "Erpal Project Management Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  $items['erpal_project_profit_margin_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_project_profit_margin_reports",
    "name" : "Erpal Project Profit Margin Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  $items['erpal_project_timetracking_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_project_timetracking_reports",
    "name" : "Erpal Project Timetracking Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  return $items;
}
