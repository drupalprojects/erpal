<?php

/**
* Returns all the menu path for config of invoice feature
*/
function _erpal_invoice_helper_config_menu(){
  
  $items['admin/erpal/invoice'] = array(
    'title' => 'ERPAL invoice',
    'page callback' => '_erpal_invoice_helper_config_basic',    
    'access arguments' => array('config erpal invoice'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL Basic Feature
*/
function _erpal_invoice_helper_config_basic(){
  $form = drupal_get_form('erpal_invoice_helper_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL invoice
*/
function erpal_invoice_helper_config_form($form, &$form_state){

  $form = array();
  
  module_load_include('inc', 'erpal_basic_helper', 'inc/config');
  $company_nid = _erpal_basic_helper_get_own_company_nid(false);
  $company_string = l(t('Please select your company!'), 'admin/erpal/basic');
  
  //fieldset for all company specific settings
  $form['company_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Company settings'),
    '#collapsible' => true,
    '#collapsed' => $company_nid > 0,
  );
  
  if ($company_nid) {
    //format a string to display the company
    $company_node = node_load($company_nid);
    $company_string = l($company_node->title, 'node/'.$company_node->nid);
  }
  //selected company
  $form['company_settings']['my_company'] = array(
    '#type' => 'item',
    '#title' => t('Your company'),
    '#markup' => $company_string,
    '#description' => t('You can change your company in !link', array('!link' => l(t('ERPAL basic settings'), 'admin/erpal/basic'))),
  );
  
  $form['erpal_invoice_number_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Invoice number prefix'),
    '#default_value' => _erpal_invoice_helper_get_invoice_number_prefix(),    
    '#description' => t('This prefix will be added as prefix to every invoice number'),
  );
  
  $form['erpal_invoice_vat_rates'] = array(
    '#type' => 'textarea',
    '#title' => t('VAT rates'),
    '#default_value' => _erpal_invoice_helper_get_vat_rates_string(),    
    '#description' => t('Syntax is vat_value#vat_display_label#additional invoice note each line'),
  );
  
  $form['erpal_invoice_credit_periods'] = array(
    '#type' => 'textarea',
    '#title' => t('Credit periods'),
    '#default_value' => _erpal_invoice_helper_get_credit_periods_string(),    
    '#description' => t('Enter credit period in days each in a separate line'),
  );
  
  $form['erpal_invoice_manuall_notes'] = array(
    '#type' => 'textarea',
    '#title' => t('Manuall invoice notes'),
    '#default_value' => _erpal_invoice_helper_get_manuall_notes(),    
    '#description' => t('Manually entered notes to show below your invoice calculation. Please us the fallowing tokens to add invoice data to your text: [node:field_credit_period], '),
  );
  
  //show available Tokens
  $token_types = array(
    'theme' => 'token_tree',
    'token_types' => array('erpal_invoice'),
    'global_types' => FALSE,
    'click_insert' => TRUE,
    'recursion_limit' => 1,
  );
  
  if (module_exists('token')) {
    $form['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => $token_types,
    );
  }
  else {
    $form['token_tree'] = array(
      '#markup' => '<p>' . t('Enable the <a href="@drupal-token">Token module</a> to view the available token browser.', array('@drupal-token' => 'http://drupal.org/project/token')) . '</p>',
    );
  }
  
  
  
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
  );
  
  return $form;
}

/**
* submit handler of erpal basic config form
*/
function erpal_invoice_helper_config_form_submit($form, $form_state){

  $values = $form_state['values'];

  variable_set('erpal_invoice_number_prefix', $values['erpal_invoice_number_prefix']);
  variable_set('erpal_invoice_vat_rates_string', $values['erpal_invoice_vat_rates']);
  variable_set('erpal_invoice_credit_periods_string', $values['erpal_invoice_credit_periods']);
  variable_set('erpal_invoice_manuall_notes', $values['erpal_invoice_manuall_notes']);
  
}

/**
* Function to return the invoice number prefix
*/
function _erpal_invoice_helper_get_invoice_number_prefix() {
  return variable_get('erpal_invoice_number_prefix', '');
}

/**
* Function that returns credit periods provided by the erpal_invoice_helper_module
*/
function _erpal_invoice_helper_get_credit_periods_string() {
  return variable_get('erpal_invoice_credit_periods_string', '14');
}


/**
* Function that returns credit periods as an array
*/
function _erpal_invoice_helper_get_credit_periods_arr() {
  $credit_periods_string = _erpal_invoice_helper_get_credit_periods_string();
  
  $credit_periods = explode("\r\n", $credit_periods_string);
  $periods = array();
  
  foreach ($credit_periods as $period) {
    $periods[$period] = $period.' '.t('days');
  }
  
  return $periods;
}

/**
* Function that returns manuall added notes to an invoice
*/
function _erpal_invoice_helper_get_manuall_notes() {
  return variable_get('erpal_invoice_manuall_notes', '');
}

/**
* Function that returns the vat rates string provided by the erpal_invoice_helper module
*/
function _erpal_invoice_helper_get_vat_rates_string() {
  return variable_get('erpal_invoice_vat_rates_string', '7#7');
}


/**
* returns vat rates as array
* @param $add_notes - if true the funciton adds all notes that are related to each vat rate.
* @return array var_rate value is the key, the array value is either the vat label (if $add_notes=false) or
* an array with keys 'label' and 'note'.
*/
function _erpal_invoice_helper_vat_rates_arr($add_notes=false) {
  $vat_rates_string = _erpal_invoice_helper_get_vat_rates_string();
  
  //split to get each row
  $vat_rates_strings = explode("\r\n", $vat_rates_string);

  //now split each row, so first value ist var_rate value in percen, secound valu is the label
  //third value is a note
  $rates = array();
  foreach ($vat_rates_strings as $rate_string) {
    $vat_row = explode('#', $rate_string);
    
    if (!isset($vat_row[0]))  
      continue;
      
    $vat_rate = $vat_row[0];
    
    if (isset($vat_row[1]))
      $vat_label = $vat_row[1];
    else
      $vat_label = $vat_rate."%";
      
    $vat_note = '';
    if (isset($vat_row[2]))
      $vat_note = $vat_row[2];
      
    if ($add_notes) {
      $rates[$vat_row[0]] = array(
        'label' => $vat_label,
        'note' => $vat_note,
        'value' => $vat_rate,
      );
    } else {     
      $rates[$vat_row[0]] = $vat_label;       
    }
  }

  return $rates;
}

/**
* Function returns the bank accounts to display in the invoice.
*/
function _erpal_invoice_helper_get_bank_accounts() {
  return _erpal_basic_helper_get_bank_accounts();  //this will return an array of entities
}