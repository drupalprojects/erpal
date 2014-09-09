<?php
/**
 * @file
 * erpal_heartbeat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_heartbeat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'erpal_heartbeat';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'ERPAL heartbeat';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Global heartbeat';
  $handler->display->display_options['css_class'] = 'erpal-heartbeat';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access erpal heartbeat';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'entity';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No messages created yet';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No heartbeat activity available

';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_erpal_hb_node_ref_target_id']['id'] = 'field_erpal_hb_node_ref_target_id';
  $handler->display->display_options['relationships']['field_erpal_hb_node_ref_target_id']['table'] = 'field_data_field_erpal_hb_node_ref';
  $handler->display->display_options['relationships']['field_erpal_hb_node_ref_target_id']['field'] = 'field_erpal_hb_node_ref_target_id';
  $handler->display->display_options['relationships']['field_erpal_hb_node_ref_target_id']['required'] = TRUE;
  /* Field: User picture - (Partial 0) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['ui_name'] = 'User picture - (Partial 0)';
  $handler->display->display_options['fields']['message_render']['label'] = '';
  $handler->display->display_options['fields']['message_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render']['partials'] = 1;
  $handler->display->display_options['fields']['message_render']['partials_delta'] = '0';
  /* Field: Operation info - (Partial 1) */
  $handler->display->display_options['fields']['message_render_1']['id'] = 'message_render_1';
  $handler->display->display_options['fields']['message_render_1']['table'] = 'message';
  $handler->display->display_options['fields']['message_render_1']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render_1']['ui_name'] = 'Operation info - (Partial 1)';
  $handler->display->display_options['fields']['message_render_1']['label'] = '';
  $handler->display->display_options['fields']['message_render_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render_1']['partials'] = 1;
  $handler->display->display_options['fields']['message_render_1']['partials_delta'] = '1';
  /* Field: Teaser - (Partial 2) */
  $handler->display->display_options['fields']['message_render_2']['id'] = 'message_render_2';
  $handler->display->display_options['fields']['message_render_2']['table'] = 'message';
  $handler->display->display_options['fields']['message_render_2']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render_2']['ui_name'] = 'Teaser - (Partial 2)';
  $handler->display->display_options['fields']['message_render_2']['label'] = '';
  $handler->display->display_options['fields']['message_render_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render_2']['partials'] = 1;
  $handler->display->display_options['fields']['message_render_2']['partials_delta'] = '2';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Message: Published (field_erpal_hb_published) */
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['id'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['table'] = 'field_data_field_erpal_hb_published';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['field'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'user';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  /* Filter criterion: Date: Date (message) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'message';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'message.timestamp' => 'message.timestamp',
  );

  /* Display: Heartbeat Page All */
  $handler = $view->new_display('page', 'Heartbeat Page All', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Published (field_erpal_hb_published) */
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['id'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['table'] = 'field_data_field_erpal_hb_published';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['field'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'user';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'User';
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
    9 => 0,
  );
  /* Filter criterion: Date: Date (message) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'message';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'message.timestamp' => 'message.timestamp',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_erpal_hb_node_ref_target_id';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'heartbeat/all';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Message example';
  $handler->display->display_options['menu']['description'] = 'Typical UAS (User activity stream).';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Heartbeat page own */
  $handler = $view->new_display('page', 'Heartbeat page own', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My heartbeat';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Published (field_erpal_hb_published) */
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['id'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['table'] = 'field_data_field_erpal_hb_published';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['field'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Date: Date (message) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'message';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'message.timestamp' => 'message.timestamp',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'user';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_erpal_hb_node_ref_target_id';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'heartbeat';

  /* Display: Global heartbeat block */
  $handler = $view->new_display('block', 'Global heartbeat block', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Published (field_erpal_hb_published) */
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['id'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['table'] = 'field_data_field_erpal_hb_published';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['field'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['value'] = array(
    1 => '1',
  );

  /* Display: Own heartbeat block */
  $handler = $view->new_display('block', 'Own heartbeat block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My heartbeat';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Published (field_erpal_hb_published) */
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['id'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['table'] = 'field_data_field_erpal_hb_published';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['field'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'user';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Project heartbeat */
  $handler = $view->new_display('panel_pane', 'Project heartbeat', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Project heartbeat';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Project (field_project_ref) */
  $handler->display->display_options['arguments']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['relationship'] = 'field_erpal_hb_node_ref_target_id';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_project_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Published (field_erpal_hb_published) */
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['id'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['table'] = 'field_data_field_erpal_hb_published';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['field'] = 'field_erpal_hb_published_value';
  $handler->display->display_options['filters']['field_erpal_hb_published_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'user';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  /* Filter criterion: Date: Date (message) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'message';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'message.timestamp' => 'message.timestamp',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_erpal_hb_node_ref_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_task' => 'erpal_task',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['erpal_heartbeat'] = array(
    t('Master'),
    t('Global heartbeat'),
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
    t('No messages created yet'),
    t('No heartbeat activity available

'),
    t('User'),
    t('Content entity referenced from field_erpal_hb_node_ref'),
    t('Name'),
    t('Date'),
    t('Heartbeat Page All'),
    t('Content type'),
    t('Heartbeat page own'),
    t('My heartbeat'),
    t('Global heartbeat block'),
    t('Own heartbeat block'),
    t('Project heartbeat'),
    t('All'),
    t('View panes'),
  );
  $export['erpal_heartbeat'] = $view;

  return $export;
}
