<?php

/**
* #######################################################################
* FUNCTIONS FOR Bulk Operation to CREATE an INVOICE
* #######################################################################
*/


/**
* Callback for configurable bulk operation for creating an invoice
*/
function erpal_invoice_helper_invoice_from_billables_action_form($context) {
  $form = array();
  
  $form['reduce_billables'] = array(
    '#type' => 'radios',
    '#title' => 'Group billables',
    '#options' => array(
      'minimal' => t('Group billables by customer, vat rate and currency'),
      'single_price' => t('Group by single price (for work payed by time e.g.)'),
      'none' => t('No grouping'),
    ),
    '#required' => true,
    '#default_value' => 'minimal',
    '#description' => t('All billables will be grouped according to grouping fields as one billable'),
  );

  //get the Customer and the addresses, credit period, ADDITIONAL note
  $billable_ids = $context['selection'];
  $customer_id_arr = _erpal_invoice_helper_get_billable_customers($billable_ids);

  //if user has more than one customers select redirect back, actually creating more than once invoice is not supported
  if (count($customer_id_arr) > 1) {
    drupal_set_message(t('Sorry, please select only billables with a unique customer using the view filter "Customer"'), 'error');
    drupal_goto($_GET['q']);
  }
  
  //if there is no customer, we cannot create an invoice...
  if (count($customer_id_arr) <= 0) {
    drupal_set_message(t('Sorry, but we cannot determine a cusotmer for your invoice. Please ensure that all billables have a customer set.'), 'error');
    drupal_goto($_GET['q']);
  }
  
  //now get invoce address etc of customer, we are sure, we only have one customer here, but we prepare for the future already
  foreach ($customer_id_arr as $customer_id) {
    $customer_node = node_load($customer_id);
    $customer_defaults_form = _erpal_invoice_helper_customer_defaults_form($customer_node);
  }
  
  $form = array_merge($form, $customer_defaults_form);
  
  return $form;
}

/**
* Validation handler of bulk operation configuration form for creating an invoice
*/
function erpal_invoice_helper_invoice_from_billables_action_validate($form, &$form_state) {
  //@todo ?
  
}

/**
* Submit handler for bulk operation configuration form for creating an invoice
*/
function erpal_invoice_helper_invoice_from_billables_action_submit($form, &$form_state) {
  //return other context option (the values that have been submitted) to have them in our action callback
  $values = $form_state['values'];
  
  //save default invoice values für this customer!
  $defaults = array(
    'address_id' => $values['address_id'],
    'credit_period' => $values['credit_period'],
    'notes' => $values['notes'],
  );
  $customer_nid = $values['customer_nid'];
  
  if ($values['save_defaults'])
    _erpal_invoice_helper_set_customer_defaults($customer_nid, $defaults);
  
  return $values;
}


/**
* Callback for the action erpal_invoice_helper_invoice_from_billables_action create an invoice by billables
* invoice is created without reduced billables!!
*/
function erpal_invoice_helper_invoice_from_billables_action(&$billables, $context) {
  module_load_include('inc', 'erpal_invoice_helper', 'inc/invoice.calc'); 
  $billable_ids = array_keys($billables);
  $reduce_options = $context['reduce_billables'];
  $reduce = $reduce_options['minimal'] || $reduce_options['single_price'];
  $group_by_single_price = $reduce_options['single_price'];

  if ($group_by_single_price)
    $params['group_by'] = array('single_price');

 _erpal_invoice_helper_invoice_from_billables($billable_ids, $reduce, $params);  
}

/**
* returns a form with defaults of a customer if available
*/
function _erpal_invoice_helper_customer_defaults_form($customer_node) {
  $allowed_addresses = _erpal_basic_helper_get_contact_adresses($customer_node, true);
  $allowed_credit_periods = _erpal_invoice_helper_get_credit_periods_arr();
  
  $form = array();
  
  $defaults = _erpal_invoice_helper_get_customer_defaults($customer_node->nid);
  $default_address = $defaults['address_id'];
  $default_credit_period = $defaults['credit_period'];
  $default_notes = $defaults['notes'];
 
  $form['customer_title'] = array(
    '#type' => 'item',
    '#title' => t('Customer'),
    '#markup' => l($customer_node->title, "node/".$customer_node->nid),
  );
  
  $form['customer_nid'] = array(
    '#type' => 'value',
    '#value' => $customer_node->nid,
  );
  
  $form['address_id'] = array(
    '#type' => 'select',
    '#title' => t('Address'),
    '#options' => $allowed_addresses,
    '#default_value' => $default_address,
    '#required' => true,
  );
  
  $form['credit_period'] = array(
    '#type' => 'select',
    '#title' => t('Credit period'),
    '#options' => $allowed_credit_periods,
    '#default_value' => $default_credit_period,
    '#required' => true,
  );

  $form['notes'] = array(
    '#type' => 'textarea',
    '#title' => t('Notes'),
    '#default_value' => $default_notes,
  );
  
  //@TODO preview billables (non reduced with hint that they will b reduced) and princing (total, netto, vat rates)
  
  $form['save_defaults'] = array(
    '#type' => 'checkbox',
    '#title' => t('Save settings as default for this customer'),
    '#default_value' => true,
  );
  
  return $form;
}

/**
* Saves invoice parameters as invoice defaults
* @param $defaults an array with keys: address_id, credit_period, notes
*/
function _erpal_invoice_helper_set_customer_defaults($customer_nid, $defaults) {
  //first delete all defaults for the customer
  db_delete('erpal_invoice_defaults')
  ->condition('customer_nid', $customer_nid)
  ->execute();
  
  //now insert new default values
  db_insert('erpal_invoice_defaults')
  ->fields(array(
    'customer_nid' => $customer_nid,
    'address_id' => $defaults['address_id'],
    'credit_period' => $defaults['credit_period'],
    'notes' => $defaults['notes'],
  ))
  ->execute();
}

/**
* Returns the default values for a customer
* @param $customer_nid the nid of the node we want to have the defaults for
* @return an array withy keys: address_id, credit_period, notes
*/
function _erpal_invoice_helper_get_customer_defaults($customer_nid) {
  
  $defaults = array(
    'address_id' => 0,
    'credit_period' => 14,
    'notes' => _erpal_invoice_helper_get_manuall_notes(),
  );

  //Start a query over the erpal_invoice_defaults table
  $query = db_select('erpal_invoice_defaults', 'd');
  // Select rows that match the string within type erpal_contact
  $return = $query
    ->fields('d', array('customer_nid', 'address_id', 'credit_period', 'notes'))
    ->condition('d.customer_nid', $customer_nid, '=')
    ->execute();
  
  // add matches to $matches  
  foreach ($return as $row) {
    return (array)$row; //we have only one default, so return it!
  }
  
  return $defaults;
}