<?php
/**
* All functions needed to reduce some entities to one entity
*/

/**
* groups all billables to logic subsets with equal properties like vat_rate, customer etc.
*/
function _billable_group_for_reduce($billable_ids, $group_by=array(), $ignore_parent=false) {
  //ensure that we have a minimum group by array
  $group_by = _billable_ensure_minimal_group_by($group_by);

  $groups = array();
  foreach ($billable_ids as $billable_id) {
    //all reduced billables must have equal vat_rate, the same customer, same currency, or they are splitted into sub reduced billables
    $billable = billable_load($billable_id);

    //Validate if the billable could be reduced!
    if ($billable->billed)  //@TODO perhaps notify the user about this potential error!    
      continue; //billable entities that are already billed could not be reduced!
    if ($billable->parent_billable && !$ignore_parent)
      continue;  //billables that are already reduced should not be reduced any more!
      //@todo if we should provide this, we have to implement endless recursion in depth
      
    //we create an ID called unity that identifies a group    
    $unity = _billable_reduce_group_id($billable, $group_by);

    //with the unity we ensure that all billables have homogen certain attributes. So we just calculate and trust that they are
    //really homogen. They will not if user of this function fills a wrong group_by array !!!
    $groups[$unity]['billables'][] = $billable;
    $groups[$unity]['subject'] = t('Service according to attachment');  //@TODO hier soll der user einen Text vergeben können
    $groups[$unity]['currency'] = $billable->currency;
    $groups[$unity]['vat_rate'] = $billable->vat_rate;
    $date_delivery = isset($groups[$unity]['date_delivery']) ? $groups[$unity]['date_delivery'] : 0;
    $groups[$unity]['date_delivery'] = max($date_delivery, $billable->date_delivery);  //get the latest deliverydate of all
    $groups[$unity]['customer'] = $billable->customer_nid;

    //if we group by single price, we add the quantity and keep the single price otherwise it is always one and the
    //single price is added because we don't have the same single price at each billable in a group
    if (in_array('single_price', $group_by)) {      
      if (!isset($groups[$unity]['quantity']))
        $groups[$unity]['quantity'] = 0;
      $groups[$unity]['quantity'] += $billable->quantity;    
      
      $groups[$unity]['single_price'] = $billable->single_price;
    } else {
      $groups[$unity]['quantity'] = 1;
      if (!isset($groups[$unity]['single_price']))
        $groups[$unity]['single_price'] = 0;
        
      $groups[$unity]['single_price'] += $billable->total_price_no_vat;
    }
    
  }

  return $groups;
}

/**
* @see billable.entity.inc function reduce()
* @param $entity_ids an array of ids of billables that should be reduces to a minimum
* @param $group_by is an array of strings that identifys which fields must be equal to group
* @param $return_unreduce if true, billables that are not reduced because their group has only 
*   one element, are returned as "new billables", too
* @return all new created billables
*/
function _billable_reduce($billable_ids, $group_by=array(), $return_unreduced=false) {
  
  $new_billables = array();
  
  //get the groups with homgen customers, vat_rate and currency
  $groups = _billable_group_for_reduce($billable_ids, $group_by);

  //now we got all billables into groups, get on reduced billable for each group 
  foreach ($groups as $group_key=>$group_data) {
    //reduce only if there a more than 1 billables per group
    if (count($group_data['billables']) < 2) {
      if ($return_unreduced) {
        foreach ($group_data['billables'] as $billable)
          $new_billables[$billable->billable_id] = $billable;
      }
      continue;
    }
    
    //create a new billable
    $new_billable = entity_create('billable', array());
    $new_billable->subject = $group_data['subject'];
    $new_billable->currency = $group_data['currency'];
    $new_billable->subject_nid = 0; //parent billables have no subject nid
    $new_billable->quantity = $group_data['quantity'];
    $new_billable->single_price = $group_data['single_price'];
    $new_billable->vat_rate = $group_data['vat_rate'];
    $new_billable->date_delivery = $group_data['date_delivery'];
    $new_billable->billables = $group_data['billables'];  //not saved to database
    $new_billable->customer_nid = $group_data['customer'];  
    //@todo the field is external attached so this module should not know itbut it must be able to set the customer here....
    $new_billable->save();
    
    $new_billables[$new_billable->billable_id] = $new_billable;
    
    //and now set the id of the new billable entity as parent for each reduced billable in this group
    foreach ($group_data['billables'] as $billable) {
      $billable->parent_billable = $new_billable->billable_id;
      $billable->save();
    }
  }
  
  return $new_billables;
  
}

/**
* Creates a group id for a billable that is equal if some properties of a billable entity are equal
*/
function _billable_reduce_group_id($billable, $group_by) {

  $unity = '';
  foreach ($group_by as $field_name) {
    
    $value = $billable->field_by_name($field_name);
    if ($unity)
      $unity .= "-";
      
    $unity .= $value;
  }
  
  return $unity;
}

/**
* ensure that we have a minimum group by array, because on every reduce process we 
* need at least equal vat_rate, customer and currency
*/
function _billable_ensure_minimal_group_by($group_by) {
  if (!in_array('customer', $group_by))
    $group_by[] = 'customer';
    
  if (!in_array('vat_rate', $group_by))
    $group_by[] = 'vat_rate';

  if (!in_array('currency', $group_by))
    $group_by[] = 'currency';
    
  return $group_by;
}