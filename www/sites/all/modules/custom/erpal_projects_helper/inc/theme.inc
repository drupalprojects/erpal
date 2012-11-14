<?php

/**
* @file provide functions to them the output of views and nodes
*/

/**
* preprocess node rendering
*/
function erpal_projects_helper_preprocess_node(&$variables) {
  if ($variables['type'] == 'erpal_task' && $variables['view_mode'] == 'view_row_details')
    _erpal_projects_helper_preprocess_node_erpal_task_view_row_details($variables);
}

/**
* proprocess rendering of erpal_task in view_row_details view mode
*/
function _erpal_projects_helper_preprocess_node_erpal_task_view_row_details(&$variables) {
  $node = $variables['node'];

  $deadline = isset($node->field_date[LANGUAGE_NONE][0]) ? $node->field_date[LANGUAGE_NONE][0]['value2'] : false;     
  if ($deadline) {
    $deadline_unix = erpal_date_as_unix_timestamp($deadline); 
    $status_field_name = 'field_task_status_term';
    $status = _erpal_crm_helper_get_date_status_state($deadline_unix, false, $node, $status_field_name);
    $variables['classes_array'][] = $status;
  }
}

/**
* Alter fields and rows in the view table
*/
function erpal_projects_helper_preprocess_views_view_table(&$variables) {
  $view = $variables['view'];
  _erpal_projects_helper_projects_and_tasks_preprocess($view, $variables['field_classes'], $variables['row_classes']);
}


/**
* Function to preprocess task and project rows in views
*/
function _erpal_projects_helper_projects_and_tasks_preprocess(&$view, &$field_classes, &$row_classes) {
    
  if ($view->name == 'tasks' || $view->name == 'tickets') {
    $node = new stdClass;
    $node->type = 'erpal_task';    
  } elseif ($view->name == 'projects') {
    $node = new stdClass;
    $node->type = 'erpal_project';
  } else
    return;

  $status_field_name = _erpal_projects_helper_get_status_field_name($node);
  $status_field_name_views = 'field_'.$status_field_name;
  
  $date_field_name = 'field_date';
  $date_field_name_views = 'field_'.$date_field_name;
 
  $result = $view->result;
  foreach ($result as $delta=>$res_obj) {
    $status_term = isset($res_obj->{$status_field_name_views}[0]['raw']['taxonomy_term']) ? $res_obj->{$status_field_name_views}[0]['raw']['taxonomy_term'] : false;    
    
    $date = isset($res_obj->{$date_field_name_views}[0]['raw']['value2']) ? $res_obj->{$date_field_name_views}[0]['raw']['value2'] : false;

    $date_unix = erpal_date_as_unix_timestamp($date);
    $state = _erpal_crm_helper_get_date_status_state($date_unix, $status_term);
    
    $row_classes[$delta][] = $state;  
  }

}

