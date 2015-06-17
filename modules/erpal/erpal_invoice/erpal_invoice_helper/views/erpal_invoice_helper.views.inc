<?php

/**
 * @file
 * Adds custom handler for views filter for all entityreference fields that have
 * 'erpal_contact' in target bundles
 */

/**
 * Implements hook_views_data_alter().
 */
function erpal_invoice_helper_views_data_alter(&$data) {
  // Assign custom handler class
  $handler = 'erpal_basic_helper_own_company_filter_handler';
  $data['billable']['customer_nid']['filter']['handler'] = $handler;
  $data['billable']['contractor_nid']['filter']['handler'] = $handler;
  
}
