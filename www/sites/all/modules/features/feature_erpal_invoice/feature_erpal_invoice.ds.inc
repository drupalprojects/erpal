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
        0 => 'field_invoice_number',
        1 => 'group_order_numbers',
        2 => 'field_invoice_date',
        3 => 'field_credit_period',
        4 => 'field_payed',
        5 => 'field_order_number_extern',
        6 => 'field_payment_date',
        7 => 'field_order_number_intern',
      ),
      'footer' => array(
        0 => 'field_billables_ref',
        1 => 'field_skonto',
        2 => 'field_pdf_file',
        3 => 'field_note',
        4 => 'submit',
        5 => 'delete',
      ),
      'hidden' => array(
        0 => 'menu',
        1 => 'name',
        2 => 'revision',
        3 => 'token_tree',
        4 => 'alias',
        5 => 'comment',
        6 => 'date',
        7 => 'status',
        8 => 'link_title',
        9 => 'enabled',
        10 => 'title',
        11 => 'link',
        12 => 'description',
        13 => 'promote',
        14 => 'log',
        15 => 'sticky',
        16 => 'parent',
        17 => 'weight',
        18 => 'order_numbers_token_tree',
        19 => 'field_currency',
        20 => 'preview',
        21 => 'field_invoice_total',
        22 => 'revision_information',
        23 => 'path',
        24 => 'comment_settings',
        25 => 'field_invoice_vat',
        26 => 'field_auto_note',
        27 => 'field_price_no_vat',
        28 => 'author',
        29 => 'options',
        30 => 'additional_settings',
        31 => 'actions',
        32 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_contractor_ref' => 'left',
      'field_customer_ref' => 'left',
      'field_invoice_address_id' => 'left',
      'field_invoice_number' => 'right',
      'group_order_numbers' => 'right',
      'field_invoice_date' => 'right',
      'field_credit_period' => 'right',
      'field_payed' => 'right',
      'field_order_number_extern' => 'right',
      'field_payment_date' => 'right',
      'field_order_number_intern' => 'right',
      'field_billables_ref' => 'footer',
      'field_skonto' => 'footer',
      'field_pdf_file' => 'footer',
      'field_note' => 'footer',
      'submit' => 'footer',
      'delete' => 'footer',
      'menu' => 'hidden',
      'name' => 'hidden',
      'revision' => 'hidden',
      'token_tree' => 'hidden',
      'alias' => 'hidden',
      'comment' => 'hidden',
      'date' => 'hidden',
      'status' => 'hidden',
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
      'field_currency' => 'hidden',
      'preview' => 'hidden',
      'field_invoice_total' => 'hidden',
      'revision_information' => 'hidden',
      'path' => 'hidden',
      'comment_settings' => 'hidden',
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
