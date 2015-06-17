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
  $field_group->identifier = 'group_advanced|node|erpal_contract|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contract';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'field_activity_ref',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-advanced',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_advanced|node|erpal_contract|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_budget_automation|node|erpal_contract|form';
  $field_group->group_name = 'group_budget_automation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contract';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Budget automation',
    'weight' => '3',
    'children' => array(
      0 => 'field_budget_booking',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Budget automation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-automation',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_budget_automation|node|erpal_contract|form'] = $field_group;

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
    'weight' => '2',
    'children' => array(
      0 => 'field_cancelation_period',
      1 => 'field_cancelation_period_con',
      2 => 'field_cancelation_period_unit',
      3 => 'field_contract_duration',
      4 => 'field_repeating_duration',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Cancelation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-cancel',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_cancelation|node|erpal_contract|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contract_form_basics|node|erpal_contract|form';
  $field_group->group_name = 'group_contract_form_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contract';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '0',
    'children' => array(
      0 => 'field_contract_type',
      1 => 'field_date',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-contract',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contract_form_basics|node|erpal_contract|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contract_form_files|node|erpal_contract|form';
  $field_group->group_name = 'group_contract_form_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contract';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '5',
    'children' => array(
      0 => 'field_asset_files',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-file',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contract_form_files|node|erpal_contract|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contract_form_payment|node|erpal_contract|form';
  $field_group->group_name = 'group_contract_form_payment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contract';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Payment',
    'weight' => '1',
    'children' => array(
      0 => 'field_contract_payment',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Payment',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-pricing',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contract_form_payment|node|erpal_contract|form'] = $field_group;

  return $export;
}
