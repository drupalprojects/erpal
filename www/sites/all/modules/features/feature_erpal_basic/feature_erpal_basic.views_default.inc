<?php
/**
 * @file
 * feature_erpal_basic.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_erpal_basic_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_contact_type' => 'field_contact_type',
    'edit_node' => 'edit_node',
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
    'field_contact_type' => array(
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
echo _erpal_basic_helper_view_contacts_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no contacts available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Contact Type */
  $handler->display->display_options['fields']['field_contact_type']['id'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['field'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['field_api_classes'] = 0;
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
    'erpal_contact' => 'erpal_contact',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Contact Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_value']['id'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_value']['field'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['value'] = array(
    'person' => 'person',
    'company' => 'company',
  );
  $handler->display->display_options['filters']['field_contact_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['operator_id'] = 'field_contact_type_value_op';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['label'] = 'Contact Type';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['operator'] = 'field_contact_type_value_op';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['identifier'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;

  /* Display: Contacts */
  $handler = $view->new_display('page', 'Contacts', 'page');
  $handler->display->display_options['display_description'] = 'List of all contacts';
  $handler->display->display_options['path'] = 'crm/contacts';
  $handler->display->display_options['menu']['title'] = 'CRM';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Contact Reference Project */
  $handler = $view->new_display('entityreference_view_widget', 'Contact Reference Project', 'entityreference_view_widget_2');

  /* Display: Contact Dialog Search Project */
  $handler = $view->new_display('references_dialog', 'Contact Dialog Search Project', 'references_dialog_customer_project');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Choose a contact';
  $handler->display->display_options['display_description'] = 'Search a customer for a project';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Contact Type */
  $handler->display->display_options['fields']['field_contact_type']['id'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['field'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact_type']['field_api_classes'] = 0;
  $handler->display->display_options['attach'] = array(
    0 => 'node:field_customer_ref:erpal_project',
  );
  $translatables['contacts'] = array(
    t('Master'),
    t('Contacts'),
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
echo _erpal_basic_helper_view_contacts_header_content();
?>'),
    t('There are no contacts available'),
    t('Name'),
    t('Contact Type'),
    t('Type'),
    t('List of all contacts'),
    t('Contact Reference Project'),
    t('Contact Dialog Search Project'),
    t('Choose a contact'),
    t('Search a customer for a project'),
  );
  $export['contacts'] = $view;

  $view = new view;
  $view->name = 'relations_view';
  $view->description = 'Lists relations of a certain type';
  $view->tag = 'default';
  $view->base_table = 'relation';
  $view->human_name = 'Relations view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Relations by node';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints']['id'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['label'] = '';
  $handler->display->display_options['fields']['endpoints']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['external'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['endpoints']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['endpoints']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['html'] = 0;
  $handler->display->display_options['fields']['endpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['endpoints']['hide_empty'] = 0;
  $handler->display->display_options['fields']['endpoints']['empty_zero'] = 0;
  $handler->display->display_options['fields']['endpoints']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['endpoints']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints']['group_rows'] = 1;
  $handler->display->display_options['fields']['endpoints']['delta_offset'] = '0';
  $handler->display->display_options['fields']['endpoints']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['endpoints']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['endpoints']['field_api_classes'] = 0;
  /* Field: Relation: Rendered Relation */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_relation';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  /* Contextual filter: Relation: Relation type */
  $handler->display->display_options['arguments']['relation_type']['id'] = 'relation_type';
  $handler->display->display_options['arguments']['relation_type']['table'] = 'relation';
  $handler->display->display_options['arguments']['relation_type']['field'] = 'relation_type';
  $handler->display->display_options['arguments']['relation_type']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['relation_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['relation_type']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['relation_type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['relation_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['relation_type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['relation_type']['glossary'] = 0;
  $handler->display->display_options['arguments']['relation_type']['limit'] = '0';
  $handler->display->display_options['arguments']['relation_type']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['relation_type']['break_phrase'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'relations';

  /* Display: Relations by node */
  $handler = $view->new_display('panel_pane', 'Relations by node', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'endpoints' => 'endpoints',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'endpoints' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints']['id'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['label'] = '';
  $handler->display->display_options['fields']['endpoints']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['external'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['endpoints']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['endpoints']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['endpoints']['alter']['html'] = 0;
  $handler->display->display_options['fields']['endpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['endpoints']['hide_empty'] = 0;
  $handler->display->display_options['fields']['endpoints']['empty_zero'] = 0;
  $handler->display->display_options['fields']['endpoints']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['endpoints']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints']['type'] = 'relation_endpoint_simple_table';
  $handler->display->display_options['fields']['endpoints']['group_rows'] = 1;
  $handler->display->display_options['fields']['endpoints']['delta_offset'] = '0';
  $handler->display->display_options['fields']['endpoints']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['endpoints']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['endpoints']['field_api_classes'] = 0;
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_date_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'int_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_date_1']['field_api_classes'] = 0;
  /* Field: Relation: Change Date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'relation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Changed';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['changed']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['changed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['changed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['changed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['changed']['date_format'] = 'int_date_time';
  /* Field: Relation: Create Date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'relation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
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
  /* Field: Relation: Relation Tags */
  $handler->display->display_options['fields']['field_work_at_rel_tags']['id'] = 'field_work_at_rel_tags';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['table'] = 'field_data_field_work_at_rel_tags';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['field'] = 'field_work_at_rel_tags';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['label'] = 'Tags';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_work_at_rel_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['field_api_classes'] = 0;
  /* Field: Relation: Relation type */
  $handler->display->display_options['fields']['relation_type']['id'] = 'relation_type';
  $handler->display->display_options['fields']['relation_type']['table'] = 'relation';
  $handler->display->display_options['fields']['relation_type']['field'] = 'relation_type';
  $handler->display->display_options['fields']['relation_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['relation_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['relation_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['relation_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['relation_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['relation_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['relation_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['relation_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['relation_type']['hide_alter_empty'] = 1;
  /* Field: Relation: Role in project */
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['id'] = 'field_projet_role_rel_tags';
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['table'] = 'field_data_field_projet_role_rel_tags';
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['field'] = 'field_projet_role_rel_tags';
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Relation: endpoints (endpoints:entity_id) */
  $handler->display->display_options['arguments']['endpoints_entity_id']['id'] = 'endpoints_entity_id';
  $handler->display->display_options['arguments']['endpoints_entity_id']['table'] = 'field_data_endpoints';
  $handler->display->display_options['arguments']['endpoints_entity_id']['field'] = 'endpoints_entity_id';
  $handler->display->display_options['arguments']['endpoints_entity_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['endpoints_entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['endpoints_entity_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['endpoints_entity_id']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['endpoints_entity_id']['not'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'endpoints_entity_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Relation: endpoints (endpoints:entity_id)',
    ),
  );
  $translatables['relations_view'] = array(
    t('Master'),
    t('Relations by node'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Rendered Relation'),
    t('All'),
    t('Page'),
    t('Period'),
    t('Changed'),
    t('Created'),
    t('Tags'),
    t('Relation type'),
    t('Role in project'),
    t('View panes'),
  );
  $export['relations_view'] = $view;

  return $export;
}
