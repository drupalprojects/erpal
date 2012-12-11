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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access activities view';
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
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_customer_ref' => 'field_customer_ref',
    'field_activity_status_term' => 'field_activity_status_term',
    'field_next_contact' => 'field_next_contact',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
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
    'field_activity_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_next_contact' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'This contact has no activities';
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
  $handler->display->display_options['fields']['title']['label'] = 'Activity title';
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
  $handler->display->display_options['fields']['field_activity_status_term']['id'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['field'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Next Contact */
  $handler->display->display_options['fields']['field_next_contact']['id'] = 'field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['field'] = 'field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['settings'] = array(
    'format_type' => 'erpal_date_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Sort criterion: Content: Updated/commented date */
  $handler->display->display_options['sorts']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['sorts']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['sorts']['last_updated']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Contextual filter: Field: Customer (field_customer_ref) */
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: Status (field_activity_status_term) */
  $handler->display->display_options['filters']['field_activity_status_term_tid']['id'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['field'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator_id'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['identifier'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_activity_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['vocabulary'] = 'activity_status_terms';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['error_message'] = FALSE;
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
    'erpal_crm_activity' => 'erpal_crm_activity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Activities by customer */
  $handler = $view->new_display('panel_pane', 'Activities by customer', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CRM activities as customer';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Status (field_activity_status_term) */
  $handler->display->display_options['filters']['field_activity_status_term_tid']['id'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['field'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator_id'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['identifier'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_activity_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['vocabulary'] = 'activity_status_terms';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['error_message'] = FALSE;
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
    'erpal_crm_activity' => 'erpal_crm_activity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
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
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Next activities pane */
  $handler = $view->new_display('panel_pane', 'Next activities pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Next activities';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No next activities';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  /* Filter criterion: Content: Status (field_activity_status_term) */
  $handler->display->display_options['filters']['field_activity_status_term_tid']['id'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['field'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator_id'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['identifier'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_activity_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['vocabulary'] = 'activity_status_terms';
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
    'erpal_crm_activity' => 'erpal_crm_activity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Next Contact (field_next_contact) */
  $handler->display->display_options['filters']['field_next_contact_value']['id'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['filters']['field_next_contact_value']['field'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_next_contact_value']['group'] = 1;
  $handler->display->display_options['filters']['field_next_contact_value']['default_date'] = 'now +3 day';
  /* Filter criterion: Content: Next Contact (field_next_contact) */
  $handler->display->display_options['filters']['field_next_contact_value_1']['id'] = 'field_next_contact_value_1';
  $handler->display->display_options['filters']['field_next_contact_value_1']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['filters']['field_next_contact_value_1']['field'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_next_contact_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_next_contact_value_1']['default_date'] = 'now';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Missed activities pane */
  $handler = $view->new_display('panel_pane', 'Missed activities pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Missed activities';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No missed activities';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  /* Filter criterion: Content: Status (field_activity_status_term) */
  $handler->display->display_options['filters']['field_activity_status_term_tid']['id'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['field'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator_id'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['identifier'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_activity_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['vocabulary'] = 'activity_status_terms';
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
    'erpal_crm_activity' => 'erpal_crm_activity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Next Contact (field_next_contact) */
  $handler->display->display_options['filters']['field_next_contact_value']['id'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['filters']['field_next_contact_value']['field'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_next_contact_value']['group'] = 1;
  $handler->display->display_options['filters']['field_next_contact_value']['default_date'] = 'now';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: activities view pane */
  $handler = $view->new_display('panel_pane', 'activities view pane', 'panel_pane_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Activities by contact */
  $handler = $view->new_display('panel_pane', 'Activities by contact', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CRM activities involved';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['id'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['field'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_activity_status_term']['id'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['field'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Next Contact */
  $handler->display->display_options['fields']['field_next_contact']['id'] = 'field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['field'] = 'field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['settings'] = array(
    'format_type' => 'erpal_date_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Contacts (field_contacts_ref) */
  $handler->display->display_options['arguments']['field_contacts_ref_target_id']['id'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['arguments']['field_contacts_ref_target_id']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['arguments']['field_contacts_ref_target_id']['field'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['arguments']['field_contacts_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_contacts_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_contacts_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_contacts_ref_target_id']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Status (field_activity_status_term) */
  $handler->display->display_options['filters']['field_activity_status_term_tid']['id'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['field'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator_id'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['identifier'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_activity_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['vocabulary'] = 'activity_status_terms';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['error_message'] = FALSE;
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
    'erpal_crm_activity' => 'erpal_crm_activity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'field_contacts_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field: Contacts (field_contacts_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: CRM Activities Pane */
  $handler = $view->new_display('panel_pane', 'CRM Activities Pane', 'panel_pane_5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Activity title';
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
  $handler->display->display_options['fields']['field_activity_status_term']['id'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['field'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Next Contact */
  $handler->display->display_options['fields']['field_next_contact']['id'] = 'field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['field'] = 'field_next_contact';
  $handler->display->display_options['fields']['field_next_contact']['settings'] = array(
    'format_type' => 'erpal_date_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
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
  /* Filter criterion: Content: Status (field_activity_status_term) */
  $handler->display->display_options['filters']['field_activity_status_term_tid']['id'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['field'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator_id'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['operator'] = 'field_activity_status_term_tid_op';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['identifier'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_activity_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_status_term_tid']['vocabulary'] = 'activity_status_terms';
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
    'erpal_crm_activity' => 'erpal_crm_activity',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['crm_activities'] = array(
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
    t('This contact has no activities'),
    t('customer'),
    t('Activity title'),
    t('Customer'),
    t('Status'),
    t('Next Contact'),
    t('All'),
    t('Title'),
    t('Activities by customer'),
    t('CRM activities as customer'),
    t('View panes'),
    t('Next activities pane'),
    t('Next activities'),
    t('No next activities'),
    t('Missed activities pane'),
    t('Missed activities'),
    t('No missed activities'),
    t('Search Terms'),
    t('activities view pane'),
    t('Activities by contact'),
    t('CRM activities involved'),
    t('Content entity referenced from field_contacts_ref'),
    t('CRM Activities Pane'),
  );
  $export['crm_activities'] = $view;

  return $export;
}
