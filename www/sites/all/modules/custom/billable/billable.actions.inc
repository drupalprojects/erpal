<?php

/**
* Callback for the action billable_reduce_action to reduce billables
* NO grouping by singfle price
*/
function billable_reduce_action(&$billables, $context) {

  module_load_include('inc', 'billable', 'billable.reduce'); 
  $billable_ids = array_keys($billables);
  _billable_reduce($billable_ids);
  
}

/**
* Callback for the action billable_reduce_by_single_price_action to reduce billables
* NO grouping by singfle price
*/
function billable_reduce_by_single_price_action(&$billables, $context) {
  
  module_load_include('inc', 'billable', 'billable.reduce'); 
  $billable_ids = array_keys($billables);
  $group_by = array('single_price');
  _billable_reduce($billable_ids, $group_by);
  
}