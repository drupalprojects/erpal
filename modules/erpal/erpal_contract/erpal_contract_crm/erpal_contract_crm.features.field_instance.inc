<?php
/**
 * @file
 * erpal_contract_crm.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function erpal_contract_crm_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-erpal_contract-field_activity_ref'
  $field_instances['node-erpal_contract-field_activity_ref'] = array(
    'bundle' => 'erpal_contract',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'erpal_basic_helper',
        'settings' => array(
          'link' => 1,
        ),
        'type' => 'entityreference_typed_label',
        'weight' => 11,
      ),
      'node_view' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_activity_ref',
    'label' => 'CRM activity',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'disable',
          'fallback' => 'none',
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'references_dialog_add' => 0,
        'references_dialog_edit' => 0,
        'references_dialog_search' => 0,
        'references_dialog_search_view' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('CRM activity');

  return $field_instances;
}
