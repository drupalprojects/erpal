<?php
/**
 * @file
 * erpal_basic.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function erpal_basic_taxonomy_default_vocabularies() {
  return array(
    'address_types' => array(
      'name' => 'Address types',
      'machine_name' => 'address_types',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'company_relation_tags' => array(
      'name' => 'Company relation tags',
      'machine_name' => 'company_relation_tags',
      'description' => 'Describes the position a person has in a company',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'contact_tags' => array(
      'name' => 'Contact Tags',
      'machine_name' => 'contact_tags',
      'description' => 'Tags for Contacts',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'countries' => array(
      'name' => 'Countries',
      'machine_name' => 'countries',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'number_types' => array(
      'name' => 'Number types',
      'machine_name' => 'number_types',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
