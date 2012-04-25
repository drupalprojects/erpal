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
        0 => 'date',
        1 => 'field_invoice_total',
        2 => 'title',
        3 => 'menu',
        4 => 'name',
        5 => 'status',
        6 => 'revision',
        7 => 'token_tree',
        8 => 'comment',
        9 => 'enabled',
        10 => 'alias',
        11 => 'link_title',
        12 => 'description',
        13 => 'promote',
        14 => 'log',
        15 => 'link',
        16 => 'parent',
        17 => 'sticky',
        18 => 'weight',
        19 => 'preview',
        20 => 'order_numbers_token_tree',
        21 => 'field_invoice_vat',
        22 => 'field_auto_note',
        23 => 'revision_information',
        24 => 'path',
        25 => 'comment_settings',
        26 => 'author',
        27 => 'field_price_no_vat',
        28 => 'options',
        29 => 'additional_settings',
        30 => 'actions',
        31 => '_add_existing_field',
      ),
      'left' => array(
        0 => 'field_contractor_ref',
        1 => 'field_customer_ref',
        2 => 'field_invoice_address_id',
      ),
      'right' => array(
        0 => 'field_invoice_number',
        1 => 'group_order_numbers',
        2 => 'field_invoice_date',
        3 => 'field_order_number_extern',
        4 => 'field_credit_period',
        5 => 'field_payed',
        6 => 'field_order_number_intern',
        7 => 'field_payment_date',
      ),
      'footer' => array(
        0 => 'field_billables_ref',
        1 => 'field_currency',
        2 => 'field_skonto',
        3 => 'field_pdf_file',
        4 => 'field_note',
        5 => 'submit',
        6 => 'delete',
      ),
    ),
    'fields' => array(
      'date' => 'hidden',
      'field_contractor_ref' => 'left',
      'field_customer_ref' => 'left',
      'field_invoice_address_id' => 'left',
      'field_invoice_number' => 'right',
      'group_order_numbers' => 'right',
      'field_invoice_date' => 'right',
      'field_order_number_extern' => 'right',
      'field_credit_period' => 'right',
      'field_payed' => 'right',
      'field_order_number_intern' => 'right',
      'field_billables_ref' => 'footer',
      'field_currency' => 'footer',
      'field_invoice_total' => 'hidden',
      'field_skonto' => 'footer',
      'field_pdf_file' => 'footer',
      'field_note' => 'footer',
      'submit' => 'footer',
      'delete' => 'footer',
      'title' => 'hidden',
      'menu' => 'hidden',
      'name' => 'hidden',
      'status' => 'hidden',
      'revision' => 'hidden',
      'token_tree' => 'hidden',
      'comment' => 'hidden',
      'enabled' => 'hidden',
      'alias' => 'hidden',
      'link_title' => 'hidden',
      'description' => 'hidden',
      'promote' => 'hidden',
      'log' => 'hidden',
      'link' => 'hidden',
      'parent' => 'hidden',
      'sticky' => 'hidden',
      'weight' => 'hidden',
      'preview' => 'hidden',
      'order_numbers_token_tree' => 'hidden',
      'field_invoice_vat' => 'hidden',
      'field_payment_date' => 'right',
      'field_auto_note' => 'hidden',
      'revision_information' => 'hidden',
      'path' => 'hidden',
      'comment_settings' => 'hidden',
      'author' => 'hidden',
      'field_price_no_vat' => 'hidden',
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
