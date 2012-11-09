<?php

/**
* @file provide functions for dynamic menu items in CRM context
*/
//define some contexts
define('ERPAL_CONTEXT_ACTIVITIES', 'activities'); //activities list
define('ERPAL_CONTEXT_CRM_GLOBAL', 'crm_global'); //we are in activies view or in a tab that belongs to the activities
define('ERPAL_CONTEXT_ACTIVITY', 'activity');
define('ERPAL_CONTEXT_CONTACTS', 'contacts');
define('ERPAL_CONTEXT_CONTACT_ACTIVITIES', 'contact_activities');
define('ERPAL_CONTEXT_CONTACT', 'contact');

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_crm_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();
  
  //CHECK PROJECT CONTEXT
  if (drupal_match_path($path, 'node/%*') ) {
    $node = isset($router_item['map'][1]) ? $router_item['map'][1] : false;
    
    if (!$node || !is_object($node))
      return $contexts;
    
    //may be we have a ctools context
    
    if (get_class($node) == 'ctools_context')
      $node = $node->data;    
    
    switch ($node->type) {
      case 'erpal_crm_activity':
        $contexts[ERPAL_CONTEXT_ACTIVITY] = true;              
        break;
      case 'erpal_contact':       
        $contexts[ERPAL_CONTEXT_CONTACT] = true;    
        break;      
    }
  }

  //CHECK CRM Global CONTEXT
  if (drupal_match_path($path, 'crm/contacts') || drupal_match_path($path, 'crm/activities')) {        
    $contexts[ERPAL_CONTEXT_CRM_GLOBAL] = true;      
  }
  
  
  //CHECK ACTIVITIES list CONTEXT
  if ($path == 'crm/activities') {        
    $contexts[ERPAL_CONTEXT_ACTIVITIES] = true;       
  }
  
  //CHECK PROJECTS list CONTEXT
  if ($path == 'crm/contacts') {        
    $contexts[ERPAL_CONTEXT_CONTACTS] = true;          
  }

  return $contexts;  
}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_crm_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
  //activities list context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_ACTIVITIES, $router_item)) {        
    _erpal_crm_helper_activities_links($data);       
  }
  
  //CRM global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CRM_GLOBAL, $router_item)) {    
    _erpal_crm_helper_crm_global_links($data, $router_item);       
  } 
  
  //CRM contacts context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTACTS, $router_item)) {    
    _erpal_crm_helper_contacts_links($data, $router_item);       
  } 
  
  //CRM contacts context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTACT, $router_item)) {    
    $contact_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_crm_helper_contact_links($data, $router_item, $contact_node);       
  }

  
  //Node Timetracking Context
  /*
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_NODE_TIMETRACKINGS, $router_item)) {
    $node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_projects_helper_node_timetrackings_links($data, $node); 
  }
  */
}

/**
* Adds all crm global context links
*/
function _erpal_crm_helper_crm_global_links(&$data, $router_item) {
  //single project context
  
  //hide the links if we are in a contact o
  erpal_make_local_tab($data, t('Activities'), 'crm/activities');
  erpal_make_local_tab($data, t('Contacts'), 'crm/contacts');
}

/**
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_crm_helper_erpal_menu_parents($router_item) {
  return _erpal_crm_helper_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_crm_helper_get_menu_parents($router_item) {
  $projects_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_CRM_GLOBAL, $router_item);
  
  if ($projects_global) {
    return 'crm';
  }
}

/**
* Adds all activities context links
*/
function _erpal_crm_helper_contacts_links(&$data) {
  //single project context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new contact'), 'node/add/erpal-contact', $query);
}

/**
* Adds all contact context links
*/
function _erpal_crm_helper_contact_links(&$data, $router_item, $contact_node) {
  //single project context
  $query = array();
  erpal_make_action($data, t('Edit this contact'), 'node/'.$contact_node->nid.'/edit', $query);
  $query = array('field_customer_ref' => $contact_node->nid, 'destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new activity for this contact'), 'node/add/erpal-crm-activity', $query);
  
  erpal_make_local_tab($data, t('Contacts'), 'crm/contacts');
}

/**
* Adds all activities context links
*/
function _erpal_crm_helper_activities_links(&$data) {
  //single project context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new activity'), 'node/add/erpal-crm-activity', $query);
}