<?php
/**
 * @file
 * erpal_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_availability|profile2|main|form';
  $field_group->group_name = 'group_availability';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Availability',
    'weight' => '5',
    'children' => array(
      0 => 'field_hours_per_day',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Availability',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_availability|profile2|main|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contract|profile2|main|form';
  $field_group->group_name = 'group_contract';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'main';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contract settings',
    'weight' => '1',
    'children' => array(
      0 => 'field_contract_data',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contract settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_contract|profile2|main|form'] = $field_group;

  return $export;
}
