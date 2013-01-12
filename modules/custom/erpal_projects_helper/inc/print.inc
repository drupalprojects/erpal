<?php

/**
* @file has all functions for printing tasks
*/

/**
* Manu callback for printing a task
*/
function _erpal_projects_helper_task_print($task_node) {
  //@TODO
  $print_type = _erpal_projects_helper_task_print_type();
  
  $print_html = theme('erpal_task_print', array('node' => $task_node));
  
  if ($print_type == 'html') {
    //output as simple HTML
    die($print_html);
  } elseif ($print_type == 'pdf') {
    //output as PDF and send as download
    _erpal_print_html_as_pdf($print_html);    
  }
  
}