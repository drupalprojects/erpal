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
  
  // Add textfield for private filesystem settings
   
  $form['filesystem_settings'] = array(
    '#title' => st('Filesystem settings'),
    '#type' => 'fieldset',
  );
  $form['filesystem_settings']['file_private_path'] = array(
    '#type' => 'textfield', 
    '#title' => st('Private file system path'), 
    '#default_value' => variable_get('file_private_path', 'sites/default/files/private'), 
    '#maxlength' => 255,
    '#required' => TRUE, 
  );

  $form['#validate'][] = 'erpal_germany_file_private_path_validate';
  $form['#submit'][] = 'erpal_germany_file_private_path_submit';
}

function erpal_germany_file_private_path_validate($form, $form_state){ 
  $dir = $form_state['values']['file_private_path'];
  if(!file_prepare_directory($dir, FILE_CREATE_DIRECTORY)){
    if(is_dir($dir)){
      form_set_error('file_private_path', 'The private filesystem path is not writable. Drupal needs write permissions to ' . $dir);
    }else{
      form_set_error('file_private_path', 'The private filesystem folder does not exist and can not be created. Please set the permissions, or create the folder manually.');
    }
  }
}



function erpal_germany_file_private_path_submit($form, $form_state){
  variable_set('file_private_path', $form_state['values']['file_private_path']);

}

/** 
 * Add additional install tasks 
 */
function erpal_germany_install_tasks(){

  
  $tasks = array();
  
  $tasks['erpal_germany_preconfigure_site'] = array(
    'display_name' => st('Configure Erpal'),
    'display' => TRUE,
    'type' => 'batch',
  );

  $tasks['erpal_germany_contact_information_form'] = array(
    'display_name' => st('Contact information'),
    'display' => TRUE,
    'type' => 'form',
  );
  
  if(FALSE){
    $tasks['erpal_germany_config_form'] = array(
      'display_name' => st('Configure Erpal'),
      'display' => TRUE,
      'type' => 'form',
    );
    $tasks['erpal_germany_calendar_config_form'] = array(
      'display_name' => st('Configure Calendar'),
      'display' => TRUE,
      'type' => 'form',
    );
    $tasks['erpal_germany_invoice_config_form'] = array(
      'display_name' => st('Configure Invoice'),
      'display' => TRUE,
      'type' => 'form',
    );
  }
  $tasks['erpal_germany_last_config_steps'] = array(
    'display' => FALSE, 
    'type' => 'batch',
  );
  
  return $tasks;
}

function erpal_germany_preconfigure_site(){
  $operations = array(
    array('_erpal_germany_create_relations', array()),
    array('_erpal_germany_create_taxonomy', array()),
    array('_erpal_germany_invoice_config', array()),
    array('_erpal_germany_projects_config', array()),
    array('_erpal_germany_calendar_config', array()),
    array('_erpal_germany_various_settings', array()),
  );
  $batch = array(
    'title' => st('Preparing site'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'erpal_germany') . '/erpal_germany_callbacks.inc',
  );
  return $batch;  
}


function erpal_germany_last_config_steps(){
  
  $operations = array(
    array('_erpal_germany_rebuild_content_access', array()),
    array('_erpal_germany_revert_features', array()),
  );
    
  $batch = array(
    'title' => st('Performing last installation tasks'),
    'operations' => $operations,  
    'file' => drupal_get_path('profile', 'erpal_germany') . '/erpal_germany_callbacks.inc',
  );
  return $batch;

}

/**
 * Installation task "Contact information"
 * 
 */
function erpal_germany_contact_information_form($form, &$form_state){
  drupal_set_title(st('Contact information'));
  $form = array();  
  $form['contact_name'] = array(
    '#type' => 'fieldset',
    '#title' => st('My Company'),
  );
  
  $form['contact_name']['company_name'] = array(
    '#type' => 'textfield',    
    '#title' => st('Company name:'),
    '#required' => TRUE,
  );
  $form['company_address'] = array(
    '#type' => 'fieldset',
    '#title' => st('Main Address'),  
  );
  $form['company_address']['street'] = array(
    '#title' => st('Street:'),
    '#type' => 'textfield', 
    '#required' => TRUE,     
  );
  $form['company_address']['zip_code'] = array(
    '#title' => st('ZIP-Code:'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['company_address']['city'] = array(
    '#title' => st('City:'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  
  
  $countries_vocabulary = taxonomy_vocabulary_machine_name_load('countries');
  $countries_terms = taxonomy_get_tree($countries_vocabulary->vid, 0);
  $countries = array();
  foreach($countries_terms as $term){
    $countries[$term->tid] = $term->name;
  }  
  $form['company_address']['country'] = array(
    '#title' => st('Country'),
    '#type' => 'select',
    '#options' => $countries,
    '#default_value' => array_search('Germany', $countries),
  );
  
    
  $form['contact_information'] = array(
    '#type' => 'fieldset',
    '#title' => st('Contact information'),
  );
  $form['contact_information']['phone_number'] = array(
    '#title' => st('Phone number:'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['contact_information']['email_address'] = array(
    '#title' => st('Email:'),
    '#type' => 'textfield',
    '#required' => TRUE,
  
  );
  
  
  $form['submit'] = array(
    '#value' => st('Save and continue'),
    '#type' => 'submit',
  );
  
  
  return $form;
}

function erpal_germany_contact_information_form_validate($form, $form_state){
  $values = $form_state['values'];

  if(!is_numeric($values['zip_code']))
    form_set_error('zip_code', 'Please enter only numbers as a zip-code.');
  
  if(!is_numeric($values['phone_number']))
    form_set_error('phone_number', 'Please enter only numbers as phone number.');
  
  if(!valid_email_address($values['email_address']))
    form_set_error('email_address', 'The Email-address is not valid.');
}


function erpal_germany_contact_information_form_submit($form, $form_state){
  
  $values = $form_state['values'];
  $company_name = $values['company_name'];
  global $user;
  $node_type = 'erpal_contact';
  $node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name)) ? $user->name : '',
    'type' => $node_type,
    'language' => LANGUAGE_NONE,  
    'title' => $company_name,
    'field_company_name' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $company_name,
          'format' => NULL,
          'save_value' => $company_name,
        ),
      ),
    ),
    'field_contact_type' => array(
      LANGUAGE_NONE => array(
        0 => array('value' => 'company',),
      ),
    ),
    'field_email' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $values['email_address'],
        ),
      ),
    ),
  );
  node_object_prepare($node); 
  node_save($node);

  $address = entity_create('field_collection_item', array('field_name' => 'field_addresses'));
  $address->setHostEntity('node', $node);
  $address->field_street[LANGUAGE_NONE][0]['value'] = $values['street'];
  $address->field_zip_code[LANGUAGE_NONE][0]['value'] = $values['zip_code'];
  $address->field_city[LANGUAGE_NONE][0]['value'] = $values['city'];
  //$address->field_country_term[LANGUAGE_NONE][0]['value'] = $values['country']->tid;
  $address->save();
  
  $phone_number = entity_create('field_collection_item', array('field_name' => 'field_phone'));
  $phone_number->setHostEntity('node', $node);
  $phone_number->field_phone_number[LANGUAGE_NONE][0]['value'] = $values['phone_number'];
  $phone_number->save();
  
  variable_set('erpal_config_my_company_nid', $node->nid);
  variable_set('my_field_addresses', 0);  //set field 0 as default
  variable_set('my_field_phone', 0);  //      ""  
  variable_set('my_field_email', $values['email_address']);  //save email address
}

/**
 * Basic settings form 
 */
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
    '#title' => t('Allowed doc file extensions'),
    '#description' => t('These extensions are allowed when uploading a file to the asset management. Separate them by spaces.'),
    '#default_value' => _erpal_docs_helper_doc_extensions(),
  );
  
  $form['erpal_contract'] = array(
    '#type' => 'fieldset',
    '#title' => 'Erpal Contract',
  );
  
  $form['erpal_contract']['precalculation_range'] = array(
    '#type' => 'textfield',
    '#title' => t('Precalculation range contract duration'),
    '#description' => t('Number of month the date items for contract calculation are precalculated.'),
    '#default_value' => _erpal_contract_helper_cancelation_precalculate_range(),
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

function erpal_germany_config_form_submit($form, $form_state){
  $values = $form_state['values']; 
  variable_set('erpal_docs_doc_file_extensions', $values['doc_file_extensions']);
  variable_set('date_format_erpal_date', $values['date_only']);
  variable_set('date_format_erpal_date_time', $values['date_time']);
  variable_set('erpal_debug', $values['debug_mode']);
  variable_set('erpal_book_skip_pdf_header_frontpage', $values['skip_logo']);
  $cancelation_precalculate_range = intval($values['precalculation_range']);
  variable_set('cancelation_precalculate_range', $cancelation_precalculate_range);
}

function erpal_germany_invoice_config_form(){
  drupal_set_title(st('Erpal Invoice configuration'));
  $form = drupal_get_form('erpal_invoice_helper_config_form');
  return $form;
}

function erpal_germany_calendar_config_form(){
  drupal_set_title(st('Erpal Calendar configuration'));
  $form = drupal_get_form('erpal_calendar_helper_config_form');
  return $form;
}
