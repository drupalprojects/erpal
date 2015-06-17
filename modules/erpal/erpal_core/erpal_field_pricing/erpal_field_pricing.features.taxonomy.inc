<?php
/**
 * @file
 * erpal_field_pricing.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function erpal_field_pricing_taxonomy_default_vocabularies() {
  return array(
    'expense_category_terms' => array(
      'name' => 'Expense category terms',
      'machine_name' => 'expense_category_terms',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'service_category_terms' => array(
      'name' => 'Service category terms',
      'machine_name' => 'service_category_terms',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
