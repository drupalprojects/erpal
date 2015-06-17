<?php

/**
* @file adds some query functions for projects and other functions for erpal_project nodes
*/

/**
* Alters the project node form
*/
function _erpal_projects_helper_project_node_form_alter(&$form, &$form_state) {
  //if form is filled by entityreference prepopulate, the crm activity is already prefilled.
  //with the activity we can preselect the customer, because it may be the same as in activity and project
  //in most cases  
  _erpal_projects_helper_preselect_if_project_from_activity($form);
}


/**
* If the project is create from an activity (preset and node not already created), set the customer assigned to that activity and the title
*/
function _erpal_projects_helper_preselect_if_project_from_activity(&$form) {
  $nid = $form['nid']['#value'];
  
  //if node already exists, do nothing here
  if ($nid)
    return;
  
  $activity_nid = $form['field_activity_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'];
  $activity_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($activity_nid);

  if (!empty($activity_nid) && is_numeric($activity_nid)) {
    $activity_node = node_load($activity_nid);
    $customer_nid = false;

    if (isset($activity_node->field_customer_ref[LANGUAGE_NONE][0]['target_id'])) {
      $customer_nid = $activity_node->field_customer_ref[LANGUAGE_NONE][0]['target_id'];
    }

    if ($customer_nid) {
      $customer_node = node_load($customer_nid);
      $form['field_customer_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'] = $customer_node->title." (".$customer_nid.")";
    }
    
    $form['title']['#default_value'] = $activity_node->title;
  }
}

/**
* Add links shown on project lists
*/
function _erpal_projects_helper_add_projects_view_link(&$links) {
 
  if (user_access('create erpal_project content')) {
    $back_to_list = l(
      t('Add new project'), 
      'node/add/erpal-project',
      array(
        'query' => array(        
          'destination' => $_GET['q'],
        )
      )
    );
    
    $links[] = $back_to_list;
  }
}

/**
* Returns the activity referenced by the project
*/
function _erpal_projects_helper_get_activity_by_project($project_node) {
  $activity_node = false;
  if (isset($project_node->field_activity_ref[LANGUAGE_NONE][0])) {
    $activity_nid = $project_node->field_activity_ref[LANGUAGE_NONE][0]['target_id'];
    $activity_node = node_load($activity_nid);
  }
  
  return $activity_node;
  
}

/**
* called in hook_node_presave of this module if presaved node is a project
*/
function erpal_projects_helper_node_presave_project($node) {
  
  $old_nid = isset($node->nid) ? $node->nid : false;
  if ($old_nid) {
    $old_node = node_load($old_nid);
    _erpal_projects_helper_handle_removed_book_nodes($node, $old_node);
  }
}


/**
* Just return all projects the user is allowed to see
*/
function _erpal_projects_helper_get_all_projects($for_select=false) {
  
  $projects = array();
  if ($for_select) {    
   
    $query = db_select('node', 'n');
    $query
      ->fields('n', array('nid', 'title'))
      ->condition('n.type', 'erpal_project')
      ->condition('n.status', '1')
      ->orderBy('n.title', 'DESC')
      ->addTag('node_access');
    
    $result = $query->execute();
    
    foreach ($result as $record) {
      // Do something with each $record
      $projects[$record->nid] = $record->title;
    }
    
    return $projects;
  } else {  
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_project')
    ->propertyCondition('status', 1);
    
    $result = $query->execute();

    if (isset($result['node'])) {
      $project_nids = array_keys($result['node']);
      $project_nodes = entity_load('node', $project_nids);
      
      $projects = array_merge($projects, $project_nodes);
    }
  }
}

/**
* Returns time infomration of a given project or task node in an array. It returns the amount of
* Estimated Time on this node and separate on its child nodes
* Consumed Time (timetracking) on this node and separate on its child nodes
* Time to work on this node and separate on its child nodes
*/
function _erpal_projects_helper_time_information($node) {
  $result = array(
    'local' => array('estimated' => 0, 'timetracking' => 0, 'estimated_left' => 0),
    'children' => array('estimated' => 0, 'timetracking' => 0, 'estimated_left' => 0),
  );  //prepare result
  
  if ($node->type == 'erpal_project') {
    $child_nids = _erpal_projects_helper_get_tasks_by_project($node->nid);
  } 
  elseif ($node->type == 'erpal_task') {
    $child_nids = _erpal_projects_helper_get_children($node->nid, true);
  }
  else
    return $result;

  $child_times = erpal_projects_helper_summed_timeinformation($node, $child_nids, true, true); //times of children

  if ($node->type == 'erpal_task') { //only for tasks because timetracking is not possible on projects
    $result['local']['estimated'] = round($child_times['direct_estimated'], 2);
    $result['local']['estimated_left'] = round($child_times['direct_estimated_left'], 2);
    $result['local']['timetracking'] = round($child_times['direct_timetracking'], 2);
  }
  elseif ($node->type == 'erpal_project') {
    $result['local']['estimated'] = round($child_times['direct_estimated'], 2);
  }
  
  $result['children']['estimated'] = round($child_times['estimated'], 2);
  $result['children']['estimated_left'] = round($child_times['estimated_left'], 2);
  $result['children']['timetracking'] = round($child_times['timetracking'], 2);

  return $result;
}

/**
* Calculate sum of all estimations of tasks in a project
*/
function _erpal_projects_helper_summed_project_estimation($project_node) {
  static $sums = array(); //to cache results
  
  //is it static cached?
  if (isset($sums[$project_node->nid]))
    return $sums[$project_node->nid];
    
  $estimation = 0;
  //get all tasks of project
  $task_nids = _erpal_projects_helper_get_tasks($project_node->nid, true, false);
  $task_nids = array_keys($task_nids);
  
  if (!is_array($task_nids) || !count($task_nids))
    return 0;
    
  //now get the sum of estimations of these tasks
  //get table for timetracking field_estimated_time
  $field_info = field_info_field('field_estimated_time');

  $sql_arr = $field_info['storage']['details']['sql']['FIELD_LOAD_CURRENT'];
  $field_name = array_keys($sql_arr);  
  $field_name_table_estimation = $field_name[0];
  $value_field_estimation = $sql_arr[$field_name_table_estimation]['value'];

  $query = db_select($field_name_table_estimation,"e");
  $query->condition('e.entity_id', $task_nids);
  $query->addExpression("SUM(".$value_field_estimation.")", 'time');
  $res = $query->execute()->fetchAssoc();
  
  $estimation = $res['time'];
  
  $sums[$project_node->nid] = $estimation; //cache it static
  
  return $estimation;
}

/**
* Returns all users assigned to the project team with their permissions set in array('uid' => 3, 'permissions' => array())
*/
function _erpal_projects_helper_get_project_team_uids($project_node) {

  $team_fielcollection_ids = isset($project_node->field_project_team[LANGUAGE_NONE]) ? $project_node->field_project_team[LANGUAGE_NONE] : false;
  
  $uids = array();
  if (!$team_fielcollection_ids)
    return $uids;
  
  foreach ($team_fielcollection_ids as $delta=>$value) {
    $entity_id = $value['value'];
    
    $field_collection = entity_load('field_collection_item', array($entity_id));
    
    //explicit check if the field collection still exists, it will not, if it was removed in edit form
    if (!count($field_collection))
      continue;
      
    $field_collection = $field_collection[$entity_id];
    
    $user_permissions = _erpal_projects_helper_team_user_permissions($field_collection);
    $uids[] = $user_permissions;        
  }

  return $uids;
}

/**
* Returns the set permissions of a field_project_team field collection
* @param $user_field_collection a field_collection entity of bundle field_project_team
*/
function _erpal_projects_helper_team_user_permissions($field_collection) {
  $uid = isset($field_collection->field_user[LANGUAGE_NONE][0]) ? $field_collection->field_user[LANGUAGE_NONE][0]['target_id'] : false;
    
  $permissions = array();
  $perms_arr = isset($field_collection->field_project_permissions[LANGUAGE_NONE]) ? $field_collection->field_project_permissions[LANGUAGE_NONE] : array();
  
  foreach ($perms_arr as $delta=>$perms_val) {
    $permissions[] = $perms_val['value'];
  }
  
  return array('uid' => $uid, 'permissions' => $permissions);
}

/**
* Checks if users where removed from the team of the project
* @return an array with field collection ids of the collections that where removed
*/
function _erpal_projects_helper_team_changes_compare_previous($project_node) {
  //check if a complete field collection has been removed from the team (if only a user changed within the field collection, we get this to know in hook_entity_update (@see erpal_projects_access module
  $team = isset($project_node->field_project_team[LANGUAGE_NONE]) ? $project_node->field_project_team[LANGUAGE_NONE] : false;
  
  $original_node = isset($project_node->original) ? $project_node->original : false;
  if (!$original_node)
    return array();
    
  $team_original = isset($original_node->field_project_team[LANGUAGE_NONE]) ? $original_node->field_project_team[LANGUAGE_NONE] : array();
  
  $collection_ids = array();
  foreach ($team_original as $delta_original=>$collection_original) {
    $original_id = $collection_original['value'];
    $was_found = false;
    foreach ($team as $delta=>$collection) {
      $id = $collection['value'];
      if ($id == $original_id) {
        $was_found = true;
        break;
      }
    }
    
    //if we didn't find the entity, it has been deleted and so the team changed
    if (!$was_found) {
      $collection_ids[] = $original_id;
    }
  }
  
  return $collection_ids;
}

/**
* Get all projects that have the given semantic status
* @param string status the string representing the semantic status we want to query projects for.
*/
function _erpal_projects_helper_get_projects_by_semantic_status($status) {
  //first, get all terms with the given semantic status
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', 'project_status_terms')    
    ->fieldCondition('field_simple_process_status', 'value', $status)   
    ->addMetaData('account', user_load(1)); // Run the query as user 1.
    
  $result = $query->execute();
  $term_tids = array();
  if (isset($result['taxonomy_term'])) {
    $term_tids = array_keys($result['taxonomy_term']);    
  }
  
  $project_nids = array();
  if (!empty($term_tids)) {
    //now get all project nids with the given terms
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'erpal_project')    
      ->fieldCondition('field_project_status_term', 'tid', $term_tids)   
      ->addMetaData('account', user_load(1)); // Run the query as user 1.
      
    $result = $query->execute();
    
    if (isset($result['node'])) {
      $project_nids = array_keys($result['node']);    
    }
  }

  return $project_nids;
}

/**
* Returns the user with a given tid of project role in a given project
*/
function erpal_projects_helper_get_users_by_project_role($project_node, $role_tid) {
  if (!is_numeric($project_node)) {
    $project_node = node_load($project_node);
  }
  
  $project_node_w = entity_metadata_wrapper('node', $project_node);
  $team_collections = $project_node_w->field_project_team->value();
  
  $uids = array();
  foreach ($team_collections as $team_collection) {
    $team_collection_w = entity_metadata_wrapper('field_collection_item', $team_collection);
    $role_terms = $team_collection_w->field_project_role_tags->value();
    foreach ($role_terms as $role_term) {  
      if ($role_term->tid == $role_tid) {
        //here we have a team member that has the role we need
        //so get the user
        $uid = !empty($team_collection->field_user[LANGUAGE_NONE][0]['target_id']) ? $team_collection->field_user[LANGUAGE_NONE][0]['target_id'] : FALSE;
        if ($uid) {
          $uids[] = $uid;
        }
      }
    }
  }

  return array_unique($uids);
}

