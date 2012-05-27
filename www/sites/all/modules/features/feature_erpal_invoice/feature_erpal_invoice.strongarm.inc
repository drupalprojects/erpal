<?php
/**
 * @file
 * feature_erpal_invoice.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_erpal_invoice_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_invoice';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_invoice';
  $strongarm->value = '1';
  $export['ant_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_invoice';
  $strongarm->value = '[node:field_invoice_number] - [node:field-customer-ref:title] - [node:field-invoice-date:short]';
  $export['ant_pattern_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_invoice';
  $strongarm->value = 0;
  $export['ant_php_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'billable_customer_type';
  $strongarm->value = 'erpal_contact';
  $export['billable_customer_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_invoice';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_invoice';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_invoice';
  $strongarm->value = '50';
  $export['comment_default_per_page_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_invoice';
  $strongarm->value = '2';
  $export['comment_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_invoice';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_invoice';
  $strongarm->value = '1';
  $export['comment_preview_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_invoice';
  $strongarm->value = 1;
  $export['comment_subject_field_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_invoice';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_invoice';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_invoice';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_invoice';
  $strongarm->value = '1';
  $export['node_preview_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_invoice';
  $strongarm->value = 1;
  $export['node_submitted_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_erpal_invoice';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_erpal_invoice'] = $strongarm;

  return $export;
}
