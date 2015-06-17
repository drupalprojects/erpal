<?php

/**
* @file this file contains all custome code to handle project based book access
*/

/**
* Implements hook_node_presave
*/ 
function erpal_projects_books_access_node_presave($node) {
  if ($node->type != 'erpal_project')
    return;
  
  if (empty($node->nid))
    return;
  
  _erpal_projects_books_access_handle_grants($node, 'presave');
}

/**
* Function handles grants for books of the currently saved project team field collection
*/
function _erpal_projects_books_access_handle_grants($project_node, $op) {
  //static cache to process only once
  static $cache = array();
  if (!empty($cache[$project_node->nid]))
    return;
  $cache[$project_node->nid] = true;  
  
  //get all referenced concepts
  $books = !empty($project_node->field_books_ref[LANGUAGE_NONE]) ? $project_node->field_books_ref[LANGUAGE_NONE] : array();  

  //flatten books array
  $book_nids = array();
  foreach ($books as $nid) {
    $book_nids[] = $nid['target_id'];
  }
  
  //get all ORIGINAL referenced concepts in the PREVIOUS VERSION
  $old_project_node = !empty($project_node->original) ? $project_node->original : false;
  $old_books = array();
  if ($old_project_node) {
    $old_books = !empty($old_project_node->field_books_ref[LANGUAGE_NONE]) ? $old_project_node->field_books_ref[LANGUAGE_NONE] : array();
  }
  
  //if there are no current books and no book in the previous version, return without doing anything
  if (!count($books) && !count($old_books))
    return;

  //flatten books array
  $old_book_nids = array();
  foreach ($old_books as $nid) {
    $old_book_nids[] = $nid['target_id'];
  }
  
  //now we have old an new books. We can get added and deleted books from that. 
  //For added books we need to give all grants to all team members, not only changes, including to pages
  //For deleted books we need to remove grants for the book and for pages!
  
  //check which book nids are new!
  $new_book_nids = array();
  foreach ($book_nids as $book_nid) {
    if (!in_array($book_nid, $old_book_nids)) {
      $new_book_nids[] = $book_nid;
    }
  }
  
  //check removed book nids
  $removed_book_nids = array();
  foreach ($old_book_nids as $book_nid) {
    if (!in_array($book_nid, $book_nids)) {
      $removed_book_nids[] = $book_nid;
    }
  }

  $changed_permissions = _erpal_projects_helper_get_team_changes($project_node);
  $acquire_grant_nodes = _erpal_projects_books_access_grant_book_permissions($changed_permissions, $book_nids, $project_node);
  
  //now do the same again but for all permissions and only the new added books
  $new_acquire_grant_nodes = array();
  $all_permissions = _erpal_projects_helper_get_team_changes($project_node, true);
  $new_acquire_grant_nodes = _erpal_projects_books_access_grant_book_permissions($all_permissions, $new_book_nids, $project_node);
  $acquire_grant_nodes = array_merge($acquire_grant_nodes, $new_acquire_grant_nodes);
  
  //now remove grants from removed books and their pages
  $new_acquire_grant_nodes = array();
  $all_permissions_delete_op['delete'] = !empty($all_permissions['add']) ? $all_permissions['add'] : array();
  $new_acquire_grant_nodes = _erpal_projects_books_access_grant_book_permissions($all_permissions_delete_op, $removed_book_nids, $project_node);
  $acquire_grant_nodes = array_merge($acquire_grant_nodes, $new_acquire_grant_nodes);
  
  
  //no aquire grants
  foreach ($acquire_grant_nodes as $nid) {
    $node = node_load($nid);
    node_access_acquire_grants($node);
  }
}

/**
* Handles the aul assignement process for given permissions and given book nids
* @param $changed_permissions a permission array of added and removed permissions each user
* @param $book_nids the books nid to add or remove grants from / to
* @param $project_node the project node that gives grants to the books
*/
function _erpal_projects_books_access_grant_book_permissions($changed_permissions, $book_nids, $project_node) {
  //now add and remove all according to the change record
  //first delete permissions
  $acquire_grant_nodes = array();
  if (!empty($changed_permissions['delete'])) {
    foreach ($changed_permissions['delete'] as $uid => $fields) {
      if (empty($fields['field_book_permissions'])) 
        continue;
        
      foreach ($fields['field_book_permissions'] as $permission) {
        $aul_id = _erpal_projects_books_access_init_aul_list($permission, $uid, $project_node->nid);
        //remove all nodes from the users aul list
        foreach ($book_nids as $book_nid) {
          aul_remove_node($aul_id, $book_nid);  //let book access decide if grants should be removed from sub pages or not
          $acquire_grant_nodes[] = $book_nid;
        }
      }
    }
  }
  
  //now add permissions
  if (!empty($changed_permissions['add'])) {
    foreach ($changed_permissions['add'] as $uid => $fields) {
      if (empty($fields['field_book_permissions'])) 
        continue;
        
      foreach ($fields['field_book_permissions'] as $permission) {

        //init permissions
        $perm = array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        );
      
        $aul_id = _erpal_projects_books_access_init_aul_list($permission, $uid, $project_node->nid);
        if ($permission == 'view_books') {
          $perm['view'] = 1;
        }
        
        if ($permission == 'update_books') {
          $perm['update'] = 1;
        }
        
        // add user access
        aul_user_add_aul($uid, $aul_id, $perm['view'], $perm['update'], $perm['delete'], 0);
        
        //now add every book referenced to the project
        foreach ($book_nids as $book_nid) {
          aul_add_node($aul_id, $book_nid); //let book access module handle if grants should be given to the sub pages or not
          
          $acquire_grant_nodes[] = $book_nid;
        }
      }
    }
  }
  
  return $acquire_grant_nodes;
}

/**
* Init AUL list for the given pperation
* @TODO: we will have a AUL list for every user for every project because if a book was removed from 
* a project grants should only be removed that were given by this project. May be this is inperformanter because
* it increase grants as ACL does. Just to leave a note here. But we hve to know in this case where the grants came from.
* UPDATE: Currently we ensure that a book can only be in one project t the same time. SO this will not increase AUL within this configuration
*/
function _erpal_projects_books_access_init_aul_list($op, $uid, $project_nid, $recreate=false) {
  $module = 'erpal_projects_books_access';
  
  $aul_name = _erpal_projects_books_access_get_aul_name($op, $uid, $project_nid);

  // get aul id or create new if doesn't exist
  $aul_id = aul_get_id_by_name($module, $aul_name);
  // delete if it's needed
  if ($aul_id && $recreate) {
    aul_delete_aul($aul_id);
  }
  // create new if it doesn't exist or was deleted
  if (!$aul_id || $recreate) {
    $aul_id = aul_create_aul($module, $aul_name);
  }

  return $aul_id;
}

function _erpal_projects_books_access_get_aul_name($op, $uid, $project_nid) {
  // create aul name in format: $op_node
  $name = $op . '_uid_' . $uid . '_from_' . $project_nid;
  return $name;
}

/**
* Implements hook_project_team_changes_alter @see erpal_projects_helper.module
* with this hook we will alter the field values changed of fields that where added by this module
*/
function erpal_projects_books_access_project_team_changes_alter(&$changes, $context) {
  $op = $context['op'];
  $uid = $context['uid'];
  $member = $context['member'];
  $current_old_member = $context['current_old_member'];
  $get_all_current = $context['get_all_current'];
  
  //check the perms field
  $project_perms = !empty($member->field_book_permissions[LANGUAGE_NONE]) ? $member->field_book_permissions[LANGUAGE_NONE] : array();
  $old_project_perms = !empty($current_old_member->field_book_permissions[LANGUAGE_NONE]) ? $current_old_member->field_book_permissions[LANGUAGE_NONE] : array();;

  $perms = array();    
  $old_perms = array();
  
  foreach ($project_perms as $perms_arr) {
    $perms[] = $perms_arr['value'];    
  }
  
  foreach ($old_project_perms as $perms_arr) {
    $old_perms[] = $perms_arr['value'];    
  }

  if ($get_all_current) {
    $diff_arr = $perms;
  } else {
    $diff_arr = array_diff($perms, $old_perms);
  }
  
  if (!empty($diff_arr))
    $changes[$op][$uid]['field_book_permissions'] = $diff_arr;
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
function erpal_projects_books_access_aul_enabled() {
  return !erpal_projects_books_access_disabling();
}

/**
 * Implements hook_disable().
 */
function erpal_projects_books_access_disable() {
  erpal_projects_books_access_disabling(TRUE);
  node_access_rebuild();
}

/**
 * Remembers if we have disabled access.
 */
function erpal_projects_books_access_disabling($set = NULL) {
  static $disabling = FALSE;

  if (isset($set)) {
    $disabling = $set;
  }
  return $disabling;
}

/**
 * @} End of "defgroup aul_helpers".
 */