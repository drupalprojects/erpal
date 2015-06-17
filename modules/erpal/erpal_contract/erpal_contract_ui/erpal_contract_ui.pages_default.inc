<?php
/**
 * @file
 * erpal_contract_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_contract_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_9';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 8;
  $handler->conf = array(
    'title' => 'Contract Node Pane',
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
              'erpal_contract' => 'erpal_contract',
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
  $display->title = '%node:title';
  $display->uuid = 'a70d9748-cd47-02a4-d16b-35b70c8e2a60';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8f4a7252-d666-1464-cd39-ba43b97e4ead';
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
    $pane->uuid = '8f4a7252-d666-1464-cd39-ba43b97e4ead';
    $display->content['new-8f4a7252-d666-1464-cd39-ba43b97e4ead'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-8f4a7252-d666-1464-cd39-ba43b97e4ead';
    $pane = new stdClass();
    $pane->pid = 'new-ebbceb8b-bf99-3134-154e-0a911dfa5d17';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'contract_basic_panel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
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
    $pane->uuid = 'ebbceb8b-bf99-3134-154e-0a911dfa5d17';
    $display->content['new-ebbceb8b-bf99-3134-154e-0a911dfa5d17'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-ebbceb8b-bf99-3134-154e-0a911dfa5d17';
    $pane = new stdClass();
    $pane->pid = 'new-c44b5b85-74f0-56e4-c17e-3c6a15e3299c';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'contract_time_information';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c44b5b85-74f0-56e4-c17e-3c6a15e3299c';
    $display->content['new-c44b5b85-74f0-56e4-c17e-3c6a15e3299c'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-c44b5b85-74f0-56e4-c17e-3c6a15e3299c';
    $pane = new stdClass();
    $pane->pid = 'new-fa3436a7-e353-3584-fdda-360a36de23cf';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'body_and_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
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
    $pane->uuid = 'fa3436a7-e353-3584-fdda-360a36de23cf';
    $display->content['new-fa3436a7-e353-3584-fdda-360a36de23cf'] = $pane;
    $display->panels['sidebar_second_left'][2] = 'new-fa3436a7-e353-3584-fdda-360a36de23cf';
    $pane = new stdClass();
    $pane->pid = 'new-6230d94d-4d1f-42d4-fd2f-8fc05957e172';
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
    $pane->uuid = '6230d94d-4d1f-42d4-fd2f-8fc05957e172';
    $display->content['new-6230d94d-4d1f-42d4-fd2f-8fc05957e172'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-6230d94d-4d1f-42d4-fd2f-8fc05957e172';
    $pane = new stdClass();
    $pane->pid = 'new-6cbac466-b1f1-3bc4-e1a3-d3d1b4f6d5f6';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'contract_budget_information';
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
    $pane->uuid = '6cbac466-b1f1-3bc4-e1a3-d3d1b4f6d5f6';
    $display->content['new-6cbac466-b1f1-3bc4-e1a3-d3d1b4f6d5f6'] = $pane;
    $display->panels['sidebar_second_left'][3] = 'new-6cbac466-b1f1-3bc4-e1a3-d3d1b4f6d5f6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_9'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_contract_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'contracts';
  $page->task = 'page';
  $page->admin_title = 'Contracts';
  $page->admin_description = '';
  $page->path = 'contracts';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access contracts view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Contracts',
    'name' => 'menu-erpal-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_contracts_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'contracts';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Contracts panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->title = 'Contracts';
  $display->uuid = '8fb537c3-b959-ccc4-45c6-3c6e00eadd9b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c87cc644-041d-f904-9984-9e36d42d5fa5';
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
    $pane->uuid = 'c87cc644-041d-f904-9984-9e36d42d5fa5';
    $display->content['new-c87cc644-041d-f904-9984-9e36d42d5fa5'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-c87cc644-041d-f904-9984-9e36d42d5fa5';
    $pane = new stdClass();
    $pane->pid = 'new-142a187a-a7e7-405a-9482-336c4f4f2a51';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-contract_tabs';
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
    $pane->uuid = '142a187a-a7e7-405a-9482-336c4f4f2a51';
    $display->content['new-142a187a-a7e7-405a-9482-336c4f4f2a51'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-142a187a-a7e7-405a-9482-336c4f4f2a51';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['contracts'] = $page;

  return $pages;

}
