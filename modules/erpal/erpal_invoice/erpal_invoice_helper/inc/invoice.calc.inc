<?php

/**
* @file calculates fields like total, payment date etc. if an invoice is inserted or updated
*/


/**
* @param object $invoice the invoice node the fields are calculated at
* @param string $action describes the action that called the function (update, insert, presave)
*/
function _erpal_invoice_helper_calculate_fields($invoice, $action) {
  //then all fields that are directly attached to the 
  //invoice node (no field collection and other entity references)  
  _erpal_invoice_helper_calculate_payment_date($invoice);
  
  //now the calculations using entity references and field collections
  _erpal_invoice_helper_calculate_prices($invoice, $action);
  _erpal_invoice_helper_set_billables_billed($invoice); 

  //if invoice contractor is not own company, set exported because it cannot be exported an so filtering is not possible
  //e.g. for all unexported invoices
  _erpal_invoice_helper_set_exported_if_extern($invoice);
}

/**
* Set a invoice to exported if contractor is not the own company
*/
function _erpal_invoice_helper_set_exported_if_extern($invoice, $skipp_save_invoice=true) {
  module_load_include('inc', 'erpal_basic_helper', 'inc/config');
  $company_nid = _erpal_basic_helper_get_own_company_nid(false);
  $contractor_nid = $invoice->field_contractor_ref[LANGUAGE_NONE][0]['target_id'];
  
  if ($company_nid != $contractor_nid)
    $invoice->field_invoice_exported[LANGUAGE_NONE][0]['value'] = 1;
    
  if (!$skipp_save_invoice)
    node_save($invoice);
}

/**
* The payment date of the invoice is caclualted
* @param $invoce the invoice the calculation is processed
*/
function _erpal_invoice_helper_calculate_payment_date($invoice) {

  $invoice_date = $invoice->field_invoice_date[LANGUAGE_NONE][0]['value'];
  $credit_period = $invoice->field_credit_period[LANGUAGE_NONE][0]['value'];
  
  //add the days of invoice_credit to the invoice_date in seconds because of unix timestamp
  $sec_per_day = 60 * 60 * 24;
  $payment_date = $invoice_date + ($credit_period * $sec_per_day);
  $invoice->field_payment_date[LANGUAGE_NONE][0]['value'] = $payment_date;
}

/**
* Calculats the invoice vat, the total invoice price excl and incl vat rates for each vat rate occuring in the invoice line intems
* @param $invoce the invoice the calculation is processed
*/
function _erpal_invoice_helper_calculate_prices($invoice) {

  //go througg each line item and pick the vat
  $line_items = $invoice->field_billables_ref[LANGUAGE_NONE];
  $vat_rates = array();
  $total_vat = 0;
  $total_excl_vat = 0;
  $total_incl_vat = 0;

  $currency = false;
  foreach ($line_items as $line_item) {
    if (!$line_item['target_id'])
      continue;
      
    $billable = billable_load($line_item['target_id']);

    $vat_rate = $billable->vat_rate;
    $vat = $billable->total_vat;
    if (!isset($vat_rates[$vat_rate]))
      $vat_rates[$vat_rate] = $vat;
    else
      $vat_rates[$vat_rate] += $vat;
      
    $total_vat += $vat;
    $total_excl_vat += $billable->total_price_no_vat;
    $total_incl_vat += $billable->total_price;
    
    //in the validation we have ensured that currencies in all billables are unique. 
    //so we can fill the variable from any billable.
    $currency = $billable->currency;
  }
  
  //first add the single values to the invoice
  $invoice->field_price_no_vat[LANGUAGE_NONE][0]['value'] = $total_excl_vat;
  $invoice->field_invoice_total[LANGUAGE_NONE][0]['value'] = $total_incl_vat;
  $invoice->field_currency[LANGUAGE_NONE][0]['value'] = $currency;
  
  //now we have to add an entity for vat field collection for each vat rate we have found
  //in our line items
  $delta = 0;

  foreach ($vat_rates as $vat_rate=>$vat) {
    $vat_rate_collection = false;
    if (isset($invoice->field_invoice_vat[LANGUAGE_NONE][$delta])) {
      //if there is already an entity, load it and re-calculate its values
      $id = $invoice->field_invoice_vat[LANGUAGE_NONE][$delta]['value'];
      //$id = $id['value'];
      $vat_rate_collection = entity_load('field_collection_item', array($id));
      
      if (is_array($vat_rate_collection))
        $vat_rate_collection = array_shift($vat_rate_collection);
    }
    
    if(!$vat_rate_collection) {
      //create a new field_collection_item entity
      $values = array();
      $values['field_name'] = 'field_invoice_vat';      
      $values['field_vat_rate'][LANGUAGE_NONE][0]['value'] = $vat_rate;   
      $values['field_vat_total'][LANGUAGE_NONE][0]['value'] = $vat;         
      //save the entity to link it to the host with its id, otherwise we dont have an id      
      $vat_rate_collection = entity_create('field_collection_item', $values);
      
      // Attach the field_collection entity to the application node. This has to
      // happen separately so that it actually works -- you can't just specify
      // this via the $values array.
      //@see http://drupal.org/node/1353926
      $vat_rate_collection->setHostEntity('node', $invoice, LANGUAGE_NONE, TRUE); //last param: true= link node to host
           
      $vat_rate_collection->save(true);  //save the entity AND save the host again
      $invoice->is_new = false; //otherwise the node will be added to the database again which leads to an duplicate entry in node table
     
      //node_save($invoice); //manually save the host node
      //already has a vat_rate_collection entity which leads to the next section of this if condition.
    } else    
    if (is_object($vat_rate_collection)) {
      //add values here, too because we manipulate an existing entity
      $vat_rate_collection->field_vat_rate[LANGUAGE_NONE][0]['value'] = $vat_rate;
      $vat_rate_collection->field_vat_total[LANGUAGE_NONE][0]['value'] = $vat;
      
      //no set host entity needed cause the collection entity is already attached to the node      
      $vat_rate_collection->save(true); //last param skips host save, because this will result in an endless loop!
    }
    
    $delta++;
  }
  
  $lastDelta = $delta-1;
  //delete all vat entities that have delta index bigger than the last $delta value
  foreach ($invoice->field_invoice_vat[LANGUAGE_NONE] as $delta=>$entity) {
    if ($delta > $lastDelta) {
      //unset this entity, it is not needed here. The entities will be deleted by the field collection module.
      $entity_id = $entity['value'];   
      unset($invoice->field_invoice_vat[LANGUAGE_NONE][$delta]);
    }
  }
  
}

/**
* Set all billable entities attached to that invoice as billed and saves them again
*/
function _erpal_invoice_helper_set_billables_billed($invoice) {
  //go throug each line item and pick the vat
  $line_items = $invoice->field_billables_ref[LANGUAGE_NONE];
  
  foreach ($line_items as $line_item) {
    $billable = billable_load($line_item['target_id']);
    $billable->set_billed(true);
    $billable->save();
  }
}

/**
* Function that creates the invoice note, with automatically generated notes (e.g. from vat settings)
* or from hook_invoice_notes by other moduls.
*/
function _erpal_invoice_helper_set_notes($invoice) {
  $notes = array();
 
  //if value is already set and not equal to default note, skipp!
  $skip_manuell_notes = false;
  $default_note = _erpal_invoice_helper_get_manuall_notes();
  if (isset($invoice->field_note[LANGUAGE_NONE][0]['value'])) {    
    if ($invoice->field_note[LANGUAGE_NONE][0]['value']) {
      $skip_manuell_notes = true;
    }
  }
  if (!$skip_manuell_notes) {
    //add these manual notes to the text area
    $invoice->field_note[LANGUAGE_NONE][0]['value'] = $default_note;
  }
  
  //now make them alterable by other modules and add these values to the auto notes
  $notes = module_invoke_all('invoice_notes_alter', $invoice);

  //order according to weight, an create the plain text that will be added to the invoice
  $ordered_notes = array();
  if (isset($notes['add']) && is_array($notes['add'])) {
    foreach ($notes['add'] as $note_arr) {
      $weight = $note_arr['weight'];
      $note = $note_arr['note'];
      $ordered_notes[$weight] = $note;
    }
  }
  
  ksort($ordered_notes);
  
  //add the nodes that should be added and delete the nodes that should be deleted!

  //first, delete notes that should be deleted!
  if (isset($notes['del']) && is_array($notes['del'])) {
    foreach ($notes['del'] as $note_to_del) {
      if (isset($invoice->field_auto_note[LANGUAGE_NONE])) {
        foreach ($invoice->field_auto_note[LANGUAGE_NONE] as $delta=>$auto_note) {
          $note = $auto_note['value'];
          if ($note == $note_to_del)
            unset($invoice->field_auto_note[LANGUAGE_NONE][$delta]);
        }
      }
    }
  }

  //and now add the other auto notes
  foreach ($ordered_notes as $weight=>$note) {
    //add it only if it does not exists
    $exists = false;
    if (isset($invoice->field_auto_note[LANGUAGE_NONE])) {
      if ($invoice->field_auto_note[LANGUAGE_NONE]) {
        foreach ($invoice->field_auto_note[LANGUAGE_NONE] as $existing_note) {
          if ($existing_note['value'] == $note) {
            $exists = true;
            break;
          }
        }
      }
    }
    
    if (!$exists)
      $invoice->field_auto_note[LANGUAGE_NONE][]['value'] = $note;
  }

}

/**
* Implements hook_invoice_notes_alter
* @param $invoice the invoice we create the notes for
*/
function erpal_invoice_helper_invoice_notes_alter($invoice) {
  //check if there is one vat rate that has a message, add the message to notes
  //we do NOT check with the field invoice_vat because perhaps this field is actually not
  //calculated. So we use the billables an the vat rate to check which var rates will be calculated at the billable
  
  //get all vat rates of the invoice
  $billables = $invoice->field_billables_ref[LANGUAGE_NONE];
  $invoice_vat = array();
  foreach ($billables as $delta=>$billable_id) {
    //load the billable
    $billable = billable_load($billable_id['target_id']);
    $invoice_vat[] = $billable->vat_rate;
  }

  $notes = array();
  $vat_rates = _erpal_invoice_helper_vat_rates_arr(true); //add notes to the labels

  foreach ($vat_rates as $vat_rate=>$vat_arr) {
    $vat_rate_note = $vat_arr['note'];
    
    $note_added = false;
    foreach ($invoice_vat as $delta=>$invoice_vat_rate) {
      if (isset($invoice_vat_rate['value']) && $vat_rate == $invoice_vat_rate['value']) {
        //add the note!
        if (isset($vat_arr['note']) && $vat_arr['note']) {
          $note_added = true;
          $notes['add'][] = array(
            'weight' => 2,  //@todo which value to preset here?
            'note' => $vat_arr['note'],
          );
        }
      }              
    }
    
    if (!$note_added && isset($vat_arr['note']) && trim($vat_arr['note']))
      $notes['del'][] = $vat_arr['note'];
  }

  return $notes;
}

/**
* Function to create an invoice
* @param $billable_ids an array of billable ids the invoice is created from
* @param $params an array with further params like credit period etc.
*   possible keys in $params array are: group_by, customer_id, currency, invoice_date, Credit_period, skonto['credit_period'] and skonto['discount_percent'] 
* @param $reduced boolean true if billables should be reduced as far as possible. Reduced billables could be printed as attachment later
* @return an status array with key 'status'=1 if everything is ok, if it is 0, errors are placed in the key 'errors', 'invoice' holds the invoice node
*/
function _erpal_invoice_helper_invoice_from_billables($billable_ids, $reduced=false, $params=array()) {
  global $user;
 
  $status = array(
    'status' => 1, //that means everything is ok
    'errors' => array(),
    'invoice' => false,
  );

  if (count($billable_ids) <= 0) {
    $status['status'] = 0;
    $status['errors'][] = t('There are no billable items the invoice should be created from.');
    return $status;
  }

  //perhaps there is no invoice address given, then we cannot create the invoice
  if (!(isset($params['address_id']) && intval($params['address_id']))) {
    $status['status'] = 0;
    $status['errors'][] = t('There is no invoice address selected for the invoice.');
    return $status;
  }

  if ($reduced) {
    //reduce all billables given and then create the bill with the reduced entities
    //Load files from the billable module
    module_load_include('inc', 'billable', 'billable.reduce');
    $group_by = array();
    if (isset($params['group_by'])) {
      if ($params['group_by'] == 'service_category') {  
        $group_by['service_category'] = array(          
          'field_name' => 'field_service_category_term', 
          'parents' => array(LANGUAGE_NONE, 0, 'tid')
        ); //may be there is the service_category field to group the billables by.
      }
      if ($params['group_by'] == 'expense_category') {
        $group_by['expense_category'] = array(          
          'field_name' => 'field_expense_category', 
          'parents' => array(LANGUAGE_NONE, 0, 'tid')
        ); //may be there is the expense_category field to group the billables by.
      }
    }
    
    $billables = _billable_reduce($billable_ids, $group_by, true);
    $billable_ids = array_keys($billables);
  }
  
  //load all billables for the test!
  $billables = billable_load_multiple($billable_ids);

  //try to get the customer and the contractor, if there is no customer in params, the customer of all billables must 
  //be equal otherwise there will be an error same for contractors
  //### get the customer ####
  $customer_nid_new = 0;
  if (isset($params['customer_nid']))
    $customer_nid = $params['customer_nid'];
  else {
    $customer_nid = 0; //init    
    foreach ($billables as $billable) {
      $customer_nid_new = $billable->customer_nid;
      if (!$customer_nid)
        $customer_nid = $customer_nid_new;
      else
        if ($customer_nid <> $customer_nid_new) {
          //BAD! There are different customers in the billables. We cannot create an invoice with that information!       
         $status['status'] = 0;
          $status['errors'][] = t('There is no unique customer for that invoice and the billable invoice lines have different customers set.');
          return $status;
        }
    }
    
    if (!$customer_nid) {
      //BAD! There is no customer detected in the billables!. We cannot create an invoice with that information!
      $status['status'] = 0;
      $status['errors'][] = t('There is no unique customer for that invoice found in the billable line items.');
      return $status;
    }
  }
  
  //### get the contractor ####
  if (isset($params['contractor_nid']))
    $contractor_nid = $params['contractor_nid'];
  else {
    $contractor_nid = 0; //init
    foreach ($billables as $billable) {
      $contractor_nid_new = $billable->contractor_nid;
      if (!$contractor_nid)
        $contractor_nid = $contractor_nid_new;
      else
        if ($contractor_nid <> $contractor_nid_new) {
          //BAD! There are different contractors in the billables. We cannot create an invoice with that information!       
         $status['status'] = 0;
          $status['errors'][] = t('There is no unique contractor for that invoice and the billable invoice lines have different contractors set.');
          return $status;
        }
    }
    
    if (!$contractor_nid) {
      //BAD! There is no customer detected in the billables!. We cannot create an invoice with that information!
      $status['status'] = 0;
      $status['errors'][] = t('There is no unique contractor for that invoice found in the billable line items.');
      return $status;
    }
  }

  //as we tried to get a customer, we try to get a currency for that invoice. It must be equal in all billables!
  $currency = false;
  foreach ($billables as $billable) {
    $currency_new = $billable->currency;
    if (!$currency)
        $currency = $currency_new;
    else
      if ($currency <> $currency_new) {
        //BAD!! NO currency found but equal currencies in the billables! We cannot create an invoice with that information
        $status['status'] = 0;
        $status['errors'][] = t('There is no unique currency found in the billable invoice items.');
        return $status;
      }
  }

  //now create the invoice!
  //create the invoice with the  billables      
  $invoice = new stdClass();
  $invoice->status = 1; //published
  $invoice->type = 'erpal_invoice';  
   
  $invoice->uid = $user->uid;
  $invoice->language = LANGUAGE_NONE;
  //set some other invoice specific fields

  //set order numbers
  $invoice->field_order_number_intern[LANGUAGE_NONE][0]['value'] = isset($params['order_numbers_intern']) ? $params['order_numbers_intern'] : '';
  $invoice->field_order_number_extern[LANGUAGE_NONE][0]['value'] = isset($params['order_numbers_extern']) ? $params['order_numbers_extern'] : '';
  
  //set date and credit information
  $invoice->field_invoice_date[LANGUAGE_NONE][0]['value'] = isset($params['invoice_date']) ? $params['invoice_date'] : time();  //the current date
  $invoice->field_credit_period[LANGUAGE_NONE][0]['value'] = isset($params['credit_period']) ? $params['credit_period'] : 14;

  $invoice->field_currency[LANGUAGE_NONE][0]['value'] = $currency;
  
  //add customer
  $invoice->field_customer_ref[LANGUAGE_NONE][0]['target_id'] = $customer_nid;
  
  //add contractor
  $invoice->field_contractor_ref[LANGUAGE_NONE][0]['target_id'] = $contractor_nid;
  
  //if there are notes, set the notes
  $invoice->field_note[LANGUAGE_NONE][0]['value'] = isset($params['notes']) ? $params['notes'] : '';

  //add address_id
  $invoice->field_invoice_address_id[LANGUAGE_NONE][0]['value'] = $params['address_id'];
  
  if (isset($params['invoice_number'])) {
    $invoice->field_invoice_number[LANGUAGE_NONE][0]['value'] = $params['invoice_number'];
  }
  
  //add skonto information from params if set!
  if (isset($params['skonto'])) {
    $credit_period = isset($params['skonto']['credit_period']) ? $params['skonto']['credit_period'] : 0;
    $discount_percent = isset($params['skonto']['discount_percent']) ? $params['skonto']['discount_percent'] : 0;
    
    if (!$credit_period)
      $credit_period = 0;
    if (!$discount_percent)
      $discount_percent = 0;
    
    //create an skonto fieldset collection
    $values = array();
    $values['field_name'] = 'field_skonto';      

    //save the entity to link it to the host with its id, otherwise we dont have an id      
    $skonto_collection = entity_create('field_collection_item', $values);    
    
    //set field values of field collection
    $skonto_collection->field_credit_period[LANGUAGE_NONE][0]['value'] = $credit_period;
    $skonto_collection->field_discount_percent[LANGUAGE_NONE][0]['value'] = $discount_percent;
    
    $skonto_collection->setHostEntity('node', $invoice, LANGUAGE_NONE, TRUE); //last param: true= link node to host      
    $skonto_collection->save(true);  //save the entity AND skip saving the host, it will be saved later!
    
  }
  
  //add billables
  foreach ($billable_ids as $billable_id) {
    $invoice->field_billables_ref[LANGUAGE_NONE][]['target_id'] = $billable_id;
  }
  
  node_object_prepare($invoice); 
  node_save($invoice);
  
  $status['invoice'] = $invoice;
  
  return $status;
}

/**
* function sets all billable, the current invoce references, unbilled
*/
function _erpal_invoice_helper_ungroup_billables($billables_id_arr) {
  foreach($billables_id_arr as $delta=>$billable_id) {
    $billable = billable_load($billable_id);
    module_load_include('inc', 'billable', 'billable.reduce');
    _billable_ungroup($billable, true);  //after that the billable is delete and doesn't exist any more
  }
}

/**
* Ungroups all billables in the given array
*/
function _erpal_invoice_helper_unbill_billables($billables_id_arr) {
  foreach($billables_id_arr as $delta=>$billable_id) {
    $billable = billable_load($billable_id);
    $billable->set_billed(false);
    $billable->save();
  }
}


