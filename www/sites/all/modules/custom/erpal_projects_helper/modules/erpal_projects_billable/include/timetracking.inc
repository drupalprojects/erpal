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
  $billable_information = _erpal_projects_billable_subject_billabel_information_subject($subject_node);

  //only process if the task is price mode per hour!
  //if ($billable_information['price_mode'] != 'per_hour')
    //return;

  _erpal_billable_update_billable($node, 'insert');

}


/**
* Function on update timetracking. Functions fetches the related billable entity (only one per Timetracking) and alters its data if
* according to the settings on the timetracking node (druation changed etc)
* this happens only if the billabe is not set to "billed"!
* @param the timetracking node
*/
function _erpal_projects_billable_update_timetracking($node) {
  
  //get the billabel
  $billables = _erpal_projects_billable_billbales_by_subject_nid($node->nid, true);

  $subject_nid = $node->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
  $subject_node = node_load($subject_nid);
  $billable_information = _erpal_projects_billable_subject_billabel_information_subject($subject_node);

  //only process if the task is completed!
  //if ($billable_information['price_mode'] != 'per_hour')
    //return;

  _erpal_billable_update_billable($node, 'update');
 
}