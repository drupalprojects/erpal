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

  $view = new view;
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
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
echo _erpal_projects_helper_view_projects_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No projects found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Project Status */
  $handler->display->display_options['fields']['field_project_status']['id'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['fields']['field_project_status']['field'] = 'field_project_status';
  $handler->display->display_options['fields']['field_project_status']['label'] = 'Status';
  $handler->display->display_options['fields']['field_project_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_status']['field_api_classes'] = 0;
  /* Field: Content: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_customer_ref']['field_api_classes'] = 0;
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
  /* Filter criterion: Content: Project Status (field_project_status) */
  $handler->display->display_options['filters']['field_project_status_value']['id'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['filters']['field_project_status_value']['field'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator_id'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['identifier'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_project_status_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_project' => 'erpal_project',
  );
  /* Filter criterion: Content: Customer (field_customer_ref) */
  $handler->display->display_options['filters']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator_id'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['identifier'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['reduce'] = 0;

  /* Display: Projects */
  $handler = $view->new_display('page', 'Projects', 'page');
  $handler->display->display_options['display_description'] = 'List of all projects';
  $handler->display->display_options['path'] = 'projects/projects';

  /* Display: Projects by activity pane */
  $handler = $view->new_display('panel_pane', 'Projects by activity pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: CRM activity (field_activity_ref) */
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['id'] = 'field_activity_ref_target_id';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['table'] = 'field_data_field_activity_ref';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['field'] = 'field_activity_ref_target_id';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_activity_ref_target_id']['not'] = 0;
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
  $export['projects'] = $view;

  $view = new view;
  $view->name = 'tasks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tasks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Project tasks';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'field_task_assigned_users_uid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
    'field_project_ref_nid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 1,
        'bef_filter_description' => '',
      ),
    ),
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No tasks available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_project_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_project_ref']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_project_ref']['field_api_classes'] = 0;
  /* Field: Content: Task status */
  $handler->display->display_options['fields']['field_task_status']['id'] = 'field_task_status';
  $handler->display->display_options['fields']['field_task_status']['table'] = 'field_data_field_task_status';
  $handler->display->display_options['fields']['field_task_status']['field'] = 'field_task_status';
  $handler->display->display_options['fields']['field_task_status']['label'] = 'Status';
  $handler->display->display_options['fields']['field_task_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_task_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_task_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_task_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_task_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_task_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_task_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_task_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_task_status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_task_status']['field_api_classes'] = 0;
  /* Field: Content: Task Type */
  $handler->display->display_options['fields']['field_task_type']['id'] = 'field_task_type';
  $handler->display->display_options['fields']['field_task_type']['table'] = 'field_data_field_task_type';
  $handler->display->display_options['fields']['field_task_type']['field'] = 'field_task_type';
  $handler->display->display_options['fields']['field_task_type']['label'] = 'Type';
  $handler->display->display_options['fields']['field_task_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_task_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_task_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_task_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_task_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_task_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_task_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_task_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_task_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_task_type']['field_api_classes'] = 0;
  /* Field: Content: Estimated time */
  $handler->display->display_options['fields']['field_estimated_time']['id'] = 'field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['table'] = 'field_data_field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['field'] = 'field_estimated_time';
  $handler->display->display_options['fields']['field_estimated_time']['label'] = 'Time';
  $handler->display->display_options['fields']['field_estimated_time']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['text'] = '[field_estimated_time] h';
  $handler->display->display_options['fields']['field_estimated_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_estimated_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_estimated_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_estimated_time']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_estimated_time']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_estimated_time']['field_api_classes'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
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
  /* Filter criterion: Content: Task status (field_task_status) */
  $handler->display->display_options['filters']['field_task_status_value']['id'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['table'] = 'field_data_field_task_status';
  $handler->display->display_options['filters']['field_task_status_value']['field'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_value']['expose']['operator_id'] = 'field_task_status_value_op';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['operator'] = 'field_task_status_value_op';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['identifier'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_task_status_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Task Type (field_task_type) */
  $handler->display->display_options['filters']['field_task_type_value']['id'] = 'field_task_type_value';
  $handler->display->display_options['filters']['field_task_type_value']['table'] = 'field_data_field_task_type';
  $handler->display->display_options['filters']['field_task_type_value']['field'] = 'field_task_type_value';
  $handler->display->display_options['filters']['field_task_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_value']['expose']['operator_id'] = 'field_task_type_value_op';
  $handler->display->display_options['filters']['field_task_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_value']['expose']['operator'] = 'field_task_type_value_op';
  $handler->display->display_options['filters']['field_task_type_value']['expose']['identifier'] = 'field_task_type_value';
  $handler->display->display_options['filters']['field_task_type_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_task_type_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
    'field_data_field_date.field_date_value2' => 'field_data_field_date.field_date_value2',
  );
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator_id'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['operator'] = 'field_project_ref_target_id_op';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['identifier'] = 'field_project_ref_target_id';
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['reduce'] = 0;

  /* Display: Tasks */
  $handler = $view->new_display('page', 'Tasks', 'page');
  $handler->display->display_options['display_description'] = 'A simple List with Tasks and task filters';
  $handler->display->display_options['path'] = 'projects/tasks';

  /* Display: Task by project pane */
  $handler = $view->new_display('panel_pane', 'Task by project pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_project_ref_target_id']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Task status (field_task_status) */
  $handler->display->display_options['filters']['field_task_status_value']['id'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['table'] = 'field_data_field_task_status';
  $handler->display->display_options['filters']['field_task_status_value']['field'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_task_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_value']['expose']['operator_id'] = 'field_task_status_value_op';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['operator'] = 'field_task_status_value_op';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['identifier'] = 'field_task_status_value';
  $handler->display->display_options['filters']['field_task_status_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_task_status_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Task Type (field_task_type) */
  $handler->display->display_options['filters']['field_task_type_value']['id'] = 'field_task_type_value';
  $handler->display->display_options['filters']['field_task_type_value']['table'] = 'field_data_field_task_type';
  $handler->display->display_options['filters']['field_task_type_value']['field'] = 'field_task_type_value';
  $handler->display->display_options['filters']['field_task_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_task_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_value']['expose']['operator_id'] = 'field_task_type_value_op';
  $handler->display->display_options['filters']['field_task_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_value']['expose']['operator'] = 'field_task_type_value_op';
  $handler->display->display_options['filters']['field_task_type_value']['expose']['identifier'] = 'field_task_type_value';
  $handler->display->display_options['filters']['field_task_type_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_task_type_value']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['date_filter']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date.field_date_value' => 'field_data_field_date.field_date_value',
    'field_data_field_date.field_date_value2' => 'field_data_field_date.field_date_value2',
  );
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['reduce'] = 0;
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
  $export['tasks'] = $view;

  $view = new view;
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
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
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
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No timetrackings available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['label'] = 'field_timetracking_subject';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_date_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date_time']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_date_time']['field_api_classes'] = 0;
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_timetracking_duration']['id'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['table'] = 'field_data_field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['field'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_timetracking_duration']['field_api_classes'] = 0;
  /* Field: Field: Billing Duration */
  $handler->display->display_options['fields']['field_billing_duration']['id'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['table'] = 'field_data_field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['field'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_billing_duration']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Task';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['fields']['title_2']['label'] = 'Project';
  $handler->display->display_options['fields']['title_2']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_2']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_2']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_2']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_2']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_2']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_2']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
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
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['not'] = 0;
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
  $handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['field_project_ref_target_id']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['field_date_time_value']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';

  /* Display: Timetrackings */
  $handler = $view->new_display('page', 'Timetrackings', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['label'] = 'field_timetracking_subject';
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['required'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['label'] = 'field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['required'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_nid';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_project_ref_target_id']['not'] = 0;
  $handler->display->display_options['path'] = 'projects/timetrackings';

  /* Display: Timetrackings by task */
  $handler = $view->new_display('panel_pane', 'Timetrackings by task', 'panel_pane_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
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
  $handler->display->display_options['relationships']['field_timetracking_subject_target_id']['required'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['label'] = 'field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['required'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Subject (field_timetracking_subject) */
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['id'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['field'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_timetracking_subject_target_id']['not'] = 0;
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
  $handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['field_date_time_value']['expose']['multiple'] = FALSE;
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date_time']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_date_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date_time']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_date_time']['field_api_classes'] = 0;
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_timetracking_duration']['id'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['table'] = 'field_data_field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['field'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_timetracking_duration']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_timetracking_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_timetracking_duration']['field_api_classes'] = 0;
  /* Field: Field: Billing Duration */
  $handler->display->display_options['fields']['field_billing_duration']['id'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['table'] = 'field_data_field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['field'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_billing_duration']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_billing_duration']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_billing_duration']['field_api_classes'] = 0;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_timetracking_subject']['id'] = 'field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['field'] = 'field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['label'] = 'Task';
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_timetracking_subject']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_timetracking_subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_timetracking_subject']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_timetracking_subject']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_timetracking_subject']['field_api_classes'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['relationship'] = 'field_timetracking_subject_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_project_ref_target_id']['not'] = 0;
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
  $handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['field_date_time_value']['expose']['multiple'] = FALSE;
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
  $export['timetrackings'] = $view;

  return $export;
}
