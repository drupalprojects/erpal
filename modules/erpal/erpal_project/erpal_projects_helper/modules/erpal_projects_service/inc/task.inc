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
function _erpal_projects_service_task_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = false, $project = -1, $user = -1) {
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
  $task = node_load($nid);
//  dpm($task);
  $task_out = array();
  $task_out['title'] = $task->title;
  $task_out['task'] = url('rest/projects/task/' . $task->nid, array('absolute' => TRUE));
  if ($details) {
    $task_out['description'] = $task->body[LANGUAGE_NONE][0]['value'];
    $task_out['created'] = $task->created;
    $task_out['changed'] = $task->changed;
    $task_out['task_status_term'] = $task->field_task_status_term[LANGUAGE_NONE][0]['tid'];
    $task_out['task_type_term'] = $task->field_task_type_term[LANGUAGE_NONE][0]['tid'];
    $task_out['priority_term'] = $task->field_priority_term[LANGUAGE_NONE][0]['tid'];
    $task_out['progress_percent'] = $task->field_progress_percent[LANGUAGE_NONE][0]['value'];
    $task_out['project_tags'] = $task->field_project_tags[LANGUAGE_NONE][0]['tid'];
    $task_out['project'] = url('rest/projects/project/' . $task->field_project_ref[LANGUAGE_NONE][0]['target_id'], array('absolute' => TRUE));
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

