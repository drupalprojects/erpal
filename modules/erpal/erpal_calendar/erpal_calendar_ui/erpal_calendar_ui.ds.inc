<?php
/**
 * @file
 * erpal_calendar_ui.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_calendar_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_date|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_date';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_users',
      ),
      'right' => array(
        0 => 'field_date_repeat',
        1 => 'field_date_type',
      ),
      'hidden' => array(
        0 => 'path',
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'field_users' => 'left',
      'field_date_repeat' => 'right',
      'field_date_type' => 'right',
      'path' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_date|form'] = $ds_layout;

  return $export;
}
