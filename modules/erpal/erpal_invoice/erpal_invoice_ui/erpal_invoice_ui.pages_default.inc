<?php
/**
 * @file
 * erpal_invoice_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_invoice_ui_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Invoice Node Panel',
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
              'erpal_invoice' => 'erpal_invoice',
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
  $display->uuid = '033abcd5-9a60-1434-8176-26a2e28dabc0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cb3eb2e0-8a59-1034-fd78-53fede4cdf35';
    $pane->panel = 'sidebar_first_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'invoice_header_fields';
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
    $pane->uuid = 'cb3eb2e0-8a59-1034-fd78-53fede4cdf35';
    $display->content['new-cb3eb2e0-8a59-1034-fd78-53fede4cdf35'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-cb3eb2e0-8a59-1034-fd78-53fede4cdf35';
    $pane = new stdClass();
    $pane->pid = 'new-365a11ed-fac0-a024-d14c-e8b1021c8dc6';
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
    $pane->uuid = '365a11ed-fac0-a024-d14c-e8b1021c8dc6';
    $display->content['new-365a11ed-fac0-a024-d14c-e8b1021c8dc6'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-365a11ed-fac0-a024-d14c-e8b1021c8dc6';
    $pane = new stdClass();
    $pane->pid = 'new-8208b00b-cd1b-5854-4997-9c74f595abd0';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'panels_mini';
    $pane->subtype = 'invoice_content_panel';
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
    $pane->uuid = '8208b00b-cd1b-5854-4997-9c74f595abd0';
    $display->content['new-8208b00b-cd1b-5854-4997-9c74f595abd0'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-8208b00b-cd1b-5854-4997-9c74f595abd0';
    $pane = new stdClass();
    $pane->pid = 'new-1ed06f35-e123-1654-1d14-fced63ecc669';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_auto_note';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1ed06f35-e123-1654-1d14-fced63ecc669';
    $display->content['new-1ed06f35-e123-1654-1d14-fced63ecc669'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-1ed06f35-e123-1654-1d14-fced63ecc669';
    $pane = new stdClass();
    $pane->pid = 'new-0704d496-314b-9544-fd7d-89e553a9d11b';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_note';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'note_invoice_token_replace',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0704d496-314b-9544-fd7d-89e553a9d11b';
    $display->content['new-0704d496-314b-9544-fd7d-89e553a9d11b'] = $pane;
    $display->panels['sidebar_second_left'][2] = 'new-0704d496-314b-9544-fd7d-89e553a9d11b';
    $pane = new stdClass();
    $pane->pid = 'new-66a69882-8200-49ad-85f6-770e308c91b9';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '66a69882-8200-49ad-85f6-770e308c91b9';
    $display->content['new-66a69882-8200-49ad-85f6-770e308c91b9'] = $pane;
    $display->panels['sidebar_second_left'][3] = 'new-66a69882-8200-49ad-85f6-770e308c91b9';
    $pane = new stdClass();
    $pane->pid = 'new-b74555d0-9bae-404b-b412-eb7c02fa4caf';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'b74555d0-9bae-404b-b412-eb7c02fa4caf';
    $display->content['new-b74555d0-9bae-404b-b412-eb7c02fa4caf'] = $pane;
    $display->panels['sidebar_second_left'][4] = 'new-b74555d0-9bae-404b-b412-eb7c02fa4caf';
    $pane = new stdClass();
    $pane->pid = 'new-0efc5ea4-52e2-1654-d547-1166a50de41c';
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
    $pane->uuid = '0efc5ea4-52e2-1654-d547-1166a50de41c';
    $display->content['new-0efc5ea4-52e2-1654-d547-1166a50de41c'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-0efc5ea4-52e2-1654-d547-1166a50de41c';
    $pane = new stdClass();
    $pane->pid = 'new-c218a658-1052-33f4-c9b0-8f7f1ccc4b17';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'invoice_general_fields';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'General fields',
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
    $pane->uuid = 'c218a658-1052-33f4-c9b0-8f7f1ccc4b17';
    $display->content['new-c218a658-1052-33f4-c9b0-8f7f1ccc4b17'] = $pane;
    $display->panels['sidebar_second_right'][1] = 'new-c218a658-1052-33f4-c9b0-8f7f1ccc4b17';
    $pane = new stdClass();
    $pane->pid = 'new-20b0b122-26c6-0514-b1c7-d87aa79e1977';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'panels_mini';
    $pane->subtype = 'invoice_detailed_fields';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Detailed fields',
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
    $pane->uuid = '20b0b122-26c6-0514-b1c7-d87aa79e1977';
    $display->content['new-20b0b122-26c6-0514-b1c7-d87aa79e1977'] = $pane;
    $display->panels['sidebar_second_right'][2] = 'new-20b0b122-26c6-0514-b1c7-d87aa79e1977';
    $pane = new stdClass();
    $pane->pid = 'new-d41f5dcf-9bd3-1f14-251e-b33264c53ba8';
    $pane->panel = 'sidebar_second_right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_asset_files';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_file_node',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Invoice PDF',
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
    $pane->uuid = 'd41f5dcf-9bd3-1f14-251e-b33264c53ba8';
    $display->content['new-d41f5dcf-9bd3-1f14-251e-b33264c53ba8'] = $pane;
    $display->panels['sidebar_second_right'][3] = 'new-d41f5dcf-9bd3-1f14-251e-b33264c53ba8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_billable_view_page_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'billable_view_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Billable view pane',
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
  $display->title = '%billable:title';
  $display->uuid = '3801b5e3-6d02-cd94-91a6-796b86b12491';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-abc65c74-08f1-2734-7d13-a2fa7e4bd1c3';
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
    $pane->uuid = 'abc65c74-08f1-2734-7d13-a2fa7e4bd1c3';
    $display->content['new-abc65c74-08f1-2734-7d13-a2fa7e4bd1c3'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-abc65c74-08f1-2734-7d13-a2fa7e4bd1c3';
    $pane = new stdClass();
    $pane->pid = 'new-8cc38d79-1b85-be44-6559-a3348bfcbb7b';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'entity_view';
    $pane->subtype = 'billable';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'default',
      'context' => 'argument_entity_id:billable_1',
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
    $pane->uuid = '8cc38d79-1b85-be44-6559-a3348bfcbb7b';
    $display->content['new-8cc38d79-1b85-be44-6559-a3348bfcbb7b'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-8cc38d79-1b85-be44-6559-a3348bfcbb7b';
    $pane = new stdClass();
    $pane->pid = 'new-013dbf84-a8e5-4c39-9c78-cbf68e468821';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'invoices-panel_pane_6';
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
    $pane->uuid = '013dbf84-a8e5-4c39-9c78-cbf68e468821';
    $display->content['new-013dbf84-a8e5-4c39-9c78-cbf68e468821'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-013dbf84-a8e5-4c39-9c78-cbf68e468821';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_billable_view_page_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_payment_view_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'payment_view';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Payment view pane',
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
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'argument_entity_id:payment_1',
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
  $display->title = '%payment:label';
  $display->uuid = '431dd8a1-aaca-4433-9361-3f93a78e3cce';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-702a15b3-a6aa-4606-9d4f-7a561dd07488';
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
    $pane->uuid = '702a15b3-a6aa-4606-9d4f-7a561dd07488';
    $display->content['new-702a15b3-a6aa-4606-9d4f-7a561dd07488'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-702a15b3-a6aa-4606-9d4f-7a561dd07488';
    $pane = new stdClass();
    $pane->pid = 'new-b24e9656-bb03-4c6a-87d2-c718781703c5';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'pm_existing_pages';
    $pane->subtype = 'pm_existing_pages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      0 => 'task_id',
      'task_id' => 'payment_view',
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
    $pane->uuid = 'b24e9656-bb03-4c6a-87d2-c718781703c5';
    $display->content['new-b24e9656-bb03-4c6a-87d2-c718781703c5'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-b24e9656-bb03-4c6a-87d2-c718781703c5';
    $pane = new stdClass();
    $pane->pid = 'new-c003bf16-7084-4872-8c09-633bc8e618a5';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'invoices-panel_pane_1';
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
    $pane->uuid = 'c003bf16-7084-4872-8c09-633bc8e618a5';
    $display->content['new-c003bf16-7084-4872-8c09-633bc8e618a5'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-c003bf16-7084-4872-8c09-633bc8e618a5';
    $pane = new stdClass();
    $pane->pid = 'new-835a01a9-78e4-4bb4-8afb-cd02c90f204a';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'billables-panel_pane_5';
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
    $pane->uuid = '835a01a9-78e4-4bb4-8afb-cd02c90f204a';
    $display->content['new-835a01a9-78e4-4bb4-8afb-cd02c90f204a'] = $pane;
    $display->panels['sidebar_second_left'][2] = 'new-835a01a9-78e4-4bb4-8afb-cd02c90f204a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-702a15b3-a6aa-4606-9d4f-7a561dd07488';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_payment_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_invoice_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'billables';
  $page->task = 'page';
  $page->admin_title = 'Billables';
  $page->admin_description = '';
  $page->path = 'invoice/billables';
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
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_billables_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'billables';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->title = 'Billables';
  $display->uuid = 'd9453215-74fa-13f4-2531-ce2189549244';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-64107e4a-645a-a2f4-f9b8-d6e68a6fb7dd';
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
    $pane->uuid = '64107e4a-645a-a2f4-f9b8-d6e68a6fb7dd';
    $display->content['new-64107e4a-645a-a2f4-f9b8-d6e68a6fb7dd'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-64107e4a-645a-a2f4-f9b8-d6e68a6fb7dd';
    $pane = new stdClass();
    $pane->pid = 'new-7c2ccd2d-8feb-c934-61b4-e56b02b28d28';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'block';
    $pane->subtype = 'erpal_invoice_helper-invoices_date_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7c2ccd2d-8feb-c934-61b4-e56b02b28d28';
    $display->content['new-7c2ccd2d-8feb-c934-61b4-e56b02b28d28'] = $pane;
    $display->panels['sidebar_first_right'][1] = 'new-7c2ccd2d-8feb-c934-61b4-e56b02b28d28';
    $pane = new stdClass();
    $pane->pid = 'new-8c0ec25b-5350-a474-1924-181826b69328';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-billables_tabs';
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
    $pane->uuid = '8c0ec25b-5350-a474-1924-181826b69328';
    $display->content['new-8c0ec25b-5350-a474-1924-181826b69328'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-8c0ec25b-5350-a474-1924-181826b69328';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['billables'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'billables_pane';
  $page->task = 'page';
  $page->admin_title = 'Billables pane';
  $page->admin_description = '';
  $page->path = 'node/%node/billables';
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
    'title' => 'Billables',
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
  $handler->name = 'page_billables_pane_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'billables_pane';
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
  $display->uuid = '1da80d04-9f8b-a474-79e4-9719c939fa83';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f1ea840a-d09a-e4b4-ed80-0a5706722b9a';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'billables-panel_pane_2';
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
    $pane->uuid = 'f1ea840a-d09a-e4b4-ed80-0a5706722b9a';
    $display->content['new-f1ea840a-d09a-e4b4-ed80-0a5706722b9a'] = $pane;
    $display->panels['left'][0] = 'new-f1ea840a-d09a-e4b4-ed80-0a5706722b9a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['billables_pane'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'invoices_';
  $page->task = 'page';
  $page->admin_title = 'Invoices ';
  $page->admin_description = '';
  $page->path = 'invoice/invoices';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access invoices view',
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
  $handler->name = 'page_invoices__panel_context';
  $handler->task = 'page';
  $handler->subtask = 'invoices_';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->title = 'Invoices';
  $display->uuid = 'a48ba85c-0dd4-7524-1585-e30b24d61bcf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9b28d1f2-4d21-34a4-69a2-c747410ffcd0';
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
    $pane->uuid = '9b28d1f2-4d21-34a4-69a2-c747410ffcd0';
    $display->content['new-9b28d1f2-4d21-34a4-69a2-c747410ffcd0'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-9b28d1f2-4d21-34a4-69a2-c747410ffcd0';
    $pane = new stdClass();
    $pane->pid = 'new-bee38037-42a8-bce4-c106-0f91a44c206f';
    $pane->panel = 'sidebar_first_right';
    $pane->type = 'block';
    $pane->subtype = 'erpal_invoice_helper-invoices_date_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Invoice dates',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bee38037-42a8-bce4-c106-0f91a44c206f';
    $display->content['new-bee38037-42a8-bce4-c106-0f91a44c206f'] = $pane;
    $display->panels['sidebar_first_right'][1] = 'new-bee38037-42a8-bce4-c106-0f91a44c206f';
    $pane = new stdClass();
    $pane->pid = 'new-e8fc667a-ad89-e5f4-3dc3-7dd28ddf8c69';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-invoice_tabs';
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
    $pane->uuid = 'e8fc667a-ad89-e5f4-3dc3-7dd28ddf8c69';
    $display->content['new-e8fc667a-ad89-e5f4-3dc3-7dd28ddf8c69'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-e8fc667a-ad89-e5f4-3dc3-7dd28ddf8c69';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['invoices_'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'payments';
  $page->task = 'page';
  $page->admin_title = 'payments';
  $page->admin_description = '';
  $page->path = 'invoice/payments';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer payment entities',
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
  $handler->name = 'page_payments_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'payments';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
  );
  $display = new panels_display();
  $display->layout = 'one';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b8021f70-780b-f6a4-adf4-7c0d75966e8b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-57b56f73-3773-53f4-b564-ab7b1bafad65';
    $pane->panel = 'one_main';
    $pane->type = 'page_actions';
    $pane->subtype = 'page_actions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'erpal-content-right',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '57b56f73-3773-53f4-b564-ab7b1bafad65';
    $display->content['new-57b56f73-3773-53f4-b564-ab7b1bafad65'] = $pane;
    $display->panels['one_main'][0] = 'new-57b56f73-3773-53f4-b564-ab7b1bafad65';
    $pane = new stdClass();
    $pane->pid = 'new-01122779-7f50-7c34-e127-e7450662c64c';
    $pane->panel = 'one_main';
    $pane->type = 'payment_add_to_invoice';
    $pane->subtype = 'payment_add_to_invoice';
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
    $pane->uuid = '01122779-7f50-7c34-e127-e7450662c64c';
    $display->content['new-01122779-7f50-7c34-e127-e7450662c64c'] = $pane;
    $display->panels['one_main'][1] = 'new-01122779-7f50-7c34-e127-e7450662c64c';
    $pane = new stdClass();
    $pane->pid = 'new-bc488af9-fd7d-2104-a97d-51796b93ab25';
    $pane->panel = 'one_main';
    $pane->type = 'views_panes';
    $pane->subtype = 'payment-panel_pane_2';
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
    $pane->uuid = 'bc488af9-fd7d-2104-a97d-51796b93ab25';
    $display->content['new-bc488af9-fd7d-2104-a97d-51796b93ab25'] = $pane;
    $display->panels['one_main'][2] = 'new-bc488af9-fd7d-2104-a97d-51796b93ab25';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['payments'] = $page;

  return $pages;

}
