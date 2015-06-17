<?php
/**
 * @file
 * erpal_field_pricing.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_field_pricing_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_pricing|full';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_pricing';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_price_mode',
        1 => 'field_vat_rate',
        2 => 'field_price',
        3 => 'field_currency',
        4 => 'field_buy_vat_rate',
        5 => 'field_contractor_ref',
        6 => 'field_buy_price',
        7 => 'field_buy_currency',
        8 => 'field_budget_time_billing',
        9 => 'field_service_category_term',
        10 => 'field_users',
        11 => 'field_budget_low_limit',
        12 => 'field_expense_category',
      ),
    ),
    'fields' => array(
      'field_price_mode' => 'ds_content',
      'field_vat_rate' => 'ds_content',
      'field_price' => 'ds_content',
      'field_currency' => 'ds_content',
      'field_buy_vat_rate' => 'ds_content',
      'field_contractor_ref' => 'ds_content',
      'field_buy_price' => 'ds_content',
      'field_buy_currency' => 'ds_content',
      'field_budget_time_billing' => 'ds_content',
      'field_service_category_term' => 'ds_content',
      'field_users' => 'ds_content',
      'field_budget_low_limit' => 'ds_content',
      'field_expense_category' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
  );
  $export['field_collection_item|field_pricing|full'] = $ds_layout;

  return $export;
}
