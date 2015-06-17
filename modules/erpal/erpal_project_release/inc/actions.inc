<?php

/**
* #######################################################################
* FUNCTIONS FOR Bulk Operation to add tasks to releases
* #######################################################################
*/


/**
* Callback for the action erpal_project_release_add_tasks_to_release adds tasks to a release node
*/
function erpal_project_release_add_tasks_to_release(&$tasks, $context) {
  //now add all tasks to the release. We want to avoid 
  //sending notifications
  $c = 0;
  foreach ($tasks as $nid => $task_node) {
    $task_node->skipp_notify = true;
    $task_node->field_release_ref[LANGUAGE_NONE][0]['target_id'] = arg(1); //the release
    node_save($task_node);
    
    $c++;
  }
  
  drupal_set_message(t('!count tasks added to the release.', array('!count' => $c)));
  
}

/**
* Callback for the action erpal_project_release_remove_tasks_from_release that removes tasks from a release node
*/
function erpal_project_release_remove_tasks_from_release(&$tasks, $context) {
  //now remove all tasks from the release. We want to avoid 
  //sending notifications
  $c = 0;
  foreach ($tasks as $nid => $task_node) {
    $task_node->skipp_notify = true;
    unset($task_node->field_release_ref[LANGUAGE_NONE]);
    //node_save($task_node);
    field_attach_update('node', $task_node);
    //clear the node cache
    node_load($task_node->nid, NULL, true);
    $c++;
  }
  
  drupal_set_message(t('!count tasks removed from the release.', array('!count' => $c)));
}
