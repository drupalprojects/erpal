<?php

/**
* Returns all the menu path for config
*/
function _erpal_basic_helper_config_menu(){
  
  $items['admin/erpal'] = array(
    'title' => 'ERPAL',
    'page callback' => '_erpal_basic_helper_config',    
    'access arguments' => array('access erpal config'),
    'file' => 'inc/config.inc',
    'type' => MENU_NORMAL_ITEM,
  );
  
  $items['admin/erpal/core'] = array(
    'title' => 'ERPAL Core',
    'page callback' => '_erpal_basic_helper_config_core',    
    'access arguments' => array('access erpal config'),
    'file' => 'inc/config.inc',
    'type' => MENU_DEFAULT_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Provides basic config interface for ERPAL
*/
function _erpal_basic_helper_config(){
  
  drupal_goto('admin/erpal/core');
}

function _erpal_basic_helper_config_core(){

  return 'hallo ERPAL CORE CONFIG. Hier sollten Tabs erscheinen.';
}