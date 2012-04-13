<?php

/**
* @file file has all functions for integration projects in erpal with services
*/

/**
 * Callback for retrieving erpal_project resources.
 *
 * @param int $id
 * @return object
 */
function _erpal_projects_service_project_retrieve($id) {
  //@todo implement
  $project_node = _erpal_projects_service_get_project($id);

  return $project_node;
}

/**
* Callback for returning a list of projects resprecting a given filter
* @param $parameter are given in the URL as GET parameters. Possible keys in the array are
* uids, the uids that are assigned to the tasks, only projects with assigned tasks are returned
* task_states only projects that contain tasks with the given state are returned.
*/
function _erpal_projects_service_project_index($parameters=array()) {
  module_load_include('inc', 'erpal_projects_helper', 'inc/projects');

  $task_states = array();
  $uids = array();
  $changed = 0;
  if (isset($parameters['uids']))
    $uids = $parameters['uids'];
  if (isset($parameters['states']))
    $task_states = $parameters['states'];
  if (isset($parameters['changed']))
    $changed = $parameters['changed'];
   
  $projects = _erpal_projects_helper_get_projects_with_assigned_tasks($task_states, $uids, $changed);
  return $projects;
}


/**
* Access callback for retrieving a erpal_project object
*/
function _erpal_projects_service_project_access($op, $args) {
  global $user;
  $access = FALSE;

  switch ($op) {
    case 'view':      
      $project = _erpal_projects_service_get_project($args[0]);
      if (!$project->nid)
        return false;
      $access = $project->nid > 0;  //if node_load succeeds, the user has access to load the node.
      //@todo test this with og integration!
      break;
    case 'update':
      $access = FALSE; //no update per remote
      break;
    case 'delete':
      $access = FALSE; //no delete per remote
      break;
  }
  
  return $access;
}

/**
* Loads and returns a project with a given id
* @param int $id the id of the project
* @return object the node, if the node isnt a project node, false will be returned
*/
function _erpal_projects_service_get_project($id) {
  $project_node = node_load($id);

  if ($project_node->type != 'erpal_project')
    false;
    
  return $project_node;
}
