<?php

/**
* @file all functions dealing with tasks in erpal_projects_billable module
*/

/**
* Function callback on insert task
* @param the task node
*/
function _erpal_projects_billable_insert_task($node) {
  
  $billable_information = _erpal_projects_billable_subject_billabel_information_subject($node);
  
  //only process if the task is completed!
  $task_status = $node->field_task_status[LANGUAGE_NONE][0]['value'];
  if ($task_status != 'completed')
    return;
  
  //now we have all information to create a billable from this timetracking
  $price_mode = isset($billable_information['per_hour']) ? $billable_information['per_hour'] : 0;
  $price = isset($billable_information['price']) ? $billable_information['price'] : 0;  
  $customer_node = $billable_information['customer'];
  if ($price_mode == 'fixed_price' && $price && $customer_node)
  {  
    $single_price = $price;
    $customer_nid = $customer_node->nid;
    $subject_nid = $node->nid;  //the subject is the timetracking itself
    $quantity = 1; //cause it is fixed price
    $currency = $billable_information['currency'];
    $vat_rate = $billable_information['vat_rate'];
    $subject_title = $node->title;
    $date_delivery = $node->changed; //last change of the task node
    
    //last parameter is set false, so we create a new billable!
    _erpal_project_billable_save_billable(
      $subject_title, 
      $customer_nid, 
      $subject_nid, 
      $quantity, 
      $single_price, 
      $currency, 
      $vat_rate, 
      $date_delivery, 
      false
    );
  }
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
function _erpal_projects_billable_update_task($node) {
  
  $billables = _erpal_projects_billable_billbales_by_subject_nid($node->nid, true);
    
  $billable_information = _erpal_projects_billable_subject_billabel_information_subject($node);
  
  //now we have all information to create a billable from this timetracking
  $price_mode = isset($billable_information['per_hour']) ? $billable_information['per_hour'] : 0;
  $price = isset($billable_information['price']) ? $billable_information['price'] : 0;  
  $customer_node = $billable_information['customer'];

  //not a fixed price project, no customer or no price set? Skip!
  if (!($price_mode == 'fixed_price' && $price && $customer_node))
    return;

  //otherwise prepare data for the billable entity
  $single_price = $price;
  $customer_nid = $customer_node->nid;
  $subject_nid = $node->nid;  //the subject is the timetracking itself
  $quantity = 1; //cause it is a fixed price task
  $currency = $billable_information['currency'];
  $vat_rate = $billable_information['vat_rate'];
  $subject_title = $node->title;
  $date_delivery = $node->created;

  //There should be only one billable to this task. But we get an array so we process it completely 
  $has_billable = false;
  $task_status = $node->field_task_status[LANGUAGE_NONE][0]['value'];
  foreach ($billables as $id=>$billable) {
    $has_billable = true;
    if ($billable->billed)
      continue;  //do nothing, cause it is already billed
    
    //not completed any more?
    if ($task_status != 'completed') {
      //delete the billable, it is not allowed here, cause the task has not been completed!
      entity_delete('billable', $billable->billable_id);
    } else {
      //if task status is completed
      //last parameter is set false, so we create a new billable!
      _erpal_project_billable_save_billable(
        $subject_title, 
        $customer_nid, 
        $subject_nid, 
        $quantity, 
        $single_price, 
        $currency, 
        $vat_rate, 
        $date_delivery, 
        $billable  //update this one
      );
    }
      
    
  }
  
  
  if (!$has_billable && $task_status == 'completed') {
    //create a new billable
    //last parameter is set false, so we create a new billable!
  _erpal_project_billable_save_billable(
    $subject_title, 
    $customer_nid, 
    $subject_nid, 
    $quantity, 
    $single_price, 
    $currency, 
    $vat_rate, 
    $date_delivery, 
    false  //create a new billable
  );
  }
    
}