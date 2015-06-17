<?php
/**
 * @file
 * erpal_field_pricing.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_field_pricing_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pricing|field_collection_item|field_pricing|form';
  $field_group->group_name = 'group_pricing';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_pricing';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pricing',
    'weight' => '0',
    'children' => array(
      0 => 'group_purchasing',
      1 => 'group_selling',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_pricing|field_collection_item|field_pricing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_purchasing|field_collection_item|field_pricing|form';
  $field_group->group_name = 'group_purchasing';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_pricing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pricing';
  $field_group->data = array(
    'label' => 'Purchasing',
    'weight' => '13',
    'children' => array(
      0 => 'field_buy_currency',
      1 => 'field_buy_price',
      2 => 'field_buy_vat_rate',
      3 => 'field_contractor_ref',
      4 => 'field_expense_category',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_purchasing|field_collection_item|field_pricing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_selling|field_collection_item|field_pricing|form';
  $field_group->group_name = 'group_selling';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_pricing';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_pricing';
  $field_group->data = array(
    'label' => 'Selling',
    'weight' => '12',
    'children' => array(
      0 => 'field_budget_time_billing',
      1 => 'field_budgets',
      2 => 'field_currency',
      3 => 'field_price',
      4 => 'field_price_mode',
      5 => 'field_service_category_term',
      6 => 'field_vat_rate',
      7 => 'field_budget_low_limit',
      8 => 'field_users',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_selling|field_collection_item|field_pricing|form'] = $field_group;

  return $export;
}
