<?php
/**
 * @file
 * feature_erpal_book.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_erpal_book_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_book_page|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_book_page';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_parent',
        3 => 'field_estimated_duration',
        4 => 'field_book_tags',
        5 => 'field_is_template',
        6 => 'field_weight',
        7 => 'field_book_ref',
        8 => 'field_page_exclude_from',
      ),
      'hidden' => array(
        0 => 'field_book_origin',
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'body' => 'header',
      'field_parent' => 'header',
      'field_estimated_duration' => 'header',
      'field_book_tags' => 'header',
      'field_is_template' => 'header',
      'field_weight' => 'header',
      'field_book_ref' => 'header',
      'field_page_exclude_from' => 'header',
      'field_book_origin' => 'hidden',
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
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'field_contact_ref',
        2 => 'field_address_id',
        3 => 'body',
        4 => 'field_book_tags',
        5 => 'field_is_template',
      ),
      'hidden' => array(
        0 => 'field_book_origin',
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_contact_ref' => 'header',
      'field_address_id' => 'header',
      'body' => 'header',
      'field_book_tags' => 'header',
      'field_is_template' => 'header',
      'field_book_origin' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_book|form'] = $ds_layout;

  return $export;
}
