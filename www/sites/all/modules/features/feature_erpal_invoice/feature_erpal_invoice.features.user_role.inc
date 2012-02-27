<?php
/**
 * @file
 * feature_erpal_invoice.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function feature_erpal_invoice_user_default_roles() {
  $roles = array();

  // Exported role: invoice user
  $roles['invoice user'] = array(
    'name' => 'invoice user',
    'weight' => '5',
  );

  return $roles;
}
