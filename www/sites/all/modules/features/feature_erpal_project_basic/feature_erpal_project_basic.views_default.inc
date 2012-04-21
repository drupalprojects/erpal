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
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
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
  $handler->display->display_options['fields']['field_customer_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['hide_alter_empty'] = 1;
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
  /* Filter criterion: Content: Customer (field_customer_ref) */
  $handler->display->display_options['filters']['field_customer_ref_nid']['id'] = 'field_customer_ref_nid';
  $handler->display->display_options['filters']['field_customer_ref_nid']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['filters']['field_customer_ref_nid']['field'] = 'field_customer_ref_nid';
  $handler->display->display_options['filters']['field_customer_ref_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['operator_id'] = 'field_customer_ref_nid_op';
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['operator'] = 'field_customer_ref_nid_op';
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['identifier'] = 'field_customer_ref_nid';
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['reduce'] = 0;
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

  /* Display: Projects */
  $handler = $view->new_display('page', 'Projects', 'page');
  $handler->display->display_options['display_description'] = 'List of all projects';
  $handler->display->display_options['path'] = 'projects/projects';
  $translatables['projects'] = array(
    t('Master'),
    t('Projects'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<?php
echo _erpal_projects_helper_view_projects_header_content();
?>'),
    t('Status'),
    t('Customer'),
    t('List of all projects'),
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
    5 => '5',
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
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
  $handler->display->display_options['fields']['field_project_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_project_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_project_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_project_ref']['hide_alter_empty'] = 1;
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
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['id'] = 'field_task_assigned_users_uid';
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['field'] = 'field_task_assigned_users_uid';
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['expose']['operator_id'] = 'field_task_assigned_users_uid_op';
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['expose']['label'] = 'Users';
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['expose']['operator'] = 'field_task_assigned_users_uid_op';
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['expose']['identifier'] = 'field_task_assigned_users_uid';
  $handler->display->display_options['filters']['field_task_assigned_users_uid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Project (field_project_ref) */
  $handler->display->display_options['filters']['field_project_ref_nid']['id'] = 'field_project_ref_nid';
  $handler->display->display_options['filters']['field_project_ref_nid']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['filters']['field_project_ref_nid']['field'] = 'field_project_ref_nid';
  $handler->display->display_options['filters']['field_project_ref_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_ref_nid']['expose']['operator_id'] = 'field_project_ref_nid_op';
  $handler->display->display_options['filters']['field_project_ref_nid']['expose']['label'] = 'Project';
  $handler->display->display_options['filters']['field_project_ref_nid']['expose']['operator'] = 'field_project_ref_nid_op';
  $handler->display->display_options['filters']['field_project_ref_nid']['expose']['identifier'] = 'field_project_ref_nid';
  $handler->display->display_options['filters']['field_project_ref_nid']['expose']['reduce'] = 0;
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
  $handler->display->display_options['arguments']['field_project_ref_nid']['id'] = 'field_project_ref_nid';
  $handler->display->display_options['arguments']['field_project_ref_nid']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_nid']['field'] = 'field_project_ref_nid';
  $handler->display->display_options['arguments']['field_project_ref_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_project_ref_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_ref_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_project_ref_nid']['not'] = 0;
  $translatables['tasks'] = array(
    t('Master'),
    t('Project tasks'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Project'),
    t('Status'),
    t('Type'),
    t('Time'),
    t('[field_estimated_time] h'),
    t('Edit'),
    t('Users'),
    t('Date'),
    t('Tasks'),
    t('A simple List with Tasks and task filters'),
    t('Task by project pane'),
    t('All'),
    t('View panes'),
  );
  $export['tasks'] = $view;

  return $export;
}
