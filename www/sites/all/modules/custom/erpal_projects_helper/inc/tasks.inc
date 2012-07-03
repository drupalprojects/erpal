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
    $query->fieldCondition('field_task_assigned_users', 'target_id', $uids, 'IN');
  }
  
  if (count($task_states) > 0) {
    $query->fieldCondition('field_task_status', 'value', $task_states, 'IN');
  }
  
  if ($changed) {
    $query->propertyCondition('changed', $changed, '>=');  //all entites after the given changed date
  }
  
  if ($project_nid) {
    $query->fieldCondition('field_project_ref', 'target_id', $project_nid);
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
* Return tasks by project
* @return array with nids of tasks referencing the given project_nid
*/
function _erpal_projects_helper_get_tasks_by_project($project_nid) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_task')
  ->propertyCondition('status', 1)
  ->fieldCondition('field_project_ref', 'target_id', $project_nid);
    
  $result = $query->execute();

  $task_nodes = array();
  if (isset($result['node'])) {
    $task_nids = array_keys($result['node']);
  }

  return $task_nids;
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
  
  if (!isset($task_node->field_parent[LANGUAGE_NONE][0]['target_id']))
    return;
    
  $parent_nid = $task_node->field_parent[LANGUAGE_NONE][0]['target_id'];
  $parent_node = node_load($parent_nid);
  $project_nid = _erpal_projects_helper_has_project($parent_node);
  
  if ($project_nid) {
    $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'] = $project_nid;
  }
}

/**
* returns the activity which is related to a task over its related project
*/
function _erpal_projects_helper_get_activity_by_task($task_node) {
  $activity_node = false;
  if (isset($task_node->field_project_ref[LANGUAGE_NONE][0])) {
    $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
    $project_node = node_load($project_nid);
  }
  
  $activity_node = _erpal_projects_helper_get_activity_by_project($project_node);
  
  return $activity_node;
}

/**
* Implements hook_erpal_clone_node_alter to alter task node if cloned
* @param $node is the new cloned node
* @param $args[parent_nid] is the nid of the new parent_node of the cloned node
* @param $args[options] some options given to the clone process
*/
function erpal_projects_helper_erpal_clone_node_alter($node, $args) {
  $parent_nid = $args['parent_nid'];
  $options = $args['options'];
  
  if ($node->type == 'erpal_task') {
    //ensure that the correct project is set to the task
    //even this is done in presave (@see erpal_projects_helper_node_presave_task) it is important to ensure, so we do it again here after cloning
    _erpal_projects_helper_task_set_project($node);  

    //prepare other task node attributes according to option
    if ($options['reset_task_status']) {
      $node->field_task_status[LANGUAGE_NONE][0]['value'] = _erpal_projects_helper_insert_task_state();
      $node->field_progress_percent[LANGUAGE_NONE][0]['value'] = 0;
    }  
    
    //anyway, delete the assigned user because this will be a ressource planing issue
    unset($node->field_task_assigned_users);
    
  }
 
}

/**
* Implements hook_erpal_clone_node_postprocess_alter to add the new book to the given project
*/
function erpal_projects_helper_erpal_clone_node_postprocess_alter($node, $args) {
  $parent_nid = $args['parent_nid'];
  $options = $args['options'];
  
  if ($node->type == 'erpal_book') {
    //Link new book to selected project and delete all references to exported files of the new 
    //if tasks are cloned, they will be added to this project
  
    if ($options['project']) {
      $project_nid = $options['project'];
      $project_node = node_load($project_nid);
      $project_node->field_books_ref[LANGUAGE_NONE][]['target_id'] = $node->nid;
      node_save($project_node);
    }
  }
}