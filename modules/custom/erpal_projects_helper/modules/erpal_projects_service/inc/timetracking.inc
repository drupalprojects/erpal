<?php

/**
 * @file all functions needed to integrate timetracking nodes with services module
 */

/**
 * Callback for retrieving single erpal_task resources.
 *
 * @param int $id
 * @return object
 */
function _erpal_projects_service_timetracking_retrieve($id) {
  $task_node = _erpal_projects_service_timetracking_out((int) $id, TRUE);

  return $task_node;
}

/**
 * Callback for returning a list of timetrackings considering given filters
 * @param int $start Deliver data from nth element, defaults to 0.
 * @param int $count Delive n elements
 * @param int $changed_since Deliver all elemets changed after date  x. Format: UNIX timestamp in UTC
 */
function _erpal_projects_service_timetracking_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = FALSE) {
  module_load_include('inc', 'erpal_projects_helper', 'inc/timetracking');

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
          ->propertyCondition('type', 'erpal_timetracking')
          ->range((int) $start, (int) $count)
          ->propertyCondition('changed', (int) $changed_since, '>=');

  $entities = $query->execute();

  $projects_out = array();

  if (!empty($entities['node'])) {
    //prepare for output!
    foreach (array_keys($entities['node']) as $nid) {
      $projects_out[] = _erpal_projects_service_timetracking_out($nid, $details);
    }
  }

  return $projects_out;
}

/**
 * retrieves a project node and returns only simple data
 *
 * @return array with title and url
 * @author  Oskar Bechtold
 */
function _erpal_projects_service_timetracking_out($nid, $details = FALSE) {
  $timetracking = node_load($nid);
  dpm($timetracking);
  $timetracking_out = array();
  $timetracking_out['title'] = $timetracking->title;
  $timetracking_out['timetracking'] = url('rest/projects/timetracking/' . $timetracking->nid, array('absolute' => TRUE));
  $timetracking_out['duration'] = $timetracking->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
  if ($details) {
    $timetracking_out['startdate'] = $timetracking->field_date_time[LANGUAGE_NONE][0]['value'];
    $timetracking_out['enddate'] = $timetracking->field_date_time[LANGUAGE_NONE][0]['value2'];
    $timetracking_out['timezone'] = $timetracking->field_date_time[LANGUAGE_NONE][0]['timezone'];
    $timetracking_out['billing_duration'] = $timetracking->field_billing_duration[LANGUAGE_NONE][0]['value'];
    $timetracking_out['subject'] = $timetracking->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
    $timetracking_out['project_tags'] = $timetracking->field_project_tags[LANGUAGE_NONE][0]['tid'];
  }
  return $timetracking_out;
}

/**
 * Create a new timetracking node by services module request
 */
function _erpal_projects_service_timetracking_create($timetracking) {
  $returns = array();
  foreach ($timetracking['timetracking'] as $value) {
    $newTimetracking = (object) NULL;
    $newTimetracking->type = 'erpal_timetracking';
    $newTimetracking->title = $value['title'];
    $newTimetracking->field_date_time[LANGUAGE_NONE][0]['value'] = $value['startdate'];
    $newTimetracking->field_date_time[LANGUAGE_NONE][0]['value2'] = $value['enddate'];
    $newTimetracking->field_date_time[LANGUAGE_NONE][0]['timezone'] = $value['timezone'];
    $newTimetracking->field_billing_duration[LANGUAGE_NONE][0]['value'] = $value['billing_duration'];
    $newTimetracking->field_timetracking_duration[LANGUAGE_NONE][0]['value'] = $value['duration'];
    $newTimetracking->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'] = $value['subject'];
    $newTimetracking->field_project_tags[LANGUAGE_NONE][0]['tid'] = $value['project_tags'];
    node_save($newTimetracking);
    $returnnode['title'] = $newTimetracking->title;
    $returnnode['timetracking'] = url('rest/projects/timetracking/' . $newTimetracking->nid, array('absolute' => TRUE));
    $returnnode['duration'] = $newTimetracking->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
    $returns[] = $returnnode;
  }
  return $returns;
}

/**
 * Check access for creating a timetracking node
 */
function _erpal_projects_service_timetrackings_access($op, $args) {
//  module_load_include('inc', 'services', 'resources/node_resource');
//  
//  $args = _erpal_projects_service_map_timetracking_values($args);
//
//  return _node_resource_access($op, array(0 => $args)); //this is the access handler function of the node resource of the services module
//  //@todo check with node access
  module_load_include('inc', 'services', 'resources/node_resource');
  return _node_resource_access($op, $args); //this is the access handler function of the node resource of the services module
  //@todo check with node access
}

///**
//* Maps timetracking values to node  because the app webservice doesn't need to know the [und][0][value] strukture auf
//* drupals data structure
//*/
//function _erpal_projects_service_map_timetracking_values($timetracking) {
//  
//  $final_tt = array('type' => 'erpal_timetracking');
//  $final_tt['title'] = $timetracking['title'];
//  if (isset($timetracking['body']))
//    $final_tt['body'][LANGUAGE_NONE][0]['value'] = $timetracking['body'];
//    
//  if (isset($timetracking['duration']))
//    $final_tt['field_timetracking_duration'][LANGUAGE_NONE][0]['value'] = $timetracking['duration'];
//  
//  if (isset($timetracking['task_id'])) {
//    //as we use entity relation, we need to set the title with the nid, not only the nid...
//    $task = node_load($timetracking['task_id']);
//    $final_tt['field_timetracking_subject'][LANGUAGE_NONE][0]['target_id'] = ($task->title)." (".$task->nid.")";
//  }
//  
//  if (isset($timetracking['date'])) {
//    $final_tt['field_date_time'][LANGUAGE_NONE][0]['value']['date'] = date('m/d/Y', $timetracking['date']);
//    $final_tt['field_date_time'][LANGUAGE_NONE][0]['value']['time'] = date('H:i', $timetracking['date']);
//    
//    /*
//    $date_till = $timetracking['date'] + ($timetracking['duration'] * 60 * 60);
//    $final_tt['field_date_time'][LANGUAGE_NONE][0]['value2']['date'] = date('m/d/Y', $date_till);
//    $final_tt['field_date_time'][LANGUAGE_NONE][0]['value2']['time'] = date('H:i', $date_till);
//    */
//  }
//
//  return $final_tt;
//}
