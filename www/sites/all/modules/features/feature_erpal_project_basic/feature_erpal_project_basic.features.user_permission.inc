<?php
/**
 * @file
 * feature_erpal_project_basic.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_erpal_project_basic_user_default_permissions() {
  $permissions = array();

  // Exported permission: create erpal_timetracking content
  $permissions['create erpal_timetracking content'] = array(
    'name' => 'create erpal_timetracking content',
    'roles' => array(
      0 => 'crm user',
      1 => 'project user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any erpal_timetracking content
  $permissions['delete any erpal_timetracking content'] = array(
    'name' => 'delete any erpal_timetracking content',
    'roles' => array(),
  );

  // Exported permission: delete own erpal_timetracking content
  $permissions['delete own erpal_timetracking content'] = array(
    'name' => 'delete own erpal_timetracking content',
    'roles' => array(
      0 => 'crm user',
      1 => 'project user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any erpal_timetracking content
  $permissions['edit any erpal_timetracking content'] = array(
    'name' => 'edit any erpal_timetracking content',
    'roles' => array(),
  );

  // Exported permission: edit own erpal_timetracking content
  $permissions['edit own erpal_timetracking content'] = array(
    'name' => 'edit own erpal_timetracking content',
    'roles' => array(
      0 => 'crm user',
      1 => 'project user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
