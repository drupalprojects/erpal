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

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  //do we have node add form
  if (drupal_match_path($path, 'node/add/erpal-contact*')) { 
    $contexts[ERPAL_CONTEXT_CONTACT] = true;  
  } elseif (drupal_match_path($path, 'node/add/erpal-crm-activity*')) {  
    $contexts[ERPAL_CONTEXT_ACTIVITY] = true; 
  }
  
  //do we have an edit form?
  if ($path == 'node/%/edit') {
    if ($node->type == 'erpal_contact') {
      $contexts[ERPAL_CONTEXT_CONTACT] = true;
    } elseif ($node->type == 'erpal_crm_activity') { 
      $contexts[ERPAL_CONTEXT_ACTIVITY] = true;
    }
  }
     
  if (drupal_match_path($path, 'node/%*') ) {    
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/invoices or something like this
    $is_crm_context_node = false;
   
    switch ($node->type) {
      case 'erpal_contact':  
        $contexts[ERPAL_CONTEXT_CONTACT] = true;  
        break;
      case 'erpal_crm_activity':
        $contexts[ERPAL_CONTEXT_ACTIVITY] = true;          
        break;        
    }
  }
  
  //CHECK ACTIVITIES list CONTEXT
  if ($path == 'activities' || $path == 'node/%/activities') { 
    $contexts[ERPAL_CONTEXT_ACTIVITIES] = true;       
  }
  
  //CHECK Contacts list CONTEXT
  if ($path == 'contacts') {        
    $contexts[ERPAL_CONTEXT_CONTACTS] = true;          
  }
  
  //CHECK NODE Activities CONTEXT
  if ($path == 'node/%/activities') {        
    $contexts[ERPAL_CONTEXT_CONTACT_ACTIVITIES] = true;      
  }
  

  return $contexts;  

}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_crm_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
  $node = _erpal_basic_helper_router_object(1, $router_item);
  $is_node_view = !isset($router_item['original_map'][2]) || $router_item['original_map'][2] == 'view'; 
  
  //activities list context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_ACTIVITIES, $router_item)) {        
    _erpal_crm_helper_activities_links($data, $node);       
  }
  
  //CRM contacts context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTACTS, $router_item)) {    
    _erpal_crm_helper_contacts_links($data);       
    _erpal_crm_helper_crm_global_menu_tabs($data, $node, array('contacts'));   
  } 
  
  //CRM contacts context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTACT, $router_item)) {    
    _erpal_crm_helper_contact_links($data, $node, $is_node_view); 
    _erpal_crm_helper_crm_global_menu_tabs($data, $node, array('contacts'));   
  }
  
  //Node Activity Context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_ACTIVITY, $router_item)) {  
    _erpal_crm_helper_node_activity_links($data, $node, $is_node_view); 
    _erpal_crm_helper_crm_global_menu_tabs($data, $node, array('activities'));   
  }
 
  
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
  $activity = _erpal_basic_helper_has_context(ERPAL_CONTEXT_ACTIVITY, $router_item);
  $contact = _erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTACT, $router_item);
  
  if ($activity) {
    return 'activities';
  }
  
  if ($contact) {
    return 'contacts';
  }
}

/**
* Adds all activities context links
*/
function _erpal_crm_helper_contacts_links(&$data) {
  //contacts list context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new contact'), 'node/add/erpal-contact', $query);
}

/**
* Adds all activity contact links
*/
function _erpal_crm_helper_node_activity_links(&$data, $activity_node, $is_node_view=false) {
  //single activity context
  if ($is_node_view) {
    $query = array();
    erpal_make_action($data, t('Edit this activity'), 'node/'.$activity_node->nid.'/edit', $query);
    $query = array('field_activity_ref' => $activity_node->nid, 'destination' => $_GET['q']);
    erpal_make_action($data, t('Create a new project from this activity'), 'node/add/erpal-project', $query);
    erpal_make_action($data, t('Create a new contract from this activity'), 'node/add/erpal-contract', $query);
  }
  
}

/**
* Adds all contact context links
*/
function _erpal_crm_helper_contact_links(&$data, $contact_node, $is_node_view=false) {
  //single contact context
  if ($is_node_view) {
    $query = array();
    erpal_make_action($data, t('Edit this contact'), 'node/'.$contact_node->nid.'/edit', $query);
    
    $query = array('field_customer_ref' => $contact_node->nid);
    erpal_make_action($data, t('Create a new activity'), 'node/add/erpal-crm-activity', $query);
    erpal_make_action($data, t('Create a new invoice'), 'node/add/erpal-invoice', $query);
    erpal_make_action($data, t('Create a new contract'), 'node/add/erpal-contract', $query);
    
    $query = array('destination' => $_GET['q']);
    erpal_make_action($data, t('Create a new relation'), 'node/'.$contact_node->nid.'/relations/add', $query);
    
  }
}

/**
* Adds all activities context links
*/
function _erpal_crm_helper_activities_links(&$data, $contact_node=false) {
  $contact_nid = false;
  $query = array('destination' => $_GET['q']);
  if (is_object($contact_node) && $contact_node) {
    $query['field_customer_ref'] = $contact_node->nid;
    $contact_nid = $contact_node->nid;
  }
  
  erpal_make_action($data, t('Create a new activity'), 'node/add/erpal-crm-activity', $query);
  _erpal_crm_helper_crm_global_menu_tabs($data, $contact_nid);
}

/**
* Show all menu tab links for crm context
*/
function _erpal_crm_helper_crm_global_menu_tabs(&$data, $current_nid=false, $active_tabs=array()) {

  static $processed = false;
  
  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  //erpal_make_local_tab($data, t('Activities'), 'activities', array(), in_array('activities', $active_tabs)); 
  //erpal_make_local_tab($data, t('Contacts'), 'contacts', array(), in_array('contacts', $active_tabs)); 
} 