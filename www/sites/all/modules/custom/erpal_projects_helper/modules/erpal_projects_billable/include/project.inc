<?php

/**
* @file all functions dealing with projects in erpal_projects_billable module
*/

/**
* Function callback on insert project
* @param the project node
*/
function _erpal_projects_billable_insert_project($node) {
  
  //only process if the task is completed!
  $project_status = false;
  $project_status = _erpal_basic_helper_get_tid_semantic($node, 'field_project_status_term');  

  if ($project_status != 'completed')
    return;
    
  _erpal_billable_update_billable($node, 'insert');
}

/**
* Function on update task. Functions fetches the related billable entity (only one per task) and alters its data if
* according to the settings on the task node (druation changed etc).
* this happens only if the billabe is not set to "billed"!
* possible cases:
* - if billable is already billed: do nothing!
* - else:
* - there is allready a billabe referenced to this task and the task status is complete: adapt information to billable
* - there is allready a billabe referenced to this task and the task status is NOT complete: delete the billable //@todo: really?
* - there is no billabe referenced to the task: create a new one!
* @param the task node
*/
function _erpal_projects_billable_update_project($node) {
  
  $billables = _erpal_projects_billable_billbales_by_subject_nid($node->nid, true);
    
  $billable_information = _erpal_projects_billable_subject_billable_information_subject($node);
  
  /*
  //now we have all information to create a billable from this project
  $price_mode = isset($billable_information['per_hour']) ? $billable_information['per_hour'] : 0;
  $price = isset($billable_information['price']) ? $billable_information['price'] : 0;  
  $customer_node = $billable_information['customer'];

  //not a fixed price project, no customer or no price set? Skip!
  if (!($price_mode == 'fixed_price' && $price && $customer_node))
    return;
  */
  _erpal_billable_update_billable($node, 'update');
    
}