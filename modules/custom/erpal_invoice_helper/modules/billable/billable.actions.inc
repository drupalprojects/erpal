<?php

/**
* Callback for the action billable_reduce_action to reduce billables
* NO grouping by singfle price
*/
function billable_reduce_action(&$billables, $context) {

  module_load_include('inc', 'billable', 'billable.reduce'); 
  $billable_ids = array_keys($billables);
  _billable_reduce($billable_ids);
  
  if (isset($context['single_price']) && $context['single_price']) {
    $group_by = array('single_price');
    _billable_reduce($billable_ids, $group_by);
  }
  
}

/**
* Action to set a billable billed
*/
function billable_billed_action(&$billables, $context) {
  foreach ($billables as $billable) {
    $billable->set_billed(true);
    $billable->save();
  }
}

/**
* Action to set a billable unbilled
*/
function billable_unbilled_action(&$billables, $context) {
  foreach ($billables as $billable) {
    $billable->set_billed(false);
    $billable->save();
  }
}

/**
* Callback for action delete billables
*/
function billable_delete_action(&$billables, $context) {
  $billable_ids = array_keys($billables);
  billable_delete_multiple($billable_ids);
}

/**
*  Form to configure the billable reduce action
*/
function billable_reduce_action_form($context) {

  $form = array();
  
  $form['single_price'] = array(
    '#type' => 'checkbox',
    '#title' => t('Group by single price'),
    '#default_value' => false,
    '#description' => t('Billables will be grouped by customer, vat rates, currency and with this option, by single price. This is usefull for payed work by time tracking to reduce the amount of invoice line items'),
  );
  
  return $form;
}

/**
* Submithandler of reduce action config form
*/
function billable_reduce_action_submit($form, $form_state) {
  $values = $form_state['values'];

  return $values;
}
