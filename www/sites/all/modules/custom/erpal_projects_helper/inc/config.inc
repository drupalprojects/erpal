<?php

/**
* @file here are all functions available that help to configure erpal in the erpal config form.
*/

/**
* Returns all the menu path for config of crm feature
*/
function _erpal_projects_helper_config_menu() {
  
  $items['admin/erpal/projects'] = array(
    'title' => 'ERPAL Projects',
    'page callback' => '_erpal_projects_helper_config_projects',    
    'access arguments' => array('config erpal projects'),
    'file' => 'inc/config.inc',
    'type' => MENU_LOCAL_TASK,
  );
  
  return $items;
}

/**
* Settings for the ERPAL CRM Feature
*/
function _erpal_projects_helper_config_projects() {
  $form = drupal_get_form('erpal_projects_helper_config_form');

  return $form;
}

/**
* Form to show all settings to configure ERPAL projects module
*/
function erpal_projects_helper_config_form($form, &$form_state) {

  $form = array();
  
  $form['budget_usage_warn'] = array(
    '#type' => 'textfield',
    '#title' => t('Warn at budget usage %'),
    '#description' => t('If budget usage is closed to this value a warning is shown and the trigger is called.'),
    '#size' => 5,
    '#default_value' => _erpal_projects_helper_budget_usage_warn(),
  );
  
  $print_options = array('html' => t('HTML output'), 'pdf' => t('As PDF'));
  $form['erpal_task_print_type'] = array(
    '#type' => 'radios',
    '#title' => t('How to print tasks'),
    '#options' => $print_options,
    '#default_value' => _erpal_projects_helper_task_print_type(),
  );
  
  $form['task_notifications'] = array(
    '#type' => 'fieldset',
    '#title' => t('Task notifications'),
    '#collapsible' => true,
    '#collapsed' => true,
  );
  
  $form['task_notifications']['erpal_task_update_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Message subject'),    
    '#default_value' => _erpal_projects_helper_task_update_subject(),
  );
  
  $form['task_notifications']['erpal_task_update_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message text'),    
    '#default_value' => _erpal_projects_helper_task_update_message(),
  );
  
  //add available tokens to the form
  //show available Tokens  
  if (module_exists('token')) {
    $form['task_notifications']['token_tree'] = array(
      '#theme' => 'token_tree',   
      '#token_types' => array('erpal_project_notifications'),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
      '#recursion_limit' => 1,
    );
  }
  
  $form['timetracking'] = array(
    '#type' => 'fieldset',
    '#title' => t('Timetracking'),
    '#collapsible' => true,
    '#collapsed' => true,
  );
  
  $form['timetracking']['timetracking_default_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Timetracking default title'),
    '#description' => t('This text will be used as default timetracking title on a task as subject'),
    '#default_value' => _erpal_projects_helper_get_timetracking_default_title(),
  );
  
  //add available tokens to the form
  //show available Tokens  
  if (module_exists('token')) {
    $form['timetracking']['token_tree'] = array(
      '#theme' => 'token_tree',   
      '#token_types' => array('erpal_task'),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
      '#recursion_limit' => 1,
    );
  }
  
  
  $form['status_terms_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit project status terms'), 'admin/structure/taxonomy/project_status_terms'),
  );
  
  $form['task_type_terms_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit task type terms'), 'admin/structure/taxonomy/task_type_terms'),
  );
  
  $form['task_status_terms_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit task status terms'), 'admin/structure/taxonomy/task_status_terms'),
  );
  
  $form['project_tags_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit project / task category terms'), 'admin/structure/taxonomy/project_tags'),
  );
  
  $form['priority_terms_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit priority terms'), 'admin/structure/taxonomy/priority_terms'),
  );
  
  _erpal_projects_helper_field_access_config_form($form);
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('save'),
  );
  
  return $form;
}

/**
* returns the default timetracking title with subject tokens
*/
function _erpal_projects_helper_get_timetracking_default_title() {
  return variable_get('timetracking_default_title', t('Work on task "[erpal_task:title]"'));
}

/**
* Validation callback of projects config form
*/
function erpal_projects_helper_config_form_validate($form, $form_state) {
  $values = $form_state['values'];
  $budget_usage_warn = trim($values['budget_usage_warn']);

  $out_of_range = false;
  if ($budget_usage_warn < 1 || $budget_usage_warn > 100)
    $out_of_range = true;
  
  if (!is_numeric($budget_usage_warn) || $out_of_range)
    form_set_error('budget_usage_warn', t('Please enter only numeric values between 1 and 100'));
}

/**
* Submit callback of projects config form
*/
function erpal_projects_helper_config_form_submit($form, $form_state) {
  $values = $form_state['values'];
  $budget_usage_warn = trim($values['budget_usage_warn']);
  $erpal_task_print_type = $values['erpal_task_print_type'];
  $erpal_task_update_subject = $values['erpal_task_update_subject'];
  $erpal_task_update_message = $values['erpal_task_update_message'];
  $timetracking_default_title = $values['timetracking_default_title'];
  
  variable_set('erpal_projects_budget_usage_warn', $budget_usage_warn);
  variable_set('erpal_task_print_type', $erpal_task_print_type);
  
  //notification messages
  variable_set('erpal_task_update_subject', $erpal_task_update_subject);
  variable_set('erpal_task_update_message', $erpal_task_update_message);
  
  //Timetracking
  variable_set('timetracking_default_title', $timetracking_default_title);
  
}

/**
* Returns the task print type
*/
function _erpal_projects_helper_task_print_type() {
  return variable_get('erpal_task_print_type', 'html');
}

/**
* Return the project budget warn treshold
*/
function _erpal_projects_helper_budget_usage_warn() {
  return variable_get('erpal_projects_budget_usage_warn', 90);
}

/**
* Returns the message text for task update notifications
*/
function _erpal_projects_helper_task_update_message() {
  return variable_get('erpal_task_update_message', false);
}

/**
* Returns the message subject for task update notifications
*/
function _erpal_projects_helper_task_update_subject() {
  return variable_get('erpal_task_update_subject', false);
}