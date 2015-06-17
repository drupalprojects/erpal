<?php
/**
 * @file
 * erpal_project.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_project_strongarm() {
  $export = array();

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
  $strongarm->value = '300';
  $export['comment_default_per_page_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_task';
  $strongarm->value = '300';
  $export['comment_default_per_page_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_erpal_timetracking';
  $strongarm->value = '300';
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
  $strongarm->value = 0;
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
  $strongarm->name = 'field_bundle_settings_comment__comment_node_erpal_task';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'comment_alter_field_asset_files' => array(
          'weight' => '12',
        ),
        'comment_alter_field_date' => array(
          'weight' => '-2',
        ),
        'comment_alter_field_priority_term' => array(
          'weight' => '8',
        ),
        'comment_alter_field_progress_percent' => array(
          'weight' => '1',
        ),
        'comment_alter_field_task_assigned_users' => array(
          'weight' => '10',
        ),
        'comment_alter_field_task_status_term' => array(
          'weight' => '7',
        ),
        'comment_alter_field_task_type_term' => array(
          'weight' => '9',
        ),
        'comment_alter_field_estimated_time' => array(
          'weight' => '-1',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_comment__comment_node_erpal_task'] = $strongarm;

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
          'weight' => '1',
        ),
        'additional_settings' => array(
          'weight' => '40',
        ),
        'revision_information' => array(
          'weight' => '36',
        ),
        'revision' => array(
          'weight' => '25',
        ),
        'log' => array(
          'weight' => '27',
        ),
        'author' => array(
          'weight' => '38',
        ),
        'name' => array(
          'weight' => '19',
        ),
        'date' => array(
          'weight' => '24',
        ),
        'options' => array(
          'weight' => '39',
        ),
        'status' => array(
          'weight' => '12',
        ),
        'promote' => array(
          'weight' => '28',
        ),
        'sticky' => array(
          'weight' => '32',
        ),
        'actions' => array(
          'weight' => '17',
        ),
        'submit' => array(
          'weight' => '15',
        ),
        'preview' => array(
          'weight' => '34',
        ),
        'delete' => array(
          'weight' => '16',
        ),
        'preview_changes' => array(
          'weight' => '35',
        ),
        'comment_settings' => array(
          'weight' => '37',
        ),
        'comment' => array(
          'weight' => '23',
        ),
        'menu' => array(
          'weight' => '18',
        ),
        'enabled' => array(
          'weight' => '20',
        ),
        'link' => array(
          'weight' => '30',
        ),
        'link_title' => array(
          'weight' => '26',
        ),
        'description' => array(
          'weight' => '29',
        ),
        'parent' => array(
          'weight' => '31',
        ),
        'weight' => array(
          'weight' => '33',
        ),
        'path' => array(
          'weight' => '26',
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
      'view_row_details' => array(
        'custom_settings' => TRUE,
      ),
      'in_activity' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => TRUE,
      ),
      'minimal' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'additional_settings' => array(
          'weight' => '44',
        ),
        'revision_information' => array(
          'weight' => '41',
        ),
        'revision' => array(
          'weight' => '23',
        ),
        'log' => array(
          'weight' => '36',
        ),
        'author' => array(
          'weight' => '42',
        ),
        'name' => array(
          'weight' => '30',
        ),
        'date' => array(
          'weight' => '33',
        ),
        'options' => array(
          'weight' => '43',
        ),
        'status' => array(
          'weight' => '15',
        ),
        'promote' => array(
          'weight' => '35',
        ),
        'sticky' => array(
          'weight' => '37',
        ),
        'actions' => array(
          'weight' => '45',
        ),
        'submit' => array(
          'weight' => '18',
        ),
        'preview' => array(
          'weight' => '38',
        ),
        'delete' => array(
          'weight' => '19',
        ),
        'preview_changes' => array(
          'weight' => '39',
        ),
        'comment_settings' => array(
          'weight' => '20',
        ),
        'comment' => array(
          'weight' => '25',
        ),
        'menu' => array(
          'weight' => '29',
        ),
        'enabled' => array(
          'weight' => '32',
        ),
        'link' => array(
          'weight' => '34',
        ),
        'link_title' => array(
          'weight' => '31',
        ),
        'description' => array(
          'weight' => '21',
        ),
        'parent' => array(
          'weight' => '22',
        ),
        'weight' => array(
          'weight' => '28',
        ),
        'path' => array(
          'weight' => '10',
        ),
        'alias' => array(
          'weight' => '26',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__erpal_timetracking';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__erpal_timetracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_erpal_project';
  $strongarm->value = '0';
  $export['language_content_type_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_erpal_task';
  $strongarm->value = '0';
  $export['language_content_type_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_erpal_project';
  $strongarm->value = '65';
  $export['maxlength_js_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_erpal_task';
  $strongarm->value = '65';
  $export['maxlength_js_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_erpal_project';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_erpal_task';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_erpal_task'] = $strongarm;

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
    1 => 'revision',
  );
  $export['node_options_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_task';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_erpal_timetracking';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
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

  return $export;
}
