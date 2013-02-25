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
  if (!isset($data['payload']) || empty($data['payload']))
    return (object) array('error' => 'Can\'t find payload');
  $payload = $data['payload'];
  $data = drupal_json_decode($payload);
  // handle commits array
  if (!isset($data['commits']) || empty($data['commits']) || !is_array($data['commits']))
    return (object) array('error' => 'Can\'t find commits');

  // Comment and update task using git commit message data
  $result = array();
  foreach ($data['commits'] as $commit) {
    if (isset($commit['id']))
      $result[$commit['id']] = _erpal_git_commit_comment($commit);
    else
      $result = array('error' => 'Can\'t find commit Id');
  }

  return (object) $result;
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
  $result = array();

  // Check if message exists
  if (!isset($data['message']))
    return array('error' => 'Can\'t find message');
  else
    $message = $data['message'];

  // Check if nid exists
  if (!preg_match('/#\d+/', $message, $matches))
    return array('error' => 'Can\'t find #nid tag in message');
  else
    $nid = str_replace('#', '', $matches[0]);

  // Check if node exists and node type is erpal_task
  $node = node_load($nid);
  if (!$node || $node->type != 'erpal_task')
    return array('error' => 'Can\'t find task #nid');

  // If the users email is not found in the system, the comment will be assigned 
  // to as admin.
  if (!isset($data['author']['email']) || !$user = user_load_by_mail($data['author']['email'])) {
    $user = user_load(1);
  }
  // prepare comment body data
  $formatted_message = _erpal_git_prepare_message_data($data);
  // comment subject
  $subject = t('GIT commit');
  if (isset($data['id']))
    $subject .= ': ' . $data['id'];

  // add comment
  _erpal_git_create_comment($nid, $user, $formatted_message, $subject);
  $result['comment'] = array('success' => 'Comment was added');

  // change node status
  if ($node_update = _erpal_git_change_task_status($node, $message))
    $result['status'] = $node_update;
  else
    $result['status'] = array('warning' => 'Bad ?status tag');
  
  return $result;
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
  // message:	Commit-Message
  if (isset($data['message'])) {
    $message['message'] = array(
      '#type' => 'item',
      '#markup' => $data['message']
    );
  }
  // timestamp:	Date and time of the Commit. Format yyyy-mm-dd'T'hh:mm:ss
  if (isset($data['timestamp'])) {
    $message['timestamp'] = array(
      '#type' => 'item',
      '#markup' => t('Date') . ': ' . $data['timestamp']
    );
  }
  // url:	URL to the commit in a repository viewer
  if (isset($data['url'])) {
    $message['url'] = array(
      '#type' => 'item',
      '#markup' => t('Commit url') . ': ' . $data['url'],
    );
  }
  // Author
  $author = array();
  // author: "name"
  if (isset($data['author']['name']))
    $author[] = $data['author']['name'];
  // author: "email"
  if (isset($data['author']['email'])) 
    $author[] = $data['author']['email'];
  
  if (!empty($author)) {
    $message['email'] = array(
      '#type' => 'item',
      '#markup' => t('Author') . ': ' . implode(', ', $author),
    );
  }

  return render($message);
}

function _erpal_git_change_task_status($node, $message) {
  // Check if node status tag exists
  if (!preg_match('/\?\w+/', $message, $matches))
    return array('success' => 'No status tag in the message');

  $status = str_replace('?', '', $matches[0]);
  if (!$vocabulary = taxonomy_vocabulary_machine_name_load('task_status_terms'))
    return array('error' => 'Can\'t load vocabulary.');

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
        // break because only one term in vocabulary must contain status tag
        return array('error' => 'There are more than one status in vocabulery that matches your tag. Use another ?status tag.');
    }
  }

  // update node status
  if ($status_tid) {
    $node_status = field_get_items('node', $node, 'field_task_status_term');
    if ($node_status[0]['tid'] && $node_status[0]['tid'] != $status_tid) {
      $node->field_task_status_term[LANGUAGE_NONE][0]['tid'] = $status_tid;
      node_save($node);
      return array('success' => 'Task status was updated');
    } else {
      return array('success' => 'Task already have this status');
    }
  }
}
