<?php

/**
* @file provide functions to have user notifications on projects
*/

/**
* Checks if there should be some notifications send on tasks to subscribers and if so, send them
* @param $op the operation that is performed on the entity
*/
function _erpal_projects_helper_handle_notifications_on_subscribers($entity, $entity_type, $op) {
  if ($entity_type == 'node') {
    if ($entity->type != 'erpal_task')
      return false; //only for tasks
    
    _erpal_projects_helper_handle_entity_notification($entity, $entity_type, $op);
    
  } elseif ($entity_type == 'comment') {
    if ($entity->node_type != 'comment_node_erpal_task')
      return;      
      
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
  
  //send a notification to these users
  $message = _erpal_projects_helper_get_project_notify_message($entity, $entity_type, $op);
  _erpal_projects_helper_notify_users($users, $message);
}

/**
* Returns all users that should be notified about changes of the given node
*/
function _erpal_projects_helper_get_project_subscribers($entity, $entity_type, $op) {
  
  $users = array();
  $task_node = false;
  if ($entity_type == 'comment') {
    if ($entity->node_type == 'comment_node_erpal_task') {
      //load the node for the comment and notify for this node
      $task_node = node_load($entity->nid);      
    }
  } elseif ($entity_type == 'node') {
    if ($entity->type == 'erpal_task') {
      $task_node = $entity;                
    }
  }
  
  if ($task_node) {
    module_load_include('inc', 'flag', 'flag.rules'); //incloude flag rules integration
   
    //get the project of the task
    $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];

    $project_node = node_load($project_nid);
    $project_subscriptions_flag = flag_get_flag('project_subscriptions');
    $project_subscribers = flag_rules_action_fetch_users($project_subscriptions_flag, $project_node);    
    
    $task_subscriptions_flag = flag_get_flag('task_subscriptions');
    $task_subscribers = flag_rules_action_fetch_users($task_subscriptions_flag, $task_node);
    
    //now merge the users to have a unique array and no user will get douplicate notifications
    $subscribers = array();
    foreach ($project_subscribers['users'] as $uid) {
      $subscribers[$uid] = $uid;
    }
    foreach ($task_subscribers['users'] as $uid) {
      $subscribers[$uid] = $uid;
    }

    if (count($subscribers)) {
      //get users subscribed to project or task  
      if ($op == 'insert') {
        //node_access_acquire_grants($entity); //write the grants bevor checking access because if node was inserted we dont have grants here. Enebale this if some permissions go wrong
      }
    }
    
    //now check that all users really have access to the node. Users that dont have access are not notified.
    $users = _erpal_projects_helper_delete_users_no_access($subscribers, $task_node, 'node'); 
  }
  
  return $users;
}

/**
* Returns the message to send to subscribers if project changes 
* @param $entity the message may contain data of the entity.
*/
function _erpal_projects_helper_get_project_notify_message($entity, $entity_type, $op) {
  $message = _erpal_projects_helper_task_update_message();
  $subject = _erpal_projects_helper_task_update_subject();
  
  $data['op'] = $op;
  $data['entity'] = $entity;
  $data['entity_type'] = $entity_type;
  $subject = token_replace($subject, $data);
  $message = token_replace($message, $data);
  
  return array(
    'message' => $message,
    'subject' => $subject,
  );
}

/**
* Sends a message to the users. 
* @param $users an array with user IDs to send the message to 
* @param $message the message to send to the users
* @TODO handle this with the messaging module to be more abstract in notification method
*/
function _erpal_projects_helper_notify_users($users, $message) {
  global $user;
  
  $subject = $message['subject'];
  $message = $message['message'];

  if (!count($users))
    return;  //no mail if no users
  
  //now send mail to users
  //@TODO integrate with messaging module
  //get the mails of the users
  $mails = array();
  foreach ($users as $uid) {
    $a_user = user_load($uid);
    $mails[] = $a_user->mail;
  }
  $mails = implode(',', $mails);
  $site_name = variable_get('site_name', 'ERPAL');
  $site_mail = variable_get('site_mail', ini_get('sendmail_from'));
  $sender = $site_name.' <'.$site_mail.'>';
  $params = array('message' => $message, 'subject' => $subject);
  $message = drupal_mail('erpal_projects_helper', 'task_notifications', $mails, user_preferred_language($user), $params, $sender);
  
  if ($message['result']) {
    drupal_set_message(t('!count user(s) have been notified', array('!count' => count($users))));
  } else {
    drupal_set_message(t('!count user(s) could NOT be notified because of mail sending error', array('!count' => count($users))), 'error');
  }
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
* Function to set message for sending mail. Called by erpal_projects_helper_mail
*/
function _erpal_projects_helper_task_notification_mail($key, &$message, $params) {
  $message['subject'] = $params['subject'];
  $message['body'][] = $params['message'];
}