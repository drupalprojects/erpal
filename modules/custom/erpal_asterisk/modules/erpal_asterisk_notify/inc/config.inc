<?php

/**
* Returns all the menu path for config of asterisk notify
*/
function _erpal_asterisk_notify_menu(){
  
  $items = array();
  $items['admin/erpal/asterisk/notify'] = array(
    'title' => 'Asterisk Notify Config',
    'page callback' => '_erpal_asterisk_notify_config',    
    'access arguments' => array('config erpal asterisk'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );

  return $items;
}

/*
 * This is a callback function for configuration of erpal 
 */

function _erpal_asterisk_notify_config(){
  
   //return _erpal_notify_ingoing_call('01574463596');
   return drupal_get_form('_erpal_asterisk_notify_get_view_form');
  
}

/*
 * Forms wich list all views in erpal
 * @return array $form  Forms  
 */

function _erpal_asterisk_notify_get_view_form() {
  
  $form= array();
  
  $form['description'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Select the messages for incoming call notifications'),
    '#collapsible' => TRUE, // Added 
    '#collapsed' => FALSE, // Added
  );
  
  // $form['description']['views'] = array(
    // '#type' => 'radios',
    // '#title' => t('Views'),
    // '#options' => _erpal_asterisk_notify_get_views_of_type_erpal_contact(),
    // '#default_value' => variable_get('asterisk_default_view'),
    // '#required' => TRUE,
  // );
  
  $form['description']['default_message'] = array(
    '#title' => t('Default message'),
    '#type' => 'textarea',
    '#description' => t('This message will show up when the Number is given/ For number set: %number%'),
    '#default_value' => variable_get('asterisk_default_message'),
    '#rows' => 10,
    '#cols' => 60,
    '#resizable' => TRUE,
  );
  
  $form['description']['unknown_number_message'] = array(
    '#title' => t('Unknown number message'),
    '#type' => 'textarea',
    '#description' => t('This message will show up for calls from unknown number'),
    '#default_value' => variable_get('asterisk_unknown_number_message'),
    '#rows' => 10,
    '#cols' => 60,
    '#resizable' => TRUE,
  );
  
  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save as default'),
  );
 
  return $form;
  
}

/*
 *  Implemtent form Submit Function 
 */
function _erpal_asterisk_notify_get_view_form_submit(&$form, &$form_state) {

  // variable_set('asterisk_default_view'   , $form_state['values']['views']);
  variable_set('asterisk_default_message', $form_state['values']['default_message']);
  variable_set('asterisk_unknown_number_message', $form_state['values']['unknown_number_message']);
 
}


