<?php
/**
 * @file
 * erpal_crm_reports.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_crm_reports_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_13';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 14;
  $handler->conf = array(
    'title' => 'Forecast Node Panel',
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
              'erpal_customer_forecast' => 'erpal_customer_forecast',
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
    $pane->pid = 'new-73c4bd09-083f-a6d4-9919-b65ae4a17235';
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
    $pane->uuid = '73c4bd09-083f-a6d4-9919-b65ae4a17235';
    $display->content['new-73c4bd09-083f-a6d4-9919-b65ae4a17235'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-73c4bd09-083f-a6d4-9919-b65ae4a17235';
    $pane = new stdClass();
    $pane->pid = 'new-933cee41-7b18-4ad9-9b81-395ef241acd4';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'node_forecast_details_view';
    $pane->subtype = 'node_forecast_details_view';
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
    $pane->uuid = '933cee41-7b18-4ad9-9b81-395ef241acd4';
    $display->content['new-933cee41-7b18-4ad9-9b81-395ef241acd4'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-933cee41-7b18-4ad9-9b81-395ef241acd4';
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
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_13'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_15';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 15;
  $handler->conf = array(
    'title' => 'Expense Plan Node Panel',
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
              'erpal_expense_forecast' => 'erpal_expense_forecast',
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
  $display->uuid = '81748854-82aa-4954-9dfa-fcd5886aed67';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e8a07e2a-699c-439f-81a1-c1b9ebdc4f5a';
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
    $pane->uuid = 'e8a07e2a-699c-439f-81a1-c1b9ebdc4f5a';
    $display->content['new-e8a07e2a-699c-439f-81a1-c1b9ebdc4f5a'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-e8a07e2a-699c-439f-81a1-c1b9ebdc4f5a';
    $pane = new stdClass();
    $pane->pid = 'new-fa0ed333-463f-450f-9dc7-79c9d5ea4549';
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
    $pane->uuid = 'fa0ed333-463f-450f-9dc7-79c9d5ea4549';
    $display->content['new-fa0ed333-463f-450f-9dc7-79c9d5ea4549'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-fa0ed333-463f-450f-9dc7-79c9d5ea4549';
    $pane = new stdClass();
    $pane->pid = 'new-9ca97cad-ffb9-4d66-9718-aed3331b4d19';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'node_forecast_details_view';
    $pane->subtype = 'node_forecast_details_view';
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
    $pane->uuid = '9ca97cad-ffb9-4d66-9718-aed3331b4d19';
    $display->content['new-9ca97cad-ffb9-4d66-9718-aed3331b4d19'] = $pane;
    $display->panels['sidebar_second_left'][1] = 'new-9ca97cad-ffb9-4d66-9718-aed3331b4d19';
    $pane = new stdClass();
    $pane->pid = 'new-27199801-caa3-436b-ae01-369dd0509f05';
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
    $pane->uuid = '27199801-caa3-436b-ae01-369dd0509f05';
    $display->content['new-27199801-caa3-436b-ae01-369dd0509f05'] = $pane;
    $display->panels['sidebar_second_right'][0] = 'new-27199801-caa3-436b-ae01-369dd0509f05';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e8a07e2a-699c-439f-81a1-c1b9ebdc4f5a';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_15'] = $handler;

  return $export;
}
