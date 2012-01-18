<?php
/**
 * @file
 * feature_erpal_crm.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_erpal_crm_user_default_roles() {
  $roles = array();

  // Exported role: crm user
  $roles['crm user'] = array(
    'name' => 'crm user',
    'weight' => '3',
  );

  return $roles;
}
