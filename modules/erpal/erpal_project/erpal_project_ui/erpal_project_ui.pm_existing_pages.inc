<?php
/**
 * @file
 * erpal_project_ui.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function erpal_project_ui_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'budget_view_page';
  $pm_existing_page->label = 'Budget view page';
  $pm_existing_page->context = 'entity|budget|budget_id';
  $pm_existing_page->paths = 'budget/%budget';
  $export['budget_view_page'] = $pm_existing_page;

  return $export;
}
