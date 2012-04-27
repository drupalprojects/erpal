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
  $task_node = _erpal_projects_service_get_task($id);

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
  return $tasks;
}

/**
* Updats a task node
*/
function _erpal_projects_service_task_update($nid, $task) {
  module_load_include('inc', 'services', 'resources/node_resource');
  $task['type'] = 'erpal_task';
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
*/
function _erpal_projects_service_get_task($id) {
  $task_node = node_load($id);

  if ($task_node->type != 'erpal_task')
    false;
    
  return $task_node;
}