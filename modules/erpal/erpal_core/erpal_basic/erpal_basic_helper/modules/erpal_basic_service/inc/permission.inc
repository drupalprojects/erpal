<?php

/**
 * @file functions needed to make permission accessible by services
 * @author Lavong Soysavanh <ls@brightsolutions.de>
 */

/**
 * retrieves and returns permissions
 * @param int $uid the permission id to return
 * @param bool $details whether permissions will be returned with details , defaults to false
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return array the project prepared for output
 */
function _erpal_basic_service_permission_retrieve($uid) {
  $user = user_load($uid);
  if (!$user || empty($user)) {
    return services_error('failed retrieving permissions for user: ' . $uid, 400);
  }

  $permissions_out = array();

  $contact_type = 'erpal_contact';
  $contact_perm = _get_permission_string_for_type($contact_type, $user);
  $permissions_out[$contact_type] = $contact_perm;

  $activity_type = 'erpal_crm_activity';
  $activity_perm = _get_permission_string_for_type($activity_type, $user);
  $permissions_out[$activity_type] = $activity_perm;

  $file_type = 'erpal_file';
  $file_perm = _get_permission_string_for_type($file_type, $user);
  $permissions_out[$file_type] = $file_perm;

  $date_item_type = 'date_item';
  $date_item_perm = _get_permission_string_for_type($date_item_type, $user);
  $permissions_out[$date_item_type] = $date_item_perm;

  $comment_type = 'comment';
  $post_comment_perm = user_access('post comments', $user);
  $access_comment_perm = user_access('access comments', $user);
  $comment_perm = '';
  if ($post_comment_perm)
    $comment_perm .= 'cu';
  if ($access_comment_perm)
    $comment_perm .= 'r';
  $permissions_out[$comment_type] = $comment_perm;

  return $permissions_out;
}

/**
 * @param type $type
 */
function _get_permission_string_for_type($type, $user) {
  $perm = '';
  if (node_access('create', $type, $user))
    $perm .= 'c';
  if (node_access('view', $type, $user))
    $perm .= 'r';
  if (node_access('update', $type, $user))
    $perm .= 'u';
  if (node_access('delete', $type, $user))
    $perm .= 'd';
  return $perm;
}

/**
 * Check access for permission node
 * @param $op
 *   The operation to be performed on the node. Possible values are:
 *   - "view"
 *   - "update"
 *   - "delete"
 *   - "create"
 */
function _erpal_basic_service_permission_access($op, $args = NULL) {
  return node_access($op, 'user');
}

