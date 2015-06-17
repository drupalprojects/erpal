<?php
/**
 * @file
 * erpal_calendar_ui.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function erpal_calendar_ui_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'date_item_panel';
  $pm_existing_page->label = 'Date item panel';
  $pm_existing_page->context = 'entity|date_item|date_item_id';
  $pm_existing_page->paths = 'date_item/%date_item';
  $export['date_item_panel'] = $pm_existing_page;

  return $export;
}
