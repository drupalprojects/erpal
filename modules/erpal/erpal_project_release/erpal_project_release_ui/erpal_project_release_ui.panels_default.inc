<?php
/**
 * @file
 * erpal_project_release_ui.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_project_release_ui_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'release_header_fields';
  $mini->category = 'ERPAL project release';
  $mini->admin_title = 'Release header fields';
  $mini->admin_description = '';
  $mini->requiredcontexts = array(
    0 => array(
      'identifier' => 'Node',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '',
      'id' => 1,
    ),
  );
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4c4a7203-b317-0514-d163-abc503e87422';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7d2ebb1c-cbd7-5f94-e547-855a43b3b13d';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_asset_file';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_typed_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '7d2ebb1c-cbd7-5f94-e547-855a43b3b13d';
    $display->content['new-7d2ebb1c-cbd7-5f94-e547-855a43b3b13d'] = $pane;
    $display->panels['middle'][0] = 'new-7d2ebb1c-cbd7-5f94-e547-855a43b3b13d';
    $pane = new stdClass();
    $pane->pid = 'new-ec569d4a-3a01-5b84-a960-416851c8cdf0';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_release_tag';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = 'ec569d4a-3a01-5b84-a960-416851c8cdf0';
    $display->content['new-ec569d4a-3a01-5b84-a960-416851c8cdf0'] = $pane;
    $display->panels['middle'][1] = 'new-ec569d4a-3a01-5b84-a960-416851c8cdf0';
    $pane = new stdClass();
    $pane->pid = 'new-4b902263-f0bc-39e4-b19d-853b6a60d6b4';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_typed_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '4b902263-f0bc-39e4-b19d-853b6a60d6b4';
    $display->content['new-4b902263-f0bc-39e4-b19d-853b6a60d6b4'] = $pane;
    $display->panels['middle'][2] = 'new-4b902263-f0bc-39e4-b19d-853b6a60d6b4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['release_header_fields'] = $mini;

  return $export;
}
