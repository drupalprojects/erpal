<?php
/**
 * @file
 * feature_erpal_dashboard.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_erpal_dashboard_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'front_page_enable';
  $strongarm->value = 1;
  $export['front_page_enable'] = $strongarm;

  return $export;
}
