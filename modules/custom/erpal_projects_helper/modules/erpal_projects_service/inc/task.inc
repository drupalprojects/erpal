<?php

/**
* @file all functions needed for make erpal_tasks accessible by services
* @author Oskar Bechtold <bechtold@brightsolutions.de>
* @copyright (c) 2013
*/

/**
 * Callback for retrieving single erpal_task resources.
 *
 * @param int $id
 * @return object
 */
function _erpal_projects_service_task_retrieve($id) {
  $task_node = _erpal_projects_service_task_out( (int)$id, TRUE);

  return $task_node;
}

/**
* Callback for returning a list of erpal_tasks given filters
* @param int $start Deliver data from nth element, defaults to 0.
 * @param int $count Delive n elements
 * @param int $changed_since Deliver all elemets changed after date  x. Format: UNIX timestamp in UTC
 * @param bool $details Deliver elements with more detail
*/
function _erpal_projects_service_task_index($start=0, $count=PHP_INT_MAX, $changed_since=0, $details=false, $project=-1, $user=-1) {  
  module_load_include('inc', 'erpal_projects_helper', 'inc/tasks');
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'erpal_task')
    ->range( (int)$start, (int)$count)
    ->propertyCondition('changed', (int)$changed_since,'>=');
  if($project != -1){
    $query ->fieldCondition('field_project_ref', 'target_id', (int)$project, '=') ;
  }
  if($user != -1){
    $query ->fieldCondition('field_task_assigned_users', 'target_id', (int)$user, '=') ;
  }

  $entities = $query->execute();

  $tasks_out = array();

  if (!empty($entities['node'])) {
    //prepare for output!
    foreach (array_keys($entities['node']) as $nid) {
      $tasks_out[] = _erpal_projects_service_task_out($nid,$details);
    }
  }

  return $tasks_out;
}


/**
* Updats a task node
*/
function _erpal_projects_service_task_update($nid, $task) {
  $task = (object)$task['task'];
//  module_load_include('inc', 'services', 'resources/node_resource');
//  $task['type'] = 'erpal_task';
//  
//  //map values to node
//  if (isset($task['status'])) {
//    $task['field_task_status_term'][LANGUAGE_NONE][0]['tid'] = $task['status'];
//    unset($task['status']);
//  }
//  
//  if (isset($task['date_start'])) {
//    $task['field_date'][LANGUAGE_NONE][0]['value'] = $task['date_start'];
//    unset($task['date_start']);
//  }
//  
//  if (isset($task['date_end'])) {
//    $task['field_date'][LANGUAGE_NONE][0]['value2'] = $task['date_end'];
//    unset($task['date_end']);
//  }
//  
//  $task_node = node_load($nid);
//  if (!isset($task['field_date'])) {
//    $date_to_set = false;
//    if (isset($task_node->field_date[LANGUAGE_NONE][0]))      
//      $date_to_set = $task_node->field_date[LANGUAGE_NONE][0];
//    $task['field_date'][LANGUAGE_NONE][0]['value'] = $date_to_set;
//  }
//    
//  _node_resource_update($nid, $task);  //this is the routine of the services module to update a node
}


/**
 * 
 * @param type $nid
 * @param type $details
 * @return type
 */
function _erpal_projects_service_task_out($nid, $details=FALSE) {
  $task = node_load($nid);
  dpm($task);
  $task_out = array();
  $task_out['title'] = $task->title;
  $task_out['task'] = url('rest/projects/task/'.$task->nid, array('absolute'=>TRUE) );
  if($details){
    $task_out['description'] = $task->body[LANGUAGE_NONE][0]['value'];
    $task_out['created'] = $task->created;
    $task_out['changed'] = $task->changed;
    $task_out['task_status_term'] = $task->field_task_status_term[LANGUAGE_NONE][0]['tid'];
    $task_out['task_type_term'] = $task->field_task_type_term[LANGUAGE_NONE][0]['tid'];
    $task_out['priority_term'] = $task->field_priority_term[LANGUAGE_NONE][0]['tid'];
    $task_out['progress_percent'] = $task->field_progress_percent[LANGUAGE_NONE][0]['value'];
    $task_out['project_tags'] = $task->field_project_tags[LANGUAGE_NONE][0]['tid'];
    $task_out['project'] = url('rest/projects/project/'.$task->field_project_ref[LANGUAGE_NONE][0]['target_id'], array('absolute'=>TRUE) );
    
    
  }
  return $task_out;
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

///**
//* Prepares a task node to an easy output
//*/
//function _erpal_projects_service_task_out($task_node) {
//
//  //get task type
//  $type_tid = isset($task_node->field_task_type_term[LANGUAGE_NONE][0]['tid']) ? $task_node->field_task_type_term[LANGUAGE_NONE][0]['tid'] : false;
//  
//  $task_type = '';
//  if ($type_tid) {
//    $term = taxonomy_term_load($type_tid);
//    $task_type = $term->name;  //@TODO sollte hier evtl besser ein Array mit tid und name �bergeben werden?
//  }
//  
//  //get task status
//  $status_tid = isset($task_node->field_task_status_term[LANGUAGE_NONE][0]['tid']) ? $task_node->field_task_status_term[LANGUAGE_NONE][0]['tid'] : false;
//  
//  $task_status = '';
//  if ($status_tid) {
//    $term = taxonomy_term_load($status_tid);
//    $task_status = $term->name;  //@TODO sollte hier evtl besser ein Array mit tid und name �bergeben werden?
//  }
//
//  return array(
//    'id' => $task_node->nid,
//    'title' => $task_node->title,    
//    'date_start' => isset($task_node->field_date[LANGUAGE_NONE][0]['value']) ? $task_node->field_date[LANGUAGE_NONE][0]['value'] : 0,
//    'date_end' => isset($task_node->field_date[LANGUAGE_NONE][0]['value2']) ? $task_node->field_date[LANGUAGE_NONE][0]['value2'] : 0,
//    'estimated' => isset($task_node->field_estimated_time[LANGUAGE_NONE][0]['value']) ? $task_node->field_estimated_time[LANGUAGE_NONE][0]['value'] : 0,
//    'status' => $task_status,
//    'project_id' => $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'],
//    'body' => isset($task_node->body[LANGUAGE_NONE][0]['value']) ? $task_node->body[LANGUAGE_NONE][0]['value'] : '',
//    'type' => $task_type,
//  );
//}