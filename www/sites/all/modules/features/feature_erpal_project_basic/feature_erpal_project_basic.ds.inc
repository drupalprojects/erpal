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
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_asset_files',
      ),
      'left' => array(
        0 => 'field_date',
        1 => 'field_project_status_term',
        2 => 'field_priority_term',
        3 => 'field_project_contacts',
        4 => 'field_customer_ref',
        5 => 'field_activity_ref',
      ),
      'right' => array(
        0 => 'field_project_tags',
        1 => 'field_pricing',
      ),
      'footer' => array(
        0 => 'field_books_ref',
        1 => 'status',
        2 => 'group_audience',
        3 => 'group_content_access',
        4 => 'submit',
        5 => 'delete',
      ),
      'hidden' => array(
        0 => 'menu',
        1 => 'name',
        2 => 'enabled',
        3 => 'path',
        4 => 'alias',
        5 => 'comment',
        6 => 'date',
        7 => 'revision',
        8 => 'link_title',
        9 => 'log',
        10 => 'promote',
        11 => 'description',
        12 => 'link',
        13 => 'parent',
        14 => 'sticky',
        15 => 'weight',
        16 => 'preview',
        17 => 'preview_changes',
        18 => 'revision_information',
        19 => 'comment_settings',
        20 => 'author',
        21 => 'options',
        22 => 'additional_settings',
        23 => 'actions',
        24 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'body' => 'header',
      'field_asset_files' => 'header',
      'field_date' => 'left',
      'field_project_status_term' => 'left',
      'field_priority_term' => 'left',
      'field_project_contacts' => 'left',
      'field_customer_ref' => 'left',
      'field_activity_ref' => 'left',
      'field_project_tags' => 'right',
      'field_pricing' => 'right',
      'field_books_ref' => 'footer',
      'status' => 'footer',
      'group_audience' => 'footer',
      'group_content_access' => 'footer',
      'submit' => 'footer',
      'delete' => 'footer',
      'menu' => 'hidden',
      'name' => 'hidden',
      'enabled' => 'hidden',
      'path' => 'hidden',
      'alias' => 'hidden',
      'comment' => 'hidden',
      'date' => 'hidden',
      'revision' => 'hidden',
      'link_title' => 'hidden',
      'log' => 'hidden',
      'promote' => 'hidden',
      'description' => 'hidden',
      'link' => 'hidden',
      'parent' => 'hidden',
      'sticky' => 'hidden',
      'weight' => 'hidden',
      'preview' => 'hidden',
      'preview_changes' => 'hidden',
      'revision_information' => 'hidden',
      'comment_settings' => 'hidden',
      'author' => 'hidden',
      'options' => 'hidden',
      'additional_settings' => 'hidden',
      'actions' => 'hidden',
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
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'field_date',
        1 => 'field_estimated_time',
        2 => 'field_is_ticket',
        3 => 'field_task_type_term',
        4 => 'group_task_time_group',
        5 => 'field_parent',
        6 => 'field_progress_percent',
        7 => 'field_task_status_term',
        8 => 'field_priority_term',
      ),
      'header' => array(
        0 => 'title',
        1 => 'field_project_ref',
        2 => 'body',
        3 => 'field_asset_files',
      ),
      'right' => array(
        0 => 'field_pricing',
        1 => 'field_task_assigned_users',
      ),
      'footer' => array(
        0 => 'field_project_tags',
        1 => 'field_task_exclude_from',
        2 => 'status',
        3 => 'group_audience',
        4 => 'group_content_access',
        5 => 'submit',
        6 => 'delete',
        7 => 'comment_settings',
      ),
      'hidden' => array(
        0 => 'description',
        1 => 'parent',
        2 => 'revision',
        3 => 'path',
        4 => 'comment',
        5 => 'alias',
        6 => 'field_timetracking_button',
        7 => 'weight',
        8 => 'menu',
        9 => 'name',
        10 => 'link_title',
        11 => 'enabled',
        12 => 'date',
        13 => 'link',
        14 => 'promote',
        15 => 'log',
        16 => 'sticky',
        17 => 'preview',
        18 => 'preview_changes',
        19 => 'field_weight',
        20 => 'revision_information',
        21 => 'author',
        22 => 'options',
        23 => 'additional_settings',
        24 => 'actions',
        25 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_date' => 'left',
      'field_estimated_time' => 'left',
      'title' => 'header',
      'field_project_ref' => 'header',
      'body' => 'header',
      'field_asset_files' => 'header',
      'field_is_ticket' => 'left',
      'field_task_type_term' => 'left',
      'group_task_time_group' => 'left',
      'field_parent' => 'left',
      'field_progress_percent' => 'left',
      'field_task_status_term' => 'left',
      'field_priority_term' => 'left',
      'field_pricing' => 'right',
      'field_task_assigned_users' => 'right',
      'field_project_tags' => 'footer',
      'field_task_exclude_from' => 'footer',
      'status' => 'footer',
      'group_audience' => 'footer',
      'group_content_access' => 'footer',
      'submit' => 'footer',
      'delete' => 'footer',
      'comment_settings' => 'footer',
      'description' => 'hidden',
      'parent' => 'hidden',
      'revision' => 'hidden',
      'path' => 'hidden',
      'comment' => 'hidden',
      'alias' => 'hidden',
      'field_timetracking_button' => 'hidden',
      'weight' => 'hidden',
      'menu' => 'hidden',
      'name' => 'hidden',
      'link_title' => 'hidden',
      'enabled' => 'hidden',
      'date' => 'hidden',
      'link' => 'hidden',
      'promote' => 'hidden',
      'log' => 'hidden',
      'sticky' => 'hidden',
      'preview' => 'hidden',
      'preview_changes' => 'hidden',
      'field_weight' => 'hidden',
      'revision_information' => 'hidden',
      'author' => 'hidden',
      'options' => 'hidden',
      'additional_settings' => 'hidden',
      'actions' => 'hidden',
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
