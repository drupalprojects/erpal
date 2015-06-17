<?php
/**
 * @file
 * erpal_employee.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_employee_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_timekeeping';
  $cat_item->name = 'Erpal Timekeeping (default)';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Timekeeping';
  $cat_item->path = 'timekeeping';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'timekeeping',
    'arguments' => array(),
    'name' => 'Erpal Timekeeping (default)',
    'path' => 'timekeeping',
    'category' => 'Timekeeping',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-working-time',
        'path_router' => 'node/add/erpal-working-time',
        'path_original' => 'node/add/erpal-working-time',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new working time',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'timekeeping',
        'path_router' => 'timekeeping',
        'path_original' => 'timekeeping',
        'path_pattern' => 'timekeeping',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Timekeeping',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => TRUE,
        'machine_name' => 'timekeeping',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      1 => array(
        'path' => 'timekeeping/all',
        'path_router' => 'timekeeping/all',
        'path_original' => 'timekeeping/all',
        'path_pattern' => 'timekeeping/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All Timekeeping',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'timekeeping_all',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_timekeeping',
    'path_original' => 'timekeeping',
    'path_pattern' => 'timekeeping',
    'path_query' => array(),
    'path_router' => 'timekeeping',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = 6;
  $export['erpal_timekeeping'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_timekeeping_all';
  $cat_item->name = 'Erpal Timekeeping: All';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Timekeeping';
  $cat_item->path = 'timekeeping/all';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'timekeeping',
    'arguments' => array(),
    'name' => 'Erpal Timekeeping: All',
    'path' => 'timekeeping/all',
    'category' => 'Timekeeping',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'timekeeping',
        'path_router' => 'timekeeping',
        'path_original' => 'timekeeping',
        'path_pattern' => 'timekeeping',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Timekeeping',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_timekeeping|timekeeping',
      ),
      1 => array(
        'path' => 'timekeeping/all',
        'path_router' => 'timekeeping/all',
        'path_original' => 'timekeeping/all',
        'path_pattern' => 'timekeeping/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All Timekeeping',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_timekeeping|timekeeping_all',
      ),
    ),
    'machine_name' => 'erpal_timekeeping_all',
    'path_original' => 'timekeeping/all',
    'path_pattern' => 'timekeeping/%',
    'path_query' => array(),
    'path_router' => 'timekeeping/all',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 7;
  $export['erpal_timekeeping_all'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_timekeeping_create_working_time';
  $cat_item->name = 'Erpal Timekeeping: Create Working time';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Timekeeping';
  $cat_item->path = 'node/add/erpal-working-time';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'timekeeping',
    'arguments' => array(),
    'name' => 'Erpal Timekeeping: Create Working time',
    'path' => 'node/add/erpal-working-time',
    'category' => 'Timekeeping',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'timekeeping',
        'path_router' => 'timekeeping',
        'path_original' => 'timekeeping',
        'path_pattern' => 'timekeeping',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Timekeeping',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_timekeeping|timekeeping',
      ),
      1 => array(
        'path' => 'timekeeping/all',
        'path_router' => 'timekeeping/all',
        'path_original' => 'timekeeping/all',
        'path_pattern' => 'timekeeping/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All Timekeeping',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_timekeeping|timekeeping_all',
      ),
    ),
    'machine_name' => 'erpal_timekeeping_create_working_time',
    'path_original' => 'node/add/erpal-working-time',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/add/erpal-working-time',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 10;
  $export['erpal_timekeeping_create_working_time'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_timekeeping_edit_working_time';
  $cat_item->name = 'Erpal Timekeeping: Edit Working time';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Timekeeping';
  $cat_item->path = 'node/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_working_time' => 'erpal_working_time',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'timekeeping',
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
    'name' => 'Erpal Timekeeping: Edit Working time',
    'path' => 'node/%/edit',
    'category' => 'Timekeeping',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'timekeeping',
        'path_router' => 'timekeeping',
        'path_original' => 'timekeeping',
        'path_pattern' => 'timekeeping',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Timekeeping',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_timekeeping|timekeeping',
      ),
      1 => array(
        'path' => 'timekeeping/all',
        'path_router' => 'timekeeping/all',
        'path_original' => 'timekeeping/all',
        'path_pattern' => 'timekeeping/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All Timekeeping',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_timekeeping|timekeeping_all',
      ),
    ),
    'machine_name' => 'erpal_timekeeping_edit_working_time',
    'path_original' => 'node/%node/edit',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 9;
  $export['erpal_timekeeping_edit_working_time'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_timekeeping_view_working_time';
  $cat_item->name = 'Erpal Timekeeping: View Working time';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Timekeeping';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_working_time' => 'erpal_working_time',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'timekeeping',
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
    'name' => 'Erpal Timekeeping: View Working time',
    'path' => 'node/%',
    'category' => 'Timekeeping',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'timekeeping',
        'path_router' => 'timekeeping',
        'path_original' => 'timekeeping',
        'path_pattern' => 'timekeeping',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Timekeeping',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_timekeeping|timekeeping',
      ),
      1 => array(
        'path' => 'timekeeping/all',
        'path_router' => 'timekeeping/all',
        'path_original' => 'timekeeping/all',
        'path_pattern' => 'timekeeping/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All Timekeeping',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_timekeeping|timekeeping_all',
      ),
    ),
    'machine_name' => 'erpal_timekeeping_view_working_time',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 8;
  $export['erpal_timekeeping_view_working_time'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_user_timekeeping_offsets';
  $cat_item->name = 'Erpal User: Timekeeping offset';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'User';
  $cat_item->path = 'user/%/timekeeping-offsets';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'arguments' => array(
      1 => array(
        'argument_name' => 'user',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'name' => 'Erpal User: Timekeeping offset',
    'path' => 'user/%/timekeeping-offsets',
    'category' => 'User',
    'cat_actions' => array(
      0 => array(
        'path' => 'working_times/add/[user:uid]',
        'path_router' => 'working_times/add/[user:uid]',
        'path_original' => 'working_times/add/[user:uid]',
        'path_pattern' => 'working_times/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new offset',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'user/[user:uid]/notifications',
        'path_router' => 'user/[user:uid]/notifications',
        'path_original' => 'user/[user:uid]/notifications',
        'path_pattern' => 'user/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Notifications',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_user_view|notifications',
      ),
    ),
    'machine_name' => 'erpal_user_timekeeping_offsets',
    'path_original' => 'user/%user/timekeeping-offsets',
    'path_pattern' => 'user/%/%',
    'path_query' => array(),
    'path_router' => 'user/%/timekeeping-offsets',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_user_timekeeping_offsets'] = $cat_item;

  return $export;
}
