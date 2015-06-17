<?php
/**
 * @file
 * erpal_crm_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_crm_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'activity_revisions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Activity revisions';
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
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
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
  /* Field: Content (historical data): Status */
  $handler->display->display_options['fields']['field_activity_status_term-revision_id']['id'] = 'field_activity_status_term-revision_id';
  $handler->display->display_options['fields']['field_activity_status_term-revision_id']['table'] = 'field_revision_field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term-revision_id']['field'] = 'field_activity_status_term-revision_id';
  $handler->display->display_options['fields']['field_activity_status_term-revision_id']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content (historical data): Next contact */
  $handler->display->display_options['fields']['field_next_contact-revision_id']['id'] = 'field_next_contact-revision_id';
  $handler->display->display_options['fields']['field_next_contact-revision_id']['table'] = 'field_revision_field_next_contact';
  $handler->display->display_options['fields']['field_next_contact-revision_id']['field'] = 'field_next_contact-revision_id';
  $handler->display->display_options['fields']['field_next_contact-revision_id']['settings'] = array(
    'format_type' => 'erpal_date_time',
    'fromto' => 'both',
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
  $handler->display->display_options['fields']['name']['label'] = 'User';
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
    'erpal_crm_activity' => 'erpal_crm_activity',
  );

  /* Display: Activity revisions pane */
  $handler = $view->new_display('panel_pane', 'Activity revisions pane', 'panel_pane_1');
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
  $translatables['activity_revisions'] = array(
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
    t('Updated date'),
    t('Status'),
    t('Next contact'),
    t('User'),
    t('All'),
    t('Activity revisions pane'),
    t('View panes'),
  );
  $export['activity_revisions'] = $view;

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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_customer_ref' => 'field_customer_ref',
    'field_activity_status_term' => 'field_activity_status_term',
    'created' => 'created',
    'last_updated' => 'last_updated',
    'field_next_contact' => 'field_next_contact',
    'field_volume' => 'field_volume',
    'field_chance' => 'field_chance',
    'field_activity_origin' => 'field_activity_origin',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_customer_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_activity_status_term' => array(
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
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_next_contact' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_volume' => array(
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
    'field_chance' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_activity_origin' => array(
      'sortable' => 1,
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
  $handler->display->display_options['style_options']['decimal'] = ',';
  $handler->display->display_options['style_options']['separator'] = '';
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
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['id'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['field'] = 'field_contacts_ref_target_id';
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
  $handler->display->display_options['fields']['field_customer_ref']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_activity_status_term']['id'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['field'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last update';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'erpal_date_time';
  /* Field: Content: Next contact */
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
  /* Field: Content: Volume */
  $handler->display->display_options['fields']['field_volume']['id'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['table'] = 'field_data_field_volume';
  $handler->display->display_options['fields']['field_volume']['field'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Prospect Quality */
  $handler->display->display_options['fields']['field_chance']['id'] = 'field_chance';
  $handler->display->display_options['fields']['field_chance']['table'] = 'field_data_field_chance';
  $handler->display->display_options['fields']['field_chance']['field'] = 'field_chance';
  $handler->display->display_options['fields']['field_chance']['type'] = 'editable';
  $handler->display->display_options['fields']['field_chance']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'button',
    'empty_text' => '',
    'fallback_format' => 'list_default',
  );
  /* Field: Content: Origin */
  $handler->display->display_options['fields']['field_activity_origin']['id'] = 'field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['field'] = 'field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['type'] = 'editable';
  $handler->display->display_options['fields']['field_activity_origin']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'button',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
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
  /* Filter criterion: Content: Origin (field_activity_origin) */
  $handler->display->display_options['filters']['field_activity_origin_tid']['id'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['field'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_origin_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator_id'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['label'] = 'Origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['identifier'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_activity_origin_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_origin_tid']['vocabulary'] = 'activity_origin';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_2']['id'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['table'] = 'node';
  $handler->display->display_options['filters']['title_2']['field'] = 'title';
  $handler->display->display_options['filters']['title_2']['relationship'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['filters']['title_2']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_2']['expose']['operator_id'] = 'title_2_op';
  $handler->display->display_options['filters']['title_2']['expose']['label'] = 'Participants';
  $handler->display->display_options['filters']['title_2']['expose']['operator'] = 'title_2_op';
  $handler->display->display_options['filters']['title_2']['expose']['identifier'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_2']['expose']['remember_roles'] = array(
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
  /* Relationship: Content: Status (field_activity_status_term) */
  $handler->display->display_options['relationships']['field_activity_status_term_tid']['id'] = 'field_activity_status_term_tid';
  $handler->display->display_options['relationships']['field_activity_status_term_tid']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['relationships']['field_activity_status_term_tid']['field'] = 'field_activity_status_term_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['id'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['field'] = 'field_contacts_ref_target_id';
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
  /* Filter criterion: Content: Origin (field_activity_origin) */
  $handler->display->display_options['filters']['field_activity_origin_tid']['id'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['field'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_origin_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator_id'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['label'] = 'Origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['identifier'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_activity_origin_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_origin_tid']['vocabulary'] = 'activity_origin';
  /* Filter criterion: Content: Next contact (field_next_contact) */
  $handler->display->display_options['filters']['field_next_contact_value']['id'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['filters']['field_next_contact_value']['field'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_next_contact_value']['group'] = 1;
  $handler->display->display_options['filters']['field_next_contact_value']['default_date'] = 'now +3 day';
  /* Filter criterion: Content: Next contact (field_next_contact) */
  $handler->display->display_options['filters']['field_next_contact_value_1']['id'] = 'field_next_contact_value_1';
  $handler->display->display_options['filters']['field_next_contact_value_1']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['filters']['field_next_contact_value_1']['field'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value_1']['operator'] = '>=';
  $handler->display->display_options['filters']['field_next_contact_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_next_contact_value_1']['default_date'] = 'now';
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_2']['id'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['table'] = 'node';
  $handler->display->display_options['filters']['title_2']['field'] = 'title';
  $handler->display->display_options['filters']['title_2']['relationship'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['filters']['title_2']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_2']['group'] = 1;
  $handler->display->display_options['filters']['title_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_2']['expose']['operator_id'] = 'title_2_op';
  $handler->display->display_options['filters']['title_2']['expose']['label'] = 'Participants';
  $handler->display->display_options['filters']['title_2']['expose']['operator'] = 'title_2_op';
  $handler->display->display_options['filters']['title_2']['expose']['identifier'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_2']['expose']['remember_roles'] = array(
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
  /* Relationship: Content: Status (field_activity_status_term) */
  $handler->display->display_options['relationships']['field_activity_status_term_tid']['id'] = 'field_activity_status_term_tid';
  $handler->display->display_options['relationships']['field_activity_status_term_tid']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['relationships']['field_activity_status_term_tid']['field'] = 'field_activity_status_term_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['id'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['table'] = 'field_data_field_contacts_ref';
  $handler->display->display_options['relationships']['field_contacts_ref_target_id']['field'] = 'field_contacts_ref_target_id';
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
  /* Filter criterion: Content: Origin (field_activity_origin) */
  $handler->display->display_options['filters']['field_activity_origin_tid']['id'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['field'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_origin_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator_id'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['label'] = 'Origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['identifier'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_activity_origin_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_origin_tid']['vocabulary'] = 'activity_origin';
  /* Filter criterion: Content: Next contact (field_next_contact) */
  $handler->display->display_options['filters']['field_next_contact_value']['id'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value']['table'] = 'field_data_field_next_contact';
  $handler->display->display_options['filters']['field_next_contact_value']['field'] = 'field_next_contact_value';
  $handler->display->display_options['filters']['field_next_contact_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_next_contact_value']['group'] = 1;
  $handler->display->display_options['filters']['field_next_contact_value']['default_date'] = 'now';
  /* Filter criterion: Taxonomy term: Semantic process (field_simple_process_status) */
  $handler->display->display_options['filters']['field_simple_process_status_value']['id'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['table'] = 'field_data_field_simple_process_status';
  $handler->display->display_options['filters']['field_simple_process_status_value']['field'] = 'field_simple_process_status_value';
  $handler->display->display_options['filters']['field_simple_process_status_value']['relationship'] = 'field_activity_status_term_tid';
  $handler->display->display_options['filters']['field_simple_process_status_value']['value'] = array(
    'in_progress' => 'in_progress',
  );
  $handler->display->display_options['filters']['field_simple_process_status_value']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_2']['id'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['table'] = 'node';
  $handler->display->display_options['filters']['title_2']['field'] = 'title';
  $handler->display->display_options['filters']['title_2']['relationship'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['filters']['title_2']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_2']['expose']['operator_id'] = 'title_2_op';
  $handler->display->display_options['filters']['title_2']['expose']['label'] = 'Participants';
  $handler->display->display_options['filters']['title_2']['expose']['operator'] = 'title_2_op';
  $handler->display->display_options['filters']['title_2']['expose']['identifier'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_2']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Activities view pane */
  $handler = $view->new_display('panel_pane', 'Activities view pane', 'panel_pane_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: CRM Activities Pane */
  $handler = $view->new_display('panel_pane', 'CRM Activities Pane', 'panel_pane_5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['relationships']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
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
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_activity_status_term']['id'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['field'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Last update';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'erpal_date_time';
  /* Field: Content: Next contact */
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
  /* Field: Content: Volume */
  $handler->display->display_options['fields']['field_volume']['id'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['table'] = 'field_data_field_volume';
  $handler->display->display_options['fields']['field_volume']['field'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Prospect Quality */
  $handler->display->display_options['fields']['field_chance']['id'] = 'field_chance';
  $handler->display->display_options['fields']['field_chance']['table'] = 'field_data_field_chance';
  $handler->display->display_options['fields']['field_chance']['field'] = 'field_chance';
  $handler->display->display_options['fields']['field_chance']['type'] = 'editable';
  $handler->display->display_options['fields']['field_chance']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'button',
    'empty_text' => '',
    'fallback_format' => 'list_default',
  );
  /* Field: Content: Origin */
  $handler->display->display_options['fields']['field_activity_origin']['id'] = 'field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['field'] = 'field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['type'] = 'editable';
  $handler->display->display_options['fields']['field_activity_origin']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'button',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
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
  /* Filter criterion: Content: Origin (field_activity_origin) */
  $handler->display->display_options['filters']['field_activity_origin_tid']['id'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['field'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_activity_origin_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator_id'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['label'] = 'Origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['identifier'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_activity_origin_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_origin_tid']['vocabulary'] = 'activity_origin';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_2']['id'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['table'] = 'node';
  $handler->display->display_options['filters']['title_2']['field'] = 'title';
  $handler->display->display_options['filters']['title_2']['relationship'] = 'field_contacts_ref_target_id';
  $handler->display->display_options['filters']['title_2']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_2']['expose']['operator_id'] = 'title_2_op';
  $handler->display->display_options['filters']['title_2']['expose']['label'] = 'Participants';
  $handler->display->display_options['filters']['title_2']['expose']['operator'] = 'title_2_op';
  $handler->display->display_options['filters']['title_2']['expose']['identifier'] = 'title_2';
  $handler->display->display_options['filters']['title_2']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title_2']['expose']['remember_roles'] = array(
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
    t('Content entity referenced from field_contacts_ref'),
    t('Activity title'),
    t('Customer'),
    t('Status'),
    t('Submitted'),
    t('Last update'),
    t('Next contact'),
    t('Volume'),
    t('Prospect Quality'),
    t('Origin'),
    t('All'),
    t('Title'),
    t('Participants'),
    t('Next activities pane'),
    t('Next activities'),
    t('No next activities'),
    t('term from field_activity_status_term'),
    t('Content entity referenced from field_customer_ref'),
    t('View panes'),
    t('Missed activities pane'),
    t('Missed activities'),
    t('No missed activities'),
    t('Search Terms'),
    t('Activities view pane'),
    t('CRM Activities Pane'),
  );
  $export['crm_activities'] = $view;

  return $export;
}
