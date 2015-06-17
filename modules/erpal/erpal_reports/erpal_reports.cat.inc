<?php
/**
 * @file
 * erpal_reports.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_reports_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_crm_reports_detail_view';
  $cat_item->name = 'ERPAL CRM Reports detail view';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'ERPAL reports';
  $cat_item->path = 'erpal/reports/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:erpal_reports',
          'settings' => array(
            'type' => array(
              'erpal_crm_customer_reports' => 'erpal_crm_customer_reports',
              'erpal_crm_expense_reports' => 'erpal_crm_expense_reports',
              'erpal_crm_lead_reports' => 'erpal_crm_lead_reports',
              'erpal_crm_sales_forecast_reports' => 'erpal_crm_sales_forecast_reports',
              'erpal_crm_sales_reports' => 'erpal_crm_sales_reports',
            ),
          ),
          'context' => 'erpal_reports',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'reports/dashboard',
    'arguments' => array(
      2 => array(
        'argument_name' => 'erpal_reports',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:erpal_reports',
        'settings' => array(
          'identifier' => 'ERPAL Reports: ID',
        ),
      ),
    ),
    'name' => 'ERPAL CRM Reports detail view',
    'path' => 'erpal/reports/%',
    'category' => 'ERPAL reports',
    'cat_actions' => array(
      0 => array(
        'path' => 'erpal/reports/[erpal_reports:id]/edit',
        'path_router' => 'erpal/reports/[erpal_reports:id]/edit',
        'path_original' => 'erpal/reports/[erpal_reports:id]/edit',
        'path_pattern' => 'erpal/%/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Edit',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'reports/project',
        'path_router' => 'reports/project',
        'path_original' => 'reports/project',
        'path_pattern' => 'reports/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Projects',
        'css_id' => '',
        'css_class' => 'reports_project',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'report_projects',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      1 => array(
        'path' => 'reports/crm',
        'path_router' => 'reports/crm',
        'path_original' => 'reports/crm',
        'path_pattern' => 'reports/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'CRM',
        'css_id' => '',
        'css_class' => 'reports_crm',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => 'report_crm',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_crm_reports_detail_view',
    'path_original' => 'erpal/reports/%erpal_reports',
    'path_pattern' => 'erpal/%/%',
    'path_query' => array(),
    'path_router' => 'erpal/reports/%',
    'reusable' => 0,
    'cat_remove' => array(
      0 => array(
        'path' => 'erpal/reports/%/view',
        'path_router' => 'erpal/reports/%/view',
        'path_original' => 'erpal/reports/%erpal_reports/view',
        'path_pattern' => 'erpal/%/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      1 => array(
        'path' => 'erpal/reports/%/edit',
        'path_router' => 'erpal/reports/%/edit',
        'path_original' => 'erpal/reports/%erpal_reports/edit',
        'path_pattern' => 'erpal/%/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
    ),
  );
  $cat_item->weight = 0;
  $export['erpal_crm_reports_detail_view'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_project_reports_detail_view';
  $cat_item->name = 'ERPAL Project Reports detail view';
  $cat_item->catch_subpaths = 1;
  $cat_item->category = 'ERPAL reports';
  $cat_item->path = 'erpal/reports/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:erpal_reports',
          'settings' => array(
            'type' => array(
              'erpal_project_active_projects_reports' => 'erpal_project_active_projects_reports',
              'erpal_project_management_reports' => 'erpal_project_management_reports',
              'erpal_project_profit_margin_reports' => 'erpal_project_profit_margin_reports',
              'erpal_project_timetracking_reports' => 'erpal_project_timetracking_reports',
            ),
          ),
          'context' => 'erpal_reports',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'reports/dashboard',
    'arguments' => array(
      2 => array(
        'argument_name' => 'erpal_reports',
        'argument_type' => 'path',
        'position' => 2,
        'argument' => 'entity_id:erpal_reports',
        'settings' => array(
          'identifier' => 'ERPAL Reports: ID',
        ),
      ),
    ),
    'name' => 'ERPAL Project Reports detail view',
    'path' => 'erpal/reports/%',
    'category' => 'ERPAL reports',
    'cat_actions' => array(
      0 => array(
        'path' => 'erpal/reports/[erpal_reports:id]/edit',
        'path_router' => 'erpal/reports/[erpal_reports:id]/edit',
        'path_original' => 'erpal/reports/[erpal_reports:id]/edit',
        'path_pattern' => 'erpal/%/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Edit',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'reports/project',
        'path_router' => 'reports/project',
        'path_original' => 'reports/project',
        'path_pattern' => 'reports/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Projects',
        'css_id' => '',
        'css_class' => 'reports_project',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => 'report_projects',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      1 => array(
        'path' => 'reports/crm',
        'path_router' => 'reports/crm',
        'path_original' => 'reports/crm',
        'path_pattern' => 'reports/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'CRM',
        'css_id' => '',
        'css_class' => 'reports_crm',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => 'report_crm',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_project_reports_detail_view',
    'path_original' => 'erpal/reports/%erpal_reports',
    'path_pattern' => 'erpal/%/%',
    'path_query' => array(),
    'path_router' => 'erpal/reports/%',
    'reusable' => 0,
    'cat_remove' => array(
      0 => array(
        'path' => 'erpal/reports/%/view',
        'path_router' => 'erpal/reports/%/view',
        'path_original' => 'erpal/reports/%erpal_reports/view',
        'path_pattern' => 'erpal/%/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      1 => array(
        'path' => 'erpal/reports/%/edit',
        'path_router' => 'erpal/reports/%/edit',
        'path_original' => 'erpal/reports/%erpal_reports/edit',
        'path_pattern' => 'erpal/%/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
    ),
  );
  $cat_item->weight = 0;
  $export['erpal_project_reports_detail_view'] = $cat_item;

  return $export;
}
