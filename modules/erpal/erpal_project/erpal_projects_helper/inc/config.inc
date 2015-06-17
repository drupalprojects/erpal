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

  $form['budget'] = array(
    '#type' => 'fieldset',
    '#title' => t('Budget settings'),
    '#collapsible' => true,
    '#collapsed' => true,
  );
  
  $form['budget']['budget_usage_warn'] = array(
    '#type' => 'textfield',
    '#title' => t('Warn at budget usage %'),
    '#description' => t('If budget usage is closed to this value a warning is shown and the trigger is called. This can be individually set on projects and tasks.'),
    '#size' => 5,
    '#default_value' => _erpal_projects_helper_budget_usage_warn(),
  );
  
  $form['budget']['budget_usage_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject for budget email'),
    '#default_value' => _erpal_projects_helper_budget_usage_email_subject(),
  );
  
  $form['budget']['budget_usage_email_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body for budget email'),
    '#default_value' => _erpal_projects_helper_budget_usage_email_body(),
  );
  
  //add available tokens to the form
  //show available Tokens  
  if (module_exists('token')) {
    $form['budget']['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('erpal_project_budget'),
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
  
  $round_settings = _erpal_projects_helper_get_timetracking_round_settings();
  $form['timetracking']['timetracking_round_duration_steps'] = array(
    '#type' => 'textfield',
    '#title' => t('Round timetracking duration'),
    '#description' => t('Value in minutes where every timetracking duration will be round to.'),
    '#default_value' => $round_settings['duration'],
  );
  
  $form['timetracking']['timetracking_round_billing_duration_steps'] = array(
    '#type' => 'textfield',
    '#title' => t('Round timetracking billing duration'),
    '#description' => t('Value in minutes where every timetracking billing duration will be round to.'),
    '#default_value' => $round_settings['billing_duration'],
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


  $form['task_category_terms_edit_link'] = array(
    '#type' => 'item',
    '#markup' => l(t('Edit task and project category terms'), 'admin/structure/taxonomy/project_tags'),
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
  
  return system_settings_form($form);
}

/**
* Return the round settings for timetracking duration and billing duration in an array with both values
*/
function _erpal_projects_helper_get_timetracking_round_settings() {
  return array(
    'duration' => variable_get('timetracking_round_duration_steps', false),
    'billing_duration' => variable_get('timetracking_round_billing_duration_steps', false),
  );
}

/**
* Returns on which types (task or comment) update messages should be send right now)
*/
function _erpal_projects_helper_task_update_types() {
  return variable_get('erpal_task_update_types', array('comment_node_erpal_task'));
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
  $erpal_task_update_subject = $values['erpal_task_update_subject'];
  $erpal_task_update_message = $values['erpal_task_update_message'];
  $timetracking_default_title = $values['timetracking_default_title'];
  $erpal_task_update_types = $values['erpal_task_update_types'];
  $budget_usage_email_subject = $values['budget_usage_email_subject'];
  $budget_usage_email_body = $values['budget_usage_email_body'];
  
  variable_set('erpal_projects_budget_usage_warn', $budget_usage_warn); 

  //notification messages
  variable_set('erpal_task_update_subject', $erpal_task_update_subject);
  variable_set('erpal_task_update_message', $erpal_task_update_message);

  //Timetracking
  variable_set('timetracking_default_title', $timetracking_default_title);
  
  //Update types
  variable_set('erpal_task_update_types', $erpal_task_update_types);
  
  //Mail settings
  variable_set('budget_usage_email_subject', $budget_usage_email_subject);
  variable_set('budget_usage_email_body', $budget_usage_email_body);
  
}

/**
* Return the project budget warn treshold
*/
function _erpal_projects_helper_budget_usage_warn() {
  return variable_get('erpal_projects_budget_usage_warn', 90);
}

/**
* Return the project budget email subject
*/
function _erpal_projects_helper_budget_usage_email_subject() {
  $text = t('Budget [erpal_project_budget:budget_status] in [erpal_project_budget:budget_project_title]');
  return variable_get('budget_usage_email_subject', $text);
}

/**
* Return the project budget email body
*/
function _erpal_projects_helper_budget_usage_email_body() {
  $text = t('The budget for [erpal_project_budget:budget_project_link] is [erpal_project_budget:budget_status]

You will find the budget added to [erpal_project_budget:budget_node_link]');
  return variable_get('budget_usage_email_body', $text);
}