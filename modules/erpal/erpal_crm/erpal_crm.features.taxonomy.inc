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
    'activity_status_terms' => array(
      'name' => 'Activity status terms',
      'machine_name' => 'activity_status_terms',
      'description' => 'Terms for activity status',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
