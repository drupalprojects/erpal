<?php
/**
 * @file
 * feature_erpal_invoice.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_erpal_invoice_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_invoice|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_invoice';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'field_contractor_ref',
        1 => 'field_customer_ref',
        2 => 'field_addition_to_address',
        3 => 'field_invoice_address_id',
      ),
      'right' => array(
        0 => 'group_order_numbers',
        1 => 'field_invoice_number',
        2 => 'field_invoice_date',
        3 => 'field_order_number_extern',
        4 => 'field_credit_period',
        5 => 'field_order_number_intern',
        6 => 'field_payed',
        7 => 'field_payment_date',
      ),
      'footer' => array(
        0 => 'field_billables_ref',
        1 => 'field_skonto',
        2 => 'field_note',
        3 => 'field_currency',
        4 => 'token_tree',
        5 => 'group_notes',
        6 => 'field_asset_files',
        7 => 'field_invoice_exported',
        8 => 'status',
        9 => 'submit',
        10 => 'delete',
      ),
      'hidden' => array(
        0 => 'title',
        1 => 'menu',
        2 => 'name',
        3 => 'link_title',
        4 => 'alias',
        5 => 'comment',
        6 => 'revision',
        7 => 'enabled',
        8 => 'date',
        9 => 'promote',
        10 => 'link',
        11 => 'description',
        12 => 'log',
        13 => 'sticky',
        14 => 'parent',
        15 => 'weight',
        16 => 'order_numbers_token_tree',
        17 => 'preview',
        18 => 'revision_information',
        19 => 'path',
        20 => 'comment_settings',
        21 => 'field_invoice_total',
        22 => 'field_invoice_vat',
        23 => 'field_auto_note',
        24 => 'field_price_no_vat',
        25 => 'author',
        26 => 'options',
        27 => 'additional_settings',
        28 => 'actions',
        29 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_contractor_ref' => 'left',
      'field_customer_ref' => 'left',
      'field_addition_to_address' => 'left',
      'field_invoice_address_id' => 'left',
      'group_order_numbers' => 'right',
      'field_invoice_number' => 'right',
      'field_invoice_date' => 'right',
      'field_order_number_extern' => 'right',
      'field_credit_period' => 'right',
      'field_order_number_intern' => 'right',
      'field_payed' => 'right',
      'field_payment_date' => 'right',
      'field_billables_ref' => 'footer',
      'field_skonto' => 'footer',
      'field_note' => 'footer',
      'field_currency' => 'footer',
      'token_tree' => 'footer',
      'group_notes' => 'footer',
      'field_asset_files' => 'footer',
      'field_invoice_exported' => 'footer',
      'status' => 'footer',
      'submit' => 'footer',
      'delete' => 'footer',
      'title' => 'hidden',
      'menu' => 'hidden',
      'name' => 'hidden',
      'link_title' => 'hidden',
      'alias' => 'hidden',
      'comment' => 'hidden',
      'revision' => 'hidden',
      'enabled' => 'hidden',
      'date' => 'hidden',
      'promote' => 'hidden',
      'link' => 'hidden',
      'description' => 'hidden',
      'log' => 'hidden',
      'sticky' => 'hidden',
      'parent' => 'hidden',
      'weight' => 'hidden',
      'order_numbers_token_tree' => 'hidden',
      'preview' => 'hidden',
      'revision_information' => 'hidden',
      'path' => 'hidden',
      'comment_settings' => 'hidden',
      'field_invoice_total' => 'hidden',
      'field_invoice_vat' => 'hidden',
      'field_auto_note' => 'hidden',
      'field_price_no_vat' => 'hidden',
      'author' => 'hidden',
      'options' => 'hidden',
      'additional_settings' => 'hidden',
      'actions' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_invoice|form'] = $ds_layout;

  return $export;
}
