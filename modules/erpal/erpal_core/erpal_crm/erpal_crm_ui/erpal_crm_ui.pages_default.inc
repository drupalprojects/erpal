<?php
/**
 * @file
 * erpal_crm_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_crm_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Contact Node Panel',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_contact' => 'erpal_contact',
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
      'left' => NULL,
      'right' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '84eb2c44-660d-8224-31c9-1210f69b6f89';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-201c69ab-2512-2d54-1980-f42ae24eb63a';
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
    $pane->uuid = '201c69ab-2512-2d54-1980-f42ae24eb63a';
    $display->content['new-201c69ab-2512-2d54-1980-f42ae24eb63a'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-201c69ab-2512-2d54-1980-f42ae24eb63a';
    $pane = new stdClass();
    $pane->pid = 'new-88a284ed-92be-8a64-11c5-aaff250a4e5c';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-contact-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'More Data to this Contact:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '88a284ed-92be-8a64-11c5-aaff250a4e5c';
    $display->content['new-88a284ed-92be-8a64-11c5-aaff250a4e5c'] = $pane;
    $display->panels['sidebar_first_right'][1] = 'new-88a284ed-92be-8a64-11c5-aaff250a4e5c';
    $pane = new stdClass();
    $pane->pid = 'new-f94abcd5-30d1-00b4-e945-45c092711b0d';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
      'build_mode' => 'node_view',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f94abcd5-30d1-00b4-e945-45c092711b0d';
    $display->content['new-f94abcd5-30d1-00b4-e945-45c092711b0d'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-f94abcd5-30d1-00b4-e945-45c092711b0d';
    $pane = new stdClass();
    $pane->pid = 'new-37ce7d36-9347-3de4-0946-343378def8bc';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '50',
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
    $pane->uuid = '37ce7d36-9347-3de4-0946-343378def8bc';
    $display->content['new-37ce7d36-9347-3de4-0946-343378def8bc'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-37ce7d36-9347-3de4-0946-343378def8bc';
    $pane = new stdClass();
    $pane->pid = 'new-a88bd61c-1cc3-54d4-15cd-4a92bc02e9b7';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
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
    $pane->uuid = 'a88bd61c-1cc3-54d4-15cd-4a92bc02e9b7';
    $display->content['new-a88bd61c-1cc3-54d4-15cd-4a92bc02e9b7'] = $pane;
    $display->panels['sidebar_second_left'][2] = 'new-a88bd61c-1cc3-54d4-15cd-4a92bc02e9b7';
    $pane = new stdClass();
    $pane->pid = 'new-83f6c9c9-993b-0b34-b16f-6b9a21efa2dd';
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
    $pane->uuid = '83f6c9c9-993b-0b34-b16f-6b9a21efa2dd';
    $display->content['new-83f6c9c9-993b-0b34-b16f-6b9a21efa2dd'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-83f6c9c9-993b-0b34-b16f-6b9a21efa2dd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 7;
  $handler->conf = array(
    'title' => 'Activity Node Panel',
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
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_crm_activity' => 'erpal_crm_activity',
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
      'middle' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '4af7f671-1637-da94-3120-b4e6524f6d96';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-75b27fe9-9395-5e64-05a0-4cd2a402490d';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 1,
      'leave_node_title' => 0,
      'build_mode' => 'node_view',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '75b27fe9-9395-5e64-05a0-4cd2a402490d';
    $display->content['new-75b27fe9-9395-5e64-05a0-4cd2a402490d'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-75b27fe9-9395-5e64-05a0-4cd2a402490d';
    $pane = new stdClass();
    $pane->pid = 'new-a9ada6f9-0666-a734-5962-d105245206d9';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '50',
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
    $pane->uuid = 'a9ada6f9-0666-a734-5962-d105245206d9';
    $display->content['new-a9ada6f9-0666-a734-5962-d105245206d9'] = $pane;
    $display->panels['sidebar_first_left'][1] = 'new-a9ada6f9-0666-a734-5962-d105245206d9';
    $pane = new stdClass();
    $pane->pid = 'new-47715f81-fef0-c9a4-b94f-24fb2a26e820';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
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
    $pane->uuid = '47715f81-fef0-c9a4-b94f-24fb2a26e820';
    $display->content['new-47715f81-fef0-c9a4-b94f-24fb2a26e820'] = $pane;
    $display->panels['sidebar_first_left'][2] = 'new-47715f81-fef0-c9a4-b94f-24fb2a26e820';
    $pane = new stdClass();
    $pane->pid = 'new-0f697b15-1538-11f4-c55b-5c65230e7ab3';
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
    $pane->uuid = '0f697b15-1538-11f4-c55b-5c65230e7ab3';
    $display->content['new-0f697b15-1538-11f4-c55b-5c65230e7ab3'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-0f697b15-1538-11f4-c55b-5c65230e7ab3';
    $pane = new stdClass();
    $pane->pid = 'new-4d5905a7-af24-af44-69f7-b1a575510b85';
    $pane->panel = 'sidebar_first_right';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4d5905a7-af24-af44-69f7-b1a575510b85';
    $display->content['new-4d5905a7-af24-af44-69f7-b1a575510b85'] = $pane;
    $display->panels['sidebar_first_right'][1] = 'new-4d5905a7-af24-af44-69f7-b1a575510b85';
    $pane = new stdClass();
    $pane->pid = 'new-08157855-6de5-e4f4-89a6-18d3f284e5f0';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'activity_status_panel';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '08157855-6de5-e4f4-89a6-18d3f284e5f0';
    $display->content['new-08157855-6de5-e4f4-89a6-18d3f284e5f0'] = $pane;
    $display->panels['sidebar_first_right'][2] = 'new-08157855-6de5-e4f4-89a6-18d3f284e5f0';
    $pane = new stdClass();
    $pane->pid = 'new-e81ad87f-ac07-4ab2-87df-edc342d80793';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'projects-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e81ad87f-ac07-4ab2-87df-edc342d80793';
    $display->content['new-e81ad87f-ac07-4ab2-87df-edc342d80793'] = $pane;
    $display->panels['sidebar_first_right'][3] = 'new-e81ad87f-ac07-4ab2-87df-edc342d80793';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_8'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_crm_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'crm';
  $page->task = 'page';
  $page->admin_title = 'Activities';
  $page->admin_description = '';
  $page->path = 'activities';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access activities view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_crm_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'crm';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'CRM Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'erpal_content_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Activities';
  $display->uuid = '81b143a2-b8be-3da4-89b9-e2f6643ceac7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cc397cb5-ea74-4df4-f925-c30c03741c41';
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
    $pane->uuid = 'cc397cb5-ea74-4df4-f925-c30c03741c41';
    $display->content['new-cc397cb5-ea74-4df4-f925-c30c03741c41'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-cc397cb5-ea74-4df4-f925-c30c03741c41';
    $pane = new stdClass();
    $pane->pid = 'new-33f0cbce-1c39-77d4-31d4-d9749804da0c';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-all_activities_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '33f0cbce-1c39-77d4-31d4-d9749804da0c';
    $display->content['new-33f0cbce-1c39-77d4-31d4-d9749804da0c'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-33f0cbce-1c39-77d4-31d4-d9749804da0c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['crm'] = $page;

  return $pages;

}
