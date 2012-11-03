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
  
  variable_set('erpal_projects_budget_usage_warn', $budget_usage_warn);
  variable_set('erpal_task_print_type', $erpal_task_print_type);
  
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