<?php


/**
 * Implements hook_token_info().
 */
function erpal_invoice_helper_token_info() {
  $types['erpal_invoice'] = array(
    'name' => t("Erpal invoice token"),
    'description' => t("Tokens for invoice notes."),
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
  
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_invoice' => $invoice,
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
          $replacements[$original] = date('Y-m-d', $invoice->field_invoice_date[LANGUAGE_NONE][0]['value']); //@todo use drupal date_format with a date format without time!
        break;
        case 'payment_date':
          $replacements[$original] = date('Y-m-d', $invoice->field_payment_date[LANGUAGE_NONE][0]['value']); //@todo use drupal date_format with a date format without time!
        break;
        case 'currency':
          $replacements[$original] = $invoice->field_currency[LANGUAGE_NONE][0]['value'];
        break;
      }
    }
  }

  return $replacements;
}
