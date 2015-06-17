<?php
/**
 * @file
 * erpal_contacts_importer_feeds.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_contacts_importer_feeds_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_import_erpal_contact';
  $strongarm->value = 0;
  $export['bs_uniquenode_check_on_import_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_import_erpal_contact_erpal_contact';
  $strongarm->value = 0;
  $export['bs_uniquenode_check_on_import_erpal_contact_erpal_contact'] = $strongarm;

  return $export;
}
