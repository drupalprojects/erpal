<?php
/**
 * @file
 * erpal_crm_reports.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_crm_reports_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_customer_forecast';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_customer_forecast';
  $strongarm->value = '1';
  $export['ant_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_expense_forecast';
  $strongarm->value = '1';
  $export['ant_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_customer_forecast';
  $strongarm->value = 'Customer Forcast for [node:field_contact_ref]';
  $export['ant_pattern_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_customer_forecast';
  $strongarm->value = 0;
  $export['ant_php_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_all_checked_fields_need_to_be_unique_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_all_checked_fields_need_to_be_unique_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_all_checked_fields_need_to_be_unique_erpal_customer_forecast_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_all_checked_fields_need_to_be_unique_erpal_customer_forecast_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_all_checked_fields_need_to_be_unique__erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_all_checked_fields_need_to_be_unique__erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_import_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_check_on_import_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_import_erpal_customer_forecast_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_check_on_import_erpal_customer_forecast_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_import__erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_check_on_import__erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_update_erpal_customer_forecast';
  $strongarm->value = 0;
  $export['bs_uniquenode_check_on_update_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_update_erpal_customer_forecast_erpal_customer_forecast';
  $strongarm->value = 0;
  $export['bs_uniquenode_check_on_update_erpal_customer_forecast_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_check_on_update__erpal_customer_forecast';
  $strongarm->value = 0;
  $export['bs_uniquenode_check_on_update__erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_compare_method_contact_ref';
  $strongarm->value = '1';
  $export['bs_uniquenode_compare_method_contact_ref'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_custom_message_on_equal_erpal_customer_forecast_erpal_customer_forecast';
  $strongarm->value = '';
  $export['bs_uniquenode_custom_message_on_equal_erpal_customer_forecast_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_must_be_unique_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_must_be_unique_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_must_be_unique_erpal_customer_forecast_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_must_be_unique_erpal_customer_forecast_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bs_uniquenode_must_be_unique__erpal_customer_forecast';
  $strongarm->value = 1;
  $export['bs_uniquenode_must_be_unique__erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_customer_forecast';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_expense_forecast';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_expense_forecast';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_customer_forecast';
  $strongarm->value = '50';
  $export['comment_default_per_page_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_expense_forecast';
  $strongarm->value = '50';
  $export['comment_default_per_page_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_customer_forecast';
  $strongarm->value = '2';
  $export['comment_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_expense_forecast';
  $strongarm->value = '2';
  $export['comment_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_expense_forecast';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_customer_forecast';
  $strongarm->value = '1';
  $export['comment_preview_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_expense_forecast';
  $strongarm->value = '1';
  $export['comment_preview_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['comment_subject_field_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_expense_forecast';
  $strongarm->value = 1;
  $export['comment_subject_field_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_erpal_customer_forecast';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_field_collection_item__field_forecast_elements';
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
  $export['field_bundle_settings_field_collection_item__field_forecast_elements'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_customer_forecast';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
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
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
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
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_expense_forecast';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_erpal_customer_forecast';
  $strongarm->value = '0';
  $export['language_content_type_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_erpal_expense_forecast';
  $strongarm->value = '0';
  $export['language_content_type_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_customer_forecast';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_expense_forecast';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_customer_forecast';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_expense_forecast';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_customer_forecast';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_expense_forecast';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_customer_forecast';
  $strongarm->value = '1';
  $export['node_preview_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_expense_forecast';
  $strongarm->value = '1';
  $export['node_preview_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_customer_forecast';
  $strongarm->value = 1;
  $export['node_submitted_erpal_customer_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_expense_forecast';
  $strongarm->value = 1;
  $export['node_submitted_erpal_expense_forecast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_erpal_customer_forecast';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_erpal_customer_forecast'] = $strongarm;

  return $export;
}
