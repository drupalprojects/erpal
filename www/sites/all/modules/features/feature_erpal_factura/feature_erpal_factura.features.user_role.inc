<?php
/**
 * @file
 * feature_erpal_factura.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_erpal_factura_user_default_roles() {
  $roles = array();

  // Exported role: factura user
  $roles['factura user'] = array(
    'name' => 'factura user',
    'weight' => '5',
  );

  return $roles;
}
