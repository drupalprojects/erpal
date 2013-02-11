<?php
/**
 * @file
 * erpal_field_pricing.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function erpal_field_pricing_field_default_fields() {
  $fields = array();

  // Exported field: 'field_collection_item-field_pricing-field_budget_time_billing'.
  $fields['field_collection_item-field_pricing-field_budget_time_billing'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_budget_time_billing',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'billable' => 'Timetracking is always billed',
          'not_billable' => 'Timetracking is not billed, only if budget is empty',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'field_pricing',
      'default_value' => array(
        0 => array(
          'value' => 'billable',
        ),
      ),
      'deleted' => '0',
      'description' => 'Choose if timetrackings are billable within a budget or not. If not they will only billed if budget is empty and there is a price set.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 9,
        ),
        'in_pane' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 9,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_budget_time_billing',
      'label' => 'Budget time billing',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 4,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_pricing-field_budgets'.
  $fields['field_collection_item-field_pricing-field_budgets'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_budgets',
      'foreign keys' => array(
        'budget' => array(
          'columns' => array(
            'target_id' => 'budget_id',
          ),
          'table' => 'budget',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
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
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'field_pricing',
      'default_value' => NULL,
      'default_value_function' => 'entityreference_prepopulate_field_default_value',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'erpal_basic_helper',
          'settings' => array(
            'link' => 1,
          ),
          'type' => 'entityreference_typed_label',
          'weight' => 8,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'erpal_basic_helper',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_typed_label',
          'weight' => 8,
        ),
        'in_pane' => array(
          'label' => 'above',
          'module' => 'erpal_basic_helper',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_typed_label',
          'weight' => 8,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_budgets',
      'label' => 'Budgets',
      'required' => 0,
      'settings' => array(
        'behaviors' => array(
          'prepopulate' => array(
            'action' => 'hide',
            'fallback' => 'redirect',
            'skip_perm' => '0',
            'status' => 1,
          ),
        ),
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'references_dialog_add' => 1,
          'references_dialog_edit' => 0,
          'references_dialog_search' => 0,
          'references_dialog_search_view' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => 3,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_pricing-field_currency'.
  $fields['field_collection_item-field_pricing-field_currency'] = array(
    'field_config' => array(
      'active' => '1',
      'bundle' => 'field_pricing',
      'cardinality' => '1',
      'deleted' => '0',
      'description' => 'Add a field for selecting the currency',
      'entity_type' => 'field_collection_item',
      'entity_types' => array(),
      'field_instance' => array(
        'widget' => array(
          'module' => 'options',
          'settings' => array(),
          'type' => 'options_select',
          'weight' => '4',
        ),
      ),
      'field_name' => 'field_currency',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'label' => 'Currency',
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => 'erpal_field_pricing_field_currency_allowed_values',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'field_pricing',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Add a field for selecting the currency',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_instance' => array(
        'widget' => array(
          'module' => 'options',
          'settings' => array(),
          'type' => 'options_select',
          'weight' => '4',
        ),
      ),
      'field_name' => 'field_currency',
      'label' => 'Currency',
      'required' => FALSE,
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => 'erpal_field_pricing_field_currency_allowed_values',
        'user_register_form' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_pricing-field_price'.
  $fields['field_collection_item-field_pricing-field_price'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_price',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'decimal_separator' => '.',
        'precision' => '10',
        'profile2_private' => FALSE,
        'scale' => '2',
      ),
      'translatable' => '0',
      'type' => 'number_decimal',
    ),
    'field_instance' => array(
      'bundle' => 'field_pricing',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 2,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_decimal',
          'weight' => 1,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 2,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_decimal',
          'weight' => 1,
        ),
        'in_pane' => array(
          'label' => 'above',
          'module' => 'number',
          'settings' => array(
            'decimal_separator' => '.',
            'prefix_suffix' => TRUE,
            'scale' => 2,
            'thousand_separator' => ' ',
          ),
          'type' => 'number_decimal',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_price',
      'label' => 'Price',
      'required' => FALSE,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 5,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_pricing-field_price_mode'.
  $fields['field_collection_item-field_pricing-field_price_mode'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_price_mode',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
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
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'field_pricing',
      'default_value' => array(
        0 => array(
          'value' => 'none',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
        'in_pane' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_price_mode',
      'label' => 'Price mode',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_pricing-field_service_category_term'.
  $fields['field_collection_item-field_pricing-field_service_category_term'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_service_category_term',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => '0',
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'service_category_terms',
            'parent' => '0',
          ),
        ),
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'field_pricing',
      'comment_enabled' => 0,
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 10,
        ),
        'in_pane' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_service_category_term',
      'label' => 'Service category',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 6,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_pricing-field_vat_rate'.
  $fields['field_collection_item-field_pricing-field_vat_rate'] = array(
    'field_config' => array(
      'active' => '1',
      'bundle' => 'field_pricing',
      'cardinality' => '1',
      'deleted' => '0',
      'description' => 'Add a reference to a specification to erpal_tasks node type',
      'entity_type' => 'field_collection_item',
      'entity_types' => array(),
      'field_instance' => array(
        'widget' => array(
          'module' => 'options',
          'settings' => array(),
          'type' => 'options_select',
          'weight' => '3',
        ),
      ),
      'field_name' => 'field_vat_rate',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'label' => 'VAT',
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => 'erpal_field_pricing_field_vat_rate_allowed_values',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_integer',
    ),
    'field_instance' => array(
      'bundle' => 'field_pricing',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Add a reference to a specification to erpal_tasks node type',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_instance' => array(
        'widget' => array(
          'module' => 'options',
          'settings' => array(),
          'type' => 'options_select',
          'weight' => '3',
        ),
      ),
      'field_name' => 'field_vat_rate',
      'label' => 'VAT',
      'required' => FALSE,
      'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => 'erpal_field_pricing_field_vat_rate_allowed_values',
        'user_register_form' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_integer',
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 1,
      ),
    ),
  );

  // Exported field: 'node-erpal_project-field_pricing'.
  $fields['node-erpal_project-field_pricing'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_pricing',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => 0,
        'path' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'erpal_project',
      'default_value' => array(
        0 => array(),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'add' => 'Add',
            'delete' => 'Delete',
            'description' => TRUE,
            'edit' => 'Edit',
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_view',
          'weight' => 2,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 19,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'test' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'add' => 'Add',
            'delete' => 'Delete',
            'description' => TRUE,
            'edit' => 'Edit',
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_view',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_pricing',
      'label' => 'Pricing',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection',
        'settings' => array(),
        'type' => 'field_collection_embed',
        'weight' => 7,
      ),
    ),
  );

  // Exported field: 'node-erpal_task-field_pricing'.
  $fields['node-erpal_task-field_pricing'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_pricing',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => 0,
        'path' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'erpal_task',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'field_collection',
          'settings' => array(
            'add' => 'Add',
            'delete' => 'Delete',
            'description' => TRUE,
            'edit' => 'Edit',
          ),
          'type' => 'field_collection_list',
          'weight' => 11,
        ),
        'entityreference_view_widget' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'full' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 25,
        ),
        'in_activity' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 21,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'view_row_details' => array(
          'label' => 'hidden',
          'module' => 'field_collection',
          'settings' => array(
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_fields',
          'weight' => 10,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_pricing',
      'label' => 'Pricing',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'field_collection',
        'settings' => array(),
        'type' => 'field_collection_embed',
        'weight' => 9,
      ),
    ),
  );

  // Exported field: 'taxonomy_term-service_category_terms-field_allow_grouping'.
  $fields['taxonomy_term-service_category_terms-field_allow_grouping'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_allow_grouping',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Don\'t allow grouping in invoices',
          1 => 'Allow grouping in invoices',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'service_category_terms',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_allow_grouping',
      'label' => 'Allow grouping',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
        ),
        'type' => 'options_onoff',
        'weight' => 33,
      ),
    ),
  );

  // Exported field: 'taxonomy_term-service_category_terms-field_is_default_term'.
  $fields['taxonomy_term-service_category_terms-field_is_default_term'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_is_default_term',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Use not as default',
          1 => 'Use as default',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'service_category_terms',
      'comment_enabled' => 0,
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'field_is_default_term',
      'label' => 'Is default',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 0,
        ),
        'type' => 'options_onoff',
        'weight' => 32,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a field for selecting the currency');
  t('Add a reference to a specification to erpal_tasks node type');
  t('Allow grouping');
  t('Budget time billing');
  t('Budgets');
  t('Choose if timetrackings are billable within a budget or not. If not they will only billed if budget is empty and there is a price set.');
  t('Currency');
  t('Is default');
  t('Price');
  t('Price mode');
  t('Pricing');
  t('Service category');
  t('VAT');

  return $fields;
}
