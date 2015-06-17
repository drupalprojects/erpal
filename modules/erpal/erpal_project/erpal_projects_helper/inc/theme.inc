<?php

/**
* @file provide functions to them the output of views and nodes
*/


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
    
  //filter only for views that filter tasks and projects only
  //@TODO much better would it be to have a views row plugin where we can set the fields and conditions when the views row should be altered red
  if ($view->base_table == 'node') {
    //only if we have either tasks or projects in filter
    $filter_node_types = !empty($view->filter['type']) ? $view->filter['type'] : false;
    if (!$filter_node_types || count($filter_node_types) > 1) //only one node type per view here supported, see TODO above
      return false;
    
  } else
    return false;

  //get the node type filtered by the view
  $node_type = reset($filter_node_types->value);
  $node = new stdClass;
  $node->type = $node_type;

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

