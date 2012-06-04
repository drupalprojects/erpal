<?php

/**
* @file file has all functions for integration projects in erpal with services
*/

/**
 * Callback for retrieving erpal_project resources.
 *
 * @param int $id the nid of the project node that should be retrieved
 * @return object
 */
function _erpal_projects_service_project_retrieve($id) {
  $project_node = _erpal_projects_service_get_project($id, false);

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
  if (isset($parameters['task_changed']))
    $task_changed = $parameters['task_changed'];
  if (isset($parameters['project_changed']))
    $project_changed = $parameters['project_changed'];
   
  $projects = _erpal_projects_helper_get_projects_with_assigned_tasks($task_states, $uids, $task_changed, $project_changed);
  
  $projects_out = array();
  //prepare for output!
  foreach ($projects as $project) {
    $project = _erpal_projects_service_project_out($project);
    $projects_out[] = $project;
  }
  
  return $projects_out;
}


/**
* Access callback for retrieving a erpal_project object
*/
function _erpal_projects_service_project_access($op, $args) {
  global $user;
  $access = FALSE;

  switch ($op) {
    case 'view':      
      $project = _erpal_projects_service_get_project($args[0], true);

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
* @param $return_real_node if true the node will be returned, otherwise a prepared output
*/
function _erpal_projects_service_get_project($id, $return_real_node=true) {
  $project_node = node_load($id);

  if ($project_node->type != 'erpal_project')
    return false;

  if ($return_real_node)
    return $project_node;
    
  $project_node = _erpal_projects_service_project_out($project_node);
  return $project_node;
}

/**
* Prepares a project node to an easy output
*/
function _erpal_projects_service_project_out($project_node) {
  $customer_nid = 0;
  if (isset($project_node->field_customer_ref[LANGUAGE_NONE][0]['target_id']))
    $customer_nid = $project_node->field_customer_ref[LANGUAGE_NONE][0]['target_id'];

  $customer_title = '';
  if ($customer_nid) {
    $customer_node = node_load($customer_nid);
    $customer_title = $customer_node->title;
  }

  return array(
    'id' => $project_node->nid,
    'title' => $project_node->title,
    'status' => $project_node->field_project_status[LANGUAGE_NONE][0]['value'],
    'date_start' => isset($project_node->field_date[LANGUAGE_NONE][0]['value']) ? $project_node->field_date[LANGUAGE_NONE][0]['value'] : 0,
    'date_end' => isset($project_node->field_date[LANGUAGE_NONE][0]['value2']) ? $project_node->field_date[LANGUAGE_NONE][0]['value2'] : 0,
    'body' => $project_node->body[LANGUAGE_NONE][0]['value'],
    'customer' => $customer_title,
  );
}
