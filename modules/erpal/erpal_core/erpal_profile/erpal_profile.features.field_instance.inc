<?php
/**
 * @file
 * erpal_profile.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function erpal_profile_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_billing_duration'
  $field_instances['field_collection_item-field_contract_data-field_billing_duration'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
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
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_currency'
  $field_instances['field_collection_item-field_contract_data-field_currency'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
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
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_expense_category'
  $field_instances['field_collection_item-field_contract_data-field_expense_category'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_expense_category',
    'label' => 'Expense category',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_holiday_per_year'
  $field_instances['field_collection_item-field_contract_data-field_holiday_per_year'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
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
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_hours'
  $field_instances['field_collection_item-field_contract_data-field_hours'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
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
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_member_type'
  $field_instances['field_collection_item-field_contract_data-field_member_type'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
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
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_price'
  $field_instances['field_collection_item-field_contract_data-field_price'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
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
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_project_tags'
  $field_instances['field_collection_item-field_contract_data-field_project_tags'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
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
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_valid_since'
  $field_instances['field_collection_item-field_contract_data-field_valid_since'] = array(
    'bundle' => 'field_contract_data',
    'deleted' => 0,
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
        'increment' => 15,
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
  );

  // Exported field_instance:
  // 'field_collection_item-field_contract_data-field_vat_rate'
  $field_instances['field_collection_item-field_contract_data-field_vat_rate'] = array(
    'bundle' => 'field_contract_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Tax rate for invoices by this worker',
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
    'label' => 'Tax rate',
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
  );

  // Exported field_instance: 'profile2-contract-field_contract_data'
  $field_instances['profile2-contract-field_contract_data'] = array(
    'bundle' => 'contract',
    'default_value' => NULL,
    'deleted' => 0,
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
      'settings' => array(
        'nodragging' => FALSE,
      ),
      'type' => 'field_collection_table',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'profile2-main-field_contact_ref'
  $field_instances['profile2-main-field_contact_ref'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'erpal_basic_helper',
        'settings' => array(
          'link' => TRUE,
        ),
        'type' => 'entityreference_typed_label',
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
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'profile2-main-field_hours_per_day'
  $field_instances['profile2-main-field_hours_per_day'] = array(
    'bundle' => 'main',
    'default_value' => NULL,
    'deleted' => 0,
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
  t('Expense category');
  t('Holiday a year');
  t('Hours a week');
  t('Hours a week the worker has to work');
  t('How many days a year the worker has for holiday');
  t('Member type');
  t('Monday till sunday basic availability per day');
  t('Price per h');
  t('Project tags');
  t('Specify project tags so you can make contracts depending on project types');
  t('Tax rate');
  t('Tax rate for invoices by this worker');
  t('The billing duration of an invoice by this worker');
  t('The currency for invoices by this worker');
  t('Valid since');

  return $field_instances;
}
