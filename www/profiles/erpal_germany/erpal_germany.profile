<?php
/**
 * @file
 * Enables modules and site configuration for a erpal site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function erpal_germany_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form['filesystem_settings'] = array(
    '#type' => 'fieldset',
    '#title' => st('Filesystem settings'),
  );
  $form['filesystem_settings']['file_private_path'] = array(
    '#type' => 'textfield', 
    '#title' => st('Private file system path'), 
    '#default_value' => variable_get('file_private_path', ''), 
    '#maxlength' => 255, 
    '#description' => st('An existing local file system path for storing private files. It should be writable by Drupal and not accessible over the web. See the online handbook for <a href="@handbook">more information about securing private files</a>.', array('@handbook' => 'http://drupal.org/documentation/modules/file')), 
    '#after_build' => array('system_check_directory'),
  );
  $form['#submit'][] = 'erpal_germany_file_private_path_submit';
}

function erpal_germany_file_private_path_submit($form, $form_state){
  variable_set('file_private_path', $form_state['values']['file_private_path']);
}

/**
 * Zusaetzliche installationsaufgaben definieren 
 */
function erpal_germany_install_tasks(){
  return array(
    'erpal_germany_contact_information_form' => array(
      'display_name' => st('Contact Information'),
      'display' => TRUE,
      'type' => 'form',
      ),
    'erpal_germany_config_form' => array(
      'display_name' => st('Configure Erpal'),
      'display' => TRUE,
      'type' => 'form',
      ),
    //~ 'erpal_germany_invoice_config_form' => array(
      //~ 'display_name' => st('Configure Invoice'),
      //~ 'display' => TRUE,
      //~ 'type' => 'form',
      //~ ),
    //~ 'erpal_germany_calendar_config_form' => array(
      //~ 'display_name' => st('Configure Calendar'),
      //~ 'display' => TRUE,
      //~ 'type' => 'form',
      //~ ),
    );
}

/**
 * Installation task "Contact information"
 * 
 */
function erpal_germany_contact_information_form(){
  drupal_set_title(st('Contact information'));
  $form = array();
  $form['company_settings'] = array(
    '#type' => 'fieldset',
    '#title' => st('My Company'),
  );
  $form['company_settings']['company_name'] = array(
    '#type' => 'textfield',    
    '#title' => st('Company name:'),
  );
  $form['company_address'] = array(
    '#type' => 'fieldset',
    '#title' => st('Main Address'),  
  );
  $form['company_address']['street'] = array(
    '#title' => st('Street:'),
    '#type' => 'textfield',
  );
  $form['company_address']['zip_code'] = array(
    '#title' => st('ZIP-Code:'),
    '#type' => 'textfield',
  );
  $form['company_address']['city'] = array(
    '#title' => st('City:'),
    '#type' => 'textfield',
  );
  //~ $form['company_address']['country'] = array(
    //~ '#title' => st('Country'),
    //~ '#type' => 'select',
    //~ 
  //~ );
  $form['company_address']['phone_number'] = array(
    '#title' => st('Phone number:'),
    '#type' => 'textfield',
  );
  $form['company_address']['email_address'] = array(
    '#title' => st('Email:'),
    '#type' => 'textfield',
  );
  $form['submit'] = array(
    '#value' => st('Save and continue'),
    '#type' => 'submit',
  );
  
  
  return $form;
}

function erpal_germany_contact_information_form_validate($form, $form_state){

    
}

function erpal_germany_contact_information_form_submit($form, $form_state){
  global $user;
  $node_type = 'erpal_contact';
  $node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name)) ? $user->name : '',
    'type' => $node_type,
    'language' => LANGUAGE_NONE,  
    'title' => $form_state['values']['company_name'],
    'field_company_name' => array(
      'und' => array(
        0 => array(
          'value' => $form_state['values']['company_name'],
          'format' => NULL,
          'save_value' => $form_state['values']['company_name'],
        ),
      ),
    ),
    'field_contact_type' => array(
      'und' => array(
        0 => array('value' => 'company',),
      ),
    ),
    'field_email' => array(
      'und' => array(
        0 => array(
          'value' => $form_state['values']['email_address'],
        ),
      ),
    ),
  );
  node_object_prepare($node);
  node_save($node);

  $address = entity_create('field_collection_item', array('field_name' => 'field_addresses'));
  $address->setHostEntity('node', $node);
  $address->field_street[LANGUAGE_NONE][0]['value'] = $form_state['values']['street'];
  $address->field_zip_code[LANGUAGE_NONE][0]['value'] = $form_state['values']['zip_code'];
  $address->field_city[LANGUAGE_NONE][0]['value'] = $form_state['values']['city'];
  $address->save();
  
  $phone_number = entity_create('field_collection_item', array('field_name' => 'field_phone'));
  $phone_number->setHostEntity('node', $node);
  $phone_number->field_phone_number[LANGUAGE_NONE][0]['value'] = $form_state['values']['phone_number'];
  $phone_number->save();
  
  variable_set('erpal_config_my_company_nid', $node->nid);
  variable_set('my_field_addresses', 0);  //set field 0 as default
  variable_set('my_field_phone', 0);  //      ""  
  variable_set('my_field_email', $form_state['values']['email_address']);  //save email address
}

function erpal_germany_config_form(){
  drupal_set_title(st('Erpal configuration'));
  $form = array();
  
  $form['date_settings'] = array(
    '#type' => 'fieldset',
    '#title' => st('Date settings'),
  );
  $date_formats = _erpal_basic_helper_get_date_formats();
  $form['date_settings']['date_only'] = array(
    '#type' => 'select',
    '#options' => $date_formats,
    '#default_value' => _erpal_basic_helper_date_format_date_only(),
    '#title' => st('Date only format'),
  );
  $form['date_settings']['date_time'] = array(
    '#type' => 'select',
    '#options' => $date_formats,
    '#default_value' => _erpal_basic_helper_date_format_date_time(),
    '#title' => st('Date and time format'),
  );
  
  $form['erpal_book'] = array(
    '#type' => 'fieldset',
    '#title' => 'Erpal Book',
  );
  $form['erpal_book']['skip_logo'] = array(
    '#type' => 'checkbox',
    '#title' => st('Skip header logo in pdf frontpage'),
    '#description' => st('If checked, the logo of a pdf document will not be shown on pdfs first page (frontpage)'),
  
  );
  

  
  
  $form['erpal_docs'] = array(
    '#type' => 'fieldset',
    '#title' => 'Erpal Docs',
  );
  $form['erpal_docs']['doc_file_extensions'] = array(
    '#type' => 'textfield',
    '#title' => st('Allowed doc file extensions'),
    '#value' => 'txt pdf doc docx xls xlsx csv bmp jpg jpeg gif png mm ppt pptx bmml',
  );
  
  

  $form['advanced_configuration'] = array(
    '#type' => 'fieldset',
    '#title' => st('Advanced configuration'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced_configuration']['debug_mode'] = array(
    '#type' => 'checkbox',
    '#title' => st('Run ERPAL in debug mode'),
  );
  

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
  );
  return $form;
}

function erpal_germany_config_form_validate($form, $form_state){

}

function erpal_germany_config_form_submit($form, $form_state){
  variable_set('erpal_docs_doc_file_extensions', $form_state['values']['doc_file_extensions']);
  variable_set('erpal_date_format_date_only', $form_state['values']['date_only']);
  variable_set('erpal_date_format_date_time', $form_state['values']['date_time']);
  variable_set('erpal_debug', $form_state['values']['debug_mode']);
  variable_set('erpal_book_skip_pdf_header_frontpage', $form_state['values']['skip_logo']);
}

function erpal_germany_invoice_config_form(){
  drupal_set_title(st('Erpal Invoice configuration'));
  $form = array();
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
  );
  return $form;
}

function erpal_germany_invoice_config_form_validate($form, $form_state){

}

function erpal_germany_invoice_config_form_submit($form, $form_state){
  
}


function erpal_germany_calendar_config_form(){
  drupal_set_title(st('Erpal Calendar configuration'));
  $form = array();
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'), 
  );
  return $form;
  
}

function erpal_germany_calendar_config_form_validate($form, $form_state){
  
}

function erpal_germany_calendar_config_form_submit($form, $form_state){
  

}







