<?php



/**
 * Provides a basic configuration for local testing
 */
function erpal_asterisk_install(){
  variable_set('asterisk_nodejs_host'    , "127.0.0.1");
  variable_set('asterisk_nodejs_http_port'    , 8080);
  variable_set('asterisk_nodejs_socket_port'    , 3081);
  variable_set('asterisk_nodejs_lifetime', 60); 
}

/**
* Returns all the menu path for config of asterisk notify
*/
function _erpal_asterisk_menu(){
  
  $items = array();
  
  $items['admin/erpal/asterisk/core'] = array(
    'title' => 'Asterisk Core Config',
    'page callback' => '_erpal_asterisk_config',    
    'access arguments' => array('config erpal asterisk'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  $items['asterisk/ingoingcall/%'] = array(
    'page callback' => '_erpal_asterisk_call',    
    'page arguments' => array(2,3),
    'access callback' => TRUE,
  );
  return $items;
}


/*
 * This function is callback for configuration of core module
 */
function _erpal_asterisk_config(){
  
  return drupal_get_form('_erpal_asterisk_config_form');

}


/*
 * Forms wich list all views in erpal
 * @return array $form  Forms  
 */

function _erpal_asterisk_config_form() {
  
  $form= array();
  
  $form['asterisk'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Nodejs-server settings'),
    '#collapsible' => TRUE, // Added 
    '#collapsed' => FALSE, // Added
  );
    
  $form['asterisk']['host'] = array(
    '#type'        => 'textfield', 
    '#title'       => t('HOST-IP:'),
    '#default_value'     => variable_get('asterisk_nodejs_host'),
    '#description' => t('Host of NodeJs Server'),
  );
  
  $form['asterisk']['http_port'] = array(
    '#type' => 'textfield', 
    '#title' => t('HTTP Port'),
    '#default_value'     => variable_get('asterisk_nodejs_http_port'),
    '#description' => t('HTTP Port of NodeJs Server'),
  );
  
  $form['asterisk']['socket_port'] = array(
    '#type' => 'textfield', 
    '#title' => t('Socket Port'),
    '#default_value'     => variable_get('asterisk_nodejs_socket_port'),
    '#description' => t('Socket Port of NodeJs Server'),
  );
  
  $form['asterisk']['lifetime'] = array(
    '#type' => 'textfield', 
    '#title' => t('Lifetime'),
    '#default_value'     => variable_get('asterisk_nodejs_lifetime'),
    '#description' => t('Lifetime of call'),
  );
  
  $form['libphonenumber'] = array(
      '#type' => 'fieldset',
      '#title' => t('Libphonenumber config'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
  
  $form['libphonenumber']['country'] = array(
      '#type' => 'select',
      '#title' => t('Default country'),
      '#description' => t('Select the default country-code for phonenumber normalisation'),
      '#options' => libphonenumber_get_regions(),
      '#default_value' => variable_get('libphonenumber_default_country'), 
    );
  $form['libphonenumber']['area'] = array(
      '#type' => 'textfield',
      '#title' => t('Default area code'),
      '#description' => t('Enter the country code of your phonenumber. Such as "06151" for Darmstadt or "030" for Berlin'),
      '#default_value' => variable_get('libphonenumber_default_area'),
  );
    
  $form['libphonenumber']['format'] = array(
      '#type' => 'select', 
      '#title' => t('Default format for your phone numbers'), 
      '#description' => t('Select the default format for phonenumber normalisation'),
      '#options' => libphonenumber_get_formats(),
      '#default_value' => variable_get('libphonenumber_default_format'),
    );
  
  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save configurations'),
  );
 
  return $form;
  
}


/**
 * Implements form validate function for _asterisk_config_form
 * 
 */
function _erpal_asterisk_config_form_validate(&$form, &$form_state){
  if(!filter_var($form_state['values']['host'], FILTER_VALIDATE_IP)){
    form_set_error('host', t('The entered Host is not a valid IP-Address'));
  }
  if(!is_numeric($form_state['values']['http_port'])){
    form_set_error('http_port', t('HTTP-Port has to be numeric'));
  }
  if(!is_numeric($form_state['values']['socket_port'])){
    form_set_error('socket_port', t('Socket-Port has to be numeric'));
  }
  if(!is_numeric($form_state['values']['lifetime'])){
    form_set_error('lifetime', t('Lifetime has to be numeric'));
  }
    
}

/**
 *  Implemtents form Submit Function for _asterisk_config_form
 */
function _erpal_asterisk_config_form_submit(&$form, &$form_state) {

  variable_set('asterisk_nodejs_host'    , $form_state['values']['host']);
  variable_set('asterisk_nodejs_http_port'    , $form_state['values']['http_port']);
  variable_set('asterisk_nodejs_socket_port'    , $form_state['values']['socket_port']);
  variable_set('asterisk_nodejs_lifetime', $form_state['values']['lifetime']);
  
   // Save default country number in 'libphonenumber_default_country'  
  $country = $form_state['values']['country'];
  variable_set('libphonenumber_default_country', $country);
  
  $format = $form_state['values']['format'];
  variable_set('libphonenumber_default_format', $format);
   
  $area = $form_state['values']['area'];
  variable_set('libphonenumber_default_area', $area);
}

