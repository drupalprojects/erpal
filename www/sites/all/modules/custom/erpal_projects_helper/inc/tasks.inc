<?php

/**
* @file adds some query functions for tasks and other functions for erpal_task nodes
*/

/**
* Callback for autocomplete path for tasks by project
*/
function _erpal_projects_helper_tasks_autocomplete($project_nid, $text) {
  $project_nid = arg(3) ? arg(3) : 0; //if it is not set, return all tasks

  $task_nids = _erpal_projects_helper_get_tasks_by_project($project_nid, $text, 20); //limit to only 20 rows
  
  $matches = _erpal_basic_helper_nids_for_form_select($task_nids);
  
  // return for JS
  drupal_json_output($matches);
}

/**
* Access callback for validating access to task by project autocomplete path
*/
function _erpal_projects_helper_tasks_autocomplete_access() {
  return user_access('access tasks view');
}

/**
* Function returns a list of tasks respecting the given params as filter. 
*
* @param array $task_states array of all states tasks are returned with.
* @param array with uids $uid user ID to return only tasks a user is assigned to
* @param int $changed all projects that have changed since the variable
* @param int $project_nid only tasks of the given project are returned
* @return array an array of erpal_project objects matching the filter
*/
function _erpal_projects_helper_get_tasks_by_assigned_user($task_states=array(), $uids=array(), $changed=0, $project_nid=0) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_task')
  ->propertyCondition('status', 1);

  if (count($uids) > 0) {
    $query->fieldCondition('field_task_assigned_users', 'target_id', $uids, 'IN');
  }
  
  if (count($task_states) > 0) {
    $query->fieldCondition('field_task_status_term', 'tid', $task_states, 'IN');
  }
  
  if ($changed) {
    $query->propertyCondition('changed', $changed, '>=');  //all entites after the given changed date
  }
  
  if ($project_nid) {
    $query->fieldCondition('field_project_ref', 'target_id', $project_nid);
  }
  
  $result = $query->execute();

  $task_nodes = array();
  if (isset($result['node'])) {
    $task_nids = array_keys($result['node']);
    $task_nodes = entity_load('node', $task_nids);
  }
 
  return $task_nodes;
}

/**
* Return tasks by project
* @param $project_nid the nid of the project we want the tasks for
* @param $like_title a substring the task title must contain
* @return array with nids of tasks referencing the given project_nid
*/
function _erpal_projects_helper_get_tasks_by_project($project_nid, $like_title=false, $limit=false) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_task')
  ->propertyCondition('status', 1);
  
  if ($project_nid)
    $query->fieldCondition('field_project_ref', 'target_id', $project_nid);
   
  if ($like_title) {
    //add like condition
    $query->propertyCondition('title', '%'.$like_title.'%', 'LIKE');
  }
  
  if ($limit)
    $query->range(0,$limit); //limit rows, if set!
   
  $result = $query->execute();

  $task_nids = array();
  if (isset($result['node'])) {
    $task_nids = array_keys($result['node']);
  }

  return $task_nids;
}

/**
* Checks if node is a ticket
*/
function _erpal_projects_helper_is_ticket($node) {
  if ($node->type != 'erpal_task')
    return false;
  
  $is_ticket = isset($node->field_is_ticket[LANGUAGE_NONE][0]['value']) ? $node->field_is_ticket[LANGUAGE_NONE][0]['value'] : false;
  
  return $is_ticket;
}

/**
* Adds erpal context links on task view
*/
function _erpal_projects_helper_add_task_links(&$links, $node) {
  if (is_numeric($node))
    $node = node_load($node);
  
  if ($node->type != 'erpal_task')
    return;
  
  $is_ticket = _erpal_projects_helper_is_ticket($node);
  
  //back to list links
  if ($is_ticket) {
    //back to tickets
    $list_type = 'tickets';
    $list_label = t('ticket');
  } else {
    //back to tasks
    $list_type = 'tasks';
    $list_label = t('task');
  }
  
  $project_nid = $node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
  $back_to_list = l(
    t('Go to !type list', array('!type' => $list_label)), 
    'node/'.$project_nid.'/'.$list_type
  );  
  $links[] = $back_to_list;
  
  //add subtask / Subticket link
  if (user_access('create erpal_task content')) {
    $project_nid = $node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
    $subtask_link = l(
      t('Create a sub!type', array('!type' => $list_label)), 
      'node/add/erpal-task',
      array(
        'query' => array(
          'field_parent' => $node->nid,
          'field_project_ref' => $project_nid,
          'is_ticket' => $is_ticket,
        ),
      )
    );  
    $links[] = $subtask_link;
  }
  
  //quick timetracking
  if (user_access('use quick timetracking')) {
    $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($node->nid);
    $links[] = $timetracking_button;
  }

}

/**
* Link to add a Subticket
*/


/**
* Return all tasks
* @return array with nids of tasks referencing the given project_nid if set
*/
function _erpal_projects_helper_get_tasks($project_nid=false, $for_options=false, $ignore_permissions=false) {
  //@TODO my be add static cache for better performance on multiple calls
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_task')
  ->propertyCondition('status', 1);  
  //@TODO maybe add access control to query
  
  if ($ignore_permissions) {
    $query->addMetaData('account', user_load(1));
  }
  
  if ($project_nid) {
    $query->fieldCondition('field_project_ref', 'target_id', $project_nid);
  }
    
  $result = $query->execute();

  $task_nids = array();
  if (isset($result['node']) && count($result['node'])) {
    $task_nids = array_keys($result['node']);
  

    //now we have task nids, now execute a query to get nid, title pairs
    $result = db_select('node', 'n')
      ->fields('n', array('nid', 'title'))
      ->condition('nid', $task_nids, 'IN')
      ->orderBy('title', 'ASC')//ORDER BY created
      ->execute()
      ->fetchAll();
  }
    
  $ret = array();
  if ($for_options) {
    foreach ($result as $obj) {
      $ret[$obj->nid] = ($obj->title);
    }
  } else
    return $result;

  return $ret;
}

/**
* Return all tasks of a project that have no parent at all or no parent of type erpal_task
*/
function _erpal_projects_helper_get_tasks_of_project_having_no_task_parent($project_node) {
  
  $res = db_query('SELECT n.nid FROM {node} n 
    LEFT JOIN {field_data_field_project_ref} project ON n.vid=project.revision_id
    LEFT JOIN {field_data_field_parent} parent ON n.vid=parent.revision_id
    LEFT JOIN {node} node_parent_type ON node_parent_type.vid=parent.revision_id
    WHERE project.field_project_ref_target_id=:project_nid AND
    ((parent.field_parent_target_id <> :parent_node_type) OR parent.field_parent_target_id IS NULL)
  ', array(':project_nid' => $project_node->nid, ':parent_node_type' => 'erpal_task'))
    ->fetchAll();
  
  $nids = array();
  foreach ($res as $nid_obj) {
    $nids[] = $nid_obj->nid;
  }
 
  return $nids;
}


/**
* Presave function for tasks
*/
function erpal_projects_helper_node_presave_task($task_node) {
  _erpal_projects_helper_task_set_project($task_node);
}

/**
* Set the project according to the parents project
*/
function _erpal_projects_helper_task_set_project($task_node) {
  
  if (!isset($task_node->field_parent[LANGUAGE_NONE][0]['target_id']))
    return;
    
  $parent_nid = $task_node->field_parent[LANGUAGE_NONE][0]['target_id'];
  $parent_node = node_load($parent_nid);
  $project_nid = _erpal_projects_helper_has_project($parent_node);
  
  if ($project_nid) {
    $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'] = $project_nid;
  }
}

/**
* returns the activity which is related to a task over its related project
*/
function _erpal_projects_helper_get_activity_by_task($task_node) {
  $activity_node = false;
  if (isset($task_node->field_project_ref[LANGUAGE_NONE][0])) {
    $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
    $project_node = node_load($project_nid);
  }
  
  $activity_node = _erpal_projects_helper_get_activity_by_project($project_node);
  
  return $activity_node;
}

/**
* Prepopulate some fields on task edit / insert form
*/
function _erpal_projects_helper_task_edit_form_prepopulate(&$form) {
  //IS_TICKET
  $key = 'field_is_ticket';
  if (isset($_GET[$key])) {    
    //prepopulate the ticket field
    $value = $_GET[$key] ? 1 : 0;
    $form['field_is_ticket'][LANGUAGE_NONE]['#default_value'] = $value;
    //now hide it
    $form['field_is_ticket'][LANGUAGE_NONE]['#type'] = 'value';
  }

  //PROJECT_REF
  $key = 'field_project_ref';
  if (isset($_GET[$key]) && $_GET[$key]) {    
    //prepopulate the project_ref field
    
    $value = _erpal_basic_helper_autocomplete_string_from_nid($_GET[$key]);
    $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'] = $value;
    //now hide it
    $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
  }
}

/**
* Alters the tasks form
*/
function _erpal_projects_helper_task_node_form_alter(&$form, &$form_state) {
  //only if node will be new created
  $nid = $form['nid']['#value'];
  if (!$nid) {
    //if parent is already set, hide the project field, but preset it so pricing information can be reloaded!
    if (isset($form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value']))
      if ($form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value']) {
        $parent_nid = $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value'];
        $parent_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($parent_nid);
        $parent_node = node_load($parent_nid);
        $project_nid = _erpal_projects_helper_has_project($parent_node);          

        $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
        $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'] = _erpal_basic_helper_autocomplete_string_from_nid($project_nid);

        $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#required'] = false;  //will be automatically set @see _erpal_projects_helper_task_set_project in task.inc again
      }

      //parent is not required here and it is already set as default value
      $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
      $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#required'] = false;
  } else {
    //hide parent and project ref anyway!
    $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
    $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
  }
  
}

/**
* Implements hook_erpal_clone_node_alter to alter task node if cloned
* @param $node is the new cloned node
* @param $args[parent_nid] is the nid of the new parent_node of the cloned node
* @param $args[options] some options given to the clone process
*/
function erpal_projects_helper_erpal_clone_node_alter($node, $args) {
  $parent_nid = $args['parent_nid'];
  $options = $args['options'];
  
  if ($node->type == 'erpal_task') {
    //ensure that the correct project is set to the task
    //even this is done in presave (@see erpal_projects_helper_node_presave_task) it is important to ensure, so we do it again here after cloning
    _erpal_projects_helper_task_set_project($node);  

    //prepare other task node attributes according to option
    if ($options['reset_task_status']) {
      $vid = _erpal_basic_helper_term_field_get_vid('field_task_status_term'); 
      $default_tid = _erpal_basic_helper_get_default_tid($vid);
      $node->field_task_status_term[LANGUAGE_NONE][0]['tid'] = $default_tid;
      $node->field_progress_percent[LANGUAGE_NONE][0]['value'] = 0;
    }  
    
    //anyway, delete the assigned user because this will be a ressource planing issue
    unset($node->field_task_assigned_users);
    
  }
 
}

/**
* Implements hook_erpal_clone_node_postprocess_alter to add the new book to the given project
*/
function erpal_projects_helper_erpal_clone_node_postprocess_alter($node, $args) {
  $parent_nid = $args['parent_nid'];
  $options = $args['options'];
  
  if ($node->type == 'erpal_book') {
    //Link new book to selected project and delete all references to exported files of the new 
    //if tasks are cloned, they will be added to this project
  
    if ($options['project']) {
      $project_nid = $options['project'];
      $project_node = node_load($project_nid);
      $project_node->field_books_ref[LANGUAGE_NONE][]['target_id'] = $node->nid;
      node_save($project_node);
    }
  }
}