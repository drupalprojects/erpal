<?php

/**
* Define the vat field
*/
function _erpal_billable_vat_field() {
  $instance = array(
    'label' => t('VAT'),
    'description' => t('Add a reference to a specification to erpal_tasks node type'),
    'field_name' => 'field_vat_rate',
    'entity_type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => 'erpal_billable_field_vat_rate_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'list_integer',
      
    'field_instance' => array(
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '3',
      ),
    ),
  );
  
  return $instance;
}

/**
* Define the currency field
*/
function _erpal_billable_currency_field() {
  $instance = array(
    'label' => t('Currency'),
    'description' => t('Add a field for selecting the currency'),
    'field_name' => 'field_currency',
    'entity_type' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'settings' => array(
        'allowed_values' => array(),
        'allowed_values_function' => 'erpal_billable_field_currency_allowed_values',
      ),
      'translatable' => '0',
      'type' => 'list_text',
      
    'field_instance' => array(
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '4',
      ),
    ),
  );
  
  return $instance;
}

/**
* Adds a field for VAT to the entity field_collection_item with the bundle field_pricing
* Called in hook_enable in install file
*/
function _erpal_billable_add_vat_field_instances() {
  
  //get the field definition
  $vat_field = _erpal_billable_vat_field();
  
  $afield = field_info_field('field_vat_rate');
  
  if (!$afield['id'])
    field_create_field($vat_field);
  
  //attach field only if it is not attached
  $ainstance = field_info_instance('field_collection_item', 'field_vat_rate', 'field_pricing');
  if (!$ainstance['id'])
    field_create_instance($vat_field);
}


/**
* Adds a field for Currency to the entity field_collection_item with the bundle field_pricing
* Called in hook_enable in install file
*/
function _erpal_billable_add_currency_field_instances() {
 
  //get the field definition
  $currency_field = _erpal_billable_currency_field();
  
  $afield = field_info_field('field_currency');

  if (!$afield['id'])
    field_create_field($currency_field);
  
  //attach field only if it is not attached
  $ainstance = field_info_instance('field_collection_item', 'field_currency', 'field_pricing');
  if (!$ainstance['id'])
    field_create_instance($currency_field);
}