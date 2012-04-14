<?php

/**
* @file adds some query functions for projects and other functions for erpal_project nodes
*/

/**
* Function returns a list of projects respecting the given params as filter. 
*
* @param array $task_states array of all states tasks are returned with.
* @param array with uids $uid user ID to return only tasks a user is assigned to
* @param changed all projects that have changed since the variable
* @return array an array of erpal_project objects matching the filter*
* IMPORTANT If there are no filters set, perhaps you will get big amount of data!
*/
function _erpal_projects_helper_get_projects_with_assigned_tasks($task_states=array(), $uids=array(), $changed=0) {
  global $user;

  /*
  if (count($uids) <= 0)
    $uids = array($user->uid);
  */
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_task')
  ->propertyCondition('status', 1);

  if (count($uids) > 0) {
    $query->fieldCondition('field_task_assigned_users', 'uid', $uids, 'IN');
  }
  
  if (count($task_states) > 0) {
    $query->fieldCondition('field_task_status', 'value', $task_states, 'IN');
  }
  
  if ($changed) {
    $query->propertyCondition('changed', $changed, '>=');  //all entites after the given changed date
  }
  
  $result = $query->execute();

  if (isset($result['node'])) {
    $task_nids = array_keys($result['node']);
    $task_nodes = entity_load('node', $task_nids);
  }
  
  //now return the project nodes!
  $projects = array();

  foreach ($task_nodes as $task) {
    $project_node = node_load($task->field_project_ref[LANGUAGE_NONE][0]['nid']);
    $projects[$project_node->nid] = $project_node;
  }

  return $projects;
}