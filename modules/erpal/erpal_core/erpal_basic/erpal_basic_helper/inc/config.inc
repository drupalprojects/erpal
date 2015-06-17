<?php

/**
* Returns all the menu path for config of Basic feature
*/
function _erpal_basic_helper_config_menu(){
  
  $items['admin/erpal'] = array(
    'title' => 'ERPAL',
    'page callback' => '_erpal_basic_helper_config',    
    'access arguments' => array('config erpal'),
    'file' => 'inc/config.inc',
    'type' => MENU_NORMAL_ITEM,
  );
  
  $items['admin/erpal/basic'] = array(
    'title' => 'ERPAL BASIC',
    'page callback' => '_erpal_basic_helper_config_basic',    
    'access arguments' => array('config erpal basic'),
    'file' => 'inc/config.inc',
    'type' => MENU_DEFAULT_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL Basic Feature
*/
function _erpal_basic_helper_config_basic(){
  $form = drupal_get_form('erpal_basic_helper_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL Core
*/
function erpal_basic_helper_config_form($form, &$form_state){

  $form = array();
  
  $new_contact_link = _erpal_basic_helper_create_contact_link(false, array(), t('create a new contact'));
  
  $submitted_company = 0;
  $submitted_company = isset($form_state['values']['my_company']) ? $form_state['values']['my_company'] : 0;
  if ($submitted_company)
    $company_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($submitted_company);
  else
    $company_nid = _erpal_basic_helper_get_own_company_nid(false);  
  
  $form['erpal_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Run ERPAL in debug mode'),
    '#default_value' => erpal_debug(),
  );
  
  $show_edit_string = '';
  if ($company_nid) {
    $company_node = node_load($company_nid);
    $show_edit_string = l(t('show'), 'node/'.$company_node->nid)." | ".l(t('edit'), 'node/'.$company_node->nid."/edit");
  }
  $form['my_company'] = array(
    '#title' => t('My Company'),
    '#type' => 'textfield',
    '#autocomplete_path' => 'crm/contacts/autocomplete',
    '#default_value' => _erpal_basic_helper_get_own_company_nid(true), //get it in autocomplete format
    '#description' => $show_edit_string." ".t('Select your own company from your contacts or !add_new_contact_link', array('!add_new_contact_link' => $new_contact_link)),
    '#ajax' => array(
      'callback' => '_erpal_basic_helper_ajax_company_preselect_addresses_config',
      'wrapper' => 'basic_address_wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );
  
  $form['ajax_wrapper'] = array(
    '#prefix' => '<div id="basic_address_wrapper">',
    '#suffix' => '</div>',
  );
  
  if ($company_nid) {
    //select the main address that is relevant for all kind of sender information etc.
    $my_address_entity = _erpal_basic_helper_get_my_address_entity();        
    
    $form['ajax_wrapper']['my_address'] = array(
      '#type' => 'select',
      '#title' => t('Main address for correspondence'),
      '#options' => _erpal_basic_helper_get_contact_adresses($company_node, true),
      '#default_value' => $my_address_entity ? $my_address_entity->item_id : 0,
      '#description' => t('This address will be printed on invoices and other official documents'),
    );
  }
  
  $form['country_terms_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit country terms'), 'admin/structure/taxonomy/countries'),
  );
  
  $form['date_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Date settings'),
    '#collapsible' => true,
    '#collapsed' => false,
  );
  
  $date_formats = _erpal_basic_helper_get_date_formats();
  $form['date_settings']['format_date_only'] = array(
    '#type' => 'select',
    '#options' => $date_formats,
    '#default_value' => _erpal_basic_helper_date_format_date_only(),
    '#title' => t('Date only format'),
  );
  
  $form['date_settings']['format_date_time'] = array(
    '#type' => 'select',
    '#options' => $date_formats,
    '#default_value' => _erpal_basic_helper_date_format_date_time(),
    '#title' => t('Date and time format'),
  );
  
  $form['date_settings']['hint'] = array(
    '#type' => 'item',
    '#markup' => t('You can add more date formats in !config_link', array('!config_link' => l(t('date time configuration'), 'admin/config/regional/date-time/formats'))),
  );
  
  $form['submit'] = array(
    '#value' => t('save'),
    '#type' => 'submit',
  );

  return $form;
}

/**
* Callback for AJAX request to update contact data like address, phone etc in basic config
*/
function _erpal_basic_helper_ajax_company_preselect_addresses_config($form, $form_state) {

  if (isset($form['ajax_wrapper']))
    return $form['ajax_wrapper'];  //form has already been processed, so just return the elements
    
  return array();
}

/**
* Validate config form input
*/
function erpal_basic_helper_config_form_validate($form, $form_state) {
  $values = $form_state['values'];
  $my_company_string = $values['my_company'];
  
  $company_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($my_company_string);
  
  $company_node = node_load($company_nid);
  $valid_contact_error = t('Please select a valid contact');
  
  if (empty($company_node))
    return;
  
  if (!$company_node->nid)
    form_set_error('my_company', $valid_contact_error);
    
  if ($company_node->type != 'erpal_contact')
    form_set_error('my_company', $valid_contact_error);
}

/**
* submit handler of erpal basic config form
*/
function erpal_basic_helper_config_form_submit($form, $form_state){

  $values = $form_state['values'];
  $my_company_string = $values['my_company'];
  
  $company_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($my_company_string);
  $address_id = false;
  if (isset($values['my_address']))
    $address_id = $values['my_address'];
  
  $debug = $values['erpal_debug'];
  $format_date_only = $values['format_date_only'];
  $format_date_time = $values['format_date_time'];
  variable_set('erpal_debug', $debug);  //erpal debug mode
  variable_set('erpal_config_my_company_nid', $company_nid);  //save company
  variable_set('my_field_addresses', $address_id);  //save address
  
  variable_set('date_format_erpal_date', $format_date_only);
  variable_set('date_format_erpal_date_time', $format_date_time);
  
}

/**
* returnd the nid from a string created by _erpal_basic_helper_autocomplete_string_from_nid
*/
function _erpal_basic_helper_get_nid_from_autocomplete_string($autocomplete_string){

  if (is_numeric($autocomplete_string))
    return $autocomplete_string;

  preg_match('/^(?:\s*|(.*) )?\[\s*nid\s*:\s*(\d+)\s*\]$/', $autocomplete_string, $matches);
  $nid = 0;
  if (!empty($matches)) {
    //try with [nid]    
    $nid = $matches[2];
  } else {
    //try with (nid)
    preg_match('/^(?:\s*|(.*) )?\(\s*(\d+)\s*\)$/', $autocomplete_string, $matches);
    $nid = 0;

    if (!empty($matches)) {
      //try with [nid]
      $nid = $matches[2];
    }
  }
  
  return $nid;
}

/**
* Returns the own company of the installation
*/
function _erpal_basic_helper_get_own_company_nid($for_autocomplete){
  
  $contact_nid = variable_get('erpal_config_my_company_nid', false);
  
  if ($for_autocomplete)
    return _erpal_basic_helper_autocomplete_string_from_nid($contact_nid);
  else
    return $contact_nid;
}

/**
* returns a autocomplete compatible String for a nid title (12)
*/
function _erpal_basic_helper_autocomplete_string_from_nid($nid){
  if (!$nid)
    return '';
  $node = node_load($nid);
  
  if ($node)
    return $node->title . " (".$nid . ")";
    
  return false;
}


/**
* Overview for all the activated ERPAL Features
*/
function _erpal_basic_helper_config(){
  drupal_goto('admin/erpal/basic');
}

