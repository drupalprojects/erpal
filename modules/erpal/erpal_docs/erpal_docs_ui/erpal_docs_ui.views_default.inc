<?php
/**
 * @file
 * erpal_docs_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_docs_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'documents';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Documents';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Documents';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access documents view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No files available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
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
  /* Field: Content: File tags */
  $handler->display->display_options['fields']['field_file_tags']['id'] = 'field_file_tags';
  $handler->display->display_options['fields']['field_file_tags']['table'] = 'field_data_field_file_tags';
  $handler->display->display_options['fields']['field_file_tags']['field'] = 'field_file_tags';
  $handler->display->display_options['fields']['field_file_tags']['delta_offset'] = '0';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
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
    'erpal_file' => 'erpal_file',
  );
  /* Filter criterion: Content: File tags (field_file_tags) */
  $handler->display->display_options['filters']['field_file_tags_tid']['id'] = 'field_file_tags_tid';
  $handler->display->display_options['filters']['field_file_tags_tid']['table'] = 'field_data_field_file_tags';
  $handler->display->display_options['filters']['field_file_tags_tid']['field'] = 'field_file_tags_tid';
  $handler->display->display_options['filters']['field_file_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['operator_id'] = 'field_file_tags_tid_op';
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['label'] = 'File tags';
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['operator'] = 'field_file_tags_tid_op';
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['identifier'] = 'field_file_tags_tid';
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_file_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_file_tags_tid']['vocabulary'] = 'file_tags';
  $handler->display->display_options['filters']['field_file_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
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
    8 => 0,
  );

  /* Display: Reference Dialog Search */
  $handler = $view->new_display('references_dialog', 'Reference Dialog Search', 'references_dialog_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
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
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['attach'] = array(
    0 => 'node:field_asset_files:erpal_crm_activity',
  );

  /* Display: File usage pane */
  $handler = $view->new_display('panel_pane', 'File usage pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'This file is used at';
  $handler->display->display_options['display_description'] = 'Pane showing nodes referencing the file';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Files (field_asset_files) */
  $handler->display->display_options['arguments']['field_asset_files_target_id']['id'] = 'field_asset_files_target_id';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['table'] = 'field_data_field_asset_files';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['field'] = 'field_asset_files_target_id';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'field_asset_files_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Invoice PDF (field_asset_files:target_id)',
    ),
  );

  /* Display: Files pane */
  $handler = $view->new_display('panel_pane', 'Files pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Documents by project */
  $handler = $view->new_display('panel_pane', 'Documents by project', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_asset_files_node']['id'] = 'reverse_field_asset_files_node';
  $handler->display->display_options['relationships']['reverse_field_asset_files_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_asset_files_node']['field'] = 'reverse_field_asset_files_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: File tags */
  $handler->display->display_options['fields']['field_file_tags']['id'] = 'field_file_tags';
  $handler->display->display_options['fields']['field_file_tags']['table'] = 'field_data_field_file_tags';
  $handler->display->display_options['fields']['field_file_tags']['field'] = 'field_file_tags';
  $handler->display->display_options['fields']['field_file_tags']['delta_offset'] = '0';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_asset_files_node';
  $handler->display->display_options['fields']['title_1']['label'] = 'Attached at';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['relationship'] = 'reverse_field_asset_files_node';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_action'] = 'default';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['erpal_subtasks']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['fail'] = 'empty';
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
    'erpal_file' => 'erpal_file',
  );
  /* Filter criterion: Content: File tags (field_file_tags) */
  $handler->display->display_options['filters']['field_file_tags_tid']['id'] = 'field_file_tags_tid';
  $handler->display->display_options['filters']['field_file_tags_tid']['table'] = 'field_data_field_file_tags';
  $handler->display->display_options['filters']['field_file_tags_tid']['field'] = 'field_file_tags_tid';
  $handler->display->display_options['filters']['field_file_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['operator_id'] = 'field_file_tags_tid_op';
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['label'] = 'File tags';
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['operator'] = 'field_file_tags_tid_op';
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['identifier'] = 'field_file_tags_tid';
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_file_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_file_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_file_tags_tid']['vocabulary'] = 'file_tags';
  $handler->display->display_options['filters']['field_file_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
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
    8 => 0,
  );
  /* Filter criterion: Task: Task subtasks */
  $handler->display->display_options['filters']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['filters']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['filters']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['filters']['erpal_subtasks']['value'] = '1';
  $handler->display->display_options['filters']['erpal_subtasks']['exposed'] = TRUE;
  $handler->display->display_options['filters']['erpal_subtasks']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['erpal_subtasks']['expose']['label'] = 'Show sub-files';
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
    'child_tasks_files' => array(
      'type' => 'panel',
      'context' => 'entity:node.field-duration-calc',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'File Usage: Show files of child tasks',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['documents'] = $view;

  $view = new view();
  $view->name = 'documents_usage_comments';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Documents usage comments';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Used at comments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'subject' => 'subject',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'subject' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Comment: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = 'Comment';
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Content';
  /* Sort criterion: Comment: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Files (field_asset_files) */
  $handler->display->display_options['arguments']['field_asset_files_target_id']['id'] = 'field_asset_files_target_id';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['table'] = 'field_data_field_asset_files';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['field'] = 'field_asset_files_target_id';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_asset_files_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Comment: Approved */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;

  /* Display: Comments by asset */
  $handler = $view->new_display('panel_pane', 'Comments by asset', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'field_asset_files_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field: Files (field_asset_files)',
    ),
  );
  $export['documents_usage_comments'] = $view;

  return $export;
}
