<?php

/**
* @file provide functions for dynamic menu items
*/
//define some contexts
define('ERPAL_CONTEXT_OWN_HEARTBEAT', 'own_heartbeat');
define('ERPAL_CONTEXT_GLOBAL_HEARTBEAT', 'global_heartbeat');

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_heartbeat_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  if (drupal_match_path($path, 'heartbeat/*')) {  
    $contexts[ERPAL_CONTEXT_OWN_HEARTBEAT] = true;         
  }    
  
  if (drupal_match_path($path, 'heartbeat/all')) {  
    $contexts[ERPAL_CONTEXT_GLOBAL_HEARTBEAT] = true;         
  }    
  
  return $contexts;  

}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_heartbeat_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
 
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_OWN_HEARTBEAT, $router_item)) {         
    _erpal_heartbeat_global_menu_tabs($data, array('own heartbeat'));   
  } 
 
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_GLOBAL_HEARTBEAT, $router_item)) {         
    _erpal_heartbeat_global_menu_tabs($data, array('heartbeat'));   
  } 
 
}

/**
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_heartbeat_erpal_menu_parents($router_item) {
  return _erpal_heartbeat_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_heartbeat_get_menu_parents($router_item) {
  $heartbeat_own = _erpal_basic_helper_has_context(ERPAL_CONTEXT_OWN_HEARTBEAT, $router_item);
  $heartbeat_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_GLOBAL_HEARTBEAT, $router_item);

  if ($heartbeat_own || $heartbeat_global) {
    return 'heartbeat';
  }
}

/**
* Show all menu tab links for doc context
*/
function _erpal_heartbeat_global_menu_tabs(&$data, $active_tabs=array()) {

  static $processed = false;
  
  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  //thi will only be shown if we add another tab here!
  erpal_make_local_tab($data, t('Heartbeat'), 'heartbeat/all', array(), in_array('heartbeat', $active_tabs));
  erpal_make_local_tab($data, t('Own heartbeat'), 'heartbeat', array(), in_array('heartbeat', $active_tabs));

} 