<?php

/**
* @file provide functions for dynamic menu items in Contracts context
*/
//define some contexts
define('ERPAL_CONTEXT_DOCS', 'docs'); //docs list
define('ERPAL_CONTEXT_DOC_GLOBAL', 'doc_global');
define('ERPAL_CONTEXT_DOC', 'doc');

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_docs_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  //do we have node add form
  if (drupal_match_path($path, 'node/add/erpal-file*')) { 
    $contexts[ERPAL_CONTEXT_DOC_GLOBAL] = true;
    $contexts[ERPAL_CONTEXT_DOC] = true;  
  }
  
  //do we have an edit form?
  if ($path == 'node/%/edit') {
    if ($node->type == 'erpal_file') {
      $contexts[ERPAL_CONTEXT_DOC_GLOBAL] = true;
    }
  }
     
  if (drupal_match_path($path, 'node/%*') ) {    
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/bla or something like this  
    switch ($node->type) {
      case 'erpal_file':  
        $contexts[ERPAL_CONTEXT_DOC] = true; 
        $contexts[ERPAL_CONTEXT_DOC_GLOBAL] = true;         
        break;       
    }
  }
  
  //CHECK Doc Global CONTEXT
  if (drupal_match_path($path, 'documents/*') || drupal_match_path($path, 'documents')) {  
    $contexts[ERPAL_CONTEXT_DOC_GLOBAL] = true;      
  }  

  if (drupal_match_path($path, 'documents')) {  
    $contexts[ERPAL_CONTEXT_DOCS] = true;      
  }    

  return $contexts;  

}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_docs_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
  $node = _erpal_basic_helper_router_object(1, $router_item);
  $is_node_view = !isset($router_item['original_map'][2]) || $router_item['original_map'][2] == 'view'; 

  //Contracts contact context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_DOCS, $router_item)) {    
    _erpal_docs_helper_contacts_links($data);          
    _erpal_docs_helper_docs_global_menu_tabs($data, $node, array('documents'));   
  } 
  
  //CRM contacts context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_DOC, $router_item)) {    
    _erpal_docs_helper_doc_links($data, $node, $is_node_view); 
    _erpal_docs_helper_docs_global_menu_tabs($data, $node, array('documents'));   
  }
 
  //just global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_DOC_GLOBAL, $router_item)) {    
    _erpal_docs_helper_docs_global_menu_tabs($data, $node, array('documents'));   
  }
}

/**
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_docs_helper_erpal_menu_parents($router_item) {
  return _erpal_docs_helper_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_docs_helper_get_menu_parents($router_item) {
  $docs_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_DOC_GLOBAL, $router_item);

  if ($docs_global) {
    return 'documents';
  }
}

/**
* Adds all doc context links
*/
function _erpal_docs_helper_contacts_links(&$data) {
  //docs list context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new document'), 'node/add/erpal-file', $query);
}


/**
* Adds all doc context links
*/
function _erpal_docs_helper_doc_links(&$data, $doc_node, $is_node_view=false) {
  //single doc context
  if ($is_node_view) {
    $query = array();
    erpal_make_action($data, t('Edit this document'), 'node/'.$doc_node->nid.'/edit', $query);    
  }
}


/**
* Show all menu tab links for doc context
*/
function _erpal_docs_helper_docs_global_menu_tabs(&$data, $current_nid=false, $active_tabs=array()) {

  static $processed = false;
  
  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  //thi will only be shown if we add another tab here!
  erpal_make_local_tab($data, t('Documents'), 'documents', array(), in_array('documents', $active_tabs));

} 