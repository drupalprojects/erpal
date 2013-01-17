<?php

/**
 * Comment node using git commit message data
 * Format of commit objects:
 *   id: ID (Hash) of the commit
 *   message:	Commit-Message
 *   timestamp:	Date and time of the Commit. Format yyyy-mm-dd'T'hh:mm:ssz
 *   url:	URL to the commit in a repository viewer
 *   author: Object with author information and fields "name" and "email"
 */
function _erpal_git_commit($data) {
  // Check if message exists
  if (!isset($data['message']))
    return (object) array('error' => 'Cant find message');
  else
    $message = $data['message'];

  // Check if nid exists
  if (!preg_match('/#\d+/', $message, $matches))
    return (object) array('error' => 'Cant find #nid in message');
  else
    $nid = str_replace('#', '', $matches[0]);

  // Check if node exists
  if (!$node = node_load($nid)) {
    return (object) array('error' => 'Cant find node #nid');
  }

  // Comment node
  if (!isset($data['author']['email']))
    $user = user_load(1);
  else
    $user = user_load_by_mail($data['author']['email']);

  // prepare comment body data
  $formatted_message = _erpal_git_prepare_message_data($data);
  // comment subject
  $subject = t('GIT commit');
  if (isset($data['id']))
    $subject .= ': ' . $data['id'];
  // add comment
  _erpal_git_create_comment($nid, $user, $formatted_message, $subject);
  
  // Change node status
  
  return (object) array('result' => print_r($subject, true));
}

/**
 * Creates comment
 * @param int $nid
 *   nid of a node you want to attach a comment to
 * @param object $user
 *   user who lefts the comment
 * @param string $message
 *   comment body
 * @param string $subject
 *   comment subject
 * @return type
 */
function _erpal_git_create_comment($nid, $user, $message, $subject = '', $pid = 0) {
  $l = LANGUAGE_NONE;
  $comment = new stdClass();
  $comment->nid = $nid; // nid of a node you want to attach a comment to
  $comment->cid = 0; // leave it as is
  $comment->pid = $pid; // parent comment id, 0 if none 
  $comment->uid = $user->uid; // user's id, who left the comment
  $comment->mail = $user->mail; // user's email
  $comment->name = $user->name;
  $comment->is_anonymous = 0; // leave it as is
  $comment->status = COMMENT_PUBLISHED; // We auto-publish this comment
  $comment->language = $l; // The same as for a node
  $comment->subject = $subject; // Comment subject
  $comment->comment_body[$l][0]['value'] = $message; // Comment body
  $comment->comment_body[$l][0]['format'] = 'filtered_html';

  comment_submit($comment); // saving a comment
  return comment_save($comment);
}

/**
 * Prepare comment message body
 */
function _erpal_git_prepare_message_data($data) {
  $message = array();
  // id: ID (Hash) of the commit
  if (isset($data['id'])) {
    $message['id'] = array(
      '#type' => 'item',
      '#title' => t('Commit Id'),
      '#markup' => $data['id']
    );
  }
  // message:	Commit-Message
  if (isset($data['message'])) {
    $message['message'] = array(
      '#type' => 'item',
      '#title' => t('Message'),
      '#markup' => $data['message']
    );
  }
  // timestamp:	Date and time of the Commit. Format yyyy-mm-dd'T'hh:mm:ss
  if (isset($data['timestamp'])) {
    $message['timestamp'] = array(
      '#type' => 'item',
      '#title' => t('Date'),
      '#markup' => $data['timestamp']
    );
  }
  // url:	URL to the commit in a repository viewer
  if (isset($data['url'])) {
    $message['url'] = array(
      '#type' => 'item',
      '#title' => t('url'),
      '#markup' => $data['url']
    );
  }
  // author: "name"
  if (isset($data['author']['name'])) {
    $message['name'] = array(
      '#type' => 'item',
      '#title' => t('Author name'),
      '#markup' => $data['author']['name']
    );
  }
  // author: "email"
  if (isset($data['author']['email'])) {
    $message['email'] = array(
      '#type' => 'item',
      '#title' => t('Author email'),
      '#markup' => $data['author']['email']
    );
  }

  return render($message);
}