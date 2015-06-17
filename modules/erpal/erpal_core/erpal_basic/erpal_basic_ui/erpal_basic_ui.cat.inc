<?php
/**
 * @file
 * erpal_basic_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_basic_ui_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'all_nodes_aul_manage';
  $cat_item->name = 'All Nodes: AUL manage and Node edit';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Nodes';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => '',
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
    'name' => 'All Nodes: AUL manage and Node edit',
    'path' => 'node/%',
    'category' => 'Nodes',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/[node:nid]/aul',
        'path_router' => 'node/[node:nid]/aul',
        'path_original' => 'node/[node:nid]/aul',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Manage user access',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      1 => array(
        'path' => 'node/[node:nid]/edit',
        'path_router' => 'node/[node:nid]/edit',
        'path_original' => 'node/[node:nid]/edit',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Edit this [node:content-type]',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'all_nodes_aul_manage',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 5;
  $export['all_nodes_aul_manage'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'delete_log_tab';
  $cat_item->name = 'Delete log tab';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'node';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => '',
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
    'name' => 'Delete log tab',
    'path' => 'node/%',
    'category' => 'node',
    'cat_actions' => array(),
    'cat_tabs' => array(),
    'machine_name' => 'delete_log_tab',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(
      0 => array(
        'path' => 'node/%/log',
        'path_router' => 'node/%/log',
        'path_original' => 'node/%node/log',
        'path_pattern' => 'node/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
    ),
  );
  $cat_item->weight = 0;
  $export['delete_log_tab'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts';
  $cat_item->name = 'Erpal Contacts';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contacts';
  $cat_item->path = 'contacts';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(),
    'name' => 'Erpal Contacts',
    'path' => 'contacts',
    'category' => 'Contacts',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-contact',
        'path_router' => 'node/add/erpal-contact',
        'path_original' => 'node/add/erpal-contact',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new contact',
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
      1 => array(
        'path' => 'import/erpal-contacts-import',
        'path_router' => 'import/erpal-contacts-import',
        'path_original' => 'import/erpal-contacts-import',
        'path_pattern' => 'import/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Contacts importer',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_contacts',
    'path_original' => 'contacts',
    'path_pattern' => 'contacts',
    'path_query' => array(),
    'path_router' => 'contacts',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -99;
  $export['erpal_contacts'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts_aul_contact';
  $cat_item->name = 'Erpal Contacts: AUL of Contact';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contacts';
  $cat_item->path = 'node/%node/aul';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
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
    'active_trail_path' => 'contacts',
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
    'name' => 'Erpal Contacts: AUL of Contact',
    'path' => 'node/%node/aul',
    'category' => 'Contacts',
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
    'machine_name' => 'erpal_contacts_aul_contact',
    'path_original' => 'node/%node/aul',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/aul',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -93;
  $export['erpal_contacts_aul_contact'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts_create_contact';
  $cat_item->name = 'Erpal Contacts: Create Contact';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contacts';
  $cat_item->path = 'node/add/erpal-contact';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'active_trail_path' => 'contacts',
    'arguments' => array(),
    'name' => 'Erpal Contacts: Create Contact',
    'path' => 'node/add/erpal-contact',
    'category' => 'Contacts',
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
    'machine_name' => 'erpal_contacts_create_contact',
    'path_original' => 'node/add/erpal-contact',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/add/erpal-contact',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -98;
  $export['erpal_contacts_create_contact'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts_edit_contact';
  $cat_item->name = 'Erpal Contacts: Edit Contact';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contacts';
  $cat_item->path = 'node/%node/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
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
    'active_trail_path' => 'contacts',
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
    'name' => 'Erpal Contacts: Edit Contact',
    'path' => 'node/%node/edit',
    'category' => 'Contacts',
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
    'machine_name' => 'erpal_contacts_edit_contact',
    'path_original' => 'node/%node/edit',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -94;
  $export['erpal_contacts_edit_contact'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts_view_contact';
  $cat_item->name = 'Erpal Contacts: View Contact';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contacts';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
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
    'active_trail_path' => 'contacts',
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
    'name' => 'Erpal Contacts: View Contact',
    'path' => 'node/%',
    'category' => 'Contacts',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-crm-activity',
        'path_router' => 'node/add/erpal-crm-activity',
        'path_original' => 'node/add/erpal-crm-activity',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_customer_ref' => '[node:nid]',
        ),
        'path_destination' => FALSE,
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
    'machine_name' => 'erpal_contacts_view_contact',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -96;
  $export['erpal_contacts_view_contact'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_home';
  $cat_item->name = 'Erpal Home';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'General';
  $cat_item->path = 'dashboard';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'arguments' => array(),
    'name' => 'Erpal Home',
    'path' => 'dashboard',
    'category' => 'General',
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
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => TRUE,
        'machine_name' => 'erpal_home',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_home',
    'path_original' => 'dashboard',
    'path_pattern' => 'dashboard',
    'path_query' => array(),
    'path_router' => 'dashboard',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -100;
  $export['erpal_home'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'node_disable_general_tabs';
  $cat_item->name = 'Node disable general tabs';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'Generali';
  $cat_item->path = 'node/%node';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => '',
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
    'name' => 'Node disable general tabs',
    'path' => 'node/%node',
    'category' => 'Generali',
    'cat_actions' => array(),
    'cat_tabs' => array(),
    'machine_name' => 'node_disable_general_tabs',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(
      0 => array(
        'path' => 'node/%/edit',
        'path_router' => 'node/%/edit',
        'path_original' => 'node/%node/edit',
        'path_pattern' => 'node/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      1 => array(
        'path' => 'node/%/aul',
        'path_router' => 'node/%/aul',
        'path_original' => 'node/%node/aul',
        'path_pattern' => 'node/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      2 => array(
        'path' => 'node/%/devel',
        'path_router' => 'node/%/devel',
        'path_original' => 'node/%node/devel',
        'path_pattern' => 'node/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      3 => array(
        'path' => 'node/%/view',
        'path_router' => 'node/%/view',
        'path_original' => 'node/%node/view',
        'path_pattern' => 'node/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      4 => array(
        'path' => 'node/%/revisions',
        'path_router' => 'node/%/revisions',
        'path_original' => 'node/%node/revisions',
        'path_pattern' => 'node/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      5 => array(
        'path' => 'node/%/repeats',
        'path_router' => 'node/%/repeats',
        'path_original' => 'node/%node/repeats',
        'path_pattern' => 'node/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
    ),
  );
  $cat_item->weight = 4;
  $export['node_disable_general_tabs'] = $cat_item;

  return $export;
}
