<?php
/**
 * @file
 * erpal_basic.features.field_conditional_state.inc
 */

/**
 * Implements hook_field_conditional_state_defaults().
 */
function erpal_basic_field_conditional_state_defaults() {
  $items = array();

  $items["erpal_contact:field_birthday:node:field_contact_type:invisible:company"] = array(
    'type' => 'node',
    'bundle' => 'erpal_contact',
    'field_name' => 'field_birthday',
    'control_field' => 'field_contact_type',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'company' => 'company',
    ),
  );

  $items["erpal_contact:field_company_name:node:field_contact_type:invisible:person"] = array(
    'type' => 'node',
    'bundle' => 'erpal_contact',
    'field_name' => 'field_company_name',
    'control_field' => 'field_contact_type',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'person' => 'person',
    ),
  );

  $items["erpal_contact:field_firstname:node:field_contact_type:invisible:company"] = array(
    'type' => 'node',
    'bundle' => 'erpal_contact',
    'field_name' => 'field_firstname',
    'control_field' => 'field_contact_type',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'company' => 'company',
    ),
  );

  $items["erpal_contact:field_gender:node:field_contact_type:invisible:company"] = array(
    'type' => 'node',
    'bundle' => 'erpal_contact',
    'field_name' => 'field_gender',
    'control_field' => 'field_contact_type',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'company' => 'company',
    ),
  );

  $items["erpal_contact:field_languages:node:field_contact_type:invisible:company"] = array(
    'type' => 'node',
    'bundle' => 'erpal_contact',
    'field_name' => 'field_languages',
    'control_field' => 'field_contact_type',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'company' => 'company',
    ),
  );

  $items["erpal_contact:field_lastname:node:field_contact_type:invisible:company"] = array(
    'type' => 'node',
    'bundle' => 'erpal_contact',
    'field_name' => 'field_lastname',
    'control_field' => 'field_contact_type',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'company' => 'company',
    ),
  );

  $items["erpal_contact:field_salutation:node:field_contact_type:invisible:company"] = array(
    'type' => 'node',
    'bundle' => 'erpal_contact',
    'field_name' => 'field_salutation',
    'control_field' => 'field_contact_type',
    'state' => 'invisible',
    'condition_type' => 'or',
    'trigger_values' => array(
      'company' => 'company',
    ),
  );

  return $items;
}
