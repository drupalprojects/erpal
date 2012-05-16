<?php
/**
 * @file
 * feature_erpal_book.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_erpal_book_views_default_views() {
  $export = array();

  $view = new view;
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
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'jstree';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Parent */
  $handler->display->display_options['fields']['field_parent']['id'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['table'] = 'field_data_field_parent';
  $handler->display->display_options['fields']['field_parent']['field'] = 'field_parent';
  $handler->display->display_options['fields']['field_parent']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_parent']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_parent']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_parent']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_parent']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_parent']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_parent']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_parent']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_parent']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_parent']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_parent']['field_api_classes'] = 0;
  /* Sort criterion: Content: Weight (field_weight) */
  $handler->display->display_options['sorts']['field_weight_value']['id'] = 'field_weight_value';
  $handler->display->display_options['sorts']['field_weight_value']['table'] = 'field_data_field_weight';
  $handler->display->display_options['sorts']['field_weight_value']['field'] = 'field_weight_value';
  /* Contextual filter: Content: Book (field_book_ref) */
  $handler->display->display_options['arguments']['field_book_ref_nid']['id'] = 'field_book_ref_nid';
  $handler->display->display_options['arguments']['field_book_ref_nid']['table'] = 'field_data_field_book_ref';
  $handler->display->display_options['arguments']['field_book_ref_nid']['field'] = 'field_book_ref_nid';
  $handler->display->display_options['arguments']['field_book_ref_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_book_ref_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_book_ref_nid']['default_argument_options']['argument'] = 'No pages found';
  $handler->display->display_options['arguments']['field_book_ref_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_book_ref_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_book_ref_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_book_ref_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_book_ref_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_book_ref_nid']['not'] = 0;
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
  /* Filter criterion: Content: Parent (field_parent) */
  $handler->display->display_options['filters']['field_parent_nid']['id'] = 'field_parent_nid';
  $handler->display->display_options['filters']['field_parent_nid']['table'] = 'field_data_field_parent';
  $handler->display->display_options['filters']['field_parent_nid']['field'] = 'field_parent_nid';
  $handler->display->display_options['filters']['field_parent_nid']['operator'] = 'empty';

  /* Display: Pages of book */
  $handler = $view->new_display('panel_pane', 'Pages of book', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_book_ref_nid' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Book (field_book_ref)',
    ),
  );

  /* Display: Child nodes */
  $handler = $view->new_display('panel_pane', 'Child nodes', 'panel_pane_2');
  $handler->display->display_options['display_description'] = 'Dispalys all nodes that have parent nid set to contextual filter';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parent (field_parent) */
  $handler->display->display_options['arguments']['field_parent_nid']['id'] = 'field_parent_nid';
  $handler->display->display_options['arguments']['field_parent_nid']['table'] = 'field_data_field_parent';
  $handler->display->display_options['arguments']['field_parent_nid']['field'] = 'field_parent_nid';
  $handler->display->display_options['arguments']['field_parent_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_parent_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_parent_nid']['default_argument_options']['argument'] = 'No pages available';
  $handler->display->display_options['arguments']['field_parent_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_parent_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_parent_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_parent_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_parent_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_parent_nid']['not'] = 0;
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
  $handler->display->display_options['argument_input'] = array(
    'field_parent_nid' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Parent (field_parent)',
    ),
  );
  $export['book_children'] = $view;

  $view = new view;
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
  $handler->display->display_options['title'] = 'Books';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
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
  $handler->display->display_options['header']['area']['content'] = '<?php return _erpal_book_helper_view_contacts_header_content(); ?>';
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
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'int_date_time';
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
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Book Tags (field_book_tags) */
  $handler->display->display_options['filters']['field_book_tags_tid']['id'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['table'] = 'field_data_field_book_tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['field'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['operator_id'] = 'field_book_tags_tid_op';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['label'] = 'Tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['operator'] = 'field_book_tags_tid_op';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['identifier'] = 'field_book_tags_tid';
  $handler->display->display_options['filters']['field_book_tags_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_book_tags_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_book_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_book_tags_tid']['vocabulary'] = 'book_tags';
  $handler->display->display_options['filters']['field_book_tags_tid']['error_message'] = 1;

  /* Display: Books */
  $handler = $view->new_display('page', 'Books', 'page');
  $handler->display->display_options['path'] = 'books/books';

  /* Display: Book templates */
  $handler = $view->new_display('page', 'Book templates', 'page_1');
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
  /* Filter criterion: Content: Is template (field_is_template) */
  $handler->display->display_options['filters']['field_is_template_value']['id'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['table'] = 'field_data_field_is_template';
  $handler->display->display_options['filters']['field_is_template_value']['field'] = 'field_is_template_value';
  $handler->display->display_options['filters']['field_is_template_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'books/templates';
  $export['books'] = $view;

  return $export;
}
