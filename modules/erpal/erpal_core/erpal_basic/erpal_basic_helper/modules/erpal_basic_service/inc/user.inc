<?php

/**
 * @file functions needed to make user accessible by services
 * @author Lavong Soysavanh <ls@brightsolutions.de>
 */

/**
 * callback for retrieving a single user resource.
 *
 * @param int $id the nid of the project node that should be retrieved
 * @param bool $details whether users will be returned with details, defaults to true
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return object
 */
function _erpal_basic_service_user_index($start = 0, $count = PHP_INT_MAX, $changed_since = 0, $details = false, $include_children = FALSE) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'user')
      ->range((int) $start, (int) $count)
      ->propertyCondition('created', (int) $changed_since, '>=');

  $entities = $query->execute();

  $users_out = array();

  if (!empty($entities['user'])) {
    foreach (array_keys($entities['user']) as $uid) {
      if ($uid > 0) {
        $users_out[] = _erpal_basic_service_user_out($uid, $details, $include_children);
      }
    }
  }

  return $users_out;
  //return services_error('not implemented yet', 500);
}

/**
 * retrieves and returns users
 * @param int $uid the user id to return
 * @param bool $details whether users will be returned with details , defaults to false
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return array the project prepared for output
 */
function _erpal_basic_service_user_retrieve($uid, $details = true, $include_children = false) {
  $user_out = _erpal_basic_service_user_out($uid, $details, $include_children);
  return $user_out;
}

/**
 * retrieves and returns users
 * @param int $uid the user id to return
 * @param bool $details whether users will be returned with details , defaults to false
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return array the project prepared for output
 */
function _erpal_basic_service_user_out($uid, $details = true, $include_children = false) {

  $user = user_load($uid);
  if (!$user || empty($user)) {
    return services_error('failed retrieving user with id: ' . $uid, 400);
  }

  $users_out = array();
  $users_out['uid'] = (int) $user->uid;
  $users_out['url'] = url('rest/basic/erpal_user/' . $user->uid, array('absolute' => TRUE));
  $users_out['name'] = $user->name;
  $users_out['email'] = $user->mail;
  $users_out['created'] = (int) $user->created;
  $users_out['access'] = (int) $user->access;
  $users_out['login'] = (int) $user->login;
  if (isset($user->picture) && isset($user->picture)) {
    $users_out['image_url'] = file_create_url($user->picture->uri);
  }

  $details = !(!$details || (strtolower($details) === 'false'));
  if ($details) {
    $users_out['timezone'] = $user->timezone;
    if (!empty($user->roles)) {
      $users_out['roles'] = array();
      foreach ($user->roles as $value) {
        $users_out['roles'][] = $value;
      }
    }
  }

  $users_out['permissions'] = url('rest/basic/erpal_permission/' . $user->uid, array('absolute' => TRUE));

  return $users_out;
}

/**
 * Check access for user node
 * @param $op
 *   The operation to be performed on the node. Possible values are:
 *   - "view"
 *   - "update"
 *   - "delete"
 *   - "create"
 */
function _erpal_basic_service_user_access($op, $args = NULL) {
  return node_access($op, 'users');
}

