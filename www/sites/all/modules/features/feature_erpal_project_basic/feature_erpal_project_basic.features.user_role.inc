<?php
/**
 * @file
 * feature_erpal_project_basic.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_erpal_project_basic_user_default_roles() {
  $roles = array();

  // Exported role: project user.
  $roles['project user'] = array(
    'name' => 'project user',
    'weight' => '4',
  );

  return $roles;
}
