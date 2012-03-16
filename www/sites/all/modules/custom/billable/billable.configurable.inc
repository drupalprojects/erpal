<?php

//@file all functions which data should be configurable over an admin form

/**
* Return all customers that can be refernces to a billable
*/
function _billable_get_customers() {
  //@TODO get customers from user selection view (or node type)
  $customers = array();

  $query = db_select('node', 'n');
  $query
    ->fields('n', array('nid', 'title'))
    ->condition('n.type', 'erpal_contact')
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
