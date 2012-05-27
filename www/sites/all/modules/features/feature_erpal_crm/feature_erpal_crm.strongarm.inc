<?php
/**
 * @file
 * feature_erpal_crm.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_erpal_crm_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_crm_activity';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_erpal_crm_activity'] = $strongarm;

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
  $strongarm->value = '50';
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
  $strongarm->value = 1;
  $export['comment_subject_field_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_crm_activity';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_crm_activity'] = $strongarm;

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
    1 => 'promote',
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
  $strongarm->value = 1;
  $export['node_submitted_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_erpal_crm_activity';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_erpal_crm_activity';
  $strongarm->value = 'each';
  $export['unique_field_comp_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_erpal_crm_activity';
  $strongarm->value = array();
  $export['unique_field_fields_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_erpal_crm_activity';
  $strongarm->value = 'type';
  $export['unique_field_scope_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_erpal_crm_activity';
  $strongarm->value = array();
  $export['unique_field_show_matches_erpal_crm_activity'] = $strongarm;

  return $export;
}
