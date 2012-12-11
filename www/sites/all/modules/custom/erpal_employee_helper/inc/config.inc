<?php

/**
* Returns all the menu path for config of employee feature
*/
function _erpal_employee_helper_config_menu(){
  
  $items['admin/erpal/employee'] = array(
    'title' => 'ERPAL Employee',
    'page callback' => '_erpal_employee_helper_config_basic',    
    'access arguments' => array('config erpal employee'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL employee Feature
*/
function _erpal_employee_helper_config_basic(){
  $form = drupal_get_form('erpal_employee_helper_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL employee
*/
function erpal_employee_helper_config_form($form, &$form_state){

  $form = array();
  
  $form['erpal_employee_holiday_month_transfer'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount of month to transfer holiday days'),
    '#description' => t('The number of month rest holiday days are are transfered to the next year.'),
    '#default_value' => _erpal_employee_get_holiday_month_transfer(),
  );
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
    '#submit' => array('_erpal_employee_helper_config_form_submit'),
  );
  
  return $form;
}

/**
* Submit handler of employee config form
*/
function _erpal_employee_helper_config_form_submit($form, $form_state) {
  $values = $form_state['values'];
  
  $erpal_employee_holiday_month_transfer = $values['erpal_employee_holiday_month_transfer'];
  variable_set('erpal_employee_holiday_month_transfer', intval($erpal_employee_holiday_month_transfer));
}

/**
* Returns the amount of months that "not used" holidays will be transfered into the next year.
*/
function _erpal_employee_get_holiday_month_transfer() {
  return variable_get('erpal_employee_holiday_month_transfer', 3);
}