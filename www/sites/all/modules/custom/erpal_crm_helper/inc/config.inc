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
function _erpal_crm_helper_config_core()
{
  return "ERPAL CRM";
}
