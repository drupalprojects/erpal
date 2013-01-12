<?php
/**
 * @file
 * erpal_crm.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_crm_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chance|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_chance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Chance and financials',
    'weight' => '7',
    'children' => array(
      0 => 'field_chance',
      1 => 'field_volume',
      2 => 'field_expected_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_chance|node|erpal_crm_activity|form'] = $field_group;

  return $export;
}
