<?php
/**
 * @file
 * erpal_contract_ui.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_contract_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_contract|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_contract';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'field_contract_payment',
        2 => 'group_cancelation',
        3 => 'field_cancelation_period',
        4 => 'field_cancelation_period_con',
        5 => 'field_cancelation_period_unit',
        6 => 'field_contract_duration',
        7 => 'field_repeating_duration',
      ),
      'right' => array(
        0 => 'field_date',
        1 => 'field_contract_type',
        2 => 'field_budget_booking',
      ),
      'advancedleft' => array(
        0 => 'body',
      ),
      'advancedright' => array(
        0 => 'field_activity_ref',
        1 => 'field_asset_files',
      ),
      'hidden' => array(
        0 => 'path',
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'field_contract_payment' => 'left',
      'group_cancelation' => 'left',
      'field_date' => 'right',
      'field_contract_type' => 'right',
      'field_cancelation_period' => 'left',
      'field_cancelation_period_con' => 'left',
      'field_budget_booking' => 'right',
      'field_cancelation_period_unit' => 'left',
      'body' => 'advancedleft',
      'field_contract_duration' => 'left',
      'field_activity_ref' => 'advancedright',
      'field_repeating_duration' => 'left',
      'field_asset_files' => 'advancedright',
      'path' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_contract|form'] = $ds_layout;

  return $export;
}
