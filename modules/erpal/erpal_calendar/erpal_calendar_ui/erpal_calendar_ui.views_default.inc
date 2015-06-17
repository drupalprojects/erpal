<?php
/**
 * @file
 * erpal_calendar_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_calendar_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'erpal_ical_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'date_item';
  $view->human_name = 'ical Export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'All Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'feed_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access calendar view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Date item: Referenced source node */
  $handler->display->display_options['relationships']['src_id']['id'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['table'] = 'date_item';
  $handler->display->display_options['relationships']['src_id']['field'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['label'] = 'Date Node';
  $handler->display->display_options['relationships']['src_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_users_target_id_1']['id'] = 'field_users_target_id_1';
  $handler->display->display_options['relationships']['field_users_target_id_1']['table'] = 'field_data_field_users';
  $handler->display->display_options['relationships']['field_users_target_id_1']['field'] = 'field_users_target_id';
  $handler->display->display_options['relationships']['field_users_target_id_1']['relationship'] = 'src_id';
  /* Field: date item: Date */
  $handler->display->display_options['fields']['field_date_item_date']['id'] = 'field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['table'] = 'field_data_field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['field'] = 'field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'src_id';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'src_id';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_users_target_id_1';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Date item: Date item type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'date_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simple_date' => 'simple_date',
  );

  /* Display: my-events.ical */
  $handler = $view->new_display('feed', 'my-events.ical', 'my_events_ical');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Events';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['style_options']['cal_name'] = '';
  $handler->display->display_options['row_plugin'] = 'date_ical_fields';
  $handler->display->display_options['row_options']['date_field'] = 'field_date_item_date';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['additional_settings'] = array(
    'skip_blank_dates' => 0,
  );
  $handler->display->display_options['path'] = 'my-events.ical';
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: all-events.ical */
  $handler = $view->new_display('feed', 'all-events.ical', 'all_events_ical');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['style_options']['cal_name'] = '';
  $handler->display->display_options['row_plugin'] = 'date_ical_fields';
  $handler->display->display_options['row_options']['date_field'] = 'field_date_item_date';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['description_field'] = 'body';
  $handler->display->display_options['row_options']['additional_settings'] = array(
    'skip_blank_dates' => 0,
  );
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Date item: Referenced source node */
  $handler->display->display_options['relationships']['src_id']['id'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['table'] = 'date_item';
  $handler->display->display_options['relationships']['src_id']['field'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['label'] = 'Date Node';
  $handler->display->display_options['relationships']['src_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Date item: Date item type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'date_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simple_date' => 'simple_date',
  );
  /* Filter criterion: date item: Date tags (field_date_item_tags) */
  $handler->display->display_options['filters']['field_date_item_tags_tid']['id'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['table'] = 'field_data_field_date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['field'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['value'] = array(
    302 => '302',
    352 => '352',
  );
  $handler->display->display_options['filters']['field_date_item_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['vocabulary'] = 'date_item_tags';
  $handler->display->display_options['path'] = 'all-events.ical';
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['erpal_ical_export'] = array(
    t('Master'),
    t('All Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Date Node'),
    t('User entity referenced from field_users'),
    t('Date'),
    t('Title'),
    t('Body'),
    t('All'),
    t('my-events.ical'),
    t('My Events'),
    t('all-events.ical'),
  );
  $export['erpal_ical_export'] = $view;

  $view = new view();
  $view->name = 'full_calendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'date_item';
  $view->human_name = 'full calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access calendar view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['firstDay'] = '1';
  $handler->display->display_options['style_options']['fields']['title'] = TRUE;
  /* Relationship: Date item: Referenced source node */
  $handler->display->display_options['relationships']['src_id']['id'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['table'] = 'date_item';
  $handler->display->display_options['relationships']['src_id']['field'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['id'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['table'] = 'field_data_field_task_assigned_users';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['field'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['relationships']['field_task_assigned_users_target_id']['relationship'] = 'src_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_users_target_id']['id'] = 'field_users_target_id';
  $handler->display->display_options['relationships']['field_users_target_id']['table'] = 'field_data_field_users';
  $handler->display->display_options['relationships']['field_users_target_id']['field'] = 'field_users_target_id';
  $handler->display->display_options['relationships']['field_users_target_id']['relationship'] = 'src_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'src_id';
  /* Field: date item: Date */
  $handler->display->display_options['fields']['field_date_item_date']['id'] = 'field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['table'] = 'field_data_field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['field'] = 'field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'src_id';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_task_assigned_users_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_users_target_id';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'users';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_2']['exclude'] = TRUE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['relationship'] = 'src_id';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  /* Contextual filter: Date: Date (date_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'date_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'date_item.date_from' => 'date_item.date_from',
    'date_item.date_till' => 'date_item.date_till',
  );
  /* Filter criterion: date item: Date tags (field_date_item_tags) */
  $handler->display->display_options['filters']['field_date_item_tags_tid']['id'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['table'] = 'field_data_field_date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['field'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator_id'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['label'] = 'Date categories';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['identifier'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['vocabulary'] = 'date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'name_1' => 'name_1',
  );
  /* Filter criterion: Date item: Date item type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'date_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simple_date' => 'simple_date',
  );
  /* Filter criterion: Date item: Date item removed */
  $handler->display->display_options['filters']['removed']['id'] = 'removed';
  $handler->display->display_options['filters']['removed']['table'] = 'date_item';
  $handler->display->display_options['filters']['removed']['field'] = 'removed';
  $handler->display->display_options['filters']['removed']['value'] = '0';

  /* Display: Full own calendar pane */
  $handler = $view->new_display('panel_pane', 'Full own calendar pane', 'full_calendar_own_dates');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Expose *.ical feed';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<div>
  <label for="ical-integration">Integrate this Calendar into Google Calendar, iCalendar and Microsoft Outlook: </label>
  <?php /*Sadly views doesn\'t have a token integration, so we\'ve got to use PHP here...*/ $url=url(\'my-events.ical\',array(\'absolute\'=>TRUE,\'query\'=>array(\'token\'=>tokenauth_get_token()))); ?>
  <input id="ical-integration" type="text" onclick="jQuery(this).val(\'<?php print $url; ?>\').select();" onblur="jQuery(this).val(\'<?php print $url; ?>\');" value="<?php print $url; ?>" />
</div>
';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: date item: Date tags (field_date_item_tags) */
  $handler->display->display_options['filters']['field_date_item_tags_tid']['id'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['table'] = 'field_data_field_date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['field'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator_id'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['label'] = 'Date categories';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['identifier'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['vocabulary'] = 'date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 2;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'name_1' => 'name_1',
    'name_2' => 'name_2',
  );
  $handler->display->display_options['filters']['combine']['exclude_from_select_area'] = 1;
  /* Filter criterion: Content: date type (field_date_type) */
  $handler->display->display_options['filters']['field_date_type_value']['id'] = 'field_date_type_value';
  $handler->display->display_options['filters']['field_date_type_value']['table'] = 'field_data_field_date_type';
  $handler->display->display_options['filters']['field_date_type_value']['field'] = 'field_date_type_value';
  $handler->display->display_options['filters']['field_date_type_value']['relationship'] = 'src_id';
  $handler->display->display_options['filters']['field_date_type_value']['value'] = array(
    'holiday' => 'holiday',
  );
  $handler->display->display_options['filters']['field_date_type_value']['group'] = 2;
  /* Filter criterion: Date item: Date item type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'date_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simple_date' => 'simple_date',
  );
  /* Filter criterion: Date item: Date item removed */
  $handler->display->display_options['filters']['removed']['id'] = 'removed';
  $handler->display->display_options['filters']['removed']['table'] = 'date_item';
  $handler->display->display_options['filters']['removed']['field'] = 'removed';
  $handler->display->display_options['filters']['removed']['value'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Project calendar pane */
  $handler = $view->new_display('panel_pane', 'Project calendar pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['relationship'] = 'src_id';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['erpal_subtasks']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['types'] = array(
    'erpal_project' => 'erpal_project',
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['arguments']['erpal_subtasks']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['erpal_subtasks']['validate']['fail'] = 'access denied';
  /* Contextual filter: Date: Date (date_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'date_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'date_item.date_from' => 'date_item.date_from',
    'date_item.date_till' => 'date_item.date_till',
  );
  $handler->display->display_options['argument_input'] = array(
    'erpal_subtasks' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Task: Task subtasks',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Full all calendar pane */
  $handler = $view->new_display('panel_pane', 'Full all calendar pane', 'full_calendar_all_dates');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Expose *.ical feed';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<div>
  <label for="ical-integration">Integrate this Calendar into Google Calendar, iCalendar and Microsoft Outlook: </label>
  <?php /*Sadly views doesn\'t have a token integration, so we\'ve got to use PHP here...*/ $url=url(\'all-events.ical\',array(\'absolute\'=>TRUE,\'query\'=>array(\'token\'=>tokenauth_get_token()))); ?>
  <input id="ical-integration" type="text" onclick="jQuery(this).val(\'<?php print $url; ?>\').select();" onblur="jQuery(this).val(\'<?php print $url; ?>\');" value="<?php print $url; ?>" />
</div>
';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: date item: Date tags (field_date_item_tags) */
  $handler->display->display_options['filters']['field_date_item_tags_tid']['id'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['table'] = 'field_data_field_date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['field'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator_id'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['label'] = 'Date categories';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['identifier'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['vocabulary'] = 'date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'name_1' => 'name_1',
    'name_2' => 'name_2',
  );
  $handler->display->display_options['filters']['combine']['exclude_from_select_area'] = 1;
  /* Filter criterion: Date item: Date item type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'date_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simple_date' => 'simple_date',
  );
  /* Filter criterion: Date item: Date item removed */
  $handler->display->display_options['filters']['removed']['id'] = 'removed';
  $handler->display->display_options['filters']['removed']['table'] = 'date_item';
  $handler->display->display_options['filters']['removed']['field'] = 'removed';
  $handler->display->display_options['filters']['removed']['value'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: User dates today */
  $handler = $view->new_display('block', 'User dates today', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My appointments today';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['defaultView'] = 'agendaDay';
  $handler->display->display_options['style_options']['firstDay'] = '1';
  $handler->display->display_options['style_options']['right'] = '';
  $handler->display->display_options['style_options']['contentHeight'] = 650;
  $handler->display->display_options['style_options']['fields']['title'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Task: Task subtasks */
  $handler->display->display_options['arguments']['erpal_subtasks']['id'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['table'] = 'node';
  $handler->display->display_options['arguments']['erpal_subtasks']['field'] = 'erpal_subtasks';
  $handler->display->display_options['arguments']['erpal_subtasks']['relationship'] = 'src_id';
  $handler->display->display_options['arguments']['erpal_subtasks']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['erpal_subtasks']['summary']['format'] = 'default_summary';
  /* Contextual filter: Date: Date (date_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'date_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'date_item.date_from' => 'date_item.date_from',
    'date_item.date_till' => 'date_item.date_till',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: date item: Date tags (field_date_item_tags) */
  $handler->display->display_options['filters']['field_date_item_tags_tid']['id'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['table'] = 'field_data_field_date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['field'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator_id'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['label'] = 'Date categories';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['operator'] = 'field_date_item_tags_tid_op';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['identifier'] = 'field_date_item_tags_tid';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_date_item_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_date_item_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['vocabulary'] = 'date_item_tags';
  $handler->display->display_options['filters']['field_date_item_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Date item: Date item type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'date_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simple_date' => 'simple_date',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'name_1' => 'name_1',
    'name_2' => 'name_2',
  );
  $handler->display->display_options['filters']['combine']['exclude_from_select_area'] = 1;
  /* Filter criterion: Date item: Date item removed */
  $handler->display->display_options['filters']['removed']['id'] = 'removed';
  $handler->display->display_options['filters']['removed']['table'] = 'date_item';
  $handler->display->display_options['filters']['removed']['field'] = 'removed';
  $handler->display->display_options['filters']['removed']['value'] = '0';
  $translatables['full_calendar'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('relation src node'),
    t('User entity referenced from field_task_assigned_users'),
    t('User entity referenced from field_users'),
    t('author'),
    t('Date'),
    t('Title'),
    t('Name'),
    t('All'),
    t('Date categories'),
    t('User'),
    t('Full own calendar pane'),
    t('Expose *.ical feed'),
    t('View panes'),
    t('Project calendar pane'),
    t('Full all calendar pane'),
    t('Username'),
    t('User dates today'),
    t('My appointments today'),
  );
  $export['full_calendar'] = $view;

  $view = new view();
  $view->name = 'full_calendar_all_holidays';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'date_item';
  $view->human_name = 'Full calendar all holidays';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access holidays calendar view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['fields']['title'] = TRUE;
  /* Relationship: Date item: Referenced source node */
  $handler->display->display_options['relationships']['src_id']['id'] = 'src_id';
  $handler->display->display_options['relationships']['src_id']['table'] = 'date_item';
  $handler->display->display_options['relationships']['src_id']['field'] = 'src_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'src_id';
  /* Field: date item: Date */
  $handler->display->display_options['fields']['field_date_item_date']['id'] = 'field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['table'] = 'field_data_field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['field'] = 'field_date_item_date';
  $handler->display->display_options['fields']['field_date_item_date']['label'] = 'Datum';
  $handler->display->display_options['fields']['field_date_item_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Contextual filter: Date: Date (date_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'date_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'date_item.date_from' => 'date_item.date_from',
    'date_item.date_till' => 'date_item.date_till',
  );
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Date item: Date item type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'date_item';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simple_date' => 'simple_date',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date item: Date item removed */
  $handler->display->display_options['filters']['removed']['id'] = 'removed';
  $handler->display->display_options['filters']['removed']['table'] = 'date_item';
  $handler->display->display_options['filters']['removed']['field'] = 'removed';
  $handler->display->display_options['filters']['removed']['value'] = '0';
  $handler->display->display_options['filters']['removed']['group'] = 1;
  /* Filter criterion: Content: Working time type (field_working_time_type) */
  $handler->display->display_options['filters']['field_working_time_type_value']['id'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['table'] = 'field_data_field_working_time_type';
  $handler->display->display_options['filters']['field_working_time_type_value']['field'] = 'field_working_time_type_value';
  $handler->display->display_options['filters']['field_working_time_type_value']['relationship'] = 'src_id';
  $handler->display->display_options['filters']['field_working_time_type_value']['value'] = array(
    'holiday' => 'holiday',
  );
  $handler->display->display_options['filters']['field_working_time_type_value']['group'] = 2;
  $handler->display->display_options['filters']['field_working_time_type_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Content: date type (field_date_type) */
  $handler->display->display_options['filters']['field_date_type_value']['id'] = 'field_date_type_value';
  $handler->display->display_options['filters']['field_date_type_value']['table'] = 'field_data_field_date_type';
  $handler->display->display_options['filters']['field_date_type_value']['field'] = 'field_date_type_value';
  $handler->display->display_options['filters']['field_date_type_value']['relationship'] = 'src_id';
  $handler->display->display_options['filters']['field_date_type_value']['value'] = array(
    'holiday' => 'holiday',
  );
  $handler->display->display_options['filters']['field_date_type_value']['group'] = 2;
  $handler->display->display_options['filters']['field_date_type_value']['reduce_duplicates'] = TRUE;

  /* Display: All holidays full calendar */
  $handler = $view->new_display('panel_pane', 'All holidays full calendar', 'panel_pane_1');
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['full_calendar_all_holidays'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('relation src node'),
    t('Title'),
    t('Datum'),
    t('All'),
    t('All holidays full calendar'),
    t('View panes'),
  );
  $export['full_calendar_all_holidays'] = $view;

  return $export;
}
