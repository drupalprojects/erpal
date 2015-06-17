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
        0 => 'group_contract_form_basics',
        1 => 'title',
        2 => 'group_contract_form_payment',
        3 => 'field_date',
        4 => 'group_cancelation',
        5 => 'group_budget_automation',
        6 => 'field_contract_type',
        7 => 'field_cancelation_period',
        8 => 'group_advanced',
        9 => 'field_contract_payment',
        10 => 'field_cancelation_period_con',
        11 => 'group_contract_form_files',
        12 => 'field_cancelation_period_unit',
        13 => 'field_budget_booking',
        14 => 'field_contract_duration',
        15 => 'body',
        16 => 'field_activity_ref',
        17 => 'field_asset_files',
        18 => 'field_repeating_duration',
      ),
      'hidden' => array(
        0 => 'path',
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_contract_form_basics' => 'left',
      'title' => 'left',
      'group_contract_form_payment' => 'left',
      'field_date' => 'left',
      'group_cancelation' => 'left',
      'group_budget_automation' => 'left',
      'field_contract_type' => 'left',
      'field_cancelation_period' => 'left',
      'group_advanced' => 'left',
      'field_contract_payment' => 'left',
      'field_cancelation_period_con' => 'left',
      'group_contract_form_files' => 'left',
      'field_cancelation_period_unit' => 'left',
      'path' => 'hidden',
      'field_budget_booking' => 'left',
      'field_contract_duration' => 'left',
      'body' => 'left',
      'field_activity_ref' => 'left',
      'field_asset_files' => 'left',
      '_add_existing_field' => 'hidden',
      'field_repeating_duration' => 'left',
    ),
    'classes' => array(),
  );
  $export['node|erpal_contract|form'] = $ds_layout;

  return $export;
}
