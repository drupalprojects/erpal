<?php
/**
 * @file
 * feature_erpal_project_basic.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_erpal_project_basic_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_project';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_task';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_timetracking';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_project';
  $strongarm->value = '0';
  $export['ant_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_task';
  $strongarm->value = '0';
  $export['ant_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_erpal_timetracking';
  $strongarm->value = '0';
  $export['ant_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_project';
  $strongarm->value = '';
  $export['ant_pattern_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_task';
  $strongarm->value = '';
  $export['ant_pattern_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_erpal_timetracking';
  $strongarm->value = '';
  $export['ant_pattern_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_project';
  $strongarm->value = 0;
  $export['ant_php_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_task';
  $strongarm->value = 0;
  $export['ant_php_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_erpal_timetracking';
  $strongarm->value = 0;
  $export['ant_php_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_project';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_task';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_erpal_timetracking';
  $strongarm->value = 0;
  $export['comment_anonymous_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_project';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_task';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_erpal_timetracking';
  $strongarm->value = 1;
  $export['comment_default_mode_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_project';
  $strongarm->value = '50';
  $export['comment_default_per_page_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_task';
  $strongarm->value = '50';
  $export['comment_default_per_page_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_timetracking';
  $strongarm->value = '50';
  $export['comment_default_per_page_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_project';
  $strongarm->value = '2';
  $export['comment_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_task';
  $strongarm->value = '2';
  $export['comment_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_erpal_timetracking';
  $strongarm->value = '2';
  $export['comment_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_project';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_task';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_erpal_timetracking';
  $strongarm->value = 1;
  $export['comment_form_location_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_project';
  $strongarm->value = '1';
  $export['comment_preview_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_task';
  $strongarm->value = '1';
  $export['comment_preview_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_erpal_timetracking';
  $strongarm->value = '1';
  $export['comment_preview_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_project';
  $strongarm->value = 1;
  $export['comment_subject_field_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_task';
  $strongarm->value = 1;
  $export['comment_subject_field_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_erpal_timetracking';
  $strongarm->value = 1;
  $export['comment_subject_field_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_erpal_project';
  $strongarm->value = 1;
  $export['enable_revisions_page_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_erpal_task';
  $strongarm->value = 1;
  $export['enable_revisions_page_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_erpal_timetracking';
  $strongarm->value = 1;
  $export['enable_revisions_page_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_project';
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
      'test' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'additional_settings' => array(
          'weight' => '35',
        ),
        'revision_information' => array(
          'weight' => '30',
        ),
        'revision' => array(
          'weight' => '19',
        ),
        'log' => array(
          'weight' => '21',
        ),
        'author' => array(
          'weight' => '33',
        ),
        'name' => array(
          'weight' => '14',
        ),
        'date' => array(
          'weight' => '17',
        ),
        'options' => array(
          'weight' => '34',
        ),
        'status' => array(
          'weight' => '10',
        ),
        'promote' => array(
          'weight' => '22',
        ),
        'sticky' => array(
          'weight' => '26',
        ),
        'actions' => array(
          'weight' => '36',
        ),
        'submit' => array(
          'weight' => '11',
        ),
        'preview' => array(
          'weight' => '28',
        ),
        'delete' => array(
          'weight' => '12',
        ),
        'preview_changes' => array(
          'weight' => '29',
        ),
        'comment_settings' => array(
          'weight' => '32',
        ),
        'comment' => array(
          'weight' => '16',
        ),
        'menu' => array(
          'weight' => '13',
        ),
        'enabled' => array(
          'weight' => '15',
        ),
        'link' => array(
          'weight' => '24',
        ),
        'link_title' => array(
          'weight' => '20',
        ),
        'description' => array(
          'weight' => '23',
        ),
        'parent' => array(
          'weight' => '25',
        ),
        'weight' => array(
          'weight' => '27',
        ),
        'path' => array(
          'weight' => '31',
        ),
        'alias' => array(
          'weight' => '18',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_task';
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
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'additional_settings' => array(
          'weight' => '38',
        ),
        'revision_information' => array(
          'weight' => '34',
        ),
        'revision' => array(
          'weight' => '18',
        ),
        'log' => array(
          'weight' => '29',
        ),
        'author' => array(
          'weight' => '36',
        ),
        'name' => array(
          'weight' => '22',
        ),
        'date' => array(
          'weight' => '26',
        ),
        'options' => array(
          'weight' => '37',
        ),
        'status' => array(
          'weight' => '12',
        ),
        'promote' => array(
          'weight' => '28',
        ),
        'sticky' => array(
          'weight' => '30',
        ),
        'actions' => array(
          'weight' => '39',
        ),
        'submit' => array(
          'weight' => '13',
        ),
        'preview' => array(
          'weight' => '31',
        ),
        'delete' => array(
          'weight' => '14',
        ),
        'preview_changes' => array(
          'weight' => '32',
        ),
        'comment_settings' => array(
          'weight' => '15',
        ),
        'comment' => array(
          'weight' => '19',
        ),
        'menu' => array(
          'weight' => '21',
        ),
        'enabled' => array(
          'weight' => '24',
        ),
        'link' => array(
          'weight' => '27',
        ),
        'link_title' => array(
          'weight' => '23',
        ),
        'description' => array(
          'weight' => '16',
        ),
        'parent' => array(
          'weight' => '17',
        ),
        'weight' => array(
          'weight' => '20',
        ),
        'path' => array(
          'weight' => '35',
        ),
        'alias' => array(
          'weight' => '25',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_project';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_task';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_erpal_timetracking';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_project';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_task';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_erpal_timetracking';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_project';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_task';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_timetracking';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_project';
  $strongarm->value = '1';
  $export['node_preview_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_task';
  $strongarm->value = '1';
  $export['node_preview_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_erpal_timetracking';
  $strongarm->value = '1';
  $export['node_preview_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_project';
  $strongarm->value = 1;
  $export['node_submitted_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_task';
  $strongarm->value = 1;
  $export['node_submitted_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_erpal_timetracking';
  $strongarm->value = 1;
  $export['node_submitted_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_content_type_erpal_project';
  $strongarm->value = 'omitted';
  $export['og_group_content_type_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_group_type_erpal_task';
  $strongarm->value = 'omitted';
  $export['og_group_type_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_node_view_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_node_view_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_erpal_project';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_erpal_task';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_erpal_project';
  $strongarm->value = 0;
  $export['show_diff_inline_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_erpal_task';
  $strongarm->value = 0;
  $export['show_diff_inline_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_erpal_timetracking';
  $strongarm->value = 0;
  $export['show_diff_inline_erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_erpal_project';
  $strongarm->value = 1;
  $export['show_preview_changes_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_erpal_task';
  $strongarm->value = 1;
  $export['show_preview_changes_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_erpal_timetracking';
  $strongarm->value = 1;
  $export['show_preview_changes_erpal_timetracking'] = $strongarm;

  return $export;
}
