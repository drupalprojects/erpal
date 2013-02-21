<?php

/**
 * Notify users assigned to date via email
 */
function _erpal_calendar_helper_subscribe_date_assigned_users($node) {
  $assigned = $assigned_original = $assigned_users_original = $assigned_users = array();

  // get uids of assigned users
  $assigned_users = field_get_items('node', $node, 'field_users');
  if (!empty($assigned_users) && is_array($assigned_users)) {
    foreach ($assigned_users as $assigned_user) {
      $assigned[] = $assigned_user['target_id'];
    }
  }
  // get uids of original assigned users
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
  $updated_diff = array_diff($assigned, $assigned_original);

  // notify assigned users
  if (!empty($updated_diff)) {
    _erpal_calendar_helper_loop_date_users($updated_diff, $node);
  }
}

/**
 * helper function
 * subscribe / unsubscribe users from the erpal_task
 */
function _erpal_calendar_helper_loop_date_users($assigned_users, $node) {
  foreach ($assigned_users as $assigned_user) {
    global $user;
    // User won't receive notification if he adds himself to the date node
    if ($assigned_user != $user->uid){
      if ($account = user_load($assigned_user)) {
        // send notification email to assigned user
        _erpal_calendar_helper_date_assigned_email($account, $node, 'assign');
      }
    }
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