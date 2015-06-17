<?php

/**
 * @file all functions needed to make erpal_tasks accessible by services
 * @author Oskar Bechtold <bechtold@brightsolutions.de>
 * @copyright (c) 2013
 */

/**
 * Callback for retrieving single erpal_task.
 *
 * @param int $id
 * @return array of the task, prepared for output
 */
function _erpal_projects_service_task_retrieve($id) {
  $task_node = _erpal_projects_service_task_out((int) $id, TRUE);

  return $task_node;
}

/**
 * Callback for returning a list of erpal_tasks considering given filters
 * @param int $start number to start list from, defaults to 0
 * @param int $count number of item to return, defaults to PHP_INT_MAX
 * @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
 * @param bool $details whether tasks will be returned with details , defaults to false
 * @param int $project return only tasks of that project, defaults to -1 (all projects)
 * @param int $user return only tasks assigned to that user , defaults to -1 (all users)
 * @return array array of tasks, prepared for output
 */
function _erpal_projects_service_task_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = false, $project = -1, $user = -1, $parent = -1) {
  module_load_include('inc', 'erpal_projects_helper', 'inc/tasks');
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
          ->propertyCondition('type', 'erpal_task')
          ->range((int) $start, (int) $count)
          ->propertyCondition('changed', (int) $changed_since, '>=');
  if ($project != -1) {
    $query->fieldCondition('field_project_ref', 'target_id', (int) $project, '=');
  }
  if ($user != -1) {
    $query->fieldCondition('field_task_assigned_users', 'target_id', (int) $user, '=');
  }
  if ($parent != -1) {
    $query->fieldCondition('field_parent', 'target_id', (int) $parent, '=');
  }

  $entities = $query->execute();

  $tasks_out = array();

  if (!empty($entities['node'])) {
    //prepare for output!
    foreach (array_keys($entities['node']) as $nid) {
      $tasks_out[] = _erpal_projects_service_task_out($nid, $details);
    }
  }

  return $tasks_out;
}


/**
 * prepare tasks to output via service
 * @param type $nid the node to return
 * @param type $details whether to return with details or not, defaults to false
 * @return type tho task as array, prepared for output
 */

function _erpal_projects_service_task_out($nid, $details = FALSE) {
  $tasktemp = node_load($nid);
  $task = entity_metadata_wrapper('node',$tasktemp);
  $task_out = array();
  $task_out['title'] = $task->title->value();
  $task_out['task'] = url('rest/projects/task/' . $task->nid->value(), array('absolute' => TRUE));
  if ($details) {
    $body = $task->body->value();
    $task_out['description'] = strip_tags($body['value']);
    $task_out['created'] = (int)$task->created->value();
    $task_out['changed'] = (int)$task->changed->value();
    if (isset($tasktemp->field_task_status_term) && !empty($tasktemp->field_task_status_term)) {
      $task_out['task_status_term'] = (int) $task->field_task_status_term->value()->tid;
      $status = field_get_items('taxonomy_term', $task->field_task_status_term->value(), 'field_simple_process_status');
      $task_out['semantic_status'] = $status[0]['value'];
    }
    $task_out['task_type_term'] = (int)$task->field_task_type_term->value()->tid;
    $task_out['priority_term'] = (int)$task->field_priority_term->value()->tid;
    $task_out['progress_percent'] = (int)$task->field_progress_percent->value();
	$task_out['estimated_time'] = $task->field_estimated_time->value();
    $task_out['project_tags'] = (is_object($task->field_project_tags->value()))?
            (int)$task->field_project_tags->value()->tid :
            null;
    $task_out['project'] = url('rest/projects/project/' . $task->field_project_ref->value()->nid, array('absolute' => TRUE));
    $task_out['parent'] = (is_object($task->field_parent->value()))?
            url('rest/projects/task/' . $task->field_parent->value()->nid , array('absolute' => TRUE)) :
            NULL;
    $task_out['subtasks'] = url('rest/projects/task', array('absolute' => TRUE,'query'=>array('parent'=>$task->nid->value())));
    foreach ($task->field_task_assigned_users->value() as $user) {
      $task_out['assigned_users'][] = (int)$user->uid;
    }
    $date = $task->field_date->value();
    //unfortunately the date is saved as datetime, so we need to convert it to timestamp. We can ignore timezone, as we do not need a time, only date.
    $value = new DateTime($date['value']);
    $value2 = new DateTime($date['value2']);
    $task_out['start_date'] = (int)$value->getTimestamp();
    $task_out['due_date'] = (int)$value2->getTimestamp();
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
 * Access callback for create a erpal_task object
 */
function _erpal_projects_service_task_create_access($op, $args) {
  global $user;
  
  if($op == 'create'){
    $project = node_load($args[0]['project']);
    $uids = _erpal_projects_helper_get_project_team_uids($project);

    if(count($uids)){
      foreach ($uids as $key => $value) {
        if($user->uid == $value['uid']){
          if(in_array('view_tickets_list', $value['permissions']) &&
              in_array('view_tasks_list', $value['permissions'])){
            return TRUE;
          }
        }
      }
    }
  }

  return FALSE;
}

/**
 * Create a new task node by services module request
 * @param array $task the data delivered by the webservice
 * @return int the new task nid for output
 * @TODO: maybe use drupal_form_submit or _node_resource_create to have validation instead of node_save
 */
function _erpal_projects_service_task_create($task) {
  global $user;
  
  $newTask = new stdClass();
  $newTask->uid = $user->uid;
  $newTask->type = 'erpal_task';
  $newTask->language = LANGUAGE_NONE;
  $newTask->title = $task['title'];
  $newTask->body[LANGUAGE_NONE][0]['value'] = $task['body'];
  $newTask->field_is_ticket[LANGUAGE_NONE][0]['value'] = $task['ticket'];
  $newTask->field_project_ref[LANGUAGE_NONE][0]['target_id'] = $task['project'];
  $newTask->field_task_status_term[LANGUAGE_NONE][0]['tid'] = $task['status'];
  $newTask->field_priority_term[LANGUAGE_NONE][0]['tid'] = $task['priority'];
  $newTask->field_task_type_term[LANGUAGE_NONE][0]['tid'] = $task['task_type'];

  if (isset($task['parent'])) {
    $newTask->field_parent[LANGUAGE_NONE][0]['target_id'] = $task['parent'];
  }

  if (isset($task['file'])) {
    $newFile = new stdClass();
    $newFile->uid = $task['uid'];
    $newFile->type = 'erpal_file';
    $newFile->language = LANGUAGE_NONE;
    $fid = _file_resource_create($task['file']);
    $newFile->field_docs_file[LANGUAGE_NONE][] = array(
      'fid' => $fid['fid'],
      'display' => 1,
    );
    $newFile->title = $task['file']['filename'];
    node_save($newFile);

    $newTask->field_asset_files[LANGUAGE_NONE][0]['target_id'] = $newFile->nid;
  }

  node_save($newTask);

  $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_pricing'));
  $field_collection_item->setHostEntity('node', $newTask);
  $field_collection_item->field_price_mode[LANGUAGE_NONE][0]['value'] = 'none';
  $field_collection_item->save();

  return $newTask->nid;
}
