<?php

/**
* Callback for the action erpal_invoice_helper_invoice_from_billables_action create an invoice by billables
* invoice is created without reduced billables!!
*/
function erpal_invoice_helper_invoice_from_billables_action(&$billables, $context) {

  module_load_include('inc', 'erpal_invoice_helper', 'inc/invoice.calc'); 
  $billable_ids = array_keys($billables);
  _erpal_invoice_helper_invoice_from_billables($billable_ids);
  
}

/**
* Callback for the action erpal_invoice_helper_invoice_from_billables_reduced_action create an invoice by billables
* billables are reduced!!
*/
function erpal_invoice_helper_invoice_from_billables_reduced_action(&$billables, $context) {

  module_load_include('inc', 'erpal_invoice_helper', 'inc/invoice.calc'); 
  $billable_ids = array_keys($billables);
  _erpal_invoice_helper_invoice_from_billables($billable_ids, true);
  
}