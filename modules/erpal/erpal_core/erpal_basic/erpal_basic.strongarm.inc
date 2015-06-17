<?php
/**
 * @file
 * erpal_basic.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_basic_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_contact';
  $strongarm->value = '1';
  $export['ant_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_contact';
  $strongarm->value = '[erpal_contact:company_name] [erpal_contact:firstname] [erpal_contact:lastname]';
  $export['ant_pattern_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_contact';
  $strongarm->value = 0;
  $export['ant_php_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_all_checked_fields_need_to_be_unique_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_all_checked_fields_need_to_be_unique_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_all_checked_fields_need_to_be_unique_erpal_contact_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_all_checked_fields_need_to_be_unique_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_update_erpal_contact';
  $strongarm->value = 0;
  $export['bs_uniquenode_check_on_update_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_update_erpal_contact_erpal_contact';
  $strongarm->value = 0;
  $export['bs_uniquenode_check_on_update_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_compare_method_company_name';
  $strongarm->value = '2';
  $export['bs_uniquenode_compare_method_company_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_compare_method_firstname';
  $strongarm->value = '2';
  $export['bs_uniquenode_compare_method_firstname'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_compare_method_lastname';
  $strongarm->value = '2';
  $export['bs_uniquenode_compare_method_lastname'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_custom_message_on_equal_erpal_contact';
  $strongarm->value = 'This contact already exists.';
  $export['bs_uniquenode_custom_message_on_equal_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_custom_message_on_equal_erpal_contact_erpal_contact';
  $strongarm->value = 'This contact already exists.';
  $export['bs_uniquenode_custom_message_on_equal_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_must_be_unique_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_must_be_unique_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_must_be_unique_erpal_contact_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_must_be_unique_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_node_type_intern_company_name';
  $strongarm->value = 1;
  $export['bs_uniquenode_node_type_intern_company_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_node_type_intern_firstname';
  $strongarm->value = 1;
  $export['bs_uniquenode_node_type_intern_firstname'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_node_type_intern_lastname';
  $strongarm->value = 1;
  $export['bs_uniquenode_node_type_intern_lastname'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_phonem_search_if_equal_result_empty_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_phonem_search_if_equal_result_empty_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_phonem_search_if_equal_result_empty_erpal_contact_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_phonem_search_if_equal_result_empty_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_respect_userspace_erpal_contact';
  $strongarm->value = 0;
  $export['bs_uniquenode_respect_userspace_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_respect_userspace_erpal_contact_erpal_contact';
  $strongarm->value = 0;
  $export['bs_uniquenode_respect_userspace_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_search_equal_first_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_search_equal_first_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_search_equal_first_erpal_contact_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_search_equal_first_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_skip_emptyerpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_skip_emptyerpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_skip_emptyerpal_contact_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_skip_emptyerpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_title_check_erpal_contact';
  $strongarm->value = '0';
  $export['bs_uniquenode_title_check_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_title_check_erpal_contact_erpal_contact';
  $strongarm->value = '0';
  $export['bs_uniquenode_title_check_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_use_intersection_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_use_intersection_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_use_intersection_erpal_contact_erpal_contact';
  $strongarm->value = 1;
  $export['bs_uniquenode_use_intersection_erpal_contact_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_contact';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_contact';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_contact';
  $strongarm->value = '300';
  $export['comment_default_per_page_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_contact';
  $strongarm->value = '2';
  $export['comment_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_contact';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_contact';
  $strongarm->value = '1';
  $export['comment_preview_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_contact';
  $strongarm->value = 1;
  $export['comment_subject_field_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_addresses';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'in_pane' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_field_collection_item__field_addresses'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_contact';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
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
      'in_activity' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_view' => array(
        'custom_settings' => TRUE,
      ),
      'in_node_view' => array(
        'custom_settings' => FALSE,
      ),
      'minimal' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '12',
        ),
        'path' => array(
          'weight' => '13',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_relation__works_at';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'relation_with_endpoints' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_relation__works_at'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_erpal_contact';
  $strongarm->value = '0';
  $export['language_content_type_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_contact';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_contact';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_contact';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_contact';
  $strongarm->value = '0';
  $export['node_preview_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_contact';
  $strongarm->value = 0;
  $export['node_submitted_erpal_contact'] = $strongarm;

  return $export;
}
