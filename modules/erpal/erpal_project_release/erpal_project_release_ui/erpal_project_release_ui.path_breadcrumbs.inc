<?php
/**
 * @file
 * erpal_project_release_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_project_release_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'project_releases_view_breadcrumb';
  $path_breadcrumb->name = 'Project releases view breadcrumb';
  $path_breadcrumb->path = 'node/%node/releases';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:title',
      2 => 'Releases',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:nid',
      2 => 'node/%node:nid/releases',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -88;
  $export['project_releases_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'release_node_breadcrumb';
  $path_breadcrumb->name = 'Release node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:field-project-ref:title',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:field-project-ref:nid',
      2 => 'node/%node:nid',
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
              'erpal_project_release' => 'erpal_project_release',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -86;
  $export['release_node_breadcrumb'] = $path_breadcrumb;

  return $export;
}
