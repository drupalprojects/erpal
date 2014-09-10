<?php
/**
 * @file
 * erpal_bookmark_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_bookmark_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'bookmarks';
  $page->task = 'page';
  $page->admin_title = 'Bookmarks';
  $page->admin_description = '';
  $page->path = 'user/bookmarks';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access bookmarks view',
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
  $handler->name = 'page_bookmarks_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'bookmarks';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Bookmarks panel',
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
  $display->uuid = '8ebe1150-4a64-4c82-9d2f-f7ad541092c9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-27265f65-4489-4cab-8150-460614458541';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-bookmarks';
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
    $pane->uuid = '27265f65-4489-4cab-8150-460614458541';
    $display->content['new-27265f65-4489-4cab-8150-460614458541'] = $pane;
    $display->panels['middle'][0] = 'new-27265f65-4489-4cab-8150-460614458541';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-27265f65-4489-4cab-8150-460614458541';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['bookmarks'] = $page;

  return $pages;

}
