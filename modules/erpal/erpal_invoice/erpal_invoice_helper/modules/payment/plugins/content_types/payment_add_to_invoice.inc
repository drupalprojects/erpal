<?php

/**
 * @file
 * With content type "Payment add to invoice form".
 *
 * Shows all invoices and payments.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  "title"           => t('Payment add to invoice form.'),
  "description"     => t('Shows a Payment add to invoice form'),
  "render callback" => "payment_add_to_invoice_render",
  "defaults"        => array(),
  "category"        => t('ERPAL Payment'),
);


/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context - in this case we don't have any.
 *
 * @return
 *   An object with at least title and content.
 */
function payment_add_to_invoice_render($subtype, $conf, $args, $context) {
  
  $query = drupal_get_query_parameters();
  $query['invoices'] = !empty($query['invoices']) ? $query['invoices']: array();
  $query['payment'] = !empty($query['payment']) ? $query['payment']: array();

  $block          = new stdClass();
  $block->title   = t('Add Payment to invoices');
  $block->content = drupal_get_form('payment_add_invoices_form', $query['invoices'], $query['payment']);
  
  return $block;
}
