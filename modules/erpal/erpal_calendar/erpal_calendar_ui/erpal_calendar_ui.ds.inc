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
        0 => 'group_date_form_basics',
        1 => 'title',
        2 => 'group_date_form_body',
        3 => 'body',
        4 => 'group_date_form_participants',
        5 => 'field_date_repeat',
        6 => 'field_users',
        7 => 'group_date_form_contacts',
        8 => 'field_contacts_ref',
        9 => 'field_date_type',
        10 => 'group_date_form_files',
        11 => 'field_asset_files',
      ),
      'hidden' => array(
        0 => 'path',
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_date_form_basics' => 'left',
      'title' => 'left',
      'group_date_form_body' => 'left',
      'body' => 'left',
      'group_date_form_participants' => 'left',
      'field_date_repeat' => 'left',
      'field_users' => 'left',
      'group_date_form_contacts' => 'left',
      'field_contacts_ref' => 'left',
      'field_date_type' => 'left',
      'group_date_form_files' => 'left',
      'field_asset_files' => 'left',
      'path' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_date|form'] = $ds_layout;

  return $export;
}
