<?php
/**
 * @file
 * erpal_crm_reports.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_crm_reports_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts_create_customer_forecast';
  $cat_item->name = 'ERPAL contacts: create customer forecast';
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
    'name' => 'ERPAL contacts: create customer forecast',
    'path' => 'node/%',
    'category' => 'Contacts',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-customer-forecast',
        'path_router' => 'node/add/erpal-customer-forecast',
        'path_original' => 'node/add/erpal-customer-forecast',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_contact_ref' => '[node:nid]',
          'qt-crm_report_tabs' => '5',
        ),
        'path_destination' => TRUE,
        'title' => 'Create new forecast',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'erpal_contacts_create_customer_forecast',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_contacts_create_customer_forecast'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_expense_forecast_add_exepense_forecast';
  $cat_item->name = 'ERPAL Expense forecast: Add exepense forecast';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Reports';
  $cat_item->path = 'reports/%type';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => '6',
            'case' => 0,
          ),
          'context' => 'tab_id',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
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
      'qt-crm_report_tabs' => array(
        'argument_name' => 'tab_id',
        'argument_type' => 'query',
        'position' => 'qt-crm_report_tabs',
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'tab_id',
          'use_tail' => 0,
        ),
      ),
    ),
    'name' => 'ERPAL Expense forecast: Add exepense forecast',
    'path' => 'reports/%type',
    'category' => 'Reports',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-expense-forecast',
        'path_router' => 'node/add/erpal-expense-forecast',
        'path_original' => 'node/add/erpal-expense-forecast',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create new expense forecast',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'erpal_expense_forecast_add_exepense_forecast',
    'path_original' => 'reports/%type?qt-crm_report_tabs=%tab_id',
    'path_pattern' => 'reports/%',
    'path_query' => array(
      'qt-crm_report_tabs' => '%tab_id',
    ),
    'path_router' => 'reports/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_expense_forecast_add_exepense_forecast'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_reports_crm_reports_dashboard';
  $cat_item->name = 'Erpal Reports: CRM reports dashboard';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'Reports';
  $cat_item->path = 'reports/%type';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(),
      'logic' => 'or',
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
    'name' => 'Erpal Reports: CRM reports dashboard',
    'path' => 'reports/%type',
    'category' => 'Reports',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'reports/crm',
        'path_router' => 'reports/crm',
        'path_original' => 'reports/crm',
        'path_pattern' => 'reports/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'CRM',
        'css_id' => '',
        'css_class' => 'report',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'reports_crm',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_reports_crm_reports_dashboard',
    'path_original' => 'reports/%type',
    'path_pattern' => 'reports/%',
    'path_query' => array(),
    'path_router' => 'reports/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_reports_crm_reports_dashboard'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_sales_forecast_add_sales_forecast';
  $cat_item->name = 'ERPAL Sales forecast: Add sales forecast';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Reports';
  $cat_item->path = 'reports/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => '5',
            'case' => 0,
          ),
          'context' => 'tab_id',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
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
      'qt-crm_report_tabs' => array(
        'argument_name' => 'tab_id',
        'argument_type' => 'query',
        'position' => 'qt-crm_report_tabs',
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'tab_id',
          'use_tail' => 0,
        ),
      ),
    ),
    'name' => 'ERPAL Sales forecast: Add sales forecast',
    'path' => 'reports/%',
    'category' => 'Reports',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-customer-forecast',
        'path_router' => 'node/add/erpal-customer-forecast',
        'path_original' => 'node/add/erpal-customer-forecast',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create new sales forecast',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'erpal_sales_forecast_add_sales_forecast',
    'path_original' => 'reports/%type?qt-crm_report_tabs=%tab_id',
    'path_pattern' => 'reports/%',
    'path_query' => array(
      'qt-crm_report_tabs' => '%tab_id',
    ),
    'path_router' => 'reports/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_sales_forecast_add_sales_forecast'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'forecast_plan_node';
  $cat_item->name = 'Forecast Plan Node';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'Reports';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'erpal_customer_forecast' => 'erpal_customer_forecast',
              'erpal_expense_forecast' => 'erpal_expense_forecast',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'reports/dashboard',
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
    'name' => 'Forecast Plan Node',
    'path' => 'node/%',
    'category' => 'Reports',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'reports/crm',
        'path_router' => 'reports/crm',
        'path_original' => 'reports/crm',
        'path_pattern' => 'reports/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'CRM',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => 'reports_crm',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      1 => array(
        'path' => 'reports/project',
        'path_router' => 'reports/project',
        'path_original' => 'reports/project',
        'path_pattern' => 'reports/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Projects',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'reports_projects',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'forecast_plan_node',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['forecast_plan_node'] = $cat_item;

  return $export;
}
