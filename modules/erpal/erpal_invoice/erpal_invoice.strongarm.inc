<?php
/**
 * @file
 * erpal_invoice.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_invoice_strongarm() {
  $export = array();

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
  $strongarm->value = '300';
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
  $strongarm->name = 'field_bundle_settings_node__erpal_invoice';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '3',
        ),
        'additional_settings' => array(
          'weight' => '46',
        ),
        'revision_information' => array(
          'weight' => '37',
        ),
        'revision' => array(
          'weight' => '25',
        ),
        'log' => array(
          'weight' => '31',
        ),
        'author' => array(
          'weight' => '44',
        ),
        'name' => array(
          'weight' => '21',
        ),
        'date' => array(
          'weight' => '27',
        ),
        'options' => array(
          'weight' => '45',
        ),
        'status' => array(
          'weight' => '16',
        ),
        'promote' => array(
          'weight' => '28',
        ),
        'sticky' => array(
          'weight' => '32',
        ),
        'actions' => array(
          'weight' => '47',
        ),
        'submit' => array(
          'weight' => '17',
        ),
        'preview' => array(
          'weight' => '36',
        ),
        'delete' => array(
          'weight' => '18',
        ),
        'token_tree' => array(
          'weight' => '13',
        ),
        'comment_settings' => array(
          'weight' => '39',
        ),
        'comment' => array(
          'weight' => '24',
        ),
        'order_numbers_token_tree' => array(
          'weight' => '35',
        ),
        'menu' => array(
          'weight' => '20',
        ),
        'enabled' => array(
          'weight' => '26',
        ),
        'link' => array(
          'weight' => '29',
        ),
        'link_title' => array(
          'weight' => '22',
        ),
        'description' => array(
          'weight' => '30',
        ),
        'parent' => array(
          'weight' => '33',
        ),
        'weight' => array(
          'weight' => '34',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'alias' => array(
          'weight' => '23',
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

  return $export;
}
