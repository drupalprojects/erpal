<?php
/**
 * @file
 * erpal_crm_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_crm_ui_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_activities';
  $cat_item->name = 'Erpal Activities';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Activities';
  $cat_item->path = 'activities';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'activities',
    'arguments' => array(),
    'name' => 'Erpal Activities',
    'path' => 'activities',
    'category' => 'Activities',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-crm-activity',
        'path_router' => 'node/add/erpal-crm-activity',
        'path_original' => 'node/add/erpal-crm-activity',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new activity',
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
    'machine_name' => 'erpal_activities',
    'path_original' => 'activities',
    'path_pattern' => 'activities',
    'path_query' => array(),
    'path_router' => 'activities',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -91;
  $export['erpal_activities'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_activities_aul_activity';
  $cat_item->name = 'Erpal Activities: AUL Activity';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Activities';
  $cat_item->path = 'node/%/aul';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_crm_activity' => 'erpal_crm_activity',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'activities',
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
    'name' => 'Erpal Activities: AUL Activity',
    'path' => 'node/%/aul',
    'category' => 'Activities',
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
    'machine_name' => 'erpal_activities_aul_activity',
    'path_original' => 'node/%node/aul',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/aul',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -87;
  $export['erpal_activities_aul_activity'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_activities_create_activity';
  $cat_item->name = 'Erpal Activities: Create Activity';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Activities';
  $cat_item->path = 'node/add/erpal-crm-activity';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'activities',
    'arguments' => array(),
    'name' => 'Erpal Activities: Create Activity',
    'path' => 'node/add/erpal-crm-activity',
    'category' => 'Activities',
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
    'machine_name' => 'erpal_activities_create_activity',
    'path_original' => 'node/add/erpal-crm-activity',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/add/erpal-crm-activity',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -90;
  $export['erpal_activities_create_activity'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_activities_edit_activity';
  $cat_item->name = 'Erpal Activities: Edit Activity';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Activities';
  $cat_item->path = 'node/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_crm_activity' => 'erpal_crm_activity',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'activities',
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
    'name' => 'Erpal Activities: Edit Activity',
    'path' => 'node/%/edit',
    'category' => 'Activities',
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
    'machine_name' => 'erpal_activities_edit_activity',
    'path_original' => 'node/%node/edit',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -88;
  $export['erpal_activities_edit_activity'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_activities_view_activity';
  $cat_item->name = 'Erpal Activities: View Activity';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Activities';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_crm_activity' => 'erpal_crm_activity',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'activities',
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
    'name' => 'Erpal Activities: View Activity',
    'path' => 'node/%',
    'category' => 'Activities',
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
    'machine_name' => 'erpal_activities_view_activity',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -89;
  $export['erpal_activities_view_activity'] = $cat_item;

  return $export;
}
