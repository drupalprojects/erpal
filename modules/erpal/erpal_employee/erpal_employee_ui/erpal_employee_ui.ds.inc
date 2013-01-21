<?php
/**
 * @file
 * erpal_employee_ui.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_employee_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_working_time|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_working_time';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_working_time_type',
        2 => 'field_date_time',
      ),
      'right' => array(
        0 => 'field_date_times',
      ),
      'hidden' => array(
        0 => 'path',
        1 => 'field_duration_calc',
        2 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_working_time_type' => 'left',
      'field_date_time' => 'left',
      'field_date_times' => 'right',
      'path' => 'hidden',
      'field_duration_calc' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_working_time|form'] = $ds_layout;

  return $export;
}
