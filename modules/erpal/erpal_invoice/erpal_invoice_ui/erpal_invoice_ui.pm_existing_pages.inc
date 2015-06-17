<?php
/**
 * @file
 * erpal_invoice_ui.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function erpal_invoice_ui_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'billable_view_page';
  $pm_existing_page->label = 'billable_view_page';
  $pm_existing_page->context = 'entity|billable|billable_id';
  $pm_existing_page->paths = 'billable/%billable/view';
  $export['billable_view_page'] = $pm_existing_page;

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'payment_view';
  $pm_existing_page->label = 'Payment view';
  $pm_existing_page->context = 'entity|payment|pid';
  $pm_existing_page->paths = 'payment/%payment';
  $export['payment_view'] = $pm_existing_page;

  return $export;
}
