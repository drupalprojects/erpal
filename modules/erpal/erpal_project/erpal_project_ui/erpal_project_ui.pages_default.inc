<?php
/**
 * @file
 * erpal_project_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_project_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project Node Panel',
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
              'erpal_project' => 'erpal_project',
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
      'middle' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
    'sidebar_second_right' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'c9742b1b-7e4a-0fc4-d103-623ca996c6bf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2f2734c7-7b06-9934-91ff-b86266f5995a';
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
    $pane->uuid = '2f2734c7-7b06-9934-91ff-b86266f5995a';
    $display->content['new-2f2734c7-7b06-9934-91ff-b86266f5995a'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-2f2734c7-7b06-9934-91ff-b86266f5995a';
    $pane = new stdClass();
    $pane->pid = 'new-1fd9d07a-d680-5734-6947-e620dcb2ab25';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-project_node_tabs';
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
    $pane->uuid = '1fd9d07a-d680-5734-6947-e620dcb2ab25';
    $display->content['new-1fd9d07a-d680-5734-6947-e620dcb2ab25'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-1fd9d07a-d680-5734-6947-e620dcb2ab25';
    $pane = new stdClass();
    $pane->pid = 'new-b8cebf74-86dd-6cf4-e566-a9d24c6f21ea';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'project_development_urls';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b8cebf74-86dd-6cf4-e566-a9d24c6f21ea';
    $display->content['new-b8cebf74-86dd-6cf4-e566-a9d24c6f21ea'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-b8cebf74-86dd-6cf4-e566-a9d24c6f21ea';
    $pane = new stdClass();
    $pane->pid = 'new-9d18600e-1b72-e284-3964-02572dd7b308';
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
      'settings' => array(
        'pane_collapsed' => 0,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9d18600e-1b72-e284-3964-02572dd7b308';
    $display->content['new-9d18600e-1b72-e284-3964-02572dd7b308'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-9d18600e-1b72-e284-3964-02572dd7b308';
    $pane = new stdClass();
    $pane->pid = 'new-cc6880ef-9528-9bb4-f959-8cb36da07ba1';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'project_general_fields';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cc6880ef-9528-9bb4-f959-8cb36da07ba1';
    $display->content['new-cc6880ef-9528-9bb4-f959-8cb36da07ba1'] = $pane;
    $display->panels['sidebar_second_right'][1] = 'new-cc6880ef-9528-9bb4-f959-8cb36da07ba1';
    $pane = new stdClass();
    $pane->pid = 'new-88fcb37e-fbc4-a094-d9c9-d17922380573';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'time_information';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Time information',
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
    $pane->uuid = '88fcb37e-fbc4-a094-d9c9-d17922380573';
    $display->content['new-88fcb37e-fbc4-a094-d9c9-d17922380573'] = $pane;
    $display->panels['sidebar_second_right'][2] = 'new-88fcb37e-fbc4-a094-d9c9-d17922380573';
    $pane = new stdClass();
    $pane->pid = 'new-6dd8680c-4e1d-ef94-f150-7699b92f7df5';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_pricing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Pricing',
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
    $pane->uuid = '6dd8680c-4e1d-ef94-f150-7699b92f7df5';
    $display->content['new-6dd8680c-4e1d-ef94-f150-7699b92f7df5'] = $pane;
    $display->panels['sidebar_second_right'][3] = 'new-6dd8680c-4e1d-ef94-f150-7699b92f7df5';
    $pane = new stdClass();
    $pane->pid = 'new-fa9681e6-37f8-47b9-8f6a-df89b3b15895';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'budgets';
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
      'settings' => array(
        'pane_collapsed' => 1,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'fa9681e6-37f8-47b9-8f6a-df89b3b15895';
    $display->content['new-fa9681e6-37f8-47b9-8f6a-df89b3b15895'] = $pane;
    $display->panels['sidebar_second_right'][4] = 'new-fa9681e6-37f8-47b9-8f6a-df89b3b15895';
    $pane = new stdClass();
    $pane->pid = 'new-ae41615e-59fd-1a54-8103-f22606b76458';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_books_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => 0,
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'ae41615e-59fd-1a54-8103-f22606b76458';
    $display->content['new-ae41615e-59fd-1a54-8103-f22606b76458'] = $pane;
    $display->panels['sidebar_second_right'][5] = 'new-ae41615e-59fd-1a54-8103-f22606b76458';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_10';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 9;
  $handler->conf = array(
    'title' => 'Timetracking Node panel',
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
              'erpal_timetracking' => 'erpal_timetracking',
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
  $display->uuid = '186a9674-c809-a2e4-adac-a414ca184bc3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2667589c-a40c-7084-0d22-2f6aa84136e0';
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
    $pane->uuid = '2667589c-a40c-7084-0d22-2f6aa84136e0';
    $display->content['new-2667589c-a40c-7084-0d22-2f6aa84136e0'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-2667589c-a40c-7084-0d22-2f6aa84136e0';
    $pane = new stdClass();
    $pane->pid = 'new-9d84b37e-1b6c-4b24-4d41-a5c92e3ebe5b';
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
    $pane->uuid = '9d84b37e-1b6c-4b24-4d41-a5c92e3ebe5b';
    $display->content['new-9d84b37e-1b6c-4b24-4d41-a5c92e3ebe5b'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-9d84b37e-1b6c-4b24-4d41-a5c92e3ebe5b';
    $pane = new stdClass();
    $pane->pid = 'new-7e54b8f7-2048-d084-fd33-e95e34cdc685';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
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
    $pane->uuid = '7e54b8f7-2048-d084-fd33-e95e34cdc685';
    $display->content['new-7e54b8f7-2048-d084-fd33-e95e34cdc685'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-7e54b8f7-2048-d084-fd33-e95e34cdc685';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_10'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Task Node Panel',
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
              'erpal_task' => 'erpal_task',
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
    'top' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '028daa4d-7d86-dc54-a5e0-b69ca5173d68';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a34a4125-2209-6ad4-0943-f01f17bd44b4';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'task_basic_fields';
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
    $pane->uuid = 'a34a4125-2209-6ad4-0943-f01f17bd44b4';
    $display->content['new-a34a4125-2209-6ad4-0943-f01f17bd44b4'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-a34a4125-2209-6ad4-0943-f01f17bd44b4';
    $pane = new stdClass();
    $pane->pid = 'new-dd326a1a-26c3-35e4-452c-c880166d3ce2';
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
    $pane->uuid = 'dd326a1a-26c3-35e4-452c-c880166d3ce2';
    $display->content['new-dd326a1a-26c3-35e4-452c-c880166d3ce2'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-dd326a1a-26c3-35e4-452c-c880166d3ce2';
    $pane = new stdClass();
    $pane->pid = 'new-0d647340-fded-7cc4-8d7e-f9ba5882a340';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-task_content_tabs';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:erpal_task:field_is_ticket',
          'settings' => array(
            'field_is_ticket' => array(
              'und' => array(
                0 => array(
                  'value' => 0,
                ),
              ),
            ),
            'field_is_ticket_value' => NULL,
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
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
    $pane->uuid = '0d647340-fded-7cc4-8d7e-f9ba5882a340';
    $display->content['new-0d647340-fded-7cc4-8d7e-f9ba5882a340'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-0d647340-fded-7cc4-8d7e-f9ba5882a340';
    $pane = new stdClass();
    $pane->pid = 'new-b48a8500-ead8-bd64-0d42-8ebded4b77ac';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-ticket_content_tabs';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:erpal_task:field_is_ticket',
          'settings' => array(
            'field_is_ticket' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_is_ticket_value' => '1',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b48a8500-ead8-bd64-0d42-8ebded4b77ac';
    $display->content['new-b48a8500-ead8-bd64-0d42-8ebded4b77ac'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-b48a8500-ead8-bd64-0d42-8ebded4b77ac';
    $pane = new stdClass();
    $pane->pid = 'new-62e10818-488b-418d-b2b9-bc2346f4c755';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_timetracking_button';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'computed_field_unsanitized',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '62e10818-488b-418d-b2b9-bc2346f4c755';
    $display->content['new-62e10818-488b-418d-b2b9-bc2346f4c755'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-62e10818-488b-418d-b2b9-bc2346f4c755';
    $pane = new stdClass();
    $pane->pid = 'new-b5b50dd1-f38c-feb4-c5eb-09d1682d3b35';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'custom_node_content';
    $pane->subtype = 'custom_node_content';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Hide on quicktab active',
            'php' => 'if (function_exists(\'_erpal_projects_helper_hide_task_right_panes\')) {
  return !_erpal_projects_helper_hide_task_right_panes();
}
return TRUE;',
          ),
          'not' => FALSE,
        ),
      ),
    );
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
    $pane->uuid = 'b5b50dd1-f38c-feb4-c5eb-09d1682d3b35';
    $display->content['new-b5b50dd1-f38c-feb4-c5eb-09d1682d3b35'] = $pane;
    $display->panels['sidebar_second_right'][1] = 'new-b5b50dd1-f38c-feb4-c5eb-09d1682d3b35';
    $pane = new stdClass();
    $pane->pid = 'new-f6330958-c7c6-5bb4-c9aa-dfd94fa0e04e';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'task_right_sidebar_pane';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Hide on quicktab active',
            'php' => 'if (function_exists(\'_erpal_projects_helper_hide_task_right_panes\')) {
  return !_erpal_projects_helper_hide_task_right_panes();
}
return TRUE;',
          ),
          'not' => FALSE,
        ),
      ),
    );
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f6330958-c7c6-5bb4-c9aa-dfd94fa0e04e';
    $display->content['new-f6330958-c7c6-5bb4-c9aa-dfd94fa0e04e'] = $pane;
    $display->panels['sidebar_second_right'][2] = 'new-f6330958-c7c6-5bb4-c9aa-dfd94fa0e04e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_budget_view_page_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'budget_view_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Budget view panel',
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
  $display->title = '';
  $display->uuid = '96bc9bcd-4f23-5e84-f90a-ad4c75e9ffda';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-19bd85c8-8481-1dc4-4199-73da25200409';
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
      'override_title_text' => 'Budget (%budget:available-hours / %budget:total-hours)',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '19bd85c8-8481-1dc4-4199-73da25200409';
    $display->content['new-19bd85c8-8481-1dc4-4199-73da25200409'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-19bd85c8-8481-1dc4-4199-73da25200409';
    $pane = new stdClass();
    $pane->pid = 'new-201a3690-2389-20b4-c578-48b4573e1140';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'entity_view';
    $pane->subtype = 'budget';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'default',
      'context' => 'argument_entity_id:budget_1',
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
    $pane->uuid = '201a3690-2389-20b4-c578-48b4573e1140';
    $display->content['new-201a3690-2389-20b4-c578-48b4573e1140'] = $pane;
    $display->panels['sidebar_first_left'][1] = 'new-201a3690-2389-20b4-c578-48b4573e1140';
    $pane = new stdClass();
    $pane->pid = 'new-28559f84-564c-4ea4-092b-0345a00815c1';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'budget_node';
    $pane->subtype = 'budget_node';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '28559f84-564c-4ea4-092b-0345a00815c1';
    $display->content['new-28559f84-564c-4ea4-092b-0345a00815c1'] = $pane;
    $display->panels['sidebar_first_left'][2] = 'new-28559f84-564c-4ea4-092b-0345a00815c1';
    $pane = new stdClass();
    $pane->pid = 'new-6d93d0fb-d18f-6a34-3d3a-719dec597d40';
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
    $pane->uuid = '6d93d0fb-d18f-6a34-3d3a-719dec597d40';
    $display->content['new-6d93d0fb-d18f-6a34-3d3a-719dec597d40'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-6d93d0fb-d18f-6a34-3d3a-719dec597d40';
    $pane = new stdClass();
    $pane->pid = 'new-df7aa323-c3fd-b154-99a2-257a80824d28';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'timetrackings-panel_pane_3';
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
    $pane->uuid = 'df7aa323-c3fd-b154-99a2-257a80824d28';
    $display->content['new-df7aa323-c3fd-b154-99a2-257a80824d28'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-df7aa323-c3fd-b154-99a2-257a80824d28';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_budget_view_page_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_project_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'budgets';
  $page->task = 'page';
  $page->admin_title = 'Budgets';
  $page->admin_description = '';
  $page->path = 'projects/budgets';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access budgets view',
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
  $handler->name = 'page_budgets_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'budgets';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Budgets overview panel',
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
  $display->title = 'Budgets overview';
  $display->uuid = '09c3bb75-a773-3344-7dd0-2bbcb45db5d4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ccae406c-6315-5844-7d87-13cbb43c2422';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'budgets-panel_pane_1';
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
    $pane->uuid = 'ccae406c-6315-5844-7d87-13cbb43c2422';
    $display->content['new-ccae406c-6315-5844-7d87-13cbb43c2422'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-ccae406c-6315-5844-7d87-13cbb43c2422';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['budgets'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'global_fixed_price_items';
  $page->task = 'page';
  $page->admin_title = 'Global fixed price items';
  $page->admin_description = '';
  $page->path = 'projects/pricing/fixed';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access billables view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Fixed price items',
    'name' => 'navigation',
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
  $handler->name = 'page_global_fixed_price_items_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'global_fixed_price_items';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Global fixed price items panel',
    'no_blocks' => 1,
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
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Fixed price items';
  $display->uuid = '400a516c-a8a1-2544-7dd6-b1bd4e797944';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6ec68491-b4e5-bbf4-61b3-7a80cf5b289e';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'fixed_price_nodes-panel_pane_1';
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
    $pane->uuid = '6ec68491-b4e5-bbf4-61b3-7a80cf5b289e';
    $display->content['new-6ec68491-b4e5-bbf4-61b3-7a80cf5b289e'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-6ec68491-b4e5-bbf4-61b3-7a80cf5b289e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['global_fixed_price_items'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'page_budgets';
  $page->task = 'page';
  $page->admin_title = 'page-budgets';
  $page->admin_description = '';
  $page->path = 'node/%node/pricing';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'erpal_project' => 'erpal_project',
            'erpal_task' => 'erpal_task',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      1 => array(
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
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'field view pricing',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Pricing',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_page_budgets_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'page_budgets';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
              'erpal_project' => 'erpal_project',
              'erpal_task' => 'erpal_task',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6fdc10c1-728d-e044-75ca-bdd282bc9744';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-437b9618-6b55-4144-2dbf-c593e8f4482a';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_pricing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_table_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
        'edit' => 'Edit',
        'delete' => 'Delete',
        'add' => 'Add',
        'description' => 1,
        'empty' => 1,
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '437b9618-6b55-4144-2dbf-c593e8f4482a';
    $display->content['new-437b9618-6b55-4144-2dbf-c593e8f4482a'] = $pane;
    $display->panels['left'][0] = 'new-437b9618-6b55-4144-2dbf-c593e8f4482a';
    $pane = new stdClass();
    $pane->pid = 'new-c5443e89-1642-8b74-d5ae-4b8c33c8050f';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'fixed_price_nodes-panel_pane_2';
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
    $pane->uuid = 'c5443e89-1642-8b74-d5ae-4b8c33c8050f';
    $display->content['new-c5443e89-1642-8b74-d5ae-4b8c33c8050f'] = $pane;
    $display->panels['left'][1] = 'new-c5443e89-1642-8b74-d5ae-4b8c33c8050f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['page_budgets'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_calendar';
  $page->task = 'page';
  $page->admin_title = 'Project calendar';
  $page->admin_description = '';
  $page->path = 'node/%node/calendar';
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
  $handler->name = 'page_project_calendar_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'project_calendar';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project calendar panel',
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
              'erpal_project' => 'erpal_project',
              'erpal_task' => 'erpal_task',
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
  $display->title = 'Dates for %node:title';
  $display->uuid = 'a15f71d6-08ae-c8d4-1dc3-576215dcd918';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-86576a0f-4b66-7504-7d29-701bfe30fff7';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'full_calendar-panel_pane_2';
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
    $pane->uuid = '86576a0f-4b66-7504-7d29-701bfe30fff7';
    $display->content['new-86576a0f-4b66-7504-7d29-701bfe30fff7'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-86576a0f-4b66-7504-7d29-701bfe30fff7';
    $pane = new stdClass();
    $pane->pid = 'new-7b241707-275d-e614-99a9-fabebed41b56';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'fullcalendar_legend';
    $pane->subtype = 'fullcalendar_legend';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view' => 'full_calendar-panel_pane_2',
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
    $pane->uuid = '7b241707-275d-e614-99a9-fabebed41b56';
    $display->content['new-7b241707-275d-e614-99a9-fabebed41b56'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-7b241707-275d-e614-99a9-fabebed41b56';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_calendar'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_files';
  $page->task = 'page';
  $page->admin_title = 'Project files';
  $page->admin_description = '';
  $page->path = 'node/%node/files';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access documents view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
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
    ),
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
  $handler->name = 'page_project_files_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'project_files';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project documents panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
              'erpal_task' => 'erpal_task',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
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
  $display->title = 'Files at %node:title';
  $display->uuid = 'a45f9c52-05ba-d9f4-d510-4021fcd40624';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ad283597-b262-5524-ddd2-e469d778953a';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'documents-panel_pane_3';
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
    $pane->uuid = 'ad283597-b262-5524-ddd2-e469d778953a';
    $display->content['new-ad283597-b262-5524-ddd2-e469d778953a'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-ad283597-b262-5524-ddd2-e469d778953a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_project_files_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'project_files';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Document files',
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
              'erpal_book' => 'erpal_book',
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
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Files at %node:title';
  $display->uuid = 'a84a75d1-363a-3b14-0589-f4874f8a030a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2f087d22-f633-f854-c909-fc8854110edd';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'documents-panel_pane_4';
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
    $pane->uuid = '2f087d22-f633-f854-c909-fc8854110edd';
    $display->content['new-2f087d22-f633-f854-c909-fc8854110edd'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-2f087d22-f633-f854-c909-fc8854110edd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_files'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_tasks';
  $page->task = 'page';
  $page->admin_title = 'Tasks';
  $page->admin_description = '';
  $page->path = 'node/%node/tasks';
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
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'erpal_project' => 'erpal_project',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      3 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Access global or on project team',
          'php' => 'return _erpal_projects_helper_user_can_access_page(\'tasks\', $contexts);',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Tasks',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_project_tasks_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'project_tasks';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel Tasks by Project',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
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
  $display->title = 'Tasks of %node:title';
  $display->uuid = '69d9cd0b-3c1c-b5c4-e56e-5817ae18b5c5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1cce55bc-a2e6-a5b4-b96c-af98eaafc02a';
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
    $pane->uuid = '1cce55bc-a2e6-a5b4-b96c-af98eaafc02a';
    $display->content['new-1cce55bc-a2e6-a5b4-b96c-af98eaafc02a'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-1cce55bc-a2e6-a5b4-b96c-af98eaafc02a';
    $pane = new stdClass();
    $pane->pid = 'new-5b13c31d-2206-2e64-1155-cf691f093d9e';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-tasks_by_project_tabs';
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
    $pane->uuid = '5b13c31d-2206-2e64-1155-cf691f093d9e';
    $display->content['new-5b13c31d-2206-2e64-1155-cf691f093d9e'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-5b13c31d-2206-2e64-1155-cf691f093d9e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_tasks'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_timetrackings';
  $page->task = 'page';
  $page->admin_title = 'Timetracking';
  $page->admin_description = '';
  $page->path = 'node/%node/timetracking';
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
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'erpal_project' => 'erpal_project',
            'erpal_task' => 'erpal_task',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access timetrackings view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Timetrackings',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_project_timetrackings_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'project_timetrackings';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel timetracking by project',
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
              'erpal_project' => 'erpal_project',
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
      'center' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4f78247f-b58c-2144-9110-4cb73f5bc488';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ba99d6fb-459f-c564-2915-76fdfc7b6376';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h2',
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
    $pane->uuid = 'ba99d6fb-459f-c564-2915-76fdfc7b6376';
    $display->content['new-ba99d6fb-459f-c564-2915-76fdfc7b6376'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-ba99d6fb-459f-c564-2915-76fdfc7b6376';
    $pane = new stdClass();
    $pane->pid = 'new-0a718946-e6d0-78c4-21cb-15b0d7178f41';
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
    $pane->uuid = '0a718946-e6d0-78c4-21cb-15b0d7178f41';
    $display->content['new-0a718946-e6d0-78c4-21cb-15b0d7178f41'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-0a718946-e6d0-78c4-21cb-15b0d7178f41';
    $pane = new stdClass();
    $pane->pid = 'new-da2c2563-0d17-44b4-91f7-eb724e321212';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'timetrackings-panel_pane_2';
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
    $pane->uuid = 'da2c2563-0d17-44b4-91f7-eb724e321212';
    $display->content['new-da2c2563-0d17-44b4-91f7-eb724e321212'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-da2c2563-0d17-44b4-91f7-eb724e321212';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_project_timetrackings_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'project_timetrackings';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Panel timetracking by task',
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
              'erpal_task' => 'erpal_task',
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
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Timetrackings of %node:title';
  $display->uuid = '30edd8a8-bad0-c5d4-092d-c24bf0e0c48c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-29a85738-e039-fe34-ed56-9e7fed49648c';
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
    $pane->uuid = '29a85738-e039-fe34-ed56-9e7fed49648c';
    $display->content['new-29a85738-e039-fe34-ed56-9e7fed49648c'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-29a85738-e039-fe34-ed56-9e7fed49648c';
    $pane = new stdClass();
    $pane->pid = 'new-9dd6ab56-34e5-cca4-c97d-00cbf798cced';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'timetrackings-panel_pane_1';
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
    $pane->uuid = '9dd6ab56-34e5-cca4-c97d-00cbf798cced';
    $display->content['new-9dd6ab56-34e5-cca4-c97d-00cbf798cced'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-9dd6ab56-34e5-cca4-c97d-00cbf798cced';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_timetrackings'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects_list';
  $page->task = 'page';
  $page->admin_title = 'Projects list';
  $page->admin_description = '';
  $page->path = 'projects/projects';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access projects view',
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
  $handler->name = 'page_projects_list_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'projects_list';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->title = 'Projects';
  $display->uuid = '15620836-412b-2454-fd69-5fd0addc6795';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fcc38a15-ecda-2194-d5b3-d4cd7d7be920';
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
    $pane->uuid = 'fcc38a15-ecda-2194-d5b3-d4cd7d7be920';
    $display->content['new-fcc38a15-ecda-2194-d5b3-d4cd7d7be920'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-fcc38a15-ecda-2194-d5b3-d4cd7d7be920';
    $pane = new stdClass();
    $pane->pid = 'new-53a501f6-15f9-4684-2dfd-c05fa1f5a8dc';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-project_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '53a501f6-15f9-4684-2dfd-c05fa1f5a8dc';
    $display->content['new-53a501f6-15f9-4684-2dfd-c05fa1f5a8dc'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-53a501f6-15f9-4684-2dfd-c05fa1f5a8dc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects_list'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'tickets';
  $page->task = 'page';
  $page->admin_title = 'Tickets';
  $page->admin_description = '';
  $page->path = 'node/%node/tickets';
  $page->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'erpal_project' => 'erpal_project',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      2 => array(
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
      3 => array(
        'name' => 'php',
        'settings' => array(
          'description' => 'Access global or on project team',
          'php' => 'return _erpal_projects_helper_user_can_access_page(\'tickets\', $contexts);',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Tickets',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_tickets_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'tickets';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Tickets of %node:title',
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
              'erpal_project' => 'erpal_project',
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
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Tickets of %node:title';
  $display->uuid = '648a14f5-d847-36a4-c983-421b32cf7424';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-35ecd643-b1f7-b1a4-f12d-cb23c5ee9c9b';
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
    $pane->uuid = '35ecd643-b1f7-b1a4-f12d-cb23c5ee9c9b';
    $display->content['new-35ecd643-b1f7-b1a4-f12d-cb23c5ee9c9b'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-35ecd643-b1f7-b1a4-f12d-cb23c5ee9c9b';
    $pane = new stdClass();
    $pane->pid = 'new-c61f422c-9b54-1364-55df-6cdced089a88';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-tickets_by_project_tabs';
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
    $pane->uuid = 'c61f422c-9b54-1364-55df-6cdced089a88';
    $display->content['new-c61f422c-9b54-1364-55df-6cdced089a88'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-c61f422c-9b54-1364-55df-6cdced089a88';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tickets'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_projects';
  $page->task = 'page';
  $page->admin_title = 'User projects';
  $page->admin_description = '';
  $page->path = 'user/projects';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access projects view',
        ),
        'context' => 'argument_entity_id:user_1',
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
  $handler->name = 'page_user_projects_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_projects';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Projects by user panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
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
  $display->title = '%user:name\'s projects';
  $display->uuid = '5981e90f-39ad-41b4-f191-5e4100a0dab8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3130506e-de93-46e6-93d9-1f4ff0ec5138';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-user_projects_tabs';
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
    $pane->uuid = '3130506e-de93-46e6-93d9-1f4ff0ec5138';
    $display->content['new-3130506e-de93-46e6-93d9-1f4ff0ec5138'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-3130506e-de93-46e6-93d9-1f4ff0ec5138';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_projects'] = $page;

  return $pages;

}
