<?php
/**
 * @file
 * feature_erpal_project_basic.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_erpal_project_basic_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'assigned_tasks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Assigned tasks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Assigned open tasks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No tasks available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  /* Relationship: Content: Status (field_task_status_term) */
  $handler->display->display_options['relationships']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Timetracking button */
  $handler->display->display_options['fields']['field_timetracking_button']['id'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['table'] = 'field_data_field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['field'] = 'field_timetracking_button';
  /* Sort criterion: Field: Period - end date (field_date:value2) */
  $handler->display->display_options['sorts']['field_date_value2']['id'] = 'field_date_value2';
  $handler->display->display_options['sorts']['field_date_value2']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value2']['field'] = 'field_date_value2';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );

  /* Display: Assigned tasks page */
  $handler = $view->new_display('page', 'Assigned tasks page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'editable';
  $handler->display->display_options['fields']['field_task_status_term']['settings'] = array(
    'click_to_edit' => 1,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_plain',
  );
  /* Field: Content: Progress */
  $handler->display->display_options['fields']['field_progress_percent']['id'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['table'] = 'field_data_field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['field'] = 'field_progress_percent';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Timetracking button */
  $handler->display->display_options['fields']['field_timetracking_button']['id'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['table'] = 'field_data_field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['field'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['label'] = 'Timetracking';
  $handler->display->display_options['fields']['field_timetracking_button']['type'] = 'computed_field_unsanitized';
  $handler->display->display_options['path'] = 'tasks';

  /* Display: Assigned tasks block */
  $handler = $view->new_display('block', 'Assigned tasks block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Timetracking button */
  $handler->display->display_options['fields']['field_timetracking_button']['id'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['table'] = 'field_data_field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['field'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['label'] = 'Timetracking';
  $handler->display->display_options['fields']['field_timetracking_button']['type'] = 'computed_field_unsanitized';
  $translatables['assigned_tasks'] = array(
    t('Master'),
    t('Assigned open tasks'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No tasks available'),
    t('User entity referenced from field_task_assigned_users'),
    t('term from field_task_status_term'),
    t('Title'),
    t('Project'),
    t('Priority'),
    t('Deadline'),
    t('Timetracking button'),
    t('Assigned tasks page'),
    t('Status'),
    t('Progress'),
    t('Parent'),
    t('Timetracking'),
    t('Assigned tasks block'),
  );
  $export['assigned_tasks'] = $view;

  $view = new view();
  $view->name = 'fixed_price_nodes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Fixed price nodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access billables view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_project_ref' => 'field_project_ref',
    'field_date' => 'field_date',
    'field_project_status_term' => 'field_project_status_term',
    'field_task_status_term' => 'field_project_status_term',
    'field_price' => 'field_price',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_status_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No fixed priced items found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Pricing (field_pricing) */
  $handler->display->display_options['relationships']['field_pricing_value']['id'] = 'field_pricing_value';
  $handler->display->display_options['relationships']['field_pricing_value']['table'] = 'field_data_field_pricing';
  $handler->display->display_options['relationships']['field_pricing_value']['field'] = 'field_pricing_value';
  $handler->display->display_options['relationships']['field_pricing_value']['delta'] = '-1';
  /* Relationship: Content: Status (field_project_status_term) */
  $handler->display->display_options['relationships']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  /* Relationship: Content: Status (field_task_status_term) */
  $handler->display->display_options['relationships']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Price per month */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['relationship'] = 'field_pricing_value';
  $handler->display->display_options['fields']['field_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Field collection item: Price per month (field_price) */
  $handler->display->display_options['filters']['field_price_value']['id'] = 'field_price_value';
  $handler->display->display_options['filters']['field_price_value']['table'] = 'field_data_field_price';
  $handler->display->display_options['filters']['field_price_value']['field'] = 'field_price_value';
  $handler->display->display_options['filters']['field_price_value']['relationship'] = 'field_pricing_value';
  $handler->display->display_options['filters']['field_price_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_price_value']['group'] = 1;
  /* Filter criterion: Field collection item: Price mode (field_price_mode) */
  $handler->display->display_options['filters']['field_price_mode_value']['id'] = 'field_price_mode_value';
  $handler->display->display_options['filters']['field_price_mode_value']['table'] = 'field_data_field_price_mode';
  $handler->display->display_options['filters']['field_price_mode_value']['field'] = 'field_price_mode_value';
  $handler->display->display_options['filters']['field_price_mode_value']['relationship'] = 'field_pricing_value';
  $handler->display->display_options['filters']['field_price_mode_value']['value'] = array(
    'fixed_price' => 'fixed_price',
  );
  $handler->display->display_options['filters']['field_price_mode_value']['group'] = 1;
  $handler->display->display_options['filters']['field_price_mode_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['id'] = 'field_simple_process_status_value_1';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 2;
  $handler->display->display_options['filters']['field_simple_process_status_value']['reduce_duplicates'] = TRUE;

  /* Display: Fixed price nodes pane */
  $handler = $view->new_display('panel_pane', 'Fixed price nodes pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_project_status_term']['id'] = 'field_project_status_term';
  $handler->display->display_options['fields']['field_project_status_term']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['fields']['field_project_status_term']['field'] = 'field_project_status_term';
  $handler->display->display_options['fields']['field_project_status_term']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_project_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['alter']['text'] = '[field_project_status_term] --';
  $handler->display->display_options['fields']['field_task_status_term']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Price per month */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['relationship'] = 'field_pricing_value';
  $handler->display->display_options['fields']['field_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';

  /* Display: Fixed price tasks by project pane */
  $handler = $view->new_display('panel_pane', 'Fixed price tasks by project pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Fixed price tasks';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['fixed_price_nodes'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No fixed priced items found'),
    t('field collection item from field_pricing'),
    t('term from field_project_status_term'),
    t('term from field_task_status_term'),
    t('Task title'),
    t('Project'),
    t('Deadline'),
    t('Status'),
    t('Price'),
    t('Fixed price nodes pane'),
    t('[field_project_status_term] --'),
    t('Type'),
    t('View panes'),
    t('Fixed price tasks by project pane'),
    t('Fixed price tasks'),
    t('All'),
  );
  $export['fixed_price_nodes'] = $view;

  $view = new view();
  $view->name = 'projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access projects view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_customer_ref' => 'field_customer_ref',
    'field_project_status_term' => 'field_project_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_date' => 'field_date',
    'field_date_1' => 'field_date_1',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_priority_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No projects found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_project_status_term']['id'] = 'field_project_status_term';
  $handler->display->display_options['fields']['field_project_status_term']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['fields']['field_project_status_term']['field'] = 'field_project_status_term';
  $handler->display->display_options['fields']['field_project_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Project starts';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = 'Project ends';
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_project' => 'erpal_project',
  );
  /* Filter criterion: Field: Customer (field_customer_ref) */
  $handler->display->display_options['filters']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator_id'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['identifier'] = 'field_customer_ref_target_id';
  /* Filter criterion: Content: Status (field_project_status_term) */
  $handler->display->display_options['filters']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['filters']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_project_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['operator_id'] = 'field_project_status_term_tid_op';
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['operator'] = 'field_project_status_term_tid_op';
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['identifier'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_status_term_tid']['vocabulary'] = 'project_status_terms';
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';

  /* Display: Projects by activity pane */
  $handler = $view->new_display('panel_pane', 'Projects by activity pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_activity_status_term']['id'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['field'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['label'] = '';
  $handler->display->display_options['fields']['field_activity_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_activity_status_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_activity_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([field_activity_status_term])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: CRM activity (field_activity_ref) */
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['id'] = 'field_activity_ref_target_id';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['table'] = 'field_data_field_activity_ref';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['field'] = 'field_activity_ref_target_id';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_project' => 'erpal_project',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['argument_input'] = array(
    'field_activity_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: CRM activity (field_activity_ref)',
    ),
  );

  /* Display: Projects and tasks reference dialog search */
  $handler = $view->new_display('references_dialog', 'Projects and tasks reference dialog search', 'references_dialog_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Projects and tasks';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
  /* Filter criterion: Field: Customer (field_customer_ref) */
  $handler->display->display_options['filters']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator_id'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['identifier'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Tasks by project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['attach'] = array(
    0 => 'field_collection_item:field_budget_destination:field_budget_booking',
  );

  /* Display: Projects pane */
  $handler = $view->new_display('panel_pane', 'Projects pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Field: Customer (field_customer_ref) */
  $handler->display->display_options['filters']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator_id'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['identifier'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_project_status_term) */
  $handler->display->display_options['filters']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['filters']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_project_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['operator_id'] = 'field_project_status_term_tid_op';
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['operator'] = 'field_project_status_term_tid_op';
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['identifier'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_status_term_tid']['vocabulary'] = 'project_status_terms';
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_project' => 'erpal_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['projects'] = array(
    t('Master'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No projects found'),
    t('Title'),
    t('Customer'),
    t('Status'),
    t('Priority'),
    t('Project starts'),
    t('Project ends'),
    t('Projects by activity pane'),
    t('[title] ([field_activity_status_term])'),
    t('All'),
    t('View panes'),
    t('Projects and tasks reference dialog search'),
    t('Projects and tasks'),
    t('Content entity referenced from field_project_ref'),
    t('Type'),
    t('Tasks by project'),
    t('Projects pane'),
    t('Search Terms'),
  );
  $export['projects'] = $view;

  $view = new view();
  $view->name = 'tasks';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Tasks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks details';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'nid' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'title' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_task_status_term_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_priority_term_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_task_type_term_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_project_tags_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_task_assigned_users_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No tasks available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['relationships']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['relationships']['field_parent_target_id']['field'] = 'field_parent_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Estimated time */
  $handler->display->display_options['fields']['field_estimated_time']['id'] = 'field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['table'] = 'field_data_field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['field'] = 'field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['label'] = 'Time';
  $handler->display->display_options['fields']['field_estimated_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['text'] = '[field_estimated_time] h';
  $handler->display->display_options['fields']['field_estimated_time']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent_1']['id'] = 'field_parent_1';
  $handler->display->display_options['fields']['field_parent_1']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent_1']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['fields']['field_parent_1']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Weight */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Sort criterion: Content: Weight (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';

  /* Display: Task by project pane tree */
  $handler = $view->new_display('panel_pane', 'Task by project pane tree', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tree';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks details';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 0;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_project' => 0,
    'erpal_task' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 1,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['label'] = 'Priority (field_priority_term)';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Task child view AJAX */
  $handler = $view->new_display('panel_pane', 'Task child view AJAX', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks details';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 1;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_task' => 'erpal_task',
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_project' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 1,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;

  /* Display: Task child view AJAX TOP */
  $handler = $view->new_display('panel_pane', 'Task child view AJAX TOP', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks details';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 1;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_task' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 1,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['relationships']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['relationships']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_2']['id'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['table'] = 'node';
  $handler->display->display_options['filters']['type_2']['field'] = 'type';
  $handler->display->display_options['filters']['type_2']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['filters']['type_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['type_2']['group'] = 2;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;

  /* Display: Subtasks Tree */
  $handler = $view->new_display('panel_pane', 'Subtasks Tree', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Subtasks (tree)';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access sub tasks and tickets tree view';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 0;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_project' => 0,
    'erpal_task' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 0,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_parent_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tasks by ID */
  $handler = $view->new_display('panel_pane', 'Tasks by ID', 'panel_pane_6');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks details';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['results_id'] = 1;
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 0;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_date' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_project' => 0,
    'erpal_task' => 0,
    'erpal_timetracking' => 0,
    'erpal_space' => 0,
    'article' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 0,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;

  /* Display: Subtasks List */
  $handler = $view->new_display('panel_pane', 'Subtasks List', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Subtasks (list)';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access sub tasks and tickets view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_task_type_term' => 'field_task_type_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'name' => 'name',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_priority_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_type_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '#';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Parent';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_parent_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Subtasks Details */
  $handler = $view->new_display('panel_pane', 'Subtasks Details', 'panel_pane_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Subtasks (details)';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access sub tasks and tickets details view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'view_row_details';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_parent_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tasks by project pane list */
  $handler = $view->new_display('panel_pane', 'Tasks by project pane list', 'panel_pane_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'List';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid_1' => 'nid_1',
    'title' => 'title',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_task_type_term' => 'field_task_type_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'name' => 'name',
    'field_parent' => 'field_parent',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'nid_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_priority_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_type_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '#';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['label'] = 'Priority (field_priority_term)';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'wildcard',
      'context' => 'entity:comment.node',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tasks by project pane details */
  $handler = $view->new_display('panel_pane', 'Tasks by project pane details', 'panel_pane_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Details';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks tree';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'view_row_details';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '#';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['label'] = 'Priority (field_priority_term)';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['tasks'] = array(
    t('Master'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No tasks available'),
    t('Content entity referenced from field_parent'),
    t('author'),
    t('Project'),
    t('Type'),
    t('Status'),
    t('Priority'),
    t('Time'),
    t('[field_estimated_time] h'),
    t('Parent'),
    t('Edit'),
    t('Nid'),
    t('Weight'),
    t('Assigned'),
    t('Title'),
    t('Categories'),
    t('Task by project pane tree'),
    t('Tree'),
    t('All'),
    t('ID'),
    t('Priority (field_priority_term)'),
    t('View panes'),
    t('Task child view AJAX'),
    t('Task child view AJAX TOP'),
    t('Subtasks Tree'),
    t('Subtasks (tree)'),
    t('Tasks by ID'),
    t('Subtasks List'),
    t('Subtasks (list)'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('#'),
    t('Task title'),
    t('Submitted'),
    t('Last update'),
    t('Deadline'),
    t('Author'),
    t('Subtasks Details'),
    t('Subtasks (details)'),
    t('Tasks by project pane list'),
    t('List'),
    t('Tasks by project pane details'),
    t('Details'),
  );
  $export['tasks'] = $view;

  $view = new view();
  $view->name = 'tickets';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = 'Tickets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tickets view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_task_type_term_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_task_status_term_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_task_assigned_users_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_priority_term_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'title' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_project_tags_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No tasks available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['relationships']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['relationships']['field_parent_target_id']['field'] = 'field_parent_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Estimated time */
  $handler->display->display_options['fields']['field_estimated_time']['id'] = 'field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['table'] = 'field_data_field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['field'] = 'field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['label'] = 'Time';
  $handler->display->display_options['fields']['field_estimated_time']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['text'] = '[field_estimated_time] h';
  $handler->display->display_options['fields']['field_estimated_time']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent_1']['id'] = 'field_parent_1';
  $handler->display->display_options['fields']['field_parent_1']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent_1']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['fields']['field_parent_1']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Weight */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Sort criterion: Content: Weight (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Tickets by project pane tree */
  $handler = $view->new_display('panel_pane', 'Tickets by project pane tree', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tree';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tickets tree';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 0;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_project' => 0,
    'erpal_task' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 1,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['label'] = 'Priority (field_priority_term)';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tickets child view AJAX */
  $handler = $view->new_display('panel_pane', 'Tickets child view AJAX', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tickets tree';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 1;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_task' => 'erpal_task',
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_project' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 1,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';

  /* Display: Tickets child view AJAX TOP */
  $handler = $view->new_display('panel_pane', 'Tickets child view AJAX TOP', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tickets tree';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 1;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_task' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 1,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['relationships']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['relationships']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_2']['id'] = 'type_2';
  $handler->display->display_options['filters']['type_2']['table'] = 'node';
  $handler->display->display_options['filters']['type_2']['field'] = 'type';
  $handler->display->display_options['filters']['type_2']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['filters']['type_2']['operator'] = 'empty';
  $handler->display->display_options['filters']['type_2']['group'] = 2;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['value'] = '';
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';

  /* Display: Subtickets Tree */
  $handler = $view->new_display('panel_pane', 'Subtickets Tree', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Subtickets (tree)';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access sub tasks and tickets tree view';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 0;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_project' => 0,
    'erpal_task' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 0,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_parent_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tickets by ID */
  $handler = $view->new_display('panel_pane', 'Tickets by ID', 'panel_pane_6');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tickets tree';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['results_id'] = 1;
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent_1';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type';
  $handler->display->display_options['style_options']['ajax_child_view'] = 0;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_contact' => 0,
    'erpal_book' => 0,
    'erpal_book_page' => 0,
    'erpal_contract' => 0,
    'erpal_crm_activity' => 0,
    'erpal_file' => 0,
    'erpal_invoice' => 0,
    'erpal_project' => 0,
    'erpal_task' => 0,
    'erpal_timetracking' => 0,
    'article' => 0,
    'erpal_space' => 0,
    'page' => 0,
  );
  $handler->display->display_options['style_options']['context_menu'] = array(
    'use_context_menu_hook' => 0,
    'custom_context_menu' => '',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;

  /* Display: Subtickets List */
  $handler = $view->new_display('panel_pane', 'Subtickets List', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Subtickets (list)';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access sub tasks and tickets view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_task_type_term' => 'field_task_type_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'name' => 'name',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_priority_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_type_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '#';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ticket title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_parent_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Subtickets Details */
  $handler = $view->new_display('panel_pane', 'Subtickets Details', 'panel_pane_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Subtasks (details)';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access sub tasks and tickets details view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'view_row_details';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_parent_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tickets by project pane list */
  $handler = $view->new_display('panel_pane', 'Tickets by project pane list', 'panel_pane_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'List';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tickets view';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid_1' => 'nid_1',
    'title' => 'title',
    'field_task_type_term' => 'field_task_type_term',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'field_parent' => 'field_parent',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'nid_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_type_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_priority_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '#';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ticket title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['label'] = 'Priority (field_priority_term)';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tickets by project pane details */
  $handler = $view->new_display('panel_pane', 'Tickets by project pane details', 'panel_pane_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Details';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tickets details';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'view_row_details';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '#';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last update';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['label'] = 'Priority (field_priority_term)';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_priority_term_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Categories (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['tickets'] = array(
    t('Master'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No tasks available'),
    t('Content entity referenced from field_parent'),
    t('author'),
    t('Project'),
    t('Type'),
    t('Status'),
    t('Priority'),
    t('Time'),
    t('[field_estimated_time] h'),
    t('Parent'),
    t('Edit'),
    t('Nid'),
    t('Weight'),
    t('Assigned'),
    t('Title'),
    t('Categories'),
    t('ID'),
    t('Tickets by project pane tree'),
    t('Tree'),
    t('All'),
    t('Priority (field_priority_term)'),
    t('View panes'),
    t('Tickets child view AJAX'),
    t('Tickets child view AJAX TOP'),
    t('Subtickets Tree'),
    t('Subtickets (tree)'),
    t('Tickets by ID'),
    t('Subtickets List'),
    t('Subtickets (list)'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('#'),
    t('Ticket title'),
    t('Submitted'),
    t('Last update'),
    t('Deadline'),
    t('Author'),
    t('Subtickets Details'),
    t('Subtasks (details)'),
    t('Tickets by project pane list'),
    t('List'),
    t('Tickets by project pane details'),
    t('Details'),
  );
  $export['tickets'] = $view;

  $view = new view();
  $view->name = 'timetracking_entities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'timetracking';
  $view->human_name = 'timetracking entities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My unbooked timetrackings';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create timetracking';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'description',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_timetracking_button',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'timetracking_id' => 'timetracking_id',
    'changed' => 'changed',
    'description' => 'description',
    'time_start' => 'time_start',
    'time_end' => 'time_end',
    'duration' => 'duration',
    'title' => 'title',
    'delete_timetracking' => 'delete_timetracking',
    'edit_timetracking' => 'edit_timetracking',
    'name' => 'name',
    'field_timetracking_button' => 'field_timetracking_button',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timetracking_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'time_start' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'time_end' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_timetracking' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_timetracking' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_timetracking_button' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No timetrackings available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Timetracking: Timetracking subject */
  $handler->display->display_options['relationships']['subject_id']['id'] = 'subject_id';
  $handler->display->display_options['relationships']['subject_id']['table'] = 'timetracking';
  $handler->display->display_options['relationships']['subject_id']['field'] = 'subject_id';
  /* Relationship: Timetracking: Timetracking user */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'timetracking';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Timetracking */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'timetracking';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::erpal_invoice_helper_invoice_from_billables_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_delete_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_projects_helper_timetracking_finalise_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_reduce_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_billed_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_unbilled_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Timetracking: Timetracking ID */
  $handler->display->display_options['fields']['timetracking_id']['id'] = 'timetracking_id';
  $handler->display->display_options['fields']['timetracking_id']['table'] = 'timetracking';
  $handler->display->display_options['fields']['timetracking_id']['field'] = 'timetracking_id';
  /* Field: Timetracking: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'timetracking';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Timetracking: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'timetracking';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Artikelbezeichnung';
  /* Field: Timetracking: Time_start */
  $handler->display->display_options['fields']['time_start']['id'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['table'] = 'timetracking';
  $handler->display->display_options['fields']['time_start']['field'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['label'] = 'start';
  $handler->display->display_options['fields']['time_start']['date_format'] = 'erpal_date_time';
  /* Field: Timetracking: Time_end */
  $handler->display->display_options['fields']['time_end']['id'] = 'time_end';
  $handler->display->display_options['fields']['time_end']['table'] = 'timetracking';
  $handler->display->display_options['fields']['time_end']['field'] = 'time_end';
  $handler->display->display_options['fields']['time_end']['label'] = 'end';
  $handler->display->display_options['fields']['time_end']['date_format'] = 'erpal_date_time';
  /* Field: Timetracking: Duration */
  $handler->display->display_options['fields']['duration']['id'] = 'duration';
  $handler->display->display_options['fields']['duration']['table'] = 'timetracking';
  $handler->display->display_options['fields']['duration']['field'] = 'duration';
  $handler->display->display_options['fields']['duration']['precision'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'subject_id';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: Timetracking: Delete Link */
  $handler->display->display_options['fields']['delete_timetracking']['id'] = 'delete_timetracking';
  $handler->display->display_options['fields']['delete_timetracking']['table'] = 'timetracking';
  $handler->display->display_options['fields']['delete_timetracking']['field'] = 'delete_timetracking';
  /* Field: Timetracking: Edit Link */
  $handler->display->display_options['fields']['edit_timetracking']['id'] = 'edit_timetracking';
  $handler->display->display_options['fields']['edit_timetracking']['table'] = 'timetracking';
  $handler->display->display_options['fields']['edit_timetracking']['field'] = 'edit_timetracking';
  /* Field: Content: Timetracking button */
  $handler->display->display_options['fields']['field_timetracking_button']['id'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['table'] = 'field_data_field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['field'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['relationship'] = 'subject_id';
  $handler->display->display_options['fields']['field_timetracking_button']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timetracking_button']['type'] = 'computed_field_unsanitized';
  /* Sort criterion: Timetracking: Time_start */
  $handler->display->display_options['sorts']['time_start']['id'] = 'time_start';
  $handler->display->display_options['sorts']['time_start']['table'] = 'timetracking';
  $handler->display->display_options['sorts']['time_start']['field'] = 'time_start';
  $handler->display->display_options['sorts']['time_start']['order'] = 'DESC';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: My timetracking entites */
  $handler = $view->new_display('page', 'My timetracking entites', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['path'] = 'projects/timetrackings/tmp';

  /* Display: My Timetrackings block */
  $handler = $view->new_display('block', 'My Timetrackings block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Timetracking: Time_start */
  $handler->display->display_options['fields']['time_start']['id'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['table'] = 'timetracking';
  $handler->display->display_options['fields']['time_start']['field'] = 'time_start';
  $handler->display->display_options['fields']['time_start']['label'] = 'start';
  $handler->display->display_options['fields']['time_start']['date_format'] = 'erpal_date_time';
  /* Field: Timetracking: Duration */
  $handler->display->display_options['fields']['duration']['id'] = 'duration';
  $handler->display->display_options['fields']['duration']['table'] = 'timetracking';
  $handler->display->display_options['fields']['duration']['field'] = 'duration';
  $handler->display->display_options['fields']['duration']['precision'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'subject_id';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  /* Field: Timetracking: Edit Link */
  $handler->display->display_options['fields']['edit_timetracking']['id'] = 'edit_timetracking';
  $handler->display->display_options['fields']['edit_timetracking']['table'] = 'timetracking';
  $handler->display->display_options['fields']['edit_timetracking']['field'] = 'edit_timetracking';
  $handler->display->display_options['fields']['edit_timetracking']['label'] = '';
  $handler->display->display_options['fields']['edit_timetracking']['element_label_colon'] = FALSE;
  /* Field: Content: Timetracking button */
  $handler->display->display_options['fields']['field_timetracking_button']['id'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['table'] = 'field_data_field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['field'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['relationship'] = 'subject_id';
  $handler->display->display_options['fields']['field_timetracking_button']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_timetracking_button']['type'] = 'computed_field_unsanitized';
  /* Field: Timetracking: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'timetracking';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = 'Artikelbezeichnung';
  $handler->display->display_options['fields']['description']['exclude'] = TRUE;
  $translatables['timetracking_entities'] = array(
    t('Master'),
    t('My unbooked timetrackings'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No timetrackings available'),
    t('Timetracking subject'),
    t('Timetracking user'),
    t('Timetracking'),
    t('Timetracking ID'),
    t('.'),
    t(','),
    t('Changed'),
    t('Artikelbezeichnung'),
    t('start'),
    t('end'),
    t('Duration'),
    t('Subject'),
    t('User'),
    t('Delete Link'),
    t('Edit Link'),
    t('Timetracking button'),
    t('My timetracking entites'),
    t('My Timetrackings block'),
  );
  $export['timetracking_entities'] = $view;

  $view = new view();
  $view->name = 'timetrackings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'timetrackings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Timetrackings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access timetrackings view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No timetrackings available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['label'] = 'field_timetracking_subject';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations_1']['id'] = 'views_bulk_operations_1';
  $handler->display->display_options['fields']['views_bulk_operations_1']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations_1']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations_1']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_book_helper_clone_to_book_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_invoice_helper_invoice_from_billables_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_delete_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_timetracking_export_basic_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_projects_helper_timetracking_finalise_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_reduce_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_billed_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_unbilled_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations_1']['vbo']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date and time */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_timetracking_duration']['id'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['table'] = 'field_data_field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['field'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Billing Duration */
  $handler->display->display_options['fields']['field_billing_duration']['id'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['table'] = 'field_data_field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['field'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Task';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Project';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Subject (field_timetracking_subject) */
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_timetracking' => 'erpal_timetracking',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Timetrackings */
  $handler = $view->new_display('page', 'Timetrackings', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['label'] = 'field_timetracking_subject';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['label'] = 'field_project_ref';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_nid';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'projects/timetrackings';

  /* Display: Timetrackings by task */
  $handler = $view->new_display('panel_pane', 'Timetrackings by task', 'panel_pane_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['label'] = 'field_timetracking_subject';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['label'] = 'field_project_ref';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_book_helper_clone_to_book_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_invoice_helper_invoice_from_billables_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_delete_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_timetracking_export_basic_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_projects_helper_timetracking_finalise_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_reduce_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_billed_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_unbilled_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date and time */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_timetracking_duration']['id'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['table'] = 'field_data_field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['field'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Billing Duration */
  $handler->display->display_options['fields']['field_billing_duration']['id'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['table'] = 'field_data_field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['field'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Project';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Subject (field_timetracking_subject) */
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_timetracking' => 'erpal_timetracking',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Timetracking: Show subtasks */
  $handler->display->display_options['filters']['timetracking_subtasks']['id'] = 'timetracking_subtasks';
  $handler->display->display_options['filters']['timetracking_subtasks']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['filters']['timetracking_subtasks']['field'] = 'timetracking_subtasks';
  $handler->display->display_options['filters']['timetracking_subtasks']['value'] = 0;
  $handler->display->display_options['filters']['timetracking_subtasks']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timetracking_subtasks']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['timetracking_subtasks']['expose']['label'] = 'Show subtasks';
  $handler->display->display_options['filters']['timetracking_subtasks']['expose']['operator'] = 'timetracking_subtasks_op';
  $handler->display->display_options['filters']['timetracking_subtasks']['expose']['identifier'] = 'timetracking_subtasks';
  $handler->display->display_options['filters']['timetracking_subtasks']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['timetracking_subtasks']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['argument_input'] = array(
    'field_timetracking_subject_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Subject (field_timetracking_subject)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Timetracking by project pane */
  $handler = $view->new_display('panel_pane', 'Timetracking by project pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_book_helper_clone_to_book_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_invoice_helper_invoice_from_billables_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_delete_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_timetracking_export_basic_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_projects_helper_timetracking_finalise_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_reduce_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_billed_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_unbilled_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Timetracking title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date and time */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_timetracking_duration']['id'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['table'] = 'field_data_field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['field'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Billing Duration */
  $handler->display->display_options['fields']['field_billing_duration']['id'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['table'] = 'field_data_field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['field'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_timetracking_subject']['id'] = 'field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['field'] = 'field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['label'] = 'Task';
  $handler->display->display_options['fields']['field_timetracking_subject']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Subject (field_timetracking_subject) */
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['expose']['operator_id'] = 'field_timetracking_subject_target_id_op';
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['expose']['label'] = 'Task';
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['expose']['operator'] = 'field_timetracking_subject_target_id_op';
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['expose']['identifier'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_timetracking_subject_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_timetracking' => 'erpal_timetracking',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Budget timetrackings pane */
  $handler = $view->new_display('panel_pane', 'Budget timetrackings pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_budget_target_id']['id'] = 'field_budget_target_id';
  $handler->display->display_options['relationships']['field_budget_target_id']['table'] = 'field_data_field_budget';
  $handler->display->display_options['relationships']['field_budget_target_id']['field'] = 'field_budget_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Budget: Budget ID */
  $handler->display->display_options['arguments']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['arguments']['budget_id']['table'] = 'budget';
  $handler->display->display_options['arguments']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['arguments']['budget_id']['relationship'] = 'field_budget_target_id';
  $handler->display->display_options['arguments']['budget_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['budget_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['budget_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['budget_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['budget_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_timetracking' => 'erpal_timetracking',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  $handler->display->display_options['argument_input'] = array(
    'budget_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Budget: Budget ID',
    ),
  );
  $translatables['timetrackings'] = array(
    t('Master'),
    t('Timetrackings'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No timetrackings available'),
    t('author'),
    t('field_timetracking_subject'),
    t('Select'),
    t('Date and time'),
    t('Duration'),
    t('Billing Duration'),
    t('Task'),
    t('Project'),
    t('User'),
    t('All'),
    t('Search Terms'),
    t('Date'),
    t('field_project_ref'),
    t('Timetrackings by task'),
    t('Content'),
    t('Show subtasks'),
    t('View panes'),
    t('Timetracking by project pane'),
    t('Timetracking title'),
    t('Budget timetrackings pane'),
    t('budget entity referenced from field_budget'),
  );
  $export['timetrackings'] = $view;

  return $export;
}
