<?php


/**
 * Implements hook_token_info().
 */
function erpal_invoice_helper_token_info() {
  $types['erpal_invoice'] = array(
    'name' => t("Erpal invoice token"),
    'description' => t("Tokens for invoice notes."),
    'needs-data' => 'erpal_invoice',
  );
  
  $types['erpal_invoice_skonto'] = array(
    'name' => t("Erpal invoice skonto token"),
    'description' => t("Tokens for invoice skonto tokens."),
    'needs-data' => 'erpal_invoice',
  );
  
  $types['erpal_invoice_referenced_data'] = array(
    'name' => t("Erpal invoice CRM data"),
    'description' => t("Tokens for invoice from crm activities."),
    'needs-data' => 'erpal_invoice_referenced_data',
  );

  $invoice['total'] = array(
    'name' => t("Total price"),
    'description' => t("The total price of the invoice."),
  );
  $invoice['credit_period'] = array(
    'name' => t("Credit period"),
    'description' => t("The credit period in days for the invoice."),
  );
  $invoice['invoice_date'] = array(
    'name' => t("The invoice date"),
    'description' => t("The date of the invoice."),
  );
  $invoice['payment_date'] = array(
    'name' => t("The payment date"),
    'description' => t("The date of the invoice whenit has to be payed."),
  );
  $invoice['currency'] = array(
    'name' => t("The currency"),
    'description' => t("The currency of the invoice."),
  );
  $invoice['next_invoice_number'] = array(
    'name' => t("Next invoice number"),
    'description' => t("The next invoice number in the system."),
  );
  
  //skonto
  $invoice_skonto['skonto_period'] = array(
    'name' => t("The skonto period"),
    'description' => t("This is the skonto period in days."),
  );
  $invoice_skonto['skonto_rate'] = array(
    'name' => t("Skonto rate"),
    'description' => t("The skonto rate in percent."),
  );
  
  
  //if module erpal project basic is active, add tokens for 
  $referenced_data = false;
  if (module_exists('erpal_project') || module_exists('erpal_contract')) {
    $referenced_data['order_numbers_intern'] = array(
      'name' => t("Internal order numbers"),
      'description' => t("Your internal numbers of orders related to the invoice items"),
    );
    $referenced_data['order_numbers_extern'] = array(
      'name' => t("External order numbers"),
      'description' => t("Your external numbers of orders related to the invoice items"),
    );
  }
  
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_invoice' => $invoice,
      'erpal_invoice_skonto' => $invoice_skonto,
      'erpal_invoice_referenced_data' => $referenced_data,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function erpal_invoice_helper_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;  
  
  $replacements = array();
  if ($type == 'erpal_invoice') {
    $invoice = isset($data['erpal_invoice']) ? $data['erpal_invoice'] : false;
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'credit_period':
          $replacements[$original] = $invoice->field_credit_period[LANGUAGE_NONE][0]['value'];
        break;
        case 'total':
          $replacements[$original] = number_format($invoice->field_invoice_total[LANGUAGE_NONE][0]['value'], 2, ',', '.');
        break;
        case 'invoice_date':
          $replacements[$original] = erpal_date_formatted($invoice->field_invoice_date[LANGUAGE_NONE][0]['value']);
        break;
        case 'payment_date':
          $replacements[$original] = erpal_date_formatted($invoice->field_payment_date[LANGUAGE_NONE][0]['value']);
        break;
        case 'currency':
          $replacements[$original] = $invoice->field_currency[LANGUAGE_NONE][0]['value'];
        break;
        case 'next_invoice_number':
          $invoice_number = isset($data['invoice_number']) && $data['invoice_number'] ? $data['invoice_number'] : _erpal_invoice_helper_get_next_invoice_number();
          $replacements[$original] = $invoice_number;
        break;
        
      }
    }
  } elseif ($type == 'erpal_invoice_referenced_data') {
    $invoice = $data['erpal_invoice_referenced_data'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'order_numbers_intern':
          $order_numbers = _erpal_invoice_helper_get_order_numbers($invoice);   
          $replacements[$original] = implode(',', $order_numbers['intern']);
          break;
        case 'order_numbers_extern':
          $order_numbers = _erpal_invoice_helper_get_order_numbers($invoice);            
          $replacements[$original] = implode(',', $order_numbers['extern']);        
          break;
      }
    }
  } elseif ($type == 'erpal_invoice_skonto') {
    $invoice = isset($data['erpal_invoice']) ? $data['erpal_invoice'] : false;
    if($invoice) {
      $skonto = _erpal_invoice_helper_get_skonto($invoice);
      foreach ($tokens as $name => $original) {
        switch ($name) {
          case 'skonto_period':
            $replacements[$original] = $skonto['period'];
          break;
          case 'skonto_rate':
            $replacements[$original] = $skonto['rate'];
          break;               
        }
      }
    }
  }

  return $replacements;
}
