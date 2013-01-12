<?php
/**
 * @file
 * erpal_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_project_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|node|erpal_timetracking|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_timetracking';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '4',
    'children' => array(
      0 => 'field_billing_duration',
      1 => 'field_date_time',
      2 => 'field_budget',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_advanced|node|erpal_timetracking|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_status_information|node|erpal_task|view_row_details';
  $field_group->group_name = 'group_status_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'view_row_details';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Status information',
    'weight' => '7',
    'children' => array(
      0 => 'field_progress_percent',
      1 => 'field_task_status_term',
      2 => 'field_priority_term',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Status information',
      'instance_settings' => array(
        'classes' => 'inline_fields',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_status_information|node|erpal_task|view_row_details'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_task_time_group|node|erpal_task|form';
  $field_group->group_name = 'group_task_time_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Time information',
    'weight' => '18',
    'children' => array(
      0 => 'field_date',
      1 => 'field_estimated_time',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Time information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_task_time_group|node|erpal_task|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_time_information|node|erpal_task|view_row_details';
  $field_group->group_name = 'group_time_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'view_row_details';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Time information',
    'weight' => '6',
    'children' => array(
      0 => 'field_date',
      1 => 'field_estimated_time',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Time information',
      'instance_settings' => array(
        'classes' => 'inline_fields',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_time_information|node|erpal_task|view_row_details'] = $field_group;

  return $export;
}
