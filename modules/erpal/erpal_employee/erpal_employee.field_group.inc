<?php
/**
 * @file
 * erpal_employee.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_employee_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_working_time_form_basics|node|erpal_working_time|form';
  $field_group->group_name = 'group_working_time_form_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_working_time';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '0',
    'children' => array(
      0 => 'field_date_time',
      1 => 'field_working_time_type',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-working-time',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_working_time_form_basics|node|erpal_working_time|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_working_time_form_breaks|node|erpal_working_time|form';
  $field_group->group_name = 'group_working_time_form_breaks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_working_time';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Breaks',
    'weight' => '1',
    'children' => array(
      0 => 'field_date_times',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Breaks',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-breaks',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_working_time_form_breaks|node|erpal_working_time|form'] = $field_group;

  return $export;
}
