<?php
/**
* @file
* All functions that grant access for erpal_date nodes of calendar feature
*/
define('CALENDAR_AUL_PRIO', 0);

/**
 * Manage AUL for a date node.
 * 
 * @param object $node
 *   node object
 * @param string $op
 *   operation type
 */
function _erpal_calendar_helper_manage_date_aul($node, $op) {
  // Check node operation.
  if ($op == 'update' || $op == 'insert') {
    
    // Get all date participant users.
    $participants = array();
    if (isset($node->field_users[LANGUAGE_NONE][0])) {
      $participants = $node->field_users[LANGUAGE_NONE];
    }
    
    // Clear all of a module's AULs from a node.
    aul_node_delete($node);
    
    // Loop participents.
    foreach ($participants as $user) {  
      // Collect all uids.
      $uid = $user['target_id'];
      
      // Ensure AUL's existence, but we manage only view access.
      $date_view_aul = _erpal_calendar_helper_access_init_date_aul($uid, 'view');

      // Add current date node to users' AUL.
      aul_add_node($date_view_aul, $node->nid);
      
      // Assign the AUL to the department (View Yes, Write No, Delete No, 
      // prio=0).
      aul_user_add_aul($uid, $date_view_aul, 1, 0, 0, CALENDAR_AUL_PRIO);
    }
    
    // Rebuild grants after AULs' update.
    node_access_acquire_grants($node);
  }
}

/**
 * Initialises the AULs of a user and returns the ID in an array.
 * 
 * @param int $uid
 *   User id
 * @param string $op
 *   operation name
 * @param bool $recreate
 *   optional parameter for recreation
 * 
 * @return int
 *   Returns the id of a AUL for a given user and operation
 */
function _erpal_calendar_helper_access_init_date_aul($uid, $op, $recreate = FALSE) {
  $aul_name = $op . '_uid_' . $uid;

  // get aul id or create new if doesn't exist
  $aul_id = aul_get_id_by_name('erpal_calendar_helper', $aul_name);
  // delete if it's needed
  if ($aul_id && $recreate) {
    aul_delete_aul($aul_id);
  }
  // create new if it doesn't exist or was deleted
  if (!$aul_id || $recreate) {
    $aul_id = aul_create_aul('erpal_calendar_helper', $aul_name);
  }

  return $aul_id;
}

/**
 * @defgroup aul_helpers AUL: helpers
 * @ingroup helpers
 * @{
 * These functions are needed to make the AUL module work
 */

/**
 * Implements hook_aul_enabled().
 * Used by the AUL module
 */
function erpal_calendar_helper_aul_enabled() {
  return !erpal_calendar_helper_disabling();
}

/**
 * Implements hook_disable().
 */
function erpal_calendar_helper_disable() {
  erpal_calendar_helper_disabling(TRUE);
  node_access_rebuild();
}

/**
 * Remembers if we have disabled access
 */
function erpal_calendar_helper_disabling($set = NULL) {
  static $disabling = FALSE;

  if (isset($set)) {
    $disabling = $set;
  }
  return $disabling;
}

/**
 * @} End of "defgroup aul_helpers".
 */