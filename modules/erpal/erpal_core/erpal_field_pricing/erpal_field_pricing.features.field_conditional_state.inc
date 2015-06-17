<?php
/**
 * @file
 * erpal_field_pricing.features.field_conditional_state.inc
 */

/**
 * Implements hook_field_conditional_state_defaults().
 */
function erpal_field_pricing_field_conditional_state_defaults() {
  $items = array();

  $items["field_pricing:field_currency:field_collection_item:field_price_mode:invisible:none-not_billable"] = array(
    'type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'field_name' => 'field_currency',
    'control_field' => 'field_price_mode',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'none' => 'none',
      'not_billable' => 'not_billable',
    ),
  );

  $items["field_pricing:field_price:field_collection_item:field_price_mode:invisible:none-not_billable"] = array(
    'type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'field_name' => 'field_price',
    'control_field' => 'field_price_mode',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'none' => 'none',
      'not_billable' => 'not_billable',
    ),
  );

  $items["field_pricing:field_vat_rate:field_collection_item:field_price_mode:invisible:none-not_billable"] = array(
    'type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'field_name' => 'field_vat_rate',
    'control_field' => 'field_price_mode',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'none' => 'none',
      'not_billable' => 'not_billable',
    ),
  );

  return $items;
}
