<?php
/**
 * @file
 * erpal_employee_ui.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function erpal_employee_ui_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'all_timekeepings';
  $page->task = 'page';
  $page->admin_title = 'All timekeepings';
  $page->admin_description = '';
  $page->path = 'timekeeping/all';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view any timekeeping',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'All timekeeping',
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
  $handler->name = 'page_all_timekeepings_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'all_timekeepings';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'All timekeeping panel',
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
  $display->title = 'All timekeeping';
  $display->uuid = '94180d3e-0530-d4e4-9daa-7786a82561b2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3586c09f-0fc0-3474-990a-731ddc1a0ad4';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-all_timekeeping_tabs';
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
    $pane->uuid = '3586c09f-0fc0-3474-990a-731ddc1a0ad4';
    $display->content['new-3586c09f-0fc0-3474-990a-731ddc1a0ad4'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-3586c09f-0fc0-3474-990a-731ddc1a0ad4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['all_timekeepings'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'timekeeping';
  $page->task = 'page';
  $page->admin_title = 'Timekeeping';
  $page->admin_description = '';
  $page->path = 'timekeeping';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view timekeeping',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Timekeeping',
    'name' => 'menu-erpal-menu',
    'weight' => '10',
    'parent' => array(
      'type' => 'tab',
      'title' => 'Timekeeping',
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
  $handler->name = 'page_timekeeping_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'timekeeping';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Timekeeping panel',
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
  $display->title = 'Timekeeping';
  $display->uuid = '0b4ba2c7-c3c5-fbd4-715d-ada6a9292573';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-616d2ab8-b7c2-76e4-8581-f76dcb03f8e6';
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
    $pane->uuid = '616d2ab8-b7c2-76e4-8581-f76dcb03f8e6';
    $display->content['new-616d2ab8-b7c2-76e4-8581-f76dcb03f8e6'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-616d2ab8-b7c2-76e4-8581-f76dcb03f8e6';
    $pane = new stdClass();
    $pane->pid = 'new-e22e1729-7132-bfc4-d1fd-8f99ac35cc1f';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'block';
    $pane->subtype = 'quicktabs-timekeeping_tabs';
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
    $pane->uuid = 'e22e1729-7132-bfc4-d1fd-8f99ac35cc1f';
    $display->content['new-e22e1729-7132-bfc4-d1fd-8f99ac35cc1f'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-e22e1729-7132-bfc4-d1fd-8f99ac35cc1f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['timekeeping'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_working_time_offset';
  $page->task = 'page';
  $page->admin_title = 'User working time offset';
  $page->admin_description = '';
  $page->path = 'user/%user/timekeeping-offsets';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'view any timekeeping',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Timekeeping offset',
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
  $handler->name = 'page_user_working_time_offset_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_working_time_offset';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Timekeeping offset panel',
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
  $display->uuid = 'be6d6980-6d39-0c34-5d4b-f89eb0b9178f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-589ba2c7-a8de-1434-d5f2-e2ad5d05b04a';
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
      'override_title_text' => 'Timekeeping offset for %user:name',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '589ba2c7-a8de-1434-d5f2-e2ad5d05b04a';
    $display->content['new-589ba2c7-a8de-1434-d5f2-e2ad5d05b04a'] = $pane;
    $display->panels['sidebar_first_left'][0] = 'new-589ba2c7-a8de-1434-d5f2-e2ad5d05b04a';
    $pane = new stdClass();
    $pane->pid = 'new-a7a917a7-1214-8544-a99d-9bb867e6b675';
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
    $pane->uuid = 'a7a917a7-1214-8544-a99d-9bb867e6b675';
    $display->content['new-a7a917a7-1214-8544-a99d-9bb867e6b675'] = $pane;
    $display->panels['sidebar_first_right'][0] = 'new-a7a917a7-1214-8544-a99d-9bb867e6b675';
    $pane = new stdClass();
    $pane->pid = 'new-122b52ce-211e-8c94-fd2d-61cb81883bc1';
    $pane->panel = 'sidebar_second_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'working_times-panel_pane_3';
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
    $pane->uuid = '122b52ce-211e-8c94-fd2d-61cb81883bc1';
    $display->content['new-122b52ce-211e-8c94-fd2d-61cb81883bc1'] = $pane;
    $display->panels['sidebar_second_left'][0] = 'new-122b52ce-211e-8c94-fd2d-61cb81883bc1';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_working_time_offset'] = $page;

  return $pages;

}
