<?php

/**
* @file calculates fields like total, payment date etc. if an invoice is inserted or updated
*/


/**
* @param $invoice the invoice node the fields are calculated at
*/
function _erpal_invoice_helper_calculate_fields($invoice) {

  _erpal_invoice_helper_calculate_payment_date($invoice);
  _erpal_invoice_helper_calculate_prices($invoice);  //@todo muss das in hook update oder insert?
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

  //@todo pr�fen ob hier evtl rechenfehler z.B. durch Rundung entstehen
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
      $invoice->is_new = false; //otherwise the node will be added to the database again which leads to an duolicate entry in node table
      node_save($invoice); //manuelly save the host node
      //already be a vat_rate_collection entity which leads to the next section of this if condition.
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