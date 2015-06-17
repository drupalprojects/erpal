<?php
/**
 * @file
 * erpal_crm_tasks.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_crm_tasks_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'crm_activity_by_task';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CRM Activity by task';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CRM activity';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_task_ref_node']['id'] = 'reverse_field_task_ref_node';
  $handler->display->display_options['relationships']['reverse_field_task_ref_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_task_ref_node']['field'] = 'reverse_field_task_ref_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_task_ref_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Task (field_task_ref) */
  $handler->display->display_options['arguments']['field_task_ref_target_id']['id'] = 'field_task_ref_target_id';
  $handler->display->display_options['arguments']['field_task_ref_target_id']['table'] = 'field_data_field_task_ref';
  $handler->display->display_options['arguments']['field_task_ref_target_id']['field'] = 'field_task_ref_target_id';
  $handler->display->display_options['arguments']['field_task_ref_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_task_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_task_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_task_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_task_ref_target_id']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_task_ref_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_crm_activity' => 'erpal_crm_activity',
  );

  /* Display: CRM Activity by task pane */
  $handler = $view->new_display('panel_pane', 'CRM Activity by task pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_task_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:comment.node',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Field: Task (field_task_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['crm_activity_by_task'] = array(
    t('Master'),
    t('CRM activity'),
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
    t('Content referencing Content from field_task_ref'),
    t('All'),
    t('CRM Activity by task pane'),
    t('View panes'),
  );
  $export['crm_activity_by_task'] = $view;

  return $export;
}
