<?php
/**
 * @file
 * erpal_contract_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_contract_ui_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_activities_actvity_view_contracts';
  $cat_item->name = 'Erpal activities: actvity view: contracts';
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
    'name' => 'Erpal activities: actvity view: contracts',
    'path' => 'node/%',
    'category' => 'Activities',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-contract',
        'path_router' => 'node/add/erpal-contract',
        'path_original' => 'node/add/erpal-contract',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_activity_ref' => '[node:nid]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create a new contract',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'erpal_activities_actvity_view_contracts',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -89;
  $export['erpal_activities_actvity_view_contracts'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts_contact_view_contracts';
  $cat_item->name = 'Erpal contacts: Contact view: contracts';
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
    'name' => 'Erpal contacts: Contact view: contracts',
    'path' => 'node/%',
    'category' => 'Contacts',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-contract',
        'path_router' => 'node/add/erpal-contract',
        'path_original' => 'node/add/erpal-contract',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'fied_customer_ref' => '[node:nid]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create a new contract',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'erpal_contacts_contact_view_contracts',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -95;
  $export['erpal_contacts_contact_view_contracts'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contracts';
  $cat_item->name = 'Erpal Contracts (default)';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contracts';
  $cat_item->path = 'contracts';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'contracts',
    'arguments' => array(),
    'name' => 'Erpal Contracts (default)',
    'path' => 'contracts',
    'category' => 'Contracts',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-contract',
        'path_router' => 'node/add/erpal-contract',
        'path_original' => 'node/add/erpal-contract',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new contract',
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
    'machine_name' => 'erpal_contracts',
    'path_original' => 'contracts',
    'path_pattern' => 'contracts',
    'path_query' => array(),
    'path_router' => 'contracts',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -12;
  $export['erpal_contracts'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contracts_aul_contract';
  $cat_item->name = 'Erpal Contracts: AUL Contract';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contracts';
  $cat_item->path = 'node/%/aul';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_contract' => 'erpal_contract',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'contracts',
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
    'name' => 'Erpal Contracts: AUL Contract',
    'path' => 'node/%/aul',
    'category' => 'Contracts',
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
    'machine_name' => 'erpal_contracts_aul_contract',
    'path_original' => 'node/%node/aul',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/aul',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -10;
  $export['erpal_contracts_aul_contract'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contracts_create_contract';
  $cat_item->name = 'Erpal Contracts: Create Contract';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contracts';
  $cat_item->path = 'node/add/erpal-contract';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'contracts',
    'arguments' => array(),
    'name' => 'Erpal Contracts: Create Contract',
    'path' => 'node/add/erpal-contract',
    'category' => 'Contracts',
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
    'machine_name' => 'erpal_contracts_create_contract',
    'path_original' => 'node/add/erpal-contract',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/add/erpal-contract',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -11;
  $export['erpal_contracts_create_contract'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contracts_edit_contract';
  $cat_item->name = 'Erpal Contracts: Edit Contract';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contracts';
  $cat_item->path = 'node/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_contract' => 'erpal_contract',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'contracts',
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
    'name' => 'Erpal Contracts: Edit Contract',
    'path' => 'node/%/edit',
    'category' => 'Contracts',
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
    'machine_name' => 'erpal_contracts_edit_contract',
    'path_original' => 'node/%node/edit',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -9;
  $export['erpal_contracts_edit_contract'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contracts_view_contract';
  $cat_item->name = 'Erpal Contracts: View Contract';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contracts';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_contract' => 'erpal_contract',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'contracts',
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
    'name' => 'Erpal Contracts: View Contract',
    'path' => 'node/%',
    'category' => 'Contracts',
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
    'machine_name' => 'erpal_contracts_view_contract',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -8;
  $export['erpal_contracts_view_contract'] = $cat_item;

  return $export;
}
