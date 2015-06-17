<?php
/**
 * @file
 * erpal_docs_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_docs_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'File Node Panel',
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
              'erpal_file' => 'erpal_file',
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
  $display->uuid = '3e67cf61-cca9-3e24-85d8-8e2dff44249e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b3e02881-9b15-bb24-d121-cef501858c6f';
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
    $pane->uuid = 'b3e02881-9b15-bb24-d121-cef501858c6f';
    $display->content['new-b3e02881-9b15-bb24-d121-cef501858c6f'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-b3e02881-9b15-bb24-d121-cef501858c6f';
    $pane = new stdClass();
    $pane->pid = 'new-8da0bbca-0739-e854-f51f-3566fccffc3f';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_docs_file';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_table',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8da0bbca-0739-e854-f51f-3566fccffc3f';
    $display->content['new-8da0bbca-0739-e854-f51f-3566fccffc3f'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-8da0bbca-0739-e854-f51f-3566fccffc3f';
    $pane = new stdClass();
    $pane->pid = 'new-96da44bd-4037-0aa4-e5a7-9319981a0c13';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'documents_usage_comments-panel_pane_1';
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
    $pane->uuid = '96da44bd-4037-0aa4-e5a7-9319981a0c13';
    $display->content['new-96da44bd-4037-0aa4-e5a7-9319981a0c13'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-96da44bd-4037-0aa4-e5a7-9319981a0c13';
    $pane = new stdClass();
    $pane->pid = 'new-27d30108-ccdc-7694-29e8-42b6be35a264';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'documents-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '27d30108-ccdc-7694-29e8-42b6be35a264';
    $display->content['new-27d30108-ccdc-7694-29e8-42b6be35a264'] = $pane;
    $display->panels['sidebar_second_left'][2] = 'new-27d30108-ccdc-7694-29e8-42b6be35a264';
    $pane = new stdClass();
    $pane->pid = 'new-6a55709c-ef31-4e54-d9d9-c217e5d196be';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'node_revisions-panel_pane_1';
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
    $pane->uuid = '6a55709c-ef31-4e54-d9d9-c217e5d196be';
    $display->content['new-6a55709c-ef31-4e54-d9d9-c217e5d196be'] = $pane;
    $display->panels['sidebar_second_left'][3] = 'new-6a55709c-ef31-4e54-d9d9-c217e5d196be';
    $pane = new stdClass();
    $pane->pid = 'new-6dad2cb1-09f3-b454-0983-9258ceb680d0';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6dad2cb1-09f3-b454-0983-9258ceb680d0';
    $display->content['new-6dad2cb1-09f3-b454-0983-9258ceb680d0'] = $pane;
    $display->panels['sidebar_second_left'][4] = 'new-6dad2cb1-09f3-b454-0983-9258ceb680d0';
    $pane = new stdClass();
    $pane->pid = 'new-8bea3e2f-8511-c1f4-41f3-c261cdee44fd';
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
    $pane->uuid = '8bea3e2f-8511-c1f4-41f3-c261cdee44fd';
    $display->content['new-8bea3e2f-8511-c1f4-41f3-c261cdee44fd'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-8bea3e2f-8511-c1f4-41f3-c261cdee44fd';
    $pane = new stdClass();
    $pane->pid = 'new-705a747d-b57b-a5d4-8de4-f1d01367a5df';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_file_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '705a747d-b57b-a5d4-8de4-f1d01367a5df';
    $display->content['new-705a747d-b57b-a5d4-8de4-f1d01367a5df'] = $pane;
    $display->panels['sidebar_second_right'][1] = 'new-705a747d-b57b-a5d4-8de4-f1d01367a5df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_docs_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'documents_panel';
  $page->task = 'page';
  $page->admin_title = 'Documents Panel';
  $page->admin_description = '';
  $page->path = 'files';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access documents view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
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
  $handler->name = 'page_documents_panel_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'documents_panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Documents panel',
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
      'middle' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Files';
  $display->uuid = 'f5ba8d39-403c-3424-bd72-2fb71a5c3345';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8710f9b7-cfba-3354-594f-f4790d5f3367';
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
    $pane->uuid = '8710f9b7-cfba-3354-594f-f4790d5f3367';
    $display->content['new-8710f9b7-cfba-3354-594f-f4790d5f3367'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-8710f9b7-cfba-3354-594f-f4790d5f3367';
    $pane = new stdClass();
    $pane->pid = 'new-7f764504-1321-e064-b18a-18db5d5c613e';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'documents-panel_pane_2';
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
    $pane->uuid = '7f764504-1321-e064-b18a-18db5d5c613e';
    $display->content['new-7f764504-1321-e064-b18a-18db5d5c613e'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-7f764504-1321-e064-b18a-18db5d5c613e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['documents_panel'] = $page;

  return $pages;

}
