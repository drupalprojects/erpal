<?php

/**
* Validates an invoice
* @return an array with key are field names of the fields that have an error and the value is
*   an array with the single errors of each field
*/
function _erpal_invoice_helper_invoice_validate($invoice) {
  $errors = array();
  
  //validate billables
  $billable_errors = _erpal_invoice_helper_invoice_validate_billables($invoice);
  $errors = array_merge($errors, $billable_errors);
  
  
  return $errors;
}

/**
* Validates billables attached to the invoice
*/
function _erpal_invoice_helper_invoice_validate_billables($invoice) {
  
  $errors = array();  
  $billables = $invoice->field_billables_ref[LANGUAGE_NONE];

  $currencies = array();
  
  //is this billable entity duplicate referenced by this invoice?
  for ($i = 0; $i < count($billables); $i++){
    if (!isset($billables[$i]))
      continue;
    if (!$billables[$i]['target_id'])
      continue;

    $billable = $billables[$i];
    $billable = billable_load($billable['target_id']);
    
    //this billable must not be referenced in another invoice!
    $invoices = _erpal_invoice_helper_get_invoices_by_billable($billable);
    if (count($invoices) > 1) {
      //display error with the invoices referncing this billable listed
      foreach ($invoices as $invoice_nid) {
        $invoice_node = node_load($invoice_nid);
        $invoice_title = $invoice_node->title;
        $billable_title = $billable->subject;
        
        
        if (!erpal_debug())
          $errors['field_billables_ref]['.LANGUAGE_NONE.']['.$i.'][target_id'][] = t('Billable %billable_subject already included in invoice %invoice_title', array('%billable_subject' => $billable_title, '%invoice_title' => $invoice_title));
      }
    }
    
    //add the curreny for later validation
    $currencies[$billable->currency] = $billable->currency;
    
    //start from the current item iteration down in the array searching for further duplicates    
    for ($j = $i+1; $j < count($billables); $j++) {
      if (!isset($billables[$j])) 
        continue;
      if (!$billables[$j]['target_id'])
        continue;
        
      $billable2 = $billables[$j];
      if ($billable2['target_id'] == $billable->billable_id) {
        //duplicate billable at this invoice!
        $errors['field_billables_ref]['.LANGUAGE_NONE.']['.$j.'][target_id'][] = t('Duplicate invoice item %title', array('%title' => $billable->subject));
      }
    }
  }
  
  if (count($currencies) > 1) {
    $currency_string = implode(',', $currencies);
    form_set_error('field_billables_ref', t('Your invoice items have multiple currencies: %currencies - Please make shure there is only one currency within all invoice items.', array('%currencies' => $currency_string)));
  } else {
    //the currency of the invoice must be empty or if not, it must be the same as the currency in the invoice line items
    $invoice_currency = $invoice->field_currency[LANGUAGE_NONE][0]['value'];
    $billables_currency = array_shift($currencies); //there should be only one currency here
    
    if ($billables_currency && $invoice_currency)
      if ($billables_currency != $invoice_currency)
        form_set_error('field_currency', t('The currency of the invoice (%invoice_currency) is different from the currency of the invoice items (%billables_currency).', array('%invoice_currency' => $invoice_currency, '%billables_currency' => $billables_currency)));
  }
 
  
  return $errors;
}

/**
* returns all invoices that contain the given billable
* @param a billable a billable entitiy object
* @return an array of nids of the referencing invoices
*/
function _erpal_invoice_helper_get_invoices_by_billable($billable) {

  $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'erpal_invoice')
        ->fieldCondition('field_billables_ref', 'target_id', $billable->billable_id);
        
  $records = $query->execute();

  $ret = array();
  foreach ($records as $type=>$type_records) {
    if (is_array($type_records)) {
      foreach ($type_records as $billable_min_obj) {
        $ret[] = $billable_min_obj->nid;
      }
    }
  }

  return $ret;
}
