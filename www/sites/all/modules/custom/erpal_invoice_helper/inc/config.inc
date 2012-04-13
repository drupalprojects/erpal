<?php

/**
* Returns all the menu path for config of invoice feature
*/
function _erpal_invoice_helper_config_menu(){
  
  $items['admin/erpal/invoice'] = array(
    'title' => 'ERPAL invoice',
    'page callback' => '_erpal_invoice_helper_config_basic',    
    'access arguments' => array('config erpal invoice'),
    'file' => 'inc/config.inc',
    'type' => MENU_DEFAULT_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL Basic Feature
*/
function _erpal_invoice_helper_config_basic(){
  $form = drupal_get_form('erpal_invoice_helper_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL invoice
*/
function erpal_invoice_helper_config_form($form, &$form_state){

  $form = array();
  
  //@todo: Mehrwerteuersätze, zahlungsziele etc
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
  );
  
  return $form;
}

/**
* submit handler of erpal basic config form
*/
function erpal_invoice_helper_config_form_submit($form, $form_state){

  $values = $form_state['values'];

}
