<?php
/**
 * @file
 * erpal_crm_tasks.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function erpal_crm_tasks_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-erpal_crm_activity-field_task_ref'
  $field_instances['node-erpal_crm_activity-field_task_ref'] = array(
    'bundle' => 'erpal_crm_activity',
    'comment_enabled' => 0,
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'This is the task where time for work on this CRM activity can be tracked.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'erpal_basic_helper',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_typed_label',
        'weight' => 18,
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
    'field_name' => 'field_task_ref',
    'label' => 'Task',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
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
      'weight' => 10,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Task');
  t('This is the task where time for work on this CRM activity can be tracked.');

  return $field_instances;
}
