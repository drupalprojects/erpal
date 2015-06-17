<?php
/**
 * @file
 * erpal_invoice.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_invoice_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_invoice_addresses|node|erpal_invoice|form';
  $field_group->group_name = 'group_invoice_addresses';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Invoice Addresses',
    'weight' => '13',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_invoice_addresses|node|erpal_invoice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_invoice_billables|node|erpal_invoice|form';
  $field_group->group_name = 'group_invoice_billables';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Billables',
    'weight' => '3',
    'children' => array(
      0 => 'field_billables_ref',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Billables',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-billable',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_invoice_billables|node|erpal_invoice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_invoice_form_basics|node|erpal_invoice|form';
  $field_group->group_name = 'group_invoice_form_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '0',
    'children' => array(
      0 => 'field_contractor_ref',
      1 => 'field_credit_period',
      2 => 'field_currency',
      3 => 'field_customer_ref',
      4 => 'field_invoice_address_id',
      5 => 'field_invoice_date',
      6 => 'field_invoice_number',
      7 => 'field_payed',
      8 => 'field_shipping_address_id',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-invoice',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_invoice_form_basics|node|erpal_invoice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_invoice_form_skonto|node|erpal_invoice|form';
  $field_group->group_name = 'group_invoice_form_skonto';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Skonto',
    'weight' => '6',
    'children' => array(
      0 => 'field_skonto',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Skonto',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-skonto',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_invoice_form_skonto|node|erpal_invoice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_invoice_pdf|node|erpal_invoice|form';
  $field_group->group_name = 'group_invoice_pdf';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Invoice PDF',
    'weight' => '7',
    'children' => array(
      0 => 'field_asset_files',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Invoice PDF',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-pdf',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_invoice_pdf|node|erpal_invoice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_invoice_sonstiges|node|erpal_invoice|form';
  $field_group->group_name = 'group_invoice_sonstiges';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_invoice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Invoice Sonstiges',
    'weight' => '16',
    'children' => array(
      0 => 'field_auto_note',
      1 => 'field_invoice_total',
      2 => 'field_invoice_vat',
      3 => 'field_payment_date',
      4 => 'field_price_no_vat',
      5 => 'title',
      6 => 'path',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Invoice Sonstiges',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_invoice_sonstiges|node|erpal_invoice|form'] = $field_group;

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
    'weight' => '8',
    'children' => array(
      0 => 'field_note',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Notes',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-notes',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
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
    'weight' => '1',
    'children' => array(
      0 => 'field_order_number_extern',
      1 => 'field_order_number_intern',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Order numbers',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-order-numbers',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_order_numbers|node|erpal_invoice|form'] = $field_group;

  return $export;
}
