<?php

/**
* @file all functions dealing with timetracking in erpal_projects_billable module
*/

/**
* Function callback on insert timetracking
* @param the timetracking node
*/
function _erpal_projects_billable_insert_timetracking($node) {
  
  $subject_nid = $node->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
  $subject_node = node_load($subject_nid);

  _erpal_billable_update_billable($node, 'insert');

}


/**
* Function on update timetracking. Functions fetches the related billable entity (only one per Timetracking) and alters its data if
* according to the settings on the timetracking node (druation changed etc)
* this happens only if the billabe is not set to "billed"!
* @param the timetracking node
*/
function _erpal_projects_billable_update_timetracking($node) {
 
  _erpal_billable_update_billable($node, 'update');
 
}