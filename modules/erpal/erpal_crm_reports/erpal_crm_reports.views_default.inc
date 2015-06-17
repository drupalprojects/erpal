<?php
/**
 * @file
 * erpal_crm_reports.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_crm_reports_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'customer_forecast';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Customer Forecast';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Customer Forecast';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm sales forecast report';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_forecast_date' => 'field_forecast_date',
    'field_expected_volume' => 'field_expected_volume',
    'field_dynamic_volume' => 'field_dynamic_volume',
    'field_current_volume' => 'field_current_volume',
    'field_forecast_calculated' => 'field_forecast_calculated',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_forecast_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_expected_volume' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_dynamic_volume' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_current_volume' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_forecast_calculated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* Relationship: Content: Forecast elements (field_forecast_elements) */
  $handler->display->display_options['relationships']['field_forecast_elements_value']['id'] = 'field_forecast_elements_value';
  $handler->display->display_options['relationships']['field_forecast_elements_value']['table'] = 'field_data_field_forecast_elements';
  $handler->display->display_options['relationships']['field_forecast_elements_value']['field'] = 'field_forecast_elements_value';
  $handler->display->display_options['relationships']['field_forecast_elements_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_forecast_elements_value']['delta'] = '-1';
  /* Relationship: Field collection item: Forecast volumes (field_forecast_volumes) */
  $handler->display->display_options['relationships']['field_forecast_volumes_value']['id'] = 'field_forecast_volumes_value';
  $handler->display->display_options['relationships']['field_forecast_volumes_value']['table'] = 'field_data_field_forecast_volumes';
  $handler->display->display_options['relationships']['field_forecast_volumes_value']['field'] = 'field_forecast_volumes_value';
  $handler->display->display_options['relationships']['field_forecast_volumes_value']['relationship'] = 'field_forecast_elements_value';
  $handler->display->display_options['relationships']['field_forecast_volumes_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_forecast_volumes_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_contact_ref_target_id']['id'] = 'field_contact_ref_target_id';
  $handler->display->display_options['relationships']['field_contact_ref_target_id']['table'] = 'field_data_field_contact_ref';
  $handler->display->display_options['relationships']['field_contact_ref_target_id']['field'] = 'field_contact_ref_target_id';
  $handler->display->display_options['relationships']['field_contact_ref_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Forecast';
  /* Field: Field collection item: Forecast date */
  $handler->display->display_options['fields']['field_forecast_date']['id'] = 'field_forecast_date';
  $handler->display->display_options['fields']['field_forecast_date']['table'] = 'field_data_field_forecast_date';
  $handler->display->display_options['fields']['field_forecast_date']['field'] = 'field_forecast_date';
  $handler->display->display_options['fields']['field_forecast_date']['relationship'] = 'field_forecast_elements_value';
  $handler->display->display_options['fields']['field_forecast_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Field collection item: Expected volume */
  $handler->display->display_options['fields']['field_expected_volume']['id'] = 'field_expected_volume';
  $handler->display->display_options['fields']['field_expected_volume']['table'] = 'field_data_field_expected_volume';
  $handler->display->display_options['fields']['field_expected_volume']['field'] = 'field_expected_volume';
  $handler->display->display_options['fields']['field_expected_volume']['relationship'] = 'field_forecast_elements_value';
  $handler->display->display_options['fields']['field_expected_volume']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Dynamic volume */
  $handler->display->display_options['fields']['field_dynamic_volume']['id'] = 'field_dynamic_volume';
  $handler->display->display_options['fields']['field_dynamic_volume']['table'] = 'field_data_field_dynamic_volume';
  $handler->display->display_options['fields']['field_dynamic_volume']['field'] = 'field_dynamic_volume';
  $handler->display->display_options['fields']['field_dynamic_volume']['relationship'] = 'field_forecast_elements_value';
  $handler->display->display_options['fields']['field_dynamic_volume']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Current volume */
  $handler->display->display_options['fields']['field_current_volume']['id'] = 'field_current_volume';
  $handler->display->display_options['fields']['field_current_volume']['table'] = 'field_data_field_current_volume';
  $handler->display->display_options['fields']['field_current_volume']['field'] = 'field_current_volume';
  $handler->display->display_options['fields']['field_current_volume']['relationship'] = 'field_forecast_elements_value';
  /* Field: Field collection item: Forecast calculated */
  $handler->display->display_options['fields']['field_forecast_calculated']['id'] = 'field_forecast_calculated';
  $handler->display->display_options['fields']['field_forecast_calculated']['table'] = 'field_data_field_forecast_calculated';
  $handler->display->display_options['fields']['field_forecast_calculated']['field'] = 'field_forecast_calculated';
  $handler->display->display_options['fields']['field_forecast_calculated']['relationship'] = 'field_forecast_elements_value';
  $handler->display->display_options['fields']['field_forecast_calculated']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_customer_forecast' => 'erpal_customer_forecast',
  );
  /* Filter criterion: Field collection item: Forecast date (field_forecast_date) */
  $handler->display->display_options['filters']['field_forecast_date_value']['id'] = 'field_forecast_date_value';
  $handler->display->display_options['filters']['field_forecast_date_value']['table'] = 'field_data_field_forecast_date';
  $handler->display->display_options['filters']['field_forecast_date_value']['field'] = 'field_forecast_date_value';
  $handler->display->display_options['filters']['field_forecast_date_value']['relationship'] = 'field_forecast_elements_value';
  $handler->display->display_options['filters']['field_forecast_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_forecast_date_value']['expose']['operator_id'] = 'field_forecast_date_value_op';
  $handler->display->display_options['filters']['field_forecast_date_value']['expose']['label'] = 'Forecast year';
  $handler->display->display_options['filters']['field_forecast_date_value']['expose']['operator'] = 'field_forecast_date_value_op';
  $handler->display->display_options['filters']['field_forecast_date_value']['expose']['identifier'] = 'field_forecast_date_value';
  $handler->display->display_options['filters']['field_forecast_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_forecast_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_forecast_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_forecast_date_value']['form_type'] = 'date_text';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_contact_ref_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Contact';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );

  /* Display: Forecast Pane */
  $handler = $view->new_display('panel_pane', 'Forecast Pane', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['customer_forecast'] = array(
    t('Master'),
    t('Customer Forecast'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field collection item from field_forecast_elements'),
    t('field collection item from field_forecast_volumes'),
    t('Content entity referenced from field_contact_ref'),
    t('Forecast'),
    t('Forecast date'),
    t('Expected volume'),
    t('Dynamic volume'),
    t('Current volume'),
    t('Forecast calculated'),
    t('Forecast year'),
    t('Contact'),
    t('Forecast Pane'),
    t('View panes'),
  );
  $export['customer_forecast'] = $view;

  $view = new view();
  $view->name = 'expense_forecast';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Expense forecast';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Expense Forecast';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view crm expense forecast plan';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_expense_category' => 'field_expense_category',
    'field_forecast_date' => 'field_forecast_date',
    'field_forecast_estimated' => 'field_forecast_estimated',
    'field_forecast_dynamic' => 'field_forecast_dynamic',
    'field_current_volume' => 'field_current_volume',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_expense_category' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_forecast_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_forecast_estimated' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_forecast_dynamic' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_current_volume' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No expense forecasts available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Content: Expense Elements (field_expense_elements) */
  $handler->display->display_options['relationships']['field_expense_elements_value']['id'] = 'field_expense_elements_value';
  $handler->display->display_options['relationships']['field_expense_elements_value']['table'] = 'field_data_field_expense_elements';
  $handler->display->display_options['relationships']['field_expense_elements_value']['field'] = 'field_expense_elements_value';
  $handler->display->display_options['relationships']['field_expense_elements_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Expense category */
  $handler->display->display_options['fields']['field_expense_category']['id'] = 'field_expense_category';
  $handler->display->display_options['fields']['field_expense_category']['table'] = 'field_data_field_expense_category';
  $handler->display->display_options['fields']['field_expense_category']['field'] = 'field_expense_category';
  $handler->display->display_options['fields']['field_expense_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: Forecast date */
  $handler->display->display_options['fields']['field_forecast_date']['id'] = 'field_forecast_date';
  $handler->display->display_options['fields']['field_forecast_date']['table'] = 'field_data_field_forecast_date';
  $handler->display->display_options['fields']['field_forecast_date']['field'] = 'field_forecast_date';
  $handler->display->display_options['fields']['field_forecast_date']['relationship'] = 'field_expense_elements_value';
  $handler->display->display_options['fields']['field_forecast_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Field collection item: Forecast Estimated */
  $handler->display->display_options['fields']['field_forecast_estimated']['id'] = 'field_forecast_estimated';
  $handler->display->display_options['fields']['field_forecast_estimated']['table'] = 'field_data_field_forecast_estimated';
  $handler->display->display_options['fields']['field_forecast_estimated']['field'] = 'field_forecast_estimated';
  $handler->display->display_options['fields']['field_forecast_estimated']['relationship'] = 'field_expense_elements_value';
  $handler->display->display_options['fields']['field_forecast_estimated']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Forecast Dynamic */
  $handler->display->display_options['fields']['field_forecast_dynamic']['id'] = 'field_forecast_dynamic';
  $handler->display->display_options['fields']['field_forecast_dynamic']['table'] = 'field_data_field_forecast_dynamic';
  $handler->display->display_options['fields']['field_forecast_dynamic']['field'] = 'field_forecast_dynamic';
  $handler->display->display_options['fields']['field_forecast_dynamic']['relationship'] = 'field_expense_elements_value';
  $handler->display->display_options['fields']['field_forecast_dynamic']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Current volume */
  $handler->display->display_options['fields']['field_current_volume']['id'] = 'field_current_volume';
  $handler->display->display_options['fields']['field_current_volume']['table'] = 'field_data_field_current_volume';
  $handler->display->display_options['fields']['field_current_volume']['field'] = 'field_current_volume';
  $handler->display->display_options['fields']['field_current_volume']['relationship'] = 'field_expense_elements_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_expense_forecast' => 'erpal_expense_forecast',
  );
  /* Filter criterion: Field collection item: Forecast date (field_forecast_date) */
  $handler->display->display_options['filters']['field_forecast_date_value_1']['id'] = 'field_forecast_date_value_1';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['table'] = 'field_data_field_forecast_date';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['field'] = 'field_forecast_date_value';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['relationship'] = 'field_expense_elements_value';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_forecast_date_value_1']['expose']['operator_id'] = 'field_forecast_date_value_1_op';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['expose']['label'] = 'Forecast date';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['expose']['operator'] = 'field_forecast_date_value_1_op';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['expose']['identifier'] = 'field_forecast_date_value_1';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_forecast_date_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_forecast_date_value_1']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_forecast_date_value_1']['form_type'] = 'date_text';
  /* Filter criterion: Field: Expense category (field_expense_category) */
  $handler->display->display_options['filters']['field_expense_category_tid']['id'] = 'field_expense_category_tid';
  $handler->display->display_options['filters']['field_expense_category_tid']['table'] = 'field_data_field_expense_category';
  $handler->display->display_options['filters']['field_expense_category_tid']['field'] = 'field_expense_category_tid';
  $handler->display->display_options['filters']['field_expense_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_expense_category_tid']['expose']['operator_id'] = 'field_expense_category_tid_op';
  $handler->display->display_options['filters']['field_expense_category_tid']['expose']['label'] = 'Expense category';
  $handler->display->display_options['filters']['field_expense_category_tid']['expose']['operator'] = 'field_expense_category_tid_op';
  $handler->display->display_options['filters']['field_expense_category_tid']['expose']['identifier'] = 'field_expense_category_tid';
  $handler->display->display_options['filters']['field_expense_category_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_expense_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_expense_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_expense_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_expense_category_tid']['vocabulary'] = 'expense_category_terms';

  /* Display: Expense forecast pane */
  $handler = $view->new_display('panel_pane', 'Expense forecast pane', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['expense_forecast'] = array(
    t('Master'),
    t('Expense Forecast'),
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
    t('No expense forecasts available.'),
    t('field collection item from field_expense_elements'),
    t('Expense category'),
    t('Forecast date'),
    t('Forecast Estimated'),
    t('Forecast Dynamic'),
    t('Current volume'),
    t('Expense forecast pane'),
    t('View panes'),
  );
  $export['expense_forecast'] = $view;

  $view = new view();
  $view->name = 'report_details_view_billables';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'billable';
  $view->human_name = 'Report details view - billables';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'billed' => 'billed',
    'date_delivery' => 'date_delivery',
    'single_price' => 'single_price',
    'total_price_no_vat' => 'total_price_no_vat',
    'total_price' => 'total_price',
    'vat_rate' => 'vat_rate',
    'field_service_category_term' => 'field_service_category_term',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_2' => 'title_2',
    'link_billable' => 'link_billable',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'billed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'date_delivery' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'single_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'total_price_no_vat' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'total_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'vat_rate' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_service_category_term' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'link_billable' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No data available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Billable: Billable subject */
  $handler->display->display_options['relationships']['subject_nid']['id'] = 'subject_nid';
  $handler->display->display_options['relationships']['subject_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['subject_nid']['field'] = 'subject_nid';
  /* Relationship: Billable: Contractor */
  $handler->display->display_options['relationships']['contractor_nid']['id'] = 'contractor_nid';
  $handler->display->display_options['relationships']['contractor_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['contractor_nid']['field'] = 'contractor_nid';
  /* Relationship: Billable: Customer */
  $handler->display->display_options['relationships']['customer_nid']['id'] = 'customer_nid';
  $handler->display->display_options['relationships']['customer_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['customer_nid']['field'] = 'customer_nid';
  /* Field: Billable: Billed */
  $handler->display->display_options['fields']['billed']['id'] = 'billed';
  $handler->display->display_options['fields']['billed']['table'] = 'billable';
  $handler->display->display_options['fields']['billed']['field'] = 'billed';
  $handler->display->display_options['fields']['billed']['not'] = 0;
  /* Field: Billable: Date_delivery */
  $handler->display->display_options['fields']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['fields']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['label'] = 'Date delivery';
  $handler->display->display_options['fields']['date_delivery']['date_format'] = 'erpal_date';
  /* Field: Billable: Single_price */
  $handler->display->display_options['fields']['single_price']['id'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['table'] = 'billable';
  $handler->display->display_options['fields']['single_price']['field'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['label'] = 'Einzelpreis';
  $handler->display->display_options['fields']['single_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['single_price']['precision'] = '2';
  $handler->display->display_options['fields']['single_price']['separator'] = '';
  /* Field: Billable: Total_price_no_vat */
  $handler->display->display_options['fields']['total_price_no_vat']['id'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price_no_vat']['field'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['label'] = 'Total price no vat';
  $handler->display->display_options['fields']['total_price_no_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price_no_vat']['precision'] = '2';
  $handler->display->display_options['fields']['total_price_no_vat']['separator'] = '';
  /* Field: Billable: Total_price */
  $handler->display->display_options['fields']['total_price']['id'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price']['field'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['label'] = 'Total price';
  $handler->display->display_options['fields']['total_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price']['precision'] = '2';
  $handler->display->display_options['fields']['total_price']['separator'] = '';
  /* Field: Billable: Vat_rate */
  $handler->display->display_options['fields']['vat_rate']['id'] = 'vat_rate';
  $handler->display->display_options['fields']['vat_rate']['table'] = 'billable';
  $handler->display->display_options['fields']['vat_rate']['field'] = 'vat_rate';
  $handler->display->display_options['fields']['vat_rate']['label'] = 'Tax';
  $handler->display->display_options['fields']['vat_rate']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['vat_rate']['precision'] = '2';
  $handler->display->display_options['fields']['vat_rate']['separator'] = '';
  /* Field: Field: Service category */
  $handler->display->display_options['fields']['field_service_category_term']['id'] = 'field_service_category_term';
  $handler->display->display_options['fields']['field_service_category_term']['table'] = 'field_data_field_service_category_term';
  $handler->display->display_options['fields']['field_service_category_term']['field'] = 'field_service_category_term';
  $handler->display->display_options['fields']['field_service_category_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'subject_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'contractor_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Contractor';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'customer_nid';
  $handler->display->display_options['fields']['title_2']['label'] = 'Customer';
  /* Field: Billable: Link */
  $handler->display->display_options['fields']['link_billable']['id'] = 'link_billable';
  $handler->display->display_options['fields']['link_billable']['table'] = 'billable';
  $handler->display->display_options['fields']['link_billable']['field'] = 'link_billable';
  /* Contextual filter: Billable: Billable ID */
  $handler->display->display_options['arguments']['billable_id']['id'] = 'billable_id';
  $handler->display->display_options['arguments']['billable_id']['table'] = 'billable';
  $handler->display->display_options['arguments']['billable_id']['field'] = 'billable_id';
  $handler->display->display_options['arguments']['billable_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['billable_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['billable_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['billable_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['billable_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['billable_id']['break_phrase'] = TRUE;

  /* Display: Billable block */
  $handler = $view->new_display('block', 'Billable block', 'display_billable');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Billables';

  /* Display: Unbillable block */
  $handler = $view->new_display('block', 'Unbillable block', 'display_unbillable');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Unbillables';
  $translatables['report_details_view_billables'] = array(
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
    t('No data available.'),
    t('Billable subject'),
    t('Contractor'),
    t('Customer'),
    t('Billed'),
    t('Date delivery'),
    t('Einzelpreis'),
    t('.'),
    t('Total price no vat'),
    t('Total price'),
    t('Tax'),
    t('Service category'),
    t('Subject'),
    t('Link'),
    t('All'),
    t('Billable block'),
    t('Billables'),
    t('Unbillable block'),
    t('Unbillables'),
  );
  $export['report_details_view_billables'] = $view;

  $view = new view();
  $view->name = 'report_details_view_budgets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'budget';
  $view->human_name = 'Report details view - budgets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Budget';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'link_budget' => 'link_budget',
    'title' => 'title',
    'available_hours' => 'available_hours',
    'date_from' => 'date_from',
    'date_till' => 'date_till',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'link_budget' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'available_hours' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'date_from' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'date_till' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No data available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['id'] = 'reverse_field_budgets_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['table'] = 'budget';
  $handler->display->display_options['relationships']['reverse_field_budgets_field_collection_item']['field'] = 'reverse_field_budgets_field_collection_item';
  /* Relationship: Field collection item: Entity with the Pricing (field_pricing) */
  $handler->display->display_options['relationships']['field_pricing_node']['id'] = 'field_pricing_node';
  $handler->display->display_options['relationships']['field_pricing_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_pricing_node']['field'] = 'field_pricing_node';
  $handler->display->display_options['relationships']['field_pricing_node']['relationship'] = 'reverse_field_budgets_field_collection_item';
  /* Field: Budget: Link */
  $handler->display->display_options['fields']['link_budget']['id'] = 'link_budget';
  $handler->display->display_options['fields']['link_budget']['table'] = 'budget';
  $handler->display->display_options['fields']['link_budget']['field'] = 'link_budget';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_pricing_node';
  /* Field: Budget: Available */
  $handler->display->display_options['fields']['available_hours']['id'] = 'available_hours';
  $handler->display->display_options['fields']['available_hours']['table'] = 'budget';
  $handler->display->display_options['fields']['available_hours']['field'] = 'available_hours';
  $handler->display->display_options['fields']['available_hours']['precision'] = '0';
  $handler->display->display_options['fields']['available_hours']['separator'] = '';
  /* Field: Budget: Date from */
  $handler->display->display_options['fields']['date_from']['id'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['table'] = 'budget';
  $handler->display->display_options['fields']['date_from']['field'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['date_format'] = 'erpal_date';
  /* Field: Budget: Date till */
  $handler->display->display_options['fields']['date_till']['id'] = 'date_till';
  $handler->display->display_options['fields']['date_till']['table'] = 'budget';
  $handler->display->display_options['fields']['date_till']['field'] = 'date_till';
  $handler->display->display_options['fields']['date_till']['date_format'] = 'erpal_date';
  /* Contextual filter: Budget: Budget ID */
  $handler->display->display_options['arguments']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['arguments']['budget_id']['table'] = 'budget';
  $handler->display->display_options['arguments']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['arguments']['budget_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['budget_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['budget_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['budget_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['budget_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['budget_id']['break_phrase'] = TRUE;

  /* Display: Budget block */
  $handler = $view->new_display('block', 'Budget block', 'display_budget');
  $translatables['report_details_view_budgets'] = array(
    t('Master'),
    t('Budget'),
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
    t('No data available.'),
    t('Field collection item referencing budget from field_budgets'),
    t('field_pricing'),
    t('Link'),
    t('Title'),
    t('Available'),
    t('.'),
    t('Date from'),
    t('Date till'),
    t('All'),
    t('Budget block'),
  );
  $export['report_details_view_budgets'] = $view;

  $view = new view();
  $view->name = 'report_details_view_nodes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Report details view - nodes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No data available.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Invoice Date */
  $handler->display->display_options['fields']['field_invoice_date']['id'] = 'field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['table'] = 'field_data_field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['field'] = 'field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Total excl. tax */
  $handler->display->display_options['fields']['field_price_no_vat']['id'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['table'] = 'field_data_field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['field'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['label'] = 'Total excl. Tax';
  $handler->display->display_options['fields']['field_price_no_vat']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Total incl. tax */
  $handler->display->display_options['fields']['field_invoice_total']['id'] = 'field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['table'] = 'field_data_field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['field'] = 'field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['label'] = 'Total incl. Tax';
  $handler->display->display_options['fields']['field_invoice_total']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Contractor */
  $handler->display->display_options['fields']['field_contractor_ref']['id'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['table'] = 'field_data_field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['field'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Invoice block */
  $handler = $view->new_display('block', 'Invoice block', 'display_erpal_invoice');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Invoices';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_invoice_date' => 'field_invoice_date',
    'field_price_no_vat' => 'field_price_no_vat',
    'field_invoice_total' => 'field_invoice_total',
    'field_contractor_ref' => 'field_contractor_ref',
    'field_customer_ref' => 'field_customer_ref',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_invoice_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_price_no_vat' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_invoice_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_contractor_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_customer_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_invoice' => 'erpal_invoice',
  );

  /* Display: Activity block */
  $handler = $view->new_display('block', 'Activity block', 'display_erpal_crm_activity');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'CRM Activities';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_customer_ref' => 'field_customer_ref',
    'field_activity_status_term' => 'field_activity_status_term',
    'created' => 'created',
    'changed' => 'changed',
    'field_expected_date' => 'field_expected_date',
    'field_chance' => 'field_chance',
    'field_volume' => 'field_volume',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_customer_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_activity_status_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_expected_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_chance' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_volume' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_activity_status_term']['id'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['table'] = 'field_data_field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['field'] = 'field_activity_status_term';
  $handler->display->display_options['fields']['field_activity_status_term']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Inserted';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Content: Expected date */
  $handler->display->display_options['fields']['field_expected_date']['id'] = 'field_expected_date';
  $handler->display->display_options['fields']['field_expected_date']['table'] = 'field_data_field_expected_date';
  $handler->display->display_options['fields']['field_expected_date']['field'] = 'field_expected_date';
  $handler->display->display_options['fields']['field_expected_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Prospect Quality */
  $handler->display->display_options['fields']['field_chance']['id'] = 'field_chance';
  $handler->display->display_options['fields']['field_chance']['table'] = 'field_data_field_chance';
  $handler->display->display_options['fields']['field_chance']['field'] = 'field_chance';
  /* Field: Content: Volume */
  $handler->display->display_options['fields']['field_volume']['id'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['table'] = 'field_data_field_volume';
  $handler->display->display_options['fields']['field_volume']['field'] = 'field_volume';
  $handler->display->display_options['fields']['field_volume']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );

  /* Display: Contact block */
  $handler = $view->new_display('block', 'Contact block', 'dispay_erpal_contact');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';

  /* Display: Task block */
  $handler = $view->new_display('block', 'Task block', 'display_erpal_task');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_customer_ref' => 'field_customer_ref',
    'field_date' => 'field_date',
    'field_price' => 'field_price',
    'field_project_ref' => 'field_project_ref',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_customer_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_project_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Pricing (field_pricing) */
  $handler->display->display_options['relationships']['field_pricing_value']['id'] = 'field_pricing_value';
  $handler->display->display_options['relationships']['field_pricing_value']['table'] = 'field_data_field_pricing';
  $handler->display->display_options['relationships']['field_pricing_value']['field'] = 'field_pricing_value';
  $handler->display->display_options['relationships']['field_pricing_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Deadline';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Field collection item: Price per month */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['relationship'] = 'field_pricing_value';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Project */
  $handler->display->display_options['fields']['field_project_ref']['id'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['field'] = 'field_project_ref';
  $handler->display->display_options['fields']['field_project_ref']['settings'] = array(
    'link' => 1,
  );

  /* Display: Contract block */
  $handler = $view->new_display('block', 'Contract block', 'display_erpal_contract');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Contracts';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_customer_ref' => 'field_customer_ref',
    'field_price' => 'field_price',
    'field_next_booking_date' => 'field_next_booking_date',
    'php' => 'php',
    'field_payment_period' => 'field_payment_period',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_customer_ref' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_next_booking_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_payment_period' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Contract payment (field_contract_payment) */
  $handler->display->display_options['relationships']['field_contract_payment_value']['id'] = 'field_contract_payment_value';
  $handler->display->display_options['relationships']['field_contract_payment_value']['table'] = 'field_data_field_contract_payment';
  $handler->display->display_options['relationships']['field_contract_payment_value']['field'] = 'field_contract_payment_value';
  $handler->display->display_options['relationships']['field_contract_payment_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field collection item: Price per month */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field collection item: Next payment date */
  $handler->display->display_options['fields']['field_next_booking_date']['id'] = 'field_next_booking_date';
  $handler->display->display_options['fields']['field_next_booking_date']['table'] = 'field_data_field_next_booking_date';
  $handler->display->display_options['fields']['field_next_booking_date']['field'] = 'field_next_booking_date';
  $handler->display->display_options['fields']['field_next_booking_date']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_next_booking_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Next payment value';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$fc_id = $data->field_collection_item_field_data_field_contract_payment_item;
$payment_collection = entity_load(\'field_collection_item\', array($fc_id));
$payment_collection = reset($payment_collection);
$payment_collection_w = entity_metadata_wrapper(\'field_collection_item\', $payment_collection);
$price = $payment_collection_w->field_price->value();
$payment_period = $payment_collection_w->field_payment_period->value();
return $price * $payment_period;';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo $value;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field collection item: Payment period */
  $handler->display->display_options['fields']['field_payment_period']['id'] = 'field_payment_period';
  $handler->display->display_options['fields']['field_payment_period']['table'] = 'field_data_field_payment_period';
  $handler->display->display_options['fields']['field_payment_period']['field'] = 'field_payment_period';
  $handler->display->display_options['fields']['field_payment_period']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_payment_period']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );

  /* Display: Project block */
  $handler = $view->new_display('block', 'Project block', 'display_erpal_project');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_customer_ref' => 'field_customer_ref',
    'field_date' => 'field_date',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );

  /* Display: Timetracking block */
  $handler = $view->new_display('block', 'Timetracking block', 'display_erpal_timetracking');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_date_time' => 'field_date_time',
    'field_timetracking_duration' => 'field_timetracking_duration',
    'field_timetracking_subject' => 'field_timetracking_subject',
    'field_billing_duration' => 'field_billing_duration',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_date_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_timetracking_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_timetracking_subject' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_billing_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date and time */
  $handler->display->display_options['fields']['field_date_time']['id'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['fields']['field_date_time']['field'] = 'field_date_time';
  $handler->display->display_options['fields']['field_date_time']['label'] = 'date';
  $handler->display->display_options['fields']['field_date_time']['settings'] = array(
    'format_type' => 'erpal_date_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_timetracking_duration']['id'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['table'] = 'field_data_field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['field'] = 'field_timetracking_duration';
  $handler->display->display_options['fields']['field_timetracking_duration']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_timetracking_subject']['id'] = 'field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['table'] = 'field_data_field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['field'] = 'field_timetracking_subject';
  $handler->display->display_options['fields']['field_timetracking_subject']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Billing Duration */
  $handler->display->display_options['fields']['field_billing_duration']['id'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['table'] = 'field_data_field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['field'] = 'field_billing_duration';
  $handler->display->display_options['fields']['field_billing_duration']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $translatables['report_details_view_nodes'] = array(
    t('Master'),
    t('Contacts'),
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
    t('No data available.'),
    t('Invoice Date'),
    t('Total excl. Tax'),
    t('Total incl. Tax'),
    t('Contractor'),
    t('Customer'),
    t('All'),
    t('Invoice block'),
    t('Invoices'),
    t('Activity block'),
    t('CRM Activities'),
    t('Status'),
    t('Inserted'),
    t('Updated'),
    t('Expected date'),
    t('Prospect Quality'),
    t('Volume'),
    t('Contact block'),
    t('Name'),
    t('Task block'),
    t('field collection item from field_pricing'),
    t('Content entity referenced from field_project_ref'),
    t('Deadline'),
    t('Price per month'),
    t('Project'),
    t('Contract block'),
    t('Contracts'),
    t('field collection item from field_contract_payment'),
    t('Next payment date'),
    t('Next payment value'),
    t('Payment period'),
    t('Project block'),
    t('Period'),
    t('Timetracking block'),
    t('date'),
    t('Duration'),
    t('Subject'),
    t('Billing Duration'),
  );
  $export['report_details_view_nodes'] = $view;

  return $export;
}
