<?php

/**
* Returns all the menu path for config of asterisk notify
*/
function _erpal_asterisk_notify_menu(){
  
  $items = array();
  $items['admin/erpal/asterisk/notify'] = array(
    'title' => 'Asterisk Notify Config',
    'page callback' => '_erpal_asterisk_notify_config',    
    'access arguments' => array('config erpal asterisk notify'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );

  return $items;
}



