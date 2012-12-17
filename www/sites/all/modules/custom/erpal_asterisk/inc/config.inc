<?php

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
 * This function is callback for configuration of cor module
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
  
  $form['description'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Configurations of asterisk core'),
    '#collapsible' => TRUE, // Added 
    '#collapsed' => FALSE, // Added
  );
    
  $form['description']['host'] = array(
    '#type'        => 'textfield', 
    '#title'       => t('HOST:'),
    '#default_value'     => variable_get('asterisk_nodejs_host'),
    '#description' => t('Host of NodeJs Server'),
  );
  
  $form['description']['http_port'] = array(
    '#type' => 'textfield', 
    '#title' => t('HTTP Port'),
    '#default_value'     => variable_get('asterisk_nodejs_http_port'),
    '#description' => t('HTTP Port of NodeJs Server'),
  );
  
  $form['description']['socket_port'] = array(
    '#type' => 'textfield', 
    '#title' => t('Socket Port'),
    '#default_value'     => variable_get('asterisk_nodejs_socket_port'),
    '#description' => t('Socket Port of NodeJs Server'),
  );
  
  $form['description']['lifetime'] = array(
    '#type' => 'textfield', 
    '#title' => t('Lifetime'),
    '#default_value'     => variable_get('asterisk_nodejs_lifetime'),
    '#description' => t('Lifetime of call'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save configurations'),
  );
 
  return $form;
  
}


