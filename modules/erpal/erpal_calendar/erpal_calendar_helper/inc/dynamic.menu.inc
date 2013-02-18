<?php

/**
* @file provide functions for dynamic menu items in calendar context
*/
//define some contexts
define('ERPAL_CONTEXT_CALENDAR', 'calendar'); //calendar list
define('ERPAL_CONTEXT_CALENDAR_GLOBAL', 'calendar_global');
define('ERPAL_CONTEXT_DATE', 'date');

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_calendar_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  //do we have node add form
  if (drupal_match_path($path, 'node/add/erpal-date*')) { 
    $contexts[ERPAL_CONTEXT_CALENDAR_GLOBAL] = true;
    $contexts[ERPAL_CONTEXT_DATE] = true;  
  }
  
  //do we have an edit form?
  if ($path == 'node/%/edit') {
    if ($node->type == 'erpal_date') {
      $contexts[ERPAL_CONTEXT_CALENDAR_GLOBAL] = true;
    }
  }
  
  //do we have an edit form?
  if ($path == 'date_item/%/edit') {
    $contexts[ERPAL_CONTEXT_CALENDAR_GLOBAL] = true;
  }
     
  if (drupal_match_path($path, 'node/%*') ) {    
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/bla or something like this  
    switch ($node->type) {
      case 'erpal_date':  
        $contexts[ERPAL_CONTEXT_DATE] = true; 
        $contexts[ERPAL_CONTEXT_CALENDAR_GLOBAL] = true;         
        break;       
    }
  }
  
  if (drupal_match_path($path, 'date_item/%*') ) {    
    $date_item = $node; //in this case it is a date item entity not a node
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/bla or something like this     
    $contexts[ERPAL_CONTEXT_DATE] = true; 
    $contexts[ERPAL_CONTEXT_CALENDAR_GLOBAL] = true;         
  }
  
  //CHECK Doc Global CONTEXT
  if (drupal_match_path($path, 'calendar/*') || drupal_match_path($path, 'calendar')) {  
    $contexts[ERPAL_CONTEXT_CALENDAR_GLOBAL] = true;      
  }  

  if (drupal_match_path($path, 'calendar')) {  
    $contexts[ERPAL_CONTEXT_CALENDAR] = true;      
  }    

  return $contexts;  

}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_calendar_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
  $entity = _erpal_basic_helper_router_object(1, $router_item);
  $is_view = !isset($router_item['original_map'][2]) || $router_item['original_map'][2] == 'view'; 

  //Contracts contact context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CALENDAR, $router_item)) {    
    _erpal_calendar_helper_calendar_links($data);          
    _erpal_calendar_helper_calendar_global_menu_tabs($data, $entity, array('calendar'));   
  } 
  
  //CRM contacts context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_DATE, $router_item)) {    
    _erpal_calendar_helper_date_links($data, $entity, $is_view); 
    _erpal_calendar_helper_calendar_global_menu_tabs($data, $entity, array('calendar'));   
  }
 
  //just global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CALENDAR_GLOBAL, $router_item)) {    
    _erpal_calendar_helper_calendar_global_menu_tabs($data, $entity, array('calendar'));   
  }
  
  _erpal_calendar_helper_hide_menu_links($data);
}

/**
* Hide view and edit links for entities provided by calendar feature
*/
function _erpal_calendar_helper_hide_menu_links(&$data) {
  //allways remove the budget/%/edit link from local tasks
  foreach ($data['tabs'] as $delta=>$output) {
    foreach ($output['output'] as $inner_delta=>$a_output) {
      $path = $a_output['#link']['path'];
      if ($path == 'date_item/%/edit') {
        unset($data['tabs'][$delta]['output'][$inner_delta]);
      }
     
      //and if this is the view button, rename it
      if ($path == 'date_item/%' || $path == 'date_item/%/view') {
        unset($data['tabs'][$delta]['output'][$inner_delta]);
      }
    }
  }
}

/**
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_calendar_helper_erpal_menu_parents($router_item) {
  return _erpal_calendar_helper_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_calendar_helper_get_menu_parents($router_item) {
  $calendar_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_CALENDAR_GLOBAL, $router_item);

  if ($calendar_global) {
    return 'calendar';
  }
}

/**
* Adds all doc context links
*/
function _erpal_calendar_helper_calendar_links(&$data) {
  //calendar list context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new date'), 'node/add/erpal-date', $query);
}


/**
* Adds all date context links
*/
function _erpal_calendar_helper_date_links(&$data, $entity, $is_view=false) {
  //single doc context
  if ($is_view) {
    
    $query = array();
    //@TODO: not the best solutions but we need a quick check if it is a date_item or a node
    if (isset($entity->nid))
      $link = 'node/'.$entity->nid.'/edit';
    elseif (isset($entity->date_item_id)) {
      //must be a date_item
      $link = 'date_item/'.$entity->date_item_id.'/edit';
    }
    erpal_make_action($data, t('Edit this date'), $link, $query);    
  }
}


/**
* Show all menu tab links for doc context
*/
function _erpal_calendar_helper_calendar_global_menu_tabs(&$data, $current_nid=false, $active_tabs=array()) {

  static $processed = false;
  
  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  //thi will only be shown if we add another tab here!
  erpal_make_local_tab($data, t('Calendar'), 'calendar', array(), in_array('calendar', $active_tabs));

} 