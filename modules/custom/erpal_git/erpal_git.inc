<?php

/**
 * Works with git commits
 * @param object $data
 *  Format of posted JSON Object:
 * 
 *  before: ID of the previous commit, may be empty if new branch set.
 *  after: ID of the new commit
 *  ref:	which Branch / Tag was updated, Master-Branch could be for example 'refs/heads/master'
 *  commits:	Array of commit-objects (see below)
 *    Format of commit objects
 *      id: ID (Hash) of the commit
 *      message: Commit-Message
 *      timestamp: Date and time of the Commit. Format yyyy-mm-dd'T'hh:mm:ssz
 *      url: URL to the commit in a repository viewer
 *      author: Object with author information and fields "name" and "email"
 *  repository:	Object with information about the repository
 *    Format of the repository object
 *      name:	Name of the repository
 *      url: GIT-URL
 */
function _erpal_git_commit($data) {
  _erpal_git_commit_comment($data);
}

/**
 * Comment node using git commit message data
 * Format of commit objects:
 *   id: ID (Hash) of the commit
 *   message:	Commit-Message
 *   timestamp:	Date and time of the Commit. Format yyyy-mm-dd'T'hh:mm:ssz
 *   url:	URL to the commit in a repository viewer
 *   author: Object with author information and fields "name" and "email"
 */
function _erpal_git_commit_comment($data) {
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

  // Check if node exists and node type is erpal_task
  $node = node_load($nid);
  if (!$node || $node->type != 'erpal_task') {
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
  $comment_add = _erpal_git_create_comment($nid, $user, $formatted_message, $subject);
  // Change node status
  $node_update = _erpal_git_change_task_status($node, $message);
  if($comment_add || $node_update){
    return (object) array('success' => 'successful update');
  } else {
    return (object) array('warning' => 'bad nid or status tag');
  }
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

function _erpal_git_change_task_status($node, $message) {
  // Check if node status tag exists
  if (!preg_match('/\?\w+/', $message, $matches))
    return FALSE;

  $status = str_replace('?', '', $matches[0]);
  if (!$vocabulary = taxonomy_vocabulary_machine_name_load('task_status_terms'))
    return FALSE;

  // we can use this function if condition for status tag is not "contains"
  // $terms = taxonomy_get_term_by_name($status, 'task_status_terms');
  
  // get status tid
  $status_tid = '';
  $tree = taxonomy_get_tree($vocabulary->vid);
  foreach ($tree as $term) {
    // check if term name contains the status
    if (strpos(strtolower($term->name), strtolower($status)) !== FALSE) {
      // check if only one term contains status tag
      if (!$status_tid)
        $status_tid = $term->tid;
      else
        // break because only one term in voxabulary must contain status tag
        return FALSE;
    }
  }

  // update node status
  if($status_tid){
    $node_status = field_get_items('node', $node, 'field_task_status_term');
    if($node_status[0]['tid'] && $node_status[0]['tid'] != $status_tid){
      $node->field_task_status_term[$node->language][0]['tid'] = $status_tid;
      node_save($node);
      return TRUE;
    }
  }
}
