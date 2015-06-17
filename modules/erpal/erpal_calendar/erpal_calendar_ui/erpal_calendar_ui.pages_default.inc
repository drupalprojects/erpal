<?php
/**
 * @file
 * erpal_calendar_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_calendar_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_11';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 10;
  $handler->conf = array(
    'title' => 'Date Node Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_date' => 'erpal_date',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'erpal_content_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3076f069-a248-c6f4-7945-b234a0c61cd6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a1235e57-f78d-a084-4d0d-1b48ac0c0df2';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 1,
      'override_title_text' => '%node:title',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a1235e57-f78d-a084-4d0d-1b48ac0c0df2';
    $display->content['new-a1235e57-f78d-a084-4d0d-1b48ac0c0df2'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-a1235e57-f78d-a084-4d0d-1b48ac0c0df2';
    $pane = new stdClass();
    $pane->pid = 'new-e6541359-8aa4-f8f4-854a-7360fea8dd89';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'page_actions';
    $pane->subtype = 'page_actions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e6541359-8aa4-f8f4-854a-7360fea8dd89';
    $display->content['new-e6541359-8aa4-f8f4-854a-7360fea8dd89'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-e6541359-8aa4-f8f4-854a-7360fea8dd89';
    $pane = new stdClass();
    $pane->pid = 'new-f02f2f27-ec88-ee34-4555-d224e928f456';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'body_and_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f02f2f27-ec88-ee34-4555-d224e928f456';
    $display->content['new-f02f2f27-ec88-ee34-4555-d224e928f456'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-f02f2f27-ec88-ee34-4555-d224e928f456';
    $pane = new stdClass();
    $pane->pid = 'new-b848cb64-1535-5114-adcb-86762bd68101';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'custom_node_content';
    $pane->subtype = 'custom_node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'types' => array(),
      'field_name' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b848cb64-1535-5114-adcb-86762bd68101';
    $display->content['new-b848cb64-1535-5114-adcb-86762bd68101'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-b848cb64-1535-5114-adcb-86762bd68101';
    $pane = new stdClass();
    $pane->pid = 'new-f995c35a-0e4d-3fa4-ed1f-84dd76e8fde4';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_users';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_typed_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f995c35a-0e4d-3fa4-ed1f-84dd76e8fde4';
    $display->content['new-f995c35a-0e4d-3fa4-ed1f-84dd76e8fde4'] = $pane;
    $display->panels['sidebar_second_right'][1] = 'new-f995c35a-0e4d-3fa4-ed1f-84dd76e8fde4';
    $pane = new stdClass();
    $pane->pid = 'new-7377c42f-cbca-4789-9327-9a4836a5c23c';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contacts_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_typed_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7377c42f-cbca-4789-9327-9a4836a5c23c';
    $display->content['new-7377c42f-cbca-4789-9327-9a4836a5c23c'] = $pane;
    $display->panels['sidebar_second_right'][2] = 'new-7377c42f-cbca-4789-9327-9a4836a5c23c';
    $pane = new stdClass();
    $pane->pid = 'new-f0408c6b-f43e-f894-25d7-831f9bce5828';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_date_repeat';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'format_type' => 'erpal_date_time',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
        'show_repeat_rule' => 'show',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f0408c6b-f43e-f894-25d7-831f9bce5828';
    $display->content['new-f0408c6b-f43e-f894-25d7-831f9bce5828'] = $pane;
    $display->panels['sidebar_second_right'][3] = 'new-f0408c6b-f43e-f894-25d7-831f9bce5828';
    $pane = new stdClass();
    $pane->pid = 'new-61c30a7f-a689-4b66-a8a7-6462613e6010';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Author',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '61c30a7f-a689-4b66-a8a7-6462613e6010';
    $display->content['new-61c30a7f-a689-4b66-a8a7-6462613e6010'] = $pane;
    $display->panels['sidebar_second_right'][4] = 'new-61c30a7f-a689-4b66-a8a7-6462613e6010';
    $pane = new stdClass();
    $pane->pid = 'new-966281e5-48c1-4e5d-acdb-498279bead3c';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'long',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Created',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '966281e5-48c1-4e5d-acdb-498279bead3c';
    $display->content['new-966281e5-48c1-4e5d-acdb-498279bead3c'] = $pane;
    $display->panels['sidebar_second_right'][5] = 'new-966281e5-48c1-4e5d-acdb-498279bead3c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_11'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_date_item_panel_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'date_item_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Date item panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from date item (on date_item.subject_node)',
        'keyword' => 'node',
        'name' => 'entity_from_schema:src_id-date_item-node',
        'context' => 'argument_entity_id:date_item_1',
        'id' => 1,
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'erpal_content_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2b2c33d1-e6af-d1f4-1d34-bd4ef883e797';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-54adb62f-540c-7074-6d44-d268baef01d4';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'token';
    $pane->subtype = 'date_item:title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:date_item_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '54adb62f-540c-7074-6d44-d268baef01d4';
    $display->content['new-54adb62f-540c-7074-6d44-d268baef01d4'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-54adb62f-540c-7074-6d44-d268baef01d4';
    $pane = new stdClass();
    $pane->pid = 'new-55b0d402-1376-79c4-25bc-594464f2049c';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'page_actions';
    $pane->subtype = 'page_actions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '55b0d402-1376-79c4-25bc-594464f2049c';
    $display->content['new-55b0d402-1376-79c4-25bc-594464f2049c'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-55b0d402-1376-79c4-25bc-594464f2049c';
    $pane = new stdClass();
    $pane->pid = 'new-61f01334-fa04-4caf-b696-115deeb66c43';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'relationship_entity_from_schema:src_id-date_item-node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '61f01334-fa04-4caf-b696-115deeb66c43';
    $display->content['new-61f01334-fa04-4caf-b696-115deeb66c43'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-61f01334-fa04-4caf-b696-115deeb66c43';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_date_item_panel_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_calendar_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'full_calendar_pane';
  $page->task = 'page';
  $page->admin_title = 'Full calendar pane';
  $page->admin_description = '';
  $page->path = 'calendar/%type';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access calendar view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'type' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
      'keyword' => 'type',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_full_calendar_pane_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'full_calendar_pane';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Full calendar all panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'all',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'erpal_content_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Calendar';
  $display->uuid = 'fd38c263-97e4-f484-f54a-8d7a35bd1120';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a5f24d12-0c8d-7254-c9bb-8ada698a36e7';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'page_actions';
    $pane->subtype = 'page_actions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a5f24d12-0c8d-7254-c9bb-8ada698a36e7';
    $display->content['new-a5f24d12-0c8d-7254-c9bb-8ada698a36e7'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-a5f24d12-0c8d-7254-c9bb-8ada698a36e7';
    $pane = new stdClass();
    $pane->pid = 'new-f0b4488c-0777-86f4-b951-4fafd1e89c44';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'full_calendar-full_calendar_all_dates';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f0b4488c-0777-86f4-b951-4fafd1e89c44';
    $display->content['new-f0b4488c-0777-86f4-b951-4fafd1e89c44'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-f0b4488c-0777-86f4-b951-4fafd1e89c44';
    $pane = new stdClass();
    $pane->pid = 'new-3254cc3d-bda8-4284-e9d0-985d9f89311d';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'fullcalendar_legend';
    $pane->subtype = 'fullcalendar_legend';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'full_calendar-panel_pane_1',
      'legend_type' => 'taxonomy',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3254cc3d-bda8-4284-e9d0-985d9f89311d';
    $display->content['new-3254cc3d-bda8-4284-e9d0-985d9f89311d'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-3254cc3d-bda8-4284-e9d0-985d9f89311d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_full_calendar_pane_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'full_calendar_pane';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Full calendar own panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'own',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'erpal_content_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'My Calendar';
  $display->uuid = 'aa11380c-2a3f-ec24-d9e8-f7018ab2a9f8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4de998dd-df2c-b224-ed7a-1605aecceb72';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'page_actions';
    $pane->subtype = 'page_actions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4de998dd-df2c-b224-ed7a-1605aecceb72';
    $display->content['new-4de998dd-df2c-b224-ed7a-1605aecceb72'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-4de998dd-df2c-b224-ed7a-1605aecceb72';
    $pane = new stdClass();
    $pane->pid = 'new-9853fd68-f262-9664-4148-9572784ebdfc';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'full_calendar-full_calendar_own_dates';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9853fd68-f262-9664-4148-9572784ebdfc';
    $display->content['new-9853fd68-f262-9664-4148-9572784ebdfc'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-9853fd68-f262-9664-4148-9572784ebdfc';
    $pane = new stdClass();
    $pane->pid = 'new-08556cdc-344e-8dc4-d5b8-c7bd92379b34';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'fullcalendar_legend';
    $pane->subtype = 'fullcalendar_legend';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'full_calendar-panel_pane_1',
      'legend_type' => 'taxonomy',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '08556cdc-344e-8dc4-d5b8-c7bd92379b34';
    $display->content['new-08556cdc-344e-8dc4-d5b8-c7bd92379b34'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-08556cdc-344e-8dc4-d5b8-c7bd92379b34';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_full_calendar_pane_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'full_calendar_pane';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Full calendar all holidays',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'holidays',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'erpal_content_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Holiday calendar';
  $display->uuid = 'ebd816db-c103-45ee-b289-e39de90bb9c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d3f75e4d-63ec-458d-9c6d-a61fa20c85a7';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'page_actions';
    $pane->subtype = 'page_actions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd3f75e4d-63ec-458d-9c6d-a61fa20c85a7';
    $display->content['new-d3f75e4d-63ec-458d-9c6d-a61fa20c85a7'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-d3f75e4d-63ec-458d-9c6d-a61fa20c85a7';
    $pane = new stdClass();
    $pane->pid = 'new-bca09a9e-6af7-4787-b429-9301f2706b28';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'full_calendar_all_holidays-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bca09a9e-6af7-4787-b429-9301f2706b28';
    $display->content['new-bca09a9e-6af7-4787-b429-9301f2706b28'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-bca09a9e-6af7-4787-b429-9301f2706b28';
    $pane = new stdClass();
    $pane->pid = 'new-7311edce-9ad0-48b5-894e-c0150378d293';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'fullcalendar_legend';
    $pane->subtype = 'fullcalendar_legend';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'full_calendar-panel_pane_1',
      'legend_type' => 'taxonomy',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7311edce-9ad0-48b5-894e-c0150378d293';
    $display->content['new-7311edce-9ad0-48b5-894e-c0150378d293'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-7311edce-9ad0-48b5-894e-c0150378d293';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['full_calendar_pane'] = $page;

  return $pages;

}
