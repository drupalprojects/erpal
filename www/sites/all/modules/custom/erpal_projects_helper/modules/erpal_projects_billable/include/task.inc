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
    
  $billable_information = _erpal_projects_billable_subject_billable_information_subject($node);
  
  _erpal_billable_update_billable($node, 'update');
    
}

/**
* @return the parent node of the given task or project node. FALSE if no parent could be found
* @param $node a erpal_task or erpal_project node to determine the parent
*/
function _erpal_project_task_parent($node) {
  if ($node->type != 'erpal_task')
    return false; //only task have a parent
    
  //ok, this is a task
  //does it have a direct parent?
  $parent_nid = false;
  $project_nid = $node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
  
  if (isset($node->field_parent[LANGUAGE_NONE][0]['target_id'])) {
    $parent_nid = $node->field_parent[LANGUAGE_NONE][0]['target_id'];    
  } else {
    //if there is no direct parent, use the project as parent with its pricing information
    $parent_nid = $project_nid;
  }
  
  if ($parent_nid) {
    $parent_node = node_load($parent_nid);
    //if parent node is not a task or a project, use the referenced project
    if ($parent_node->type != 'erpal_task' && $parent_node->type != 'erpal_project') {
      $parent_node = node_load($project_nid);
    }
    
    return $parent_node;
  }
  
  return false;
}

/**
* Fallows the same logic as @see _erpal_project_task_parent but uses a task edit form with prepopulated project or if there is a
* prepopulate paremter in the url (e.g. ?field_project_ref=1682)
*/
function _erpal_project_task_parent_from_form($form) {
  $nid = $form['nid']['#value'];
  
  $type = $form['type']['#value'];
  if ($type != 'erpal_task')
    return false; //only task have a parent
    
  //ok, this is a task
  //does it have a direct parent?
  $parent_nid = false;
  $project_nid = isset($form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value']) ? $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'] : false;

  if ($project_nid) {
    //get from autocomplete string
    $project_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($project_nid);
  } else {
    //may be get from URL
    $project_nid = $_GET['field_project_ref'];
  }

  $parent_nid = isset($form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value']) ? $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value'] : false;

  if (!$parent_nid) {
    //if there is no direct parent, use the project as parent with its pricing information
    $parent_nid = $project_nid;
  } else {
    //get from autocomplete
    $parent_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($parent_nid);
  }

  if ($parent_nid) {
    $parent_node = node_load($parent_nid);
    //if parent node is not a task or a project, use the referenced project
    if ($parent_node->type != 'erpal_task' && $parent_node->type != 'erpal_project') {
      $parent_node = node_load($project_nid);
    }
    
    return $parent_node;
  }
  
  return false;
}