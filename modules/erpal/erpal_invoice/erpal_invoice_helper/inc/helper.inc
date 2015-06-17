<?php

/**
* Runtime cache for saving values during script processing
*/
function _erpal_invoice_helper_cache($key, $value=false) {
  static $cache = array();

  $ret = false;
  if (isset($cache[$key]))
    $ret = $cache[$key];
    
  if ($value)
    $cache[$key] = $value;
    
  return $ret;
}

/**
* Returns all customer nids to a given amount of billable ids
* @param array $billable_id_arr array of billable ids where we want to retrieve customers form
*/
function _erpal_invoice_helper_get_billable_customers($billable_id_arr) {
  if (count($billable_id_arr) <= 0)
    return array();
  
  $result = db_select('billable', 'b')
    ->fields('b', array('customer_nid'))
    ->condition('billable_id', $billable_id_arr,'IN')
    ->execute();

  $customers = array();
  while($record = $result->fetchAssoc()) {
      $customers[$record['customer_nid']] = $record['customer_nid'];
  }
  
  return $customers;
}

/**
* Returns all contractor nids to a given amount of billable ids
*/
function _erpal_invoice_helper_get_billable_contractors($billable_id_arr) {
  if (count($billable_id_arr) <= 0)
    return array();
  
  $result = db_select('billable', 'b')
    ->fields('b', array('contractor_nid'))
    ->condition('billable_id', $billable_id_arr,'IN')
    ->execute();

  $contractors = array();
  while($record = $result->fetchAssoc()) {
      $contractors[$record['contractor_nid']] = $record['contractor_nid'];
  }
  
  return $contractors;
}