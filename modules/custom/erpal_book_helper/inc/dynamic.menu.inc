<?php

/**
* @file provide functions for dynamic menu items in CRM context
*/
//define some contexts
define('ERPAL_CONTEXT_BOOKS', 'books'); //books list
define('ERPAL_CONTEXT_BOOK_TEMPLATES', 'book_templates');
define('ERPAL_CONTEXT_BOOK_GLOBAL', 'book_global');
define('ERPAL_CONTEXT_BOOK', 'book');
define('ERPAL_CONTEXT_BOOK_PAGE', 'book_page');

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_book_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  
  $contexts = array();

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  //do we have node add form
  if (drupal_match_path($path, 'node/add/erpal-book*')) { 
    $contexts[ERPAL_CONTEXT_BOOK_GLOBAL] = true;
    $contexts[ERPAL_CONTEXT_BOOK] = true;  
  } elseif (drupal_match_path($path, 'node/add/erpal-book-page*')) {  
    $contexts[ERPAL_CONTEXT_BOOK_GLOBAL] = true;
    $contexts[ERPAL_CONTEXT_BOOK_PAGE] = true; 
  }
  
  //do we have an edit form?
  if ($path == 'node/%/edit') {
    if ($node->type == 'erpal_book') {
      $contexts[ERPAL_CONTEXT_BOOK_GLOBAL] = true;
    } elseif ($node->type == 'erpal_book_page') { 
      $contexts[ERPAL_CONTEXT_BOOK_GLOBAL] = true;
    }
  }
     
  //CHECK CRM Global CONTEXT
  if (drupal_match_path($path, 'books/*') || drupal_match_path($path, 'books')) {  
    $contexts[ERPAL_CONTEXT_BOOK_GLOBAL] = true;      
  }   
     
  //CHECK books list CONTEXT
  if ($path == 'books/%') {
    $sub_page = isset($router_item['original_map'][1]) ? $router_item['original_map'][1] : false;
    if ($sub_page == 'books')
      $contexts[ERPAL_CONTEXT_BOOKS] = true;
    elseif ($sub_page == 'templates')
      $contexts[ERPAL_CONTEXT_BOOK_TEMPLATES] = true;
  }   
     
  if (drupal_match_path($path, 'node/%*') || drupal_match_path($path, 'books/*')) {    
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/invoices or something like this
   
    switch ($node->type) {
      case 'erpal_book':          
        $contexts[ERPAL_CONTEXT_BOOK] = true; 
        $contexts[ERPAL_CONTEXT_BOOK_GLOBAL] = true;        
        break;
      case 'erpal_book_page':        
        $contexts[ERPAL_CONTEXT_BOOK_PAGE] = true;
        $contexts[ERPAL_CONTEXT_BOOK_GLOBAL] = true;        
        break;        
    }
       
  }
  
  return $contexts;  

}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_book_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  $active_tab = array();
  $nid = false;
  if ($node && is_object($node) && isset($node->nid)) {
    $nid = $node->nid;
  }
  $is_node_view = !isset($router_item['original_map'][2]) || (isset($router_item['original_map'][2]) && $router_item['original_map'][2] == 'view');   
  
  //books list context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_BOOKS, $router_item)) {        
    _erpal_book_helper_books_links($data, $node);       
  }
  
  //templates context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_BOOK_TEMPLATES, $router_item)) {    
    _erpal_book_helper_book_templates_links($data);       
  } 
  
  //Book context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_BOOK, $router_item)) {    
    _erpal_book_helper_node_book_links($data, $node, $is_node_view); 
    $active_tab = isset($node->field_is_template[LANGUAGE_NONE][0]) && $node->field_is_template[LANGUAGE_NONE][0]['value'] ? 'templates' : 'books';
    _erpal_book_helper_book_global_menu_tabs($data, $nid, array($active_tab));   
  }
  
  //Book Page Context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_BOOK_PAGE, $router_item)) {  
    _erpal_book_helper_node_book_page_links($data, $node, $is_node_view); 
    $active_tab = isset($node->field_is_template[LANGUAGE_NONE][0]) && $node->field_is_template[LANGUAGE_NONE][0]['value'] ? 'templates' : 'books';
    _erpal_book_helper_book_global_menu_tabs($data, $nid, array($active_tab));   
  }
 
  //now on global context ensure that all links are shown
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_BOOK_GLOBAL, $router_item)) {   
    if (!$node) {
      $nid = isset($router_item['original_map'][2]) ? $router_item['original_map'][2] : false;
      if (!$nid) {
        $templates = isset($router_item['original_map'][1]) && $router_item['original_map'][1] == 'templates' ? true : false;
        if ($templates) 
          $active_tab = 'templates';
        else
          $active_tab = 'books';
        
      } else {
        $a_node = node_load($nid);
        $active_tab = isset($a_node->field_is_template[LANGUAGE_NONE][0]) && $a_node->field_is_template[LANGUAGE_NONE][0]['value'] ? 'templates' : 'books';
      }
    }
    _erpal_book_helper_book_global_menu_tabs($data, $nid, array($active_tab));   
  }
}

/**
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_book_helper_erpal_menu_parents($router_item) {
  return _erpal_book_helper_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_book_helper_get_menu_parents($router_item) {
  $crm_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_BOOK_GLOBAL, $router_item);
  
  if ($crm_global) {
    return 'books/books';
  }
}

/**
* Adds all activities context links
*/
function _erpal_book_helper_books_links(&$data) {
  //book list context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new book'), 'node/add/erpal-book', $query);
  _erpal_book_helper_book_global_menu_tabs($data, false, array('books'));  
}


/**
* Adds all activities context links
*/
function _erpal_book_helper_book_templates_links(&$data) {
  //book template list context
  $query = array('destination' => $_GET['q'], 'field_is_template' => 1);
  erpal_make_action($data, t('Create a new template'), 'node/add/erpal-book', $query);
  _erpal_book_helper_book_global_menu_tabs($data, false, array('templates'));  
}

/**
* Adds all activity contact links
*/
function _erpal_book_helper_node_book_links(&$data, $node, $is_node_view=false) {
  //single book context
  if ($is_node_view) {
    $query = array();
    erpal_make_action($data, t('Edit this book'), 'node/'.$node->nid.'/edit', $query);

    _erpal_book_helper_book_and_page_actions($data, $node, $is_node_view);
  }
  
}

/**
* Add actions to a book or a book page
*/
function _erpal_book_helper_book_and_page_actions(&$data, $node, $is_node_view=false) {
  $query = array('field_parent' => $node->nid);
  erpal_make_action($data, t('Add a book page'), 'node/add/erpal-book-page', $query);
  
  $query = array();
  erpal_make_action($data, t('Create PDF'), 'books/'.$node->nid.'/pdf', $query);
  erpal_make_action($data, t('Add pages cloned'), 'books/clonetemplates/'.$node->nid, $query);
  
  if ($node->type == 'erpal_book') {
    erpal_make_action($data, t('Clone to new book'), 'books/'.$node->nid.'/clone', $query);
  }
}

/**
* Adds all contact context links
*/
function _erpal_book_helper_node_book_page_links(&$data, $node, $is_node_view=false) {
  //single book page context
  if ($is_node_view) {
    $query = array();
    erpal_make_action($data, t('Edit this book page'), 'node/'.$node->nid.'/edit', $query);
    
    _erpal_book_helper_book_and_page_actions($data, $node, $is_node_view);
    
  }
}



/**
* Show all menu tab links for crm context
*/
function _erpal_book_helper_book_global_menu_tabs(&$data, $current_nid=false, $active_tabs=array()) {

  static $processed = false;

  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  erpal_make_local_tab($data, t('Books'), 'books/books', array(), in_array('books', $active_tabs)); 
  erpal_make_local_tab($data, t('Templates'), 'books/templates', array(), in_array('templates', $active_tabs)); 
} 