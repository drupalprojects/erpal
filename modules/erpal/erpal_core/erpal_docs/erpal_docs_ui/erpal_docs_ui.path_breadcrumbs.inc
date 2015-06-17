<?php
/**
 * @file
 * erpal_docs_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_docs_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'file_node_breadcrumb';
  $path_breadcrumb->name = 'File node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Files',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'files',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'erpal_file' => 'erpal_file',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -81;
  $export['file_node_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'files_view_breadcrumb';
  $path_breadcrumb->name = 'Files view breadcrumb';
  $path_breadcrumb->path = 'files';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Files',
    ),
    'paths' => array(
      0 => 'files',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -82;
  $export['files_view_breadcrumb'] = $path_breadcrumb;

  return $export;
}
