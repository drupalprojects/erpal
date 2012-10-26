<?php

/**
* @file handles all functions dealing with timetracking nodes
*/

/**
* Implements callback for compute function for timetracking_button as computed field
*/
function computed_field_field_timetracking_button_compute(&$entity_field, $entity_type, $entity, $field, $instance, $langcode, $items) {
  if ($entity_type == 'node') {
    if ($entity->type == 'erpal_task') {
      $entity_field[0]['value'] = $entity->nid;
    }
  }
  
}

/**
* Get the sum of timetracking, @TODO even calculate for projects, actually only for tasks
*/
function erpal_projects_helper_summed_timetracking($node) {
  if ($node->type != 'erpal_task' && $node->type != 'erpal_project')
    return;
    
  if ($node->type == 'erpal_task') {
    $nids = array($node->nid);
  }  
  elseif ($node->type == 'erpal_project') {
    //get all tasks of the project
    $task_nids = _erpal_projects_helper_get_tasks($node->nid, true, true);
    $nids = array_keys($task_nids);
  }
    
  //get table for timetracking field_timetracking_duration
  $field_info = field_info_field('field_timetracking_duration');
  $sql_arr = $field_info['storage']['details']['sql']['FIELD_LOAD_CURRENT'];
  $field_name = array_keys($sql_arr);  
  $field_name_table_duration = $field_name[0];
  $value_field_duration = $sql_arr[$field_name_table_duration]['value'];
  
  //get table for field_timetracking_subject
  $field_info = field_info_field('field_timetracking_subject');
  $sql_arr = $field_info['storage']['details']['sql']['FIELD_LOAD_CURRENT'];
  $field_name = array_keys($sql_arr);  
  $field_name_table_subject = $field_name[0];
  $value_field_subject = $sql_arr[$field_name_table_subject]['target_id'];

  $query = db_select($field_name_table_duration,"f");
  $query->join($field_name_table_subject, 's', 'f.revision_id = s.revision_id');
  $query->condition('s.'.$value_field_subject, $nids);
  $query->addExpression("SUM(".$value_field_duration.")", 'time');
  $res = $query->execute()->fetchAssoc();
  
  $time = $res['time'];

  return $time;
}

/**
* Post execute handles timetracking view so we can replace an empty timetracking button computed field the timetracking button using the md5 checksum of the description
*/
function _erpal_projects_helper_view_timetracking_entites_post_execute(&$view) {

  foreach ($view->result as $delta=>$result_obj) {
    if (!$result_obj->field_field_timetracking_button) {
      //if we have a subject, use this, otherwise use the md5 of the subject.
      $subject_nid = $result_obj->node_timetracking_nid;
      $description = $result_obj->timetracking_description;
      if (!$subject_nid) {
        $subject_nid = md5($description);
      }  
      $display_output = _erpal_projects_helper_render_timetracking_button_field($subject_nid);
      $result_obj->field_field_timetracking_button[0] = array(
        'rendered' => array('#markup' => $display_output, '#access' => true),
        'raw' => array('value' => $subject_nid),
      );
      
      $view->result[$delta] = $result_obj;
    }
  }
}


/**
* Implements callback for display funciton for timetracking_button as computed field
*/
function computed_field_field_timetracking_button_display($field, $entity_field_item, $entity_lang, $langcode) {
  $nid = $entity_field_item['value'];

  $display_output = _erpal_projects_helper_render_timetracking_button_field($nid);
  return $display_output;
}

/**
* Callback for action with the same name definied in hook_action_info
*/
function erpal_projects_helper_timetracking_finalise_action(&$timetrackings, $context) {
  //first validate
  $errors = _erpal_projects_helper_timetracking_finalise_action_validate($timetrackings);

  if ($errors && is_array($errors) && count($errors)) {
    
    foreach ($errors as $id=>$errors_arr) {
      $entity = $errors_arr['entity'];
      $error_texts = $errors_arr['errors'];
      foreach ($error_texts as $text) {
        drupal_set_message($text, 'error');
      }
    }
    
    //drupal_goto($_GET['q']);
  } else {
    //no errors so finalise the timetrackings
    foreach ($timetrackings as $timetracking) {
      
      //if timetracking entity has endtime set but no duration (it should be 0 or not set, just delete the entity
      if ($timetracking->time_end && !$timetracking->duration) {
        $timetracking->delete();
        continue;
      }
      
      
      $timetracking_node = _erpal_projects_helper_timetracking_finalise($timetracking);
      //if timetracking node was created, delete the temporary timetracking entity
      if ($timetracking_node->nid) {
        $timetracking->delete();
      } else {
        $timetracking_link = l($timetracking->defaultLabel(), 'timetracking/'.$timetracking->timetracking_id.'/edit');
        drupal_set_message(t('Timetracking !timetracking_link could not be finalised.', array('!timetracking_link' => $timetracking_link)), 'error');
      }
    }
  }
  
}

/**
* Renders the html code for timetracking button on tasks
*/
function _erpal_projects_helper_render_timetracking_button_field($nid) {
  if (!is_numeric($nid)) {  //it could be an MD5 has
    //we have no subject but timetracking can be started without subject!
    $node_type = false;
    $node = false;
  } else {  
    $node = node_load($nid);
    $node_type = $node->type;
  }
  
  if ($node_type == 'erpal_task' || !$node_type) {
    //add field to show the timetracking toggle button   
    $has_timetracking_active = _erpal_projects_helper_task_has_timetracking_entity_active($nid, $tracked_time);
    $has_timetracking_active_str = $has_timetracking_active ? 'on' : 'off';

    $timetracking_button = theme('timetracking_button', array('entity_type' => 'node', 'entity_id' =>$nid, 'state' => $has_timetracking_active_str, 'duration' => $tracked_time));
    
    return $timetracking_button;
  }
  
}

/**
* Checks if there are timetracking entity (temporary) that have the given node as subject_id and have no duration set
* @return false if no timetracking entities are running, otherwise true
*/
function _erpal_projects_helper_task_has_timetracking_entity_active($nid, &$tracked_time) {
  global $user;
  
  if (!$nid) { //timetrackings without subject
    $timetracking_ids = _timetrackings_by_user($user->uid, false);
    //check if there is one timetracking without subject
    $timetracking_ids_no_subject = array();
    foreach ($timetracking_ids as $timetracking_id) {
      $timetracking = timetracking_load($timetracking_id);
      if (!$timetracking->subject_id)
        $timetracking_ids_no_subject[] = $timetracking_id;
    }
    
    $timetracking_ids = $timetracking_ids_no_subject;
  } else
    $timetracking_ids = _timetrackings_by_user($user->uid, $nid);
  
  //load all entities and calculate the total time.
  $timetrackings = timetracking_load_multiple($timetracking_ids);
  $total = 0;
  $has_running = false;
  foreach ($timetrackings as $timetracking) {
    if ($timetracking->time_end) {
      $duration = $timetracking->duration;
    } else {
      $duration = (time() - $timetracking->time_start) / (60*60);
      $has_running = true;
    }
      
    $total += $duration;
  }

  $tracked_time = round($total, 2);

  return $has_running;
}


/**
* Add elements to select projects and tasks
*/
function _erpal_projects_helper_alter_timetracking_quick_form(&$form, $form_state, $project_nid=false) {
  //first add a project select box
  $projects = _erpal_projects_helper_get_all_projects(true);
  
  $projects[0] = ' ';
  $form['project_nid'] = array( 
    '#type' => 'select',
    '#options' => $projects,
    '#title' => t('Project'),
    '#default_value' => 0,
    '#ajax' => array(
      'callback' => '_erpal_projects_helper_timetracking_ajax_project_select',
      'wrapper' => 'timetracking_subject_wrapper',
      'effect' => 'fade',
      'method' => 'replace',
    ),
  );
  
  //replace the subject field with autocomplete for tasks
  $form['subject']['#autocomplete_path'] = _erpal_projects_helper_get_tasks_by_project_autocomplete_path($project_nid);
  $form['subject']['#prefix'] = '<div id="timetracking_subject_wrapper">';
  $form['subject']['#suffix'] = '</div>';
}

/**
* Get autocomplete path for tasks by project
*/
function _erpal_projects_helper_get_tasks_by_project_autocomplete_path($project_nid=0) {
  return 'projects/tasks/autocomplete/'.$project_nid;
}

/**
* Submit callback when project is chosen in timetracking block and we want wo actualise the autocomplete path for tasks
*/
function _erpal_projects_helper_timetracking_ajax_project_select($form, $form_state) {
  $values = $form_state['values'];
  $project_nid = $values['project_nid'];  

  //if there is a project nid, subject will be selected by select box, not autocomplete
  if ($project_nid) {    
    //we do this because just switching to #type = select doesn't work....so introduce a new element
    $form['subject_select']['#prefix'] = $form['subject']['#prefix'];
    $form['subject_select']['#suffix'] = $form['subject']['#suffix'];
    $form['subject_select']['#type'] = 'select';    
    $form['subject_select']['#name'] = 'subject';
    $task_nids = _erpal_projects_helper_get_tasks_by_project($project_nid);
    $tasks = _erpal_basic_helper_nids_for_form_select($task_nids);
    $form['subject_select']['#options'] = $tasks;
    return $form['subject_select'];
  } else {
    $form['subject']['#autocomplete_path'] = _erpal_projects_helper_get_tasks_by_project_autocomplete_path($project_nid);
  }

  return $form['subject'];
}

/**
* Create a real timetracking node from a temporary timetracking entity
*/
function _erpal_projects_helper_timetracking_finalise($timetracking) {
  $timetracking->close();  //it should already be closed
  $subject_nid = $timetracking->subject_id;
  $subject_node = node_load($subject_nid);
  //create a timetracking
  $tt = new stdClass();    
  $tt->language = LANGUAGE_NONE;
  $tt->type = 'erpal_timetracking';
  $tt->title = $timetracking->description ? $timetracking->description : $subject_node->title;
  $tt->field_timetracking_subject[LANGUAGE_NONE][]['target_id'] = $timetracking->subject_id;
  $tt->field_date_time[LANGUAGE_NONE][0]['value'] = $timetracking->time_start;
  $tt->field_date_time[LANGUAGE_NONE][0]['value2'] = $timetracking->time_end;
  $tt->field_billing_duration[LANGUAGE_NONE][0]['value'] = $timetracking->duration;
  $tt->uid = $timetracking->uid;
  $tt->created = $timetracking->created;
  $tt->changed = $timetracking->changed;
 
  node_object_prepare($tt);
  node_save($tt); 
  
  return $tt;
}

/**
* Validate all timetracking of the bulk operation erpal_projects_helper_timetracking_finalise_action
* @param $timetrackings
* @return array of array with the timetracking and an errormessage 
*/
function _erpal_projects_helper_timetracking_finalise_action_validate($timetrackings) {
  $errors = false;
  
  foreach ($timetrackings as $timetracking) {
    //error if timetracking has no subject
    $timetracking_link = l($timetracking->defaultLabel(), 'timetracking/'.$timetracking->timetracking_id.'/edit', array('query' => array('destination' => $_GET['q'])));
    if (!$timetracking->subject_id) {      
      $errors[$timetracking->timetracking_id]['entity'] = $timetracking;
      $errors[$timetracking->timetracking_id]['errors'][] = t('To finalise a timetracking, ensure that a subject task is set for !timetracking_link', array('!timetracking_link' => $timetracking_link));      
    } elseif (!$timetracking->time_end) {
      //if we dont have a duration the timetracking is still running and cannot be finalised!
      $errors[$timetracking->timetracking_id]['entity'] = $timetracking;
      $errors[$timetracking->timetracking_id]['errors'][] = t('To finalise the timetracking !timetracking_link, ensure that it is not still tracking the time!', array('!timetracking_link' => $timetracking_link));      
    }
  }
  
  return $errors;
}

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
  
  //if node doesn't have a duration, but billing duration, set duration to billing duration.
  if (!$duration && $billing_duration && !(isset($node->nid) && $node->nid)) {
    $node->field_timetracking_duration[LANGUAGE_NONE][0]['value'] = $billing_duration;
  }
  
  //may be the duration was set to -1 in _erpal_projects_billable_book_timetracking_to_budget which signals that we dont want to change that value in presave routine.
  if ($node->field_timetracking_duration[LANGUAGE_NONE][0]['value'] < 0)
    $node->field_timetracking_duration[LANGUAGE_NONE][0]['value'] = 0; 
  
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
* Return all timetracking nids that reference directely one of the given nids
* @param $date_from if set, the date where to start for the timetracking field_date_time[value]
* @param $date_till if set, the date where to end for the timetracking field_date_time[values2]
*/
function _erpal_projects_helper_get_direct_timetrackings_by_date_range($nids, $date_from, $date_till) {

  $timetracking_nids = array();

  if (!$nids || !count($nids))
    return $timetracking_nids;

  if (!$date_from)
    $date_from = 0;
  if (!$date_till)
    $date_till = PHP_INT_MAX;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_timetracking')
  ->fieldCondition('field_timetracking_subject', 'target_id', $nids, 'IN')
  ->fieldCondition('field_date_time', 'value', $date_from, '>=')
  ->fieldCondition('field_date_time', 'value2', $date_till, '<=')
  ->fieldOrderBy('field_date_time', 'value', 'ASC')
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