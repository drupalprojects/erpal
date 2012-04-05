<?php

//@file all functions which data should be configurable over an admin form

/**
* Return all customers that can be refernces to a billable
*/
function _billable_get_customers() {
  $customers = array();

  $type = _billable_customer_type();
  $query = db_select('node', 'n');
  $query
    ->fields('n', array('nid', 'title'))
    ->condition('n.type', $type)
    ->condition('n.status', '1')
    ->orderBy('n.title', 'DESC')
    ->addTag('node_access');
  
  $result = $query->execute();
  
  foreach ($result as $record) {
    // Do something with each $record
    $customers[$record->nid] = $record->title;
  }
  
  return $customers;
}

/**
* Returns the current selected node type for customers
*/
function _billable_customer_type() {
  return variable_get('billable_customer_type', false);
}