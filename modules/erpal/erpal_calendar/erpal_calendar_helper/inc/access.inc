<?php
/**
* @file
* All functions that grant access for erpal_date nodes of calendar feature
*/
define('CALENDAR_ACL_PRIO', 0);

/**
* manage ACL for a date node
*/
function _erpal_calendar_helper_manage_date_acl($node, $op) {
  
  if ($op == 'update' || $op == 'insert') {    
    //Ensure ACLs existence, but we manage only view access
    $date_view_acl = _erpal_calendar_helper_access_init_date_acl($node->nid, 'view', true);
    
    $participants = isset($node->field_users[LANGUAGE_NONE][0]) ? $node->field_users[LANGUAGE_NONE] : array();
      
    //assign these users to the ACL
    foreach($participants as $uid) {
      $uid = $uid['target_id'];
      acl_add_user($date_view_acl, $uid);
    }
    //assign the ACL to the department (View Yes, Write No, Delete No, prio=5)
    acl_node_add_acl($node->nid,$date_view_acl,1,0,0,CALENDAR_ACL_PRIO);    
    node_access_acquire_grants($node);
  } elseif ($op == 'delete') {
    //delete all the ACL of the date node
    _erpal_calendar_helper_access_clear_acls($node->nid);
    return;
  }
  
}

/**
* Initialises the ACLs of a date node and returns the ID in an array
*/
function _erpal_calendar_helper_access_init_date_acl($nid, $op, $delete=false) {
  $acl_name = $op.'_date_'.$nid;
  
  $acl_id = acl_get_id_by_name('erpal_calendar_helper', $acl_name);
  if($acl_id && $delete){
    //start clean
    acl_delete_acl($acl_id);    
  }
  
  if ($delete)
    $acl_id = acl_create_new_acl('erpal_calendar_helper',$acl_name);
   
  return $acl_id;
}

/**
* Deletes all ACLs and clears the lists where a node is manages
*/
function _erpal_calendar_helper_access_clear_acls($nid) {
  //first, get all ACLs where the node is in
  $acls = array();
  $select = db_select('acl_node', 'an')
    ->fields('an', array('acl_id'))
    ->condition('an.nid', $nid);
  
  $result = $select->execute();
  //then delete the ACLs 
  while ($record = $result->fetchAssoc()) {
    acl_delete_acl($record['acl_id']);
  }
 
}

/**
* These functions are needed to make the ACL module work
*/

/* Used by the ACL module */
function erpal_calendar_helper_enabled() {
  return !erpal_calendar_helper_disabling();
}


/* Implementation of hook_disable()  */
function erpal_calendar_helper_disable() {
  erpal_calendar_helper_disabling(TRUE);
  node_access_rebuild();
}

	
/* Remembers if we have disabled access */
function erpal_calendar_helper_disabling($set = NULL) {
  static $disabling = FALSE;

  if (isset($set)) {
    $disabling = $set;
  }
  return $disabling;
}

//End of ACL needed functions