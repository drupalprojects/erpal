<?php

/**
* @file calculates fields like total, payment date etc. if an invoice is inserted or updated
*/


/**
* @param $invoice the invoice node the fields are calculated at
*/
function _erpal_invoice_helper_calculate_fields($invoice) {

  //first of alle all fields that are directly attached to the 
  //invoice node (no field collection and other entity refernces)  
  _erpal_invoice_helper_calculate_payment_date($invoice);
  
  //now the caclulations using entity references and field collections
  _erpal_invoice_helper_calculate_prices($invoice);
  _erpal_invoice_helper_set_billables_billed($invoice);  
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

  //go throug each line item and pick the vat
  $line_items = $invoice->field_billables_ref[LANGUAGE_NONE];
  $vat_rates = array();
  $total_vat = 0;
  $total_excl_vat = 0;
  $total_incl_vat = 0;

  //@todo prüfen ob hier evtl rechenfehler z.B. durch Rundung entstehen und in tests aufnehmen
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
  }
  
  //first add the single values to the invoice
  $invoice->field_price_no_vat[LANGUAGE_NONE][0]['value'] = $total_excl_vat;
  $invoice->field_invoice_total[LANGUAGE_NONE][0]['value'] = $total_incl_vat;
  
  //now we have to add an entity for vat field collection for each vat rate we have found
  //in our line items
  $delta = 0;

  foreach ($vat_rates as $vat_rate=>$vat) {
    $vat_rate_collection = false;
    if (isset($invoice->field_invoice_vat[LANGUAGE_NONE][$delta])) {
      //if there is already an entitiy, load it and re-caclulate its values
      $id = $invoice->field_invoice_vat[LANGUAGE_NONE][$delta];
      $id = $id['value'];
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
      
      $vat_rate_collection->save(true);  //save the entity AND save the host againg, so next save step there will      
      $invoice->is_new = false; //otherwise the node will be added to the database again which leads to an duplicate entry in node table
      node_save($invoice); //manuelly save the host node
      //already has a vat_rate_collection entity which leads to the next section of this if condition.
    } else    
    if (is_object($vat_rate_collection)) {
      //add values here, too because we manipulate an existing entity
      $vat_rate_collection->field_vat_rate[LANGUAGE_NONE][0]['value'] = $vat_rate;
      $vat_rate_collection->field_vat_total[LANGUAGE_NONE][0]['value'] = $vat;

      //no set host entity needed cause the collection entity is already attached to the node
      $vat_rate_collection->save(true); //last param skipps host save, because this will result in an endless loop!
    }
    
    $delta++;
  }
  
  $lastDelta = $delta-1;
  //delete all vat entities that have delta index bigger than the last $delta value
  foreach ($invoice->field_invoice_vat[LANGUAGE_NONE] as $delta=>$entity) {
    if ($delta > $lastDelta) {
      //delete and unset this entity, it is not needed here
      $entity_id = $entity['value'];
      entity_delete('field_collection_item', $entity_id);
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
* Function that creates the invoice note, wit automatically generated notes (e.g. from vat settings)
* or from hook_invoice_notes by other moduls.
*/
function _erpal_invoice_helper_set_notes($invoice) {
  $notes = array();
  
  $manual_notes = _erpal_invoice_helper_get_manuall_notes();
  if ($manual_notes)
    $notes[] = array('weight' => 1, 'note' => $manual_notes);
    
  //now make them alterable by other modules
  $notes = module_invoke_all('invoice_notes_alter', $invoice, $notes);
  
  //order according to weight, an create the plain text that will be added to the invoice
  $ordered_notes = array();
  foreach ($notes as $note_arr) {
    $weight = $note_arr['weight'];
    $note = $note_arr['note'];
    $ordered_notes[$weight] = $note;
  }
  
  ksort($ordered_notes);
  
  $notes_string = implode("\r\n", $ordered_notes);

  $invoice->field_note[LANGUAGE_NONE][0]['value'] = $notes_string;

}

/**
* Implements hook_invoice_notes_alter
* @param $invoice the invoice we create the notes for
* @param $notes this array we add an array with key 'weight' and 'note' for each note line.
*/
function erpal_invoice_helper_invoice_notes_alter($invoice, $notes) {
  //check if there is one vat rate that has a message, add the message to notes
  $invoice_vat = $invoice->field_invoice_vat[LANGUAGE_NONE];
  
  $vat_rates = _erpal_invoice_helper_vat_rates_arr(true); //add notes to the labels
  foreach ($invoice_vat as $delta=>$vat_arr) {
    $id = $vat_arr['value'];
    $vat_rate_collection = entity_load('field_collection_item', array($id));
    $vat_rate_collection = $vat_rate_collection[$id];
    $vat_rate = $vat_rate_collection->field_vat_rate[LANGUAGE_NONE][0]['value'];
    
    if (isset($vat_rates[$vat_rate])) {
      if (isset($vat_rates[$vat_rate]['note']) && $vat_rates[$vat_rate]['note']) {
        $notes[] = array(
          'weight' => 2,  //@todo which value to preset here?
          'note' => $vat_rates[$vat_rate]['note'],
        );
      }
    }
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
  
  if ($reduced)
  {
    //reduce all billables given and then create the bill with the reduced entities
    //Load files from the billable module
    module_load_include('inc', 'billable', 'billable.reduce');
    $group_by = array();
    if (isset($params['group_by']))
      $group_by = $params['group_by']; //may be there is the single_price field to group the billables by.
    
    $billables = _billable_reduce($billable_ids, $group_by, true);
    $billable_ids = array_keys($billables);
  }
  
  //load all billables for the test!
  $billables = billable_load_multiple($billable_ids);

  //try to get the customer, if there is no customer in params, the customer of all billables must be equal otherwise there will
  //be an error
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
  $invoice->type = 'erpal_invoice';
  node_object_prepare($invoice);
  
  $invoice->language = LANGUAGE_NONE;
  //set some other invoice specific fields

  //set date and credit information
  $invoice->field_invoice_date[LANGUAGE_NONE][0]['value'] = isset($params['invoice_date']) ? $params['invoice_date'] : time();  //the current date
  $invoice->field_credit_period[LANGUAGE_NONE][0]['value'] = isset($params['credit_period']) ? $params['credit_period'] : 14;
  $invoice->field_currency[LANGUAGE_NONE][0]['value'] = $currency;
  
  //add customer
  $invoice->field_customer_ref[LANGUAGE_NONE][0]['nid'] = $customer_nid;
  
  //add skonto information from params if set!
  if (isset($params['skonto'])) {
    $credit_period = $params['skonto']['credit_period'];
    $discount_percent = $params['skonto']['discount_percent'];
    
    //create an skonto fieldset collection
    $values = array();
    $values['field_name'] = 'field_skonto';      
    $values['field_credit_period'][LANGUAGE_NONE][0]['value'] = $credit_period;   
    $values['field_discount_percent'][LANGUAGE_NONE][0]['value'] = $discount_percent;   
    
    //save the entity to link it to the host with its id, otherwise we dont have an id      
    $skonto_collection = entity_create('field_collection_item', $values);    
    $skonto_collection->setHostEntity('node', $invoice, LANGUAGE_NONE, TRUE); //last param: true= link node to host      
    $skonto_collection->save(true);  //save the entity AND skip saving the host, it will be saved later!
  }
  
  //add billables
  foreach ($billable_ids as $billable_id) {
    $invoice->field_billables_ref[LANGUAGE_NONE][]['target_id'] = $billable_id;
  }
 
  node_save($invoice);
  
  $status['invoice'] = $invoice;
  
  return $status;
}

