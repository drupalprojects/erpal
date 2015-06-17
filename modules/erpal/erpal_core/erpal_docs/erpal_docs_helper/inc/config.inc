<?php

/**
* Returns all the menu path for config of Basic feature
*/
function _erpal_docs_helper_config_menu(){
  
  $items['admin/erpal/docs'] = array(
    'title' => 'ERPAL Docs',
    'page callback' => '_erpal_docs_helper_config_basic',    
    'access arguments' => array('config erpal docs'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL Docs Feature
*/
function _erpal_docs_helper_config_basic(){
  $form = drupal_get_form('erpal_docs_helper_config_form');
  
  return $form;
}

/**
* Form to show all settings to configure ERPAL Docs
*/
function erpal_docs_helper_config_form($form, &$form_state){

  $form = array();
  
  $form['doc_file_extensions'] = array(
    '#type' => 'textfield',
    '#title' => t('Allowed doc file extensions'),
    '#description' => t('These extensions are allowed when uploading a file to the asset management. Separate them by spaces.'),
    '#default_value' => _erpal_docs_helper_doc_extensions(),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('save'),
  );

  return $form;
}

/**
* Submithandler of config form
*/
function erpal_docs_helper_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $extensions = str_replace(',', '', $values['doc_file_extensions']);
  variable_set('erpal_docs_doc_file_extensions', $extensions);
}

/**
* Return all allowed doc extensions for files
*/
function _erpal_docs_helper_doc_extensions() {
  return variable_get('erpal_docs_doc_file_extensions', 'txt pdf');
}
