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
        2 => 'field_invoice_address_id',
      ),
      'right' => array(
        0 => 'group_order_numbers',
        1 => 'field_invoice_number',
        2 => 'field_invoice_date',
        3 => 'field_credit_period',
        4 => 'field_order_number_extern',
        5 => 'field_payed',
        6 => 'field_payment_date',
        7 => 'field_order_number_intern',
      ),
      'footer' => array(
        0 => 'field_billables_ref',
        1 => 'field_skonto',
        2 => 'field_note',
        3 => 'field_currency',
        4 => 'submit',
        5 => 'delete',
        6 => 'status',
      ),
      'hidden' => array(
        0 => 'group_notes',
        1 => 'field_pdf_file',
        2 => 'token_tree',
        3 => 'additional_settings',
        4 => 'comment',
        5 => 'name',
        6 => 'alias',
        7 => 'menu',
        8 => 'revision',
        9 => 'date',
        10 => 'link_title',
        11 => 'enabled',
        12 => 'title',
        13 => 'link',
        14 => 'description',
        15 => 'promote',
        16 => 'log',
        17 => 'sticky',
        18 => 'parent',
        19 => 'weight',
        20 => 'order_numbers_token_tree',
        21 => 'preview',
        22 => 'field_invoice_total',
        23 => 'revision_information',
        24 => 'path',
        25 => 'comment_settings',
        26 => 'field_invoice_vat',
        27 => 'field_auto_note',
        28 => 'author',
        29 => 'field_price_no_vat',
        30 => 'options',
        31 => 'actions',
        32 => 'field_asset_files',
        33 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_contractor_ref' => 'left',
      'field_customer_ref' => 'left',
      'field_invoice_address_id' => 'left',
      'group_order_numbers' => 'right',
      'field_invoice_number' => 'right',
      'field_invoice_date' => 'right',
      'field_credit_period' => 'right',
      'field_order_number_extern' => 'right',
      'field_payed' => 'right',
      'field_payment_date' => 'right',
      'field_order_number_intern' => 'right',
      'field_billables_ref' => 'footer',
      'field_skonto' => 'footer',
      'group_notes' => 'hidden',
      'field_note' => 'footer',
      'field_currency' => 'footer',
      'submit' => 'footer',
      'field_pdf_file' => 'hidden',
      'token_tree' => 'hidden',
      'delete' => 'footer',
      'status' => 'footer',
      'additional_settings' => 'hidden',
      'comment' => 'hidden',
      'name' => 'hidden',
      'alias' => 'hidden',
      'menu' => 'hidden',
      'revision' => 'hidden',
      'date' => 'hidden',
      'link_title' => 'hidden',
      'enabled' => 'hidden',
      'title' => 'hidden',
      'link' => 'hidden',
      'description' => 'hidden',
      'promote' => 'hidden',
      'log' => 'hidden',
      'sticky' => 'hidden',
      'parent' => 'hidden',
      'weight' => 'hidden',
      'order_numbers_token_tree' => 'hidden',
      'preview' => 'hidden',
      'field_invoice_total' => 'hidden',
      'revision_information' => 'hidden',
      'path' => 'hidden',
      'comment_settings' => 'hidden',
      'field_invoice_vat' => 'hidden',
      'field_auto_note' => 'hidden',
      'author' => 'hidden',
      'field_price_no_vat' => 'hidden',
      'options' => 'hidden',
      'actions' => 'hidden',
      'field_asset_files' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_invoice|form'] = $ds_layout;

  return $export;
}
