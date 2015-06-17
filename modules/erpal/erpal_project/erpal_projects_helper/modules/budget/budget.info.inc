<?php

/**
 * @file
 * Entity support.
 */

/**
 * Implements hook_property_info().
 */
function budget_entity_property_info() {
  $info = array();

  // Add meta-data about budget properties.
  $properties = &$info['budget']['properties'];

  $properties['budget_id'] = array(
    'label' => t('Budget ID'),
    'description' => t('The primary identifier for a budget.'),
    'type' => 'integer',
    'schema field' => 'budget_id',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The type (bundle) of the activity.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'options list' => 'budget_type_get_names',
    'required' => TRUE,
    'schema field' => 'type',
  );
  $properties['created'] = array(
    'label' => t('Date created'),
    'description' => t('The date the budget was created.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'schema field' => 'created',
  );
  $properties['changed'] = array(
    'label' => t('Date updated'),
    'description' => t('The date the budget was last updated.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'Administer site configuration',
    'schema field' => 'changed',
  );
  $properties['available_hours'] = array(
    'label' => t('Available'),
    'description' => t('The available value of the budget.'),
    'type' => 'decimal',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'Administer site configuration',
    'schema field' => 'available_hours',
  );
  $properties['total_hours'] = array(
    'label' => t('Total'),
    'description' => t('The total value of the budget.'),
    'type' => 'decimal',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'Administer site configuration',
    'schema field' => 'total_hours',
  );
  $properties['date_from'] = array(
    'label' => t('Date from'),
    'description' => t('The date the budget was created.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'schema field' => 'date_from',
  );
  $properties['date_till'] = array(
    'label' => t('Date till'),
    'description' => t('The date the budget was last updated.'),
    'type' => 'date',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'Administer site configuration',
    'schema field' => 'date_till',
  );

  // Metadata of budget Type.
  $properties = &$info['budget_type']['properties'];

  $properties['id'] = array(
    'label' => t('Budget Type ID'),
    'description' => t('Primary Key: Unique activity type ID.'),
    'type' => 'integer',
    'schema field' => 'id',
  );
  $properties['type'] = array(
    'label' => t('Type'),
    'description' => t('The machine-readable name of this type.'),
    'type' => 'token',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'required' => TRUE,
    'schema field' => 'type',
  );
  $properties['label'] = array(
    'label' => t('Label'),
    'description' => t('The human-readable name of this type.'),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'required' => TRUE,
    'schema field' => 'label',
  );
  $properties['description'] = array(
    'label' => t('Description'),
    'description' => t('A brief description of this type.'),
    'type' => 'text',
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer site configuration',
    'schema field' => 'description',
  );

  return $info;
}
