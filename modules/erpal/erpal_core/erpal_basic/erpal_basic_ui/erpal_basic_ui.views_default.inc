<?php
/**
 * @file
 * erpal_basic_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_basic_ui_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access contact view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_contact_image' => 'field_contact_image',
    'title' => 'title',
    'field_contact_type' => 'field_contact_type',
    'field_contact_tags' => 'field_contact_tags',
    'field_activity_origin' => 'field_activity_origin',
    'field_target_audience' => 'field_target_audience',
    'field_customer_category' => 'field_customer_category',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_contact_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'field_contact_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_activity_origin' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_target_audience' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_customer_category' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'There are no contacts available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_contact_image']['id'] = 'field_contact_image';
  $handler->display->display_options['fields']['field_contact_image']['table'] = 'field_data_field_contact_image';
  $handler->display->display_options['fields']['field_contact_image']['field'] = 'field_contact_image';
  $handler->display->display_options['fields']['field_contact_image']['label'] = '';
  $handler->display->display_options['fields']['field_contact_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_image']['empty'] = '<div class="no_contact_image"></div>';
  $handler->display->display_options['fields']['field_contact_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_contact_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Contact Type */
  $handler->display->display_options['fields']['field_contact_type']['id'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['field'] = 'field_contact_type';
  /* Field: Content: Contact Tags */
  $handler->display->display_options['fields']['field_contact_tags']['id'] = 'field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['table'] = 'field_data_field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['field'] = 'field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['label'] = 'Categories';
  $handler->display->display_options['fields']['field_contact_tags']['type'] = 'editable';
  $handler->display->display_options['fields']['field_contact_tags']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
  );
  $handler->display->display_options['fields']['field_contact_tags']['delta_offset'] = '0';
  /* Field: Content: Origin */
  $handler->display->display_options['fields']['field_activity_origin']['id'] = 'field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['field'] = 'field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['type'] = 'editable';
  $handler->display->display_options['fields']['field_activity_origin']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Terms';
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
  );
  /* Filter criterion: Content: Contact Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_value']['id'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_value']['field'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_contact_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['operator_id'] = 'field_contact_type_value_op';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['label'] = 'Contact Type';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['operator'] = 'field_contact_type_value_op';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['identifier'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
    'erpal_contact' => 'erpal_contact',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Content: Contact Tags (field_contact_tags) */
  $handler->display->display_options['filters']['field_contact_tags_tid']['id'] = 'field_contact_tags_tid';
  $handler->display->display_options['filters']['field_contact_tags_tid']['table'] = 'field_data_field_contact_tags';
  $handler->display->display_options['filters']['field_contact_tags_tid']['field'] = 'field_contact_tags_tid';
  $handler->display->display_options['filters']['field_contact_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['operator_id'] = 'field_contact_tags_tid_op';
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['operator'] = 'field_contact_tags_tid_op';
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['identifier'] = 'field_contact_tags_tid';
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_contact_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_tags_tid']['vocabulary'] = 'contact_tags';
  $handler->display->display_options['filters']['field_contact_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Origin (field_activity_origin) */
  $handler->display->display_options['filters']['field_activity_origin_tid']['id'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['field'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator_id'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['label'] = 'Origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['identifier'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_activity_origin_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_origin_tid']['vocabulary'] = 'activity_origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['error_message'] = FALSE;

  /* Display: Contacts pane */
  $handler = $view->new_display('panel_pane', 'Contacts pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_contact_image']['id'] = 'field_contact_image';
  $handler->display->display_options['fields']['field_contact_image']['table'] = 'field_data_field_contact_image';
  $handler->display->display_options['fields']['field_contact_image']['field'] = 'field_contact_image';
  $handler->display->display_options['fields']['field_contact_image']['label'] = '';
  $handler->display->display_options['fields']['field_contact_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_image']['empty'] = '<div class="no_contact_image"></div>';
  $handler->display->display_options['fields']['field_contact_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_contact_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Contact Type */
  $handler->display->display_options['fields']['field_contact_type']['id'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['field'] = 'field_contact_type';
  /* Field: Content: Contact Tags */
  $handler->display->display_options['fields']['field_contact_tags']['id'] = 'field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['table'] = 'field_data_field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['field'] = 'field_contact_tags';
  $handler->display->display_options['fields']['field_contact_tags']['label'] = 'Categories';
  $handler->display->display_options['fields']['field_contact_tags']['type'] = 'editable';
  $handler->display->display_options['fields']['field_contact_tags']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
  );
  $handler->display->display_options['fields']['field_contact_tags']['delta_offset'] = '0';
  /* Field: Content: Origin */
  $handler->display->display_options['fields']['field_activity_origin']['id'] = 'field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['field'] = 'field_activity_origin';
  $handler->display->display_options['fields']['field_activity_origin']['type'] = 'editable';
  $handler->display->display_options['fields']['field_activity_origin']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
  );
  /* Field: Content: Target audience */
  $handler->display->display_options['fields']['field_target_audience']['id'] = 'field_target_audience';
  $handler->display->display_options['fields']['field_target_audience']['table'] = 'field_data_field_target_audience';
  $handler->display->display_options['fields']['field_target_audience']['field'] = 'field_target_audience';
  $handler->display->display_options['fields']['field_target_audience']['type'] = 'editable';
  $handler->display->display_options['fields']['field_target_audience']['settings'] = array(
    'click_to_edit' => 0,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
  );
  /* Field: Field: Customer Category */
  $handler->display->display_options['fields']['field_customer_category']['id'] = 'field_customer_category';
  $handler->display->display_options['fields']['field_customer_category']['table'] = 'field_data_field_customer_category';
  $handler->display->display_options['fields']['field_customer_category']['field'] = 'field_customer_category';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Search Terms';
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
  );
  /* Filter criterion: Content: Contact Type (field_contact_type) */
  $handler->display->display_options['filters']['field_contact_type_value']['id'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['filters']['field_contact_type_value']['field'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_contact_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['operator_id'] = 'field_contact_type_value_op';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['label'] = 'Contact Type';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['operator'] = 'field_contact_type_value_op';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['identifier'] = 'field_contact_type_value';
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_contact_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
    'erpal_contact' => 'erpal_contact',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Content: Contact Tags (field_contact_tags) */
  $handler->display->display_options['filters']['field_contact_tags_tid']['id'] = 'field_contact_tags_tid';
  $handler->display->display_options['filters']['field_contact_tags_tid']['table'] = 'field_data_field_contact_tags';
  $handler->display->display_options['filters']['field_contact_tags_tid']['field'] = 'field_contact_tags_tid';
  $handler->display->display_options['filters']['field_contact_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['operator_id'] = 'field_contact_tags_tid_op';
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['operator'] = 'field_contact_tags_tid_op';
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['identifier'] = 'field_contact_tags_tid';
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_contact_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_contact_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_tags_tid']['vocabulary'] = 'contact_tags';
  $handler->display->display_options['filters']['field_contact_tags_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Origin (field_activity_origin) */
  $handler->display->display_options['filters']['field_activity_origin_tid']['id'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['table'] = 'field_data_field_activity_origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['field'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator_id'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['label'] = 'Origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['operator'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['identifier'] = 'field_activity_origin_tid';
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_activity_origin_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_activity_origin_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_activity_origin_tid']['vocabulary'] = 'activity_origin';
  $handler->display->display_options['filters']['field_activity_origin_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Target audience (field_target_audience) */
  $handler->display->display_options['filters']['field_target_audience_tid']['id'] = 'field_target_audience_tid';
  $handler->display->display_options['filters']['field_target_audience_tid']['table'] = 'field_data_field_target_audience';
  $handler->display->display_options['filters']['field_target_audience_tid']['field'] = 'field_target_audience_tid';
  $handler->display->display_options['filters']['field_target_audience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['operator_id'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['label'] = 'Target audience';
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['operator'] = 'field_activity_origin_tid_op';
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['identifier'] = 'field_target_audience_tid';
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_target_audience_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_target_audience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_target_audience_tid']['vocabulary'] = 'target_audience_terms';
  $handler->display->display_options['filters']['field_target_audience_tid']['error_message'] = FALSE;
  /* Filter criterion: Field: Customer Category (field_customer_category) */
  $handler->display->display_options['filters']['field_customer_category_value']['id'] = 'field_customer_category_value';
  $handler->display->display_options['filters']['field_customer_category_value']['table'] = 'field_data_field_customer_category';
  $handler->display->display_options['filters']['field_customer_category_value']['field'] = 'field_customer_category_value';
  $handler->display->display_options['filters']['field_customer_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_category_value']['expose']['operator_id'] = 'field_customer_category_value_op';
  $handler->display->display_options['filters']['field_customer_category_value']['expose']['label'] = 'Customer Category';
  $handler->display->display_options['filters']['field_customer_category_value']['expose']['operator'] = 'field_customer_category_value_op';
  $handler->display->display_options['filters']['field_customer_category_value']['expose']['identifier'] = 'field_customer_category_value';
  $handler->display->display_options['filters']['field_customer_category_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_customer_category_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_customer_category_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Contact Dialog Search Project */
  $handler = $view->new_display('references_dialog', 'Contact Dialog Search Project', 'references_dialog_customer_project');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Choose a contact';
  $handler->display->display_options['display_description'] = 'Search a customer for a project';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Contact Type */
  $handler->display->display_options['fields']['field_contact_type']['id'] = 'field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['table'] = 'field_data_field_contact_type';
  $handler->display->display_options['fields']['field_contact_type']['field'] = 'field_contact_type';
  $handler->display->display_options['attach'] = array(
    0 => 'node:field_customer_ref:erpal_project',
  );
  $translatables['contacts'] = array(
    t('Master'),
    t('more'),
    t('Filter'),
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
    t('There are no contacts available'),
    t('<div class="no_contact_image"></div>'),
    t('Name'),
    t('Contact Type'),
    t('Categories'),
    t('Origin'),
    t('Search Terms'),
    t('Type'),
    t('Contacts pane'),
    t('Target audience'),
    t('Customer Category'),
    t('View panes'),
    t('Contact Dialog Search Project'),
    t('Choose a contact'),
    t('Search a customer for a project'),
  );
  $export['contacts'] = $view;

  $view = new view();
  $view->name = 'node_revisions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Node revisions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Revisions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'timestamp' => 'timestamp',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'erpal_date_time';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Sort criterion: Content revision: Updated date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Pane node revisions */
  $handler = $view->new_display('panel_pane', 'Pane node revisions', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $translatables['node_revisions'] = array(
    t('Master'),
    t('Revisions'),
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
    t('revision user'),
    t('Get the actual content from a content revision.'),
    t('Updated date'),
    t('User'),
    t('All'),
    t('Pane node revisions'),
    t('View panes'),
  );
  $export['node_revisions'] = $view;

  $view = new view();
  $view->name = 'notifications';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Notifications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Task notifications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'ops' => 'ops',
    'changed' => 'changed',
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
    'ops' => array(
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
  );
  /* Relationship: Flags: task_subscriptions */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flagged task';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'task_subscriptions';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_project_ref_target_id']['id'] = 'field_project_ref_target_id';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['table'] = 'field_data_field_project_ref';
  $handler->display->display_options['relationships']['field_project_ref_target_id']['field'] = 'field_project_ref_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Task title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_project_ref_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Project';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Notification';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Task notifications */
  $handler = $view->new_display('panel_pane', 'Task notifications', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Project notifications */
  $handler = $view->new_display('panel_pane', 'Project notifications', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Project notifications';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: project_subscriptions */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'project_subscriptions';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Project title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Notification';
  $translatables['notifications'] = array(
    t('Master'),
    t('Task notifications'),
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
    t('flagged task'),
    t('Content entity referenced from field_project_ref'),
    t('Task title'),
    t('Project'),
    t('Updated date'),
    t('Notification'),
    t('View panes'),
    t('Project notifications'),
    t('flag'),
    t('Project title'),
  );
  $export['notifications'] = $view;

  $view = new view();
  $view->name = 'relations_view';
  $view->description = 'Lists relations of a certain type';
  $view->tag = 'default';
  $view->base_table = 'relation';
  $view->human_name = 'Relations view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Relations by node';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No relations available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints']['id'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['label'] = '';
  $handler->display->display_options['fields']['endpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints']['delta_offset'] = '0';
  /* Field: Relation: Rendered Relation */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_relation';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  /* Contextual filter: Relation: Relation type */
  $handler->display->display_options['arguments']['relation_type']['id'] = 'relation_type';
  $handler->display->display_options['arguments']['relation_type']['table'] = 'relation';
  $handler->display->display_options['arguments']['relation_type']['field'] = 'relation_type';
  $handler->display->display_options['arguments']['relation_type']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['relation_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['relation_type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['relation_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['relation_type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['relation_type']['limit'] = '0';
  /* Filter criterion: Relation: Relation type */
  $handler->display->display_options['filters']['relation_type']['id'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['table'] = 'relation';
  $handler->display->display_options['filters']['relation_type']['field'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['relation_type']['expose']['operator_id'] = 'relation_type_op';
  $handler->display->display_options['filters']['relation_type']['expose']['label'] = 'Relation type';
  $handler->display->display_options['filters']['relation_type']['expose']['operator'] = 'relation_type_op';
  $handler->display->display_options['filters']['relation_type']['expose']['identifier'] = 'relation_type';
  $handler->display->display_options['filters']['relation_type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['relation_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Relations by node */
  $handler = $view->new_display('panel_pane', 'Relations by node', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'endpoints' => 'endpoints',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'endpoints' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Relation: endpoints */
  $handler->display->display_options['fields']['endpoints']['id'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['table'] = 'field_data_endpoints';
  $handler->display->display_options['fields']['endpoints']['field'] = 'endpoints';
  $handler->display->display_options['fields']['endpoints']['label'] = '';
  $handler->display->display_options['fields']['endpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['endpoints']['click_sort_column'] = 'entity_type';
  $handler->display->display_options['fields']['endpoints']['type'] = 'relation_endpoint_simple_table';
  $handler->display->display_options['fields']['endpoints']['delta_offset'] = '0';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
  $handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date_1']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Relation: Change Date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'relation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'erpal_date_time';
  /* Field: Relation: Create Date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'relation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'erpal_date_time';
  /* Field: Relation: Relation Tags */
  $handler->display->display_options['fields']['field_work_at_rel_tags']['id'] = 'field_work_at_rel_tags';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['table'] = 'field_data_field_work_at_rel_tags';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['field'] = 'field_work_at_rel_tags';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['label'] = 'Tags';
  $handler->display->display_options['fields']['field_work_at_rel_tags']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Relation: Relation type */
  $handler->display->display_options['fields']['relation_type']['id'] = 'relation_type';
  $handler->display->display_options['fields']['relation_type']['table'] = 'relation';
  $handler->display->display_options['fields']['relation_type']['field'] = 'relation_type';
  /* Field: Relation: Role in project */
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['id'] = 'field_projet_role_rel_tags';
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['table'] = 'field_data_field_projet_role_rel_tags';
  $handler->display->display_options['fields']['field_projet_role_rel_tags']['field'] = 'field_projet_role_rel_tags';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Relation: endpoints (endpoints:entity_id) */
  $handler->display->display_options['arguments']['endpoints_entity_id']['id'] = 'endpoints_entity_id';
  $handler->display->display_options['arguments']['endpoints_entity_id']['table'] = 'field_data_endpoints';
  $handler->display->display_options['arguments']['endpoints_entity_id']['field'] = 'endpoints_entity_id';
  $handler->display->display_options['arguments']['endpoints_entity_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['endpoints_entity_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['endpoints_entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['endpoints_entity_id']['break_phrase'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'endpoints_entity_id' => array(
      'type' => 'panel',
      'context' => 'entity:comment.node',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Relation: endpoints (endpoints:entity_id)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['relations_view'] = array(
    t('Master'),
    t('Relations by node'),
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
    t('No relations available'),
    t('Rendered Relation'),
    t('All'),
    t('Relation type'),
    t('Period'),
    t('Changed'),
    t('Created'),
    t('Tags'),
    t('Role in project'),
    t('View panes'),
  );
  $export['relations_view'] = $view;

  return $export;
}
