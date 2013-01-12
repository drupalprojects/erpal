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

  /* Display: Full calendar pane */
  $handler = $view->new_display('panel_pane', 'Full calendar pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['full_calendar'] = $view;

  return $export;
}
