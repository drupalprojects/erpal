<?php
/**
 * @file
 * erpal_field_pricing.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function erpal_field_pricing_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_allow_grouping'
  $field_bases['field_allow_grouping'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_allow_grouping',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Don\'t allow grouping in invoices',
        1 => 'Allow grouping in invoices',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_billing_duration'
  $field_bases['field_billing_duration'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_billing_duration',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'precision' => 10,
      'profile2_private' => FALSE,
      'scale' => 2,
    ),
    'translatable' => 0,
    'type' => 'number_decimal',
  );

  // Exported field_base: 'field_budget_time_billing'
  $field_bases['field_budget_time_billing'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_budget_time_billing',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'billable' => 'Timetracking is always billed (not prepaid)',
        'not_billable' => 'Timetracking is not billed, only if budget is empty (prepaid)',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_budgets'
  $field_bases['field_budgets'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_budgets',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'field' => 'none',
          'property' => 'budget_id',
          'type' => 'none',
        ),
        'target_bundles' => array(),
      ),
      'handler_submit' => 'Change handler',
      'profile2_private' => FALSE,
      'target_type' => 'budget',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_buy_currency'
  $field_bases['field_buy_currency'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_buy_currency',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'erpal_field_pricing_field_currency_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_buy_price'
  $field_bases['field_buy_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_buy_price',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'precision' => 10,
      'profile2_private' => FALSE,
      'scale' => 2,
    ),
    'translatable' => 0,
    'type' => 'number_decimal',
  );

  // Exported field_base: 'field_buy_vat_rate'
  $field_bases['field_buy_vat_rate'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_buy_vat_rate',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'erpal_field_pricing_field_buy_vat_rate_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_float',
  );

  // Exported field_base: 'field_contractor_ref'
  $field_bases['field_contractor_ref'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contractor_ref',
    'indexes' => array(
      'target_entity' => array(
        0 => 'target_id',
      ),
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 1,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'field' => 'body:value',
          'property' => 'nid',
          'type' => 'none',
        ),
        'target_bundles' => array(
          'erpal_contact' => 'erpal_contact',
        ),
      ),
      'handler_submit' => 'Change handler',
      'profile2_private' => FALSE,
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_currency'
  $field_bases['field_currency'] = array(
    'active' => 1,
    'bundle' => 'field_pricing',
    'cardinality' => 1,
    'deleted' => 0,
    'description' => 'Add a field for selecting the currency',
    'entity_type' => 'field_collection_item',
    'entity_types' => array(),
    'field_instance' => array(
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 4,
      ),
    ),
    'field_name' => 'field_currency',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'label' => 'Currency',
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'erpal_field_pricing_field_currency_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_expense_category'
  $field_bases['field_expense_category'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_expense_category',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'expense_category_terms',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_price'
  $field_bases['field_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_price',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'precision' => 10,
      'profile2_private' => FALSE,
      'scale' => 2,
    ),
    'translatable' => 0,
    'type' => 'number_decimal',
  );

  // Exported field_base: 'field_price_mode'
  $field_bases['field_price_mode'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_price_mode',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'none' => 'No Information',
        'not_billable' => 'Not billable',
        'fixed_price' => 'Fixed price',
        'per_hour' => 'Per hour',
        'budget' => 'Budget per hour',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_pricing'
  $field_bases['field_pricing'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pricing',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 0,
      'path' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_service_category_term'
  $field_bases['field_service_category_term'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_service_category_term',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'service_category_terms',
          'parent' => 0,
        ),
      ),
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_vat_rate'
  $field_bases['field_vat_rate'] = array(
    'active' => 1,
    'bundle' => 'field_pricing',
    'cardinality' => 1,
    'deleted' => 0,
    'description' => 'Add a reference to a specification to erpal_tasks node type',
    'entity_type' => 'field_collection_item',
    'entity_types' => array(),
    'field_instance' => array(
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 3,
      ),
    ),
    'field_name' => 'field_vat_rate',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'label' => 'Tax',
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'erpal_field_pricing_field_vat_rate_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_float',
  );

  // Exported field_base: 'field_vat_total'
  $field_bases['field_vat_total'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_vat_total',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'precision' => 10,
      'scale' => 2,
    ),
    'translatable' => 0,
    'type' => 'number_decimal',
  );

  return $field_bases;
}
