<?php
/**
 * @file
 * erpal_basic_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_basic_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'contact_node_breadcrumb';
  $path_breadcrumb->name = 'Contact node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contacts',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'contacts',
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
              'erpal_contact' => 'erpal_contact',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -99;
  $export['contact_node_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'contacts_view_breadcrumb';
  $path_breadcrumb->name = 'Contacts view breadcrumb';
  $path_breadcrumb->path = 'contacts';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Contacts',
    ),
    'paths' => array(
      0 => 'contacts',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -100;
  $export['contacts_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'general_node_view_breadcrumbs';
  $path_breadcrumb->name = 'General node view breadcrumbs';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:title',
    ),
    'paths' => array(
      0 => 'node/%node:nid',
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
    'access' => array(),
  );
  $path_breadcrumb->weight = -72;
  $export['general_node_view_breadcrumbs'] = $path_breadcrumb;

  return $export;
}
