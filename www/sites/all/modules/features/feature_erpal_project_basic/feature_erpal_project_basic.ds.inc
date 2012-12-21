<?php
/**
 * @file
 * feature_erpal_project_basic.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function feature_erpal_project_basic_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_project|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_project';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'budget_usage' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|erpal_project|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_task|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_task';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'budget_usage' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|erpal_task|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_task|view_row_details';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_task';
  $ds_fieldsetting->view_mode = 'view_row_details';
  $ds_fieldsetting->settings = array(
    'comment_count' => array(
      'weight' => '12',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:5:{s:11:"admin_title";s:0:"";s:5:"title";s:0:"";s:4:"body";s:28:"%node:comment-count comments";s:6:"format";s:13:"filtered_html";s:10:"substitute";i:1;}s:4:"type";s:6:"custom";s:7:"subtype";s:6:"custom";}',
        'load_terms' => 0,
      ),
    ),
    'files_count' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:2:{s:5:"types";a:0:{}s:10:"field_name";s:0:"";}s:4:"type";s:11:"files_count";s:7:"subtype";s:11:"files_count";}',
        'load_terms' => 0,
      ),
    ),
    'task_customer_node' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:2:{s:5:"types";a:0:{}s:10:"field_name";s:0:"";}s:4:"type";s:13:"task_customer";s:7:"subtype";s:13:"task_customer";}',
        'load_terms' => 0,
      ),
    ),
    'task_title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => 'h2',
        'ctools' => 'a:3:{s:4:"conf";a:5:{s:11:"admin_title";s:10:"Task title";s:5:"title";s:0:"";s:4:"body";s:74:"<a href="/node/%node:nid">%node:field_is_ticket #%node:nid %node:title</a>";s:6:"format";s:13:"filtered_html";s:10:"substitute";i:1;}s:4:"type";s:6:"custom";s:7:"subtype";s:6:"custom";}',
        'load_terms' => 0,
      ),
    ),
    'author' => array(
      'weight' => '10',
      'label' => 'above',
      'format' => 'author_linked',
    ),
    'post_date' => array(
      'weight' => '11',
      'label' => 'above',
      'format' => 'ds_post_date_short',
    ),
  );
  $export['node|erpal_task|view_row_details'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function feature_erpal_project_basic_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'budget_usage';
  $ds_field->label = 'Budget usage';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['budget_usage'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'task_customer_node';
  $ds_field->label = 'Task customer node';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['task_customer_node'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'task_title';
  $ds_field->label = 'Task title';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['task_title'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'time_used';
  $ds_field->label = 'time used';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['time_used'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_erpal_project_basic_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_project|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_project';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'body',
      ),
      'right' => array(
        0 => 'group_content_access',
        1 => 'field_customer_ref',
        2 => 'field_project_status_term',
        3 => 'field_priority_term',
        4 => 'field_pricing',
      ),
      'advancedleft' => array(
        0 => 'path',
        1 => 'field_project_tags',
        2 => 'og_group_ref',
        3 => 'field_project_contacts',
        4 => 'field_activity_ref',
      ),
      'advancedright' => array(
        0 => 'field_date',
        1 => 'field_books_ref',
        2 => 'field_asset_files',
      ),
      'hidden' => array(
        0 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'body' => 'left',
      'group_content_access' => 'right',
      'field_customer_ref' => 'right',
      'field_project_status_term' => 'right',
      'field_priority_term' => 'right',
      'field_pricing' => 'right',
      'path' => 'advancedleft',
      'field_project_tags' => 'advancedleft',
      'og_group_ref' => 'advancedleft',
      'field_project_contacts' => 'advancedleft',
      'field_activity_ref' => 'advancedleft',
      'field_date' => 'advancedright',
      'field_books_ref' => 'advancedright',
      'field_asset_files' => 'advancedright',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_project|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'author',
        2 => 'post_date',
        3 => 'field_project_tags',
        4 => 'field_project_status_term',
        5 => 'field_date',
        6 => 'budget_usage',
      ),
      'right' => array(
        0 => 'field_customer_ref',
        1 => 'field_project_contacts',
        2 => 'field_activity_ref',
        3 => 'body',
        4 => 'field_asset_files',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'author' => 'left',
      'post_date' => 'left',
      'field_project_tags' => 'left',
      'field_project_status_term' => 'left',
      'field_date' => 'left',
      'budget_usage' => 'left',
      'field_customer_ref' => 'right',
      'field_project_contacts' => 'right',
      'field_activity_ref' => 'right',
      'body' => 'right',
      'field_asset_files' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|erpal_project|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_task|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'advancedright' => array(
        0 => 'field_date',
        1 => 'field_estimated_time',
        2 => 'field_project_tags',
        3 => 'field_task_assigned_users',
        4 => 'group_task_time_group',
        5 => 'field_asset_files',
      ),
      'left' => array(
        0 => 'title',
        1 => 'field_is_ticket',
        2 => 'body',
      ),
      'right' => array(
        0 => 'field_project_ref',
        1 => 'group_content_access',
        2 => 'field_task_status_term',
        3 => 'field_priority_term',
        4 => 'field_task_type_term',
        5 => 'field_pricing',
      ),
      'advancedleft' => array(
        0 => 'field_parent',
        1 => 'field_progress_percent',
        2 => 'field_task_exclude_from',
        3 => 'og_group_ref',
        4 => 'path',
        5 => 'field_timetracking_button',
        6 => 'field_weight',
      ),
      'hidden' => array(
        0 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_date' => 'advancedright',
      'field_estimated_time' => 'advancedright',
      'title' => 'left',
      'field_is_ticket' => 'left',
      'body' => 'left',
      'field_project_ref' => 'right',
      'group_content_access' => 'right',
      'field_task_status_term' => 'right',
      'field_priority_term' => 'right',
      'field_task_type_term' => 'right',
      'field_pricing' => 'right',
      'field_parent' => 'advancedleft',
      'field_progress_percent' => 'advancedleft',
      'field_task_exclude_from' => 'advancedleft',
      'og_group_ref' => 'advancedleft',
      'path' => 'advancedleft',
      'field_timetracking_button' => 'advancedleft',
      'field_weight' => 'advancedleft',
      'field_project_tags' => 'advancedright',
      'field_task_assigned_users' => 'advancedright',
      'group_task_time_group' => 'advancedright',
      'field_asset_files' => 'advancedright',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_task|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_task|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'links',
        1 => 'post_date',
        2 => 'author',
        3 => 'body',
        4 => 'field_asset_files',
        5 => 'field_project_tags',
        6 => 'field_task_type_term',
        7 => 'field_task_status_term',
      ),
      'left' => array(
        0 => 'budget_usage',
        1 => 'field_date',
        2 => 'field_task_assigned_users',
        3 => 'field_parent',
        4 => 'field_task_exclude_from',
      ),
      'right' => array(
        0 => 'field_estimated_time',
        1 => 'field_project_ref',
        2 => 'field_progress_percent',
      ),
    ),
    'fields' => array(
      'links' => 'header',
      'post_date' => 'header',
      'author' => 'header',
      'body' => 'header',
      'field_asset_files' => 'header',
      'field_project_tags' => 'header',
      'field_task_type_term' => 'header',
      'field_task_status_term' => 'header',
      'budget_usage' => 'left',
      'field_date' => 'left',
      'field_task_assigned_users' => 'left',
      'field_parent' => 'left',
      'field_task_exclude_from' => 'left',
      'field_estimated_time' => 'right',
      'field_project_ref' => 'right',
      'field_progress_percent' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|erpal_task|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_task|view_row_details';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'view_row_details';
  $ds_layout->layout = 'panels-erpal_task_view_row_layout';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'sidebar_first_left' => array(
        0 => 'task_title',
      ),
      'sidebar_first_right' => array(
        0 => 'field_project_ref',
        1 => 'task_customer_node',
        2 => 'field_project_tags',
      ),
      'sidebar_second_left' => array(
        0 => 'field_parent',
        1 => 'group_submitted_information',
        2 => 'group_time_information',
        3 => 'field_date',
        4 => 'group_status_information',
        5 => 'field_estimated_time',
        6 => 'field_task_assigned_users',
        7 => 'field_progress_percent',
        8 => 'field_task_status_term',
        9 => 'author',
        10 => 'field_priority_term',
        11 => 'post_date',
      ),
      'sidebar_second_right' => array(
        0 => 'body',
      ),
      'sidebar_third_left' => array(
        0 => 'field_pricing',
      ),
      'sidebar_third_right' => array(
        0 => 'files_count',
        1 => 'comment_count',
      ),
    ),
    'fields' => array(
      'task_title' => 'sidebar_first_left',
      'field_project_ref' => 'sidebar_first_right',
      'task_customer_node' => 'sidebar_first_right',
      'field_project_tags' => 'sidebar_first_right',
      'field_parent' => 'sidebar_second_left',
      'group_submitted_information' => 'sidebar_second_left',
      'group_time_information' => 'sidebar_second_left',
      'field_date' => 'sidebar_second_left',
      'group_status_information' => 'sidebar_second_left',
      'field_estimated_time' => 'sidebar_second_left',
      'field_task_assigned_users' => 'sidebar_second_left',
      'field_progress_percent' => 'sidebar_second_left',
      'field_task_status_term' => 'sidebar_second_left',
      'body' => 'sidebar_second_right',
      'author' => 'sidebar_second_left',
      'field_priority_term' => 'sidebar_second_left',
      'field_pricing' => 'sidebar_third_left',
      'files_count' => 'sidebar_third_right',
      'post_date' => 'sidebar_second_left',
      'comment_count' => 'sidebar_third_right',
    ),
    'classes' => array(),
  );
  $export['node|erpal_task|view_row_details'] = $ds_layout;

  return $export;
}
