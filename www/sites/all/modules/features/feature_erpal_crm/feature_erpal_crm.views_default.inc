<?php
/**
 * @file
 * feature_erpal_crm.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_erpal_crm_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'crm_activities';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CRM activities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Activities as Customer';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'This contact has no activities';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['label'] = 'customer';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['required'] = 0;
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
  /* Field: Content: Activity status */
  $handler->display->display_options['fields']['field_activity_status']['id'] = 'field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['field'] = 'field_activity_status';
  $handler->display->display_options['fields']['field_activity_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_activity_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_activity_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_activity_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_activity_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_activity_status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_activity_status']['field_api_classes'] = 0;
  /* Field: Content: Next Contact */
  $handler->display->display_options['fields']['field_next_contact']['id'] = 'field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['field'] = 'field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_next_contact']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_next_contact']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_next_contact']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_next_contact']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_next_contact']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_next_contact']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_next_contact']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Customer (field_customer_ref) */
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Activity status (field_activity_status) */
  $handler->display->display_options['filters']['field_activity_status_value']['id'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['filters']['field_activity_status_value']['field'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator_id'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['label'] = 'Activity status';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['identifier'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['title']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_crm_activity' => 'erpal_crm_activity',
  );

  /* Display: CRM Activities */
  $handler = $view->new_display('page', 'CRM Activities', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CRM activities';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
return _erpal_basic_helper_view_contacts_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Activity status (field_activity_status) */
  $handler->display->display_options['filters']['field_activity_status_value']['id'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['table'] = 'field_data_field_activity_status';
  $handler->display->display_options['filters']['field_activity_status_value']['field'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator_id'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['label'] = 'Activity status';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['operator'] = 'field_activity_status_value_op';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['identifier'] = 'field_activity_status_value';
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_activity_status_value']['expose']['reduce'] = 0;
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
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_crm_activity' => 'erpal_crm_activity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['path'] = 'crm/activities';
  $handler->display->display_options['menu']['title'] = 'CRM activities';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-erpal-menu';

  /* Display: Activities by contact */
  $handler = $view->new_display('panel_pane', 'Activities by contact', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_customer_ref_nid' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Customer (field_customer_ref)',
    ),
  );
  $export['crm_activities'] = $view;

  return $export;
}
