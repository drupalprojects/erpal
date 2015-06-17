<?php
/**
 * @file
 * erpal_project_release_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_project_release_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_12';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 11;
  $handler->conf = array(
    'title' => 'Release Node Panel',
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
          'name' => 'node_access',
          'settings' => array(
            'type' => 'view',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project_release' => 'erpal_project_release',
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
  $display->uuid = 'b9b65663-7930-c644-31ad-52a6de7d0c46';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6288d261-578f-f0c4-c5d2-9fb00b3fd6e5';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'release_header_fields';
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
    $pane->uuid = '6288d261-578f-f0c4-c5d2-9fb00b3fd6e5';
    $display->content['new-6288d261-578f-f0c4-c5d2-9fb00b3fd6e5'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-6288d261-578f-f0c4-c5d2-9fb00b3fd6e5';
    $pane = new stdClass();
    $pane->pid = 'new-c8a46d4b-747d-47b4-ed38-ae690c72c9a1';
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
    $pane->uuid = 'c8a46d4b-747d-47b4-ed38-ae690c72c9a1';
    $display->content['new-c8a46d4b-747d-47b4-ed38-ae690c72c9a1'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-c8a46d4b-747d-47b4-ed38-ae690c72c9a1';
    $pane = new stdClass();
    $pane->pid = 'new-a95f1ad5-7216-4974-1197-58053a53aaaa';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-release_content_tabs';
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
    $pane->uuid = 'a95f1ad5-7216-4974-1197-58053a53aaaa';
    $display->content['new-a95f1ad5-7216-4974-1197-58053a53aaaa'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-a95f1ad5-7216-4974-1197-58053a53aaaa';
    $pane = new stdClass();
    $pane->pid = 'new-d005b3da-4e35-8334-2d35-75c103593ef4';
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
    $pane->uuid = 'd005b3da-4e35-8334-2d35-75c103593ef4';
    $display->content['new-d005b3da-4e35-8334-2d35-75c103593ef4'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-d005b3da-4e35-8334-2d35-75c103593ef4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_12'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_project_release_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_tasks_to_release_panel';
  $page->task = 'page';
  $page->admin_title = 'Add tasks to release panel';
  $page->admin_description = '';
  $page->path = 'node/%release_node/addtasks/%project_node';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_access',
        'settings' => array(
          'type' => 'view',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'create erpal_project_release content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'release_node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    'project_node' => array(
      'id' => 2,
      'identifier' => 'Node: ID 2',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_add_tasks_to_release_panel_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'add_tasks_to_release_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Add tasks to release panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from Node (on Node: Project [field_project_ref])',
        'keyword' => 'project',
        'name' => 'entity_from_field:field_project_ref-node-node',
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
              'erpal_project_release' => 'erpal_project_release',
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
  $display->title = 'Add tasks to release "%release_node:title"';
  $display->uuid = '0f2e6038-ac0e-b0e4-011d-1152df18f035';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9d273c47-0acb-efd4-e5a6-6383e7520030';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Release',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9d273c47-0acb-efd4-e5a6-6383e7520030';
    $display->content['new-9d273c47-0acb-efd4-e5a6-6383e7520030'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-9d273c47-0acb-efd4-e5a6-6383e7520030';
    $pane = new stdClass();
    $pane->pid = 'new-855ce5a2-bdf2-6014-5dfc-46a7fac2f1f4';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'relationship_entity_from_field:field_project_ref-node-node_1',
      'override_title' => 1,
      'override_title_text' => 'Project',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '855ce5a2-bdf2-6014-5dfc-46a7fac2f1f4';
    $display->content['new-855ce5a2-bdf2-6014-5dfc-46a7fac2f1f4'] = $pane;
    $display->panels['sidebar_first_left'][1] = 'new-855ce5a2-bdf2-6014-5dfc-46a7fac2f1f4';
    $pane = new stdClass();
    $pane->pid = 'new-6374e160-0e41-4dc4-ed62-5a8e9cead91d';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'tasks_for_release-panel_pane_1';
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
    $pane->uuid = '6374e160-0e41-4dc4-ed62-5a8e9cead91d';
    $display->content['new-6374e160-0e41-4dc4-ed62-5a8e9cead91d'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-6374e160-0e41-4dc4-ed62-5a8e9cead91d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_tasks_to_release_panel'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_releases_panel';
  $page->task = 'page';
  $page->admin_title = 'Project releases panel';
  $page->admin_description = '';
  $page->path = 'node/%node/releases';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_access',
        'settings' => array(
          'type' => 'view',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view project releases',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_project_releases_panel_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'project_releases_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project releases panel',
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
  $display->title = 'Releases for %node:title';
  $display->uuid = 'd9d41e9b-3965-eff4-edda-abb0ef659a41';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ce832970-c951-f954-89d0-d90fa3d1f47a';
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
    $pane->uuid = 'ce832970-c951-f954-89d0-d90fa3d1f47a';
    $display->content['new-ce832970-c951-f954-89d0-d90fa3d1f47a'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-ce832970-c951-f954-89d0-d90fa3d1f47a';
    $pane = new stdClass();
    $pane->pid = 'new-edf1ac30-c066-5994-5568-c52193316550';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'releases-panel_pane_1';
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
    $pane->uuid = 'edf1ac30-c066-5994-5568-c52193316550';
    $display->content['new-edf1ac30-c066-5994-5568-c52193316550'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-edf1ac30-c066-5994-5568-c52193316550';
    $pane = new stdClass();
    $pane->pid = 'new-96048d41-5781-6224-a10a-28cdceb6925b';
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
    $pane->uuid = '96048d41-5781-6224-a10a-28cdceb6925b';
    $display->content['new-96048d41-5781-6224-a10a-28cdceb6925b'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-96048d41-5781-6224-a10a-28cdceb6925b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_releases_panel'] = $page;

  return $pages;

}
