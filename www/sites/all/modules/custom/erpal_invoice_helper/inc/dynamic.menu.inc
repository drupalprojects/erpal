<?php

/**
* @file provide functions for dynamic menu items in invoice context
*/
//define some contexts
define('ERPAL_CONTEXT_INVOICES', 'invices'); //invoices list
define('ERPAL_CONTEXT_INVOICE_GLOBAL', 'invoice_global'); //we are in activies view or in a tab that belongs to the activities
define('ERPAL_CONTEXT_INVOICE', 'invoice');
define('ERPAL_CONTEXT_BILLABLES', 'billables');

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_invoice_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();
  
  //CHECK invoice CONTEXT
  if (drupal_match_path($path, 'node/%*') ) {
    $node = isset($router_item['map'][1]) ? $router_item['map'][1] : false;
    
    if (!$node || !is_object($node))
      return $contexts;
    
    //may be we have a ctools context
    
    if (get_class($node) == 'ctools_context')
      $node = $node->data;    
    
    switch ($node->type) {
      case 'erpal_invoice':
        $contexts[ERPAL_CONTEXT_INVOICE] = true;              
        break;    
    }
  }

  //CHECK INVOICE Global CONTEXT
  if (drupal_match_path($path, 'invoice/invoices') || drupal_match_path($path, 'invoice/billables')) {        
    $contexts[ERPAL_CONTEXT_INVOICE_GLOBAL] = true;      
  }
  
  
  //CHECK INVOICES list CONTEXT
  if ($path == 'invoice/invoices') {        
    $contexts[ERPAL_CONTEXT_INVOICES] = true;       
  }
  
  //CHECK BILLABLES list CONTEXT
  if ($path == 'invoice/billables') {        
    $contexts[ERPAL_CONTEXT_BILLABLES] = true;          
  }

  return $contexts;  
}

/**
* Implements hook_dynamic_menu_items_alter provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_invoice_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {
  //invoices list context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_INVOICES, $router_item)) {        
    _erpal_invoice_helper_invoices_links($data);       
  }
  
  //INVOICE global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_INVOICE_GLOBAL, $router_item)) {    
    _erpal_invoice_helper_invoice_global_links($data, $router_item);       
  } 
  
  //billables context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_BILLABLES, $router_item)) {    
    _erpal_invoice_helper_billables_links($data, $router_item);       
  } 
  
  //INVOICE context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_INVOICE, $router_item)) {    
    $invoice_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_invoice_helper_invoice_links($data, $router_item, $invoice_node);       
  }
}

/**
* Adds all invoice global context links
*/
function _erpal_invoice_helper_invoice_global_links(&$data, $router_item) {
  //single project context
  
  //hide the links if we are in a contact o
  erpal_make_local_tab($data, t('Invoices'), 'invoice/invoices');
  erpal_make_local_tab($data, t('Billables'), 'invoice/billables');
}

/**
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_invoice_helper_erpal_menu_parents($router_item) {
  return _erpal_invoice_helper_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_invoice_helper_get_menu_parents($router_item) {
  $invoice_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_INVOICE_GLOBAL, $router_item);
  
  if ($invoice_global) {
    return 'invoice/invoices';
  }
}

/**
* Adds all invoices context links
*/
function _erpal_invoice_helper_invoices_links(&$data, $contact_node=false) {
  //single project context
  $query = array('destination' => $_GET['q']);
  
  if ($contact_node) {
    $query['field_customer_ref'] = $contact_node->nid;
  }
  
  erpal_make_action($data, t('Create a new invoice'), 'node/add/erpal-invoice', $query);
}

/**
* Adds all billables context links
*/
function _erpal_invoice_helper_billables_links(&$data, $contact_node=false) {
  //single project context
  $query = array('destination' => $_GET['q']);
  
  erpal_make_action($data, t('Create a new billable'), 'billable/add', $query);
}

/**
* Adds all invoice context links
*/
function _erpal_invoice_helper_invoice_links(&$data, $router_item, $contact_node) {
  //single project context
  $query = array();
  erpal_make_action($data, t('Edit this invoice'), 'node/'.$contact_node->nid.'/edit', $query);
  
  erpal_make_local_tab($data, t('Invoices'), 'invoice/invoices');
  erpal_make_local_tab($data, t('Billables'), 'invoice/billables');
}
