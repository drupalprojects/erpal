<?php
/**
 * @file
 * erpal_calendar_ui.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_calendar_ui_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_existing_pages_disabled_date_item_panel';
  $strongarm->value = FALSE;
  $export['pm_existing_pages_disabled_date_item_panel'] = $strongarm;

  return $export;
}
