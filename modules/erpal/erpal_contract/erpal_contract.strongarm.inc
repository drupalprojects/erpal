<?php
/**
 * @file
 * erpal_contract.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_contract_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_contract';
  $strongarm->value = '0';
  $export['ant_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_contract';
  $strongarm->value = '';
  $export['ant_pattern_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_contract';
  $strongarm->value = 0;
  $export['ant_php_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_contract';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_contract';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_contract';
  $strongarm->value = '300';
  $export['comment_default_per_page_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_contract';
  $strongarm->value = '2';
  $export['comment_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_contract';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_contract';
  $strongarm->value = '1';
  $export['comment_preview_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_contract';
  $strongarm->value = 0;
  $export['comment_subject_field_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_contract';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'node_view' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'minimal' => array(
        'custom_settings' => FALSE,
      ),
      'in_activity' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'additional_settings' => array(
          'weight' => '32',
        ),
        'revision_information' => array(
          'weight' => '28',
        ),
        'revision' => array(
          'weight' => '14',
        ),
        'log' => array(
          'weight' => '23',
        ),
        'author' => array(
          'weight' => '31',
        ),
        'name' => array(
          'weight' => '12',
        ),
        'date' => array(
          'weight' => '19',
        ),
        'options' => array(
          'weight' => '13',
        ),
        'status' => array(
          'weight' => '9',
        ),
        'promote' => array(
          'weight' => '22',
        ),
        'sticky' => array(
          'weight' => '24',
        ),
        'actions' => array(
          'weight' => '33',
        ),
        'submit' => array(
          'weight' => '10',
        ),
        'preview' => array(
          'weight' => '27',
        ),
        'comment_settings' => array(
          'weight' => '29',
        ),
        'comment' => array(
          'weight' => '15',
        ),
        'menu' => array(
          'weight' => '11',
        ),
        'enabled' => array(
          'weight' => '16',
        ),
        'link' => array(
          'weight' => '20',
        ),
        'link_title' => array(
          'weight' => '18',
        ),
        'description' => array(
          'weight' => '21',
        ),
        'parent' => array(
          'weight' => '25',
        ),
        'weight' => array(
          'weight' => '26',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'alias' => array(
          'weight' => '17',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_contract';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_contract';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_contract';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_contract';
  $strongarm->value = '1';
  $export['node_preview_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_contract';
  $strongarm->value = 1;
  $export['node_submitted_erpal_contract'] = $strongarm;

  return $export;
}
