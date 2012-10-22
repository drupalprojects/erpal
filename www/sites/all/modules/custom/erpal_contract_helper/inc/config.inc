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
* Config callback for erpal contract feature
*/
function _erpal_contract_helper_config_basic() {
  $form = drupal_get_form('erpal_contract_helper_config_form');

  return $form;
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
  return variable_get('cancelation_precalculate_range', 60);
}