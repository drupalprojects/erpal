<?php
/**
 * @file
 * erpal_reports.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_reports_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'report_dashboard';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'erpal_reports';
  $view->human_name = 'Report dashboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view reports dashboard';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'in_pane';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No reports available';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_erpal_reports_owners_target_id']['id'] = 'field_erpal_reports_owners_target_id';
  $handler->display->display_options['relationships']['field_erpal_reports_owners_target_id']['table'] = 'field_data_field_erpal_reports_owners';
  $handler->display->display_options['relationships']['field_erpal_reports_owners_target_id']['field'] = 'field_erpal_reports_owners_target_id';
  /* Field: ERPAL Reports: Erpal reports ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'erpal_reports';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Filter criterion: ERPAL Reports: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'erpal_reports';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_crm_customer_reports' => 'erpal_crm_customer_reports',
    'erpal_crm_expense_reports' => 'erpal_crm_expense_reports',
    'erpal_crm_lead_reports' => 'erpal_crm_lead_reports',
    'erpal_crm_sales_forecast_reports' => 'erpal_crm_sales_forecast_reports',
    'erpal_crm_sales_reports' => 'erpal_crm_sales_reports',
  );
  /* Filter criterion: ERPAL Reports: Dashboard */
  $handler->display->display_options['filters']['dashboard']['id'] = 'dashboard';
  $handler->display->display_options['filters']['dashboard']['table'] = 'erpal_reports';
  $handler->display->display_options['filters']['dashboard']['field'] = 'dashboard';
  $handler->display->display_options['filters']['dashboard']['value']['value'] = '1';
  /* Filter criterion: ERPAL Reports: Is global report (field_erpal_reports_global) */
  $handler->display->display_options['filters']['field_erpal_reports_global_value']['id'] = 'field_erpal_reports_global_value';
  $handler->display->display_options['filters']['field_erpal_reports_global_value']['table'] = 'field_data_field_erpal_reports_global';
  $handler->display->display_options['filters']['field_erpal_reports_global_value']['field'] = 'field_erpal_reports_global_value';
  $handler->display->display_options['filters']['field_erpal_reports_global_value']['value'] = array(
    1 => '1',
  );

  /* Display: Global report dashboard view pane */
  $handler = $view->new_display('panel_pane', 'Global report dashboard view pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Global reports';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view reports dashboard';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No reports available';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: ERPAL Reports: Dashboard */
  $handler->display->display_options['filters']['dashboard']['id'] = 'dashboard';
  $handler->display->display_options['filters']['dashboard']['table'] = 'erpal_reports';
  $handler->display->display_options['filters']['dashboard']['field'] = 'dashboard';
  $handler->display->display_options['filters']['dashboard']['value']['value'] = '1';
  /* Filter criterion: ERPAL Reports: Is global report (field_erpal_reports_global) */
  $handler->display->display_options['filters']['field_erpal_reports_global_value']['id'] = 'field_erpal_reports_global_value';
  $handler->display->display_options['filters']['field_erpal_reports_global_value']['table'] = 'field_data_field_erpal_reports_global';
  $handler->display->display_options['filters']['field_erpal_reports_global_value']['field'] = 'field_erpal_reports_global_value';
  $handler->display->display_options['filters']['field_erpal_reports_global_value']['value'] = array(
    1 => '1',
  );

  /* Display: Personal report dashboard view pane */
  $handler = $view->new_display('panel_pane', 'Personal report dashboard view pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Personal reports';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view reports dashboard';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No reports available';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: ERPAL Reports: Dashboard */
  $handler->display->display_options['filters']['dashboard']['id'] = 'dashboard';
  $handler->display->display_options['filters']['dashboard']['table'] = 'erpal_reports';
  $handler->display->display_options['filters']['dashboard']['field'] = 'dashboard';
  $handler->display->display_options['filters']['dashboard']['value']['value'] = '1';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_erpal_reports_owners_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $translatables['report_dashboard'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No reports available'),
    t('User entity referenced from field_erpal_reports_owners'),
    t('Erpal reports ID'),
    t('.'),
    t(','),
    t('Global report dashboard view pane'),
    t('Global reports'),
    t('View panes'),
    t('Personal report dashboard view pane'),
    t('Personal reports'),
  );
  $export['report_dashboard'] = $view;

  $view = new view();
  $view->name = 'users_with_report_permission';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Users with report permission';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Permission */
  $handler->display->display_options['filters']['permission']['id'] = 'permission';
  $handler->display->display_options['filters']['permission']['table'] = 'role_permission';
  $handler->display->display_options['filters']['permission']['field'] = 'permission';
  $handler->display->display_options['filters']['permission']['value'] = array(
    'use erpal_reports' => 'use erpal_reports',
  );

  /* Display: Users with report permission */
  $handler = $view->new_display('entityreference', 'Users with report permission', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['users_with_report_permission'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Users with report permission'),
  );
  $export['users_with_report_permission'] = $view;

  return $export;
}
