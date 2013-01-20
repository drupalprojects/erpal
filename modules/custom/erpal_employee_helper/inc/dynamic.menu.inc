<?php

/**
* @file provide functions for dynamic menu items in timekeeping context
*/
//define some contexts
define('ERPAL_CONTEXT_WORKING_TIMES', 'working_times'); //working_times list
define('ERPAL_CONTEXT_WORKING_TIMES_GLOBAL', 'working_times_global');
define('ERPAL_CONTEXT_WORKING_TIMES_ALL_GLOBAL', 'working_times_all_global');
define('ERPAL_CONTEXT_WORKING_TIME', 'working_time');
define('ERPAL_CONTEXT_USER_OFFSETS', 'user_offsets'); //list of offsets of a user

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_employee_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  //do we have node add form
  if (drupal_match_path($path, 'node/add/erpal-working-time*')) { 
    $contexts[ERPAL_CONTEXT_WORKING_TIMES_GLOBAL] = true;
    $contexts[ERPAL_CONTEXT_WORKING_TIME] = true;  
  }
  
  //do we have an edit form?
  if ($path == 'node/%/edit') {
    if ($node->type == 'erpal_working_time') {
      $contexts[ERPAL_CONTEXT_WORKING_TIMES_GLOBAL] = true;
    }
  }
  
  if ($path == 'user/%/timekeeping-offsets') {
    $contexts[ERPAL_CONTEXT_USER_OFFSETS] = true;
  }
     
  if (drupal_match_path($path, 'node/%*') ) {    
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/bla or something like this  
    switch ($node->type) {
      case 'erpal_working_time':  
        $contexts[ERPAL_CONTEXT_WORKING_TIME] = true; 
        $contexts[ERPAL_CONTEXT_WORKING_TIMES_GLOBAL] = true;         
        break;       
    }
  }

  //CHECK Doc Global CONTEXT
  if (drupal_match_path($path, 'timekeeping')) {  
    $contexts[ERPAL_CONTEXT_WORKING_TIMES_GLOBAL] = true;      
  }  

  if (drupal_match_path($path, 'timekeeping')) {  
    $contexts[ERPAL_CONTEXT_WORKING_TIMES] = true;        
  }    
  
  if (drupal_match_path($path, 'timekeeping/all')) {  
    $contexts[ERPAL_CONTEXT_WORKING_TIMES_ALL_GLOBAL] = true;         
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

  //Working times context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_WORKING_TIMES, $router_item)) {    
    _erpal_employee_helper_working_times_links($data);          
    _erpal_employee_helper_timekeeping_global_menu_tabs($data, $node, array('timekeeping'));   
  } 
  
  //Working Time context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_WORKING_TIME, $router_item)) {    
    _erpal_employee_helper_working_time_links($data, $node, $is_node_view); 
    _erpal_employee_helper_timekeeping_global_menu_tabs($data, $node, array('timekeeping'));   
  }
 
  //just global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_WORKING_TIMES_GLOBAL, $router_item)) {    
    _erpal_employee_helper_timekeeping_global_menu_tabs($data, $node, array('timekeeping'));   
  }
  
  //just global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_WORKING_TIMES_ALL_GLOBAL, $router_item)) {    
    _erpal_employee_helper_timekeeping_global_menu_tabs($data, $node, array('all timekeeping'));   
  }
  
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_USER_OFFSETS, $router_item)) {
    $user = $node;
    _erpal_employee_helper_user_offsets_links($data, $user);
  }
}

/**
* Adds links to list of user working times offset
*/
function _erpal_employee_helper_user_offsets_links(&$data, $user) {
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new offset'), 'working_times/add/'.$user->uid, $query);
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
  $working_times_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_WORKING_TIMES_GLOBAL, $router_item);
  $working_times_all_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_WORKING_TIMES_ALL_GLOBAL, $router_item);

  if ($working_times_global || $working_times_all_global) {
    return 'timekeeping';
  }
}

/**
* Adds all doc context links
*/
function _erpal_employee_helper_working_times_links(&$data) {
  //docs list context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new working time'), 'node/add/erpal-working-time', $query);
}


/**
* Adds all doc context links
*/
function _erpal_employee_helper_working_time_links(&$data, $node, $is_node_view=false) {
  //single doc context
  if ($is_node_view) {
    $query = array();
    erpal_make_action($data, t('Edit this working time'), 'node/'.$node->nid.'/edit', $query);    
  }
}


/**
* Show all menu tab links for doc context
*/
function _erpal_employee_helper_timekeeping_global_menu_tabs(&$data, $current_nid=false, $active_tabs=array()) {

  static $processed = false;
  
  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  //thi will only be shown if we add another tab here!
  erpal_make_local_tab($data, t('Timekeeping'), 'timekeeping', array(), in_array('timekeeping', $active_tabs));
  erpal_make_local_tab($data, t('All Timekeeping'), 'timekeeping/all', array(), in_array('all timekeeping', $active_tabs));

} 