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
        1 => 'token_tree',
        2 => 'additional_settings',
        3 => 'comment',
        4 => 'name',
        5 => 'alias',
        6 => 'menu',
        7 => 'revision',
        8 => 'date',
        9 => 'link_title',
        10 => 'enabled',
        11 => 'title',
        12 => 'link',
        13 => 'description',
        14 => 'promote',
        15 => 'log',
        16 => 'sticky',
        17 => 'parent',
        18 => 'weight',
        19 => 'order_numbers_token_tree',
        20 => 'options',
        21 => 'field_invoice_total',
        22 => 'revision_information',
        23 => 'path',
        24 => 'comment_settings',
        25 => 'field_invoice_vat',
        26 => 'field_auto_note',
        27 => 'author',
        28 => 'field_price_no_vat',
        30 => 'actions',
        31 => 'field_asset_files',
        32 => '_add_existing_field',
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
