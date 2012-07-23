<?php

/**
* @file handles all functions dealing with timetracking nodes
*/

/**
* Presave hook a timetracking node 
*/
function erpal_projects_helper_node_presave_timetracking($node) {
 
  if (isset($node->nid)) {
    //load the old timetracking node to add its billing_duration, not the new current one
    $old_node = node_load($node->nid);
    _erpal_projects_helper_restore_timetracking_budget($old_node);
  }
  
  //if no value is available, we caclulate the value using start and end time
  $start_time = $node->field_date_time[LANGUAGE_NONE][0]['value'];
  $end_time = isset($node->field_date_time[LANGUAGE_NONE][0]['value2']) ? $node->field_date_time[LANGUAGE_NONE][0]['value2'] : $node->field_date_time[LANGUAGE_NONE][0]['value'];
  
  $diff_duration = $end_time - $start_time;
  $diff_duration = $diff_duration / (60 * 60);//calculate hours
  $time_duration = round($diff_duration, 2); //round with 2 digits
  
  $duration = 0;
  if (isset($node->field_timetracking_duration[LANGUAGE_NONE][0]))
    if (isset($node->field_timetracking_duration[LANGUAGE_NONE][0]['value']))
      $duration = $node->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
  
  if (!$duration)
    $node->field_timetracking_duration[LANGUAGE_NONE][0]['value'] = $time_duration;
  
  $billing_duration = 0;
  if (isset($node->field_billing_duration[LANGUAGE_NONE][0]))
    if (isset($node->field_billing_duration[LANGUAGE_NONE][0]['value']))
      $billing_duration = $node->field_billing_duration[LANGUAGE_NONE][0]['value'];
  
  if (!$billing_duration)
    $node->field_billing_duration[LANGUAGE_NONE][0]['value'] = $node->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
  
  return $duration;
}


/**
* @param a timetracking node
* @return a float value with the billing duration. If billing duration is set, the value is returned itself, otherwise the
*   duration value is set. This is the duration in hours
*/
function _erpal_projects_helper_get_billing_duration($node) {

  $billing_duration = $node->field_billing_duration[LANGUAGE_NONE][0]['value'];
  
  if ($billing_duration)
    return $billing_duration;
    
  $duration = $node->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
  
  if ($duration)
    return $duration;
    
  //if no value is available, we caclulate the value using start and end time
  $start_time = $node->field_date_time[LANGUAGE_NONE][0]['value'];
  $end_time = $node->field_date_time[LANGUAGE_NONE][0]['value2'];
  
  $duration = $end_time - $start_time;
  $duration = $duration / (60 * 60);//calculate hours
  $duration = round($duration, 2); //round with 2 digits
  
  return $duration;
}

/**
* Return all timetracking nids that reference directely one of the given nids
*/
function _erpal_projects_helper_get_direct_timetrackings($nids) {

  $timetracking_nids = array();
  
  if (!$nids || !count($nids))
    return $timetracking_nids;
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_timetracking')
  ->fieldCondition('field_timetracking_subject', 'target_id', $nids, 'IN')
  ->addMetaData('account', user_load(1)); // run the query as user 1 to get all nodes
  
  $result = $query->execute();

  if (isset($result['node'])) {
    $timetracking_nids = array_keys($result['node']);    
  }
  
  return $timetracking_nids;
}

/**
* Return all timetrackings that reference to a given budget_id
* @param $budget_id the budget id that the returned timetracking nodes must referr to
* @return an array with all nids of timetrackgins
*/
function _erpal_projects_helper_get_timetrackings_by_budget($budget_id) {
  $timetracking_nids = array();
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_timetracking')
  ->fieldCondition('field_budget', 'target_id', $budget_id)
  ->addMetaData('account', user_load(1)); // run the query as user 1 to get all nodes
  
  $result = $query->execute();

  if (isset($result['node'])) {
    $timetracking_nids = array_keys($result['node']);    
  }
  
  return $timetracking_nids;
}