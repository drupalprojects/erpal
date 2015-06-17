<?php
/**
 * @file
 * erpal_calendar.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function erpal_calendar_taxonomy_default_vocabularies() {
  return array(
    'date_item_tags' => array(
      'name' => 'Date item tags',
      'machine_name' => 'date_item_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
