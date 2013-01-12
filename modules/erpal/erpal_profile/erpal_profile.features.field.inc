<?php
/**
 * @file
 * erpal_profile.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function erpal_profile_field_default_fields() {
  $fields = array();

  // Exported field: 'field_collection_item-field_contract_data-field_billing_duration'.
  $fields['field_collection_item-field_contract_data-field_billing_duration'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_billing_duration',
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
      'bundle' => 'field_contract_data',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The billing duration of an invoice by this worker',
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
          'weight' => 6,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_billing_duration',
      'label' => 'Billing duration',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 7,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_contract_data-field_currency'.
  $fields['field_collection_item-field_contract_data-field_currency'] = array(
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
      'bundle' => 'field_contract_data',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'The currency for invoices by this worker',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 5,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_currency',
      'label' => 'Currency',
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

  // Exported field: 'field_collection_item-field_contract_data-field_holiday_per_year'.
  $fields['field_collection_item-field_contract_data-field_holiday_per_year'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_holiday_per_year',
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
      'bundle' => 'field_contract_data',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'How many days a year the worker has for holiday',
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
          'weight' => 3,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_holiday_per_year',
      'label' => 'Holiday a year',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 4,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_contract_data-field_hours'.
  $fields['field_collection_item-field_contract_data-field_hours'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_hours',
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
      'bundle' => 'field_contract_data',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Hours a week the worker has to work',
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
          'weight' => 2,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_hours',
      'label' => 'Hours a week',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 3,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_contract_data-field_member_type'.
  $fields['field_collection_item-field_contract_data-field_member_type'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_member_type',
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
          'freelancer' => 'Freelancer',
          'full_employee' => 'Full employee',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'field_contract_data',
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
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_member_type',
      'label' => 'Member type',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 1,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_contract_data-field_price'.
  $fields['field_collection_item-field_contract_data-field_price'] = array(
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
      'bundle' => 'field_contract_data',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Costs per hour for freelancers (excl VAT) and employees (incl social charge)',
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
          'weight' => 7,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_price',
      'label' => 'Price per h',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_contract_data-field_project_tags'.
  $fields['field_collection_item-field_contract_data-field_project_tags'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_project_tags',
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
            'vocabulary' => 'project_tags',
            'parent' => '0',
          ),
        ),
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'field_contract_data',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Specify project tags so you can make contracts depending on project types',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'taxonomy',
          'settings' => array(),
          'type' => 'taxonomy_term_reference_link',
          'weight' => 8,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_project_tags',
      'label' => 'Project tags',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'taxonomy',
        'settings' => array(
          'autocomplete_path' => 'taxonomy/autocomplete',
          'size' => 60,
        ),
        'type' => 'taxonomy_autocomplete',
        'weight' => 9,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_contract_data-field_valid_since'.
  $fields['field_collection_item-field_contract_data-field_valid_since'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_valid_since',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'date',
      'settings' => array(
        'cache_count' => '4',
        'cache_enabled' => 0,
        'granularity' => array(
          'day' => 'day',
          'hour' => 0,
          'minute' => 0,
          'month' => 'month',
          'second' => 0,
          'year' => 'year',
        ),
        'profile2_private' => FALSE,
        'repeat' => 0,
        'timezone_db' => '',
        'todate' => '',
        'tz_handling' => 'none',
      ),
      'translatable' => '0',
      'type' => 'datestamp',
    ),
    'field_instance' => array(
      'bundle' => 'field_contract_data',
      'deleted' => '0',
      'description' => 'At which date the contract data will be used',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'date',
          'settings' => array(
            'format_type' => 'erpal_date',
            'fromto' => 'both',
            'multiple_from' => '',
            'multiple_number' => '',
            'multiple_to' => '',
            'show_repeat_rule' => 'show',
          ),
          'type' => 'date_default',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_valid_since',
      'label' => 'Valid since',
      'required' => 0,
      'settings' => array(
        'default_value' => 'blank',
        'default_value2' => 'same',
        'default_value_code' => '',
        'default_value_code2' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'date',
        'settings' => array(
          'increment' => '15',
          'input_format' => 'm/d/Y - H:i:s',
          'input_format_custom' => '',
          'label_position' => 'above',
          'repeat_collapsed' => 0,
          'text_parts' => array(),
          'year_range' => '-3:+3',
        ),
        'type' => 'date_popup',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'field_collection_item-field_contract_data-field_vat_rate'.
  $fields['field_collection_item-field_contract_data-field_vat_rate'] = array(
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
      'bundle' => 'field_contract_data',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'VAT rate for invoices by this worker',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 4,
        ),
      ),
      'entity_type' => 'field_collection_item',
      'field_name' => 'field_vat_rate',
      'label' => 'VAT rate',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 5,
      ),
    ),
  );

  // Exported field: 'profile2-contract-field_contract_data'.
  $fields['profile2-contract-field_contract_data'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_contract_data',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'field_collection',
      'settings' => array(
        'hide_blank_items' => TRUE,
        'path' => '',
        'profile2_private' => 1,
      ),
      'translatable' => '0',
      'type' => 'field_collection',
    ),
    'field_instance' => array(
      'bundle' => 'contract',
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
            'view_mode' => 'full',
          ),
          'type' => 'field_collection_view',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_contract_data',
      'label' => 'Contract data',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'field_collection_table',
        'settings' => array(),
        'type' => 'field_collection_table',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'profile2-main-field_contact_ref'.
  $fields['profile2-main-field_contact_ref'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_contact_ref',
      'foreign keys' => array(),
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
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'main',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => TRUE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_contact_ref',
      'label' => 'Contact',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'references_dialog_add' => 1,
          'references_dialog_edit' => 1,
          'references_dialog_search' => 1,
          'references_dialog_search_view' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => 0,
      ),
    ),
  );

  // Exported field: 'profile2-main-field_hours_per_day'.
  $fields['profile2-main-field_hours_per_day'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '7',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_hours_per_day',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'decimal_separator' => '.',
        'precision' => '10',
        'profile2_private' => 0,
        'scale' => '2',
      ),
      'translatable' => '0',
      'type' => 'number_decimal',
    ),
    'field_instance' => array(
      'bundle' => 'main',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Monday till sunday basic availability per day',
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
          'weight' => 2,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_hours_per_day',
      'label' => 'Available hours per day',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 2,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('At which date the contract data will be used');
  t('Available hours per day');
  t('Billing duration');
  t('Contact');
  t('Contract data');
  t('Costs per hour for freelancers (excl VAT) and employees (incl social charge)');
  t('Currency');
  t('Holiday a year');
  t('Hours a week');
  t('Hours a week the worker has to work');
  t('How many days a year the worker has for holiday');
  t('Member type');
  t('Monday till sunday basic availability per day');
  t('Price per h');
  t('Project tags');
  t('Specify project tags so you can make contracts depending on project types');
  t('The billing duration of an invoice by this worker');
  t('The currency for invoices by this worker');
  t('VAT rate');
  t('VAT rate for invoices by this worker');
  t('Valid since');

  return $fields;
}
