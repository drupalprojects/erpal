<?php
/**
 * @file
 * erpal_invoice_ui.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_invoice_ui_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_existing_pages_disabled_billable_view_page';
  $strongarm->value = FALSE;
  $export['pm_existing_pages_disabled_billable_view_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_existing_pages_disabled_payment_view';
  $strongarm->value = FALSE;
  $export['pm_existing_pages_disabled_payment_view'] = $strongarm;

  return $export;
}
