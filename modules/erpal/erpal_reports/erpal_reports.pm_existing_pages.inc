<?php
/**
 * @file
 * erpal_reports.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function erpal_reports_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'report_view';
  $pm_existing_page->label = 'Report view';
  $pm_existing_page->context = 'entity|erpal_reports|id';
  $pm_existing_page->paths = 'erpal/reports/%erpal_reports';
  $export['report_view'] = $pm_existing_page;

  return $export;
}
