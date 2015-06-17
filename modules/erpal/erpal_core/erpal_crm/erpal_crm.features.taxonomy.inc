<?php
/**
 * @file
 * erpal_crm.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function erpal_crm_taxonomy_default_vocabularies() {
  return array(
    'activity_lost_reasons' => array(
      'name' => 'Activity lost reasons',
      'machine_name' => 'activity_lost_reasons',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'activity_origin' => array(
      'name' => 'Activity origin',
      'machine_name' => 'activity_origin',
      'description' => 'Where the activity was started (phone, website, personally e.g.)',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'activity_status_terms' => array(
      'name' => 'Activity status terms',
      'machine_name' => 'activity_status_terms',
      'description' => 'Terms for activity status',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
