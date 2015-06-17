<?php
/**
 * @file
 * erpal_calendar_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_calendar_ui_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_calendar';
  $cat_item->name = 'Erpal Calendar (default)';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Calendar';
  $cat_item->path = 'calendar/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'active_trail_path' => 'calendar/own',
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
    'name' => 'Erpal Calendar (default)',
    'path' => 'calendar/%',
    'category' => 'Calendar',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-date',
        'path_router' => 'node/add/erpal-date',
        'path_original' => 'node/add/erpal-date',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new date',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'calendar/own',
        'path_router' => 'calendar/own',
        'path_original' => 'calendar/own',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Own calendar',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'calendar',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      1 => array(
        'path' => 'calendar/all',
        'path_router' => 'calendar/all',
        'path_original' => 'calendar/all',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Global calendar',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'global_calendar',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      2 => array(
        'path' => 'calendar/holidays',
        'path_router' => 'calendar/holidays',
        'path_original' => 'calendar/holidays',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All holidays',
        'css_id' => '',
        'css_class' => 'global-calendar',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'all_holidays',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_calendar',
    'path_original' => 'calendar/%type',
    'path_pattern' => 'calendar/%',
    'path_query' => array(),
    'path_router' => 'calendar/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -18;
  $export['erpal_calendar'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_calendar_create_date';
  $cat_item->name = 'Erpal Calendar: Create Date';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Calendar';
  $cat_item->path = 'node/add/erpal-date';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'active_trail_path' => 'calendar/own',
    'arguments' => array(),
    'name' => 'Erpal Calendar: Create Date',
    'path' => 'node/add/erpal-date',
    'category' => 'Calendar',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'calendar/own',
        'path_router' => 'calendar/own',
        'path_original' => 'calendar/own',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Own calendar',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|calendar',
      ),
      1 => array(
        'path' => 'calendar/all',
        'path_router' => 'calendar/all',
        'path_original' => 'calendar/all',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Global calendar',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|global_calendar',
      ),
      2 => array(
        'path' => 'calendar/holidays',
        'path_router' => 'calendar/holidays',
        'path_original' => 'calendar/holidays',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All holidays',
        'css_id' => '',
        'css_class' => 'global-calendar',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'all_holidays',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_calendar_create_date',
    'path_original' => 'node/add/erpal-date',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/add/erpal-date',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -15;
  $export['erpal_calendar_create_date'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_calendar_edit_data';
  $cat_item->name = 'Erpal Calendar: Edit Data';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Calendar';
  $cat_item->path = 'date_item/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:date_item',
          'settings' => array(
            'type' => array(
              'simple_date' => 'simple_date',
            ),
          ),
          'context' => 'date_item',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'calendar/own',
    'arguments' => array(
      1 => array(
        'argument_name' => 'date_item',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:date_item',
        'settings' => array(
          'identifier' => 'date item: ID',
        ),
      ),
    ),
    'name' => 'Erpal Calendar: Edit Data',
    'path' => 'date_item/%/edit',
    'category' => 'Calendar',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'calendar/own',
        'path_router' => 'calendar/own',
        'path_original' => 'calendar/own',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Own calendar',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|calendar',
      ),
      1 => array(
        'path' => 'calendar/all',
        'path_router' => 'calendar/all',
        'path_original' => 'calendar/all',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Global calendar',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|global_calendar',
      ),
      2 => array(
        'path' => 'calendar/holidays',
        'path_router' => 'calendar/holidays',
        'path_original' => 'calendar/holidays',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All holidays',
        'css_id' => '',
        'css_class' => 'global-calendar',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'all_holidays',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_calendar_edit_data',
    'path_original' => 'date_item/%date_item/edit',
    'path_pattern' => 'date_item/%/%',
    'path_query' => array(),
    'path_router' => 'date_item/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -14;
  $export['erpal_calendar_edit_data'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_calendar_hide_date_item_tabs';
  $cat_item->name = 'Erpal calendar: hide date item tabs';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Calendar';
  $cat_item->path = 'date_item/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(
      1 => array(
        'argument_name' => 'date_item',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:date_item',
        'settings' => array(
          'identifier' => 'date item: ID',
        ),
      ),
    ),
    'name' => 'Erpal calendar: hide date item tabs',
    'path' => 'date_item/%',
    'category' => 'Calendar',
    'cat_actions' => array(),
    'cat_tabs' => array(),
    'machine_name' => 'erpal_calendar_hide_date_item_tabs',
    'path_original' => 'date_item/%date_item',
    'path_pattern' => 'date_item/%',
    'path_query' => array(),
    'path_router' => 'date_item/%',
    'reusable' => 0,
    'cat_remove' => array(
      0 => array(
        'path' => 'date_item/%/view',
        'path_router' => 'date_item/%/view',
        'path_original' => 'date_item/%date_item/view',
        'path_pattern' => 'date_item/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      1 => array(
        'path' => 'date_item/%/edit',
        'path_router' => 'date_item/%/edit',
        'path_original' => 'date_item/%date_item/edit',
        'path_pattern' => 'date_item/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
    ),
  );
  $cat_item->weight = 0;
  $export['erpal_calendar_hide_date_item_tabs'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_calendar_legend';
  $cat_item->name = 'Erpal Calendar: Legend';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Calendar';
  $cat_item->path = 'taxonomy/term/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'vids' => array(
              19 => '19',
            ),
          ),
          'context' => 'taxonomy_term',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'calendar/own',
    'arguments' => array(
      2 => array(
        'argument_name' => 'taxonomy_term',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            19 => '19',
            9 => 0,
            10 => 0,
            1 => 0,
            2 => 0,
            3 => 0,
            4 => 0,
            20 => 0,
            5 => 0,
            18 => 0,
            7 => 0,
            6 => 0,
            13 => 0,
            14 => 0,
            15 => 0,
            12 => 0,
            11 => 0,
            8 => 0,
            16 => 0,
            17 => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 0,
        ),
      ),
    ),
    'name' => 'Erpal Calendar: Legend',
    'path' => 'taxonomy/term/%',
    'category' => 'Calendar',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'calendar/own',
        'path_router' => 'calendar/own',
        'path_original' => 'calendar/own',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Own calendar',
        'css_id' => '',
        'css_class' => 'active-trail',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|calendar',
      ),
      1 => array(
        'path' => 'calendar/all',
        'path_router' => 'calendar/all',
        'path_original' => 'calendar/all',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Global calendar',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|global_calendar',
      ),
    ),
    'machine_name' => 'erpal_calendar_legend',
    'path_original' => 'taxonomy/term/%taxonomy_term',
    'path_pattern' => 'taxonomy/%/%',
    'path_query' => array(),
    'path_router' => 'taxonomy/term/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -17;
  $export['erpal_calendar_legend'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_calendar_view_data';
  $cat_item->name = 'Erpal Calendar: View Data';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Calendar';
  $cat_item->path = 'date_item/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:date_item',
          'settings' => array(
            'type' => array(
              'simple_date' => 'simple_date',
            ),
          ),
          'context' => 'date_item',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'calendar/own',
    'arguments' => array(
      1 => array(
        'argument_name' => 'date_item',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:date_item',
        'settings' => array(
          'identifier' => 'date item: ID',
        ),
      ),
    ),
    'name' => 'Erpal Calendar: View Data',
    'path' => 'date_item/%',
    'category' => 'Calendar',
    'cat_actions' => array(
      0 => array(
        'path' => 'date_item/[date_item:date-item-id]/edit',
        'path_router' => 'date_item/[date_item:date-item-id]/edit',
        'path_original' => 'date_item/[date_item:date-item-id]/edit',
        'path_pattern' => 'date_item/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Edit this single date',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      1 => array(
        'path' => 'node/[date_item:src-id]/edit',
        'path_router' => 'node/[date_item:src-id]/edit',
        'path_original' => 'node/[date_item:src-id]/edit',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Edit the [date_item:src-type]',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'calendar/own',
        'path_router' => 'calendar/own',
        'path_original' => 'calendar/own',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Own calendar',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|calendar',
      ),
      1 => array(
        'path' => 'calendar/all',
        'path_router' => 'calendar/all',
        'path_original' => 'calendar/all',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Global calendar',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|global_calendar',
      ),
      2 => array(
        'path' => 'calendar/holidays',
        'path_router' => 'calendar/holidays',
        'path_original' => 'calendar/holidays',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All holidays',
        'css_id' => '',
        'css_class' => 'global-calendar',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'all_holidays',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_calendar_view_data',
    'path_original' => 'date_item/%date_item',
    'path_pattern' => 'date_item/%',
    'path_query' => array(),
    'path_router' => 'date_item/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -16;
  $export['erpal_calendar_view_data'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_calendar_view_date_node';
  $cat_item->name = 'ERPAL Calendar:  View date node';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'Calendar';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'erpal_date' => 'erpal_date',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'calendar/own',
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
    'name' => 'ERPAL Calendar:  View date node',
    'path' => 'node/%',
    'category' => 'Calendar',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'calendar/own',
        'path_router' => 'calendar/own',
        'path_original' => 'calendar/own',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Own calendar',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|calendar',
      ),
      1 => array(
        'path' => 'calendar/all',
        'path_router' => 'calendar/all',
        'path_original' => 'calendar/all',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Global calendar',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_calendar|global_calendar',
      ),
      2 => array(
        'path' => 'calendar/holidays',
        'path_router' => 'calendar/holidays',
        'path_original' => 'calendar/holidays',
        'path_pattern' => 'calendar/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'All holidays',
        'css_id' => '',
        'css_class' => 'global-calendar',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'all_holidays',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_calendar_view_date_node',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_calendar_view_date_node'] = $cat_item;

  return $export;
}
