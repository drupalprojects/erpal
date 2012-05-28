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
      'hidden' => array(
        0 => 'token_tree',
        1 => 'title',
        2 => 'menu',
        3 => 'name',
        4 => 'link_title',
        5 => 'alias',
        6 => 'comment',
        7 => 'revision',
        8 => 'enabled',
        9 => 'date',
        10 => 'promote',
        11 => 'link',
        12 => 'description',
        13 => 'log',
        14 => 'sticky',
        15 => 'parent',
        16 => 'weight',
        17 => 'order_numbers_token_tree',
        18 => 'preview',
        19 => 'group_notes',
        20 => 'revision_information',
        21 => 'path',
        22 => 'comment_settings',
        23 => 'field_invoice_total',
        24 => 'field_invoice_vat',
        25 => 'field_auto_note',
        26 => 'field_price_no_vat',
        27 => 'field_asset_files',
        28 => 'author',
        29 => 'options',
        30 => 'additional_settings',
        31 => 'actions',
        32 => '_add_existing_field',
      ),
      'left' => array(
        0 => 'field_contractor_ref',
        1 => 'field_customer_ref',
        2 => 'field_invoice_address_id',
      ),
      'right' => array(
        0 => 'group_order_numbers',
        1 => 'field_invoice_number',
        2 => 'field_invoice_date',
        3 => 'field_credit_period',
        4 => 'field_order_number_extern',
        5 => 'field_payed',
        6 => 'field_order_number_intern',
        7 => 'field_payment_date',
      ),
      'footer' => array(
        0 => 'field_billables_ref',
        1 => 'field_skonto',
        2 => 'field_note',
        3 => 'field_currency',
        4 => 'field_invoice_exported',
        5 => 'status',
        6 => 'submit',
        7 => 'delete',
      ),
    ),
    'fields' => array(
      'token_tree' => 'hidden',
      'field_contractor_ref' => 'left',
      'field_customer_ref' => 'left',
      'field_invoice_address_id' => 'left',
      'group_order_numbers' => 'right',
      'field_invoice_number' => 'right',
      'field_invoice_date' => 'right',
      'field_credit_period' => 'right',
      'field_order_number_extern' => 'right',
      'field_payed' => 'right',
      'field_order_number_intern' => 'right',
      'field_payment_date' => 'right',
      'field_billables_ref' => 'footer',
      'field_skonto' => 'footer',
      'field_note' => 'footer',
      'field_currency' => 'footer',
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
      'group_notes' => 'hidden',
      'revision_information' => 'hidden',
      'path' => 'hidden',
      'comment_settings' => 'hidden',
      'field_invoice_total' => 'hidden',
      'field_invoice_vat' => 'hidden',
      'field_auto_note' => 'hidden',
      'field_price_no_vat' => 'hidden',
      'field_asset_files' => 'hidden',
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
