<?php

/**
* @file all functions dealing with timetracking in erpal_projects_billable module
*/

/**
* Function callback on insert timetracking
* @param the timetracking node
*/
function _erpal_projects_billable_insert_timetracking($node) {
  
  $subject_nid = $node->field_timetracking_subject[LANGUAGE_NONE][0]['nid'];
  $subject_node = node_load($subject_nid);
  $billable_information = _erpal_projects_billable_subject_billabel_information_subject($subject_node);

  //only process if the task is completed!
  if ($billable_information['price_mode'] != 'per_hour')
    return;

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

  $subject_nid = $node->field_timetracking_subject[LANGUAGE_NONE][0]['nid'];
  $subject_node = node_load($subject_nid);
  $billable_information = _erpal_projects_billable_subject_billabel_information_subject($subject_node);

  //only process if the task is completed!
  if ($billable_information['price_mode'] != 'per_hour')
    return;

  _erpal_billable_update_billable($node, 'update');
  
  return;
  
  
  foreach ($billables as $id=>$billable) {
    //save the billabel, last parameter is set, so this billable will be updated
    if ($billable->billed)
      continue; //no Updated cause it has already been billed!
      
    //@todo perhaps show warning or information to the user

    //get the subject because it holds all pricing information
    if (!($billable->subject_nid))
      continue; //no subject, no pricing information
    
    $subject_node = $node;
    //get the princing information
    $billable_information = _erpal_projects_billable_subject_billabel_information_subject($subject_node);
    //$billing_duration = _erpal_projects_helper_get_billing_duration($subject_node);

    //now we have all information to create a billable from this timetracking
    $price_mode = isset($billable_information['per_hour']) ? $billable_information['per_hour'] : 0;
    $price = isset($billable_information['price']) ? $billable_information['price'] : 0;  
    
    if (!isset($billable_information['customer']) || !$billable_information['customer'])
      continue;  //no customer, no billable update!
  
    $customer_node = $billable_information['customer'];
    
    if ($price_mode == 'per_hour' && $price && $customer_node) { //must haves!
      $single_price = $price;
      $customer_nid = $customer_node->nid;
      $subject_nid = $subject_node->nid;  //the subject is the timetracking itself
      $quantity = $subject_node->field_billing_duration[LANGUAGE_NONE][0]['value']; //due to other hook this field should allways be filled
      $currency = $billable_information['currency'];
      $vat_rate = $billable_information['vat_rate'];
      $subject_title = $subject_node->title;
      $date_delivery = $subject_node->created;

      //save the billable entity
      _erpal_project_billable_save_billable(
        $subject_title, 
        $customer_nid, 
        $subject_nid, 
        $quantity, 
        $single_price, 
        $currency, 
        $vat_rate, 
        $date_delivery, 
        $billable
      );
    }
  }
}