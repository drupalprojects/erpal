<?php
/**
 * @file
 * erpal_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function erpal_layout_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Default page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'erpal_wrapper',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'erpal_layout';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'center' => NULL,
      'left_region' => NULL,
      'right_region' => NULL,
      'tabs_region' => NULL,
      'top_region' => NULL,
      'tabs_region_' => NULL,
      'row_first_left_' => NULL,
      'row_first_right' => NULL,
      'sidebar_top' => NULL,
      'sidebar_tabs_row' => NULL,
      'sidebar_left' => NULL,
      'sidebar_right' => NULL,
      'sidebar_content' => NULL,
      'footer_row' => NULL,
    ),
    'left' => array(
      'style' => 'naked',
    ),
  );
  $display->cache = array();
  $display->title = '<none>';
  $display->uuid = '2702bbc2-d095-64d4-d961-750e9ad985db';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-88aa5389-b905-1314-05fa-46b107717d13';
    $pane->panel = 'footer_row';
    $pane->type = 'powered_by';
    $pane->subtype = 'powered_by';
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
    $pane->uuid = '88aa5389-b905-1314-05fa-46b107717d13';
    $display->content['new-88aa5389-b905-1314-05fa-46b107717d13'] = $pane;
    $display->panels['footer_row'][0] = 'new-88aa5389-b905-1314-05fa-46b107717d13';
    $pane = new stdClass();
    $pane->pid = 'new-48e4a116-ef3e-ede4-f1ff-29201b7d2509';
    $pane->panel = 'sidebar_content';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
    $pane->shown = TRUE;
    $pane->access = array(
      'logic' => 'and',
      'plugins' => array(),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '48e4a116-ef3e-ede4-f1ff-29201b7d2509';
    $display->content['new-48e4a116-ef3e-ede4-f1ff-29201b7d2509'] = $pane;
    $display->panels['sidebar_content'][0] = 'new-48e4a116-ef3e-ede4-f1ff-29201b7d2509';
    $pane = new stdClass();
    $pane->pid = 'new-89691eba-0766-7924-25d7-083ec9609365';
    $pane->panel = 'sidebar_content';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = '89691eba-0766-7924-25d7-083ec9609365';
    $display->content['new-89691eba-0766-7924-25d7-083ec9609365'] = $pane;
    $display->panels['sidebar_content'][1] = 'new-89691eba-0766-7924-25d7-083ec9609365';
    $pane = new stdClass();
    $pane->pid = 'new-07f973a4-d005-5b94-e508-d07163e72911';
    $pane->panel = 'sidebar_content';
    $pane->type = 'page_help';
    $pane->subtype = 'page_help';
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
    $pane->uuid = '07f973a4-d005-5b94-e508-d07163e72911';
    $display->content['new-07f973a4-d005-5b94-e508-d07163e72911'] = $pane;
    $display->panels['sidebar_content'][2] = 'new-07f973a4-d005-5b94-e508-d07163e72911';
    $pane = new stdClass();
    $pane->pid = 'new-5fff8bf8-f4f2-92d4-b905-f7e1feacf3aa';
    $pane->panel = 'sidebar_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = '5fff8bf8-f4f2-92d4-b905-f7e1feacf3aa';
    $display->content['new-5fff8bf8-f4f2-92d4-b905-f7e1feacf3aa'] = $pane;
    $display->panels['sidebar_content'][3] = 'new-5fff8bf8-f4f2-92d4-b905-f7e1feacf3aa';
    $pane = new stdClass();
    $pane->pid = 'new-353850b8-3b63-49c4-b88c-cfadc0adc30a';
    $pane->panel = 'sidebar_left';
    $pane->type = 'erpal_search_pane';
    $pane->subtype = 'erpal_search_pane';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-search-form',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '353850b8-3b63-49c4-b88c-cfadc0adc30a';
    $display->content['new-353850b8-3b63-49c4-b88c-cfadc0adc30a'] = $pane;
    $display->panels['sidebar_left'][0] = 'new-353850b8-3b63-49c4-b88c-cfadc0adc30a';
    $pane = new stdClass();
    $pane->pid = 'new-3966ecb3-7231-8404-b554-19b532b66fac';
    $pane->panel = 'sidebar_left';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-erpal-menu';
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
    $pane->uuid = '3966ecb3-7231-8404-b554-19b532b66fac';
    $display->content['new-3966ecb3-7231-8404-b554-19b532b66fac'] = $pane;
    $display->panels['sidebar_left'][1] = 'new-3966ecb3-7231-8404-b554-19b532b66fac';
    $pane = new stdClass();
    $pane->pid = 'new-4b04eeb8-b09f-6a04-ed32-43863886e78b';
    $pane->panel = 'sidebar_tabs_row';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
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
    $pane->uuid = '4b04eeb8-b09f-6a04-ed32-43863886e78b';
    $display->content['new-4b04eeb8-b09f-6a04-ed32-43863886e78b'] = $pane;
    $display->panels['sidebar_tabs_row'][0] = 'new-4b04eeb8-b09f-6a04-ed32-43863886e78b';
    $pane = new stdClass();
    $pane->pid = 'new-924b919e-4d82-c014-dd1b-3db68efe3915';
    $pane->panel = 'sidebar_top';
    $pane->type = 'panels_mini';
    $pane->subtype = 'user_bar';
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
    $pane->uuid = '924b919e-4d82-c014-dd1b-3db68efe3915';
    $display->content['new-924b919e-4d82-c014-dd1b-3db68efe3915'] = $pane;
    $display->panels['sidebar_top'][0] = 'new-924b919e-4d82-c014-dd1b-3db68efe3915';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_2';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Login Page',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/login',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_main' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3a117a1e-df29-11f4-95c7-d55df58104d7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-dba1d45f-2c64-ee24-2102-6d297b931f22';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Login mask logo',
      'title' => '',
      'body' => '<div id="login_mask_logo"></div>',
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
    $pane->uuid = 'dba1d45f-2c64-ee24-2102-6d297b931f22';
    $display->content['new-dba1d45f-2c64-ee24-2102-6d297b931f22'] = $pane;
    $display->panels['middle'][0] = 'new-dba1d45f-2c64-ee24-2102-6d297b931f22';
    $pane = new stdClass();
    $pane->pid = 'new-3ac38892-6f77-cda4-1df4-a144c2b36d69';
    $pane->panel = 'middle';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = '3ac38892-6f77-cda4-1df4-a144c2b36d69';
    $display->content['new-3ac38892-6f77-cda4-1df4-a144c2b36d69'] = $pane;
    $display->panels['middle'][1] = 'new-3ac38892-6f77-cda4-1df4-a144c2b36d69';
    $pane = new stdClass();
    $pane->pid = 'new-bf3109e5-04f4-6ea4-1104-05420d1dfcf4';
    $pane->panel = 'middle';
    $pane->type = 'page_help';
    $pane->subtype = 'page_help';
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
    $pane->uuid = 'bf3109e5-04f4-6ea4-1104-05420d1dfcf4';
    $display->content['new-bf3109e5-04f4-6ea4-1104-05420d1dfcf4'] = $pane;
    $display->panels['middle'][2] = 'new-bf3109e5-04f4-6ea4-1104-05420d1dfcf4';
    $pane = new stdClass();
    $pane->pid = 'new-fc3576b7-d684-4b74-5523-c86e4526ea6b';
    $pane->panel = 'middle';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
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
    $pane->uuid = 'fc3576b7-d684-4b74-5523-c86e4526ea6b';
    $display->content['new-fc3576b7-d684-4b74-5523-c86e4526ea6b'] = $pane;
    $display->panels['middle'][3] = 'new-fc3576b7-d684-4b74-5523-c86e4526ea6b';
    $pane = new stdClass();
    $pane->pid = 'new-f24637ce-8657-f014-b534-507f9d5c7d5f';
    $pane->panel = 'middle';
    $pane->type = 'powered_by';
    $pane->subtype = 'powered_by';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f24637ce-8657-f014-b534-507f9d5c7d5f';
    $display->content['new-f24637ce-8657-f014-b534-507f9d5c7d5f'] = $pane;
    $display->panels['middle'][4] = 'new-f24637ce-8657-f014-b534-507f9d5c7d5f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_2'] = $handler;

  return $export;
}
