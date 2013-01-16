<?php

/**
* @file provide functions for dynamic menu items in Contracts context
*/
//define some contexts
define('ERPAL_CONTEXT_CONTRACTS', 'contracts'); //contracts list
define('ERPAL_CONTEXT_CONTRACT_GLOBAL', 'contract_global');
define('ERPAL_CONTEXT_CONTRACT', 'contract');

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_contract_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  //do we have node add form
  if (drupal_match_path($path, 'node/add/erpal-contract*')) { 
    $contexts[ERPAL_CONTEXT_CONTRACT_GLOBAL] = true;
    $contexts[ERPAL_CONTEXT_CONTRACT] = true;  
  }
  
  //do we have an edit form?
  if ($path == 'node/%/edit') {
    if ($node->type == 'erpal_contract') {
      $contexts[ERPAL_CONTEXT_CONTRACT_GLOBAL] = true;
    }
  }
     
  if (drupal_match_path($path, 'node/%*') ) {    
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/bla or something like this
    $is_crm_context_node = false;
   
    switch ($node->type) {
      case 'erpal_contract':  
        $is_crm_context_node = true;
        $contexts[ERPAL_CONTEXT_CONTRACT] = true;  
        break;       
    }
  }
  
  //CHECK CRM Global CONTEXT
  if (drupal_match_path($path, 'contracts/*') || drupal_match_path($path, 'contracts')) {  
    $contexts[ERPAL_CONTEXT_CONTRACT_GLOBAL] = true;      
  }   

  return $contexts;  

}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_contract_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
  $node = _erpal_basic_helper_router_object(1, $router_item);
  $is_node_view = !isset($router_item['original_map'][2]) || $router_item['original_map'][2] == 'view'; 

  //Contracts contact context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTRACT, $router_item)) {    
    _erpal_contract_helper_contacts_links($data);          
    _erpal_contract_helper_contracts_global_menu_tabs($data, $node, array('contracts'));   
  } 
  
  //CRM contacts context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTACT, $router_item)) {    
    _erpal_contract_helper_contract_links($data, $node, $is_node_view); 
    _erpal_contract_helper_contracts_global_menu_tabs($data, $node, array('contracts'));   
  }
 
  //just global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTRACT_GLOBAL, $router_item)) {    
    _erpal_contract_helper_contracts_global_menu_tabs($data, $node, array('contracts'));   
  }
}

/**
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_contract_helper_erpal_menu_parents($router_item) {
  return _erpal_contract_helper_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_contract_helper_get_menu_parents($router_item) {
  $crm_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_CONTRACT_GLOBAL, $router_item);
  
  if ($crm_global) {
    return 'contracts';
  }
}

/**
* Adds all contract context links
*/
function _erpal_contract_helper_contacts_links(&$data) {
  //contracts list context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new contract'), 'node/add/erpal-contract', $query);
}


/**
* Adds all contract context links
*/
function _erpal_contract_helper_contract_links(&$data, $contact_node, $is_node_view=false) {
  //single contact context
  if ($is_node_view) {
    $query = array();
    erpal_make_action($data, t('Edit this contract'), 'node/'.$contact_node->nid.'/edit', $query);    
  }
}


/**
* Show all menu tab links for contract context
*/
function _erpal_contract_helper_contracts_global_menu_tabs(&$data, $current_nid=false, $active_tabs=array()) {

  static $processed = false;
  
  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  erpal_make_local_tab($data, t('Contracts'), 'contacts', array(), in_array('contracts', $active_tabs)); 
} 