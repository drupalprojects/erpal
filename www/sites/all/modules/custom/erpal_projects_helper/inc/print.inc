<?php

/**
* @file has all functions for printing tasks
*/

/**
* Manu callback for printing a task
*/
function _erpal_projects_helper_task_print($task_node) {
  //@TODO
  $print_html = theme('erpal_task_print', array('node' => $task_node));
  die($print_html);
}

/**
* Access callback for printing a task
*/
function _erpal_projects_helper_task_print_access() {
  return user_access('erpal print tasks');
}