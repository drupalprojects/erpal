<?php
/**
 * @file
 * erpal_crm_ui.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function erpal_crm_ui_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_contact|in_activity';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_contact';
  $ds_fieldsetting->view_mode = 'in_activity';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => 'entityreference node_erpal_contact',
      ),
    ),
  );
  $export['node|erpal_contact|in_activity'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_crm_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_contact|in_activity';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_contact';
  $ds_layout->view_mode = 'in_activity';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'right' => array(
        0 => 'title',
        1 => 'field_communication',
      ),
      'left' => array(
        0 => 'field_contact_image',
      ),
    ),
    'fields' => array(
      'title' => 'right',
      'field_communication' => 'right',
      'field_contact_image' => 'left',
    ),
    'classes' => array(),
  );
  $export['node|erpal_contact|in_activity'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_crm_activity|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_crm_activity';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'group_activity_form_basic',
        1 => 'title',
        2 => 'group_activity_form_next_contact',
        3 => 'group_activity_form_contacts',
        4 => 'field_customer_ref',
        5 => 'field_next_contact',
        6 => 'field_account_manager',
        7 => 'group_chance',
        8 => 'field_contacts_ref',
        9 => 'group_activity_form_files',
        10 => 'field_activity_status_term',
        11 => 'group_activity_form_body',
        12 => 'field_activity_origin',
        13 => 'body',
        14 => 'field_order_number_intern',
        15 => 'field_asset_files',
        16 => 'field_order_number_extern',
        17 => 'field_service_categories',
        18 => 'field_volume',
        19 => 'field_chance',
        20 => 'field_expected_date',
      ),
      'hidden' => array(
        0 => 'path',
        1 => 'field_task_ref',
        2 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_activity_form_basic' => 'left',
      'title' => 'left',
      'group_activity_form_next_contact' => 'left',
      'group_activity_form_contacts' => 'left',
      'field_customer_ref' => 'left',
      'field_next_contact' => 'left',
      'field_account_manager' => 'left',
      'group_chance' => 'left',
      'field_contacts_ref' => 'left',
      'group_activity_form_files' => 'left',
      'field_activity_status_term' => 'left',
      'group_activity_form_body' => 'left',
      'field_activity_origin' => 'left',
      'path' => 'hidden',
      'body' => 'left',
      'field_order_number_intern' => 'left',
      'field_asset_files' => 'left',
      'field_order_number_extern' => 'left',
      'field_task_ref' => 'hidden',
      'field_service_categories' => 'left',
      'field_volume' => 'left',
      'field_chance' => 'left',
      'field_expected_date' => 'left',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_crm_activity|form'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function erpal_crm_ui_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'node_view';
  $ds_view_mode->label = 'node_view';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['node_view'] = $ds_view_mode;

  return $export;
}
