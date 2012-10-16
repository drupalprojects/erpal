<?php

/**
* @file adds some query functions for projects and other functions for erpal_project nodes
*/

/**
* Function returns a list of projects respecting the given params as filter. 
*
* @param array $task_states array of all states tasks are returned with.
* @param array with uids $uid user ID to return only tasks a user is assigned to
* @return array an array of erpal_project objects matching the filter*
* IMPORTANT If there are no filters set, perhaps you will get big amount of data!
*/
function _erpal_projects_helper_get_projects_with_assigned_tasks($task_states=array(), $uids=array(), $task_changed=0, $project_changed=0) {
  global $user;

  module_load_include('inc', 'erpal_projects_helper', 'inc/tasks.inc');
  
  $task_nodes = _erpal_projects_helper_get_tasks_by_assigned_user($task_states, $uids, $task_changed);  

  //now return the project nodes!
  $projects = array();

  foreach ($task_nodes as $task) {
    $project_node = node_load($task->field_project_ref[LANGUAGE_NONE][0]['target_id']);
    if ($project_node->changed >= $changed || !$changed)
      $projects[$project_node->nid] = $project_node;
  }

  //now query  projects where changed is greater than changed param. This is an or query  
  if ($project_changed) {  //only if there is a filter, otherwise we get all projects back!
 
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_project')
    ->propertyCondition('status', 1)
    ->propertyCondition('changed', $project_changed, '>=');  //all entites after the given changed date
    
    $result = $query->execute();

    if (isset($result['node'])) {
      $project_nids = array_keys($result['node']);
      $project_nodes = entity_load('node', $project_nids);
      
      $projects = array_merge($projects, $project_nodes);
    }
  }

  return $projects;
}

/**
* Add links shown on project lists
*/
function _erpal_projects_helper_add_projects_view_link(&$links) {
 
  if (user_access('create erpal_project content')) {
    $back_to_list = l(
      t('Add new project'), 
      'node/add/erpal-project',
      array(
        'query' => array(        
          'destination' => $_GET['q'],
        )
      )
    );
    
    $links[] = $back_to_list;
  }
}

/**
* Returns the activity referenced by the project
*/
function _erpal_projects_helper_get_activity_by_project($project_node) {
  $activity_node = false;
  if (isset($project_node->field_activity_ref[LANGUAGE_NONE][0])) {
    $activity_nid = $project_node->field_activity_ref[LANGUAGE_NONE][0]['target_id'];
    $activity_node = node_load($activity_nid);
  }
  
  return $activity_node;
  
}

/**
* called in hook_node_presave of this module if presaved node is a project
*/
function erpal_projects_helper_node_presave_project($node) {
  $old_node = node_load($node->nid);
  _erpal_projects_helper_handle_removed_book_nodes($node, $old_node);
}

/**
* Just return all projects the user is allowed to see
*/
function _erpal_projects_helper_get_all_projects($for_select=false) {
  
  $projects = array();
  if ($for_select) {    
   
    $query = db_select('node', 'n');
    $query
      ->fields('n', array('nid', 'title'))
      ->condition('n.type', 'erpal_project')
      ->condition('n.status', '1')
      ->orderBy('n.title', 'DESC')
      ->addTag('node_access');
    
    $result = $query->execute();
    
    foreach ($result as $record) {
      // Do something with each $record
      $projects[$record->nid] = $record->title;
    }
    
    return $projects;
  } else {  
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_project')
    ->propertyCondition('status', 1);
    
    $result = $query->execute();

    if (isset($result['node'])) {
      $project_nids = array_keys($result['node']);
      $project_nodes = entity_load('node', $project_nids);
      
      $projects = array_merge($projects, $project_nodes);
    }
  }
}
