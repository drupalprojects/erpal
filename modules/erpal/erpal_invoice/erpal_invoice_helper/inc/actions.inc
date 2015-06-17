<?php

/**
* #######################################################################
* FUNCTIONS FOR Bulk Operation to CREATE an INVOICE
* #######################################################################
*/


/**
* Callback for configurable bulk operation for creating an invoice
*/
function erpal_invoice_helper_invoice_from_billables_action_form($context, $form_state) {
 
  //get the Customer and the addresses, credit period, ADDITIONAL note
  
  $billable_ids = $form_state['selection'];
  $customer_id_arr = _erpal_invoice_helper_get_billable_customers($billable_ids);

  $contractor_id_arr = _erpal_invoice_helper_get_billable_contractors($billable_ids);

  //if user has more than one customers select redirect back, actually creating more than once invoice is not supported
  if (count($customer_id_arr) > 1) {
    drupal_set_message(t('Sorry, please select only billables with a unique customer using the view filter "Customer"'), 'error');
    drupal_goto($_GET['q']);
  }
  
  //if user has more than one contractor select redirect back, actually creating more than once invoice is not supported
  if (count($contractor_id_arr) > 1) {
    drupal_set_message(t('Sorry, please select only billables with a unique contractor using the view filter "Contractor"'), 'error');
    drupal_goto($_GET['q']);
  }
  
  //if there is no customer, we cannot create an invoice...
  if (count($customer_id_arr) <= 0) {
    drupal_set_message(t('Sorry, but we cannot determine a customer for your invoice. Please ensure that all billables have a customer set.'), 'error');
    drupal_goto($_GET['q']);
  }
  
  //get the contractor node
  $contractor_id_arr = array_values($contractor_id_arr);
  $contractor_nid = $contractor_id_arr[0];
  $contractor_node = node_load($contractor_nid);
  
  //if the contractor is the own company, we group by service_category, otherwise by expense_category
  $form = array();
  
  $own_company_nid = _erpal_basic_helper_get_own_company_nid(false);
  if ($contractor_node->nid == $own_company_nid) {
    $options = array(    
      'service_category' => t('Group billables by service category'),
      'none' => t('No grouping'),
    );
    $default_value = 'service_category';
  } else {
    $options = array(    
      'expense_category' => t('Group billables by expense category'),
      'none' => t('No grouping'),
    );
    $default_value = 'expense_category';
  }
  
  $form['reduce_billables'] = array(
    '#type' => 'radios',
    '#title' => 'Group billables',
    '#options' => $options,
    '#required' => true,
    '#default_value' => $default_value,
    '#description' => t('Group billables in order not to have for example all timetrackings as invoice line items. Tey will be grouped'),
  );
  
  $form['contractor_title'] = array(
    '#type' => 'item',
    '#title' => t('Contractor'),
    '#markup' => l($contractor_node->title, "node/".$contractor_node->nid),
  );
  
  $form['contractor_nid'] = array(
    '#type' => 'value',
    '#value' => $contractor_node->nid,
  );
  
  //now get invoce address etc of customer, we are sure, we only have one customer here, but we prepare for the future already and loop through the customer array @TODO: merge forms
  foreach ($customer_id_arr as $customer_id) {
    $customer_node = node_load($customer_id);
    $customer_defaults_form = _erpal_invoice_helper_customer_defaults_form($customer_node, $contractor_node);
  }
  
  $form = array_merge($form, $customer_defaults_form);
  
  return $form;
}

/**
* Validation handler of bulk operation configuration form for creating an invoice
*/
function erpal_invoice_helper_invoice_from_billables_action_validate($form, &$form_state) {
  
  $values = $form_state['values'];
  //skoto: if skonto_period is set, skonto_percent must be set, too. Both values must be numeric
  $skonto_period = 0;
  $skonto_percent = 0;
  if (isset($values['skonto_period']))
    $skonto_period = $values['skonto_period'];
  if (isset($values['skonto_percent']))
    $skonto_percent = $values['skonto_percent'];
  
  if ($skonto_period && !$skonto_percent)
    form_set_error('skonto_percent', t('If you enter skonto period, please enter skonto percent, too.'));
  if (!$skonto_period && $skonto_percent)
    form_set_error('skonto_period', t('If you enter skonto credit, please enter skonto percent, too.'));

  //both must be numeric and only full numers, no floats
  if ($skonto_period && (!is_numeric($skonto_period) || strpos($skonto_period, '.') > 0))
    form_set_error('skonto_period', t('Please enter only full numeric values for skonto period.'));
  if ($skonto_percent && (!is_numeric($skonto_percent) || strpos($skonto_percent, '.') > 0))
    form_set_error('skonto_percent', t('Please enter only full numeric values for skonto percent.'));    
  
  //credit period must be numeric
  $credit_period = 0;
  if (isset($values['credit_period']))
    $credit_period = $values['credit_period'];
  if ($credit_period && !is_numeric($credit_period))
    form_set_error('credit_period', t('Please enter only full numeric values for credit period.'));
}

/**
* Submit handler for bulk operation configuration form for creating an invoice
*/
function erpal_invoice_helper_invoice_from_billables_action_submit($form, &$form_state) {
  //return other context option (the values that have been submitted) to have them in our action callback
  $values = $form_state['values'];

  //save default invoice values für this customer!
  $defaults = _erpal_invoice_helper_convert_default_form_to_array($values);
  
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
  $reduce = ($context['reduce_billables'] != 'none') ? $context['reduce_billables'] : FALSE;

  if ($reduce)
    $params['group_by'] = $reduce;
  if (isset($context['contractor_nid']))
    $params['contractor_nid'] = $context['contractor_nid'];
  if (isset($context['credit_period']))
    $params['credit_period'] = $context['credit_period']; 
  if (isset($context['invoice_date']))
    $params['invoice_date'] = strtotime($context['invoice_date']); 
  if (isset($context['skonto_period']))
    $params['skonto']['credit_period'] = $context['skonto_period']; 
  if (isset($context['skonto_percent']))
    $params['skonto']['discount_percent'] = $context['skonto_percent']; 
  if (isset($context['address_id']))
    $params['address_id'] = $context['address_id'];
  if (isset($context['order_numbers_intern']))
    $params['order_numbers_intern'] = $context['order_numbers_intern'];
  if (isset($context['order_numbers_extern']))
    $params['order_numbers_extern'] = $context['order_numbers_extern'];
  if (isset($context['invoice_number']))
    $params['invoice_number'] = $context['invoice_number'];
  if (isset($context['notes']))
    $params['notes'] = $context['notes'];

 $status = _erpal_invoice_helper_invoice_from_billables($billable_ids, $reduce, $params);  
 if (!$status['status']) {
    drupal_set_message(t('There are several errors while creating the invoice.'), 'error');
    //there are errors we should dislay!
    foreach ($status['errors'] as $message) {      
      drupal_set_message($message, 'error');
    }
 
 } else {
  $invoice = $status['invoice'];
  $invoice_link = l($invoice->title, 'node/'.$invoice->nid);
  drupal_set_message(t('The invoice !invoice_link has been created', array('!invoice_link' => $invoice_link)));
 }
}

/**
* returns a form with defaults of a customer if available
*/
function _erpal_invoice_helper_customer_defaults_form($customer_node, $contractor_node) {
  $allowed_addresses = _erpal_basic_helper_get_contact_adresses($customer_node, true);
  
  $form = array();

  $defaults = _erpal_invoice_helper_get_customer_defaults($customer_node);
  $default_address = $defaults['address_id'];
  //if we have a default credit period by this customer, use it, otherwise use the system default
  $default_credit_period = $defaults['credit_period'] ? $defaults['credit_period'] : _erpal_invoice_helper_get_default_credit_period();
  $default_notes = $defaults['notes'];
  
  //no default nodes if customer is not the own company
  module_load_include('inc', 'erpal_basic_helper', 'inc/config');
  $company_nid = _erpal_basic_helper_get_own_company_nid(false);
  $is_contractor_invoice = $company_nid != $contractor_node->nid;
  if ($is_contractor_invoice)
    $default_notes = ''; //no default nodes if we enter a contractor invoice
  
  $default_skonto_period = $defaults['skonto_period'] ? $defaults['skonto_period'] : _erpal_invoice_helper_get_skonto_period();
  $default_skonto_percent = $defaults['skonto_percent'] ? $defaults['skonto_percent'] : _erpal_invoice_helper_get_skonto_rate();  
 
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
  
  $format = erpal_lib_get_date_format(false);
  $default_date = _erpal_invoice_helper_get_todays_invoices_date();
  $form['invoice_date'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('Invoice date'),
    '#default_value' => $default_date ? date('Y-m-d', $default_date) : date('Y-m-d'),  //set today as default
    '#required' => TRUE,
  );
  
    //credit period
  $form['credit_period'] = array(
    '#type' => 'textfield',
    '#size' => 10,
    '#title' => t('Credit period'),
    '#default_value' => $default_credit_period,
    '#required' => TRUE,
  );
  
  
  $own_company_nid = _erpal_basic_helper_get_own_company_nid(false);
  if ($contractor_node->nid == $own_company_nid) {
    $next_invoice_number = _erpal_invoice_helper_get_next_invoice_number();
    $invoice_number_required = true;
  } else {
    $next_invoice_number = '';
    $invoice_number_required = false;
  }
  
  $form['invoice_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Invoice number'),
    '#default_value' => $next_invoice_number,
    '#required' => $invoice_number_required,
  );
  

  _erpal_invoice_helper_alter_invoice_number_field($form['invoice_number']['#default_value'], $form['invoice_number']['#description']);    
  
  //add fields for order numbers for intern and extern
  $form['order_numbers'] = array(
    '#type' => 'fieldset',
    '#title' => t('Order numbers'),
    '#collapsible' => true,
    '#collapsed' => true,
    '#tree' => false,
  );
  
  $form['order_numbers']['order_numbers_extern'] = array(
    '#type' => 'textfield',
    '#title' => t('Order numbers extern'),
    '#default_value' => '[erpal_invoice_referenced_data:order_numbers_extern]',
    '#description' => t('Comma separated list of all external order numbers.'),
  );
  
  $form['order_numbers']['order_numbers_intern'] = array(
    '#type' => 'textfield',
    '#title' => t('Order numbers intern'),
    '#default_value' => '[erpal_invoice_referenced_data:order_numbers_intern]',
    '#description' => t('Comma separated list of all internal order numbers.'),
  );  
  
  //add available tokens to the form
  //show available Tokens  
  if (module_exists('token')) {    
    $form['order_numbers']['token_tree'] = array(
      '#theme' => 'token_tree',   
      '#token_types' => array('erpal_invoice_referenced_data'),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
      '#recursion_limit' => 1,
    );
  }
  
  //sconto
  $form['skonto'] = array(
    '#type' => 'fieldset',
    '#title' => t('Skonto'),
    '#collapsible' => true,
    '#collapsed' => true,
    '#tree' => false,
  );
  
  $form['skonto']['skonto_period'] = array(
    '#type' => 'textfield',
    '#size' => 6,
    '#title' => t('Credit period in days'),
    '#description' => t('Within this credit period the skonto is granted.'),
    '#default_value' => $default_skonto_period,
  );
  
  $form['skonto']['skonto_percent'] = array(
    '#type' => 'textfield',    
    '#size' => 6,
    '#title' => t('Credit in percent for skonto'),
    '#default_value' => $default_skonto_percent,
  );
    
  $form['notes'] = array(
    '#type' => 'textarea',
    '#title' => t('Notes'),
    '#default_value' => $default_notes,
  );
  
  //add available tokens to the form
  //show available Tokens  
  
  if (module_exists('token') && !$is_contractor_invoice) {    
    $form['token_tree'] = array(
      '#theme' => 'token_tree',   
      '#token_types' => array('erpal_invoice'),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
      '#recursion_limit' => 1,
    );
  }
  
  //@TODO preview billables (non reduced with hint that they will be reduced) and princing (total, netto, vat rates)
  
  $form['save_defaults'] = array(
    '#type' => 'checkbox',
    '#title' => t('Save settings as default for this customer'),
    '#default_value' => true,
  );
  
  return $form;
}
