<?php


/**
 * Implements hook_token_info().
 */
function erpal_invoice_helper_token_info() {
  $types['erpal_invoice'] = array(
    'name' => t("Erpal invoice token"),
    'description' => t("Tokens for invoice notes."),
  );
  
  $types['erpal_invoice_referenced_data'] = array(
    'name' => t("Erpal invoice CRM data"),
    'description' => t("Tokens for invoice from crm activities."),
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
  
  //if module erpal project basic is active, add tokens for 
  if (module_exists('feature_erpal_project_basic')) {
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
  
  $date_form_date = _erpal_basic_helper_date_format_date_only();
  if ($type == 'erpal_invoice') {
    $invoice = $data['erpal_invoice'];
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'credit_period':
          $replacements[$original] = $invoice->field_credit_period[LANGUAGE_NONE][0]['value'];
        break;
        case 'total':
          $replacements[$original] = $invoice->field_invoice_total[LANGUAGE_NONE][0]['value'];
        break;
        case 'invoice_date':
          $replacements[$original] = date($date_form_date, $invoice->field_invoice_date[LANGUAGE_NONE][0]['value']);
        break;
        case 'payment_date':
          $replacements[$original] = date($date_form_date, $invoice->field_payment_date[LANGUAGE_NONE][0]['value']);
        break;
        case 'currency':
          $replacements[$original] = $invoice->field_currency[LANGUAGE_NONE][0]['value'];
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
  }

  return $replacements;
}
