<?php

/**
* @file all functions dealing with access granting of invoices
*/
define('INVOICE_AUL_GRANT_REALM', 'erpal_invoice_helper');


/**
* Implements hook_aul_node_add
*/
function erpal_invoice_helper_aul_add_node($nid, $aul_id) {  
  $node = node_load($nid);
  if ($node->type != 'erpal_invoice') {
    return false;
  }
  
  //grant access to the related file node
  //get the files of the invoice
  $node_w = entity_metadata_wrapper('node', $node);
  $files = $node_w->field_asset_files->value();
 
  if (is_array($files)) {
    foreach ($files as $file_node) {
      aul_add_node($aul_id, $file_node->nid);
      node_access_acquire_grants($file_node);
    }  
  }  
}

/**
* Implements hook_aul_remove_add
*/
function erpal_invoice_helper_aul_remove_node($nid, $aul_id) {
  $node = node_load($nid);
  if ($node->type != 'erpal_invoice') {
    return false;
  }

  //remove grants for access to the related file node
  //get the files of the invoice
  $node_w = entity_metadata_wrapper('node', $node);
  $files = $node_w->field_asset_files->value();
 
  if (is_array($files)) {
    foreach ($files as $file_node) {
      aul_remove_node($aul_id, $file_node->nid);
      node_access_acquire_grants($file_node);
    }  
  }  
}


/**
* Recalculate grants for ALL invoices
* @param invoice_nids array of invoice nid. If set only for those invoices the grants are recalculated
*/
function _erpal_invoice_helper_calculate_all_invoices_access($invoice_nids=array()) {

  if (empty($invoice_nids)) {
    $invoice_nids = _erpal_invoice_helper_get_invoices();
  }
  
  //start in a batch operation!
  $operations = array(
    array('_erpal_invoice_helper_calculate_invoice_access_batch', array($invoice_nids))
  );
  
  $batch = array(
    'operations' => $operations,
    'title' => t('Processing invoice access grants'),
    'init_message' => t('Batch is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('The batch process has encountered an error.'),
    'finished' => '_erpal_invoice_helper_calculate_invoice_access_finish',
  );

  batch_set($batch);
  batch_process(); //return to the given redirect

}

/**
* Finish callback for the invoice access recalculate batch operation
*/
function _erpal_invoice_helper_calculate_invoice_access_finish($success, $results, $operations) {
  if ($success) {    
    drupal_set_message(t('The invoice access control has been updated.'));    
  }
}

/**
* The batch operation called in the batch to calculate node access grants
*/
function _erpal_invoice_helper_calculate_invoice_access_batch($nids, &$context) {
   $total_count = count($nids);

  if (!isset($context['sandbox']['progress'])) {  
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['nids'] = $nids;
    $context['sandbox']['last_delta'] = -1;
    $context['sandbox']['max'] = isset($context['sandbox']['max']) ? $context['sandbox']['max'] : $total_count;
  }

  $nids = $context['sandbox']['nids'];
  $delta = $context['sandbox']['last_delta'] + 1;

  if (isset($nids[$delta])) {
    $nid = $nids[$delta];
    
    _erpal_invoice_helper_calculate_invoice_access($nid);
         
    $context['sandbox']['last_delta'] = $delta;
  }
 
  $context['sandbox']['progress']++;
  $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
}

/**
* Recalculate grants for one invoice.
* Add access grants if there are users that reference a contact in their profile that is either the customer of the invoice or that is related with a "works at" relation to another contact that is the customer of the invoice
* @param node invoice_node the node to calculate grants for
* @param boolean delete_grants if true, first all grants will be removed then recalculated
*/
function _erpal_invoice_helper_calculate_invoice_access($invoice_node, $delete_grants=false) {
  if (is_numeric($invoice_node)) {
    $invoice_node = node_load($invoice_node);
  }
  
  if ($delete_grants) {
    _erpal_invoice_helper_remove_invoice_access($invoice_node->nid);    
  }
  
  $access_control_enabled = _erpal_invoice_helper_get_access_control_invoices();
  if ($access_control_enabled) {
    //get the customer
    $invoice_node_w = entity_metadata_wrapper('node', $invoice_node);
    $customer_node = $invoice_node_w->field_customer_ref->value();
    
    $granted_contacts = _erpal_invoice_helper_get_all_related_contacts($customer_node, 'works_at');
    $granted_contacts[] = $customer_node->nid;
        
    //make the array unique    
    $granted_contacts = array_unique($granted_contacts);  
    foreach ($granted_contacts as $contact_nid) {
      _erpal_invoice_helper_calculate_invoice_access_by_contact($invoice_node->nid, $contact_nid);      
    }
  }
  
  node_access_acquire_grants($invoice_node);    
}

/**
* Grants invoices access for a given invoice node and all users that are somehow related to the contact
*/
function _erpal_invoice_helper_calculate_invoice_access_by_contact($invoice_nid, $contact_nid) {
  $referencing_profiles = _erpal_profile_helper_profiles_by_contact($contact_nid);

  foreach ($referencing_profiles as $profile_id) {
    $profile = profile2_load($profile_id);
    $uid = $profile->uid;
    $grants = array('view' => true);      
  
    //now grant access to the invoice for all the users
    aul_add_aul($uid, $invoice_nid, $grants, INVOICE_AUL_GRANT_REALM); 
  }
}

/**
* Returns all nids of all contacts that are related to the given contact using the relation of the relation_type
*/
function _erpal_invoice_helper_get_all_related_contacts($customer_node, $relation_type=false) {
  $related_contact_nids = array();
 
  //loop through all relations
  if (!empty($customer_node->field_contact_relations[LANGUAGE_NONE])) {
    foreach ($customer_node->field_contact_relations[LANGUAGE_NONE] as $relation) {
      if (!_erpal_invoice_helper_invoice_access_is_processed_relations($relation)) {
        $related_contact_nids = _erpal_invoice_helper_get_relation_contacts($relation, $relation_type);
      }
    }
  }

  return $related_contact_nids;
}

/**
* Returns all related contacts of a relation
*/
function _erpal_invoice_helper_get_relation_contacts($relation, $relation_type=false) {
  
  if (is_object($relation))
    $relation = (array)$relation;
  
  $related_contact_nids = array();
  if ($relation['relation_type'] == $relation_type || !$relation_type) {
    //add all endpoints
    $endpoints = !empty($relation['endpoints'][LANGUAGE_NONE]) ? $relation['endpoints'][LANGUAGE_NONE] : array();
    foreach ($endpoints as $delta => $endpoint) {
      if ($endpoint['entity_type'] == 'node') {
        //don't load the complete node for performance reasons but get the base data we need
        $node_base = erpal_lib_helper_node_base_data(array($endpoint['entity_id']), true);
        $node_base = !empty($node_base[$endpoint['entity_id']]) ? $node_base[$endpoint['entity_id']] : false;
        
        if (!$node_base)
          continue;
          
        if ($node_base->type == 'erpal_contact') {
          //add it to the granted contacts
          $related_contact_nids[] = $node_base->nid;
        }
      }
    }
  }
  
  return array_unique($related_contact_nids);
}

/**
* Removes all grants for invoice access control
* @param integer invoice_nid if this has a value, we only remove the grants for this invoice
* @param integer uid if this has a value, we only remove the grants for this user
* @param direct_aquire_grants boolean if true, the node grants will be acquired immediately. Otherwise the flag for dirty node access will be set
*/
function _erpal_invoice_helper_remove_invoice_access($invoice_nid=false, $uid=false, $direct_aquire_grants=false) {
  $uids = array();
  $nids = array();
  
  if (!$invoice_nid) {
    //load all invoices
    $nids = _erpal_invoice_helper_get_invoices();
  } else {
    $nids = array($invoice_nid);
  }
  
  if (!$uid) {
    //load all uids
    $result = db_select('users', 'u')
    ->fields('u', array('uid'))
    ->condition('uid', 1, '>')
    ->execute();
    
    $uids = array();
    
    while ($uid = $result->fetchAssoc()) {
      $uids[] = $uid['uid'];
    }
    
  } else {
    $uids = array($uid);
  }
  
  $grants = array('view' => TRUE);
  foreach ($nids as $nid) {
    foreach ($uids as $uid) {
      aul_remove_aul($uid, $nid, $grants, INVOICE_AUL_GRANT_REALM);
    }
    
    if ($direct_aquire_grants) {
      $node = node_load($nid);
      node_access_acquire_grants($node);
    }
  }
  
}

/**
* Removes grants by invoice ID and contact ID
*/
function _erpal_invoice_helper_remove_access_by_invoice_and_contact($invoice_nid, $contact_nid) {
  $referencing_profiles = _erpal_profile_helper_profiles_by_contact($contact_nid);
  foreach ($referencing_profiles as $profile_id) {
    $profile = profile2_load($profile_id);
    $uid = $profile->uid;
    $grants = array('view' => true);        
    aul_remove_aul($uid, $invoice_nid, $grants, INVOICE_AUL_GRANT_REALM);
  }
}

/**
* Updates invoice access for a relation of an inserted contact
*/
function _erpal_invoice_helper_calculate_invoice_access_on_relation_inserted($relation) {
  //if it already was processed in node insert or update, skip this relation, no second processing needed.  
  if (_erpal_invoice_helper_invoice_access_is_processed_relations($relation)) {    
    return;
  }
  
  //get all related contacts
  $related_contact_nids = _erpal_invoice_helper_get_relation_contacts($relation, 'works_at');
 
  //get invoices of these contacts
  $invoice_nids = _erpal_invoice_helper_get_invoices($related_contact_nids);

  //now recalculate access for these invoices and the contacts.  
  foreach ($invoice_nids as $invoice_nid) {
    foreach ($related_contact_nids as $contact_nid) {
      //first remove all grants
      _erpal_invoice_helper_remove_access_by_invoice_and_contact($invoice_nid, $contact_nid);
      
      //only grant again, if the current date is in between of the relations start and end date (if a end date is set)
      $relation_w = entity_metadata_wrapper('relation', $relation);
      $date = $relation_w->field_date->value();
      $start_date = strtotime($date['value']);
      $end_date = strtotime($date['value2']);
      
      $is_active = FALSE;
      if ($start_date < time() && $start_date == $end_date) //no end date set
        $is_active = TRUE;
      if ($start_date < time() && $end_date > time())
        $is_active = TRUE;
      
      if ($is_active) {
        _erpal_invoice_helper_calculate_invoice_access_by_contact($invoice_nid, $contact_nid);
      }
    }
    
    $invoice_node = node_load($invoice_nid);    
    node_access_acquire_grants($invoice_node);
  }
}

/**
* Save which relations have already been updated in order to not update them again if a node is saved, and with this node the relations. We don't need to handle this twice.
*/
function _erpal_invoice_helper_invoice_access_is_processed_relations($relation) {
  static $cache = array();
  
  if (is_array($relation)) {
    $relation = (object)$relation;
  }

  if (!empty($cache[$relation->rid])) {
    return TRUE;
  }
  
  $cache[$relation->rid] = TRUE;
  return FALSE;
}

/**
* Updates invoice access for an updated relation of a contact
*/
function _erpal_invoice_helper_calculate_invoice_access_on_relation_updated($relation) {
  _erpal_invoice_helper_calculate_invoice_access_on_relation_inserted($relation);
}

/**
* Remove grants for a deleted invoice
*/
function _erpal_invoice_helper_calculate_invoice_access_on_relation_deleted($relation) {
  //get all related contacts
  $related_contact_nids = _erpal_invoice_helper_get_relation_contacts($relation, 'works_at');
 
  //get invoices of these contacts
  $invoice_nids = _erpal_invoice_helper_get_invoices($related_contact_nids);

  //now recalculate access for these invoices and the contacts.  
  foreach ($invoice_nids as $invoice_nid) {
    foreach ($related_contact_nids as $contact_nid) {
      $referencing_profiles = _erpal_profile_helper_profiles_by_contact($contact_nid);

      foreach ($referencing_profiles as $profile_id) {
        $profile = profile2_load($profile_id);
        $uid = $profile->uid;
        $grants = array('view' => true);    
        aul_remove_aul($uid, $invoice_nid, $grants, INVOICE_AUL_GRANT_REALM);
      }
    }
    
    $invoice_node = node_load($invoice_nid);    
    node_access_acquire_grants($invoice_node);
  }
}

/**
* Update the invoice access if a profile has changed
*/
function _erpal_invoice_helper_update_invoice_access_on_profile_update($profile) {
  $original_profile = !empty($profile->original) ? $profile->original : false;  
  $profile_w = entity_metadata_wrapper('profile2', $profile);
  
  $original_nid = false;
  $original_uid = false;
  if ($original_profile) {
    $original_profile_w = entity_metadata_wrapper('profile2', $original_profile);
    $original_contact = $original_profile_w->field_contact_ref->value();
    if ($original_contact)
      $original_nid = $original_contact->nid;
      
    $original_uid = $original_profile->uid;  
  } 
  
  $contact_nid = false;
  $contact = $profile_w->field_contact_ref->value();
  if ($contact)
    $contact_nid = $contact->nid;
  
  //if contact did not change, do nothing
  if ($original_nid == $contact_nid) {
    return;
  }
  $invoice_nids_to_acquire = array();

  if ($original_nid) {
    //process the previous version of the profile, if there was one    
    //get all related contacts
    $contact_nids = _erpal_invoice_helper_get_all_related_contacts($original_contact, 'works_at');
    $contact_nids[] = $original_contact->nid;
    
    //get all invoices by a contacts
    $invoice_nids = _erpal_invoice_helper_get_invoices($contact_nids);
    $invoice_nids = array_unique($invoice_nids);
    $contact_nids = array_unique($contact_nids);
    foreach ($invoice_nids as $invoice_nid) {
      foreach ($contact_nids as $a_contact_nid) {              
        $grants = array('view' => true);        
        aul_remove_aul($original_uid, $invoice_nid, $grants, INVOICE_AUL_GRANT_REALM);       
      }
      
      $invoice_nids_to_acquire[] = $invoice_nid;      
    }
  }
  
  
  if ($contact_nid) {
    //process the new profiles contact
    //get all related contacts
    $contact_nids = _erpal_invoice_helper_get_all_related_contacts($contact, 'works_at');
    $contact_nids[] = $contact->nid;
    
    //get all invoices by a contacts
    $invoice_nids = _erpal_invoice_helper_get_invoices($contact_nids);
    $invoice_nids = array_unique($invoice_nids);
    $contact_nids = array_unique($contact_nids);
    foreach ($invoice_nids as $invoice_nid) {
      foreach ($contact_nids as $a_contact_nid) {      
        _erpal_invoice_helper_calculate_invoice_access_by_contact($invoice_nid, $a_contact_nid);
      }
      
      $invoice_nids_to_acquire[] = $invoice_nid;            
    }
  }
  
  //acquire grants
  foreach ($invoice_nids_to_acquire as $nid) {
    $invoice_node = node_load($nid);    
    node_access_acquire_grants($invoice_node);
  }  
  
}
