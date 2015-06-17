<?php

/**
* @file all functions dealing with projects in erpal_projects_billable module
*/

/**
* Function callback on insert project
* @param the project node
*/
function _erpal_projects_billable_insert_project($node) {
  
  //only process if the task is completed!
  $project_status = false;
  $project_status = _erpal_basic_helper_get_tid_semantic($node, 'field_project_status_term');  

  if ($project_status != 'completed')
    return;
    
  _erpal_billable_update_billable($node, 'insert');
}

/**
* Function on update task. 
*/
function _erpal_projects_billable_update_project($node) {
  _erpal_billable_update_billable($node, 'update');
    
}