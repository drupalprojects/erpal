<?php

/**
* @file here are all functions available that help to configure erpal in the erpal config form.
*/

/**
* Returns all the menu path for config of crm feature
*/
function _erpal_projects_helper_config_menu(){
  
  $items['admin/erpal/projects'] = array(
    'title' => 'ERPAL Projects',
    'page callback' => '_erpal_projects_helper_config_projects',    
    'access arguments' => array('config erpal projects'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL CRM Feature
*/
function _erpal_projects_helper_config_projects()
{
  return "ERPAL Projects";
}