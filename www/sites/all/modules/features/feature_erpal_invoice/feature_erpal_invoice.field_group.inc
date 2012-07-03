<?php
/**
 * @file
 * feature_erpal_invoice.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_erpal_invoice_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notes|node|erpal_invoice|form';
  $field_group->group_name = 'group_notes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notes',
    'weight' => '13',
    'children' => array(
      0 => 'field_note',
      1 => 'token_tree',
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
  $export['group_notes|node|erpal_invoice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_order_numbers|node|erpal_invoice|form';
  $field_group->group_name = 'group_order_numbers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Order numbers',
    'weight' => '3',
    'children' => array(
      0 => 'field_order_number_extern',
      1 => 'field_order_number_intern',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Order numbers',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_order_numbers|node|erpal_invoice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_purchasing|field_collection_item|field_pricing|form';
  $field_group->group_name = 'group_purchasing';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_pricing';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Purchasing',
    'weight' => '7',
    'children' => array(
      0 => 'field_buy_currency',
      1 => 'field_buy_price',
      2 => 'field_buy_vat_rate',
      3 => 'field_contractor_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Purchasing',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_purchasing|field_collection_item|field_pricing|form'] = $field_group;

  return $export;
}
