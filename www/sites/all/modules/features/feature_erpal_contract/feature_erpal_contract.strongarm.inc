<?php
/**
 * @file
 * feature_erpal_contract.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_erpal_contract_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_contract';
  $strongarm->value = 'edit-comment';
  $export['additional_settings__active_tab_erpal_contract'] = $strongarm;

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
  $strongarm->value = '50';
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
  $strongarm->name = 'enable_revisions_page_erpal_contract';
  $strongarm->value = 1;
  $export['enable_revisions_page_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_contract_payment';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_contract_payment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_contract';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'additional_settings' => array(
          'weight' => '31',
        ),
        'revision_information' => array(
          'weight' => '27',
        ),
        'revision' => array(
          'weight' => '12',
        ),
        'log' => array(
          'weight' => '22',
        ),
        'author' => array(
          'weight' => '30',
        ),
        'name' => array(
          'weight' => '11',
        ),
        'date' => array(
          'weight' => '18',
        ),
        'options' => array(
          'weight' => '8',
        ),
        'status' => array(
          'weight' => '15',
        ),
        'promote' => array(
          'weight' => '21',
        ),
        'sticky' => array(
          'weight' => '23',
        ),
        'actions' => array(
          'weight' => '32',
        ),
        'submit' => array(
          'weight' => '9',
        ),
        'preview' => array(
          'weight' => '26',
        ),
        'comment_settings' => array(
          'weight' => '28',
        ),
        'comment' => array(
          'weight' => '13',
        ),
        'menu' => array(
          'weight' => '10',
        ),
        'enabled' => array(
          'weight' => '14',
        ),
        'link' => array(
          'weight' => '19',
        ),
        'link_title' => array(
          'weight' => '17',
        ),
        'description' => array(
          'weight' => '20',
        ),
        'parent' => array(
          'weight' => '24',
        ),
        'weight' => array(
          'weight' => '25',
        ),
        'path' => array(
          'weight' => '29',
        ),
        'alias' => array(
          'weight' => '16',
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
    1 => 'promote',
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

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_erpal_contract';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_erpal_contract';
  $strongarm->value = 0;
  $export['show_diff_inline_erpal_contract'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_erpal_contract';
  $strongarm->value = 1;
  $export['show_preview_changes_erpal_contract'] = $strongarm;

  return $export;
}
