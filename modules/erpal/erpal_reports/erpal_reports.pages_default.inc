<?php
/**
 * @file
 * erpal_reports.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_reports_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_report_view_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'report_view';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Sales report details',
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
  $display->title = 'Report details';
  $display->uuid = '006bc07e-30a5-4bde-8647-6b22c3922052';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-df2cfbfb-c442-4eec-9af7-0ba8bfcf904c';
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
    $pane->uuid = 'df2cfbfb-c442-4eec-9af7-0ba8bfcf904c';
    $display->content['new-df2cfbfb-c442-4eec-9af7-0ba8bfcf904c'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-df2cfbfb-c442-4eec-9af7-0ba8bfcf904c';
    $pane = new stdClass();
    $pane->pid = 'new-a0a21068-c4bd-4f1a-853d-cff3423aed6c';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'entity_view';
    $pane->subtype = 'erpal_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:erpal_reports_1',
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
    $pane->uuid = 'a0a21068-c4bd-4f1a-853d-cff3423aed6c';
    $display->content['new-a0a21068-c4bd-4f1a-853d-cff3423aed6c'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-a0a21068-c4bd-4f1a-853d-cff3423aed6c';
    $pane = new stdClass();
    $pane->pid = 'new-5c825337-b652-45a7-95f5-cdc8ca748de7';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'report_details_view';
    $pane->subtype = 'report_details_view';
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
    $pane->uuid = '5c825337-b652-45a7-95f5-cdc8ca748de7';
    $display->content['new-5c825337-b652-45a7-95f5-cdc8ca748de7'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-5c825337-b652-45a7-95f5-cdc8ca748de7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_report_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_reports_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'reports';
  $page->task = 'page';
  $page->admin_title = 'Reports';
  $page->admin_description = '';
  $page->path = 'reports/%type';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'use erpal_reports',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
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
  $handler->name = 'page_reports_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'reports';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Project Reports',
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
            'value' => 'project',
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
    ),
  );
  $display->cache = array();
  $display->title = 'Project Reports';
  $display->uuid = '41987fe2-3b60-ecd4-fd04-52a676ba4a0e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2df00bd0-a967-5a14-a5d5-09cdf9208046';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-project_report_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '2df00bd0-a967-5a14-a5d5-09cdf9208046';
    $display->content['new-2df00bd0-a967-5a14-a5d5-09cdf9208046'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-2df00bd0-a967-5a14-a5d5-09cdf9208046';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_reports_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'reports';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Reporting dashboard',
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
            'value' => 'dashboard',
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
      'left' => NULL,
      'right' => NULL,
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'abcdff0e-4cce-c0b4-b5cd-24aa5c30bbdb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1a8f6caf-c9b4-dd64-4d11-e210015688d0';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>From this page you can access all available reports. You can add new reports in every project and CRM report by clicking the "dashboard" checkbox in the report configuration form.</p>
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1a8f6caf-c9b4-dd64-4d11-e210015688d0';
    $display->content['new-1a8f6caf-c9b4-dd64-4d11-e210015688d0'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-1a8f6caf-c9b4-dd64-4d11-e210015688d0';
    $pane = new stdClass();
    $pane->pid = 'new-beaae103-5aa5-44c8-82d5-a6f6bebfeca2';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-report_dashboard';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'beaae103-5aa5-44c8-82d5-a6f6bebfeca2';
    $display->content['new-beaae103-5aa5-44c8-82d5-a6f6bebfeca2'] = $pane;
    $display->panels['sidebar_first_left'][1] = 'new-beaae103-5aa5-44c8-82d5-a6f6bebfeca2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_reports_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'reports';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'CRM Reports',
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
        1 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'crm',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
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
  $display->title = 'CRM Reports';
  $display->uuid = 'a49f290f-4ec0-8424-5d0f-4915236294fc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fa48df8b-e9dd-49b7-bef7-3bd2ec90110b';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'page_actions';
    $pane->subtype = 'page_actions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = '';
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fa48df8b-e9dd-49b7-bef7-3bd2ec90110b';
    $display->content['new-fa48df8b-e9dd-49b7-bef7-3bd2ec90110b'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-fa48df8b-e9dd-49b7-bef7-3bd2ec90110b';
    $pane = new stdClass();
    $pane->pid = 'new-5f371012-2225-daa4-7926-06738368d2fe';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-crm_report_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = '';
    $pane->cache = array();
    $pane->style = '';
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5f371012-2225-daa4-7926-06738368d2fe';
    $display->content['new-5f371012-2225-daa4-7926-06738368d2fe'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-5f371012-2225-daa4-7926-06738368d2fe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['reports'] = $page;

  return $pages;

}
