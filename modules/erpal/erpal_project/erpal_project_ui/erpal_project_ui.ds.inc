<?php
/**
 * @file
 * erpal_project_ui.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function erpal_project_ui_ds_field_settings_info() {
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
  $ds_fieldsetting->id = 'node|erpal_task|in_activity';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_task';
  $ds_fieldsetting->view_mode = 'in_activity';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|erpal_task|in_activity'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_task|minimal';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_task';
  $ds_fieldsetting->view_mode = 'minimal';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|erpal_task|minimal'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|priority_terms|minimal';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'priority_terms';
  $ds_fieldsetting->view_mode = 'minimal';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|priority_terms|minimal'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|task_status_terms|default';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'task_status_terms';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|task_status_terms|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|task_status_terms|in_pane';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'task_status_terms';
  $ds_fieldsetting->view_mode = 'in_pane';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|task_status_terms|in_pane'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|task_status_terms|minimal';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'task_status_terms';
  $ds_fieldsetting->view_mode = 'minimal';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|task_status_terms|minimal'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|task_type_terms|minimal';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'task_type_terms';
  $ds_fieldsetting->view_mode = 'minimal';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|task_type_terms|minimal'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function erpal_project_ui_ds_custom_fields_info() {
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
function erpal_project_ui_ds_layout_settings_info() {
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
        0 => 'group_project_form_basics',
        1 => 'group_project_form_progress',
        2 => 'title',
        3 => 'field_pricing',
        4 => 'field_project_team',
        5 => 'group_project_form_pricing',
        6 => 'field_customer_ref',
        7 => 'field_project_tags',
        8 => 'group_project_form_files',
        9 => 'group_project_form_team',
        10 => 'field_project_status_term',
        11 => 'group_project_form_specs',
        12 => 'field_priority_term',
        13 => 'group_urls',
        14 => 'field_estimated_time',
        15 => 'field_date',
        16 => 'group_project_form_advanced',
        17 => 'body',
        18 => 'field_asset_files',
        19 => 'field_books_ref',
        20 => 'field_repository_url',
        21 => 'field_commit_deeplink_url',
        22 => 'field_development_url',
        23 => 'field_stage_url',
        24 => 'field_live_url',
        25 => 'path',
        26 => 'field_project_contacts',
        27 => 'field_activity_ref',
      ),
      'hidden' => array(
        0 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'group_project_form_basics' => 'left',
      'group_project_form_progress' => 'left',
      'title' => 'left',
      'field_pricing' => 'left',
      'field_project_team' => 'left',
      'group_project_form_pricing' => 'left',
      'field_customer_ref' => 'left',
      'field_project_tags' => 'left',
      'group_project_form_files' => 'left',
      'group_project_form_team' => 'left',
      'field_project_status_term' => 'left',
      'group_project_form_specs' => 'left',
      'field_priority_term' => 'left',
      'group_urls' => 'left',
      'field_estimated_time' => 'left',
      'field_date' => 'left',
      'group_project_form_advanced' => 'left',
      'body' => 'left',
      'field_asset_files' => 'left',
      '_add_existing_field' => 'hidden',
      'field_books_ref' => 'left',
      'field_repository_url' => 'left',
      'field_commit_deeplink_url' => 'left',
      'field_development_url' => 'left',
      'field_stage_url' => 'left',
      'field_live_url' => 'left',
      'path' => 'left',
      'field_project_contacts' => 'left',
      'field_activity_ref' => 'left',
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
      'left' => array(
        0 => 'group_task_form_basics',
        1 => 'field_pricing',
        2 => 'group_task_form_progress',
        3 => 'title',
        4 => 'field_is_ticket',
        5 => 'group_task_form_pricing',
        6 => 'field_asset_files',
        7 => 'group_task_form_files',
        8 => 'field_task_type_term',
        9 => 'field_project_tags',
        10 => 'group_task_form_advanced',
        11 => 'field_date',
        12 => 'field_estimated_time',
        13 => 'body',
        14 => 'field_priority_term',
        15 => 'field_task_exclude_from',
        16 => 'field_task_status_term',
        17 => 'field_progress_percent',
        18 => 'field_parent',
        19 => 'field_depends_on_tasks',
        20 => 'field_task_assigned_users',
        21 => 'field_project_ref',
      ),
      'hidden' => array(
        0 => 'field_weight',
        1 => 'field_timetracking_button',
        2 => 'path',
        3 => 'field_repeat_task',
        4 => 'field_release_ref',
        5 => 'group_task_repeat_options',
        6 => 'field_subtask_repeat_options',
        7 => 'field_increase_repeated_deadline',
        8 => 'field_task_page_module',
        9 => 'field_book_parent',
        10 => '_add_existing_field',
      ),
      'advancedleft' => array(
        0 => 'field_task_template_settings',
      ),
    ),
    'fields' => array(
      'group_task_form_basics' => 'left',
      'field_pricing' => 'left',
      'group_task_form_progress' => 'left',
      'title' => 'left',
      'field_is_ticket' => 'left',
      'group_task_form_pricing' => 'left',
      'field_asset_files' => 'left',
      'group_task_form_files' => 'left',
      'field_task_type_term' => 'left',
      'field_project_tags' => 'left',
      'group_task_form_advanced' => 'left',
      'field_date' => 'left',
      'field_weight' => 'hidden',
      'field_estimated_time' => 'left',
      'body' => 'left',
      'field_timetracking_button' => 'hidden',
      'field_priority_term' => 'left',
      'field_task_exclude_from' => 'left',
      'field_task_status_term' => 'left',
      'path' => 'hidden',
      'field_progress_percent' => 'left',
      'field_parent' => 'left',
      'field_depends_on_tasks' => 'left',
      'field_task_assigned_users' => 'left',
      'field_project_ref' => 'left',
      'field_task_template_settings' => 'advancedleft',
      'field_repeat_task' => 'hidden',
      'field_release_ref' => 'hidden',
      'group_task_repeat_options' => 'hidden',
      'field_subtask_repeat_options' => 'hidden',
      'field_increase_repeated_deadline' => 'hidden',
      'field_task_page_module' => 'hidden',
      'field_book_parent' => 'hidden',
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
  $ds_layout->id = 'node|erpal_task|in_activity';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'in_activity';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_timetracking_button',
        1 => 'title',
        2 => 'field_task_assigned_users',
      ),
    ),
    'fields' => array(
      'field_timetracking_button' => 'ds_content',
      'title' => 'ds_content',
      'field_task_assigned_users' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|erpal_task|in_activity'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_task|minimal';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'minimal';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_task_status_term',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_task_status_term' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|erpal_task|minimal'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|priority_terms|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'priority_terms';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_is_default_term',
        1 => 'description',
        2 => 'field_term_image',
      ),
    ),
    'fields' => array(
      'field_is_default_term' => 'ds_content',
      'description' => 'ds_content',
      'field_term_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
  );
  $export['taxonomy_term|priority_terms|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|priority_terms|minimal';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'priority_terms';
  $ds_layout->view_mode = 'minimal';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_term_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_term_image' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['taxonomy_term|priority_terms|minimal'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|task_status_terms|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'task_status_terms';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_term_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_term_image' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['taxonomy_term|task_status_terms|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|task_status_terms|in_pane';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'task_status_terms';
  $ds_layout->view_mode = 'in_pane';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_term_image',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_term_image' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['taxonomy_term|task_status_terms|in_pane'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|task_status_terms|minimal';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'task_status_terms';
  $ds_layout->view_mode = 'minimal';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_term_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_term_image' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['taxonomy_term|task_status_terms|minimal'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|task_status_terms|visual';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'task_status_terms';
  $ds_layout->view_mode = 'visual';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_term_image',
      ),
    ),
    'fields' => array(
      'field_term_image' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['taxonomy_term|task_status_terms|visual'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|task_type_terms|default';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'task_type_terms';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_is_default_term',
        1 => 'description',
        2 => 'field_term_image',
      ),
    ),
    'fields' => array(
      'field_is_default_term' => 'ds_content',
      'description' => 'ds_content',
      'field_term_image' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
  );
  $export['taxonomy_term|task_type_terms|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|task_type_terms|minimal';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'task_type_terms';
  $ds_layout->view_mode = 'minimal';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 1,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_term_image',
        1 => 'title',
      ),
    ),
    'fields' => array(
      'field_term_image' => 'ds_content',
      'title' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['taxonomy_term|task_type_terms|minimal'] = $ds_layout;

  return $export;
}
