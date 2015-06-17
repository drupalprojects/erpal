<?php
/**
 * @file
 * erpal_basic_ui.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_basic_ui_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'body_and_comments';
  $mini->category = 'erpal nodes';
  $mini->admin_title = 'Body and comments';
  $mini->admin_description = 'A Pane viewing the body and the content of a node';
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
  $display->uuid = 'f5d68b60-737b-f264-7d00-17976255ecdb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d3926596-67cd-a794-3914-d4a1d23c16d1';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
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
    $pane->uuid = 'd3926596-67cd-a794-3914-d4a1d23c16d1';
    $display->content['new-d3926596-67cd-a794-3914-d4a1d23c16d1'] = $pane;
    $display->panels['middle'][0] = 'new-d3926596-67cd-a794-3914-d4a1d23c16d1';
    $pane = new stdClass();
    $pane->pid = 'new-416ace87-ab97-7a54-5d9a-baf470c66ae8';
    $pane->panel = 'middle';
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
    $pane->uuid = '416ace87-ab97-7a54-5d9a-baf470c66ae8';
    $display->content['new-416ace87-ab97-7a54-5d9a-baf470c66ae8'] = $pane;
    $display->panels['middle'][1] = 'new-416ace87-ab97-7a54-5d9a-baf470c66ae8';
    $pane = new stdClass();
    $pane->pid = 'new-afed043f-a0fb-1ec4-29b5-c3c99361df88';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_files_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_file_node',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'afed043f-a0fb-1ec4-29b5-c3c99361df88';
    $display->content['new-afed043f-a0fb-1ec4-29b5-c3c99361df88'] = $pane;
    $display->panels['middle'][2] = 'new-afed043f-a0fb-1ec4-29b5-c3c99361df88';
    $pane = new stdClass();
    $pane->pid = 'new-fb953383-5377-6974-018c-ea610a00ec26';
    $pane->panel = 'middle';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '300',
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'fb953383-5377-6974-018c-ea610a00ec26';
    $display->content['new-fb953383-5377-6974-018c-ea610a00ec26'] = $pane;
    $display->panels['middle'][3] = 'new-fb953383-5377-6974-018c-ea610a00ec26';
    $pane = new stdClass();
    $pane->pid = 'new-6052ba05-5480-30e4-d138-7603fd9e1616';
    $pane->panel = 'middle';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '6052ba05-5480-30e4-d138-7603fd9e1616';
    $display->content['new-6052ba05-5480-30e4-d138-7603fd9e1616'] = $pane;
    $display->panels['middle'][4] = 'new-6052ba05-5480-30e4-d138-7603fd9e1616';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['body_and_comments'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'contact_general_fields';
  $mini->category = 'erpal contacts';
  $mini->admin_title = 'Contact general fields';
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
  $display->uuid = '4cc8b05c-8282-a964-31f6-bc3db3c1a057';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f212d150-3786-9764-2546-acb9272e9841';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contact_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'list_default',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f212d150-3786-9764-2546-acb9272e9841';
    $display->content['new-f212d150-3786-9764-2546-acb9272e9841'] = $pane;
    $display->panels['middle'][0] = 'new-f212d150-3786-9764-2546-acb9272e9841';
    $pane = new stdClass();
    $pane->pid = 'new-4648d261-5cb2-25a4-cd1d-e974c5607785';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contact_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Contact category',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4648d261-5cb2-25a4-cd1d-e974c5607785';
    $display->content['new-4648d261-5cb2-25a4-cd1d-e974c5607785'] = $pane;
    $display->panels['middle'][1] = 'new-4648d261-5cb2-25a4-cd1d-e974c5607785';
    $pane = new stdClass();
    $pane->pid = 'new-3f84ec83-aa5c-baf4-117c-eaebb3135a25';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_customer_category';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'list_default',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3f84ec83-aa5c-baf4-117c-eaebb3135a25';
    $display->content['new-3f84ec83-aa5c-baf4-117c-eaebb3135a25'] = $pane;
    $display->panels['middle'][2] = 'new-3f84ec83-aa5c-baf4-117c-eaebb3135a25';
    $pane = new stdClass();
    $pane->pid = 'new-b18dcad8-c88b-e874-f129-2b9ddb7829bc';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_activity_origin';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_term_reference_plain',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b18dcad8-c88b-e874-f129-2b9ddb7829bc';
    $display->content['new-b18dcad8-c88b-e874-f129-2b9ddb7829bc'] = $pane;
    $display->panels['middle'][3] = 'new-b18dcad8-c88b-e874-f129-2b9ddb7829bc';
    $pane = new stdClass();
    $pane->pid = 'new-3df5db6a-a1cf-c5e4-f519-41d888caac0c';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_gender';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'list_default',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '3df5db6a-a1cf-c5e4-f519-41d888caac0c';
    $display->content['new-3df5db6a-a1cf-c5e4-f519-41d888caac0c'] = $pane;
    $display->panels['middle'][4] = 'new-3df5db6a-a1cf-c5e4-f519-41d888caac0c';
    $pane = new stdClass();
    $pane->pid = 'new-5034b1f8-9085-4d34-d907-b183da28548d';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birthday';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'erpal_date',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
        'show_repeat_rule' => 'show',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '5034b1f8-9085-4d34-d907-b183da28548d';
    $display->content['new-5034b1f8-9085-4d34-d907-b183da28548d'] = $pane;
    $display->panels['middle'][5] = 'new-5034b1f8-9085-4d34-d907-b183da28548d';
    $pane = new stdClass();
    $pane->pid = 'new-f5f425f1-65d9-ac14-2514-7e022629d6c2';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_vat_number';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'f5f425f1-65d9-ac14-2514-7e022629d6c2';
    $display->content['new-f5f425f1-65d9-ac14-2514-7e022629d6c2'] = $pane;
    $display->panels['middle'][6] = 'new-f5f425f1-65d9-ac14-2514-7e022629d6c2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['contact_general_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'user_bar';
  $mini->category = 'erpal';
  $mini->admin_title = 'User bar';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'threecol_25_50_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4ed252ed-4a15-b5f4-157e-153f1f4ae751';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-85715b32-630e-4f94-49ea-e1f94a253191';
    $pane->panel = 'left';
    $pane->type = 'page_logo';
    $pane->subtype = 'page_logo';
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
    $pane->uuid = '85715b32-630e-4f94-49ea-e1f94a253191';
    $display->content['new-85715b32-630e-4f94-49ea-e1f94a253191'] = $pane;
    $display->panels['left'][0] = 'new-85715b32-630e-4f94-49ea-e1f94a253191';
    $pane = new stdClass();
    $pane->pid = 'new-543c6dba-30ab-b494-d1fa-4b6d3b15e343';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'erpal_basic_helper-logged_in_user_block';
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
    $pane->uuid = '543c6dba-30ab-b494-d1fa-4b6d3b15e343';
    $display->content['new-543c6dba-30ab-b494-d1fa-4b6d3b15e343'] = $pane;
    $display->panels['middle'][0] = 'new-543c6dba-30ab-b494-d1fa-4b6d3b15e343';
    $pane = new stdClass();
    $pane->pid = 'new-665c0f9f-60a4-c314-2190-006fa7b906f9';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
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
    $pane->uuid = '665c0f9f-60a4-c314-2190-006fa7b906f9';
    $display->content['new-665c0f9f-60a4-c314-2190-006fa7b906f9'] = $pane;
    $display->panels['middle'][1] = 'new-665c0f9f-60a4-c314-2190-006fa7b906f9';
    $pane = new stdClass();
    $pane->pid = 'new-7a10eae3-1861-7c24-89fc-256eb1c98add';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'erpal_projects_helper-last_timetracking_block';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7a10eae3-1861-7c24-89fc-256eb1c98add';
    $display->content['new-7a10eae3-1861-7c24-89fc-256eb1c98add'] = $pane;
    $display->panels['middle'][2] = 'new-7a10eae3-1861-7c24-89fc-256eb1c98add';
    $pane = new stdClass();
    $pane->pid = 'new-562d9e93-4020-0d44-ed08-1dbc76f43394';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'erpal_basic_helper-logout_block';
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
    $pane->uuid = '562d9e93-4020-0d44-ed08-1dbc76f43394';
    $display->content['new-562d9e93-4020-0d44-ed08-1dbc76f43394'] = $pane;
    $display->panels['right'][0] = 'new-562d9e93-4020-0d44-ed08-1dbc76f43394';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['user_bar'] = $mini;

  return $export;
}
