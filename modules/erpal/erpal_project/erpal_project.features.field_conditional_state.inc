<?php
/**
 * @file
 * erpal_project.features.field_conditional_state.inc
 */

/**
 * Implements hook_field_conditional_state_defaults().
 */
function erpal_project_field_conditional_state_defaults() {
  $items = array();

  $items["field_pricing:field_budget_low_limit:field_collection_item:field_price_mode:invisible:none-not_billable-fixed_price-per_hour"] = array(
    'type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'field_name' => 'field_budget_low_limit',
    'control_field' => 'field_price_mode',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'none' => 'none',
      'not_billable' => 'not_billable',
      'fixed_price' => 'fixed_price',
      'per_hour' => 'per_hour',
    ),
  );

  $items["field_pricing:field_budget_time_billing:field_collection_item:field_price_mode:invisible:none-not_billable-fixed_price-per_hour"] = array(
    'type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'field_name' => 'field_budget_time_billing',
    'control_field' => 'field_price_mode',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'none' => 'none',
      'not_billable' => 'not_billable',
      'fixed_price' => 'fixed_price',
      'per_hour' => 'per_hour',
    ),
  );

  $items["field_pricing:field_budgets:field_collection_item:field_price_mode:invisible:none-not_billable-fixed_price-per_hour"] = array(
    'type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'field_name' => 'field_budgets',
    'control_field' => 'field_price_mode',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'none' => 'none',
      'not_billable' => 'not_billable',
      'fixed_price' => 'fixed_price',
      'per_hour' => 'per_hour',
    ),
  );

  $items["field_pricing:field_users:field_collection_item:field_price_mode:invisible:none-not_billable-fixed_price-per_hour"] = array(
    'type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'field_name' => 'field_users',
    'control_field' => 'field_price_mode',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'none' => 'none',
      'not_billable' => 'not_billable',
      'fixed_price' => 'fixed_price',
      'per_hour' => 'per_hour',
    ),
  );

  return $items;
}
