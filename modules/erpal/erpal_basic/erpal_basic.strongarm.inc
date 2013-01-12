<?php
/**
 * @file
 * erpal_basic.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_basic_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_contact';
  $strongarm->value = '1';
  $export['ant_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_contact';
  $strongarm->value = '[erpal_contact:company_name] [erpal_contact:firstname] [erpal_contact:lastname]';
  $export['ant_pattern_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_contact';
  $strongarm->value = 0;
  $export['ant_php_erpal_contact'] = $strongarm;

  return $export;
}
