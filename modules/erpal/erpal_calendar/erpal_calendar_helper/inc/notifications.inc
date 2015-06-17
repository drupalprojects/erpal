<?php

/**
* @TODO we should migrate this to the messages module as already done in the erpal projects module for task notifications.
*/

/**
 * Notify users assigned to date via email
 */
function _erpal_calendar_helper_subscribe_date_assigned_users($node, $type='node') {
    
  $assigned = $assigned_original = $assigned_users_original = $assigned_users = array();

  // get uids of assigned users
  $assigned_users = field_get_items('node', $node, 'field_users');
  if (!empty($assigned_users) && is_array($assigned_users)) {
    foreach ($assigned_users as $assigned_user) {
      $assigned[] = $assigned_user['target_id'];
    }
  }
  
  // get uids of original assigned users
  $assigned_users_original = array();
  if (isset($node->original)) {
    $assigned_users_original = field_get_items('node', $node->original, 'field_users');
    // loop users
    if (!empty($assigned_users_original) && is_array($assigned_users_original)) {
      foreach ($assigned_users_original as $assigned_user_original) {
        $assigned_original[] = $assigned_user_original['target_id'];
      }
    }
  }

  // find assigned users
  $users = array_unique(array_merge($assigned, $assigned_original));

  // notify assigned users
  if (!empty($users)) {    
    _erpal_calendar_helper_loop_date_users($users, $node, $type);
  }
}

/**
 * helper function
 * subscribe / unsubscribe users from the erpal_task
 */
function _erpal_calendar_helper_loop_date_users($assigned_users, $node, $type='node') {
  static $notified = array();
       
  foreach ($assigned_users as $assigned_user) {
    global $user;
    // User won't receive notification if he adds himself to the date node
    if ($assigned_user != $user->uid){
      if ($account = user_load($assigned_user)) {
        if (!empty($notified[$node->nid][$assigned_user])) {    
          continue; //skip sending messages for assigned user if a message for a comment (precessed before) was already sent) Every user receives only one message but we ensure to cover all users.
        }    
                    
        $notified[$node->nid][$assigned_user] = true;
      
        if ($type == 'node') {  
          // send notification email to assigned user
          _erpal_calendar_helper_date_assigned_email($account, $node, 'assign');
        } elseif ($type == 'comment') {
          // send notification email to assigned user for new comment
          _erpal_calendar_helper_date_assigned_email_comment($account, $node);
        }
      }
    }
  }
}

/**
* Send email to assigned user to notify about a new comment
*/
function _erpal_calendar_helper_date_assigned_email_comment($account, $entity) {
  $data['entity'] = $entity->comment;
  $data['entity_type'] = 'comment';

  if (!$subject = token_replace(_erpal_calendar_get_comment_subject(), $data)) {
    $subject = 'ERPAL Notification';
  }
  $message_body = token_replace(_erpal_calendar_get_comment_message(), $data);
  if ($message_body) {
    $message = array(
      'subject' => $subject,
      'message' => $message_body,
    );

    // email will be added to a cron queue
    _erpal_basic_helper_notify_users(array($account->uid), $message);
  }
}

/**
 * Send email to assigned to date user
 * @param type $account
 */
function _erpal_calendar_helper_date_assigned_email($account, $entity, $op) {
  $data['op'] = $op;
  $data['entity'] = $entity;
  $data['entity_type'] = 'node';

  if (!$subject = token_replace(_erpal_calendar_get_assigned_subject(), $data)) {
    $subject = 'ERPAL Notification';
  }
  $message_body = token_replace(_erpal_calendar_get_assigned_message(), $data);
  if ($message_body) {
    $message = array(
      'subject' => $subject,
      'message' => $message_body,
    );
    // email will be added to a cron queue
    _erpal_basic_helper_notify_users(array($account->uid), $message);
  }
}

/**
* Send email to assigned users of a date to inform about a new comment
* @param entity comment the comment that was added or updated
* @param string operation the operation that was performed on the comment
*/
function _erpal_calendar_helper_notify_assigned_users_for_comment($comment, $operation) {
  $nid = $comment->nid;  
  $node = node_load($nid);
  $node->comment = $comment;  //save to comment to the node so we can process it later.

  _erpal_calendar_helper_subscribe_date_assigned_users($node, 'comment');
}