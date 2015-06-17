<?php
/**
 * @file
 * erpal_project_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_project_ui_views_default_views() {
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
  $handler->display->display_options['title'] = 'My assigned open tasks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'php' => 'php',
    'field_project_ref' => 'field_project_ref',
    'field_priority_term' => 'field_priority_term',
    'field_task_status_term' => 'field_task_status_term',
    'title' => 'title',
    'field_progress_percent' => 'field_progress_percent',
    'field_date' => 'field_date',
    'field_parent' => 'field_parent',
    'field_timetracking_button' => 'field_timetracking_button',
    'type' => 'type',
    'field_task_type_term' => 'field_task_type_term',
    'changed' => 'changed',
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
    'php' => array(
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
    'field_priority_term' => array(
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
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_progress_percent' => array(
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
    'field_timetracking_button' => array(
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
    'field_task_type_term' => array(
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
  );
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
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['required'] = TRUE;
  /* Relationship: Content: Status (field_project_status_term) */
  $handler->display->display_options['relationships']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['relationship'] = 'field_project_ref_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
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
  /* Sort criterion: Field: Period -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
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
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority (field_priority_term)';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';

  /* Display: My assigned tasks page */
  $handler = $view->new_display('page', 'My assigned tasks page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '#';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Task title';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return $row->title;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
return _erpal_basic_helper_render_title($data->nid, $row->type, $view, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_task_status_term']['settings'] = array(
    'click_to_edit' => 1,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_plain',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Progress */
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
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Timetracking button */
  $handler->display->display_options['fields']['field_timetracking_button']['id'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['table'] = 'field_data_field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['field'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['label'] = 'Timetracking';
  $handler->display->display_options['fields']['field_timetracking_button']['type'] = 'computed_field_unsanitized';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search terms';
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
    8 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['id'] = 'field_simple_process_status_value_1';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['group'] = 1;
  $handler->display->display_options['path'] = 'user/tasks';

  /* Display: Assigned tasks block */
  $handler = $view->new_display('block', 'Assigned tasks block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My assigned open tasks and tickets';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Task title';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return $row->title;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
return _erpal_basic_helper_render_title($data->nid, $row->type, $view, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
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
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
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
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['id'] = 'field_simple_process_status_value_1';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['value'] = array(
    'in_progress' => 'in_progress',
  );

  /* Display: All assigned tasks page */
  $handler = $view->new_display('page', 'All assigned tasks page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All assigned open tasks';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'php' => 'php',
    'title' => 'title',
    'field_project_ref' => 'field_project_ref',
    'field_priority_term' => 'field_priority_term',
    'field_task_status_term' => 'field_task_status_term',
    'field_progress_percent' => 'field_progress_percent',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'field_parent' => 'field_parent',
    'field_timetracking_button' => 'field_timetracking_button',
    'field_task_assigned_users' => 'field_task_assigned_users',
    'type' => 'type',
    'field_task_type_term' => 'field_task_type_term',
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
    'php' => array(
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
    'field_project_ref' => array(
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
    'field_task_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_progress_percent' => array(
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
    'field_parent' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_timetracking_button' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_assigned_users' => array(
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
    'field_task_type_term' => array(
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
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '#';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Task title';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return $row->title;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
return _erpal_basic_helper_render_title($row->nid, $row->type, $view, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_task_status_term']['settings'] = array(
    'click_to_edit' => 1,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_plain',
  );
  /* Field: Field: Progress */
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
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Timetracking button */
  $handler->display->display_options['fields']['field_timetracking_button']['id'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['table'] = 'field_data_field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['field'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['label'] = 'Timetracking';
  $handler->display->display_options['fields']['field_timetracking_button']['type'] = 'computed_field_unsanitized';
  /* Field: Content: Assigned To Users */
  $handler->display->display_options['fields']['field_task_assigned_users']['id'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['field'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_task_assigned_users']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search terms';
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
    8 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned To Users';
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
    8 => 0,
  );
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id_1']['id'] = 'field_task_assigned_users_target_id_1';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id_1']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id_1']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id_1']['group'] = 1;
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
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
    8 => 0,
  );
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  $handler->display->display_options['filters']['field_is_ticket_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_is_ticket_value']['expose']['operator_id'] = 'field_is_ticket_value_op';
  $handler->display->display_options['filters']['field_is_ticket_value']['expose']['label'] = 'Task / Ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['expose']['operator'] = 'field_is_ticket_value_op';
  $handler->display->display_options['filters']['field_is_ticket_value']['expose']['identifier'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_is_ticket_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_is_ticket_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['id'] = 'field_simple_process_status_value_1';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['group'] = 1;
  $handler->display->display_options['path'] = 'user/tasks/all';

  /* Display: My assigned tickets page */
  $handler = $view->new_display('page', 'My assigned tickets page', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My assigned open tickets';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '#';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Ticket title';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return $row->title;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
return _erpal_basic_helper_render_title($row->nid, $row->type, $view, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_task_status_term']['settings'] = array(
    'click_to_edit' => 1,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_plain',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Progress */
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
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Timetracking button */
  $handler->display->display_options['fields']['field_timetracking_button']['id'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['table'] = 'field_data_field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['field'] = 'field_timetracking_button';
  $handler->display->display_options['fields']['field_timetracking_button']['label'] = 'Timetracking';
  $handler->display->display_options['fields']['field_timetracking_button']['type'] = 'computed_field_unsanitized';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search terms';
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
    8 => 0,
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
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['id'] = 'field_simple_process_status_value_1';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value_1']['value'] = array(
    'in_progress' => 'in_progress',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['path'] = 'user/tickets';
  $translatables['assigned_tasks'] = array(
    t('Master'),
    t('My assigned open tasks'),
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
    t('author'),
    t('Content entity referenced from field_project_ref'),
    t('term from field_project_status_term'),
    t('Title'),
    t('Project'),
    t('Priority'),
    t('Deadline'),
    t('Timetracking button'),
    t('Priority (field_priority_term)'),
    t('My assigned tasks page'),
    t('#'),
    t('Task title'),
    t('Status'),
    t('Progress'),
    t('Updated date'),
    t('Parent'),
    t('Timetracking'),
    t('Type'),
    t('Search terms'),
    t('Assigned tasks block'),
    t('My assigned open tasks and tickets'),
    t('All assigned tasks page'),
    t('All assigned open tasks'),
    t('Assigned To Users'),
    t('Author'),
    t('Task / Ticket'),
    t('My assigned tickets page'),
    t('My assigned open tickets'),
    t('Ticket title'),
  );
  $export['assigned_tasks'] = $view;

  $view = new view();
  $view->name = 'budgets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'budget';
  $view->human_name = 'Budgets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access budgets view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'budget_id' => 'budget_id',
    'total_hours' => 'total_hours',
    'available_hours' => 'available_hours',
    'date_from' => 'date_from',
    'date_till' => 'date_till',
    'created' => 'created',
    'changed' => 'changed',
    'delete_budget' => 'delete_budget',
    'edit_budget' => 'edit_budget',
    'link_budget' => 'link_budget',
    'php' => 'php',
    'php_1' => 'php_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'budget_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'total_hours' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'available_hours' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'date_from' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'date_till' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'delete_budget' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'edit_budget' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'link_budget' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No budgets available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['id'] = 'reverse_field_budgets_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['table'] = 'budget';
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['field'] = 'reverse_field_budgets_field_collection_item';
  /* Field: Budget: Budget ID */
  $handler->display->display_options['fields']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['table'] = 'budget';
  $handler->display->display_options['fields']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['budget_id']['separator'] = '';
  /* Field: Budget: Total */
  $handler->display->display_options['fields']['total_hours']['id'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['table'] = 'budget';
  $handler->display->display_options['fields']['total_hours']['field'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['label'] = 'Total hours';
  $handler->display->display_options['fields']['total_hours']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_hours']['precision'] = '2';
  /* Field: Budget: Available */
  $handler->display->display_options['fields']['available_hours']['id'] = 'available_hours';
  $handler->display->display_options['fields']['available_hours']['table'] = 'budget';
  $handler->display->display_options['fields']['available_hours']['field'] = 'available_hours';
  $handler->display->display_options['fields']['available_hours']['label'] = 'Available hours';
  $handler->display->display_options['fields']['available_hours']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['available_hours']['precision'] = '2';
  /* Field: Budget: Date from */
  $handler->display->display_options['fields']['date_from']['id'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['table'] = 'budget';
  $handler->display->display_options['fields']['date_from']['field'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['label'] = 'Valid from';
  $handler->display->display_options['fields']['date_from']['date_format'] = 'erpal_date';
  /* Field: Budget: Date till */
  $handler->display->display_options['fields']['date_till']['id'] = 'date_till';
  $handler->display->display_options['fields']['date_till']['table'] = 'budget';
  $handler->display->display_options['fields']['date_till']['field'] = 'date_till';
  $handler->display->display_options['fields']['date_till']['label'] = 'Valid to';
  $handler->display->display_options['fields']['date_till']['date_format'] = 'erpal_date';
  /* Field: Budget: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'budget';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Budget: Date updated */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'budget';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Subject';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo _erpal_projects_helper_budget_view_subject($row->budget_id); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Project';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php echo _erpal_projects_helper_budget_view_project($row->budget_id); ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Budget: Link */
  $handler->display->display_options['fields']['link_budget']['id'] = 'link_budget';
  $handler->display->display_options['fields']['link_budget']['table'] = 'budget';
  $handler->display->display_options['fields']['link_budget']['field'] = 'link_budget';
  /* Field: Budget: Edit Link */
  $handler->display->display_options['fields']['edit_budget']['id'] = 'edit_budget';
  $handler->display->display_options['fields']['edit_budget']['table'] = 'budget';
  $handler->display->display_options['fields']['edit_budget']['field'] = 'edit_budget';
  $handler->display->display_options['fields']['edit_budget']['label'] = 'Edit';
  /* Field: Budget: Delete Link */
  $handler->display->display_options['fields']['delete_budget']['id'] = 'delete_budget';
  $handler->display->display_options['fields']['delete_budget']['table'] = 'budget';
  $handler->display->display_options['fields']['delete_budget']['field'] = 'delete_budget';
  $handler->display->display_options['fields']['delete_budget']['label'] = 'Delete';
  /* Sort criterion: Budget: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'budget';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Budget: Date updated */
  $handler->display->display_options['filters']['changed']['id'] = 'changed';
  $handler->display->display_options['filters']['changed']['table'] = 'budget';
  $handler->display->display_options['filters']['changed']['field'] = 'changed';
  $handler->display->display_options['filters']['changed']['operator'] = 'between';
  $handler->display->display_options['filters']['changed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['operator_id'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['label'] = 'Changed';
  $handler->display->display_options['filters']['changed']['expose']['operator'] = 'changed_op';
  $handler->display->display_options['filters']['changed']['expose']['identifier'] = 'changed';
  $handler->display->display_options['filters']['changed']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['changed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['changed']['form_type'] = 'date_popup';
  /* Filter criterion: Budget: Date created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'budget';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['created']['form_type'] = 'date_popup';
  /* Filter criterion: Budget: Date from */
  $handler->display->display_options['filters']['date_from']['id'] = 'date_from';
  $handler->display->display_options['filters']['date_from']['table'] = 'budget';
  $handler->display->display_options['filters']['date_from']['field'] = 'date_from';
  $handler->display->display_options['filters']['date_from']['operator'] = 'between';
  $handler->display->display_options['filters']['date_from']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_from']['expose']['operator_id'] = 'date_from_op';
  $handler->display->display_options['filters']['date_from']['expose']['label'] = 'Valid from';
  $handler->display->display_options['filters']['date_from']['expose']['operator'] = 'date_from_op';
  $handler->display->display_options['filters']['date_from']['expose']['identifier'] = 'date_from';
  $handler->display->display_options['filters']['date_from']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_from']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['date_from']['form_type'] = 'date_popup';
  /* Filter criterion: Budget: Date till */
  $handler->display->display_options['filters']['date_till']['id'] = 'date_till';
  $handler->display->display_options['filters']['date_till']['table'] = 'budget';
  $handler->display->display_options['filters']['date_till']['field'] = 'date_till';
  $handler->display->display_options['filters']['date_till']['operator'] = 'between';
  $handler->display->display_options['filters']['date_till']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_till']['expose']['operator_id'] = 'date_till_op';
  $handler->display->display_options['filters']['date_till']['expose']['label'] = 'Valid till';
  $handler->display->display_options['filters']['date_till']['expose']['operator'] = 'date_till_op';
  $handler->display->display_options['filters']['date_till']['expose']['identifier'] = 'date_till';
  $handler->display->display_options['filters']['date_till']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_till']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['date_till']['form_type'] = 'date_popup';

  /* Display: All budgets overview */
  $handler = $view->new_display('panel_pane', 'All budgets overview', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Budgets by node pane */
  $handler = $view->new_display('panel_pane', 'Budgets by node pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'total_hours' => 'total_hours',
    'available_hours' => 'available_hours',
    'date_from' => 'date_from',
    'date_till' => 'date_till',
    'link_budget' => 'link_budget',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'total_hours' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'available_hours' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'date_from' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'date_till' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'link_budget' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['id'] = 'reverse_field_budgets_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['table'] = 'budget';
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['field'] = 'reverse_field_budgets_field_collection_item';
  /* Relationship: Field collection item: Entity with the Pricing (field_pricing) */
  $handler->display->display_options['relationships']['field_pricing_node']['id'] = 'field_pricing_node';
  $handler->display->display_options['relationships']['field_pricing_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_pricing_node']['field'] = 'field_pricing_node';
  $handler->display->display_options['relationships']['field_pricing_node']['relationship'] = 'reverse_field_budgets_field_collection_item';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Budget: Total */
  $handler->display->display_options['fields']['total_hours']['id'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['table'] = 'budget';
  $handler->display->display_options['fields']['total_hours']['field'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['label'] = 'Total hours';
  $handler->display->display_options['fields']['total_hours']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_hours']['precision'] = '2';
  /* Field: Budget: Available */
  $handler->display->display_options['fields']['available_hours']['id'] = 'available_hours';
  $handler->display->display_options['fields']['available_hours']['table'] = 'budget';
  $handler->display->display_options['fields']['available_hours']['field'] = 'available_hours';
  $handler->display->display_options['fields']['available_hours']['label'] = 'Available hours';
  $handler->display->display_options['fields']['available_hours']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['available_hours']['precision'] = '2';
  /* Field: Budget: Date from */
  $handler->display->display_options['fields']['date_from']['id'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['table'] = 'budget';
  $handler->display->display_options['fields']['date_from']['field'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['label'] = 'Valid from';
  $handler->display->display_options['fields']['date_from']['date_format'] = 'erpal_date';
  /* Field: Budget: Date till */
  $handler->display->display_options['fields']['date_till']['id'] = 'date_till';
  $handler->display->display_options['fields']['date_till']['table'] = 'budget';
  $handler->display->display_options['fields']['date_till']['field'] = 'date_till';
  $handler->display->display_options['fields']['date_till']['label'] = 'Valid to';
  $handler->display->display_options['fields']['date_till']['date_format'] = 'erpal_date';
  /* Field: Budget: Link */
  $handler->display->display_options['fields']['link_budget']['id'] = 'link_budget';
  $handler->display->display_options['fields']['link_budget']['table'] = 'budget';
  $handler->display->display_options['fields']['link_budget']['field'] = 'link_budget';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Budget: Date from */
  $handler->display->display_options['sorts']['date_from']['id'] = 'date_from';
  $handler->display->display_options['sorts']['date_from']['table'] = 'budget';
  $handler->display->display_options['sorts']['date_from']['field'] = 'date_from';
  $handler->display->display_options['sorts']['date_from']['order'] = 'DESC';
  /* Sort criterion: Budget: Date till */
  $handler->display->display_options['sorts']['date_till']['id'] = 'date_till';
  $handler->display->display_options['sorts']['date_till']['table'] = 'budget';
  $handler->display->display_options['sorts']['date_till']['field'] = 'date_till';
  $handler->display->display_options['sorts']['date_till']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_pricing_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'empty';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.node',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['budgets'] = array(
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
    t('No budgets available.'),
    t('Field collection item referencing budget from field_budgets'),
    t('Budget ID'),
    t('.'),
    t('Total hours'),
    t(','),
    t('Available hours'),
    t('Valid from'),
    t('Valid to'),
    t('Date created'),
    t('Date updated'),
    t('Subject'),
    t('Project'),
    t('Link'),
    t('Edit'),
    t('Delete'),
    t('Changed'),
    t('Created'),
    t('Valid till'),
    t('All budgets overview'),
    t('View panes'),
    t('Budgets by node pane'),
    t('field_pricing'),
    t('All'),
  );
  $export['budgets'] = $view;

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
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_project_ref' => 'field_project_ref',
    'field_date' => 'field_date',
    'field_task_status_term' => 'field_task_status_term',
    'field_price' => 'field_price',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_project_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_task_status_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
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
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_project_ref' => 'field_project_ref',
    'field_date' => 'field_date',
    'field_project_status_term' => 'field_project_status_term',
    'field_task_status_term' => 'field_task_status_term',
    'field_price' => 'field_price',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_project_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_project_status_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_task_status_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_project_ref' => 'field_project_ref',
    'field_date' => 'field_date',
    'field_task_status_term' => 'field_task_status_term',
    'field_price' => 'field_price',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_project_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_task_status_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Project (field_project_ref) */
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
  $view->name = 'project_related_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Project related users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Belongs to project team */
  $handler->display->display_options['filters']['erpal_projects_relations']['id'] = 'erpal_projects_relations';
  $handler->display->display_options['filters']['erpal_projects_relations']['table'] = 'users';
  $handler->display->display_options['filters']['erpal_projects_relations']['field'] = 'erpal_projects_relations';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['project_related_users'] = array(
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
    t('Entity Reference'),
  );
  $export['project_related_users'] = $view;

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
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['label'] = 'customer';
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
  $handler->display->display_options['fields']['field_customer_ref']['type'] = 'entityreference_typed_label';
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
  /* Field: Content: Projects quick links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'node';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Quick links';
  $handler->display->display_options['fields']['operations']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
  /* Field: Content: Projects quick links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'node';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Quick links';
  $handler->display->display_options['fields']['operations']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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

  /* Display: Projects by user pane */
  $handler = $view->new_display('panel_pane', 'Projects by user pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Project team (field_project_team) */
  $handler->display->display_options['relationships']['field_project_team_value']['id'] = 'field_project_team_value';
  $handler->display->display_options['relationships']['field_project_team_value']['table'] = 'field_data_field_project_team';
  $handler->display->display_options['relationships']['field_project_team_value']['field'] = 'field_project_team_value';
  $handler->display->display_options['relationships']['field_project_team_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['relationship'] = 'field_project_team_value';
  /* Relationship: Content: Status (field_project_status_term) */
  $handler->display->display_options['relationships']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['label'] = 'customer';
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
    'erpal_project' => 'erpal_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_user_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;

  /* Display: Closed Projects pane */
  $handler = $view->new_display('panel_pane', 'Closed Projects pane', 'panel_pane_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Status (field_project_status_term) */
  $handler->display->display_options['relationships']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['label'] = 'project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['label'] = 'Customer';
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'completed' => 'completed',
    'aborted' => 'aborted',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: In progress Projects pane */
  $handler = $view->new_display('panel_pane', 'In progress Projects pane', 'panel_pane_5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Status (field_project_status_term) */
  $handler->display->display_options['relationships']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['label'] = 'project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['label'] = 'customer';
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: In progress projects by user pane */
  $handler = $view->new_display('panel_pane', 'In progress projects by user pane', 'panel_pane_6');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Project team (field_project_team) */
  $handler->display->display_options['relationships']['field_project_team_value']['id'] = 'field_project_team_value';
  $handler->display->display_options['relationships']['field_project_team_value']['table'] = 'field_data_field_project_team';
  $handler->display->display_options['relationships']['field_project_team_value']['field'] = 'field_project_team_value';
  $handler->display->display_options['relationships']['field_project_team_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['relationship'] = 'field_project_team_value';
  /* Relationship: Content: Status (field_project_status_term) */
  $handler->display->display_options['relationships']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['label'] = 'customer';
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
    'erpal_project' => 'erpal_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_user_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;

  /* Display: Closed projects by user pane */
  $handler = $view->new_display('panel_pane', 'Closed projects by user pane', 'panel_pane_7');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Project team (field_project_team) */
  $handler->display->display_options['relationships']['field_project_team_value']['id'] = 'field_project_team_value';
  $handler->display->display_options['relationships']['field_project_team_value']['table'] = 'field_data_field_project_team';
  $handler->display->display_options['relationships']['field_project_team_value']['field'] = 'field_project_team_value';
  $handler->display->display_options['relationships']['field_project_team_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_target_id']['id'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['table'] = 'field_data_field_user';
  $handler->display->display_options['relationships']['field_user_target_id']['field'] = 'field_user_target_id';
  $handler->display->display_options['relationships']['field_user_target_id']['relationship'] = 'field_project_team_value';
  /* Relationship: Content: Status (field_project_status_term) */
  $handler->display->display_options['relationships']['field_project_status_term_tid']['id'] = 'field_project_status_term_tid';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['table'] = 'field_data_field_project_status_term';
  $handler->display->display_options['relationships']['field_project_status_term_tid']['field'] = 'field_project_status_term_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['label'] = 'customer';
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
    'erpal_project' => 'erpal_project',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_user_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_project_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'completed' => 'completed',
    'aborted' => 'aborted',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;
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
    t('customer'),
    t('Title'),
    t('Customer'),
    t('Status'),
    t('Priority'),
    t('Project starts'),
    t('Project ends'),
    t('Quick links'),
    t('Projects by activity pane'),
    t('[title] ([field_activity_status_term])'),
    t('All'),
    t('View panes'),
    t('Projects pane'),
    t('Search Terms'),
    t('Projects by user pane'),
    t('field collection item from field_project_team'),
    t('User entity referenced from field_user'),
    t('term from field_project_status_term'),
    t('Closed Projects pane'),
    t('project_status_term'),
    t('In progress Projects pane'),
    t('In progress projects by user pane'),
    t('Closed projects by user pane'),
  );
  $export['projects'] = $view;

  $view = new view();
  $view->name = 'task_revisions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Task revisions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
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
    'timestamp' => 'timestamp',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
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
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No history found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  /* Field: Content revision: Compare */
  $handler->display->display_options['fields']['diff_views_radio']['id'] = 'diff_views_radio';
  $handler->display->display_options['fields']['diff_views_radio']['table'] = 'node_revision';
  $handler->display->display_options['fields']['diff_views_radio']['field'] = 'diff_views_radio';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'erpal_date_time';
  /* Field: Content (historical data): Priority */
  $handler->display->display_options['fields']['field_priority_term-revision_id']['id'] = 'field_priority_term-revision_id';
  $handler->display->display_options['fields']['field_priority_term-revision_id']['table'] = 'field_revision_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term-revision_id']['field'] = 'field_priority_term-revision_id';
  $handler->display->display_options['fields']['field_priority_term-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content (historical data): Type */
  $handler->display->display_options['fields']['field_task_type_term-revision_id']['id'] = 'field_task_type_term-revision_id';
  $handler->display->display_options['fields']['field_task_type_term-revision_id']['table'] = 'field_revision_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term-revision_id']['field'] = 'field_task_type_term-revision_id';
  $handler->display->display_options['fields']['field_task_type_term-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content (historical data): Status */
  $handler->display->display_options['fields']['field_task_status_term-revision_id']['id'] = 'field_task_status_term-revision_id';
  $handler->display->display_options['fields']['field_task_status_term-revision_id']['table'] = 'field_revision_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term-revision_id']['field'] = 'field_task_status_term-revision_id';
  $handler->display->display_options['fields']['field_task_status_term-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field (historical data): Progress */
  $handler->display->display_options['fields']['field_progress_percent-revision_id']['id'] = 'field_progress_percent-revision_id';
  $handler->display->display_options['fields']['field_progress_percent-revision_id']['table'] = 'field_revision_field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent-revision_id']['field'] = 'field_progress_percent-revision_id';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Content (historical data): Assigned To Users */
  $handler->display->display_options['fields']['field_task_assigned_users-revision_id']['id'] = 'field_task_assigned_users-revision_id';
  $handler->display->display_options['fields']['field_task_assigned_users-revision_id']['table'] = 'field_revision_field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users-revision_id']['field'] = 'field_task_assigned_users-revision_id';
  $handler->display->display_options['fields']['field_task_assigned_users-revision_id']['label'] = 'Assigned users';
  $handler->display->display_options['fields']['field_task_assigned_users-revision_id']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_task_assigned_users-revision_id']['delta_offset'] = '0';
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );

  /* Display: Task revisions pane */
  $handler = $view->new_display('panel_pane', 'Task revisions pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['task_revisions'] = array(
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
    t('No history found'),
    t('revision user'),
    t('Get the actual content from a content revision.'),
    t('Vid'),
    t('Compare'),
    t('Task title'),
    t('Updated date'),
    t('Priority'),
    t('Type'),
    t('Status'),
    t('Progress'),
    t('Name'),
    t('Assigned users'),
    t('All'),
    t('Task revisions pane'),
    t('View panes'),
  );
  $export['task_revisions'] = $view;

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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'nid' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'title' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
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
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
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
  /* Filter criterion: Field: Project (field_project_ref) */
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  /* Relationship: Content: Priority (field_priority_term) */
  $handler->display->display_options['relationships']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['relationships']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['relationships']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  /* Relationship: Content: Type (field_task_type_term) */
  $handler->display->display_options['relationships']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  /* Relationship: Content: Status (field_task_status_term) */
  $handler->display->display_options['relationships']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Progress */
  $handler->display->display_options['fields']['field_progress_percent']['id'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['table'] = 'field_data_field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['field'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['label'] = '';
  $handler->display->display_options['fields']['field_progress_percent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_progress_percent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_progress_percent']['settings'] = array(
    'click_to_edit' => 1,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'list_default',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Direct time info';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return _erpal_projects_helper_direct_time_information($row->nid);
';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$class = $value[\'alert\'] ? \'alert\' : false;
print "<span class=\'".$class."\'>".$value[\'summed_time\']."/".$value[\'estimation\']."</span>";
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
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
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['fields']['field_term_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_1']['id'] = 'field_term_image_1';
  $handler->display->display_options['fields']['field_term_image_1']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['relationship'] = 'field_task_type_term_tid';
  $handler->display->display_options['fields']['field_term_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_1']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_2']['id'] = 'field_term_image_2';
  $handler->display->display_options['fields']['field_term_image_2']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['relationship'] = 'field_priority_term_tid';
  $handler->display->display_options['fields']['field_term_image_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_2']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_2']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span></span><span class="tree-field date">[field_date]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['erpal_subtasks']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['argument_input'] = array(
    'erpal_subtasks' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Task: Task subtasks',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

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
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  /* Relationship: Content: Priority (field_priority_term) */
  $handler->display->display_options['relationships']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['relationships']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['relationships']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  /* Relationship: Content: Status (field_task_status_term) */
  $handler->display->display_options['relationships']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  /* Relationship: Content: Type (field_task_type_term) */
  $handler->display->display_options['relationships']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
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
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Field: Progress */
  $handler->display->display_options['fields']['field_progress_percent']['id'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['table'] = 'field_data_field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['field'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['exclude'] = TRUE;
  /* Field: Content: Weight */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Direct time info';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return _erpal_projects_helper_direct_time_information($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$class = $value[\'alert\'] ? \'alert\' : false;
print "<span class=\'".$class."\'>".$value[\'summed_time\']."/".$value[\'estimation\']."</span>";
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['fields']['field_term_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_1']['id'] = 'field_term_image_1';
  $handler->display->display_options['fields']['field_term_image_1']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['relationship'] = 'field_task_type_term_tid';
  $handler->display->display_options['fields']['field_term_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_1']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_2']['id'] = 'field_term_image_2';
  $handler->display->display_options['fields']['field_term_image_2']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['relationship'] = 'field_priority_term_tid';
  $handler->display->display_options['fields']['field_term_image_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_2']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_2']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span><span class="tree-field date">[field_date]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['erpal_subtasks']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Task title';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return $row->title;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
return _erpal_basic_helper_render_title($row->nid, $row->type, $view, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '3';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
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
  /* Field: Content: Assigned To Users */
  $handler->display->display_options['fields']['field_task_assigned_users']['id'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['field'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['label'] = 'Assigned';
  $handler->display->display_options['fields']['field_task_assigned_users']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_task_assigned_users']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
    'php' => 'php',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_task_type_term' => 'field_task_type_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'name' => 'name',
    'field_parent' => 'field_parent',
    'field_task_assigned_users' => 'field_task_assigned_users',
    'type' => 'type',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
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
    'field_task_assigned_users' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Task title';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return $row->title;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
return _erpal_basic_helper_render_title($row->nid_1, $row->type, $view, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_parent']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Assigned To Users */
  $handler->display->display_options['fields']['field_task_assigned_users']['id'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['field'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['label'] = 'Assigned';
  $handler->display->display_options['fields']['field_task_assigned_users']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_task_assigned_users']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Project (field_project_ref) */
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 1;
  /* Filter criterion: Content: Assigned to users of project team */
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['id'] = 'erpal_projects_relations_assigned';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['field'] = 'erpal_projects_relations_assigned';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['value'] = array(
    6 => '6',
    8 => '8',
    7 => '7',
    1 => '1',
  );
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['exposed'] = TRUE;
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['operator_id'] = 'erpal_projects_relations_assigned_op';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['operator'] = 'erpal_projects_relations_assigned_op';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['identifier'] = 'erpal_projects_relations_assigned';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
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
  $handler->display->display_options['fields']['field_parent']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Project (field_project_ref) */
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
  /* Filter criterion: Field: Category (field_project_tags) */
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

  /* Display: Task by project pane gantt */
  $handler = $view->new_display('panel_pane', 'Task by project pane gantt', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Gantt';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks details';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'gantt';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['name_field'] = 'title';
  $handler->display->display_options['style_options']['date_field'] = 'field_date_1';
  $handler->display->display_options['style_options']['end_date_field'] = 'field_date_1';
  $handler->display->display_options['style_options']['progress_field'] = 'field_progress_percent';
  $handler->display->display_options['style_options']['project_id_field'] = 'field_project_ref';
  $handler->display->display_options['style_options']['project_date_field'] = 'field_date';
  $handler->display->display_options['style_options']['parent_id_field'] = 'field_parent_1';
  $handler->display->display_options['style_options']['predecessor_id_field'] = 'field_depends_on_tasks';
  $handler->display->display_options['style_options']['columns'] = array(
    '' => '',
    'field_task_type_term' => 'field_task_type_term',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
  );
  $handler->display->display_options['style_options']['task_type'] = 'erpal-task';
  $handler->display->display_options['style_options']['add_task'] = 1;
  $handler->display->display_options['style_options']['edit_task'] = 1;
  $handler->display->display_options['style_options']['scale'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['relationships']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['relationships']['field_parent_target_id']['field'] = 'field_parent_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  /* Relationship: Content: Priority (field_priority_term) */
  $handler->display->display_options['relationships']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['relationships']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['relationships']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  /* Relationship: Content: Type (field_task_type_term) */
  $handler->display->display_options['relationships']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  /* Relationship: Content: Status (field_task_status_term) */
  $handler->display->display_options['relationships']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field: Progress */
  $handler->display->display_options['fields']['field_progress_percent']['id'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['table'] = 'field_data_field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['field'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['label'] = '';
  $handler->display->display_options['fields']['field_progress_percent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_progress_percent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_progress_percent']['settings'] = array(
    'click_to_edit' => 1,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'list_default',
  );
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
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['fields']['field_term_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_1']['id'] = 'field_term_image_1';
  $handler->display->display_options['fields']['field_term_image_1']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['relationship'] = 'field_task_type_term_tid';
  $handler->display->display_options['fields']['field_term_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_1']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_2']['id'] = 'field_term_image_2';
  $handler->display->display_options['fields']['field_term_image_2']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['relationship'] = 'field_priority_term_tid';
  $handler->display->display_options['fields']['field_term_image_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_2']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_2']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Depends on tasks */
  $handler->display->display_options['fields']['field_depends_on_tasks']['id'] = 'field_depends_on_tasks';
  $handler->display->display_options['fields']['field_depends_on_tasks']['table'] = 'field_data_field_depends_on_tasks';
  $handler->display->display_options['fields']['field_depends_on_tasks']['field'] = 'field_depends_on_tasks';
  $handler->display->display_options['fields']['field_depends_on_tasks']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_depends_on_tasks']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_depends_on_tasks']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_depends_on_tasks']['delta_offset'] = '0';
  /* Field: Content: Estimated time */
  $handler->display->display_options['fields']['field_estimated_time']['id'] = 'field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['table'] = 'field_data_field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['field'] = 'field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_parent_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_parent_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_parent_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 0,
  );
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['fields']['field_date']['label'] = 'Project date';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['label'] = 'Period task';
  $handler->display->display_options['fields']['field_date_1']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['erpal_subtasks']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value']['id'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_ticket_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['argument_input'] = array(
    'erpal_subtasks' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Task: Task subtasks',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tasks by project Entity Reference */
  $handler = $view->new_display('entityreference', 'Tasks by project Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'nid' => 'nid',
    'field_project_ref' => 0,
    'field_task_type_term' => 0,
    'field_task_status_term' => 0,
    'field_priority_term' => 0,
    'field_estimated_time' => 0,
    'field_parent_1' => 0,
    'edit_node' => 0,
    'field_parent' => 0,
    'field_weight' => 0,
    'type' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
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
  $translatables['tasks'] = array(
    t('Master'),
    t('more'),
    t('Filter'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Advanced options'),
    t('Select any filter and click on Apply to see results'),
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
    t('User entity referenced from field_task_assigned_users'),
    t('term from field_priority_term'),
    t('term from field_task_type_term'),
    t('term from field_task_status_term'),
    t('Direct time info'),
    t('Period'),
    t('Term image'),
    t('<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span></span><span class="tree-field date">[field_date]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>'),
    t('All'),
    t('ID'),
    t('Priority (field_priority_term)'),
    t('View panes'),
    t('Subtasks Tree'),
    t('Subtasks (tree)'),
    t('Progress'),
    t('<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span><span class="tree-field date">[field_date]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>'),
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
    t('Task by project pane gantt'),
    t('Gantt'),
    t('Content entity referenced from field_project_ref'),
    t('<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>'),
    t('Depends on tasks'),
    t('Estimated time'),
    t('Project date'),
    t('Period task'),
    t('Tasks by project Entity Reference'),
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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'title' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
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
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
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
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  /* Relationship: Content: Priority (field_priority_term) */
  $handler->display->display_options['relationships']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['relationships']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['relationships']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  /* Relationship: Content: Status (field_task_status_term) */
  $handler->display->display_options['relationships']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  /* Relationship: Content: Type (field_task_type_term) */
  $handler->display->display_options['relationships']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['type'] = 'entityreference_typed_label';
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
  $handler->display->display_options['fields']['field_parent_1']['type'] = 'entityreference_typed_label';
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  /* Relationship: Content: Priority (field_priority_term) */
  $handler->display->display_options['relationships']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['relationships']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['relationships']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  /* Relationship: Content: Type (field_task_type_term) */
  $handler->display->display_options['relationships']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  /* Relationship: Content: Status (field_task_status_term) */
  $handler->display->display_options['relationships']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Direct time info';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return _erpal_projects_helper_direct_time_information($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$class = $value[\'alert\'] ? \'alert\' : false;
print "<span class=\'".$class."\'>".$value[\'summed_time\']."/".$value[\'estimation\']."</span>";
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field: Progress */
  $handler->display->display_options['fields']['field_progress_percent']['id'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['table'] = 'field_data_field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['field'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['exclude'] = TRUE;
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
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['fields']['field_term_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_1']['id'] = 'field_term_image_1';
  $handler->display->display_options['fields']['field_term_image_1']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['relationship'] = 'field_task_type_term_tid';
  $handler->display->display_options['fields']['field_term_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_1']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_2']['id'] = 'field_term_image_2';
  $handler->display->display_options['fields']['field_term_image_2']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['relationship'] = 'field_priority_term_tid';
  $handler->display->display_options['fields']['field_term_image_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_2']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_2']['settings'] = array(
    'image_style' => 'icon16x16',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['erpal_subtasks']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 2;
  $handler->display->display_options['filters']['field_is_ticket_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value_1']['id'] = 'field_is_ticket_value_1';
  $handler->display->display_options['filters']['field_is_ticket_value_1']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value_1']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['filters']['field_is_ticket_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_is_ticket_value_1']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'erpal_subtasks' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Task: Task subtasks',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

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
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  /* Relationship: Content: Priority (field_priority_term) */
  $handler->display->display_options['relationships']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['relationships']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['relationships']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  /* Relationship: Content: Status (field_task_status_term) */
  $handler->display->display_options['relationships']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['relationships']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  /* Relationship: Content: Type (field_task_type_term) */
  $handler->display->display_options['relationships']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['relationships']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['label'] = '';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_type_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['label'] = '';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['label'] = '';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Direct time info';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return _erpal_projects_helper_direct_time_information($row->nid);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$class = $value[\'alert\'] ? \'alert\' : false;
print "<span class=\'".$class."\'>".$value[\'summed_time\']."/".$value[\'estimation\']."</span>";
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Weight */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Progress */
  $handler->display->display_options['fields']['field_progress_percent']['id'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['table'] = 'field_data_field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['field'] = 'field_progress_percent';
  $handler->display->display_options['fields']['field_progress_percent']['label'] = '';
  $handler->display->display_options['fields']['field_progress_percent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_progress_percent']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image']['id'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image']['relationship'] = 'field_task_status_term_tid';
  $handler->display->display_options['fields']['field_term_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_1']['id'] = 'field_term_image_1';
  $handler->display->display_options['fields']['field_term_image_1']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_1']['relationship'] = 'field_task_type_term_tid';
  $handler->display->display_options['fields']['field_term_image_1']['label'] = '';
  $handler->display->display_options['fields']['field_term_image_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Term image */
  $handler->display->display_options['fields']['field_term_image_2']['id'] = 'field_term_image_2';
  $handler->display->display_options['fields']['field_term_image_2']['table'] = 'field_data_field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['field'] = 'field_term_image';
  $handler->display->display_options['fields']['field_term_image_2']['relationship'] = 'field_priority_term_tid';
  $handler->display->display_options['fields']['field_term_image_2']['label'] = '';
  $handler->display->display_options['fields']['field_term_image_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_term_image_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_term_image_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_term_image_2']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_term_image_2']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = '<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['erpal_subtasks']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  $handler->display->display_options['filters']['field_is_ticket_value']['group'] = 2;
  $handler->display->display_options['filters']['field_is_ticket_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: Is ticket (field_is_ticket) */
  $handler->display->display_options['filters']['field_is_ticket_value_1']['id'] = 'field_is_ticket_value_1';
  $handler->display->display_options['filters']['field_is_ticket_value_1']['table'] = 'field_data_field_is_ticket';
  $handler->display->display_options['filters']['field_is_ticket_value_1']['field'] = 'field_is_ticket_value';
  $handler->display->display_options['filters']['field_is_ticket_value_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['filters']['field_is_ticket_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_ticket_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_is_ticket_value_1']['reduce_duplicates'] = TRUE;
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
    'php' => 'php',
    'title' => 'title',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_task_type_term' => 'field_task_type_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'name' => 'name',
    'title_1' => 'title_1',
    'field_task_assigned_users' => 'field_task_assigned_users',
    'type' => 'type',
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
    'php' => array(
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
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_assigned_users' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
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
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '#';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'ticket title';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return $row->title;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
return _erpal_basic_helper_render_title($row->nid, $row->type, $view, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ticket title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
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
  /* Field: Content: Assigned To Users */
  $handler->display->display_options['fields']['field_task_assigned_users']['id'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['field'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['label'] = 'Assigned';
  $handler->display->display_options['fields']['field_task_assigned_users']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_task_assigned_users']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
    'php' => 'php',
    'title' => 'title',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_task_type_term' => 'field_task_type_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'name' => 'name',
    'field_parent' => 'field_parent',
    'field_task_assigned_users' => 'field_task_assigned_users',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
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
    'field_task_assigned_users' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Ticket title';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return $row->title;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
return _erpal_basic_helper_render_title($row->nid_1, $row->type, $view, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '2';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Ticket title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status_term']['id'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['field'] = 'field_task_status_term';
  $handler->display->display_options['fields']['field_task_status_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_task_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Priority */
  $handler->display->display_options['fields']['field_priority_term']['id'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['field'] = 'field_priority_term';
  $handler->display->display_options['fields']['field_priority_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_priority_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_parent']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_parent']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Assigned To Users */
  $handler->display->display_options['fields']['field_task_assigned_users']['id'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['field'] = 'field_task_assigned_users';
  $handler->display->display_options['fields']['field_task_assigned_users']['label'] = 'Assigned';
  $handler->display->display_options['fields']['field_task_assigned_users']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_task_assigned_users']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Project (field_project_ref) */
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
  /* Filter criterion: Field: Category (field_project_tags) */
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
  /* Filter criterion: Content: Assigned to users of project team */
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['id'] = 'erpal_projects_relations_assigned';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['field'] = 'erpal_projects_relations_assigned';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['exposed'] = TRUE;
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['operator_id'] = 'erpal_projects_relations_assigned_op';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['operator'] = 'erpal_projects_relations_assigned_op';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['identifier'] = 'erpal_projects_relations_assigned';
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['erpal_projects_relations_assigned']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
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
    t('Advanced options'),
    t('Select any filter and click on Apply to see results'),
    t('No tasks available'),
    t('Content entity referenced from field_parent'),
    t('author'),
    t('User entity referenced from field_task_assigned_users'),
    t('term from field_priority_term'),
    t('term from field_task_status_term'),
    t('term from field_task_type_term'),
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
    t('Direct time info'),
    t('Progress'),
    t('Term image'),
    t('<img src="[field_term_image]" alt="[field_task_status_term]" title="[field_task_status_term]" /> <span class="tree-field title">[title]</span><span class="tree-field username">[name]</span><span class="tree-field estimation">[php]</span><span class="tree-field percent">[field_progress_percent]</span><span class="tree-icons-left"><img src="[field_term_image_2]" alt="[field_priority_term]" title="[field_priority_term]" /><img src="[field_term_image_1]" alt="[field_task_type_term]" title="[field_task_type_term]" /></span>'),
    t('All'),
    t('Priority (field_priority_term)'),
    t('View panes'),
    t('Subtickets Tree'),
    t('Subtickets (tree)'),
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
    t('ticket title'),
    t('Ticket title'),
    t('Submitted'),
    t('Last update'),
    t('Deadline'),
    t('Author'),
    t('Tickets by project pane list'),
    t('List'),
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
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::erpal_project_release_add_tasks_to_release' => array(
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
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete timetracking',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
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
    'action::erpal_project_release_remove_tasks_from_release' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
  $handler->display->display_options['fields']['description']['label'] = 'Subject';
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
  $handler->display->display_options['fields']['duration']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['duration']['precision'] = '2';
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
  /* Field: Field: Category */
  $handler->display->display_options['fields']['field_project_tags']['id'] = 'field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['field'] = 'field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_project_tags']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'button',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
  );
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
  $handler->display->display_options['fields']['duration']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['duration']['precision'] = '2';
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
  $handler->display->display_options['fields']['description']['label'] = 'Subject';
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
    t('- Choose an operation -'),
    t('Delete timetracking'),
    t('Timetracking ID'),
    t('.'),
    t(','),
    t('Changed'),
    t('Subject'),
    t('start'),
    t('end'),
    t('Duration'),
    t('User'),
    t('Category'),
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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_date_time' => 'field_date_time',
    'created' => 'created',
    'field_timetracking_duration' => 'field_timetracking_duration',
    'field_billing_duration' => 'field_billing_duration',
    'php' => 'php',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'name' => 'name',
    'field_project_tags' => 'field_project_tags',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_date_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_timetracking_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_billing_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_project_tags' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
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
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::erpal_project_release_add_tasks_to_release' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_project_release_remove_tasks_from_release' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date and time */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['label'] = 'Datum';
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
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
  /* Field: Field: Category */
  $handler->display->display_options['fields']['field_project_tags']['id'] = 'field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['field'] = 'field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_date_time_value']['expose']['label'] = 'Date and time -  start date (field_date_time)';
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
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Datum';
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
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_time_value']['default_date'] = 'first day of this month';
  $handler->display->display_options['filters']['field_date_time_value']['default_to_date'] = 'last day of this month';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: Field: Category (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Category';
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Task type';
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
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';

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
  /* Contextual filter: Field: Project (field_project_ref) */
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
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_date_time' => 'field_date_time',
    'created' => 'created',
    'field_timetracking_duration' => 'field_timetracking_duration',
    'field_billing_duration' => 'field_billing_duration',
    'php' => 'php',
    'title_2' => 'title_2',
    'name' => 'name',
    'field_project_tags' => 'field_project_tags',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_date_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_timetracking_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_billing_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title_2' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_project_tags' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Price';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo _erpal_projects_helper_timetracking_view_field_billable($data->nid);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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
  /* Field: Field: Category */
  $handler->display->display_options['fields']['field_project_tags']['id'] = 'field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['field'] = 'field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_action'] = 'default';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['erpal_subtasks']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['types'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['fail'] = 'empty';
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
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Datum';
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
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
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
  /* Filter criterion: Field: Category (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Category';
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Task: Task subtasks */
  $handler->display->display_options['filters']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['filters']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['filters']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['filters']['erpal_subtasks']['value'] = '0';
  $handler->display->display_options['filters']['erpal_subtasks']['group'] = 1;
  $handler->display->display_options['filters']['erpal_subtasks']['exposed'] = TRUE;
  $handler->display->display_options['filters']['erpal_subtasks']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['erpal_subtasks']['expose']['label'] = 'Show subtasks';
  $handler->display->display_options['filters']['erpal_subtasks']['expose']['operator'] = 'erpal_subtasks_op';
  $handler->display->display_options['filters']['erpal_subtasks']['expose']['identifier'] = 'erpal_subtasks';
  $handler->display->display_options['filters']['erpal_subtasks']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['erpal_subtasks']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_date_time' => 'field_date_time',
    'created' => 'created',
    'field_timetracking_duration' => 'field_timetracking_duration',
    'field_billing_duration' => 'field_billing_duration',
    'php' => 'php',
    'field_timetracking_subject' => 'field_timetracking_subject',
    'name' => 'name',
    'field_project_tags' => 'field_project_tags',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_date_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_timetracking_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_billing_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_timetracking_subject' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_project_tags' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::erpal_project_release_add_tasks_to_release' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_project_release_remove_tasks_from_release' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
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
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Price';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo _erpal_projects_helper_timetracking_view_field_billable($data->nid);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_timetracking_subject']['id'] = 'field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['field'] = 'field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['label'] = 'Task';
  $handler->display->display_options['fields']['field_timetracking_subject']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_timetracking_subject']['settings'] = array(
    'link' => 1,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: Field: Category */
  $handler->display->display_options['fields']['field_project_tags']['id'] = 'field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['field'] = 'field_project_tags';
  $handler->display->display_options['fields']['field_project_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Project (field_project_ref) */
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
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Datum';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_time_value']['default_date'] = 'first day of this month';
  $handler->display->display_options['filters']['field_date_time_value']['default_to_date'] = 'last day of this month';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['filters']['title_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_1']['group'] = 1;
  $handler->display->display_options['filters']['title_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Task';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
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
  /* Filter criterion: Field: Category (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Category';
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
    8 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Task type';
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
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
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
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  /* Relationship: Content: Pricing (field_pricing) */
  $handler->display->display_options['relationships']['field_pricing_value']['id'] = 'field_pricing_value';
  $handler->display->display_options['relationships']['field_pricing_value']['table'] = 'field_data_field_pricing';
  $handler->display->display_options['relationships']['field_pricing_value']['field'] = 'field_pricing_value';
  $handler->display->display_options['relationships']['field_pricing_value']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_pricing_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_budgets_target_id']['id'] = 'field_budgets_target_id';
  $handler->display->display_options['relationships']['field_budgets_target_id']['table'] = 'field_data_field_budgets';
  $handler->display->display_options['relationships']['field_budgets_target_id']['field'] = 'field_budgets_target_id';
  $handler->display->display_options['relationships']['field_budgets_target_id']['relationship'] = 'field_pricing_value';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Budget (field_budget) */
  $handler->display->display_options['arguments']['field_budget_target_id']['id'] = 'field_budget_target_id';
  $handler->display->display_options['arguments']['field_budget_target_id']['table'] = 'field_data_field_budget';
  $handler->display->display_options['arguments']['field_budget_target_id']['field'] = 'field_budget_target_id';
  $handler->display->display_options['arguments']['field_budget_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_budget_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_budget_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_budget_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_budget_target_id']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Datum';
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
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
    11 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
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
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Field: Category (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Task categories';
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
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['filters']['field_task_type_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Task type';
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
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['argument_input'] = array(
    'field_budget_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Budget (field_budget)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
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
    t('- Choose an operation -'),
    t('Title'),
    t('Datum'),
    t('Created'),
    t('Duration'),
    t('Billing Duration'),
    t('Task'),
    t('Project'),
    t('User'),
    t('Category'),
    t('Date and time -  start date (field_date_time)'),
    t('Search Terms'),
    t('Task type'),
    t('field_project_ref'),
    t('All'),
    t('Timetrackings by task'),
    t('Content'),
    t('Date and time'),
    t('Price'),
    t('Show subtasks'),
    t('View panes'),
    t('Timetracking by project pane'),
    t('Timetracking title'),
    t('Budget timetrackings pane'),
    t('Content entity referenced from field_timetracking_subject'),
    t('field collection item from field_pricing'),
    t('budget entity referenced from field_budgets'),
    t('Content entity referenced from field_project_ref'),
    t('Task categories'),
  );
  $export['timetrackings'] = $view;

  return $export;
}
