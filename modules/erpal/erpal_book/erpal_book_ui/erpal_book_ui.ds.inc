<?php
/**
 * @file
 * erpal_book_ui.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_book_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_book_page|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_book_page';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
      ),
      'right' => array(
        0 => 'field_book_tags',
        1 => 'field_is_template',
        2 => 'field_estimated_duration',
        3 => 'field_page_exclude_from',
      ),
      'hidden' => array(
        0 => 'field_parent',
        1 => 'field_weight',
        2 => 'field_book_ref',
        3 => 'field_book_origin',
        4 => 'field_asset_files',
        5 => 'path',
        6 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'field_book_tags' => 'right',
      'field_is_template' => 'right',
      'field_estimated_duration' => 'right',
      'field_page_exclude_from' => 'right',
      'field_parent' => 'hidden',
      'field_weight' => 'hidden',
      'field_book_ref' => 'hidden',
      'field_book_origin' => 'hidden',
      'field_asset_files' => 'hidden',
      'path' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_book_page|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_book|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_book';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
      ),
      'right' => array(
        0 => 'field_contact_ref',
        1 => 'field_address_id',
        2 => 'field_book_tags',
        3 => 'field_is_template',
      ),
      'hidden' => array(
        0 => 'field_book_origin',
        1 => 'field_asset_files',
        2 => 'field_book_version',
        3 => 'path',
        4 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'field_contact_ref' => 'right',
      'field_address_id' => 'right',
      'field_book_tags' => 'right',
      'field_is_template' => 'right',
      'field_book_origin' => 'hidden',
      'field_asset_files' => 'hidden',
      'field_book_version' => 'hidden',
      'path' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_book|form'] = $ds_layout;

  return $export;
}
