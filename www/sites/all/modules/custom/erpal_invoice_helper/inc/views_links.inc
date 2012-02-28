<?php


/**
* This function is called by the view billables. Links for creating some billables are added. 
* With the hook other modules could add some more links.
*/
function _erpal_invoice_helper_view_billables_header_content() {
  
  $add_erpal_billable = _erpal_invoice_helper_create_billable_link();
  
  $my_content = array(
    $add_erpal_billable,
  );
  
  //ask all other modules for content in the header area of the view
  $other_module_content = module_invoke_all('view_billables_header_content');
  
  $all_content = array_merge($other_module_content, $my_content);
  
  $content = '';
  foreach ($all_content as $a_content) {
    $content .= '<br>'.$a_content;
  }
  
  return $content;
}

/**
* Helper function to create new contact link
*/
function _erpal_invoice_helper_create_billable_link($q_arg = false, $query_arr = array(), $title=false){
  if (!$q_arg)
    $q = current_path();
  else 
    $q = $q_arg;
  
  if (!isset($query_arr['destination']) || $q_arg)
    $query_arr['destination'] = $q;
  
  if (!$title)
    $title = t("Create new billable");
    
  return l(
    $title, "billable/add", array(
        'query' => $query_arr,
    )
  );
}

/**
* This function is called by the view invoices. Links for creating some invoce are added. 
* With the hook other modules could add some more links.
*/
function _erpal_invoice_helper_view_invoices_header_content() {
  
  $add_erpal_invoice = _erpal_invoice_helper_create_invoice_link();
  
  $my_content = array(
    $add_erpal_invoice,
  );
  
  //ask all other modules for content in the header area of the view
  $other_module_content = module_invoke_all('view_invoice_header_content');
  
  $all_content = array_merge($other_module_content, $my_content);
  
  $content = '';
  foreach ($all_content as $a_content) {
    $content .= '<br>'.$a_content;
  }
  
  return $content;
}

/**
* Helper function to create new contact link
*/
function _erpal_invoice_helper_create_invoice_link($q_arg = false, $query_arr = array(), $title=false){
  if (!$q_arg)
    $q = current_path();
  else 
    $q = $q_arg;
  
  if (!isset($query_arr['destination']) || $q_arg)
    $query_arr['destination'] = $q;
  
  if (!$title)
    $title = t("Create new invoice");
    
  return l(
    $title, "node/add/erpal-invoice", array(
        'query' => $query_arr,
    )
  );
}
