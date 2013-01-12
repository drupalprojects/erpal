<?php

/**
* @file provide functions for dynamic menu items in Timekeeping context
*/
//define some contexts
define('ERPAL_CONTEXT_TIMEKEEPING_GLOBAL', 'timekeeping_global'); //timekeeping lists
define('ERPAL_CONTEXT_TIMEKEEPING_USER', 'timekeeping_user'); //timekeeping offsets profil page
//@TODO add edit and add form links and contexts

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_employee_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  //do we have node add form
  if (drupal_match_path($path, 'node/add/erpal-working-time')) { 
    $contexts[ERPAL_CONTEXT_TIMEKEEPING_GLOBAL] = true;
  }
  
  //do we have an edit form?
  if ($path == 'node/%/edit') {
    if ($node->type == 'erpal_working_time') {
      $contexts[ERPAL_CONTEXT_TIMEKEEPING_GLOBAL] = true;
    }
  }
     
  if (drupal_match_path($path, 'node/%*') ) {    
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/abc or something like this
    if ($node->type == 'erpal_working_time') {
      if (arg(2) && arg(2) != 'edit') {
        $contexts[ERPAL_CONTEXT_TIMEKEEPING_GLOBAL] = true;  
      } else {
        $contexts[ERPAL_CONTEXT_TIMEKEEPING_GLOBAL] = true;  
      }
    }
    
  }

  //Timekeeping Global CONTEXT
  if (drupal_match_path($path, 'timekeeping*')) {        
    $contexts[ERPAL_CONTEXT_TIMEKEEPING_GLOBAL] = true;      
  }
  
  //Timekeeping User CONTEXT
  if (drupal_match_path($path, 'user/%/timekeeping-offsets')) {        
    $contexts[ERPAL_CONTEXT_TIMEKEEPING_USER] = true;      
  }
  

  return $contexts;  

}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_employee_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
  $node = _erpal_basic_helper_router_object(1, $router_item);
  $is_node_view = !isset($router_item['original_map'][2]) || $router_item['original_map'][2] == 'view'; 
  
  //activities list context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMEKEEPING_GLOBAL, $router_item)) {        
    _erpal_employee_helper_timekeeping_global_links($data);       
  }
  
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMEKEEPING_USER, $router_item)) {        
    _erpal_employee_helper_timekeeping_offsets_user_links($data, $router_item);       
  }  
  
}

/**
* Shows all global timekeeping links
*/
function _erpal_employee_helper_timekeeping_global_links(&$data) {
  //contacts list context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new working time'), 'node/add/erpal-working-time', $query);
  
  _erpal_employee_helper_crm_global_menu_tabs($data);
}

/**
* Shows all links on users profile timekeeting offsets pages
*/
function _erpal_employee_helper_timekeeping_offsets_user_links(&$data, $router_item) {
  //contacts list context
  $query = array('destination' => $_GET['q']);
  $uid = $router_item['original_map'][1];
  erpal_make_action($data, t('Add new offset'), 'working_times/add/'.$uid, $query);
  
}

/**
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_employee_helper_erpal_menu_parents($router_item) {
  return _erpal_employee_helper_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_employee_helper_get_menu_parents($router_item) {
  $timekeeping_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMEKEEPING_GLOBAL, $router_item);

  if ($timekeeping_global) {
    return 'timekeeping';
  }
}

/**
* Show all menu tab links for crm context
*/
function _erpal_employee_helper_crm_global_menu_tabs(&$data, $current_nid=false, $active_tabs=array()) {

  static $processed = false;
  
  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  erpal_make_local_tab($data, t('My timekeeping'), 'timekeeping', array(), in_array('my_timekeeping', $active_tabs)); 
  erpal_make_local_tab($data, t('All timekeeping'), 'timekeeping/all', array(), in_array('all_timekeeping', $active_tabs)); 
} 
