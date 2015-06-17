<?php

/**
* Functions for erpal crm tasks config form
*/

function _erpal_crm_tasks_crm_config_form_alter(&$form, &$form_state) {
  //add elements to choose a project and tasks for activities
  $form['crm_tasks'] = array(
    '#type' => 'fieldset',
    '#title' => t('CRM Tasks settings'),
    '#collapsible' => true,
    '#collapsed' => false,
  );
  
  $projects = _erpal_projects_helper_get_projects();
  $project_nid = variable_get('crm_tasks_project', false);
  $form['crm_tasks']['crm_tasks_project'] = array(
    '#type' => 'select',
    '#title' => t('Project'),
    '#options' => $projects,
    '#default_value' => $project_nid,
    '#description' => t('This is the project for internal tasks where activity tasks will be added. Click "Save configuration" to select an optional task'),
  );
  
  if ($project_nid) {
    //if a project is selected, show tasks of the project
    $task_nids = _erpal_projects_helper_get_tasks_by_project($project_nid);
    $tasks = erpal_lib_helper_node_titles($task_nids);
    $tasks[0] = ' ';
    $form['crm_tasks']['crm_tasks_task'] = array(
      '#type' => 'select',
      '#title' => t('Parent task'),
      '#options' => $tasks,
      '#default_value' => variable_get('crm_tasks_task', false),
      '#description' => t('This is the optional parent task where activity tasks will be added.'),
    );
    
    $form['crm_tasks']['crm_tasks_create_on_insert'] = array(
      '#type' => 'checkbox',
      '#title' => t('Create and add CRM task on insert'),
      '#default_value' => _erpal_crm_tasks_create_on_insert(),
      '#description' => t('If checked, a new task will be created and added to the activity if activity is created'),
    );
    
    $form['crm_tasks']['crm_tasks_create_on_update'] = array(
      '#type' => 'checkbox',
      '#title' => t('Create and add CRM task on update'),
      '#default_value' => _erpal_crm_tasks_create_on_update(),
      '#description' => t('If checked, a new task will be created and added to the activity if activity is updated an has not yet a task assigned'),
    );
  }
  
  //stati mappings from crm status to task status
  $form['crm_task_stati'] = array(
    '#type' => 'fieldset',
    '#title' => t('Activity status to task status mapping'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );
  
  $crm_stati_vocab = taxonomy_vocabulary_machine_name_load('activity_status_terms');
  $crm_stati = taxonomy_get_tree($crm_stati_vocab->vid);
  $task_stati_vocab = taxonomy_vocabulary_machine_name_load('task_status_terms');
  $task_stati = taxonomy_get_tree($task_stati_vocab->vid);
  foreach ($crm_stati as $status_term) {
    //create the options
    $options = array(FALSE => t('No mapping - no change'));
    foreach ($task_stati as $task_term) {
      $options[$task_term->tid] = $task_term->name;
    }
    
    $form['crm_task_stati'][$status_term->tid] = array(      
      '#type' => 'select',
      '#title' => t('Map CRM actitiy status "!status" to', array('!status' => $status_term->name)),
      '#options' => $options,
      '#default_value' => _erpal_crm_tasks_get_task_status_for_activity_status($status_term->tid),
    );
  }
  
  $form['erpal_crm_tasks_enable_task_activity_mapping'] = array(
    '#type' => 'checkbox',    
    '#title' => t('Enable the mapping automation between CRM activity status and task status for activity related tasks.'),
    '#default_value' => variable_get('erpal_crm_tasks_enable_task_activity_mapping', TRUE),
  );
  
  $form['#submit'] = array('_erpal_crm_tasks_config_form_submit', '_erpal_crm_reports_config_form_submit');  //we dont want to save all values in variables, so set out own handler @TODO this will prevent other modules from adding their handler...
}

/**
* Submithandler to create the mapping and removes the values so they are not processed and saved by the following system settings form submit handler
*/
function _erpal_crm_tasks_config_form_submit($form, &$form_state) {
  $values = $form_state['values']; 

  variable_set('crm_tasks_project', !empty($values['crm_tasks_project']) ? $values['crm_tasks_project'] : FALSE);
  variable_set('crm_tasks_task', !empty($values['crm_tasks_task']) ? $values['crm_tasks_task'] : FALSE);
  variable_set('crm_tasks_create_on_insert', !empty($values['crm_tasks_create_on_insert']) ? $values['crm_tasks_create_on_insert'] : FALSE);
  variable_set('crm_tasks_create_on_update', !empty($values['crm_tasks_create_on_update']) ? $values['crm_tasks_create_on_update'] : FALSE);
  variable_set('erpal_crm_tasks_enable_task_activity_mapping', !empty($values['erpal_crm_tasks_enable_task_activity_mapping']) ? $values['erpal_crm_tasks_enable_task_activity_mapping'] : FALSE);
  
  //prepare and save the stai map
  variable_set('erpal_crm_tasks_status_mappings', $values['crm_task_stati']);
}

/**
* Return default mappings
*/
function _erpal_crm_tasks_get_task_activity_default_mapping() {
  $tid_mappings = array();
  
  //mapping goes from activity status to task status
  $name_mappings = array(
    'other' => 'inserted',
    'customer request' => 'inserted',
    'waiting for feedback' => 'in progress',
    'quote submitted' => 'ready to test',
    'revise quote' => 'buggy',
    'quote rejected' => 'aborted',
    'quote accepted' => 'completed',
    'aborted' => 'aborted'
  );
  
  //now get the tids as we need tids    
  foreach ($name_mappings as $activitiy_term => $task_name) {
    $activity_status_term = taxonomy_get_term_by_name('activity_status_terms');
    $task_status_term = taxonomy_get_term_by_name('task_status_terms');
    
    if (empty($activity_status_term->tid) || empty($task_status_term->tid))
      continue;
    
    $tid_mappings[$activity_status_term->tid] = $task_status_term->tid;
  }
  
  //set this map to default so we dont need to run this again and again
  //variable_set('erpal_crm_tasks_status_mappings', $mappings);
  
  return $tid_mappings;
}

/**
* Return the corresponding task status to an activity status
*/
function _erpal_crm_tasks_get_task_status_for_activity_status($activity_status_tid) {
  $default_mappings = _erpal_crm_tasks_get_task_activity_default_mapping();
  $mappings = variable_get('erpal_crm_tasks_status_mappings', $default_mappings);
  
  $tid = !empty($mappings[$activity_status_tid]) ? $mappings[$activity_status_tid] : false;
  
  return $tid;
}

/**
* Returns true, if a new task should be created if an activity is created
*/
function _erpal_crm_tasks_create_on_insert() {
  return variable_get('crm_tasks_create_on_insert', true);
}

/**
* Returns true, if a new task should be created if an activity is created
*/
function _erpal_crm_tasks_create_on_update() {
  return variable_get('crm_tasks_create_on_update', true);
}
