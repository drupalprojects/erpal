<?php
/**
 * @file
 * erpal_projects_books_access.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function erpal_projects_books_access_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_book_permissions'
  $field_bases['field_book_permissions'] = array(
    'active' => 1,
    'cardinality' => 2,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_book_permissions',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'view_books' => 'View documents',
        'update_books' => 'Update documents',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
