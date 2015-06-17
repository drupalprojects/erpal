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
  
  $form['invoice_templates'] = array(
    '#type' => 'fieldset',
    '#title' => t('Invoice PDF templates'),
    '#collapsible' => true,
    '#collapsed' => false,
    '#weight' => -3,
  );
  
  $form['invoice_templates']['invoice_hint'] = array(
    '#type' => 'markup',
    '#markup' => t('If you want to upload a custom invoice header logo, you can do this in the document settings at !link', array('!link' => l('ERPAL settings', 'admin/erpal'))),
  );
  
  $form['invoice_templates']['erpal_invoice_templates_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Invoice template path'),
    '#description' => t('This is the path, relative to your ERPAL installation folder, where your invoice template is placed. NO leading slash, filename must end with .tpl.php'),
    '#default_value' => _erpal_invoice_helper_get_invoice_template('invoice', false),
  );

  $form['invoice_templates']['erpal_invoice_attachment_templates_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Invoice attachment template path'),
    '#description' => t('This is the path, relative to your ERPAL installation folder, where your invoice attachment template is placed. NO leading slash, filename must end with .tpl.php'),
    '#default_value' => _erpal_invoice_helper_get_invoice_template('attachment', false),
  );
  
  $form['billable_texts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Billable texts'),
    '#collapsible' => true,
    '#collapsed' => true,
    '#weight' => -3,
  );
  
  $form['billable_texts']['erpal_billable_grouping_texts'] = array(
    '#type' => 'textfield',
    '#title' => t('Grouping billable texts'),
    '#description' => t('This text will be used as subject for grouped billables'),
    '#default_value' => _erpal_invoice_helper_get_grouping_billable_text(),
    '#maxlength' => 255,
  );
  
  //fieldset for all company specific settings
  $form['company_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Company settings'),
    '#collapsible' => true,
    '#collapsed' => $company_nid > 0,
    '#weight' => -2,
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
  
  $form['invoice_number'] = array(
    '#type' => 'fieldset',
    '#title' => t('Invoice number'),
    '#collapsible' => true,
    '#collapsed' => true,
    '#weight' => -1
  );
  
  $form['invoice_number']['erpal_invoice_number_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Invoice number pattern'),
    '#default_value' => _erpal_invoice_helper_get_invoice_number_pattern(),    
    '#description' => t('This pattern will let you design your invoice number'),
  );
  
  $form['invoice_number']['erpal_invoice_number_offset'] = array(
    '#type' => 'textfield',
    '#title' => t('Invoice number offset'),
    '#default_value' => variable_get('erpal_last_invoice_number', 1),    
    '#description' => t('This offset definies current invoice number. Next invoice number will be this +1'),
    '#element_validate' => array('element_validate_integer_positive'), 
  );
  
  //Tokens for invoice pattern
  //show available Tokens  
  $form['invoice_number']['token_tree'] = array(
    '#theme' => 'token_tree',   
    //'#token_types' => array(),
    '#global_types' => TRUE,
    '#click_insert' => TRUE,
    '#recursion_limit' => 1,
  );
  
  $form['erpal_invoice_currencies'] = array(
    '#type' => 'textarea',
    '#title' => t('Currencies'),
    '#default_value' => _erpal_invoice_helper_get_currencies_string(),    
    '#description' => t('Syntax is currency_short#currency_label each line one currency'),
  );
  
  $form['erpal_invoice_default_currency'] = array(
    '#type' => 'select',
    '#title' => t('Default currency'),
    '#options' => _erpal_invoice_helper_currencies_arr(),
    '#default_value' => _erpal_invoice_helper_get_default_currency(),
  );  
  
  $form['erpal_invoice_vat_rates'] = array(
    '#type' => 'textarea',
    '#title' => t('Tax rates'),
    '#default_value' => _erpal_invoice_helper_get_vat_rates_string(),    
    '#description' => t('Syntax is vat_value#vat_display_label#additional invoice note each line'),
  );
  
  $form['erpal_invoice_default_vat_rate'] = array(
    '#type' => 'select',
    '#title' => t('Default VAT rate'),
    '#options' => _erpal_invoice_helper_vat_rates_arr(),
    '#default_value' => _erpal_invoice_helper_get_default_vat_rate(),
  );
  
  $form['erpal_invoice_credit_periods'] = array(
    '#type' => 'textarea',
    '#title' => t('Credit periods'),
    '#default_value' => _erpal_invoice_helper_get_credit_periods_string(),    
    '#description' => t('Enter credit period in days each in a separate line'),
  );
  
  $form['erpal_invoice_default_credit_period'] = array(
    '#type' => 'select',
    '#title' => t('Default credit period'),
    '#options' => _erpal_invoice_helper_get_credit_periods_arr(),
    '#default_value' => _erpal_invoice_helper_get_default_credit_period(),
  );
  
  
  $form['erpal_invoice_manuall_notes'] = array(
    '#type' => 'textarea',
    '#title' => t('Manuall invoice notes'),
    '#default_value' => _erpal_invoice_helper_get_manuall_notes(),    
    '#description' => t('Manually entered notes to show below your invoice calculation. Please use the following tokens to add invoice data to your text'),
  ); 
  
  //show available Tokens  
  if (module_exists('token')) {
    $form['token_tree'] = array(
      '#theme' => 'token_tree',   
      '#token_types' => array('erpal_invoice'),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
      '#recursion_limit' => 1,
    );
  }

  $form['skonto'] = array(
    '#type' => 'fieldset',
    '#title' => t('Skonto settings'),
    '#collapsible' => true,
    '#collapsed' => false,
  );
  
  $form['skonto']['erpal_invoice_skonto_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Skonto text'),
    '#default_value' => _erpal_invoice_helper_get_skonto_text(),    
    '#description' => t('If your invoice has skonto settings, this text will be printed to the invoice export.'),
  );    
  
  //show available Tokens  
  if (module_exists('token')) {
    $form['skonto']['token_tree'] = array(
      '#theme' => 'token_tree',   
      '#token_types' => array('erpal_invoice_skonto'),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
      '#recursion_limit' => 1,
    );
  }
  
  $form['skonto']['erpal_invoice_skonto_period'] = array(
    '#type' => 'textfield',
    '#title' => t('Skonto priod in days'),
    '#size' => 4,
    '#default_value' => _erpal_invoice_helper_get_skonto_period(),    
    '#description' => t('The default skonto period in days for your invoices. You can also set this per customer.'),
  );
  
  $form['skonto']['erpal_invoice_skonto_rate'] = array(
    '#type' => 'textfield',
    '#title' => t('Skonto rate in percent'),
    '#size' => 4,
    '#default_value' => _erpal_invoice_helper_get_skonto_rate(),    
    '#description' => t('The default skonto rate in percent for your invoices. You can also set this per customer.'),
  );
  
  
  //text for a invoice copy marked in pdf export
  $form['erpal_invoice_copy_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Invoice copy text'),
    '#description' => t('Text is placed in an invoice if the invoice is a copy'),
    '#default_value' => _erpal_invoice_helper_get_invoice_copy_text(),
  );
  
  //text for a invoice cancelation marked in pdf export
  $form['erpal_invoice_canceled_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Invoice canceled text'),
    '#description' => t('Text is placed in an invoice if the invoice has been canceled'),
    '#default_value' => _erpal_invoice_helper_get_invoice_canceled_text(),
  );
  
  $form['service_category_terms_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit service category terms'), 'admin/structure/taxonomy/service_category_terms'),
  );
  
  //text for a invoice cancelation marked in pdf export
  $form['access_control'] = array(
    '#type' => 'fieldset',
    '#title' => t('Access control'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,    
  );
  
  //text for a invoice cancelation marked in pdf export
  $form['access_control']['erpal_invoice_access_control_invoices'] = array(
    '#type' => 'checkbox',
    '#title' => t('Access control for invoices'),
    '#description' => t('Grant access to invoices for all users referencing a CRM contact that has a "works" at relation to the company of the customer or where the user is referenced directly to the contact that is the customer of an invoice'),
    '#default_value' => _erpal_invoice_helper_get_access_control_invoices(),
  );
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
    '#submit' => array('_erpal_invoice_helper_config_form_submit'),
    '#validate' => array('_erpal_invoice_helper_config_form_validate'),
  );
  
  return $form;
}

/**
* Returns the access control flag for invoices
*/
function _erpal_invoice_helper_get_access_control_invoices() {
  return variable_get('erpal_invoice_access_control_invoices', FALSE);
}

/**
* Validation handler of config form
*/
function _erpal_invoice_helper_config_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $invoice = $values['erpal_invoice_templates_path'];
  $attachment = $values['erpal_invoice_attachment_templates_path'];

  if ($attachment) {
    //check if exists    
    if (!file_exists(DRUPAL_ROOT.'/'.$attachment)) {
      form_set_error('erpal_invoice_attachment_templates_path', t('Please ensure that the file exists.'));
    }
  }
  
  if ($invoice) {
    //check if exists    
    if (!file_exists(DRUPAL_ROOT.'/'.$invoice)) {
      form_set_error('erpal_invoice_templates_path', t('Please ensure that the file exists.'));
    }
  }
  
  drupal_theme_rebuild();  //rebuild registry
}

/**
* submit handler of erpal basic config form
*/
function _erpal_invoice_helper_config_form_submit($form, $form_state){

  $values = $form_state['values'];

  variable_set('erpal_invoice_number_pattern', $values['erpal_invoice_number_pattern']);
  variable_set('erpal_invoice_vat_rates_string', $values['erpal_invoice_vat_rates']);
  variable_set('erpal_invoice_default_vat_rate', $values['erpal_invoice_default_vat_rate']);
  variable_set('erpal_invoice_credit_periods_string', $values['erpal_invoice_credit_periods']);
  variable_set('erpal_invoice_manuall_notes', $values['erpal_invoice_manuall_notes']);
  variable_set('erpal_invoice_currencies_string', $values['erpal_invoice_currencies']);
  variable_set('erpal_invoice_default_currency', $values['erpal_invoice_default_currency']);
  variable_set('erpal_invoice_default_credit_period', $values['erpal_invoice_default_credit_period']);
  variable_set('erpal_invoice_copy_text', $values['erpal_invoice_copy_text']);
  variable_set('erpal_invoice_canceled_text', $values['erpal_invoice_canceled_text']);
  variable_set('erpal_last_invoice_number', $values['erpal_invoice_number_offset']);
  
  //skonto
  variable_set('erpal_invoice_skonto_text', $values['erpal_invoice_skonto_text']);
  variable_set('erpal_invoice_skonto_period', $values['erpal_invoice_skonto_period']);
  variable_set('erpal_invoice_skonto_rate', $values['erpal_invoice_skonto_rate']);

  //template paths  
  if (empty($values['erpal_invoice_templates_path'])) {
    $values['erpal_invoice_templates_path'] = _erpal_invoice_helper_get_invoice_template('invoice', FALSE, TRUE);
  }
  if (empty($values['erpal_invoice_attachment_templates_path'])) {
    $values['erpal_invoice_attachment_templates_path'] = _erpal_invoice_helper_get_invoice_template('attachment', FALSE, TRUE);
  }

  variable_set('erpal_invoice_templates_path', $values['erpal_invoice_templates_path']);
  variable_set('erpal_invoice_attachment_templates_path', $values['erpal_invoice_attachment_templates_path']);
  
  variable_set('erpal_billable_grouping_texts', $values['erpal_billable_grouping_texts']);
  
  //access control
  //if access control changed, set node access dirty flag
  if (variable_get('erpal_invoice_access_control_invoices', false) != $values['erpal_invoice_access_control_invoices']) {
    variable_set('erpal_invoice_access_control_invoices', $values['erpal_invoice_access_control_invoices']); 
        
    $invoice_access_enabled = _erpal_invoice_helper_get_access_control_invoices();
   
    //The flag has changed so we need to remove all previously set invoice grants
    _erpal_invoice_helper_remove_invoice_access();   
    
    //it was enabled and we need to do some recalculation of AUL grants
    _erpal_invoice_helper_calculate_all_invoices_access();
    
    if ($invoice_access_enabled) {
      drupal_set_message(t('The invoice access control has been enabled.'));
    } else {
      drupal_set_message(t('The invoice access control has been disabled.'));
    }        
  }   
}

/**
* Function to return the invoice number prefix
*/
function _erpal_invoice_helper_get_invoice_number_pattern() {
  $pattern = variable_get('erpal_invoice_number_pattern', '');
  
  if (!$pattern)
    $pattern = "[erpal_invoice:next_invoice_number]";
    
  return $pattern;
}

/**
* returns the text that is used as subject for grouped billables
*/
function _erpal_invoice_helper_get_grouping_billable_text() {
  return variable_get('erpal_billable_grouping_texts', 'Different work of service category "[erpal_projects_billable_subject:service_category]"'); 
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
* Returns the skonto text
*/
function _erpal_invoice_helper_get_skonto_text() {
  return variable_get('erpal_invoice_skonto_text', '');
}

/**
* Returns the skonto period
*/
function _erpal_invoice_helper_get_skonto_period() {
  return variable_get('erpal_invoice_skonto_period', '');
}

/**
* Returns the skonto rate
*/
function _erpal_invoice_helper_get_skonto_rate() {
  return variable_get('erpal_invoice_skonto_rate', '');
}

/**
* Function that returns the vat rates string provided by the erpal_invoice_helper module
*/
function _erpal_invoice_helper_get_vat_rates_string() {
  return variable_get('erpal_invoice_vat_rates_string', '7#7');
}

/**
* Return string that definies all available currencies
*/
function _erpal_invoice_helper_get_currencies_string() {
  return variable_get('erpal_invoice_currencies_string', 'EUR#Euro');
}

/**
* Returns the default VAT rate
*/
function _erpal_invoice_helper_get_default_vat_rate() {
  return variable_get('erpal_invoice_default_vat_rate', '19.000');
}

/**
* Returns default currency
*/
function _erpal_invoice_helper_get_default_currency() {
  return variable_get('erpal_invoice_default_currency', 'EUR');
}

/**
* Returns default credit period
*/
function _erpal_invoice_helper_get_default_credit_period() {
  return variable_get('erpal_invoice_default_credit_period', '14');
}

/**
* Returns all available currencies as array
*/
function _erpal_invoice_helper_currencies_arr() {
  $currency_string = _erpal_invoice_helper_get_currencies_string();
  $currency_strings = explode("\r\n", $currency_string);
  
  $currencies = array();
  foreach ($currency_strings as $a_currency_string) {
    $currency_row = explode('#', $a_currency_string);
    $key = $currency_row[0];
    if (isset($currency_row[1]))
      $value = $currency_row[1];
    else
      $value = $key;
      
    $currencies[$key] = $value;
  }
  
  return $currencies;
}

/**
* returns vat rates as array
* @param $add_notes - if true the funciton adds all notes that are related to each vat rate.
* @return array vat_rate value is the key, the array value is either the vat label (if $add_notes=false) or
* an array with keys 'label' and 'note'.
*/
function _erpal_invoice_helper_vat_rates_arr($add_notes=false) {
  $vat_rates_string = _erpal_invoice_helper_get_vat_rates_string();
  
  //split to get each row
  $vat_rates_strings = explode("\r\n", $vat_rates_string);

  //now split each row, so first value ist vat_rate value in percen, secound valu is the label
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
      
    //convert to 3 decimals
    $vat_row[0] = number_format($vat_row[0], 3);
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
* Return some invoice template path
*/
function _erpal_invoice_helper_get_invoice_template($type, $sanitize_endings, $return_defaults = FALSE) {
  $invoice_mod_path  = drupal_get_path('module', 'erpal_invoice_helper');
  $default_invoice_theme_path = $invoice_mod_path.'/template/invoice_pdf_html.tpl.php';
  $default_attachment_theme_path = $invoice_mod_path.'/template/invoice_attachment_pdf_html.tpl.php';
  
  $path = FALSE;
  if ($type == 'invoice') {
    if ($return_defaults) {
      $path = $default_invoice_theme_path;
    } else {
      $path = variable_get('erpal_invoice_templates_path', $default_invoice_theme_path);
    }
  }
  
  if ($type == 'attachment') {
    if ($return_defaults) {
      $path = $default_attachment_theme_path;
    } else {
      $path = variable_get('erpal_invoice_attachment_templates_path', $default_attachment_theme_path);
    }
  }
  
  if ($path) {
    //remove the tpl.php it will be added by the template funtion
    if ($sanitize_endings) {
      $path = str_replace('.tpl.php', '', $path);
    }
    
    return $path;
  }
  
  return FALSE;
}
