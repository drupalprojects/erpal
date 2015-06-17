<?php
/**
 * @file
 * erpal_basic_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_basic_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'crm_contacts';
  $page->task = 'page';
  $page->admin_title = 'CRM Contacts';
  $page->admin_description = '';
  $page->path = 'contacts';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access contact view',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
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
  $handler->name = 'page_crm_contacts_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'crm_contacts';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Contacts panel',
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
  $display->title = 'Contacts';
  $display->uuid = '757f9ce7-fef3-2484-8542-583cb332064c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8e1628eb-c1a5-b204-85ac-6ccadb0d37f3';
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
    $pane->uuid = '8e1628eb-c1a5-b204-85ac-6ccadb0d37f3';
    $display->content['new-8e1628eb-c1a5-b204-85ac-6ccadb0d37f3'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-8e1628eb-c1a5-b204-85ac-6ccadb0d37f3';
    $pane = new stdClass();
    $pane->pid = 'new-dc665ec6-7cd1-df64-bda7-4786b8c4922d';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'contacts-panel_pane_1';
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
    $pane->uuid = 'dc665ec6-7cd1-df64-bda7-4786b8c4922d';
    $display->content['new-dc665ec6-7cd1-df64-bda7-4786b8c4922d'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-dc665ec6-7cd1-df64-bda7-4786b8c4922d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['crm_contacts'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'users_notifications';
  $page->task = 'page';
  $page->admin_title = 'Users notifications';
  $page->admin_description = '';
  $page->path = 'user/%user/notifications';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Notifications',
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
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
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
  $handler->name = 'page_users_notifications_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'users_notifications';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Notifications Panel',
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
        1 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = 'My notifications';
  $display->uuid = 'd6b72072-efb4-c8f4-c1ca-8b7d4288b8fd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-484b783e-404a-2454-4548-9f006f5ef750';
    $pane->panel = 'one_main';
    $pane->type = 'views_panes';
    $pane->subtype = 'notifications-panel_pane_2';
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
    $pane->uuid = '484b783e-404a-2454-4548-9f006f5ef750';
    $display->content['new-484b783e-404a-2454-4548-9f006f5ef750'] = $pane;
    $display->panels['one_main'][0] = 'new-484b783e-404a-2454-4548-9f006f5ef750';
    $pane = new stdClass();
    $pane->pid = 'new-623073c6-2feb-27e4-bda0-5cdf7d928df5';
    $pane->panel = 'one_main';
    $pane->type = 'views_panes';
    $pane->subtype = 'notifications-panel_pane_1';
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
    $pane->uuid = '623073c6-2feb-27e4-bda0-5cdf7d928df5';
    $display->content['new-623073c6-2feb-27e4-bda0-5cdf7d928df5'] = $pane;
    $display->panels['one_main'][1] = 'new-623073c6-2feb-27e4-bda0-5cdf7d928df5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['users_notifications'] = $page;

  return $pages;

}
