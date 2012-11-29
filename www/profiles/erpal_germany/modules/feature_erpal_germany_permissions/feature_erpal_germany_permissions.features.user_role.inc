<?php
/**
 * @file
 * feature_erpal_germany_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_erpal_germany_permissions_user_default_roles() {
  $roles = array();

  // Exported role: account manager.
  $roles['account manager'] = array(
    'name' => 'account manager',
    'weight' => '7',
  );

  // Exported role: controller.
  $roles['controller'] = array(
    'name' => 'controller',
    'weight' => '6',
  );

  // Exported role: customer.
  $roles['customer'] = array(
    'name' => 'customer',
    'weight' => '2',
  );

  // Exported role: external developer.
  $roles['external developer'] = array(
    'name' => 'external developer',
    'weight' => '4',
  );

  // Exported role: financial user.
  $roles['financial user'] = array(
    'name' => 'financial user',
    'weight' => '5',
  );

  // Exported role: internal developer.
  $roles['internal developer'] = array(
    'name' => 'internal developer',
    'weight' => '3',
  );

  // Exported role: project manager.
  $roles['project manager'] = array(
    'name' => 'project manager',
    'weight' => '8',
  );

  return $roles;
}
