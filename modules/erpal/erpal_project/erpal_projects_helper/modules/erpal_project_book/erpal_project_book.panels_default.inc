<?php
/**
 * @file
 * erpal_project_book.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_project_book_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'task_concept_panel';
  $mini->category = 'ERPAL projects';
  $mini->admin_title = 'Task concept panel';
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
  $mini->relationships = array(
    0 => array(
      'identifier' => 'First book page parent',
      'keyword' => '',
      'name' => 'parent_book_page',
      'delta' => 0,
      'context' => 'requiredcontext_entity:node_1',
      'id' => 1,
    ),
  );
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
  $display->uuid = '82239991-2648-3fc4-81ad-419206673475';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0f2f554d-28de-8584-5d4a-92cd6c52ce55';
    $pane->panel = 'middle';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_book_page' => 'erpal_book_page',
            ),
          ),
          'context' => 'relationship_parent_book_page_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'none',
      'id' => '',
      'class' => '',
      'context' => 'relationship_parent_book_page_1',
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
    $pane->uuid = '0f2f554d-28de-8584-5d4a-92cd6c52ce55';
    $display->content['new-0f2f554d-28de-8584-5d4a-92cd6c52ce55'] = $pane;
    $display->panels['middle'][0] = 'new-0f2f554d-28de-8584-5d4a-92cd6c52ce55';
    $pane = new stdClass();
    $pane->pid = 'new-1fd67a7c-e41b-2354-7d92-ed15651118ac';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_parent_book_page_1',
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
    $pane->uuid = '1fd67a7c-e41b-2354-7d92-ed15651118ac';
    $display->content['new-1fd67a7c-e41b-2354-7d92-ed15651118ac'] = $pane;
    $display->panels['middle'][1] = 'new-1fd67a7c-e41b-2354-7d92-ed15651118ac';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['task_concept_panel'] = $mini;

  return $export;
}
