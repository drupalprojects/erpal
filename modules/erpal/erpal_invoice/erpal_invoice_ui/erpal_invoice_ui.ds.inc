<?php
/**
 * @file
 * erpal_invoice_ui.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_invoice_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_invoice|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_invoice';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'field_contractor_ref',
        1 => 'field_customer_ref',
        2 => 'field_addition_to_address',
        3 => 'field_invoice_address_id',
      ),
      'advancedleft' => array(
        0 => 'field_billables_ref',
        1 => 'field_skonto',
        2 => 'field_currency',
        3 => 'group_notes',
        4 => 'field_note',
        5 => 'field_asset_files',
        6 => 'field_invoice_exported',
      ),
      'hidden' => array(
        0 => 'title',
        1 => 'group_invoice_left',
        2 => 'path',
        3 => 'group_invoice_right',
        4 => 'field_invoice_total',
        5 => 'group_invoice_bottom',
        6 => 'field_invoice_vat',
        7 => 'field_auto_note',
        8 => 'group_invoice_sonstiges',
        9 => 'field_price_no_vat',
        10 => 'field_payment_date',
        11 => '_add_existing_field',
      ),
      'right' => array(
        0 => 'group_order_numbers',
        1 => 'field_invoice_number',
        2 => 'field_invoice_date',
        3 => 'field_credit_period',
        4 => 'field_order_number_extern',
        5 => 'field_order_number_intern',
        6 => 'field_payed',
      ),
    ),
    'fields' => array(
      'field_contractor_ref' => 'left',
      'field_billables_ref' => 'advancedleft',
      'field_customer_ref' => 'left',
      'field_skonto' => 'advancedleft',
      'field_addition_to_address' => 'left',
      'field_invoice_address_id' => 'left',
      'title' => 'hidden',
      'field_currency' => 'advancedleft',
      'group_invoice_left' => 'hidden',
      'group_order_numbers' => 'right',
      'group_notes' => 'advancedleft',
      'path' => 'hidden',
      'group_invoice_right' => 'hidden',
      'field_invoice_total' => 'hidden',
      'field_invoice_number' => 'right',
      'field_invoice_date' => 'right',
      'group_invoice_bottom' => 'hidden',
      'field_invoice_vat' => 'hidden',
      'field_auto_note' => 'hidden',
      'field_credit_period' => 'right',
      'group_invoice_sonstiges' => 'hidden',
      'field_order_number_extern' => 'right',
      'field_order_number_intern' => 'right',
      'field_price_no_vat' => 'hidden',
      'field_payed' => 'right',
      'field_payment_date' => 'hidden',
      '_add_existing_field' => 'hidden',
      'field_note' => 'advancedleft',
      'field_asset_files' => 'advancedleft',
      'field_invoice_exported' => 'advancedleft',
    ),
    'classes' => array(),
  );
  $export['node|erpal_invoice|form'] = $ds_layout;

  return $export;
}
