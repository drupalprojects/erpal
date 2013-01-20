<?php
/**
 * @file
 * erpal_contract.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_contract_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cancelation|node|erpal_contract|form';
  $field_group->group_name = 'group_cancelation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contract';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cancelation',
    'weight' => '3',
    'children' => array(
      0 => 'field_cancelation_period',
      1 => 'field_cancelation_period_con',
      2 => 'field_cancelation_period_unit',
      3 => 'field_contract_duration',
      4 => 'field_repeating_duration',
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
  $export['group_cancelation|node|erpal_contract|form'] = $field_group;

  return $export;
}
