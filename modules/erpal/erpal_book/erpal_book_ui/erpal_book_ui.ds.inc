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
        1 => 'field_is_template',
        2 => 'field_book_tags',
        3 => 'body',
        4 => 'field_files_ref',
        5 => 'field_page_exclude_from',
        6 => 'field_estimated_duration',
      ),
      'hidden' => array(
        0 => 'field_parent',
        1 => 'field_book_parent',
        2 => 'field_weight',
        3 => 'field_book_ref',
        4 => 'field_book_origin',
        5 => 'field_asset_files',
        6 => 'path',
        7 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_is_template' => 'left',
      'field_book_tags' => 'left',
      'body' => 'left',
      'field_files_ref' => 'left',
      'field_page_exclude_from' => 'left',
      'field_estimated_duration' => 'left',
      'field_parent' => 'hidden',
      'field_book_parent' => 'hidden',
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
        0 => 'group_book_form_basics',
        1 => 'title',
        2 => 'field_is_template',
        3 => 'field_book_tags',
        4 => 'body',
        5 => 'group_book_form_contact',
        6 => 'field_contact_ref',
        7 => 'field_address_id',
        8 => 'group_book_form_files',
        9 => 'field_files_ref',
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
      'group_book_form_basics' => 'left',
      'title' => 'left',
      'field_is_template' => 'left',
      'field_book_tags' => 'left',
      'body' => 'left',
      'group_book_form_contact' => 'left',
      'field_contact_ref' => 'left',
      'field_address_id' => 'left',
      'group_book_form_files' => 'left',
      'field_files_ref' => 'left',
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
