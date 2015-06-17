<?php
/**
 * @file
 * erpal_employee_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_employee_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'working_time';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Working time';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view timekeeping';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date_time' => 'field_date_time',
    'field_duration_calc' => 'field_duration_calc',
    'changed' => 'changed',
    'field_working_time_type' => 'field_working_time_type',
    'name' => 'name',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_duration_calc' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_working_time_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No working time found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
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
  $handler->display->display_options['fields']['field_duration_calc']['id'] = 'field_duration_calc';
  $handler->display->display_options['fields']['field_duration_calc']['table'] = 'field_data_field_duration_calc';
  $handler->display->display_options['fields']['field_duration_calc']['field'] = 'field_duration_calc';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Content: Working time type */
  $handler->display->display_options['fields']['field_working_time_type']['id'] = 'field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['table'] = 'field_data_field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['field'] = 'field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['label'] = 'Type';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Details';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo _erpal_employee_get_detailled_timetracking_link($view, $row, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['sorts']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['sorts']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['sorts']['field_date_time_value']['order'] = 'DESC';
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
    'erpal_working_time' => 'erpal_working_time',
  );
  /* Filter criterion: Content: Working time type (field_working_time_type) */
  $handler->display->display_options['filters']['field_working_time_type_value']['id'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['table'] = 'field_data_field_working_time_type';
  $handler->display->display_options['filters']['field_working_time_type_value']['field'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['operator_id'] = 'field_working_time_type_value_op';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['operator'] = 'field_working_time_type_value_op';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['identifier'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'date';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';

  /* Display: User working time day */
  $handler = $view->new_display('panel_pane', 'User working time day', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_date_time' => 'field_date_time',
    'field_duration_calc' => 'field_duration_calc',
    'changed' => 'changed',
    'field_working_time_type' => 'field_working_time_type',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_date_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_duration_calc' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_working_time_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_duration_calc']['id'] = 'field_duration_calc';
  $handler->display->display_options['fields']['field_duration_calc']['table'] = 'field_data_field_duration_calc';
  $handler->display->display_options['fields']['field_duration_calc']['field'] = 'field_duration_calc';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Content: Working time type */
  $handler->display->display_options['fields']['field_working_time_type']['id'] = 'field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['table'] = 'field_data_field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['field'] = 'field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['label'] = 'Type';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Details';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo _erpal_employee_get_detailled_timetracking_link($view, $row, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
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
    'erpal_working_time' => 'erpal_working_time',
  );
  /* Filter criterion: Content: Working time type (field_working_time_type) */
  $handler->display->display_options['filters']['field_working_time_type_value']['id'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['table'] = 'field_data_field_working_time_type';
  $handler->display->display_options['filters']['field_working_time_type_value']['field'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['operator_id'] = 'field_working_time_type_value_op';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['operator'] = 'field_working_time_type_value_op';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['identifier'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'date';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_time_value']['date_range_links'] = 1;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: All working time day */
  $handler = $view->new_display('panel_pane', 'All working time day', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any timekeeping';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_duration_calc']['id'] = 'field_duration_calc';
  $handler->display->display_options['fields']['field_duration_calc']['table'] = 'field_data_field_duration_calc';
  $handler->display->display_options['fields']['field_duration_calc']['field'] = 'field_duration_calc';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Content: Working time type */
  $handler->display->display_options['fields']['field_working_time_type']['id'] = 'field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['table'] = 'field_data_field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['field'] = 'field_working_time_type';
  $handler->display->display_options['fields']['field_working_time_type']['label'] = 'Type';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Details';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
echo _erpal_employee_get_detailled_timetracking_link($view, $row, $data);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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
    'erpal_working_time' => 'erpal_working_time',
  );
  /* Filter criterion: Content: Working time type (field_working_time_type) */
  $handler->display->display_options['filters']['field_working_time_type_value']['id'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['table'] = 'field_data_field_working_time_type';
  $handler->display->display_options['filters']['field_working_time_type_value']['field'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['operator_id'] = 'field_working_time_type_value_op';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['operator'] = 'field_working_time_type_value_op';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['identifier'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_working_time_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Date and time -  start date (field_date_time) */
  $handler->display->display_options['filters']['field_date_time_value']['id'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['table'] = 'field_data_field_date_time';
  $handler->display->display_options['filters']['field_date_time_value']['field'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_date_time_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator_id'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['label'] = 'date';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['operator'] = 'field_date_time_value_op';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['identifier'] = 'field_date_time_value';
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_date_time_value']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_date_time_value']['date_range_links'] = 1;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['working_time'] = array(
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
    t('No working time found'),
    t('author'),
    t('date'),
    t('Duration'),
    t('Updated'),
    t('Type'),
    t('Details'),
    t('Name'),
    t('User working time day'),
    t('View panes'),
    t('All working time day'),
  );
  $export['working_time'] = $view;

  $view = new view();
  $view->name = 'working_times';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'working_times';
  $view->human_name = 'Working times';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view timekeeping';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No working times found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Calculated working times: working times user */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'working_times';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Calculated working times: Year */
  $handler->display->display_options['fields']['year']['id'] = 'year';
  $handler->display->display_options['fields']['year']['table'] = 'working_times';
  $handler->display->display_options['fields']['year']['field'] = 'year';
  $handler->display->display_options['fields']['year']['separator'] = '';
  /* Field: Calculated working times: Month */
  $handler->display->display_options['fields']['month']['id'] = 'month';
  $handler->display->display_options['fields']['month']['table'] = 'working_times';
  $handler->display->display_options['fields']['month']['field'] = 'month';
  $handler->display->display_options['fields']['month']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Calculated working times: Holidays_used */
  $handler->display->display_options['fields']['holidays_used']['id'] = 'holidays_used';
  $handler->display->display_options['fields']['holidays_used']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_used']['field'] = 'holidays_used';
  $handler->display->display_options['fields']['holidays_used']['label'] = 'Holidays used from current year';
  $handler->display->display_options['fields']['holidays_used']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_used']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_used_from_before */
  $handler->display->display_options['fields']['holidays_used_from_before']['id'] = 'holidays_used_from_before';
  $handler->display->display_options['fields']['holidays_used_from_before']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_used_from_before']['field'] = 'holidays_used_from_before';
  $handler->display->display_options['fields']['holidays_used_from_before']['label'] = 'Holidays used from last year';
  $handler->display->display_options['fields']['holidays_used_from_before']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_used_from_before']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_available */
  $handler->display->display_options['fields']['holidays_available']['id'] = 'holidays_available';
  $handler->display->display_options['fields']['holidays_available']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_available']['field'] = 'holidays_available';
  $handler->display->display_options['fields']['holidays_available']['label'] = 'Holidays available';
  $handler->display->display_options['fields']['holidays_available']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_available']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_available_till */
  $handler->display->display_options['fields']['holidays_available_till']['id'] = 'holidays_available_till';
  $handler->display->display_options['fields']['holidays_available_till']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_available_till']['field'] = 'holidays_available_till';
  $handler->display->display_options['fields']['holidays_available_till']['label'] = 'Holidays expire';
  $handler->display->display_options['fields']['holidays_available_till']['date_format'] = 'erpal_date';
  /* Field: Calculated working times: Ill_days */
  $handler->display->display_options['fields']['ill_days']['id'] = 'ill_days';
  $handler->display->display_options['fields']['ill_days']['table'] = 'working_times';
  $handler->display->display_options['fields']['ill_days']['field'] = 'ill_days';
  $handler->display->display_options['fields']['ill_days']['label'] = 'ill days';
  $handler->display->display_options['fields']['ill_days']['precision'] = '0';
  $handler->display->display_options['fields']['ill_days']['suffix'] = ' days';
  /* Field: Calculated working times: Total_hours */
  $handler->display->display_options['fields']['total_hours']['id'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['table'] = 'working_times';
  $handler->display->display_options['fields']['total_hours']['field'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['label'] = 'Total time';
  $handler->display->display_options['fields']['total_hours']['precision'] = '0';
  $handler->display->display_options['fields']['total_hours']['suffix'] = ' h';
  /* Field: Calculated working times: Booked_working_hours */
  $handler->display->display_options['fields']['booked_working_hours']['id'] = 'booked_working_hours';
  $handler->display->display_options['fields']['booked_working_hours']['table'] = 'working_times';
  $handler->display->display_options['fields']['booked_working_hours']['field'] = 'booked_working_hours';
  $handler->display->display_options['fields']['booked_working_hours']['label'] = 'Booked working time';
  $handler->display->display_options['fields']['booked_working_hours']['precision'] = '0';
  $handler->display->display_options['fields']['booked_working_hours']['suffix'] = ' h';
  /* Field: Calculated working times: Overtime */
  $handler->display->display_options['fields']['overtime']['id'] = 'overtime';
  $handler->display->display_options['fields']['overtime']['table'] = 'working_times';
  $handler->display->display_options['fields']['overtime']['field'] = 'overtime';
  $handler->display->display_options['fields']['overtime']['precision'] = '0';
  $handler->display->display_options['fields']['overtime']['suffix'] = ' h';
  /* Field: Calculated working times: Overtime_reduce */
  $handler->display->display_options['fields']['overtime_reduce']['id'] = 'overtime_reduce';
  $handler->display->display_options['fields']['overtime_reduce']['table'] = 'working_times';
  $handler->display->display_options['fields']['overtime_reduce']['field'] = 'overtime_reduce';
  $handler->display->display_options['fields']['overtime_reduce']['label'] = 'Overtime reduce';
  $handler->display->display_options['fields']['overtime_reduce']['precision'] = '0';
  $handler->display->display_options['fields']['overtime_reduce']['suffix'] = ' h';
  /* Field: Calculated working times: Project_time */
  $handler->display->display_options['fields']['project_time']['id'] = 'project_time';
  $handler->display->display_options['fields']['project_time']['table'] = 'working_times';
  $handler->display->display_options['fields']['project_time']['field'] = 'project_time';
  $handler->display->display_options['fields']['project_time']['label'] = 'Project time';
  $handler->display->display_options['fields']['project_time']['precision'] = '0';
  $handler->display->display_options['fields']['project_time']['suffix'] = 'h';
  /* Field: Calculated working times: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'working_times';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Calculated working times: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'working_times';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Calculated working times: Calculated working times ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'working_times';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Sort criterion: Calculated working times: Year */
  $handler->display->display_options['sorts']['year']['id'] = 'year';
  $handler->display->display_options['sorts']['year']['table'] = 'working_times';
  $handler->display->display_options['sorts']['year']['field'] = 'year';
  $handler->display->display_options['sorts']['year']['order'] = 'DESC';
  /* Sort criterion: Calculated working times: Month */
  $handler->display->display_options['sorts']['month']['id'] = 'month';
  $handler->display->display_options['sorts']['month']['table'] = 'working_times';
  $handler->display->display_options['sorts']['month']['field'] = 'month';
  $handler->display->display_options['sorts']['month']['order'] = 'DESC';
  /* Sort criterion: Calculated working times: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'working_times';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  /* Filter criterion: Calculated working times: Month */
  $handler->display->display_options['filters']['month']['id'] = 'month';
  $handler->display->display_options['filters']['month']['table'] = 'working_times';
  $handler->display->display_options['filters']['month']['field'] = 'month';
  $handler->display->display_options['filters']['month']['exposed'] = TRUE;
  $handler->display->display_options['filters']['month']['expose']['operator_id'] = 'month_op';
  $handler->display->display_options['filters']['month']['expose']['label'] = 'Month';
  $handler->display->display_options['filters']['month']['expose']['operator'] = 'month_op';
  $handler->display->display_options['filters']['month']['expose']['identifier'] = 'month';
  $handler->display->display_options['filters']['month']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['month']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Year */
  $handler->display->display_options['filters']['year']['id'] = 'year';
  $handler->display->display_options['filters']['year']['table'] = 'working_times';
  $handler->display->display_options['filters']['year']['field'] = 'year';
  $handler->display->display_options['filters']['year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['operator_id'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['year']['expose']['operator'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'working_times';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'year' => 'year',
  );

  /* Display: User working times year */
  $handler = $view->new_display('panel_pane', 'User working times year', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'year' => 'year',
    'holidays_used' => 'holidays_used',
    'holidays_used_from_before' => 'holidays_used_from_before',
    'holidays_available' => 'holidays_available',
    'holidays_available_till' => 'holidays_available_till',
    'ill_days' => 'ill_days',
    'total_hours' => 'total_hours',
    'booked_working_hours' => 'booked_working_hours',
    'overtime' => 'overtime',
    'overtime_reduce' => 'overtime_reduce',
    'project_time' => 'project_time',
    'changed' => 'changed',
    'type' => 'type',
    'id' => 'id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'year' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_used' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_used_from_before' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_available' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_available_till' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'ill_days' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'total_hours' => array(
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
    'booked_working_hours' => array(
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
    'overtime' => array(
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
    'overtime_reduce' => array(
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
    'project_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'id' => array(
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
  $handler->display->display_options['style_options']['separator'] = '.';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Calculated working times: Year */
  $handler->display->display_options['fields']['year']['id'] = 'year';
  $handler->display->display_options['fields']['year']['table'] = 'working_times';
  $handler->display->display_options['fields']['year']['field'] = 'year';
  $handler->display->display_options['fields']['year']['separator'] = '';
  /* Field: Calculated working times: Holidays_used */
  $handler->display->display_options['fields']['holidays_used']['id'] = 'holidays_used';
  $handler->display->display_options['fields']['holidays_used']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_used']['field'] = 'holidays_used';
  $handler->display->display_options['fields']['holidays_used']['label'] = 'Holidays used from this year';
  $handler->display->display_options['fields']['holidays_used']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_used']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_used_from_before */
  $handler->display->display_options['fields']['holidays_used_from_before']['id'] = 'holidays_used_from_before';
  $handler->display->display_options['fields']['holidays_used_from_before']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_used_from_before']['field'] = 'holidays_used_from_before';
  $handler->display->display_options['fields']['holidays_used_from_before']['label'] = 'Holidays used from last year';
  $handler->display->display_options['fields']['holidays_used_from_before']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_used_from_before']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_available */
  $handler->display->display_options['fields']['holidays_available']['id'] = 'holidays_available';
  $handler->display->display_options['fields']['holidays_available']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_available']['field'] = 'holidays_available';
  $handler->display->display_options['fields']['holidays_available']['label'] = 'Holidays available';
  $handler->display->display_options['fields']['holidays_available']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_available']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_available_till */
  $handler->display->display_options['fields']['holidays_available_till']['id'] = 'holidays_available_till';
  $handler->display->display_options['fields']['holidays_available_till']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_available_till']['field'] = 'holidays_available_till';
  $handler->display->display_options['fields']['holidays_available_till']['label'] = 'Holidays expire';
  $handler->display->display_options['fields']['holidays_available_till']['date_format'] = 'erpal_date';
  /* Field: Calculated working times: Ill_days */
  $handler->display->display_options['fields']['ill_days']['id'] = 'ill_days';
  $handler->display->display_options['fields']['ill_days']['table'] = 'working_times';
  $handler->display->display_options['fields']['ill_days']['field'] = 'ill_days';
  $handler->display->display_options['fields']['ill_days']['label'] = 'ill days';
  $handler->display->display_options['fields']['ill_days']['precision'] = '0';
  $handler->display->display_options['fields']['ill_days']['suffix'] = ' days';
  /* Field: Calculated working times: Total_hours */
  $handler->display->display_options['fields']['total_hours']['id'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['table'] = 'working_times';
  $handler->display->display_options['fields']['total_hours']['field'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['label'] = 'Total time';
  $handler->display->display_options['fields']['total_hours']['precision'] = '0';
  $handler->display->display_options['fields']['total_hours']['suffix'] = ' h';
  /* Field: Calculated working times: Booked_working_hours */
  $handler->display->display_options['fields']['booked_working_hours']['id'] = 'booked_working_hours';
  $handler->display->display_options['fields']['booked_working_hours']['table'] = 'working_times';
  $handler->display->display_options['fields']['booked_working_hours']['field'] = 'booked_working_hours';
  $handler->display->display_options['fields']['booked_working_hours']['label'] = 'Booked working time';
  $handler->display->display_options['fields']['booked_working_hours']['precision'] = '0';
  $handler->display->display_options['fields']['booked_working_hours']['suffix'] = ' h';
  /* Field: Calculated working times: Overtime */
  $handler->display->display_options['fields']['overtime']['id'] = 'overtime';
  $handler->display->display_options['fields']['overtime']['table'] = 'working_times';
  $handler->display->display_options['fields']['overtime']['field'] = 'overtime';
  $handler->display->display_options['fields']['overtime']['precision'] = '0';
  $handler->display->display_options['fields']['overtime']['suffix'] = ' h';
  /* Field: Calculated working times: Overtime_reduce */
  $handler->display->display_options['fields']['overtime_reduce']['id'] = 'overtime_reduce';
  $handler->display->display_options['fields']['overtime_reduce']['table'] = 'working_times';
  $handler->display->display_options['fields']['overtime_reduce']['field'] = 'overtime_reduce';
  $handler->display->display_options['fields']['overtime_reduce']['label'] = 'Overtime reduce';
  $handler->display->display_options['fields']['overtime_reduce']['precision'] = '0';
  $handler->display->display_options['fields']['overtime_reduce']['suffix'] = ' h';
  /* Field: Calculated working times: Project_time */
  $handler->display->display_options['fields']['project_time']['id'] = 'project_time';
  $handler->display->display_options['fields']['project_time']['table'] = 'working_times';
  $handler->display->display_options['fields']['project_time']['field'] = 'project_time';
  $handler->display->display_options['fields']['project_time']['label'] = 'Project time';
  $handler->display->display_options['fields']['project_time']['precision'] = '0';
  $handler->display->display_options['fields']['project_time']['suffix'] = 'h';
  /* Field: Calculated working times: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'working_times';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Calculated working times: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'working_times';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Calculated working times: Calculated working times ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'working_times';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Calculated working times: Year */
  $handler->display->display_options['filters']['year']['id'] = 'year';
  $handler->display->display_options['filters']['year']['table'] = 'working_times';
  $handler->display->display_options['filters']['year']['field'] = 'year';
  $handler->display->display_options['filters']['year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['operator_id'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['year']['expose']['operator'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'working_times';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'year' => 'year',
    'offset' => 'offset',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: User working times month */
  $handler = $view->new_display('panel_pane', 'User working times month', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'year' => 'year',
    'month' => 'month',
    'name' => 'name',
    'holidays_used' => 'holidays_used',
    'holidays_used_from_before' => 'holidays_used_from_before',
    'holidays_available' => 'holidays_available',
    'holidays_available_till' => 'holidays_available_till',
    'ill_days' => 'ill_days',
    'total_hours' => 'total_hours',
    'booked_working_hours' => 'booked_working_hours',
    'overtime' => 'overtime',
    'overtime_reduce' => 'overtime_reduce',
    'project_time' => 'project_time',
    'changed' => 'changed',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'year' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'month' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_used' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_used_from_before' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_available' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_available_till' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'ill_days' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'total_hours' => array(
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
    'booked_working_hours' => array(
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
    'overtime' => array(
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
    'overtime_reduce' => array(
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
    'project_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'type' => array(
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
  $handler->display->display_options['style_options']['separator'] = '.';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Calculated working times: Month */
  $handler->display->display_options['filters']['month']['id'] = 'month';
  $handler->display->display_options['filters']['month']['table'] = 'working_times';
  $handler->display->display_options['filters']['month']['field'] = 'month';
  $handler->display->display_options['filters']['month']['exposed'] = TRUE;
  $handler->display->display_options['filters']['month']['expose']['operator_id'] = 'month_op';
  $handler->display->display_options['filters']['month']['expose']['label'] = 'Month';
  $handler->display->display_options['filters']['month']['expose']['operator'] = 'month_op';
  $handler->display->display_options['filters']['month']['expose']['identifier'] = 'month';
  $handler->display->display_options['filters']['month']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['month']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Year */
  $handler->display->display_options['filters']['year']['id'] = 'year';
  $handler->display->display_options['filters']['year']['table'] = 'working_times';
  $handler->display->display_options['filters']['year']['field'] = 'year';
  $handler->display->display_options['filters']['year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['operator_id'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['year']['expose']['operator'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'working_times';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'month' => 'month',
    'offset' => 'offset',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: All working times year */
  $handler = $view->new_display('panel_pane', 'All working times year', 'panel_pane_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any timekeeping';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'year' => 'year',
    'name' => 'name',
    'holidays_used' => 'holidays_used',
    'holidays_used_from_before' => 'holidays_used_from_before',
    'holidays_available' => 'holidays_available',
    'holidays_available_till' => 'holidays_available_till',
    'ill_days' => 'ill_days',
    'total_hours' => 'total_hours',
    'booked_working_hours' => 'booked_working_hours',
    'overtime' => 'overtime',
    'overtime_reduce' => 'overtime_reduce',
    'project_time' => 'project_time',
    'changed' => 'changed',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'year' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_used' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_used_from_before' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_available' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_available_till' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'ill_days' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'total_hours' => array(
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
    'booked_working_hours' => array(
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
    'overtime' => array(
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
    'overtime_reduce' => array(
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
    'project_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'type' => array(
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
  $handler->display->display_options['style_options']['separator'] = '.';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Calculated working times: Year */
  $handler->display->display_options['fields']['year']['id'] = 'year';
  $handler->display->display_options['fields']['year']['table'] = 'working_times';
  $handler->display->display_options['fields']['year']['field'] = 'year';
  $handler->display->display_options['fields']['year']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Calculated working times: Holidays_used */
  $handler->display->display_options['fields']['holidays_used']['id'] = 'holidays_used';
  $handler->display->display_options['fields']['holidays_used']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_used']['field'] = 'holidays_used';
  $handler->display->display_options['fields']['holidays_used']['label'] = 'Holidays used from this year';
  $handler->display->display_options['fields']['holidays_used']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_used']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_used_from_before */
  $handler->display->display_options['fields']['holidays_used_from_before']['id'] = 'holidays_used_from_before';
  $handler->display->display_options['fields']['holidays_used_from_before']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_used_from_before']['field'] = 'holidays_used_from_before';
  $handler->display->display_options['fields']['holidays_used_from_before']['label'] = 'Holidays used from last year';
  $handler->display->display_options['fields']['holidays_used_from_before']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_used_from_before']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_available */
  $handler->display->display_options['fields']['holidays_available']['id'] = 'holidays_available';
  $handler->display->display_options['fields']['holidays_available']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_available']['field'] = 'holidays_available';
  $handler->display->display_options['fields']['holidays_available']['label'] = 'Holidays available';
  $handler->display->display_options['fields']['holidays_available']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_available']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_available_till */
  $handler->display->display_options['fields']['holidays_available_till']['id'] = 'holidays_available_till';
  $handler->display->display_options['fields']['holidays_available_till']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_available_till']['field'] = 'holidays_available_till';
  $handler->display->display_options['fields']['holidays_available_till']['label'] = 'Holidays expire';
  $handler->display->display_options['fields']['holidays_available_till']['date_format'] = 'erpal_date';
  /* Field: Calculated working times: Ill_days */
  $handler->display->display_options['fields']['ill_days']['id'] = 'ill_days';
  $handler->display->display_options['fields']['ill_days']['table'] = 'working_times';
  $handler->display->display_options['fields']['ill_days']['field'] = 'ill_days';
  $handler->display->display_options['fields']['ill_days']['label'] = 'ill days';
  $handler->display->display_options['fields']['ill_days']['precision'] = '0';
  $handler->display->display_options['fields']['ill_days']['suffix'] = ' days';
  /* Field: Calculated working times: Total_hours */
  $handler->display->display_options['fields']['total_hours']['id'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['table'] = 'working_times';
  $handler->display->display_options['fields']['total_hours']['field'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['label'] = 'Total time';
  $handler->display->display_options['fields']['total_hours']['precision'] = '0';
  $handler->display->display_options['fields']['total_hours']['suffix'] = ' h';
  /* Field: Calculated working times: Booked_working_hours */
  $handler->display->display_options['fields']['booked_working_hours']['id'] = 'booked_working_hours';
  $handler->display->display_options['fields']['booked_working_hours']['table'] = 'working_times';
  $handler->display->display_options['fields']['booked_working_hours']['field'] = 'booked_working_hours';
  $handler->display->display_options['fields']['booked_working_hours']['label'] = 'Booked working time';
  $handler->display->display_options['fields']['booked_working_hours']['precision'] = '0';
  $handler->display->display_options['fields']['booked_working_hours']['suffix'] = ' h';
  /* Field: Calculated working times: Overtime */
  $handler->display->display_options['fields']['overtime']['id'] = 'overtime';
  $handler->display->display_options['fields']['overtime']['table'] = 'working_times';
  $handler->display->display_options['fields']['overtime']['field'] = 'overtime';
  $handler->display->display_options['fields']['overtime']['precision'] = '0';
  $handler->display->display_options['fields']['overtime']['suffix'] = ' h';
  /* Field: Calculated working times: Overtime_reduce */
  $handler->display->display_options['fields']['overtime_reduce']['id'] = 'overtime_reduce';
  $handler->display->display_options['fields']['overtime_reduce']['table'] = 'working_times';
  $handler->display->display_options['fields']['overtime_reduce']['field'] = 'overtime_reduce';
  $handler->display->display_options['fields']['overtime_reduce']['label'] = 'Overtime reduce';
  $handler->display->display_options['fields']['overtime_reduce']['precision'] = '0';
  $handler->display->display_options['fields']['overtime_reduce']['suffix'] = ' h';
  /* Field: Calculated working times: Project_time */
  $handler->display->display_options['fields']['project_time']['id'] = 'project_time';
  $handler->display->display_options['fields']['project_time']['table'] = 'working_times';
  $handler->display->display_options['fields']['project_time']['field'] = 'project_time';
  $handler->display->display_options['fields']['project_time']['label'] = 'Project time';
  $handler->display->display_options['fields']['project_time']['precision'] = '0';
  $handler->display->display_options['fields']['project_time']['suffix'] = 'h';
  /* Field: Calculated working times: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'working_times';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Calculated working times: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'working_times';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Calculated working times: Calculated working times ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'working_times';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Calculated working times: Year */
  $handler->display->display_options['filters']['year']['id'] = 'year';
  $handler->display->display_options['filters']['year']['table'] = 'working_times';
  $handler->display->display_options['filters']['year']['field'] = 'year';
  $handler->display->display_options['filters']['year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['operator_id'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['year']['expose']['operator'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'working_times';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'year' => 'year',
    'offset' => 'offset',
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: All working times month */
  $handler = $view->new_display('panel_pane', 'All working times month', 'panel_pane_5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any timekeeping';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'year' => 'year',
    'month' => 'month',
    'name' => 'name',
    'holidays_used' => 'holidays_used',
    'holidays_used_from_before' => 'holidays_used_from_before',
    'holidays_available' => 'holidays_available',
    'holidays_available_till' => 'holidays_available_till',
    'ill_days' => 'ill_days',
    'total_hours' => 'total_hours',
    'booked_working_hours' => 'booked_working_hours',
    'overtime' => 'overtime',
    'overtime_reduce' => 'overtime_reduce',
    'project_time' => 'project_time',
    'changed' => 'changed',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'year' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'month' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_used' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_used_from_before' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_available' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'holidays_available_till' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'ill_days' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'total_hours' => array(
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
    'booked_working_hours' => array(
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
    'overtime' => array(
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
    'overtime_reduce' => array(
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
    'project_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'type' => array(
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
  $handler->display->display_options['style_options']['separator'] = '.';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Calculated working times: Month */
  $handler->display->display_options['filters']['month']['id'] = 'month';
  $handler->display->display_options['filters']['month']['table'] = 'working_times';
  $handler->display->display_options['filters']['month']['field'] = 'month';
  $handler->display->display_options['filters']['month']['exposed'] = TRUE;
  $handler->display->display_options['filters']['month']['expose']['operator_id'] = 'month_op';
  $handler->display->display_options['filters']['month']['expose']['label'] = 'Month';
  $handler->display->display_options['filters']['month']['expose']['operator'] = 'month_op';
  $handler->display->display_options['filters']['month']['expose']['identifier'] = 'month';
  $handler->display->display_options['filters']['month']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['month']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Year */
  $handler->display->display_options['filters']['year']['id'] = 'year';
  $handler->display->display_options['filters']['year']['table'] = 'working_times';
  $handler->display->display_options['filters']['year']['field'] = 'year';
  $handler->display->display_options['filters']['year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['operator_id'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['year']['expose']['operator'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'working_times';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'month' => 'month',
    'offset' => 'offset',
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: User working times offsets */
  $handler = $view->new_display('panel_pane', 'User working times offsets', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'year' => 'year',
    'month' => 'month',
    'name' => 'name',
    'holidays_used' => 'holidays_used',
    'holidays_used_from_before' => 'holidays_used_from_before',
    'holidays_available' => 'holidays_available',
    'holidays_available_till' => 'holidays_available_till',
    'ill_days' => 'ill_days',
    'total_hours' => 'total_hours',
    'booked_working_hours' => 'booked_working_hours',
    'overtime' => 'overtime',
    'overtime_reduce' => 'overtime_reduce',
    'project_time' => 'project_time',
    'edit_working_times' => 'edit_working_times',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'year' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'month' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'holidays_used' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'holidays_used_from_before' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'holidays_available' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'holidays_available_till' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ill_days' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'total_hours' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'booked_working_hours' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'overtime' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'overtime_reduce' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'project_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_working_times' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Calculated working times: Calculated working times ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'working_times';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Calculated working times: Year */
  $handler->display->display_options['fields']['year']['id'] = 'year';
  $handler->display->display_options['fields']['year']['table'] = 'working_times';
  $handler->display->display_options['fields']['year']['field'] = 'year';
  $handler->display->display_options['fields']['year']['separator'] = '';
  /* Field: Calculated working times: Month */
  $handler->display->display_options['fields']['month']['id'] = 'month';
  $handler->display->display_options['fields']['month']['table'] = 'working_times';
  $handler->display->display_options['fields']['month']['field'] = 'month';
  $handler->display->display_options['fields']['month']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Calculated working times: Holidays_used */
  $handler->display->display_options['fields']['holidays_used']['id'] = 'holidays_used';
  $handler->display->display_options['fields']['holidays_used']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_used']['field'] = 'holidays_used';
  $handler->display->display_options['fields']['holidays_used']['label'] = 'Holidays used from this year';
  $handler->display->display_options['fields']['holidays_used']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_used']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_used_from_before */
  $handler->display->display_options['fields']['holidays_used_from_before']['id'] = 'holidays_used_from_before';
  $handler->display->display_options['fields']['holidays_used_from_before']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_used_from_before']['field'] = 'holidays_used_from_before';
  $handler->display->display_options['fields']['holidays_used_from_before']['label'] = 'Holidays used from last year';
  $handler->display->display_options['fields']['holidays_used_from_before']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_used_from_before']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_available */
  $handler->display->display_options['fields']['holidays_available']['id'] = 'holidays_available';
  $handler->display->display_options['fields']['holidays_available']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_available']['field'] = 'holidays_available';
  $handler->display->display_options['fields']['holidays_available']['label'] = 'Holidays available';
  $handler->display->display_options['fields']['holidays_available']['precision'] = '0';
  $handler->display->display_options['fields']['holidays_available']['suffix'] = ' days';
  /* Field: Calculated working times: Holidays_available_till */
  $handler->display->display_options['fields']['holidays_available_till']['id'] = 'holidays_available_till';
  $handler->display->display_options['fields']['holidays_available_till']['table'] = 'working_times';
  $handler->display->display_options['fields']['holidays_available_till']['field'] = 'holidays_available_till';
  $handler->display->display_options['fields']['holidays_available_till']['label'] = 'Holidays expire';
  $handler->display->display_options['fields']['holidays_available_till']['date_format'] = 'erpal_date';
  /* Field: Calculated working times: Ill_days */
  $handler->display->display_options['fields']['ill_days']['id'] = 'ill_days';
  $handler->display->display_options['fields']['ill_days']['table'] = 'working_times';
  $handler->display->display_options['fields']['ill_days']['field'] = 'ill_days';
  $handler->display->display_options['fields']['ill_days']['label'] = 'ill days';
  $handler->display->display_options['fields']['ill_days']['precision'] = '0';
  $handler->display->display_options['fields']['ill_days']['suffix'] = ' days';
  /* Field: Calculated working times: Total_hours */
  $handler->display->display_options['fields']['total_hours']['id'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['table'] = 'working_times';
  $handler->display->display_options['fields']['total_hours']['field'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['label'] = 'Total time';
  $handler->display->display_options['fields']['total_hours']['precision'] = '0';
  $handler->display->display_options['fields']['total_hours']['suffix'] = ' h';
  /* Field: Calculated working times: Booked_working_hours */
  $handler->display->display_options['fields']['booked_working_hours']['id'] = 'booked_working_hours';
  $handler->display->display_options['fields']['booked_working_hours']['table'] = 'working_times';
  $handler->display->display_options['fields']['booked_working_hours']['field'] = 'booked_working_hours';
  $handler->display->display_options['fields']['booked_working_hours']['label'] = 'Booked working time';
  $handler->display->display_options['fields']['booked_working_hours']['precision'] = '0';
  $handler->display->display_options['fields']['booked_working_hours']['suffix'] = ' h';
  /* Field: Calculated working times: Overtime */
  $handler->display->display_options['fields']['overtime']['id'] = 'overtime';
  $handler->display->display_options['fields']['overtime']['table'] = 'working_times';
  $handler->display->display_options['fields']['overtime']['field'] = 'overtime';
  $handler->display->display_options['fields']['overtime']['precision'] = '0';
  $handler->display->display_options['fields']['overtime']['suffix'] = ' h';
  /* Field: Calculated working times: Overtime_reduce */
  $handler->display->display_options['fields']['overtime_reduce']['id'] = 'overtime_reduce';
  $handler->display->display_options['fields']['overtime_reduce']['table'] = 'working_times';
  $handler->display->display_options['fields']['overtime_reduce']['field'] = 'overtime_reduce';
  $handler->display->display_options['fields']['overtime_reduce']['label'] = 'Overtime reduce';
  $handler->display->display_options['fields']['overtime_reduce']['precision'] = '0';
  $handler->display->display_options['fields']['overtime_reduce']['suffix'] = ' h';
  /* Field: Calculated working times: Project_time */
  $handler->display->display_options['fields']['project_time']['id'] = 'project_time';
  $handler->display->display_options['fields']['project_time']['table'] = 'working_times';
  $handler->display->display_options['fields']['project_time']['field'] = 'project_time';
  $handler->display->display_options['fields']['project_time']['label'] = 'Project time';
  $handler->display->display_options['fields']['project_time']['precision'] = '0';
  $handler->display->display_options['fields']['project_time']['suffix'] = 'h';
  /* Field: Calculated working times: Edit Link */
  $handler->display->display_options['fields']['edit_working_times']['id'] = 'edit_working_times';
  $handler->display->display_options['fields']['edit_working_times']['table'] = 'working_times';
  $handler->display->display_options['fields']['edit_working_times']['field'] = 'edit_working_times';
  $handler->display->display_options['fields']['edit_working_times']['label'] = '';
  $handler->display->display_options['fields']['edit_working_times']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Calculated working times: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'working_times';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Calculated working times: Month */
  $handler->display->display_options['filters']['month']['id'] = 'month';
  $handler->display->display_options['filters']['month']['table'] = 'working_times';
  $handler->display->display_options['filters']['month']['field'] = 'month';
  $handler->display->display_options['filters']['month']['exposed'] = TRUE;
  $handler->display->display_options['filters']['month']['expose']['operator_id'] = 'month_op';
  $handler->display->display_options['filters']['month']['expose']['label'] = 'Month';
  $handler->display->display_options['filters']['month']['expose']['operator'] = 'month_op';
  $handler->display->display_options['filters']['month']['expose']['identifier'] = 'month';
  $handler->display->display_options['filters']['month']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['month']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Year */
  $handler->display->display_options['filters']['year']['id'] = 'year';
  $handler->display->display_options['filters']['year']['table'] = 'working_times';
  $handler->display->display_options['filters']['year']['field'] = 'year';
  $handler->display->display_options['filters']['year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['operator_id'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['label'] = 'Year';
  $handler->display->display_options['filters']['year']['expose']['operator'] = 'year_op';
  $handler->display->display_options['filters']['year']['expose']['identifier'] = 'year';
  $handler->display->display_options['filters']['year']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    4 => 0,
    3 => 0,
    9 => 0,
  );
  /* Filter criterion: Calculated working times: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'working_times';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'offset' => 'offset',
  );
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Calculated working times: Uid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['working_times'] = array(
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
    t('No working times found'),
    t('working times user'),
    t('Year'),
    t('.'),
    t('Month'),
    t('Name'),
    t('Holidays used from current year'),
    t(','),
    t(' days'),
    t('Holidays used from last year'),
    t('Holidays available'),
    t('Holidays expire'),
    t('ill days'),
    t('Total time'),
    t(' h'),
    t('Booked working time'),
    t('Overtime'),
    t('Overtime reduce'),
    t('Project time'),
    t('h'),
    t('Changed'),
    t('Type'),
    t('Calculated working times ID'),
    t('User working times year'),
    t('Holidays used from this year'),
    t('View panes'),
    t('User working times month'),
    t('All working times year'),
    t('All working times month'),
    t('User working times offsets'),
    t('All'),
  );
  $export['working_times'] = $view;

  return $export;
}
