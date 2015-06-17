<?php
/**
 * @file
 * erpal_project_release_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_project_release_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'releases';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Releases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view project releases';
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
    'title' => 'title',
    'created' => 'created',
    'last_updated' => 'last_updated',
    'name' => 'name',
    'field_release_tag' => 'field_release_tag',
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
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_release_tag' => array(
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
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No releases found';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Release title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Content: Updated/commented date */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Updated';
  $handler->display->display_options['fields']['last_updated']['date_format'] = 'erpal_date_time';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: Content: Release tag */
  $handler->display->display_options['fields']['field_release_tag']['id'] = 'field_release_tag';
  $handler->display->display_options['fields']['field_release_tag']['table'] = 'field_data_field_release_tag';
  $handler->display->display_options['fields']['field_release_tag']['field'] = 'field_release_tag';
  $handler->display->display_options['fields']['field_release_tag']['type'] = 'text_plain';
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
    'erpal_project_release' => 'erpal_project_release',
  );

  /* Display: Releases by project pane */
  $handler = $view->new_display('panel_pane', 'Releases by project pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_project_ref_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
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
  $translatables['releases'] = array(
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
    t('No releases found'),
    t('author'),
    t('Release title'),
    t('Created'),
    t('Updated'),
    t('User'),
    t('Release tag'),
    t('Releases by project pane'),
    t('All'),
    t('View panes'),
  );
  $export['releases'] = $view;

  $view = new view();
  $view->name = 'tasks_for_release';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tasks for release';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access tasks view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
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
  $handler->display->display_options['empty']['area']['content'] = 'No tasks available';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_target_id']['id'] = 'field_parent_target_id';
  $handler->display->display_options['relationships']['field_parent_target_id']['table'] = 'field_data_field_parent';
  $handler->display->display_options['relationships']['field_parent_target_id']['field'] = 'field_parent_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '3';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::erpal_project_release_add_tasks_to_release' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_book_helper_clone_to_book_action' => array(
      'selected' => 0,
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
    'action::billable_delete_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_timetracking_export_basic_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_projects_helper_timetracking_finalise_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_project_release_remove_tasks_from_release' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_billed_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_unbilled_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '#';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_parent_target_id';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_project_ref_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
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
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
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
    8 => 0,
  );
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
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
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
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
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
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Category (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
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
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );

  /* Display: Tasks for release pane */
  $handler = $view->new_display('panel_pane', 'Tasks for release pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title' => 'title',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_task_type_term' => 'field_task_type_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_priority_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_type_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
    'erpal_task' => 'erpal_task',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Priority (field_priority_term) */
  $handler->display->display_options['filters']['field_priority_term_tid']['id'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['table'] = 'field_data_field_priority_term';
  $handler->display->display_options['filters']['field_priority_term_tid']['field'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator_id'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['label'] = 'Priority';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['operator'] = 'field_priority_term_tid_op';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['identifier'] = 'field_priority_term_tid';
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_priority_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_priority_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_priority_term_tid']['vocabulary'] = 'priority_terms';
  $handler->display->display_options['filters']['field_priority_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Status (field_task_status_term) */
  $handler->display->display_options['filters']['field_task_status_term_tid']['id'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['table'] = 'field_data_field_task_status_term';
  $handler->display->display_options['filters']['field_task_status_term_tid']['field'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator_id'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['operator'] = 'field_task_status_term_tid_op';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['identifier'] = 'field_task_status_term_tid';
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_status_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_task_status_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_status_term_tid']['vocabulary'] = 'task_status_terms';
  $handler->display->display_options['filters']['field_task_status_term_tid']['error_message'] = FALSE;
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
  /* Filter criterion: Content: Type (field_task_type_term) */
  $handler->display->display_options['filters']['field_task_type_term_tid']['id'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['filters']['field_task_type_term_tid']['field'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator_id'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['operator'] = 'field_task_type_term_tid_op';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['identifier'] = 'field_task_type_term_tid';
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_type_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_task_type_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_task_type_term_tid']['vocabulary'] = 'task_type_terms';
  $handler->display->display_options['filters']['field_task_type_term_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Category (field_project_tags) */
  $handler->display->display_options['filters']['field_project_tags_tid']['id'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['table'] = 'field_data_field_project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['field'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator_id'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['operator'] = 'field_project_tags_tid_op';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['identifier'] = 'field_project_tags_tid';
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_project_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_project_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_project_tags_tid']['vocabulary'] = 'project_tags';
  $handler->display->display_options['filters']['field_project_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Release (field_release_ref) */
  $handler->display->display_options['filters']['field_release_ref_target_id']['id'] = 'field_release_ref_target_id';
  $handler->display->display_options['filters']['field_release_ref_target_id']['table'] = 'field_data_field_release_ref';
  $handler->display->display_options['filters']['field_release_ref_target_id']['field'] = 'field_release_ref_target_id';
  $handler->display->display_options['filters']['field_release_ref_target_id']['operator'] = 'empty';
  /* Filter criterion: Content: Assigned To Users (field_task_assigned_users) */
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator_id'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['label'] = 'Assigned';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['operator'] = 'field_task_assigned_users_target_id_op';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['identifier'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_task_assigned_users_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Latest update';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['group_info']['label'] = 'Date (node)';
  $handler->display->display_options['filters']['date_filter']['group_info']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.changed' => 'node.changed',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_project_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Content: Project (field_project_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Tasks by release pane */
  $handler = $view->new_display('panel_pane', 'Tasks by release pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title' => 'title',
    'field_task_status_term' => 'field_task_status_term',
    'field_priority_term' => 'field_priority_term',
    'field_task_type_term' => 'field_task_type_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_date' => 'field_date',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_status_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_priority_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_task_type_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '3';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::erpal_project_release_add_tasks_to_release' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_book_helper_clone_to_book_action' => array(
      'selected' => 0,
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
    'action::billable_delete_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_timetracking_export_basic_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_projects_helper_timetracking_finalise_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
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
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::erpal_project_release_remove_tasks_from_release' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_billed_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_unbilled_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '#';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_task_type_term']['id'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['table'] = 'field_data_field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['field'] = 'field_task_type_term';
  $handler->display->display_options['fields']['field_task_type_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_parent_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Release (field_release_ref) */
  $handler->display->display_options['arguments']['field_release_ref_target_id']['id'] = 'field_release_ref_target_id';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['table'] = 'field_data_field_release_ref';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['field'] = 'field_release_ref_target_id';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_release_ref_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_release_ref_target_id']['validate_options']['types'] = array(
    'erpal_project_release' => 'erpal_project_release',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['tasks_for_release'] = array(
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
    t('No tasks available'),
    t('Content entity referenced from field_parent'),
    t('author'),
    t('#'),
    t('Task Title'),
    t('Status'),
    t('Priority'),
    t('Type'),
    t('Post date'),
    t('Updated date'),
    t('Deadline'),
    t('Title'),
    t('All'),
    t('Nid'),
    t('Category'),
    t('Assigned'),
    t('Tasks for release pane'),
    t('Latest update'),
    t('Date (node)'),
    t('View panes'),
    t('Tasks by release pane'),
  );
  $export['tasks_for_release'] = $view;

  return $export;
}
