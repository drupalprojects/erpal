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
  $handler->display->display_options['title'] = 'Projects';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access projects view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
echo _erpal_projects_helper_view_projects_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
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
  $handler->display->display_options['fields']['title']['label'] = '';
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
  $handler->display->display_options['filters']['field_project_status_term_tid']['vocabulary'] = 'project_status_terms';

  /* Display: Projects */
  $handler = $view->new_display('page', 'Projects', 'page');
  $handler->display->display_options['display_description'] = 'List of all projects';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
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
  $handler->display->display_options['path'] = 'projects/projects';

  /* Display: Projects by activity pane */
  $handler = $view->new_display('panel_pane', 'Projects by activity pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
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
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Tasks by project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  $handler->display->display_options['attach'] = array(
    0 => 'field_collection_item:field_budget_destination:field_budget_booking',
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
  $handler->display->display_options['title'] = 'Project tasks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'field_task_status_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_task_type_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'date_filter' => array(
      'bef_format' => 'bef_datepicker',
      'more_options' => array(
        'bef_filter_description' => '',
      ),
    ),
    'field_project_ref_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
    'field_task_assigned_users_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'bef_filter_description' => '',
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
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
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
    'field_data_field_date.field_date_value2' => 'field_data_field_date.field_date_value2',
  );
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

  /* Display: Tasks */
  $handler = $view->new_display('page', 'Tasks', 'page');
  $handler->display->display_options['display_description'] = 'A simple List with Tasks and task filters';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_project_ref' => 'field_project_ref',
    'field_task_type_term' => 'field_task_type_term',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_estimated_time' => 'field_estimated_time',
    'field_parent_1' => 'field_parent_1',
    'edit_node' => 'edit_node',
    'nid' => 'nid',
    'field_parent' => 'field_parent',
    'field_weight' => 'field_weight',
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
    ),
    'field_project_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_type_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_status_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_priority_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_estimated_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent_1' => array(
      'sortable' => 0,
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
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parent' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_weight' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['path'] = 'projects/tasks';

  /* Display: Task by project pane */
  $handler = $view->new_display('panel_pane', 'Task by project pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
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
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
    'field_data_field_date.field_date_value2' => 'field_data_field_date.field_date_value2',
  );
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

  /* Display: Task child view AJAX TOP */
  $handler = $view->new_display('panel_pane', 'Task child view AJAX TOP', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
    'field_data_field_date.field_date_value2' => 'field_data_field_date.field_date_value2',
  );
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

  /* Display: Subtasks */
  $handler = $view->new_display('panel_pane', 'Subtasks', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Subtasks';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
    'field_data_field_date.field_date_value2' => 'field_data_field_date.field_date_value2',
  );
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

  /* Display: Task by project pane */
  $handler = $view->new_display('panel_pane', 'Task by project pane', 'panel_pane_5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
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
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
    'field_data_field_date.field_date_value2' => 'field_data_field_date.field_date_value2',
  );
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

  /* Display: Tasks by ID */
  $handler = $view->new_display('panel_pane', 'Tasks by ID', 'panel_pane_6');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $export['tasks'] = $view;

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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
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
  /* Filter criterion: Content: Date -  start date (field_date_time) */
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
  /* Filter criterion: Content: Date -  start date (field_date_time) */
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
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
    'erpal_timetracking' => 'erpal_timetracking',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = '0';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  /* Filter criterion: Content: Date -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['group'] = '0';
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
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
  /* Filter criterion: Content: Date -  start date (field_date_time) */
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
  $export['timetrackings'] = $view;

  return $export;
}
