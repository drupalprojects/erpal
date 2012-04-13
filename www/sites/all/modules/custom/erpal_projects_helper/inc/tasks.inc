<?php

/**
* @file adds some query functions for tasks and other functions for erpal_task nodes
*/

/**
* Function returns a list of tasks respecting the given params as filter. 
*
* @param array $task_states array of all states tasks are returned with.
* @param array with uids $uid user ID to return only tasks a user is assigned to
* @return array an array of erpal_project objects matching the filter
*/
function _erpal_projects_helper_get_tasks_by_assigned_user($task_states=array(), $uid=array()) {
  
}
