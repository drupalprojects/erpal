<?php
/**
 * @file
 * erpal_book_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_book_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'book_children';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Book children';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All child pages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-lis';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['ajax_child_view'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
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
    'link' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  /* Field: Content: Weight */
  $handler->display->display_options['fields']['field_weight']['id'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['table'] = 'field_data_field_weight';
  $handler->display->display_options['fields']['field_weight']['field'] = 'field_weight';
  $handler->display->display_options['fields']['field_weight']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_weight']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Weight (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  /* Contextual filter: Content: Book (field_book_ref) */
  $handler->display->display_options['arguments']['field_book_ref_target_id']['id'] = 'field_book_ref_target_id';
  $handler->display->display_options['arguments']['field_book_ref_target_id']['table'] = 'field_data_field_book_ref';
  $handler->display->display_options['arguments']['field_book_ref_target_id']['field'] = 'field_book_ref_target_id';
  $handler->display->display_options['arguments']['field_book_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_book_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_book_ref_target_id']['default_argument_options']['argument'] = 'No pages found';
  $handler->display->display_options['arguments']['field_book_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_book_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_book_ref_target_id']['summary_options']['items_per_page'] = '25';
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
    'erpal_book_page' => 'erpal_book_page',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['field_parent_nid']['id'] = 'field_parent_nid';
  $handler->display->display_options['filters']['field_parent_nid']['table'] = 'field_data_field_parent';
  $handler->display->display_options['filters']['field_parent_nid']['field'] = 'field_parent_nid';
  $handler->display->display_options['filters']['field_parent_nid']['operator'] = 'empty';

  /* Display: Child book page nodes */
  $handler = $view->new_display('panel_pane', 'Child book page nodes', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Dispalys all nodes that have parent nid set to contextual filter';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'node';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_book_page' => 'erpal_book_page',
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_parent_target_id' => array(
      'type' => 'user',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Child book page nodes AJAX */
  $handler = $view->new_display('panel_pane', 'Child book page nodes AJAX', 'panel_pane_3');
  $handler->display->display_options['display_description'] = 'Load all nodes that have parent nid set to contextual filter';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['style_options']['wrapper_class'] = 'item-lis';
  $handler->display->display_options['style_options']['id_field'] = 'nid';
  $handler->display->display_options['style_options']['parent_field'] = 'field_parent';
  $handler->display->display_options['style_options']['weight_field'] = 'field_weight';
  $handler->display->display_options['style_options']['type_field'] = 'type_1';
  $handler->display->display_options['style_options']['ajax_child_view'] = 1;
  $handler->display->display_options['style_options']['ajax_child_view_top_types'] = array(
    'erpal_book' => 'erpal_book',
    'erpal_book_page' => 'erpal_book_page',
    'erpal_contact' => 0,
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
    'custom_context_menu' => 'Show IT|/node/[views_jstree_book_children_panel_pane_3:nid]
Edit IT|/node/[views_jstree_book_children_panel_pane_3:nid]/edit',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
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
    'link' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['type_1']['id'] = 'type_1';
  $handler->display->display_options['fields']['type_1']['table'] = 'node';
  $handler->display->display_options['fields']['type_1']['field'] = 'type';
  $handler->display->display_options['fields']['type_1']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_target_id']['field'] = 'field_parent_target_id';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_target_id']['default_argument_options']['argument'] = 'No pages available';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_book_page' => 'erpal_book_page',
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_parent_nid' => array(
      'type' => 'none',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $translatables['book_children'] = array(
    t('Master'),
    t('All child pages'),
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
    t('Edit'),
    t('Nid'),
    t('Parent'),
    t('Type'),
    t('Weight'),
    t('All'),
    t('Child book page nodes'),
    t('Dispalys all nodes that have parent nid set to contextual filter'),
    t('View panes'),
    t('Child book page nodes AJAX'),
    t('Load all nodes that have parent nid set to contextual filter'),
  );
  $export['book_children'] = $view;

  $view = new view();
  $view->name = 'books';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Books';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access books view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
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
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_book' => 'erpal_book',
  );
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
  );
  /* Filter criterion: Content: Book Tags (field_book_tags) */
  $handler->display->display_options['filters']['field_book_tags_tid']['id'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['table'] = 'field_data_field_book_tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['field'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['operator_id'] = 'field_book_tags_tid_op';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['operator'] = 'field_book_tags_tid_op';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['identifier'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_book_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_book_tags_tid']['vocabulary'] = 'book_tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Is template (field_is_template) */
  $handler->display->display_options['filters']['field_is_template_value']['id'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['table'] = 'field_data_field_is_template';
  $handler->display->display_options['filters']['field_is_template_value']['field'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_is_template_value']['value'] = array(
    1 => '1',
  );

  /* Display: Book templates to clone */
  $handler = $view->new_display('page', 'Book templates to clone', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Books';
  $handler->display->display_options['display_description'] = 'Lists all template pages with bulk op to clone to book given in argument';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
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
      'selected' => 1,
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
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
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
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
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
    'erpal_book_page' => 'erpal_book_page',
  );
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
  );
  /* Filter criterion: Content: Book Tags (field_book_tags) */
  $handler->display->display_options['filters']['field_book_tags_tid']['id'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['table'] = 'field_data_field_book_tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['field'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['operator_id'] = 'field_book_tags_tid_op';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['operator'] = 'field_book_tags_tid_op';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['identifier'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_book_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_book_tags_tid']['vocabulary'] = 'book_tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Is template (field_is_template) */
  $handler->display->display_options['filters']['field_is_template_value']['id'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['table'] = 'field_data_field_is_template';
  $handler->display->display_options['filters']['field_is_template_value']['field'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_is_template_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_is_template_value']['expose']['operator_id'] = 'field_is_template_value_op';
  $handler->display->display_options['filters']['field_is_template_value']['expose']['label'] = 'Is template';
  $handler->display->display_options['filters']['field_is_template_value']['expose']['operator'] = 'field_is_template_value_op';
  $handler->display->display_options['filters']['field_is_template_value']['expose']['identifier'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_is_template_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['path'] = 'books/clonetemplates/%';

  /* Display: Books pane */
  $handler = $view->new_display('panel_pane', 'Books pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Templates pane */
  $handler = $view->new_display('panel_pane', 'Templates pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
    'erpal_book' => 'erpal_book',
    'erpal_book_page' => 'erpal_book_page',
  );
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
  );
  /* Filter criterion: Content: Book Tags (field_book_tags) */
  $handler->display->display_options['filters']['field_book_tags_tid']['id'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['table'] = 'field_data_field_book_tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['field'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['operator_id'] = 'field_book_tags_tid_op';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['operator'] = 'field_book_tags_tid_op';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['identifier'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_book_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_book_tags_tid']['vocabulary'] = 'book_tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Is template (field_is_template) */
  $handler->display->display_options['filters']['field_is_template_value']['id'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['table'] = 'field_data_field_is_template';
  $handler->display->display_options['filters']['field_is_template_value']['field'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['books'] = array(
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
    t('Post date'),
    t('Title'),
    t('Tags'),
    t('Book templates to clone'),
    t('Books'),
    t('Lists all template pages with bulk op to clone to book given in argument'),
    t('Select'),
    t('Is template'),
    t('Books pane'),
    t('View panes'),
    t('Templates pane'),
  );
  $export['books'] = $view;

  return $export;
}
