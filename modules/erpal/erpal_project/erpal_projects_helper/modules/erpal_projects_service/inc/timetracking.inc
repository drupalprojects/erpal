<?php

/**
 * @file all functions needed to make erpal_timtrackings accessible by services
 * @author Oskar Bechtold <bechtold@brightsolutions.de>
 * @copyright (c) 2013
 */

/**
 * Callback for retrieving single erpal_task resources.
 *
 * @param int $id node id of the timetracking
 * @return array timetracking prepared for output
 */
function _erpal_projects_service_timetracking_retrieve($id) {
  $task_node = _erpal_projects_service_timetracking_out((int) $id, TRUE);

  return $task_node;
}

/**
 * Callback for returning a list of timetrackings considering given filters
 * @param int $start Deliver data from nth element, defaults to 0.
 * @param int $count Delive n elements, defaults to PHP_INT_MAX
 * @param int $changed_since Deliver all elemets changed after date  x. Format: UNIX timestamp in UTC
 * @param bool $details whether or not to return timtrackings with more detail
 * @return array timetrackings prepared for output
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
 * retrieves a project node and returns simple data
 * @param int $nid the node id of the timetracking
 * @param bool $details whether or not to return the timetrackings with detail
 * @return array timetrackings prepared for output
 * @author  Oskar Bechtold
 */
function _erpal_projects_service_timetracking_out($nid, $details = FALSE) {
  $timetracking = node_load($nid);
  $timetracking_out = array();
  $timetracking_out['title'] = $timetracking->title;
  $timetracking_out['timetracking'] = url('rest/projects/timetracking/' . $timetracking->nid, array('absolute' => TRUE));
  $timetracking_out['duration'] = (float)$timetracking->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
  if ($details) {
    $timetracking_out['startdate'] = (int)$timetracking->field_date_time[LANGUAGE_NONE][0]['value'];
    $timetracking_out['enddate'] = (int)$timetracking->field_date_time[LANGUAGE_NONE][0]['value2'];
    $timetracking_out['billing_duration'] = (float)$timetracking->field_billing_duration[LANGUAGE_NONE][0]['value'];
    $timetracking_out['task'] = url('rest/projects/task/' . $timetracking->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'], array('absolute' => TRUE));
    $timetracking_out['project_tags'] = (int)$timetracking->field_project_tags[LANGUAGE_NONE][0]['tid'];
  }
  return $timetracking_out;
}

/**
 * Create a new timetracking node by services module request
 * @param array $timetrackings the data delivered by the webservice, $timetracking['timetracking'] must be an array of the trackings
 * @return array the new trackings prepared for output
 * @TODO: maybe use drupal_form_submit or _node_resource_create to have validation instead of node_save
 */
function _erpal_projects_service_timetracking_create($timetracking) {
  global $user;
  $returns = array();
  foreach ($timetracking['timetracking'] as $value) {
    $newTimetracking = (object) NULL;
    $newTimetracking->uid = $user->uid;
    $newTimetracking->type = 'erpal_timetracking';
    $newTimetracking->title = $value['title'];
    $newTimetracking->field_date_time[LANGUAGE_NONE][0]['value'] = $value['startdate'];
    $newTimetracking->field_date_time[LANGUAGE_NONE][0]['value2'] = $value['enddate'];
    $task = preg_split('/\//', $value['task']);
    $newTimetracking->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'] = $task[6];

    if (isset($value['project_tags'])) {
      $newTimetracking->field_project_tags[LANGUAGE_NONE][0]['tid'] = $value['project_tags'];
    } else {
      $tasknode = node_load($task[6]);
      $task = entity_metadata_wrapper('node', $tasknode);
      if (is_object($task->field_project_tags->value())) {
        $newTimetracking->field_project_tags[LANGUAGE_NONE][0]['tid'] = $task->field_project_tags->value()->tid;
      }
    }

    node_save($newTimetracking);
    $returnnode['title'] = $newTimetracking->title;
    $returnnode['timetracking'] = url('rest/projects/timetracking/' . $newTimetracking->nid, array('absolute' => TRUE));
    $returnnode['duration'] = $newTimetracking->field_timetracking_duration[LANGUAGE_NONE][0]['value'];
    $returns[] = $returnnode;
  }
  return $returns;
}

/**
 * Returns timetracking info for current user.
 *
 * @return array
 *   An array contains:
 *    -day: amount of working hours for current day.
 *    -week: amount of working hours for current week.
 *    -month: amount of working hours for current month.
 *    -current: an array with info about current active task.
 *    -working_days: an array with info about working days.
 */
function _erpal_projects_service_timetracking_statistics() {
  global $user;

  $day = 0;
  $week = 0;
  $month = 0;
  $current = array();

  // Prepare date ranges.
  $today_range = array(
    strtotime(date('m/d/Y 00:00:00')),
    strtotime(date('m/d/Y 23:59:59')),
  );
  $week_range = array(
    strtotime(date('m/d/Y 00:00:00', strtotime("last Monday"))),
    strtotime(date('m/d/Y 23:59:59', strtotime("next Sunday"))),
  );
  $month_range = array(
    strtotime(date('m/d/Y 00:00:00', strtotime("first day of this month"))),
    strtotime(date('m/d/Y 23:59:59', strtotime("last day of this month"))),
  );
  $range = array(
    strtotime(date('m/d/Y 00:00:00', strtotime("first day of this month") - (7 * 86400))), // First day of month - 7 days to include timetrackings of current week.
    strtotime(date('m/d/Y 23:59:59', strtotime("last day of this month") + (7 * 86400))), // Last day of month + 7 days to include timetrackings of current week.
  );

  // Get all unbooked timetrackings for current month +/-7 days.
  $query = db_select('timetracking', 't');
  $query->fields('t', array('time_start', 'time_end', 'duration', 'subject_id', 'uid'))
    ->condition('time_start', $range[0], '>')
    ->condition('time_start', $range[1], '<=')
    ->condition('uid', $user->uid)
    ->orderBy('timetracking_id', 'DESC'); // To put active tt to top.
  $unbooked = $query->execute()->fetchAll();

  if (!empty($unbooked)) {
    // Get first(current) timetracking, set duration if it's not finished.
    if ($unbooked[0]->time_end == 0) {
      $unbooked[0]->duration = (REQUEST_TIME - $unbooked[0]->time_start) / 3600;
    }
    $wrapper = entity_metadata_wrapper('node', $unbooked[0]->subject_id);
    $estimate = $wrapper->field_estimated_time->raw();

    // Store data in current array.
    $current = array(
      'id' => $unbooked[0]->subject_id,
      'amount' => 0, // Define default value.
      'title' => $wrapper->label(),
      'estimate' => !empty($estimate) ? $estimate : 0,
      'active' => $unbooked[0]->time_end == 0,
    );

    // Calculate hours for unbooked timetrackings.
    foreach($unbooked as $tt) {
      if ($tt->time_start > $today_range[0] && $tt->time_start <= $today_range[1]) {
        $day += $tt->duration;
      }
      if ($tt->time_start > $week_range[0] && $tt->time_start <= $week_range[1]) {
        $week += $tt->duration;
      }
      if ($tt->time_start > $month_range[0] && $tt->time_start <= $month_range[1]) {
        $month += $tt->duration;
      }
      if ($current['id'] == $tt->subject_id) {
        $current['amount'] += $tt->duration;
      }
    }

    // Get duration for booked current task.
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->propertyCondition('type', 'erpal_timetracking')
      ->propertyCondition('uid', $user->uid)
      ->fieldCondition('field_timetracking_subject', 'target_id', $current['id'])
      ->execute();
    $nids = !empty($result['node']) ? array_keys($result['node']) : array();
    foreach($nids as $nid) {
      $wrapper = entity_metadata_wrapper('node', $nid);
      $current['amount'] += $wrapper->field_timetracking_duration->value();
    }
    $current['amount'] = number_format($current['amount'], 2);
  }

  // Get booked timetrackings for current month +/-7 days.
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'erpal_timetracking')
    ->propertyCondition('uid', $user->uid)
    ->fieldCondition('field_date_time', 'value', $range[0], '>')
    ->fieldCondition('field_date_time', 'value', $range[1], '<=')
    ->execute();

  $nids = !empty($result['node']) ? array_keys($result['node']) : array();
  foreach($nids as $nid) {
    $wrapper = entity_metadata_wrapper('node', $nid);
    $duration = $wrapper->field_timetracking_duration->value();
    $date = $wrapper->field_date_time->value->value();

    // Calculate hours.
    if ($date > $today_range[0] && $date <= $today_range[1]) {
      $day += $duration;
    }
    if ($date > $week_range[0] && $date <= $week_range[1]) {
      $week += $duration;
    }
    if ($date > $month_range[0] && $date <= $month_range[1]) {
      $month += $duration;
    }
  }

  // Calculate working days in month.
  $working_days = 0;
  $working_current = 0;
  $startTimestamp = strtotime("first day of this month");
  $endTimestamp = strtotime("last day of this month");
  for ($i = $startTimestamp; $i <= $endTimestamp; $i = $i + (60 * 60 * 24)) {
    if (date("N", $i) <= 5) {
      $working_days++;
    }
    if (date("N", $i) <= 5 && $i < REQUEST_TIME) {
      $working_current++;
    }
  }

  return array(
    'day' => number_format($day, 2),
    'week' => number_format($week, 2),
    'month' => number_format($month, 2),
    'current' => $current,
    'working_days' => array('current' => $working_current, 'all' => $working_days),
  );
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

