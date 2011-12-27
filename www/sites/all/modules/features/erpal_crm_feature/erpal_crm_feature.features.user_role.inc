<?php
/**
 * @file
 * erpal_crm_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function erpal_crm_feature_user_default_roles() {
  $roles = array();

  // Exported role: crm user
  $roles['crm user'] = array(
    'name' => 'crm user',
    'weight' => '3',
  );

  return $roles;
}
