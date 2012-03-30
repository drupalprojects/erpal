<?php

/**
* @file handles all functions dealing with timetracking nodes
*/

/**
* Presave hook a timetracking node 
*/
function erpal_projects_helper_node_presave_timetracking($node) {
 
  //if no value is available, we caclulate the value using start and end time
  $start_time = $node->field_date_time[LANGUAGE_NONE][0]['value'];
  $end_time = $node->field_date_time[LANGUAGE_NONE][0]['value2'];
  
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