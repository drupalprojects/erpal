<?php
/**
 * @file
 * feature_erpal_basic.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function feature_erpal_basic_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_contact|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_contact';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|erpal_contact|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_erpal_basic_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_contact|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_contact';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'links',
        1 => 'title',
      ),
      'left' => array(
        0 => 'field_contact_image',
        1 => 'post_date',
        2 => 'author',
        3 => 'field_contact_type',
        4 => 'field_birthday',
        5 => 'field_contact_tags',
        6 => 'field_gender',
        7 => 'field_customer_category',
        8 => 'field_legal_other',
      ),
      'right' => array(
        0 => 'field_addresses',
        1 => 'field_website',
        2 => 'field_phone',
        3 => 'field_vat_number',
        4 => 'field_xing',
        5 => 'field_facebook',
        6 => 'field_twitter',
        7 => 'field_bank_accounts',
        8 => 'field_email',
        9 => 'field_fax',
      ),
    ),
    'fields' => array(
      'links' => 'header',
      'title' => 'header',
      'field_contact_image' => 'left',
      'post_date' => 'left',
      'author' => 'left',
      'field_contact_type' => 'left',
      'field_birthday' => 'left',
      'field_contact_tags' => 'left',
      'field_gender' => 'left',
      'field_customer_category' => 'left',
      'field_legal_other' => 'left',
      'field_addresses' => 'right',
      'field_website' => 'right',
      'field_phone' => 'right',
      'field_vat_number' => 'right',
      'field_xing' => 'right',
      'field_facebook' => 'right',
      'field_twitter' => 'right',
      'field_bank_accounts' => 'right',
      'field_email' => 'right',
      'field_fax' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|erpal_contact|full'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function feature_erpal_basic_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'in_pane';
  $ds_view_mode->label = 'in-pane';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $export['in_pane'] = $ds_view_mode;

  return $export;
}
