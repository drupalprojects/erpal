<?php

/**
 * @file functions uses for the invoice ressource
 */
function _erpal_invoice_service_invoice_create($invoice) {
  $value = $invoice['invoice'];


  //collect the data and put it into an array
  $returns = array();
  global $user;

  $value = $invoice['invoice'];

  //if we don't have title, take the first 65 chars from body
  $contractor_nid = isset($value['contractor_nid']) ? $value['contractor_nid'] : false;
  $customer_nid = isset($value['customer_nid']) ? $value['customer_nid'] : false;
  $invoice_number = isset($value['invoice_number']) ? $value['invoice_number'] : false;
  $invoice_date = isset($value['invoice_date']) ? $value['invoice_date'] : false;
  $currency = isset($value['currency']) ? $value['currency'] : false;
  $paid = isset($value['paid']) ? $value['paid'] : false;
  $billables = isset($value['billables']) ? $value['billables'] : array();

  //@TODO test if this can be preset or is also overridden by customer defaults
  $invoice_address_id = isset($value['invoice_address_id']) ? $value['invoice_address_id'] : false;
  $shipping_address_id = isset($value['shipping_address_id']) ? $value['shipping_address_id'] : false;

  //@TODO support following presets. Actually they are overridden by customer defaults, 
  //@see _erpal_invoice_helper_set_invoice_form_defaults
  //$credit_period = isset($value['credit_period']) ? $value['credit_period'] : false;
  //$skonto_period = isset($value['skonto_period']) ? $value['skonto_period'] : false;
  //$skonto_percent = isset($value['skonto_percent']) ? $value['skonto_percent'] : false;
  $additional_notes = isset($value['additional_notes']) ? $value['additional_notes'] : false;

  $invoice_node_arr = array('type' => 'erpal_invoice');
  $invoice_node = (object) $invoice_node_arr;


  $form_id = 'erpal_invoice_node_form';
  $form_values = array(
    'language' => LANGUAGE_NONE,
    'name' => $user->name,
    'status' => 1,
    'type' => 'erpal_invoice',
    'promote' => 0,
    'sticky' => 0,
  );

  //now add all the fields if they are set
  if ($contractor_nid)
    $form_values['field_contractor_ref'] = array(LANGUAGE_NONE => array(0 => array('target_id' => _erpal_basic_helper_autocomplete_string_from_nid($contractor_nid))));
  if ($customer_nid)
    $form_values['field_customer_ref'] = array(LANGUAGE_NONE => array(0 => array('target_id' => _erpal_basic_helper_autocomplete_string_from_nid($customer_nid))));
  if ($invoice_address_id)
    $form_values['field_invoice_address_id'] = array(LANGUAGE_NONE => array(0 => $invoice_address_id));
  if ($shipping_address_id)
    $form_values['field_shipping_address_id'] = array(LANGUAGE_NONE => array(0 => $shipping_address_id));
  if ($invoice_number)
    $form_values['field_invoice_number'] = array(LANGUAGE_NONE => array(0 => array('value' => $invoice_number)));
  if ($invoice_date) {
    $form_values['field_invoice_date'][LANGUAGE_NONE]['value'] = $invoice_date ? date('d.m.Y', $invoice_date) : date('d.m.Y');
  }
  if ($credit_period)
    $form_values['field_credit_period'][LANGUAGE_NONE]['value'] = $credit_period;
  if ($paid)
    $form_values['field_payed'][LANGUAGE_NONE]['value'] = $paid;
  if ($currency)
    $form_values['field_currency'][LANGUAGE_NONE]['value'] = $currency;

  //Now handle field collection values for skonto!
  //$form['field_skonto'][LANGUAGE_NONE][0]['field_credit_period'][LANGUAGE_NONE][0]['value']['#default_value'] = $default_skonto_period; 
  //$form['field_skonto'][LANGUAGE_NONE][0]['field_discount_percent'][LANGUAGE_NONE][0]['value']['#default_value'] = $default_skonto_rate; 
  /*
    if ($skonto_period)
    $form_values['field_payed'][LANGUAGE_NONE]['value'] = $skonto_period;
    if ($skonto_percent)
    $form_values['field_payed'][LANGUAGE_NONE]['value'] = $skonto_percent;
   */

  //now add all billables. Create billables first and then only reference the billables ID
  foreach ($billables as $delta => $billable_arr) {

    $target_id_arr = array();
    $target_id_arr['subject'] = $billable_arr['subject'];
    $target_id_arr['date_delivery'] = $billable_arr['date_delivery'];
    $target_id_arr['quantity'] = $billable_arr['quantity'];
    $target_id_arr['single_price'] = $billable_arr['single_price'];
    $target_id_arr['currency'] = $billable_arr['currency'] ? $billable_arr['currency'] : $currency;
    $target_id_arr['field_service_category_term'][LANGUAGE_NONE] = $billable_arr['service_category'];

    if ($billable_arr['tax_type'] == 'vat')
      $target_id_arr['vat_rate'] = $billable_arr['tax_rate']; //@TODO: handle different tax rates, only VAT is supported yet!

    $form_values['field_billables_ref'][LANGUAGE_NONE][$delta]['target_id'] = $target_id_arr;
  }

  //now add the item count
  $form_state = array();
  if (count($billables)) {
    $form_state['field']['field_billables_ref'][LANGUAGE_NONE]['items_count'] = count($billables);
  }

  //@TODO: add some additional nodes
  if ($additional_notes)
    $form_values['field_note'][LANGUAGE_NONE][0]['value'] = $additional_notes;


  //now execute the form to create the invoice
  module_load_include('inc', 'node', 'node.pages');
  $form_values['op'] = t('Save');  // this seems to be a required value
  $form_state['values'] = $form_values;

  drupal_form_submit($form_id, $form_state, (object) $invoice_node);

  $invoice_node = $form_state['node'];

  $errors = form_get_errors();
  return _erpal_invoice_service_create_service_response($errors, $invoice_node);
}

/**
 * Check access for creating a invoice node
 */
function _erpal_invoice_service_invoice_create_access($op, $args) {
  return node_access($op, 'erpal_invoice');
}

/**
 * Creates an array as the response of a webservice request
 */
function _erpal_invoice_service_create_service_response($errors, $invoice_node) {
  if (!empty($errors)) {
    $returns['error'] = TRUE;
    $returns['node'] = false;
    foreach ($errors as $key => $value) {
      $error_string .= $key . ": " . $value . "<br/>";
    }
    $returns['message'] = 'Invoice could not be created because of some errors: <br/>' . $error_string;
  }
  else {
    $returns['node'] = (array) $invoice_node;
    $returns['error'] = false;
    $returns['message'] = '';
  }

  return $returns;
}