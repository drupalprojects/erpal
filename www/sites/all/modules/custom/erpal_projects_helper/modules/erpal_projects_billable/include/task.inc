<?php

/**
* @file all functions dealing with tasks in erpal_projects_billable module
*/

/**
* Function callback on insert task
* @param the task node
*/
function _erpal_projects_billable_insert_task($node) {
  
  //$billable_information = _erpal_projects_billable_subject_billabel_information_subject($node);
  
  //only process if the task is completed!
  $task_status = $node->field_task_status[LANGUAGE_NONE][0]['value'];
  if ($task_status != 'completed')
    return;

  _erpal_billable_update_billable($node, 'insert');
}

/**
* Function on update task. Functions fetches the related billable entity (only one per task) and alters its data if
* according to the settings on the task node (druation changed etc).
* this happens only if the billabe is not set to "billed"!
* possible cases:
* - if billable is already billed: do nothing!
* - else:
* - there is allready a billabe referenced to this task and the task status is complete: adapt information to billable
* - there is allready a billabe referenced to this task and the task status is NOT complete: delete the billable //@todo: really?
* - there is no billabe referenced to the task: create a new one!
* @param the task node
*/
function _erpal_projects_billable_update_task($node) {
  
  $billables = _erpal_projects_billable_billbales_by_subject_nid($node->nid, true);
    
  $billable_information = _erpal_projects_billable_subject_billabel_information_subject($node);
  
  _erpal_billable_update_billable($node, 'update');
    
}