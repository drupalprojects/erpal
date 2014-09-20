<?php
/**
 * @file
 * Enables modules and site configuration for a erpal site installation.
 */
 include_once 'install_from_db/install_from_db.profile';
 define('MAX_ALLOWED_PACKET_SIZE_MIN', 20);  //minimum value of max allowed packet size in MB for installation process
 
/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function erpal_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  
  // Add textfield for private filesystem settings
  if (!drupal_is_cli()) {
    $form['filesystem_settings'] = array(
      '#title' => st('Filesystem settings'),
      '#type' => 'fieldset',
    );
   
    $form['filesystem_settings']['file_private_path'] = array(
      '#type' => 'textfield', 
      '#title' => st('Private file system path'), 
      '#default_value' => variable_get('file_private_path', conf_path().'/files/private'), 
      '#maxlength' => 255,
      '#required' => TRUE, 
    );

    $form['#validate'][] = 'erpal_file_private_path_validate';
    $form['#submit'][] = 'erpal_file_private_path_submit';
  }
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
function erpal_install_tasks(&$install_state){
  
  $tasks = array();
  
  drupal_get_messages('status', TRUE); //remove all messages we don't need them
  
  $tasks['_erpal_revert_features'] = array(
    'display_name' => st('Reverting features'),
    'display' => TRUE,
    'type' => 'batch',
    'file' => 'erpal_callbacks.inc',
  );
  
  $tasks['erpal_create_vocabularies_and_taxonomies'] = array(
    'display_name' => st('Creating taxonomies'),
    'display' => TRUE,
    'type' => 'batch',
  );
  if (!drupal_is_cli()) {
    $tasks['erpal_contact_information_form'] = array(
      'display_name' => st('Contact information'),
      'display' => TRUE,
      'type' => 'form',
    );
  }
  $tasks['erpal_preconfigure_site'] = array(
    'display_name' => st('Preparing site'),
    'display' => TRUE,
    'type' => 'batch',
  );
  
  $tasks['erpal_last_config_steps'] = array(
    'display_name' => st('Last steps'),
    'display' => TRUE, 
    'type' => 'batch',
  );
  
  return $tasks;
}

/**
* Batch function callback to revert a feature
 * @param $feature is an array with key as feature name and value an array of components
 */
function _erpal_revert_feature($feature_name, &$context) {
  features_revert_module($feature_name);
  $context['message'] = st("Reverted feature '$feature_name'");
}

/**
 * BatchAPI callback
 * reverts all features
 */ 
function _erpal_revert_features(&$context){
  if (_erpal_is_quickinstall()) {
    return array();  //nothing todo here.
  }
  
  module_load_include('inc', 'features', 'features.export');
  features_include();
  $context['message'] = st('Reverted all features');
  
  $operations = array();
  
  //for each feature add an operation to the batch process
  $states = features_get_component_states(array(), FALSE, TRUE);
  foreach ($states as $feature_name => $components) {
    $operations[] = array('_erpal_revert_feature', array($feature_name));
  }

  $batch = array(
    'title' => st('Reverting feature'),
    'operations' => $operations,
  );
  return $batch;
}

/**
* Checks if this is a quick install or a full install
*/
function _erpal_is_quickinstall() {
  global $install_state;  
  $quickstart_state = !empty($install_state['parameters']['quickstart']) ? $install_state['parameters']['quickstart'] : false;
  $quickstart_get = !empty($_GET['quickstart']) ? $_GET['quickstart'] : false;
  
  if ($quickstart_state)
    return $quickstart_state;
    
  return $quickstart_get;
}

/**
 * Implements hook_install_tasks_alter().
 */
function erpal_install_tasks_alter(&$tasks, $install_state) {
  
   install_from_db_install_tasks_alter($tasks, $install_state);
  
  $tasks['install_select_profile']['display'] = FALSE;
  if (!drupal_is_cli()) {
    $welcome['erpal_welcome_message'] = array(
      'display_name' => st('Welcome'),
      'display' => TRUE,
      'type' => 'form',
      'run' => isset($install_state['parameters']['welcome']) ? INSTALL_TASK_SKIP : INSTALL_TASK_RUN_IF_REACHED,
    );
    
    _erpal_install_tasks_inject_database_requirements($tasks, $install_state);
    
    $old_tasks = $tasks;
  $tasks = array_slice($old_tasks, 0, 1) + $welcome+ array_slice($old_tasks, 1);
  }
  _erpal_set_theme('erpal_maintenance');
}

/**
* Inject database check for additional requirements, after adding database information
*/
function _erpal_install_tasks_inject_database_requirements(&$tasks, $install_state) {

  $new_tasks = array();
  foreach ($tasks as $task_name => $task) {
    $new_tasks[$task_name] = $task;
    if ($task_name == 'install_settings_form') {
      //add additional task before all features are reverted and ensure database settings are "strong" enough
      $new_tasks['_erpal_install_verify_db_requirements'] = array(
        'display_name' => 'Verify DB requirements',
        'type' => 'form',
        'display' => TRUE,
      );
    }
  }
  
  $tasks = $new_tasks;
}

/**
* Returns the max allowed packet size in MB
*/
function _erpal_install_get_mysql_max_allowed_packet_size() {
  $res = db_query('SELECT @@global.max_allowed_packet AS value');
  $result = $res->fetchAssoc();
  
  $ret = 0;
  if (!empty($result['value'])) {
    $ret = $result['value'] / (1024 * 1024);
  }
  
  return $ret;
}

/**
* Tries to set the max allowed packet size to the minimum value
*/
function _erpal_install_set_mysql_max_allowed_packet_size() {
  db_query('SET @@global.max_allowed_packet = '.MAX_ALLOWED_PACKET_SIZE_MIN * 1024 * 1024);
}

/**
* Test database requirements especially max_allowed_packet size
*/
function _erpal_install_verify_db_requirements() {
  
  global $install_state;
  $install_state['parameters']['verify_db_requirements'] = 'done';
  
  $form = array();
  
  //check the requirements
  $driver = db_driver();
  $is_mysql = $driver == 'mysql';
  
  $req_ok = true;
  $tried_to_set = false;
  $min_value = MAX_ALLOWED_PACKET_SIZE_MIN;
  if ($is_mysql) {
    //check if the database has correct configuration with enough power for installation
    
    $max_allowed_packet_size = _erpal_install_get_mysql_max_allowed_packet_size();
    if ($max_allowed_packet_size && $max_allowed_packet_size < $min_value) {
    
      $req_ok = false;
    }
  }
  
  //currently only verify requirements for mysql
  $form['req_ok'] = array(
    '#type' => 'value',
    '#value' => $req_ok,
  );
  
  $problems = 'MAX_ALLOWED_PACKET size is lower than '.$min_value." MB. Current value is ".$max_allowed_packet_size." MB";
  if ($req_ok) { 
    $form['explain'] = array(
      '#type' => 'markup',
      '#markup' => st('Your database is configured to install ERPAL now.'),
    );
    
    $button_text = st('Continue');
  } else {
    
    $form['explain'] = array(
      '#type' => 'markup',
      '#markup' => st("Your database configuration does not match the installation requirements.<br/><br/><b>".$problems."</b>"),
    );
    
    $form['warn_db'] = array(
      '#type' => 'checkbox',
      '#title' => st('Yes, I know that there may appear some problems with these database settings, and I want to PROCEED ANYWAY.'),
    );
    
    $button_text = st('Proceed anyway');
    
    $form['try_fix'] = array(
    '#type' => 'submit',
    '#value' => st('Try to change this value'),
    );
  }
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $button_text,
  );
  
  return $form;
}

function _erpal_install_verify_db_requirements_validate($form, &$form_state) {
  global $install_state;
  $install_state['parameters']['verify_db_requirements'] = 'done';
  
  $values = $form_state['values'];
  
  if (!empty($form['try_fix']['#value'])) {
    if ($form_state['clicked_button']['#value'] == $form['try_fix']['#value']) {
      //try to fix the problem and if it works proceed, otherwise show message again with form error
      _erpal_install_set_mysql_max_allowed_packet_size();
      
      //check again if it didn't work, show error
      $value = _erpal_install_get_mysql_max_allowed_packet_size();
      if ($value < MAX_ALLOWED_PACKET_SIZE_MIN) {
        //sorry but the value could not be changed
        form_set_error('try_fix', st('Sorry, but it was not possible to change the value automatically.'));
      }
      
    } else {
      if (empty($values['warn_db']) && !$values['req_ok']) {
        form_set_error('warn_db', st('Please confirm that you are aware of problems that may occur during installation!'));
      }
    }
  }

  
}

function _erpal_install_verify_db_requirements_submit($form, &$form_state) {
  global $install_state;
  
  if (!empty($form['try_fix']['#value'])) {
    if ($form_state['clicked_button']['#value'] == $form['try_fix']['#value']) {
      drupal_set_message(st('The database configuration was updated successfully!'));
    }
  } 
 
}


function erpal_welcome_message($form, $form_state){
  drupal_set_title(st('Welcome'));
  $welcome = st('<p>The following steps will guide you through the installation '
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
  // Prepare directories for term_images
  $operations[] = array('_erpal_taxonomy_prepare_directory', array());
  
  $is_quick_install = _erpal_is_quickinstall();
  
  if ($is_quick_install) {    
    //only copy the images as needed.
    $operations[] = array('_erpal_taxonomy_copy_images', array());
    $batch = array(
      'title' => st('Copy taxonomy images'),
      'operations' => $operations,
      'file' => drupal_get_path('profile', 'erpal') . '/erpal_taxonomy.inc',
    );
  } else {
    //add all the single terms
    
    $operations = array();
    
    // Create Taxonomies
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_service_category_vocabulary());
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_priority_vocabulary());
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_number_type_vocabulary());
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_address_type_vocabulary());
    
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_task_status_vocabulary());
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_task_type_vocabulary());  
    
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_project_status_vocabulary());
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_project_tags_vocabulary());
    
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_countries_vocabulary());
    
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_activity_origin_vocabulary());
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_activity_status_vocabulary());
    
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_date_item_vocabulary());

    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_target_audience_vocabulary());
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_salutation_terms_vocabulary());
    
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_project_role_tags_vocabulary());
    _erpal_add_taxonomy_callbacks($operations, _erpal_taxonomy_get_activity_lost_reasons_vocabulary());
    
    $batch = array(
      'title' => st('Creating taxonomies'),
      'operations' => $operations,
      'file' => drupal_get_path('profile', 'erpal') . '/erpal_taxonomy.inc',
    );
  }
  
  return $batch;  
}

function erpal_preconfigure_site(){
  $operations = array();
      
  $quick_install = _erpal_is_quickinstall();    
  if ($quick_install == 'demo') {    
    return $operations;
  }
  elseif ($quick_install == 'quick') {
    //nothing todo here
    return $operations;
  }  
      
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
  $terms = array_chunk(array_shift($data), 3, TRUE);
  
  $index = 1;
  $parts = count($terms);
  foreach ($terms as $terms_chunk){
    $operations[] = array('erpal_taxonomy_add', array($taxonomy, $terms_chunk, $parts, $index));
    $index++;
  } 
   
}

function erpal_last_config_steps(){
  
  $operations = array();
  $quick_install = _erpal_is_quickinstall();    
  
  if (!$quick_install) {
    $operations[] = array('_erpal_rebuild_content_access', array());
  }  
  
  if ($quick_install == 'demo') {
    _erpal_reset_demo_date_items_batch($operations);
    $operations[] = array('_erpal_create_demo_date', array());    
    $operations[] = array('_install_from_db_reimport_demo_users', array());    
  }
  
  $operations[] = array('_erpal_config_finish', array());    
  
  $operations[] = array('_erpal_install_cleanup', array());
    
  $batch = array(
    'title' => st('Performing last installation tasks'),
    'operations' => $operations,  
    'file' => drupal_get_path('profile', 'erpal') . '/erpal_callbacks.inc',
  );
  return $batch;

}


/**
* Reset date items in a batch process, split into chunks
*/
function _erpal_reset_demo_date_items_batch(&$operations) { 
  //now get all date items
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'date_item');    
  $result = $query->execute();

  if (isset($result['date_item'])) {      
    $params = array();
    $junks = 3;
    foreach ($result['date_item'] as $id => $obj) {  
      $params[] = $obj->date_item_id;
      if (count($params) == $junks) {
        $operations[] = array('erpal_reset_demo_date_items_callback', array($params));
        $params = array();
      }
    }
    
    if (!empty($params)) {
      $operations[] = array('erpal_reset_demo_date_items_callback', array($params));
    }
  }
 
}

/**
 * Installation task "Contact information"
 * 
 */
function erpal_contact_information_form($form, &$form_state){
  drupal_set_title(st('Contact information'));
  
  $quick_install = _erpal_is_quickinstall();
  $form = array();  
  
  if ($quick_install == 'demo') {
    //demo installation will take all data from the dump so nothing todo here
    $form['hint'] = array(
      '#type' => 'markup',    
      '#markup' => 'The contact information will be taken from the demo content',
    );
  } else {
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
      '#title' => st('Postal Code:'),
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
    
    $form['company_address']['currency'] = array(
      '#title' => st('Default currency'),
      '#type' => 'textfield',
      '#description' => st('Enter the default currency shortcode like USD or EUR.'),
      '#maxlength' => 5,
      '#required' => TRUE,
    );  
    
    $form['company_address']['vat_rate'] = array(
      '#title' => st('Default tax rate'),
      '#type' => 'textfield',
      '#description' => st('Enter the default tax rate in percent for your country.'),
      '#maxlength' => 5,
      '#required' => TRUE,
    );    
    
    $form['company_address']['vat_label'] = array(
      '#title' => st('Default tax name'),
      '#type' => 'textfield',
      '#description' => st('Enter the name of your default tax in your country.'),
      '#maxlength' => 25,
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
  }
  
  $form['submit'] = array(
    '#value' => st('Save and continue'),
    '#type' => 'submit',
  );
  
  return $form;
}

function erpal_contact_information_form_validate($form, $form_state){
  $quick_install = _erpal_is_quickinstall();
  if ($quick_install == 'demo') {
    return; //no validation needed here if demo content is installed
  }
  
  $values = $form_state['values'];
  
  if(!valid_email_address($values['email_address']))
    form_set_error('email_address', st('The Email-address is not valid!'));
  
  if(!is_numeric($values['vat_rate']))
    form_set_error('vat_rate', st('The tax rate has to be a numeric value!'));
  
}

/**
* Save contact information and some default content.
*/
function erpal_contact_information_form_submit($form, $form_state){
  
  module_load_include('inc', 'entity', 'includes/entity.controller');
  
  $quick_install = _erpal_is_quickinstall();
  
  if ($quick_install == 'demo') {
    //demo content installation, so nothing to do here.
    return;
  }
  
  if ($quick_install == 'quick') {
    //delete all existing nodes, they will be recreated.
    $result = db_select('node', 'n')
    ->fields('n', array('nid'))   
    ->execute();

    $customers = array();
    while($record = $result->fetchAssoc()) {
      $nid = $record['nid'];      
      node_delete($nid);      
    }
    
  } 
  //normal installation
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

  //add phone number
  $collection = entity_create('field_collection_item', array('field_name' => 'field_communication'));
  $collection->setHostEntity('node', $node);
  $collection_wrapper = entity_metadata_wrapper('field_collection_item', $collection);
  $collection_wrapper->field_communication_type->set('phone');
  $collection_wrapper->field_communication_address->set($values['phone_number']);
  $collection->save(TRUE);
  
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
  
  //set vat rate
  $vat_label = !empty($values['vat_label']) ? $values['vat_label'] : 'Tax';
  $vat_string = $values['vat_rate'] . '#' . $values['vat_rate'] . '% '.$vat_label;
  variable_set('erpal_invoice_vat_rates_string', $vat_string);
  $vat_rate = number_format((float)$values['vat_rate'], 3);
  variable_set('erpal_invoice_default_vat_rate', $vat_rate);
  
  //set currency
  $currency_string = $values['currency'] . '#' . $values['currency'];
  variable_set('erpal_invoice_currencies_string', $currency_string);
  variable_set('erpal_invoice_default_currency', $values['currency']);

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

/**
 * Implements hook_update_projects_alter().
 */
function erpal_update_projects_alter(&$projects) {
  // Enable update status for the erpal profile.
  $modules = system_rebuild_module_data();
  // The module object is shared in the request, so we need to clone it here.
  $erpal = clone $modules['erpal'];
  $erpal->info['hidden'] = FALSE;
  _update_process_info_list($projects, array('erpal' => $erpal), 'module', TRUE);
}

/**
 * Implements hook_update_status_alter().
 *
 * Disable reporting of projects that are in the distribution, but only
 * if they have not been updated manually.
 *
 * Projects with insecure / revoked / unsupported releases are only shown
 * after two days, which gives enough time to prepare a new erpal release
 * which the users can install and solve the problem.
 */
function erpal_update_status_alter(&$projects) {
  $bad_statuses = array(
    UPDATE_NOT_SECURE,
    UPDATE_REVOKED,
    UPDATE_NOT_SUPPORTED,
  );

  $make_filepath = drupal_get_path('module', 'erpal') . '/drupal-org.make';
  if (!file_exists($make_filepath)) {
    return;
  }

  $make_info = drupal_parse_info_file($make_filepath);
  foreach ($projects as $project_name => $project_info) {
    // Never unset the drupal project to avoid hitting an error with
    // _update_requirement_check(). See http://drupal.org/node/1875386.
    
    // Hide erpal projects, they have no update status of their own.
    if (strpos($project_name, 'erpal_') !== FALSE) {
      
      unset($projects[$project_name]);
    }
    
    if ($project_name == 'drupal' || !isset($project_info['releases']) || !isset($project_info['recommended'])) {
      continue;
    }
    
    // Hide bad releases (insecure, revoked, unsupported) if they are younger
    // than 5 days (giving erpal time to prepare an update).
    elseif (isset($project_info['status']) && in_array($project_info['status'], $bad_statuses)) {
      $two_days_ago = strtotime('5 days ago');
      if ($project_info['releases'][$project_info['recommended']]['date'] < $two_days_ago) {
        unset($projects[$project_name]);
      }
    }
    // Hide projects shipped with erpal if they haven't been manually
    // updated. We also hide patched modules
    elseif (isset($make_info['projects'][$project_name])) {
      $version = !empty($make_info['projects'][$project_name]['version']) ? $make_info['projects'][$project_name]['version'] : '';
      
      //has it patches applied?
      if (!empty($make_info['projects'][$project_name]['patch']) && count($make_info['projects'][$project_name]['patch'])) {
        unset($projects[$project_name]);
      }
      
      //if not manually updated than also hide
      if (strpos($version, 'dev') !== FALSE || strpos($version, 'erpal') !== FALSE || (DRUPAL_CORE_COMPATIBILITY . '-' . $version == $project_info['info']['version'])) {
        unset($projects[$project_name]);
      }
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Disable the update for ERPAL.
 */
function erpal_form_update_manager_update_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['projects']['#options']) && isset($form['projects']['#options']['erpal'])) {
    if (count($form['projects']['#options']) > 1) {
      unset($form['projects']['#options']['erpal']);
    }
    else {
      unset($form['projects']);
      // Hide Download button if there's no other (disabled) projects to update.
      if (!isset($form['disabled_projects'])) {
        $form['actions']['#access'] = FALSE;
      }
      $form['message']['#markup'] = t('All of your projects are up to date.');
    }
  }
}
 
