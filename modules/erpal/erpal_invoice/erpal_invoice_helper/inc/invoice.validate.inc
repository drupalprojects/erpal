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
  
  $invoice_number_errors = _erpal_invoice_helper_invoice_validate_number($invoice);
  $errors = array_merge($errors, $invoice_number_errors);
  
  $contractor_errors = _erpal_invoice_helper_invoice_validate_customer_contractor($invoice);
  $errors = array_merge($errors, $contractor_errors);
  
  return $errors;
}

/**
* validates that cusotmer and contractor are not the same
*/
function _erpal_invoice_helper_invoice_validate_customer_contractor($invoice) {
  $customer_nid = 0;
  $contractor_nid = 0;
  $errors = array();
  
  if (isset($invoice->field_customer_ref[LANGUAGE_NONE][0]['target_id']))
    $customer_nid = $invoice->field_customer_ref[LANGUAGE_NONE][0]['target_id'];
    
  if (isset($invoice->field_contractor_ref[LANGUAGE_NONE][0]['target_id']))
    $contractor_nid = $invoice->field_contractor_ref[LANGUAGE_NONE][0]['target_id'];
    
  if ($contractor_nid && $customer_nid)
    if ($contractor_nid == $customer_nid)
  
  $errors['field_customer_ref]['.LANGUAGE_NONE.'][0][target_id'][] = t('Customer and contractor must not be the same');
  
  return $errors;  
}

/**
* Validates the invoice number
*/
function _erpal_invoice_helper_invoice_validate_number($invoice) {

  $errors = array();
  $number = $invoice->field_invoice_number[LANGUAGE_NONE][0]['value'];
  
  if (!$number)
    return $errors;
  
  $company_nid = _erpal_basic_helper_get_own_company_nid(false);
  //if no contractor is set, it is the own company!
  if (isset($invoice->field_contractor_ref[LANGUAGE_NONE][0]['target_id']))  
    $contractor = node_load($invoice->field_contractor_ref[LANGUAGE_NONE][0]['target_id']);
  else
    $contractor = node_load($company_nid);
  
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
    if ($billable->currency)
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
    
    //check that no delivery date of a billable is greater than the invoice date, but we don't use the values from the loaded billable but from the widget values
    $billable_form_values = $invoice->field_billables_ref_values[LANGUAGE_NONE][$i]['widget_values'];
    $date_delivery = $billable_form_values['date_delivery'];
    $invoice_date = isset($invoice->field_invoice_date[LANGUAGE_NONE][0]) ? $invoice->field_invoice_date[LANGUAGE_NONE][0]['value'] : false;

    /*
    if ($invoice_date && $date_delivery) {
      if (date('Ymd', $invoice_date) < date('Ymd', $date_delivery)) {
        $errors['field_billables_ref]['.LANGUAGE_NONE.']['.$j.'][target_id'][] = t('Delivery date of "%title" must be less than invoice date', array('%title' => $billable_form_values['subject']));
      }
    }
    */

  }
  
  if (count($currencies) > 1) {
    $currency_string = implode(',', $currencies);
    form_set_error('field_billables_ref', t('Your invoice items have multiple currencies: %currencies - Please make sure there is only one currency within all invoice items.', array('%currencies' => $currency_string)));
  } else {
    //the currency of the invoice must be empty or if not, it must be the same as the currency in the invoice line items
    $invoice_currency = $invoice->field_currency[LANGUAGE_NONE][0]['value'];
    $billables_currency = array_shift($currencies); //there should be only one currency here
    
    if ($billables_currency && $invoice_currency)
      if ($billables_currency != $invoice_currency)
        form_set_error('field_currency', t('The currency of the invoice (%invoice_currency) is different from the currency of the invoice items (%billables_currency).', array('%invoice_currency' => $invoice_currency, '%billables_currency' => $billables_currency)));
  }

  //check that the invoice has at least one billable
  $all_billables_removed = false;
  
  $billables = $invoice->field_billables_ref[LANGUAGE_NONE]; //copy billables for validation so we will not touch the original invoice node here.
  if (!empty($_POST['removed_billables'])) {
    foreach ($_POST['removed_billables'] as $delta=>$remove) {
      unset($billables[$delta]);
      
      //even unset the widget values!
      unset($invoice->field_billables_ref_values[LANGUAGE_NONE][$delta]);
    }
    
    //now remove the billables that have no values set
    $tmp_billables = $billables;
    foreach ($tmp_billables as $delta=>$billable) {
      
      if (!is_numeric($delta)) {
        unset($billables[$delta]);
        continue;
      }
      
      if (empty($billable['target_id'])) {
        unset($billables[$delta]);
      }
    }
 
  }

  $all_billables_removed = count($billables) <= 0;
  if ($all_billables_removed || empty($billables[0]['target_id'])) {
    //no referenced billable, are there some billable data submitted?    
    $no_billable = empty($invoice->field_billables_ref_values[LANGUAGE_NONE]);    
    if ($no_billable) {
      $errors['field_billables_ref'][] = t('Please add some invoice items (billables)');
    }
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
