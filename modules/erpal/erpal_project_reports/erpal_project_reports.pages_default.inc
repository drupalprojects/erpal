<?php
/**
 * @file
 * erpal_project_reports.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_project_reports_default_page_manager_handlers() {
  $export = array();

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
  $export['page_reports_panel_context_2'] = $handler;

  return $export;
}
