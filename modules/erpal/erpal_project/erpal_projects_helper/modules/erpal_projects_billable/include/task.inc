<?php

/**
* @file all functions dealing with tasks in erpal_projects_billable module
*/

/**
* Function callback on insert task
* @param the task node
*/
function _erpal_projects_billable_insert_task($node) {
  
  //only process if the task is completed!
  $task_status = _erpal_basic_helper_get_tid_semantic($node, 'field_task_status_term');
  if ($task_status != 'completed')
    return;

  _erpal_billable_update_billable($node, 'insert');
}

/**
* Function on update task.
*/
function _erpal_projects_billable_update_task($node) {
  _erpal_billable_update_billable($node, 'update');    
}