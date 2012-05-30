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
  $strongarm->name = 'enable_revisions_page_erpal_invoice';
  $strongarm->value = 1;
  $export['enable_revisions_page_erpal_invoice'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_invoice';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '16',
        ),
        'additional_settings' => array(
          'weight' => '45',
        ),
        'revision_information' => array(
          'weight' => '35',
        ),
        'revision' => array(
          'weight' => '22',
        ),
        'log' => array(
          'weight' => '28',
        ),
        'author' => array(
          'weight' => '43',
        ),
        'name' => array(
          'weight' => '18',
        ),
        'date' => array(
          'weight' => '24',
        ),
        'options' => array(
          'weight' => '44',
        ),
        'status' => array(
          'weight' => '13',
        ),
        'promote' => array(
          'weight' => '25',
        ),
        'sticky' => array(
          'weight' => '29',
        ),
        'actions' => array(
          'weight' => '46',
        ),
        'submit' => array(
          'weight' => '14',
        ),
        'preview' => array(
          'weight' => '33',
        ),
        'delete' => array(
          'weight' => '15',
        ),
        'token_tree' => array(
          'weight' => '0',
        ),
        'comment_settings' => array(
          'weight' => '37',
        ),
        'comment' => array(
          'weight' => '21',
        ),
        'order_numbers_token_tree' => array(
          'weight' => '32',
        ),
        'menu' => array(
          'weight' => '17',
        ),
        'enabled' => array(
          'weight' => '23',
        ),
        'link' => array(
          'weight' => '26',
        ),
        'link_title' => array(
          'weight' => '19',
        ),
        'description' => array(
          'weight' => '27',
        ),
        'parent' => array(
          'weight' => '30',
        ),
        'weight' => array(
          'weight' => '31',
        ),
        'path' => array(
          'weight' => '36',
        ),
        'alias' => array(
          'weight' => '20',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_invoice'] = $strongarm;

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

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_erpal_invoice';
  $strongarm->value = 1;
  $export['show_preview_changes_erpal_invoice'] = $strongarm;

  return $export;
}
