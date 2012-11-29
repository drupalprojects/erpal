<?php

/**
* @file functions for configuration of contract feature
*/

function _erpal_contract_helper_config_menu() {

  $items['admin/erpal/contract'] = array(
    'title' => 'ERPAL Contract',
    'page callback' => '_erpal_contract_helper_config_basic',    
    'access arguments' => array('config erpal contract'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Alter invoice config form to add configuration options for contract billables
*/
function _erpal_contract_helper_invoice_helper_config_form_alter(&$form, &$form_state) {
  $form['billable_texts']['contract_billable_texts'] = array(
    '#type' => 'textfield',
    '#title' => t('Contract billable texts'),
    '#description' => t('This text will be used as subject for billables in contract context.'),
    '#default_value' => _erpal_contract_helper_get_billable_text(),
    '#maxlength' => 255,
    '#suffix' => theme('token_tree', array(
        'token_types' => array('erpal_contract_billable_subject'),
        'global_types' => FALSE,
        'click_insert' => TRUE,
      )      
    ),//add available tokens to the form
    '#weight' => 10, //show it at the end
  );
  
  $form['submit']['#submit'][] = '_erpal_contract_helper_invoice_helper_config_form_submit';
}

/**
* Additional submit handler for invoice helper config form to set variables for contract billables text
*/
function _erpal_contract_helper_invoice_helper_config_form_submit($form, $form_state) {
  $values = $form_state['values'];
  $contract_billable_texts = $values['contract_billable_texts'];
  variable_set('erpal_billable_text_erpal_contract', $contract_billable_texts);
}

/**
* Return the text that is useed for billables subject text
*/
function _erpal_contract_helper_get_billable_text() {

  $default_text = t('Payment for !service_category_token contract "!contract_title_token"', array('!service_category_token' => '[erpal_contract_billable_subject:service_category]', '!contract_title_token' => '[erpal_contract_billable_subject:contract_title]'));
  return variable_get('erpal_billable_text_erpal_contract', $default_text);
}

/**
* Config callback for erpal contract feature
*/
function _erpal_contract_helper_config_basic() {
  $form = drupal_get_form('erpal_contract_helper_config_form');

  return $form;
}

/**
* Adds tag textfields for calendar tags on date_item entites
*/
function _erpal_contract_helper_alter_calendar_config_form(&$form, $form_state) {
 
  $field_names = array('field_cancelation_period', 'field_cancelation_period_con', 'field_date');
  $entity_type = 'node';
  $bundle_name = 'erpal_contract';
  
  foreach ($field_names as $field_name) {
    $form['date_item_tags'][$entity_type][$bundle_name][$field_name] = array(
      '#type' => 'textfield',
      '#title' => t('Tags for field !field_name', array('!field_name' => $field_name)),
      '#description' => t('This tag will be added as category to entities with this field'),
      '#default_value' => _erpal_calendar_helper_field_tag($entity_type, $bundle_name, $field_name),
    );
  }
}

/**
* Settings form for contract settings
*/
function erpal_contract_helper_config_form($form, $form_state) {
  $form = array();
  
  $form['cancelation_precalculate_range'] = array(
    '#type' => 'textfield',
    '#title' => t('Precalculation range contract duration'),
    '#description' => t('Number of month the date items for contract calculation are precalculated.'),
    '#default_value' => _erpal_contract_helper_cancelation_precalculate_range(),
  );  
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
    '#submit' => array('_erpal_contract_helper_config_form_submit'),
  );

  return $form;
}

/**
* submit handler for config form
*/
function _erpal_contract_helper_config_form_submit($form, $form_state) {
  $values = $form_state['values'];

  $cancelation_precalculate_range = intval($values['cancelation_precalculate_range']);
  
  variable_set('cancelation_precalculate_range', $cancelation_precalculate_range);
}

/**
* returns the precalculation range for contract cancelation dates
*/
function _erpal_contract_helper_cancelation_precalculate_range() {
  return variable_get('cancelation_precalculate_range', 500);
}