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
          'weight' => '39',
        ),
        'revision_information' => array(
          'weight' => '34',
        ),
        'revision' => array(
          'weight' => '23',
        ),
        'log' => array(
          'weight' => '25',
        ),
        'author' => array(
          'weight' => '37',
        ),
        'name' => array(
          'weight' => '18',
        ),
        'date' => array(
          'weight' => '21',
        ),
        'options' => array(
          'weight' => '38',
        ),
        'status' => array(
          'weight' => '12',
        ),
        'promote' => array(
          'weight' => '26',
        ),
        'sticky' => array(
          'weight' => '30',
        ),
        'actions' => array(
          'weight' => '40',
        ),
        'submit' => array(
          'weight' => '15',
        ),
        'preview' => array(
          'weight' => '32',
        ),
        'delete' => array(
          'weight' => '16',
        ),
        'preview_changes' => array(
          'weight' => '33',
        ),
        'comment_settings' => array(
          'weight' => '36',
        ),
        'comment' => array(
          'weight' => '20',
        ),
        'menu' => array(
          'weight' => '17',
        ),
        'enabled' => array(
          'weight' => '19',
        ),
        'link' => array(
          'weight' => '28',
        ),
        'link_title' => array(
          'weight' => '24',
        ),
        'description' => array(
          'weight' => '27',
        ),
        'parent' => array(
          'weight' => '29',
        ),
        'weight' => array(
          'weight' => '31',
        ),
        'path' => array(
          'weight' => '35',
        ),
        'alias' => array(
          'weight' => '22',
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
          'weight' => '43',
        ),
        'revision_information' => array(
          'weight' => '39',
        ),
        'revision' => array(
          'weight' => '23',
        ),
        'log' => array(
          'weight' => '34',
        ),
        'author' => array(
          'weight' => '41',
        ),
        'name' => array(
          'weight' => '27',
        ),
        'date' => array(
          'weight' => '31',
        ),
        'options' => array(
          'weight' => '42',
        ),
        'status' => array(
          'weight' => '15',
        ),
        'promote' => array(
          'weight' => '33',
        ),
        'sticky' => array(
          'weight' => '35',
        ),
        'actions' => array(
          'weight' => '44',
        ),
        'submit' => array(
          'weight' => '18',
        ),
        'preview' => array(
          'weight' => '36',
        ),
        'delete' => array(
          'weight' => '19',
        ),
        'preview_changes' => array(
          'weight' => '37',
        ),
        'comment_settings' => array(
          'weight' => '20',
        ),
        'comment' => array(
          'weight' => '24',
        ),
        'menu' => array(
          'weight' => '26',
        ),
        'enabled' => array(
          'weight' => '29',
        ),
        'link' => array(
          'weight' => '32',
        ),
        'link_title' => array(
          'weight' => '28',
        ),
        'description' => array(
          'weight' => '21',
        ),
        'parent' => array(
          'weight' => '22',
        ),
        'weight' => array(
          'weight' => '25',
        ),
        'path' => array(
          'weight' => '40',
        ),
        'alias' => array(
          'weight' => '30',
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
  $strongarm->name = 'pathauto_node_erpal_project_pattern';
  $strongarm->value = 'projects/project/[node:nid]';
  $export['pathauto_node_erpal_project_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_erpal_task_pattern';
  $strongarm->value = 'projects/project/task/[node:nid]';
  $export['pathauto_node_erpal_task_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_erpal_timetracking_pattern';
  $strongarm->value = 'projects/project/timetracking/[node:nid]';
  $export['pathauto_node_erpal_timetracking_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_priority_terms_pattern';
  $strongarm->value = 'projects/priority/[term:name]';
  $export['pathauto_taxonomy_term_priority_terms_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_project_role_tags_pattern';
  $strongarm->value = 'projects/project-role/[term:name]';
  $export['pathauto_taxonomy_term_project_role_tags_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_project_status_terms_pattern';
  $strongarm->value = 'projects/project-status/[term:name]';
  $export['pathauto_taxonomy_term_project_status_terms_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_project_tags_pattern';
  $strongarm->value = 'projects/project-terms/[term:name]';
  $export['pathauto_taxonomy_term_project_tags_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_task_status_terms_pattern';
  $strongarm->value = 'projects/task-status/[term:name]';
  $export['pathauto_taxonomy_term_task_status_terms_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_task_type_terms_pattern';
  $strongarm->value = 'projects/task-type/[term:name]';
  $export['pathauto_taxonomy_term_task_type_terms_pattern'] = $strongarm;

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
