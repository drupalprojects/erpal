<?php
/**
 * @file
 * erpal_contract.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function erpal_contract_taxonomy_default_vocabularies() {
  return array(
    'contract_types' => array(
      'name' => 'Contract types',
      'machine_name' => 'contract_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
