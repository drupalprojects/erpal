<?php

/**
* Returns all the menu path for config of crm feature
*/
function _erpal_crm_helper_config_menu(){
  
  $items['admin/erpal/crm'] = array(
    'title' => 'ERPAL CRM',
    'page callback' => '_erpal_crm_helper_config_core',    
    'access arguments' => array('config erpal crm'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL CRM Feature
*/
function _erpal_crm_helper_config_core() {
  return drupal_get_form('erpal_crm_helper_config_form');
}

/**
* Form for crm config
*/
function erpal_crm_helper_config_form($form,$form_state) {
  //add a link to edit activity status terms
  $form = array();
  
  $form['status_terms_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit activity status terms'), 'admin/structure/taxonomy/activity_status_terms'),
  );
  
  return system_settings_form($form);
}
