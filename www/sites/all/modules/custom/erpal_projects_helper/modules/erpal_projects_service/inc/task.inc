<?php

/**
* @file all functions needed for make tasks accessable by services
*/

/**
 * Callback for retrieving erpal_task resources.
 *
 * @param int $id
 * @return object
 */
function _erpal_projects_service_task_retrieve($id) {
  $task_node = _erpal_projects_service_get_task($id, false);

  return $task_node;
}

/**
* Callback for returning a list of tasks resprecting a given filter
* @param $parameter are given in the URL as GET parameters. Possible keys in the array are
* uids, the uids that are assigned to the tasks, only tasks with assigned tasks are returned
* task_states only projects that contain tasks with the given state are returned.
*/
function _erpal_projects_service_task_index($parameters=array()) {
  module_load_include('inc', 'erpal_projects_helper', 'inc/tasks');

  $task_states = array();
  $uids = array();
  $changed = 0;
  if (isset($parameters['uids']))
    $uids = $parameters['uids'];
  if (isset($parameters['states']))
    $task_states = $parameters['states'];
  if (isset($parameters['task_changed']))
    $task_changed = $parameters['task_changed'];
  if (isset($parameters['project']))
    $project_nid = $parameters['project'];
   
  $tasks = _erpal_projects_helper_get_tasks_by_assigned_user($task_states, $uids, $task_changed, $project_nid);
  
  $tasks_out = array();
  //prepare for output!
  foreach ($tasks as $task) {
    $task = _erpal_projects_service_task_out($task);
    $tasks_out[] = $task;
  }
  
  return $tasks_out;
}

/**
* Updats a task node
*/
function _erpal_projects_service_task_update($nid, $task) {
  module_load_include('inc', 'services', 'resources/node_resource');
  $task['type'] = 'erpal_task';
  
  //map values to node
  if (isset($task['status'])) {
    $task['field_task_status_term'][LANGUAGE_NONE][0]['tid'] = $task['status'];
    unset($task['status']);
  }
  
  if (isset($task['date_start'])) {
    $task['field_date'][LANGUAGE_NONE][0]['value'] = $task['date_start'];
    unset($task['date_start']);
  }
  
  if (isset($task['date_end'])) {
    $task['field_date'][LANGUAGE_NONE][0]['value2'] = $task['date_end'];
    unset($task['date_end']);
  }
  
  $task_node = node_load($nid);
  if (!isset($task['field_date'])) {
    $date_to_set = false;
    if (isset($task_node->field_date[LANGUAGE_NONE][0]))      
      $date_to_set = $task_node->field_date[LANGUAGE_NONE][0];
    $task['field_date'][LANGUAGE_NONE][0]['value'] = $date_to_set;
  }
    
  _node_resource_update($nid, $task);  //this is the routine of the services module to update a node
}


/**
* Access callback for retrieving a erpal_task object
*/
function _erpal_projects_service_task_access($op, $args) {
  module_load_include('inc', 'services', 'resources/node_resource');
  return _node_resource_access($op, $args); //this is the access handler function of the node resource of the services module
  //@todo check with node access
  
}

/**
* Loads and returns a project with a given id
* @param int $id the id of the project
* @return object the node, if the node isnt a project node, false will be returned
* @param $return_real_node if true the node will be returned, otherwise a prepared output
*/
function _erpal_projects_service_get_task($id, $return_real_node=true) {
  $task_node = node_load($id);

  if ($task_node->type != 'erpal_task')
    false;
  
  if ($return_real_node)
    return $task_node;
    
  $task_node = _erpal_projects_service_task_out($task_node);
  
  return $task_node;
}

/**
* Prepares a task node to an easy output
*/
function _erpal_projects_service_task_out($task_node) {

  //get task type
  $type_tid = isset($task_node->field_task_type_term[LANGUAGE_NONE][0]['tid']) ? $task_node->field_task_type_term[LANGUAGE_NONE][0]['tid'] : false;
  
  $task_type = '';
  if ($type_tid) {
    $term = taxonomy_term_load($type_tid);
    $task_type = $term->name;  //@TODO sollte hier evtl besser ein Array mit tid und name übergeben werden?
  }
  
  //get task status
  $status_tid = isset($task_node->field_task_status_term[LANGUAGE_NONE][0]['tid']) ? $task_node->field_task_status_term[LANGUAGE_NONE][0]['tid'] : false,
  
  $task_status = '';
  if ($status_tid) {
    $term = taxonomy_term_load($status_tid);
    $task_status = $term->name;  //@TODO sollte hier evtl besser ein Array mit tid und name übergeben werden?
  }

  return array(
    'id' => $task_node->nid,
    'title' => $task_node->title,    
    'date_start' => isset($task_node->field_date[LANGUAGE_NONE][0]['value']) ? $task_node->field_date[LANGUAGE_NONE][0]['value'] : 0,
    'date_end' => isset($task_node->field_date[LANGUAGE_NONE][0]['value2']) ? $task_node->field_date[LANGUAGE_NONE][0]['value2'] : 0,
    'estimated' => isset($task_node->field_estimated_time[LANGUAGE_NONE][0]['value']) ? $task_node->field_estimated_time[LANGUAGE_NONE][0]['value'] : 0,
    'status' => $task_status,
    'project_id' => $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'],
    'body' => isset($task_node->body[LANGUAGE_NONE][0]['value']) ? $task_node->body[LANGUAGE_NONE][0]['value'] : '',
    'type' => $task_type,
  );
}