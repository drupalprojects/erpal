<?php
/**
 * @file
 * erpal_projects_books_access.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function erpal_projects_books_access_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_project_team-field_book_permissions'
  $field_instances['field_collection_item-field_project_team-field_book_permissions'] = array(
    'bundle' => 'field_project_team',
    'comment_enabled' => 0,
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_book_permissions',
    'label' => 'Document permissions',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Document permissions');

  return $field_instances;
}
