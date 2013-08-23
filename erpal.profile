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
function erpal_form_install_configure_form_alter(&$form, $form_state) {
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

  $form['#validate'][] = 'erpal_file_private_path_validate';
  $form['#submit'][] = 'erpal_file_private_path_submit';
}

function erpal_file_private_path_validate($form, $form_state){ 
  $dir = $form_state['values']['file_private_path'];
  if(!file_prepare_directory($dir, FILE_CREATE_DIRECTORY)){
    if(is_dir($dir)){
      form_set_error('file_private_path', 'The private filesystem path is not writable. Drupal needs write permissions to ' . $dir);
    }else{
      form_set_error('file_private_path', 'The private filesystem folder does not exist and can not be created. Please set the permissions, or create the folder manually.');
    }
  }
}



function erpal_file_private_path_submit($form, $form_state){
  variable_set('file_private_path', $form_state['values']['file_private_path']);
  variable_set('file_default_scheme', 'private'); 
}

/** 
 * Add additional install tasks 
 */
function erpal_install_tasks(){
  
  $tasks = array();
  
  $tasks['erpal_create_vocabularies_and_taxonomies'] = array(
    'display_name' => st('Creating taxonomies'),
    'display' => TRUE,
    'type' => 'batch',
  );

  $tasks['erpal_contact_information_form'] = array(
    'display_name' => st('Contact information'),
    'display' => TRUE,
    'type' => 'form',
  );
  
  $tasks['erpal_preconfigure_site'] = array(
    'display_name' => st('Preparing site'),
    'display' => TRUE,
    'type' => 'batch',
  );
  
  $tasks['erpal_last_config_steps'] = array(
    'display' => FALSE, 
    'type' => 'batch',
  );
  
  return $tasks;
}


/**
 * Implements hook_install_tasks_alter().
 */
function erpal_install_tasks_alter(&$tasks, $install_state) {
  $tasks['install_select_profile']['display'] = FALSE;
  $welcome['erpal_welcome_message'] = array(
    'display_name' => st('Welcome'),
    'display' => TRUE,
    'type' => 'form',
    'run' => isset($install_state['parameters']['welcome']) ? INSTALL_TASK_SKIP : INSTALL_TASK_RUN_IF_REACHED,
  );
  $old_tasks = $tasks;
  $tasks = array_slice($old_tasks, 0, 1) + $welcome+ array_slice($old_tasks, 1);
  _erpal_set_theme('erpal_maintenance');
}

function erpal_welcome_message($form, $form_state){
  drupal_set_title(st('Welcome'));
  $welcome = st('<p>The following steps will guide you throuh the installation '
  . 'and configuration of your new ERPAL-Site. This project is still under '
  . 'development so feel free to visit our ' 
  . l('homepage', 'http://www.erpal.info')
  . ' and share your thoughts and impressions to make it even better.</br></br>
  Thank you for choosing ERPAL!</p>');
  $form = array();
  $form['welcome_message'] = array(
    '#markup' => $welcome);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Install ERPAL'),
  );
  return $form;
}

function erpal_welcome_message_submit($form, &$form_state) {
  global $install_state;
  $install_state['parameters']['welcome'] = 'done';
}

/**
 * Forces to set the erpal_maintenance theme during the installation
 */
function _erpal_set_theme($target_theme) {
  if ($GLOBALS['theme'] != $target_theme) {
    unset($GLOBALS['theme']);
    drupal_static_reset();
    $GLOBALS['conf']['maintenance_theme'] = $target_theme;
    _drupal_maintenance_theme();
  }
}

function erpal_create_vocabularies_and_taxonomies(){
  require_once(DRUPAL_ROOT . '/profiles/erpal/erpal_taxonomy.inc'); 
    
  $operations = array();
  
  // Prepare directories for term_images
  $operations[] = array('_erpal_taxonomy_prepare', array());
  
  // Create Taxonomies
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_service_category_vocabulary());
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_priority_vocabulary());
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_number_type_vocabulary());
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_address_type_vocabulary());
  
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_task_status_vocabulary());
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_task_type_vocabulary());  
  
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_project_status_vocabulary());
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_project_status_vocabulary());
  
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_countries_vocabulary());
  
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_activity_origin_vocabulary());
  _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_activity_status_vocabulary());

  $batch = array(
    'title' => st('Creating taxonomies'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'erpal') . '/erpal_taxonomy.inc',
  );
  return $batch;  
}

function erpal_preconfigure_site(){
  $operations = array();
      
  $operations[] = array('_erpal_create_roles_and_permissions', array());
  $operations[] = array('_erpal_create_relations', array());
  $operations[] = array('_erpal_invoice_config', array());
  $operations[] = array('_erpal_projects_config', array());
  $operations[] = array('_erpal_calendar_config', array());
  $operations[] = array('_erpal_configure_layout', array());
  $operations[] = array('_erpal_configure_pathauto', array());
  $operations[] = array('_erpal_various_settings', array());

  $batch = array(
    'title' => st('Preparing site'),
    'operations' => $operations,
    'file' => drupal_get_path('profile', 'erpal') . '/erpal_callbacks.inc',
  );
  return $batch;  
}

/**
 * Adds Taxonomy callbacks to a BatchAPI operations array
 * @param $operations array() operations array with callbacks to process
 * @param $data array() with vocabulary and term data as given from the 
 * _erpal_taxonomy_get...() functions in erpal_taxonomy.inc  
 */
function _erpal_add_taxonomy_callbacks(&$operations, $data){
  $taxonomy = array_shift($data);
  $terms = array_chunk(array_shift($data), 5, TRUE);
  
  $index = 1;
  $parts = count($terms);
  foreach ($terms as $terms_chunk){
    $operations[] = array('erpal_taxonomy_add', array($taxonomy, $terms_chunk, $parts, $index));
    $index++;
  } 
}

function erpal_last_config_steps(){
  
  $operations = array(
    array('_erpal_rebuild_content_access', array()),
    array('_erpal_revert_features', array()),
    array('_erpal_config_finish', array()),
  );
    
  $batch = array(
    'title' => st('Performing last installation tasks'),
    'operations' => $operations,  
    'file' => drupal_get_path('profile', 'erpal') . '/erpal_callbacks.inc',
  );
  return $batch;

}

/**
 * Installation task "Contact information"
 * 
 */
function erpal_contact_information_form($form, &$form_state){
  drupal_set_title(st('Contact information'));
  
  $form = array();  
  $form['contact_name'] = array(
    '#type' => 'fieldset',
    '#title' => st('My Company'),
  );
  
  $form['contact_name']['company_name'] = array(
    '#type' => 'textfield',    
    '#title' => st('Company name:'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['company_address'] = array(
    '#type' => 'fieldset',
    '#title' => st('Main Address'),  
  );
  $form['company_address']['street'] = array(
    '#title' => st('Street:'),
    '#type' => 'textfield', 
    '#maxlength' => 255,
    '#required' => TRUE,     
  );
  $form['company_address']['zip_code'] = array(
    '#title' => st('ZIP-Code:'),
    '#type' => 'textfield',
    '#maxlength' => 10,
    '#required' => TRUE,
  );
  $form['company_address']['city'] = array(
    '#title' => st('City:'),
    '#type' => 'textfield',
    '#maxlength' => 80,
    '#required' => TRUE,
  );
  
  $countries = _erpal_get_countries();
  
  $form['company_address']['country'] = array(
    '#title' => st('Country'),
    '#type' => 'select',
    '#options' => $countries,
    '#default_value' => array_search('Germany', $countries),
  );
  
  $form['company_address']['vat_rate'] = array(
    '#title' => st('Default VAT rate'),
    '#type' => 'textfield',
    '#description' => st('Enter the default VAT rate in percent for your country!'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );    
    
  $form['contact_information'] = array(
    '#type' => 'fieldset',
    '#title' => st('Contact information'),
  );
  $form['contact_information']['phone_number'] = array(
    '#title' => st('Phone number:'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['contact_information']['email_address'] = array(
    '#title' => st('Email:'),
    '#type' => 'textfield',
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  
  $form['submit'] = array(
    '#value' => st('Save and continue'),
    '#type' => 'submit',
  );
  
  
  return $form;
}

function erpal_contact_information_form_validate($form, $form_state){
  $values = $form_state['values'];
  
  if(!valid_email_address($values['email_address']))
    form_set_error('email_address', st('The Email-address is not valid!'));
  
  if(!is_numeric($values['vat_rate']))
    form_set_error('vat_rate', st('The VAT rate has to be a numeric value!'));
  
}


function erpal_contact_information_form_submit($form, $form_state){
  
  module_load_include('inc', 'entity', 'includes/entity.controller');
  
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

  $address = entity_create('field_collection_item', array('field_name' => 'field_addresses'));
  $address->setHostEntity('node', $node);
  $address->field_street[LANGUAGE_NONE][0]['value'] = $values['street'];
  $address->field_zip_code[LANGUAGE_NONE][0]['value'] = $values['zip_code'];
  $address->field_city[LANGUAGE_NONE][0]['value'] = $values['city'];
  $address->field_country_term[LANGUAGE_NONE][0]['tid'] = $values['country'];
  $address->save(TRUE);

  $phone_number = entity_create('field_collection_item', array('field_name' => 'field_phone'));
  $phone_number->setHostEntity('node', $node);
  $phone_number->field_phone_number[LANGUAGE_NONE][0]['value'] = $values['phone_number'];
  $phone_number->save(TRUE);
  
  node_save($node);
  
  // Set configuration for Erpal_basic_helper
  variable_set('erpal_config_my_company_nid', $node->nid);
  variable_set('my_field_addresses', 0);  //set field 0 as default
  variable_set('my_field_phone', 0);  //      ""  
  variable_set('my_field_email', $values['email_address']);  //save email address
  
  
  // create Internal work project:
  $project_node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name)) ? $user->name : '',
    'type' => 'erpal_project',
    'language' => LANGUAGE_NONE,  
    'title' => 'Internal work',
    'field_customer_ref' => array(
      LANGUAGE_NONE => array(
        0 => array('target_id' => $node->nid,),
      ),
    ),
  );
  node_object_prepare($project_node); 
  node_save($project_node);
  variable_set('crm_tasks_project', $project_node->nid);
  
  
  
    // create "Work on CRM activities" task:
  module_load_include('module', 'erpal_basic_helper');
  
  $priority_vid = _erpal_basic_helper_term_field_get_vid('field_priority_term'); 
  $priority_default_tid = _erpal_basic_helper_get_default_tid($priority_vid);  
  
  $task_status_vid = _erpal_basic_helper_term_field_get_vid('field_task_status_term'); 
  $task_status_default_tid = _erpal_basic_helper_get_default_tid($task_status_vid);
  
  $task_type_vid = _erpal_basic_helper_term_field_get_vid('field_task_type_term'); 
  $task_type_default_tid = _erpal_basic_helper_get_default_tid($task_type_vid);
  
  $task_node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name)) ? $user->name : '',
    'type' => 'erpal_task',
    'language' => LANGUAGE_NONE,  
    'title' => 'Work on CRM activities',
    'field_project_ref' => array(
      LANGUAGE_NONE => array(
        0 => array('target_id' => $project_node->nid,),
      ),
    ),
    'field_priority_term' => array(
	  LANGUAGE_NONE => array(
	  	0 => array('tid' => $priority_default_tid),
	  ),
	),
	'field_task_status_term' => array(
	  LANGUAGE_NONE => array(
	  	0 => array('tid' => $task_status_default_tid),
	  ),
	),
	'field_task_type_term' => array(
	  LANGUAGE_NONE => array(
	  	0 => array('tid' => $task_type_default_tid),
	  ),
	),
  );
  node_object_prepare($task_node); 
  node_save($task_node);
  variable_set('crm_tasks_task', $task_node->nid);
  
  
  $vat_string = $values['vat_rate'] . '#' . $values['vat_rate'] . '%';
  
  variable_set('erpal_invoice_vat_rates_string', $vat_string);
  variable_set('erpal_invoice_default_vat_rate', (float) $vat_string);
  
  
  
}

function _erpal_get_countries(){
  $countries_vocabulary = taxonomy_vocabulary_machine_name_load('countries');
  $countries_terms = taxonomy_get_tree($countries_vocabulary->vid, 0);
  $countries = array();
  foreach($countries_terms as $term){
    $countries[$term->tid] = $term->name;
  }  
  return $countries;
}
 