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
  $field_group->identifier = 'group_order_numbers|node|erpal_invoice|form';
  $field_group->group_name = 'group_order_numbers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Order numbers',
    'weight' => '7',
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

  return $export;
}
