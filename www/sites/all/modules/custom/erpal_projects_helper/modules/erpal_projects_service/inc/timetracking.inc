<?php

/**
* @file all functions needed to integrate timetracking nodes with services module
*/

/**
* Create a new timetracking node by services module request
*/
function _erpal_projects_service_timetracking_create($timetracking) {
  module_load_include('inc', 'services', 'resources/node_resource');
  
  $timetracking = _erpal_projects_service_map_timetracking_values($timetracking);
  _node_resource_create($timetracking);
}

/**
* Check access for creating a timetracking node
*/
function _erpal_projects_service_timetrackings_access($op, $args) {
  module_load_include('inc', 'services', 'resources/node_resource');
  
  $args = _erpal_projects_service_map_timetracking_values($args);

  return _node_resource_access($op, array(0 => $args)); //this is the access handler function of the node resource of the services module
  //@todo check with node access
  
}

/**
* Maps timetracking values to node  because the app webservice doesn't need to know the [und][0][value] strukture auf
* drupals data structure
*/
function _erpal_projects_service_map_timetracking_values($timetracking) {
  
  $final_tt = array('type' => 'erpal_timetracking');
  $final_tt['title'] = $timetracking['title'];
  if (isset($timetracking['body']))
    $final_tt['body'][LANGUAGE_NONE][0]['value'] = $timetracking['body'];
    
  if (isset($timetracking['duration']))
    $final_tt['field_timetracking_duration'][LANGUAGE_NONE][0]['value'] = $timetracking['duration'];
  
  if (isset($timetracking['task_id'])) {
    //as we use entity relation, we need to set the title with the nid, not only the nid...
    $task = node_load($timetracking['task_id']);
    $final_tt['field_timetracking_subject'][LANGUAGE_NONE][0]['target_id'] = ($task->title)." (".$task->nid.")";
  }
  
  if (isset($timetracking['date'])) {
    $final_tt['field_date_time'][LANGUAGE_NONE][0]['value']['date'] = date('m/d/Y', $timetracking['date']);
    $final_tt['field_date_time'][LANGUAGE_NONE][0]['value']['time'] = date('H:i', $timetracking['date']);
    
    /*
    $date_till = $timetracking['date'] + ($timetracking['duration'] * 60 * 60);
    $final_tt['field_date_time'][LANGUAGE_NONE][0]['value2']['date'] = date('m/d/Y', $date_till);
    $final_tt['field_date_time'][LANGUAGE_NONE][0]['value2']['time'] = date('H:i', $date_till);
    */
  }

  return $final_tt;
}
