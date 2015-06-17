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
        0 => 'group_invoice_form_basics',
        1 => 'field_contractor_ref',
        2 => 'group_order_numbers',
        3 => 'field_customer_ref',
        4 => 'field_invoice_address_id',
        5 => 'group_invoice_billables',
        6 => 'field_billables_ref',
        7 => 'field_shipping_address_id',
        8 => 'field_skonto',
        9 => 'field_invoice_number',
        10 => 'field_invoice_date',
        11 => 'group_invoice_form_skonto',
        12 => 'group_invoice_pdf',
        13 => 'field_order_number_extern',
        14 => 'field_payed',
        15 => 'field_credit_period',
        16 => 'group_notes',
        17 => 'field_order_number_intern',
        18 => 'field_currency',
        19 => 'field_note',
        20 => 'field_asset_files',
      ),
      'hidden' => array(
        0 => 'title',
        1 => 'path',
        2 => 'field_invoice_total',
        3 => 'field_invoice_vat',
        4 => 'field_auto_note',
        5 => 'field_price_no_vat',
        6 => 'field_payment_date',
        7 => 'field_invoice_exported',
        8 => 'field_saldo',
        9 => 'group_invoice_addresses',
        10 => '_add_existing_field',
        11 => 'group_invoice_sonstiges',
      ),
    ),
    'fields' => array(
      'group_invoice_form_basics' => 'left',
      'field_contractor_ref' => 'left',
      'group_order_numbers' => 'left',
      'field_customer_ref' => 'left',
      'field_invoice_address_id' => 'left',
      'title' => 'hidden',
      'group_invoice_billables' => 'left',
      'path' => 'hidden',
      'field_billables_ref' => 'left',
      'field_shipping_address_id' => 'left',
      'field_skonto' => 'left',
      'field_invoice_total' => 'hidden',
      'field_invoice_number' => 'left',
      'field_invoice_date' => 'left',
      'group_invoice_form_skonto' => 'left',
      'field_invoice_vat' => 'hidden',
      'field_auto_note' => 'hidden',
      'group_invoice_pdf' => 'left',
      'field_order_number_extern' => 'left',
      'field_payed' => 'left',
      'field_credit_period' => 'left',
      'group_notes' => 'left',
      'field_order_number_intern' => 'left',
      'field_price_no_vat' => 'hidden',
      'field_payment_date' => 'hidden',
      'field_currency' => 'left',
      'field_invoice_exported' => 'hidden',
      'field_saldo' => 'hidden',
      'field_note' => 'left',
      'field_asset_files' => 'left',
      'group_invoice_addresses' => 'hidden',
      '_add_existing_field' => 'hidden',
      'group_invoice_sonstiges' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_invoice|form'] = $ds_layout;

  return $export;
}
