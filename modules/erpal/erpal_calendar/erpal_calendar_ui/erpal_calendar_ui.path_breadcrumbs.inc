<?php
/**
 * @file
 * erpal_calendar_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_calendar_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'calendar_own_view_breadcrumb';
  $path_breadcrumb->name = 'Calendar own view breadcrumb';
  $path_breadcrumb->path = 'calendar/%type';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Calendar',
    ),
    'paths' => array(
      0 => 'calendar/%type',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'type' => array(
        'position' => 1,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -78;
  $export['calendar_own_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'date_item_entity_breadcrumb';
  $path_breadcrumb->name = 'Date item entity breadcrumb';
  $path_breadcrumb->path = 'date_item/%date_item_id';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Calendar',
    ),
    'paths' => array(
      0 => 'calendar/own',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'date_item_id' => array(
        'position' => 1,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = -77;
  $export['date_item_entity_breadcrumb'] = $path_breadcrumb;

  return $export;
}
