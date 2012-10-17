<?php

/**
* Returns all the menu path for config of invoice feature
*/
function _erpal_calendar_helper_config_menu(){
  
  $items['admin/erpal/calendar'] = array(
    'title' => 'ERPAL calendar',
    'page callback' => '_erpal_calendar_helper_config_basic',    
    'access arguments' => array('config erpal calendar'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL Basic Feature
*/
function _erpal_calendar_helper_config_basic(){
  $form = drupal_get_form('erpal_calendar_helper_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL invoice
*/
function erpal_calendar_helper_config_form($form, &$form_state){

  $form = array();
  
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
    '#submit' => '_erpal_calendar_helper_config_form_submit',
  );
  
  return $form;
}

/**
* submit handler of erpal calendar config form
*/
function _erpal_calendar_helper_config_form_submit($form, $form_state){

  $values = $form_state['values'];

}
