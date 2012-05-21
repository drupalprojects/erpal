<?php

/**
* @file adds some query functions for tasks and other functions for erpal_task nodes
*/

/**
* Function returns a list of tasks respecting the given params as filter. 
*
* @param array $task_states array of all states tasks are returned with.
* @param array with uids $uid user ID to return only tasks a user is assigned to
* @param int $changed all projects that have changed since the variable
* @param int $project_nid only tasks of the given project are returned
* @return array an array of erpal_project objects matching the filter
*/
function _erpal_projects_helper_get_tasks_by_assigned_user($task_states=array(), $uids=array(), $changed=0, $project_nid=0) {
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
  
  if ($project_nid) {
    $query->fieldCondition('field_project_ref', 'nid', $project_nid);
  }
  
  $result = $query->execute();

  $task_nodes = array();
  if (isset($result['node'])) {
    $task_nids = array_keys($result['node']);
    $task_nodes = entity_load('node', $task_nids);
  }
 
  return $task_nodes;
}

/**
* Presave function for tasks
*/
function erpal_projects_helper_node_presave_task($task_node) {
  _erpal_projects_helper_task_set_project($task_node);
}

/**
* Set the project according to the parents project
*/
function _erpal_projects_helper_task_set_project($task_node) {
  
  if (!isset($task_node->field_parent[LANGUAGE_NONE][0]['nid']))
    return;
    
  $parent_nid = $task_node->field_parent[LANGUAGE_NONE][0]['nid'];
  $parent_node = node_load($parent_nid);
  $project_nid = _erpal_projects_helper_has_project($parent_node);
  
  if ($project_nid) {
    $task_node->field_project_ref[LANGUAGE_NONE][0]['nid'] = $project_nid;
  }
}

/**
* returns the activity which is related to a task over its related project
*/
function _erpal_projects_helper_get_activity_by_task($task_node) {
  $activity_node = false;
  if (isset($task_node->field_project_ref[LANGUAGE_NONE][0])) {
    $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['nid'];
    $project_node = node_load($project_nid);
  }
  
  $activity_node = _erpal_projects_helper_get_activity_by_project($project_node);
  
  return $activity_node;
}