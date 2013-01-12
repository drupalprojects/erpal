<?php
/**
 * @file
 * erpal_project_ui.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_project_ui_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_existing_pages_disabled_budget_view_page';
  $strongarm->value = FALSE;
  $export['pm_existing_pages_disabled_budget_view_page'] = $strongarm;

  return $export;
}
