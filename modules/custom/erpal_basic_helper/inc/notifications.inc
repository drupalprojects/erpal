<?php

/**
* @file provides functions to send notifications to users
*/

/**
* Functions handles a notification request. The request will be added to a queue so we send messages only once in the cron interval if there where multiple events sending this notification
*/
function _erpal_basic_helper_notify_users($users, $message, $module='erpal_basic_helper', $message_type='notifications') {
  //add message to queue if not already in queue
  $queue = DrupalQueue::get('notifications');
  //get all queue Items in an array

  $queue_items = array();
  while($item = $queue->claimItem(0)) {
    $queue_items[] = $item;
    
    //delete it and add it again so it is free again for next iteration
    $queue->deleteItem($item);    
  }
  
  //add items to queue again
  $message_found = false;
  $message_serialized = serialize($message);
  $message_id = md5($message_serialized); //message is an array with keys (message, subject)
  foreach ($queue_items as $item) {
    if ($item->data['message_id'] == $message_id) {
      //if this is the same message, just add the users.
      $item->data['users'] = array_merge($item->data['users'], $users);
      $message_found = true;
    }
    
    //add the item to queue again
    $queue->createItem($item->data);
  }
  
  //if message was not already in the queue, add it.
  if (!$message_found) {  
    
    $data = array(
      'message' => $message_serialized,
      'users' => $users,
      'message_id' => $message_id,
      'module' => $module,
      'message_type' => $message_type,
    );
    
    watchdog('ERPAL notification', 'added message '.print_r($data, true));
    $queue->createItem($data);
  }
  
}

/**
* Callback if the notifications queue runs. Here the messages are really send!
*/
function _erpal_basic_helper_notifications_queue_run($message_arr) {
  //send the message here
  $users = array_unique($message_arr['users']); // remove user duplicates
  $message = unserialize($message_arr['message']);
  $module = $message_arr['module'];
  $message_type = $message_arr['message_type'];
  _erpal_basic_helper_notify_users_send($users, $message, $module, $message_type);
}

/**
* Sends a message to the users. 
* @param $users an array with user IDs to send the message to 
* @param $message the message to send to the users
* @param $module the module that sends the message (to be able to implement hook_mail)
* @param $message_type the type of the message if some modules want to implement they own message handling
* @TODO handle this with the messaging module to be more abstract in notification method
*/
function _erpal_basic_helper_notify_users_send($users, $message, $module='erpal_basic_helper', $message_type='notifications'){
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
    if ($a_user->status)  //dont send to inactive users
      $mails[] = $a_user->mail;    
  }

  $site_name = variable_get('site_name', 'ERPAL');
  $site_mail = variable_get('site_mail', ini_get('sendmail_from'));
  $sender = $site_name.' <'.$site_mail.'>';
  $params = array('message' => $message, 'subject' => $subject);
  
  foreach ($mails as $mail) {
    //notify each user. We could add all mails to drupal_mail but then everybody will see every receipient.
    $message = drupal_mail($module, $message_type, $mail, user_preferred_language($user), $params, $sender);
  }
  
  if ($message['result']) {
    watchdog('ERPAL notification', t('!count user(s) have been notified', array('!count' => count($users))));
  } else {
    drupal_set_message(t('ERPAL notification !count user(s) could NOT be notified because of mail sending error', array('!count' => count($users))), 'error');
  }
}

/**
* Function to set message for sending mail. Called by erpal_projects_helper_mail
*/
function _erpal_basic_helper_notification_mail($key, &$message, $params) {
  $message['subject'] = $params['subject'];
  $message['body'][] = $params['message'];
}