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
  _erpal_projects_helper_set_customer_if_project_from_activity($form);
}


/**
* If the project is create from an activity (preset and node not already created), set the customer assigned to that activity
*/
function _erpal_projects_helper_set_customer_if_project_from_activity(&$form) {
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
  }
}


/**
* Function returns a list of projects respecting the given params as filter. 
*
* @param array $task_states array of all states tasks are returned with.
* @param array with uids $uid user ID to return only tasks a user is assigned to
* @return array an array of erpal_project objects matching the filter*
* IMPORTANT If there are no filters set, perhaps you will get big amount of data!
*/
function _erpal_projects_helper_get_projects_with_assigned_tasks($task_states=array(), $uids=array(), $task_changed=0, $project_changed=0) {
  global $user;

  module_load_include('inc', 'erpal_projects_helper', 'inc/tasks.inc');
  
  $task_nodes = _erpal_projects_helper_get_tasks_by_assigned_user($task_states, $uids, $task_changed);  

  //now return the project nodes!
  $projects = array();

  foreach ($task_nodes as $task) {
    $project_node = node_load($task->field_project_ref[LANGUAGE_NONE][0]['target_id']);
    if ($project_node->changed >= $changed || !$changed)
      $projects[$project_node->nid] = $project_node;
  }

  //now query  projects where changed is greater than changed param. This is an or query  
  if ($project_changed) {  //only if there is a filter, otherwise we get all projects back!
 
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_project')
    ->propertyCondition('status', 1)
    ->propertyCondition('changed', $project_changed, '>=');  //all entites after the given changed date
    
    $result = $query->execute();

    if (isset($result['node'])) {
      $project_nids = array_keys($result['node']);
      $project_nodes = entity_load('node', $project_nids);
      
      $projects = array_merge($projects, $project_nodes);
    }
  }

  return $projects;
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
  $old_node = node_load($node->nid);
  _erpal_projects_helper_handle_removed_book_nodes($node, $old_node);
  // node edit
  if (!empty($node->original)) {
    _erpal_projects_helper_subscribe_project_team($node);
  }
}

/**
 * subscribe project team to project
 */
function _erpal_projects_helper_subscribe_project_team($node){
  $udpated_team = $original_team = $updated_diff = $original_diff = $field_project_team_original = array();
  
  // updated node
  $field_project_team_udpated = field_get_items('node', $node, 'field_project_team');
  if(!empty($field_project_team_udpated) && is_array($field_project_team_udpated)){
    foreach ($field_project_team_udpated as $udpated_team_collection) {
      $udpated_team[] = $udpated_team_collection['value'];
    }
  }
  // original node
  if (!empty($node->original)) {
    $field_project_team_original = field_get_items('node', $node->original, 'field_project_team');
  }
  
  if(!empty($field_project_team_original) && is_array($field_project_team_original)){
    foreach ($field_project_team_original as $original_team_collection) {
      $original_team[] = $original_team_collection['value'];
    }
  }
  
  // find added users
  $updated_diff = array_diff($udpated_team, $original_team);
   // find deleted users
  $original_diff = array_diff($original_team, $udpated_team);

  // subscribe users to the erpal_project
  if (!empty($updated_diff)) {
    _erpal_projects_helper_loop_users($updated_diff, $node, 'flag');
  }
  
  // unsubscribe users from the erpal_project
  if (!empty($original_diff) && !empty($node->original)) {
    _erpal_projects_helper_loop_users($original_diff, $node->original, 'unflag');
  }
}

/**
 * helper function
 * subscribe / unsubscribe users from the erpal_project
 * @param type $diff
 * @param type $node
 * @param type $action
 */
function _erpal_projects_helper_loop_users($diff, $node, $action){
  $node_wrapper = entity_metadata_wrapper('node', $node);
  // loop uids of assignrd users
  foreach ($node_wrapper->field_project_team as $project_team) {
    if ($project_team && $project_team_value = $project_team->value()) {
      if (in_array($project_team_value->item_id, $diff)) {
        if ($account = $project_team->field_user->value()) {
          _erpal_projects_helper_flag($node->type, $node->nid, $action, $account);
        }
      }
    }
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

