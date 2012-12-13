<?php
/**
 * @file
 * feature_erpal_calendar.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function feature_erpal_calendar_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'calendar';
  $pm_existing_page->label = 'Calendar';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'calendar/global
calendar/global/year
calendar/global/month
calendar/global/week
calendar/global/day';
  $export['calendar'] = $pm_existing_page;

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'date_item_panel';
  $pm_existing_page->label = 'Date item panel';
  $pm_existing_page->context = 'entity|date_item|date_item_id';
  $pm_existing_page->paths = 'date_item/%date_item';
  $export['date_item_panel'] = $pm_existing_page;

  return $export;
}