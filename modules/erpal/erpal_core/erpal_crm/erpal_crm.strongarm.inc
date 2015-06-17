<?php
/**
 * @file
 * erpal_crm.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_crm_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_crm_activity';
  $strongarm->value = '0';
  $export['ant_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_crm_activity';
  $strongarm->value = '';
  $export['ant_pattern_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_crm_activity';
  $strongarm->value = 0;
  $export['ant_php_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_crm_activity';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_crm_activity';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_crm_activity';
  $strongarm->value = '300';
  $export['comment_default_per_page_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_crm_activity';
  $strongarm->value = '2';
  $export['comment_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_crm_activity';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_crm_activity';
  $strongarm->value = '1';
  $export['comment_preview_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_crm_activity';
  $strongarm->value = 0;
  $export['comment_subject_field_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_comment__comment_node_erpal_crm_activity';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'comment_alter_field_activity_status_term' => array(
          'weight' => '3',
        ),
        'comment_alter_field_asset_files' => array(
          'weight' => '6',
        ),
        'comment_alter_field_chance' => array(
          'weight' => '7',
        ),
        'comment_alter_field_contacts_ref' => array(
          'weight' => '3',
        ),
        'comment_alter_field_expected_date' => array(
          'weight' => '9',
        ),
        'comment_alter_field_next_contact' => array(
          'weight' => '2',
        ),
        'comment_alter_field_volume' => array(
          'weight' => '6',
        ),
        'comment_alter_field_activity_lost_reasons' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_comment__comment_node_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_crm_activity';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'node_view' => array(
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'in_node_view' => array(
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
        'path' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_erpal_crm_activity';
  $strongarm->value = '0';
  $export['language_content_type_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_crm_activity';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_crm_activity';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_crm_activity';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_crm_activity';
  $strongarm->value = '1';
  $export['node_preview_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_crm_activity';
  $strongarm->value = 0;
  $export['node_submitted_erpal_crm_activity'] = $strongarm;

  return $export;
}
