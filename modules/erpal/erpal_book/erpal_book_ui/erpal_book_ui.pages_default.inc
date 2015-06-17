<?php
/**
 * @file
 * erpal_book_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_book_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Book Node Panel',
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
              'erpal_book' => 'erpal_book',
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
  $display->uuid = '29c4f81f-0d28-2f64-b5a1-2c3b4f526e7a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5b550b8b-405b-26c4-6121-aeb252c101a9';
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
    $pane->uuid = '5b550b8b-405b-26c4-6121-aeb252c101a9';
    $display->content['new-5b550b8b-405b-26c4-6121-aeb252c101a9'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-5b550b8b-405b-26c4-6121-aeb252c101a9';
    $pane = new stdClass();
    $pane->pid = 'new-8d7842ec-bd4a-44a8-8789-eeeda696cca7';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-book_and_page_node_tabs';
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
    $pane->uuid = '8d7842ec-bd4a-44a8-8789-eeeda696cca7';
    $display->content['new-8d7842ec-bd4a-44a8-8789-eeeda696cca7'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-8d7842ec-bd4a-44a8-8789-eeeda696cca7';
    $pane = new stdClass();
    $pane->pid = 'new-4955cf4a-8ab2-18f4-4968-cd1c61546e98';
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
    $pane->uuid = '4955cf4a-8ab2-18f4-4968-cd1c61546e98';
    $display->content['new-4955cf4a-8ab2-18f4-4968-cd1c61546e98'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-4955cf4a-8ab2-18f4-4968-cd1c61546e98';
    $pane = new stdClass();
    $pane->pid = 'new-d8684cb5-a75b-ec34-e18e-0c1248263702';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'book_children-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd8684cb5-a75b-ec34-e18e-0c1248263702';
    $display->content['new-d8684cb5-a75b-ec34-e18e-0c1248263702'] = $pane;
    $display->panels['sidebar_second_right'][1] = 'new-d8684cb5-a75b-ec34-e18e-0c1248263702';
    $pane = new stdClass();
    $pane->pid = 'new-66702636-8d2d-9784-554d-a0d8da11960b';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'book_general_fields';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'General',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '66702636-8d2d-9784-554d-a0d8da11960b';
    $display->content['new-66702636-8d2d-9784-554d-a0d8da11960b'] = $pane;
    $display->panels['sidebar_second_right'][2] = 'new-66702636-8d2d-9784-554d-a0d8da11960b';
    $pane = new stdClass();
    $pane->pid = 'new-8d00bd72-15ea-9ac4-59c6-6a1878f88550';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'book_page_fields';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Page information',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '8d00bd72-15ea-9ac4-59c6-6a1878f88550';
    $display->content['new-8d00bd72-15ea-9ac4-59c6-6a1878f88550'] = $pane;
    $display->panels['sidebar_second_right'][3] = 'new-8d00bd72-15ea-9ac4-59c6-6a1878f88550';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Book-page Node Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Node (on Node: Book [field_book_ref])',
        'keyword' => 'book',
        'name' => 'entity_from_field:field_book_ref-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book_page' => 'erpal_book_page',
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
  $display->uuid = 'ea491472-ba03-c354-918e-02ea3bdca6c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9b6115cf-f05e-f974-25ad-fb59d5aeb948';
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
    $pane->uuid = '9b6115cf-f05e-f974-25ad-fb59d5aeb948';
    $display->content['new-9b6115cf-f05e-f974-25ad-fb59d5aeb948'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-9b6115cf-f05e-f974-25ad-fb59d5aeb948';
    $pane = new stdClass();
    $pane->pid = 'new-3d3a7133-e069-4a98-8549-b624c16a84f7';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-book_and_page_node_tabs';
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
    $pane->uuid = '3d3a7133-e069-4a98-8549-b624c16a84f7';
    $display->content['new-3d3a7133-e069-4a98-8549-b624c16a84f7'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-3d3a7133-e069-4a98-8549-b624c16a84f7';
    $pane = new stdClass();
    $pane->pid = 'new-3808fe6b-bb53-2994-15cb-b0845bbeb6da';
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
    $pane->uuid = '3808fe6b-bb53-2994-15cb-b0845bbeb6da';
    $display->content['new-3808fe6b-bb53-2994-15cb-b0845bbeb6da'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-3808fe6b-bb53-2994-15cb-b0845bbeb6da';
    $pane = new stdClass();
    $pane->pid = 'new-2aff6ea7-d3a3-5944-75f1-04762b81f7f3';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'book_children-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_book_parent_target_id' => '%book:nid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2aff6ea7-d3a3-5944-75f1-04762b81f7f3';
    $display->content['new-2aff6ea7-d3a3-5944-75f1-04762b81f7f3'] = $pane;
    $display->panels['sidebar_second_right'][1] = 'new-2aff6ea7-d3a3-5944-75f1-04762b81f7f3';
    $pane = new stdClass();
    $pane->pid = 'new-19f6e90d-d0b5-37d4-e1f3-f797e3e38068';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'book_general_fields';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'General',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '19f6e90d-d0b5-37d4-e1f3-f797e3e38068';
    $display->content['new-19f6e90d-d0b5-37d4-e1f3-f797e3e38068'] = $pane;
    $display->panels['sidebar_second_right'][2] = 'new-19f6e90d-d0b5-37d4-e1f3-f797e3e38068';
    $pane = new stdClass();
    $pane->pid = 'new-9b19658f-a55f-2fd4-7d2d-f9679abe4a82';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'book_page_fields';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Page information',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '9b19658f-a55f-2fd4-7d2d-f9679abe4a82';
    $display->content['new-9b19658f-a55f-2fd4-7d2d-f9679abe4a82'] = $pane;
    $display->panels['sidebar_second_right'][3] = 'new-9b19658f-a55f-2fd4-7d2d-f9679abe4a82';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_book_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'books';
  $page->task = 'page';
  $page->admin_title = 'Books';
  $page->admin_description = '';
  $page->path = 'books/%book_type';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access books view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'book_type' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
      'keyword' => 'book_type',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_books_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'books';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Books panel',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'books/books',
          ),
          'context' => 'empty',
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
  $display->title = 'Documents';
  $display->uuid = '99055d10-cf55-b7b4-0dff-b51721744686';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f6fb25f5-e37c-d304-f9b5-f3ab76b88289';
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
    $pane->uuid = 'f6fb25f5-e37c-d304-f9b5-f3ab76b88289';
    $display->content['new-f6fb25f5-e37c-d304-f9b5-f3ab76b88289'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-f6fb25f5-e37c-d304-f9b5-f3ab76b88289';
    $pane = new stdClass();
    $pane->pid = 'new-3013c368-4186-bf94-fd37-6d77a9722396';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'books-panel_pane_1';
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
    $pane->uuid = '3013c368-4186-bf94-fd37-6d77a9722396';
    $display->content['new-3013c368-4186-bf94-fd37-6d77a9722396'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-3013c368-4186-bf94-fd37-6d77a9722396';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_books_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'books';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Templates panel',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'books/templates',
          ),
          'context' => 'empty',
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
  $display->uuid = '317c7783-ca1c-c9f4-5d39-f1f4a0894ccb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-38219e3a-70d6-12b4-0db7-d8780c2ceab2';
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
      'override_title_text' => 'Templates',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '38219e3a-70d6-12b4-0db7-d8780c2ceab2';
    $display->content['new-38219e3a-70d6-12b4-0db7-d8780c2ceab2'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-38219e3a-70d6-12b4-0db7-d8780c2ceab2';
    $pane = new stdClass();
    $pane->pid = 'new-ba00a90e-07c8-5514-1991-bcb78ffaac4c';
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
    $pane->uuid = 'ba00a90e-07c8-5514-1991-bcb78ffaac4c';
    $display->content['new-ba00a90e-07c8-5514-1991-bcb78ffaac4c'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-ba00a90e-07c8-5514-1991-bcb78ffaac4c';
    $pane = new stdClass();
    $pane->pid = 'new-247e6599-9635-89e4-9d76-99e97a1cdcd4';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'books-panel_pane_2';
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
    $pane->uuid = '247e6599-9635-89e4-9d76-99e97a1cdcd4';
    $display->content['new-247e6599-9635-89e4-9d76-99e97a1cdcd4'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-247e6599-9635-89e4-9d76-99e97a1cdcd4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['books'] = $page;

  return $pages;

}
