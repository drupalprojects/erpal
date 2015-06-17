<?php
/**
 * @file
 * erpal_project_reports.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_project_reports_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_reports_project_reports';
  $cat_item->name = 'Erpal Reports: Project reports dashboard';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'Reports';
  $cat_item->path = 'reports/%type';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'active_trail_path' => 'reports/dashboard',
    'arguments' => array(
      1 => array(
        'argument_name' => 'type',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'String',
          'use_tail' => 0,
        ),
      ),
    ),
    'name' => 'Erpal Reports: Project reports dashboard',
    'path' => 'reports/%type',
    'category' => 'Reports',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'reports/project',
        'path_router' => 'reports/project',
        'path_original' => 'reports/project',
        'path_pattern' => 'reports/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Projects',
        'css_id' => '',
        'css_class' => 'report',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'reports_crm',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_reports_project_reports',
    'path_original' => 'reports/%type',
    'path_pattern' => 'reports/%',
    'path_query' => array(),
    'path_router' => 'reports/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_reports_project_reports'] = $cat_item;

  return $export;
}
