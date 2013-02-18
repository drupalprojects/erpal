<?php
/**
 * @file
 * feature_erpal_asterisk_profile.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function feature_erpal_asterisk_profile_field_default_fields() {
  $fields = array();

  // Exported field: 'profile2-asterisk_settings-field_phone'.
  $fields['profile2-asterisk_settings-field_phone'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_phone',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => 0,
        'path' => '',
        'profile2_private' => 0,
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'asterisk_settings',
      'comment_enabled' => 0,
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'add' => 'Add',
            'delete' => 'Delete',
            'description' => TRUE,
            'edit' => 'Edit',
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_view',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_phone',
      'label' => 'Listening numbers',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection_table',
        'settings' => array(),
        'type' => 'field_collection_table',
        'weight' => 2,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Listening numbers');

  return $fields;
}
