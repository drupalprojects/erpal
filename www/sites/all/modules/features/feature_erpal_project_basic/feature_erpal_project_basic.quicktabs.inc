<?php
/**
 * @file
 * feature_erpal_project_basic.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function feature_erpal_project_basic_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'task_content_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Task content tabs';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_body_and_comments',
      'hide_title' => 1,
      'title' => 'Details',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'vid' => 'tasks',
      'display' => 'panel_pane_5',
      'args' => '%1',
      'title' => 'Subtasks (list)',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'tasks',
      'display' => 'panel_pane_4',
      'args' => '%1',
      'title' => 'Subtasks (tree)',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'tasks',
      'display' => 'panel_pane_9',
      'args' => '%1',
      'title' => 'Subtasks (details)',
      'weight' => '-97',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Subtasks (details)');
  t('Subtasks (list)');
  t('Subtasks (tree)');
  t('Task content tabs');

  $export['task_content_tabs'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'tasks_by_project_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Tasks by project tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'tasks',
      'display' => 'panel_pane_10',
      'args' => '%1',
      'title' => 'List',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'tasks',
      'display' => 'panel_pane_1',
      'args' => '%1',
      'title' => 'Tree',
      'weight' => '-98',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'tasks',
      'display' => 'panel_pane_8',
      'args' => '%1',
      'title' => 'Details',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('List');
  t('Tasks by project tabs');
  t('Tree');

  $export['tasks_by_project_tabs'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'ticket_content_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Ticket content tabs';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_body_and_comments',
      'hide_title' => 1,
      'title' => 'Details',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'vid' => 'tickets',
      'display' => 'panel_pane_5',
      'args' => '%1',
      'title' => 'Subtickets (list)',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'tickets',
      'display' => 'panel_pane_4',
      'args' => '%1',
      'title' => 'Subtickets (tree)',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'tickets',
      'display' => 'panel_pane_9',
      'args' => '%1',
      'title' => 'Subtickets (details)',
      'weight' => '-97',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Subtickets (details)');
  t('Subtickets (list)');
  t('Subtickets (tree)');
  t('Ticket content tabs');

  $export['ticket_content_tabs'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'tickets_by_project_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Tickets by project tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'tickets',
      'display' => 'panel_pane_10',
      'args' => '%1',
      'title' => 'List',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'tickets',
      'display' => 'panel_pane_1',
      'args' => '%1',
      'title' => 'Tree',
      'weight' => '-98',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'tickets',
      'display' => 'panel_pane_8',
      'args' => '%1',
      'title' => 'Details',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('List');
  t('Tickets by project tabs');
  t('Tree');

  $export['tickets_by_project_tabs'] = $quicktabs;

  return $export;
}
