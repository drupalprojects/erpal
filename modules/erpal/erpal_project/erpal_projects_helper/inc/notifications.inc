<?php

/**
 * @file provide functions to have user notifications on projects
 */

/**
 * Checks if there should be some notifications send on tasks to subscribers and if so, send them
 * @param $op the operation that is performed on the entity
 */
function _erpal_projects_helper_handle_notifications_on_subscribers($entity, $entity_type, $op) {
  if (isset($entiy->skipp_notify) && $entiy->skipp_notify)
    return false;
  
  $update_types = _erpal_projects_helper_task_update_types();
  
  if ($entity_type == 'node') {
    if ($entity->type != 'erpal_task')
      return false; //only for tasks

    //should we send message here?
    if (!in_array('erpal_task', $update_types)) {
      return false;
    }
      
    _erpal_projects_helper_handle_entity_notification($entity, $entity_type, $op);
    
  } elseif ($entity_type == 'comment') {
    if ($entity->node_type != 'comment_node_erpal_task')
      return false;

    //should we send message here?
    if (!in_array('comment_node_erpal_task', $update_types)) {
      return false;
    }  
      
    _erpal_projects_helper_handle_entity_notification($entity, $entity_type, $op);
  }
  
}

/**
 * Starts notification process
 */
function _erpal_projects_helper_handle_entity_notification($entity, $entity_type, $op) {

  $users = _erpal_projects_helper_get_project_subscribers($entity, $entity_type, $op);

  //we dont want the user that postet the update to get the message
  global $user;
  if (isset($users[$user->uid])) {
    unset($users[$user->uid]);
  }
  
  if ($entity_type == 'comment') {
    // Create a new message
    $comment = $entity;
    $node = node_load($comment->nid);
    if ($node->type != 'erpal_task')
      return;
    
    //create messages for this event
    if (module_exists('erpal_project_notify')) {
      $task_node = $node;
      $project_nid = _erpal_projects_helper_has_project($task_node);
      $project_node = node_load($project_nid);
      $message = message_create('task_comment_message', array('uid' => $comment->uid));
      $wrapper = entity_metadata_wrapper('message', $message);
      $wrapper->field_message_comment->set($comment);
      $wrapper->field_task_ref->set($task_node);
      $wrapper->field_project_ref->set($project_node);
      $wrapper->field_message_aggregate->set(true);
      $wrapper->field_message_notify->set(true);
      $wrapper->field_users->set($users);
      $wrapper->field_message_operation->set($op);
      $wrapper->save();
    }
  } else if ($entity_type == 'node') {

    if ($entity->type != 'erpal_task')
      return;
    
    //create messages for this event
    if (module_exists('erpal_project_notify')) {
      $task_node = $entity;
      $project_nid = _erpal_projects_helper_has_project($task_node);
      $project_node = node_load($project_nid);
      $message = message_create('task_node_message', array('uid' => $task_node->uid));
      $wrapper = entity_metadata_wrapper('message', $message);
      $wrapper->field_task_ref->set($task_node);
      $wrapper->field_project_ref->set($project_node);
      $wrapper->field_message_aggregate->set(true);
      $wrapper->field_message_notify->set(true);
      $wrapper->field_users->set($users);
      $wrapper->field_message_operation->set($op);
      $wrapper->save();
    }
  }

  
  //send a notification to these users
  //$message_wrapper = _erpal_projects_helper_get_project_notify_message($entity, $entity_type, $op);
  //_erpal_basic_helper_notify_users($users, $message_wrapper);
}

/**
 * Returns all users that should be notified about changes of the given node
 */
function _erpal_projects_helper_get_project_subscribers($entity, $entity_type, $op) {

  $users = array();
  $task_node = false;
  $comment_author = '';
  if ($entity_type == 'comment') {
    if ($entity->node_type == 'comment_node_erpal_task') {
      //load the node for the comment and notify for this node
      $task_node = node_load($entity->nid);
      $comment_author = $entity->uid;
    }
  } elseif ($entity_type == 'node') {
    if ($entity->type == 'erpal_task') {
      $task_node = $entity;
    }
  }

  if ($task_node) {

    //get parents until we reach the top (project) and collect all users that want to be notified
    $parent_nodes = _erpal_projects_helper_get_parent_tasks($task_node);

    //now get all subscribers of the parent nodes
    $parent_nodes[] = $task_node;
    $task_subscribers = array();
    foreach ($parent_nodes as $parent_node) {
      $task_subscriptions_flag = flag_get_flag('task_subscriptions');
      $task_subscribers_new = _erpal_projects_helper_get_subscribers($task_subscriptions_flag, $parent_node);
      $task_subscribers_new = $task_subscribers_new['users'];
      $task_subscribers = array_merge($task_subscribers, $task_subscribers_new);
    }
    $task_subscribers = array(
      'users' => $task_subscribers,
    );

    //get the project of the task
    $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];

    $project_node = node_load($project_nid);
    $project_subscriptions_flag = flag_get_flag('project_subscriptions');
    $project_subscribers = _erpal_projects_helper_get_subscribers($project_subscriptions_flag, $project_node);

    //now merge the users to have a unique array and no user will get douplicate notifications
    $subscribers = array();
    foreach ($project_subscribers['users'] as $uid) {
      if($uid != $comment_author)
        $subscribers[$uid] = $uid;
    }
    foreach ($task_subscribers['users'] as $uid) {
      if($uid != $comment_author)
        $subscribers[$uid] = $uid;
    }

    if (count($subscribers)) {
      //get users subscribed to project or task  
      if ($op == 'insert') {
        //node_access_acquire_grants($entity); //write the grants bevor checking access because if node was inserted we dont have grants here. Enebale this if some permissions go wrong
      }
    }

    //now check that all users really have access to the node. Users that don't have access are not notified.
    $users = _erpal_projects_helper_delete_users_no_access($subscribers, $task_node, 'node');
  }
  return $users;
}

/**
 * Fetch users who flagged an entity.
 */
function _erpal_projects_helper_get_subscribers($flag, $entity) {
  $result = db_select('flagging', 'fc')
    ->fields('fc', array('uid'))
    ->condition('entity_type', $flag->entity_type)
    ->condition('entity_id', $flag->get_entity_id($entity))
    ->condition('fid', $flag->fid)
    ->execute();
  $uids = $result->fetchCol();
  // Filter out anonymous users.
  return array('users' => array_filter($uids));
}


/**
 * Returns an array with user IDs only of users that have the permission to view the entity
 */
function _erpal_projects_helper_delete_users_no_access($users, $entity, $entity_type) {
  $new_users = array();

  if ($entity_type != 'node')
    return false;  //@TODO implement for other entity_types (entity_access?)


  foreach ($users as $uid) {
    $a_user = user_load($uid);
    if (node_access('view', $entity, $a_user)) {
      $new_users[$uid] = $uid;
    }
  }

  return $new_users;
}

/**
 * Returns renderable element with nnotifiy flag link
 */
function _erpal_projects_helper_get_notify_flag_link_element($node) {
  $flag_link = false;
  $flag_link = false;
  if ($node->type == 'erpal_task')
    $flag_link = flag_create_link('task_subscriptions', $node->nid);
  elseif ($node->type == 'erpal_project')
    $flag_link = flag_create_link('project_subscriptions', $node->nid);

  if (!$flag_link)
    return;  //will be false if this node type is not notifiable

  $element = array(
    '#markup' => $flag_link,
    '#weight' => 1,
  );

  return $element;
}

/**
 * Flags node if it's erpal_task or erpal_project
 * @param string $node_type
 *   content type
 * @param int $nid
 *   The ID of the item to flag or unflag.
 * @param string $action
 *   Either 'flag' or 'unflag'.
 * @param object $account
 *   The user on whose behalf to flag. Leave empty for the current user.
 */
function _erpal_projects_helper_flag($node_type, $nid, $action = 'flag', $account = NULL) {
  if ($node_type == 'erpal_task' || $node_type == 'erpal_project') {
    if (!isset($account->uid)) {
      global $user;
      $account = $user;
    }
    
    if ($node_type == 'erpal_task') { // flag erpal_task
      $flag = flag_get_flag('task_subscriptions');
    } else
    
    if ($node_type == 'erpal_project') { //flag erpal_project
      $flag = flag_get_flag('project_subscriptions'); 
    }

    if ($action == 'flag' && !$flag->is_flagged($nid, $account->uid)) {
      $flag->flag($action, $nid, $account); // flag node
    } else
     if ($action == 'unflag' && $flag->is_flagged($nid, $account->uid)) {
      $flag->flag($action, $nid, $account); // unflag node
    } 
  }
}

/**
 * Send email to subscribed user
 * @param type $account
 */
function _erpal_projects_helper_user_assigned_email($account, $entity, $op) {
  
  //create a message for assigned user
  $task_node = $entity;
  if ($task_node->type != 'erpal_task')
    return;

  $project_nid = _erpal_projects_helper_has_project($task_node);
  $project_node = node_load($project_nid);
  $message = message_create('task_assigned_message', array('uid' => $task_node->uid));
  $wrapper = entity_metadata_wrapper('message', $message);
  $wrapper->field_task_ref->set($task_node);
  $wrapper->field_project_ref->set($project_node);
  $wrapper->field_message_aggregate->set(true);
  $wrapper->field_message_notify->set(true);
  $wrapper->field_users->set(array($account->uid));
  $wrapper->save();
}

