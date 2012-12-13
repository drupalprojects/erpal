<?php
/**
 * @file
 * feature_erpal_germany_permissions.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function feature_erpal_germany_permissions_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:erpal_space:customer'.
  $roles['node:erpal_space:customer'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'erpal_space',
    'name' => 'customer',
  );

  return $roles;
}
