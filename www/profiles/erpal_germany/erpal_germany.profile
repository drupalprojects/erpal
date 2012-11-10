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
}
/**
 *
 * Zusaetzliche installationsaufgaben definieren
 *
 */
function erpal_germany_install_tasks(){
  return array(
    //~ 'file_system_settings_form' => array(
      //~ 'display_name' => st('Configure filesystem'),
      //~ 'desplay' => TRUE,
      //~ 'type' => 'normal',
      //~ ),
    //~ 'company_info_form' => array(
      //~ 'display_name' => st('Set the name and address of your company'),
      //~ 'display' => TRUE,
      //~ 'type' => 'normal',
      //~ ),
    //~ 'erpal_config_step1_form' => array(
      //~ 'display_name' => st('Configure Erpal Step 1'),
      //~ 'display' => TRUE,
      //~ 'type' => 'form',
      //~ ),
    //~ 'erpal_config_step2_form' => array(
      //~ 'display_name' => st('Configure Erpal Step 2'),
      //~ 'display' => TRUE,
      //~ 'type' => 'form',
      //~ ),
    //~ 'erpal_config_step3_form' => array(
      //~ 'display_name' => st('Configure Erpal Step 3'),
      //~ 'display' => TRUE,
      //~ 'type' => 'form',
      //~ ),
    );
}

/**
 * Installation task "Configure Filesystem"
 * 
 */
function file_system_settings_form(){
  drupal_set_title(st('Set filesystem settings'));
  $form = drupal_get_form('system_file_system_settings'); 
  $form['submit'][] = 'file_system_settings_form_submit'; 
  return drupal_render($form);
}

function file_system_settings_form_submit($form, $form_state){
  dpm('file_system_setting_form_submit()');
  
  }

/**
 * Installation task "Set the name and address of your company"
 * 
 */ 
function company_info_form($form_state){
  $node_type = 'erpal_contact';
  $form_id = $node_type . '_node_form';
  // Node anlegen
  $node = new stdClass();
  $node->type = $node_type;
  global $user;
  $node->uid = $user->uid;
  $node->name = (isset($user->name) ? $user->name : '');  
  // Formular erzeugen
  $form = drupal_get_form($form_id, $node);
  // Disable the Relation add widget
  //unset($form['field_relation_add']['#access']);
  $form['field_relation_add']['#access'] = FALSE;
  $form['#submit'] = array('company_info_form_submit');

  // Formular rendern
  return drupal_render($form);
}

function company_info_form_submit($form, $form_state){
  // Save the new contact as "My Company"
  dpm($form_state);
  erpal_contact_node_form_submit($form, $form_state);
  drupal_set_message('company_info_form_submit()');
  $nid = $form_state['values']['nid'];
  variable_set('erpal_config_my_company_nid', $nid);
  $form_state['rebuild'] = TRUE;
  $form_state['redirect'] = url('admin', array('absolute' => true));
  
}


/**
 * Installation task "Erpal configuration"
 * 
 */
function erpal_config_step1_form(){
  drupal_set_title(st('Erpal configuration'));
  $form = array();
  $form['erpal_basic'] = drupal_get_form('erpal_basic_helper_config_form');
  unset($form['erpal_basic']['submit']);
  $form['erpal_book'] = drupal_get_form('erpal_book_helper_config_form');
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    );
    
  return $form;
}

function erpal_config_step1_form_submit($form, $form_state){
  erpal_basic_helper_config_form_submit($form['erpal_basic'], $form_state['erpal_basic']);
  erpal_book_helper_config_form_submit($form['erpal_book'], $form_state['erpal_book']);
}

function erpal_config_step2_form(){
  drupal_set_title(st('Erpal configuration'));
  $form = array();
  $form[] = drupal_get_form('erpal_calendar_helper_config_form');
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    );
  return $form;
}

function erpal_config_step3_form(){
  drupal_set_title(st('Erpal configuration'));
  $form = array();
  $form = drupal_get_form('erpal_docs_helper_config_form');
  unset($form['submit']);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    );
  return $form;
}






