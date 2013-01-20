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
    $form['crm_tasks']['crm_tasks_task'] = array(
      '#type' => 'select',
      '#title' => t('Parent task'),
      '#options' => $tasks,
      '#default_value' => variable_get('crm_tasks_task', false),
      '#description' => t('This is the optional parent task where activity tasks will be added.'),
    );
  }
}

