<?php
/**
 * @file
 * erpal_docs_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_docs_ui_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_files';
  $cat_item->name = 'Erpal Files (default)';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Files';
  $cat_item->path = 'files';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'files',
    'arguments' => array(),
    'name' => 'Erpal Files (default)',
    'path' => 'files',
    'category' => 'Files',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-file',
        'path_router' => 'node/add/erpal-file',
        'path_original' => 'node/add/erpal-file',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new file',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'dashboard',
        'path_router' => 'dashboard',
        'path_original' => 'dashboard',
        'path_pattern' => 'dashboard',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Home',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_home|erpal_home',
      ),
    ),
    'machine_name' => 'erpal_files',
    'path_original' => 'files',
    'path_pattern' => 'files',
    'path_query' => array(),
    'path_router' => 'files',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -31;
  $export['erpal_files'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_files_aul_file';
  $cat_item->name = 'Erpal Files: AUL File';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Files';
  $cat_item->path = 'node/%/aul';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
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
    'active_trail_path' => 'files',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Files: AUL File',
    'path' => 'node/%/aul',
    'category' => 'Files',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'dashboard',
        'path_router' => 'dashboard',
        'path_original' => 'dashboard',
        'path_pattern' => 'dashboard',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Home',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_home|erpal_home',
      ),
    ),
    'machine_name' => 'erpal_files_aul_file',
    'path_original' => 'node/%node/aul',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/aul',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -27;
  $export['erpal_files_aul_file'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_files_create_file';
  $cat_item->name = 'Erpal Files: Create File';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Files';
  $cat_item->path = 'node/add/erpal-file';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'files',
    'arguments' => array(),
    'name' => 'Erpal Files: Create File',
    'path' => 'node/add/erpal-file',
    'category' => 'Files',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'dashboard',
        'path_router' => 'dashboard',
        'path_original' => 'dashboard',
        'path_pattern' => 'dashboard',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Home',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_home|erpal_home',
      ),
    ),
    'machine_name' => 'erpal_files_create_file',
    'path_original' => 'node/add/erpal-file',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/add/erpal-file',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -29;
  $export['erpal_files_create_file'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_files_edit_file';
  $cat_item->name = 'Erpal Files: Edit File';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Files';
  $cat_item->path = 'node/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
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
    'active_trail_path' => 'files',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Files: Edit File',
    'path' => 'node/%/edit',
    'category' => 'Files',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'dashboard',
        'path_router' => 'dashboard',
        'path_original' => 'dashboard',
        'path_pattern' => 'dashboard',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Home',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_home|erpal_home',
      ),
    ),
    'machine_name' => 'erpal_files_edit_file',
    'path_original' => 'node/%node/edit',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -28;
  $export['erpal_files_edit_file'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_files_view_file';
  $cat_item->name = 'Erpal Files: View File';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Files';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
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
    'active_trail_path' => 'files',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Files: View File',
    'path' => 'node/%',
    'category' => 'Files',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'dashboard',
        'path_router' => 'dashboard',
        'path_original' => 'dashboard',
        'path_pattern' => 'dashboard',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Home',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_home|erpal_home',
      ),
    ),
    'machine_name' => 'erpal_files_view_file',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -30;
  $export['erpal_files_view_file'] = $cat_item;

  return $export;
}
