<?php

/**
* @file provide functions to them the output of views and nodes
*/


/**
* Alter fields and rows in the view table
*/
function erpal_crm_helper_preprocess_views_calc_table(&$variables) {
  $view = $variables['view'];
  _erpal_crm_helper_activities_preprocess($view, $variables['field_classes'], $variables['row_classes']);
}


/**
* Function to preprocess task and project rows in views
*/
function _erpal_crm_helper_activities_preprocess(&$view, &$field_classes, &$row_classes) {

  if ($view->name != 'crm_activities')
    return;

  $status_field_name = _erpal_crm_helper_get_status_field_name();
  $status_field_name_views = 'field_'.$status_field_name;
  
  $date_field_name = 'field_next_contact';
  $date_field_name_views = 'field_'.$date_field_name;
 
  $result = $view->result;
  foreach ($result as $delta=>$res_obj) {
    $status_term = isset($res_obj->{$status_field_name_views}[0]['raw']['taxonomy_term']) ? $res_obj->{$status_field_name_views}[0]['raw']['taxonomy_term'] : false;    
    
    $date = isset($res_obj->{$date_field_name_views}[0]['raw']['value']) ? $res_obj->{$date_field_name_views}[0]['raw']['value'] : false;

    $date_unix = erpal_date_as_unix_timestamp($date);
    $state = _erpal_crm_helper_get_date_status_state($date_unix, $status_term);

    $row_classes[$delta] = $state;  
  }

}

