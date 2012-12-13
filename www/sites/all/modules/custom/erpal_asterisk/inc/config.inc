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
    'type' => MENU_LOCAL_TASK,
  );
  $items['asterisk/ingoingcall/%'] = array(
    'page callback' => '_erpal_asterisk_call',    
    'page arguments' => array(2,3),
    'access callback' => TRUE,
  );

  return $items;
}



