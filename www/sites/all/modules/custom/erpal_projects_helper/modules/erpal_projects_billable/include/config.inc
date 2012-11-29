<?php

/**
* @file here are all functions available that help to configure erpal in the erpal config form.
*/

/**
* Returns all the menu path for config of crm feature
*/
function erpal_projects_billable_invoice_config_alter(&$form, &$form_state) {
  if (!isset($form['billable_texts'])) {
    $form['billable_texts'] = array(
      '#type' => 'fieldset',
      '#title' => t('Billable texts'),
      '#collapsible' => true,
      '#collapsed' => true,
      '#weight' => -3,
    );
  }
  
  $form['billable_texts']['project_billable_texts'] = array(
    '#type' => 'textfield',
    '#title' => t('Project billable texts'),
    '#description' => t('This text will be used as subject for billables in project context.'),
    '#default_value' => _erpal_projects_billable_get_billable_text('erpal_project'),
    '#maxlength' => 255,
  );
  
  $form['billable_texts']['task_billable_texts'] = array(
    '#type' => 'textfield',
    '#title' => t('Task billable texts'),
    '#description' => t('This text will be used as subject for billables in task context.'),
    '#default_value' => _erpal_projects_billable_get_billable_text('erpal_task'),
    '#maxlength' => 255,
  );
  
  $form['billable_texts']['timetracking_billable_texts'] = array(
    '#type' => 'textfield',
    '#title' => t('Timetracking billable texts'),
    '#description' => t('This text will be used as subject for billables in timetracking context.'),
    '#default_value' => _erpal_projects_billable_get_billable_text('erpal_timetracking'),
    '#maxlength' => 255,
  );
  
  //add available tokens to the form
  //show available Tokens  
  if (module_exists('token')) {
    $form['billable_texts']['token_tree'] = array(
      '#theme' => 'token_tree',   
      '#token_types' => array('erpal_projects_billable_subject'),
      '#global_types' => FALSE,
      '#click_insert' => TRUE,
      '#recursion_limit' => 1,
    );
  }
  
  $form['submit']['#validate'][] = '_erpal_projects_billable_erpal_invoice_helper_config_form_validate';
  $form['submit']['#submit'][] = '_erpal_projects_billable_erpal_invoice_helper_config_form_submit';
  
}

/**
* Additinal validation handler for form "erpal_invoice_helper_config_form"
*/
function _erpal_projects_billable_erpal_invoice_helper_config_form_validate($form, &$form_state) {
  $values = $form_state['values'];
}

/**
* Additinal submit handler for form "erpal_invoice_helper_config_form"
*/
function _erpal_projects_billable_erpal_invoice_helper_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $project_billable_texts = $values['project_billable_texts'];
  variable_set('erpal_billable_text_erpal_project', $project_billable_texts);
  
  $task_billable_texts = $values['task_billable_texts'];
  variable_set('erpal_billable_text_erpal_task', $task_billable_texts);
  
  $timetracking_billable_texts = $values['timetracking_billable_texts'];
  variable_set('erpal_billable_text_erpal_timetracking', $timetracking_billable_texts);
  
}

/**
* Gget the text for billable of different node types
*/
function _erpal_projects_billable_get_billable_text($node_type) {
  $types = node_type_get_types();
  $default_text = $types[$node_type]->name;
  if ($node_type == 'erpal_project') 
    $default_text = t('Project development on "!token"', array('!token' => '[erpal_projects_billable_subject:project_subject]'));
  if ($node_type == 'erpal_task')
    $default_text = t('Project development on "[erpal_projects_billable_subject:project_subject]"');
  if ($node_type == 'erpal_timetracking')
    $default_text = t('!type on task', array('!type' => $default_text));
  return variable_get('erpal_billable_text_'.$node_type, $default_text);
}