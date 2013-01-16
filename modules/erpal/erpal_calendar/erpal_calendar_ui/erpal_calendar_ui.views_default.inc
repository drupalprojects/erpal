<?php
/**
 * @file
 * erpal_calendar_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_calendar_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'full_calendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'date_item';
  $view->human_name = 'full calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['fields']['title'] = TRUE;
  /* Relationship: Date item: Referenced source node */
  $handler->display->display_options['relationships']['src_id']['id'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['table'] = 'date_item';
  $handler->display->display_options['relationships']['src_id']['field'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['required'] = TRUE;
  /* Field: date item: Date */
  $handler->display->display_options['fields']['field_date_item_date']['id'] = 'field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['table'] = 'field_data_field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['field'] = 'field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'src_id';
  /* Filter criterion: date item: Date tags (field_date_item_tags) */
  $handler->display->display_options['filters']['field_date_item_tags_tid']['id'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['table'] = 'field_data_field_date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['field'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator_id'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['label'] = 'Date categories';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['identifier'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['vocabulary'] = 'date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['error_message'] = FALSE;

  /* Display: Full calendar pane */
  $handler = $view->new_display('panel_pane', 'Full calendar pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['full_calendar'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('relation src node'),
    t('Date'),
    t('Title'),
    t('Date categories'),
    t('Full calendar pane'),
    t('View panes'),
  );
  $export['full_calendar'] = $view;

  return $export;
}
