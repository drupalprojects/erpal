<?php
/**
 * @file
 * erpal_project_ui.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_project_ui_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'budgets';
  $mini->category = 'ERPAL projects';
  $mini->admin_title = 'Budgets';
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
  $display->title = 'Budgets';
  $display->uuid = '6336d45a-36f5-4140-8e48-d114166aae78';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fca8649a-10b8-428a-85b1-a298c91c349a';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'budgets-panel_pane_2';
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
    $pane->uuid = 'fca8649a-10b8-428a-85b1-a298c91c349a';
    $display->content['new-fca8649a-10b8-428a-85b1-a298c91c349a'] = $pane;
    $display->panels['middle'][0] = 'new-fca8649a-10b8-428a-85b1-a298c91c349a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fca8649a-10b8-428a-85b1-a298c91c349a';
  $mini->display = $display;
  $export['budgets'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'project_development_urls';
  $mini->category = 'ERPAL projects';
  $mini->admin_title = 'Project development urls';
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
  $display->uuid = '445c406f-1547-e3f4-ad6e-673c3697298e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-383b4549-0de1-a8a4-99af-d7fb5bf2b457';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_repository_url';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '383b4549-0de1-a8a4-99af-d7fb5bf2b457';
    $display->content['new-383b4549-0de1-a8a4-99af-d7fb5bf2b457'] = $pane;
    $display->panels['middle'][0] = 'new-383b4549-0de1-a8a4-99af-d7fb5bf2b457';
    $pane = new stdClass();
    $pane->pid = 'new-c927b23a-6fd1-4834-1d38-8dc4f69aab35';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_development_url';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c927b23a-6fd1-4834-1d38-8dc4f69aab35';
    $display->content['new-c927b23a-6fd1-4834-1d38-8dc4f69aab35'] = $pane;
    $display->panels['middle'][1] = 'new-c927b23a-6fd1-4834-1d38-8dc4f69aab35';
    $pane = new stdClass();
    $pane->pid = 'new-e7366b50-b4e1-bb34-9d22-da26ac143ad8';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_stage_url';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e7366b50-b4e1-bb34-9d22-da26ac143ad8';
    $display->content['new-e7366b50-b4e1-bb34-9d22-da26ac143ad8'] = $pane;
    $display->panels['middle'][2] = 'new-e7366b50-b4e1-bb34-9d22-da26ac143ad8';
    $pane = new stdClass();
    $pane->pid = 'new-94d22cff-8117-31d4-55f0-2b6704f88d52';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_live_url';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '94d22cff-8117-31d4-55f0-2b6704f88d52';
    $display->content['new-94d22cff-8117-31d4-55f0-2b6704f88d52'] = $pane;
    $display->panels['middle'][3] = 'new-94d22cff-8117-31d4-55f0-2b6704f88d52';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['project_development_urls'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'project_general_fields';
  $mini->category = 'erpal projects';
  $mini->admin_title = 'Project general fields';
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
  $display->uuid = '94301457-a83d-9784-c1b5-8f214bbd0220';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e5560f49-7e3a-ef94-3deb-77a2a8b83c3a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_customer_ref';
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
    $pane->uuid = 'e5560f49-7e3a-ef94-3deb-77a2a8b83c3a';
    $display->content['new-e5560f49-7e3a-ef94-3deb-77a2a8b83c3a'] = $pane;
    $display->panels['middle'][0] = 'new-e5560f49-7e3a-ef94-3deb-77a2a8b83c3a';
    $pane = new stdClass();
    $pane->pid = 'new-99c4a507-2fda-5a94-3569-003fe2996580';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_activity_ref';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '99c4a507-2fda-5a94-3569-003fe2996580';
    $display->content['new-99c4a507-2fda-5a94-3569-003fe2996580'] = $pane;
    $display->panels['middle'][1] = 'new-99c4a507-2fda-5a94-3569-003fe2996580';
    $pane = new stdClass();
    $pane->pid = 'new-4404a354-23b4-3684-110c-436673b12e4a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Project category',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4404a354-23b4-3684-110c-436673b12e4a';
    $display->content['new-4404a354-23b4-3684-110c-436673b12e4a'] = $pane;
    $display->panels['middle'][2] = 'new-4404a354-23b4-3684-110c-436673b12e4a';
    $pane = new stdClass();
    $pane->pid = 'new-352a23c2-05b2-6194-c9f0-bb79a86805f1';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_status_term';
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
    $pane->uuid = '352a23c2-05b2-6194-c9f0-bb79a86805f1';
    $display->content['new-352a23c2-05b2-6194-c9f0-bb79a86805f1'] = $pane;
    $display->panels['middle'][3] = 'new-352a23c2-05b2-6194-c9f0-bb79a86805f1';
    $pane = new stdClass();
    $pane->pid = 'new-bd198009-c306-41e4-5502-f73361b5d712';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_priority_term';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'bd198009-c306-41e4-5502-f73361b5d712';
    $display->content['new-bd198009-c306-41e4-5502-f73361b5d712'] = $pane;
    $display->panels['middle'][4] = 'new-bd198009-c306-41e4-5502-f73361b5d712';
    $pane = new stdClass();
    $pane->pid = 'new-ad167ce3-c38c-3f54-ad36-fbb84f7ff230';
    $pane->panel = 'middle';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
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
    $pane->uuid = 'ad167ce3-c38c-3f54-ad36-fbb84f7ff230';
    $display->content['new-ad167ce3-c38c-3f54-ad36-fbb84f7ff230'] = $pane;
    $display->panels['middle'][5] = 'new-ad167ce3-c38c-3f54-ad36-fbb84f7ff230';
    $pane = new stdClass();
    $pane->pid = 'new-c9e44fac-8ab5-cb54-650e-52fce1b3be76';
    $pane->panel = 'middle';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'erpal_date_time',
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
    $pane->uuid = 'c9e44fac-8ab5-cb54-650e-52fce1b3be76';
    $display->content['new-c9e44fac-8ab5-cb54-650e-52fce1b3be76'] = $pane;
    $display->panels['middle'][6] = 'new-c9e44fac-8ab5-cb54-650e-52fce1b3be76';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['project_general_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'project_summary';
  $mini->category = 'ERPAL projects';
  $mini->admin_title = 'Project summary';
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
  $display->uuid = '90c0e94b-439e-f414-2d9a-4f335f84631c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6fd494c9-45fa-bd84-f12d-24dc0b9dd77c';
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
    $pane->uuid = '6fd494c9-45fa-bd84-f12d-24dc0b9dd77c';
    $display->content['new-6fd494c9-45fa-bd84-f12d-24dc0b9dd77c'] = $pane;
    $display->panels['middle'][0] = 'new-6fd494c9-45fa-bd84-f12d-24dc0b9dd77c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['project_summary'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'task_basic_fields';
  $mini->category = 'ERPAL projects';
  $mini->admin_title = 'Task basic fields';
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
  $display->layout = 'threecol_33_34_33';
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
  $display->uuid = 'e8986caf-a4d5-5734-89a0-7ee8e2ce9e21';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-44b0cb1a-aa8b-a294-4dc7-ccd913a958a6';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_task_status_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_minimal',
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
    $pane->uuid = '44b0cb1a-aa8b-a294-4dc7-ccd913a958a6';
    $display->content['new-44b0cb1a-aa8b-a294-4dc7-ccd913a958a6'] = $pane;
    $display->panels['left'][0] = 'new-44b0cb1a-aa8b-a294-4dc7-ccd913a958a6';
    $pane = new stdClass();
    $pane->pid = 'new-b7587b1f-d764-de74-954d-64e09a803c74';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_priority_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_minimal',
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
    $pane->uuid = 'b7587b1f-d764-de74-954d-64e09a803c74';
    $display->content['new-b7587b1f-d764-de74-954d-64e09a803c74'] = $pane;
    $display->panels['left'][1] = 'new-b7587b1f-d764-de74-954d-64e09a803c74';
    $pane = new stdClass();
    $pane->pid = 'new-fef1e63e-824c-c244-29e8-14d835195233';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_task_type_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_minimal',
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
    $pane->uuid = 'fef1e63e-824c-c244-29e8-14d835195233';
    $display->content['new-fef1e63e-824c-c244-29e8-14d835195233'] = $pane;
    $display->panels['left'][2] = 'new-fef1e63e-824c-c244-29e8-14d835195233';
    $pane = new stdClass();
    $pane->pid = 'new-374953a9-2854-da74-f9dd-c8fa2282f2fe';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'time_information';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'requiredcontext_entity:node_1',
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
    $pane->uuid = '374953a9-2854-da74-f9dd-c8fa2282f2fe';
    $display->content['new-374953a9-2854-da74-f9dd-c8fa2282f2fe'] = $pane;
    $display->panels['middle'][0] = 'new-374953a9-2854-da74-f9dd-c8fa2282f2fe';
    $pane = new stdClass();
    $pane->pid = 'new-0bdc5b79-fde2-cc74-0dfb-4f83415629b8';
    $pane->panel = 'right';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'erpal_date_time',
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Submitted',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0bdc5b79-fde2-cc74-0dfb-4f83415629b8';
    $display->content['new-0bdc5b79-fde2-cc74-0dfb-4f83415629b8'] = $pane;
    $display->panels['right'][0] = 'new-0bdc5b79-fde2-cc74-0dfb-4f83415629b8';
    $pane = new stdClass();
    $pane->pid = 'new-ee665dc1-0622-7484-c141-278fff6597f6';
    $pane->panel = 'right';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'erpal_date_time',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'value2',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ee665dc1-0622-7484-c141-278fff6597f6';
    $display->content['new-ee665dc1-0622-7484-c141-278fff6597f6'] = $pane;
    $display->panels['right'][1] = 'new-ee665dc1-0622-7484-c141-278fff6597f6';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['task_basic_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'task_general_fields';
  $mini->category = 'erpal tasks';
  $mini->admin_title = 'Task general fields';
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
  $display->uuid = '41340402-8a2b-df24-c577-fe6749230208';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a6207cfb-7c87-bb34-2dc6-018a762633c3';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_typed_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Project',
      'link' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a6207cfb-7c87-bb34-2dc6-018a762633c3';
    $display->content['new-a6207cfb-7c87-bb34-2dc6-018a762633c3'] = $pane;
    $display->panels['middle'][0] = 'new-a6207cfb-7c87-bb34-2dc6-018a762633c3';
    $pane = new stdClass();
    $pane->pid = 'new-988a339f-8af6-fff4-f53c-bcd6fdda3e01';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_customer_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_typed_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 0,
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
    $pane->uuid = '988a339f-8af6-fff4-f53c-bcd6fdda3e01';
    $display->content['new-988a339f-8af6-fff4-f53c-bcd6fdda3e01'] = $pane;
    $display->panels['middle'][1] = 'new-988a339f-8af6-fff4-f53c-bcd6fdda3e01';
    $pane = new stdClass();
    $pane->pid = 'new-c0585ce3-4eaf-4364-f1b2-b96ae3281a78';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Task category',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c0585ce3-4eaf-4364-f1b2-b96ae3281a78';
    $display->content['new-c0585ce3-4eaf-4364-f1b2-b96ae3281a78'] = $pane;
    $display->panels['middle'][2] = 'new-c0585ce3-4eaf-4364-f1b2-b96ae3281a78';
    $pane = new stdClass();
    $pane->pid = 'new-b6a71cc0-9abb-3d94-bdc9-d51f010ad5ea';
    $pane->panel = 'middle';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 0,
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
    $pane->uuid = 'b6a71cc0-9abb-3d94-bdc9-d51f010ad5ea';
    $display->content['new-b6a71cc0-9abb-3d94-bdc9-d51f010ad5ea'] = $pane;
    $display->panels['middle'][3] = 'new-b6a71cc0-9abb-3d94-bdc9-d51f010ad5ea';
    $pane = new stdClass();
    $pane->pid = 'new-87ce8b15-7a22-0144-bda0-e07e6ba3351e';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_task_assigned_users';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_typed_label',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 0,
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
    $pane->uuid = '87ce8b15-7a22-0144-bda0-e07e6ba3351e';
    $display->content['new-87ce8b15-7a22-0144-bda0-e07e6ba3351e'] = $pane;
    $display->panels['middle'][4] = 'new-87ce8b15-7a22-0144-bda0-e07e6ba3351e';
    $pane = new stdClass();
    $pane->pid = 'new-c55352f5-8f2e-3bf4-599c-d2d3d0838ab1';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_parent';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c55352f5-8f2e-3bf4-599c-d2d3d0838ab1';
    $display->content['new-c55352f5-8f2e-3bf4-599c-d2d3d0838ab1'] = $pane;
    $display->panels['middle'][5] = 'new-c55352f5-8f2e-3bf4-599c-d2d3d0838ab1';
    $pane = new stdClass();
    $pane->pid = 'new-3dc67a9b-7688-3eb4-e5ac-c6401a9a65ec';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_depends_on_tasks';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'minimal',
        'links' => 1,
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Depends on tasks',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '3dc67a9b-7688-3eb4-e5ac-c6401a9a65ec';
    $display->content['new-3dc67a9b-7688-3eb4-e5ac-c6401a9a65ec'] = $pane;
    $display->panels['middle'][6] = 'new-3dc67a9b-7688-3eb4-e5ac-c6401a9a65ec';
    $pane = new stdClass();
    $pane->pid = 'new-53230bce-bb3c-44b5-bc57-3a0af25a0f27';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'crm_activity_by_task-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = '';
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '53230bce-bb3c-44b5-bc57-3a0af25a0f27';
    $display->content['new-53230bce-bb3c-44b5-bc57-3a0af25a0f27'] = $pane;
    $display->panels['middle'][7] = 'new-53230bce-bb3c-44b5-bc57-3a0af25a0f27';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['task_general_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'task_right_sidebar_pane';
  $mini->category = 'erpal tasks';
  $mini->admin_title = 'Task right sidebar pane';
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
  $display->uuid = 'b4534144-5dd5-bba4-5997-519867be76c5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bcdf2899-851b-d414-71cd-1ea55e3ff0d1';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'task_general_fields';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'requiredcontext_entity:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'General',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_collapsed' => 0,
        'pane_title' => 'General',
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bcdf2899-851b-d414-71cd-1ea55e3ff0d1';
    $display->content['new-bcdf2899-851b-d414-71cd-1ea55e3ff0d1'] = $pane;
    $display->panels['middle'][0] = 'new-bcdf2899-851b-d414-71cd-1ea55e3ff0d1';
    $pane = new stdClass();
    $pane->pid = 'new-e9b842d0-67cd-6084-25d6-ef1fa96240f9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_pricing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_fields',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'full',
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_collapsed' => 0,
        'pane_title' => 'Pricing',
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e9b842d0-67cd-6084-25d6-ef1fa96240f9';
    $display->content['new-e9b842d0-67cd-6084-25d6-ef1fa96240f9'] = $pane;
    $display->panels['middle'][1] = 'new-e9b842d0-67cd-6084-25d6-ef1fa96240f9';
    $pane = new stdClass();
    $pane->pid = 'new-15de1e99-c1f2-496e-a7d9-40fa0acee649';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'budgets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'requiredcontext_entity:node_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'pane_title' => 'Budgets',
        'pane_collapsed' => 1,
      ),
      'style' => 'collapsible',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '15de1e99-c1f2-496e-a7d9-40fa0acee649';
    $display->content['new-15de1e99-c1f2-496e-a7d9-40fa0acee649'] = $pane;
    $display->panels['middle'][2] = 'new-15de1e99-c1f2-496e-a7d9-40fa0acee649';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['task_right_sidebar_pane'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'task_status_panel';
  $mini->category = 'erpal tasks';
  $mini->admin_title = 'Task status panel';
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
  $display->uuid = '34473a25-80be-2564-95e3-1d5103a7bc43';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ed20af64-c83c-69c4-e921-01010126ccfe';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_task_status_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'editable',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'fallback_format' => 'taxonomy_term_reference_plain',
        'click_to_edit' => 0,
        'click_to_edit_style' => 'button',
        'empty_text' => '',
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
    $pane->uuid = 'ed20af64-c83c-69c4-e921-01010126ccfe';
    $display->content['new-ed20af64-c83c-69c4-e921-01010126ccfe'] = $pane;
    $display->panels['middle'][0] = 'new-ed20af64-c83c-69c4-e921-01010126ccfe';
    $pane = new stdClass();
    $pane->pid = 'new-6bf1c8ab-d7d1-0a34-c9d8-6a362ec77169';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_progress_percent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'editable',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'fallback_format' => 'list_default',
        'click_to_edit' => 0,
        'click_to_edit_style' => 'button',
        'empty_text' => '',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6bf1c8ab-d7d1-0a34-c9d8-6a362ec77169';
    $display->content['new-6bf1c8ab-d7d1-0a34-c9d8-6a362ec77169'] = $pane;
    $display->panels['middle'][1] = 'new-6bf1c8ab-d7d1-0a34-c9d8-6a362ec77169';
    $pane = new stdClass();
    $pane->pid = 'new-d0f88754-166f-8714-850e-34d0afafcfd5';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_priority_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'editable',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'fallback_format' => 'taxonomy_term_reference_plain',
        'click_to_edit' => 0,
        'click_to_edit_style' => 'button',
        'empty_text' => '',
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
    $pane->uuid = 'd0f88754-166f-8714-850e-34d0afafcfd5';
    $display->content['new-d0f88754-166f-8714-850e-34d0afafcfd5'] = $pane;
    $display->panels['middle'][2] = 'new-d0f88754-166f-8714-850e-34d0afafcfd5';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['task_status_panel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'time_information';
  $mini->category = 'erpal tasks';
  $mini->admin_title = 'Time information';
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
  $display->uuid = '694215a7-57b9-15a4-2130-69a5530deb7e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1adf6f2a-ad92-4c34-01ee-ad52a80b53ea';
    $pane->panel = 'middle';
    $pane->type = 'project_time_info';
    $pane->subtype = 'project_time_info';
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
    $pane->uuid = '1adf6f2a-ad92-4c34-01ee-ad52a80b53ea';
    $display->content['new-1adf6f2a-ad92-4c34-01ee-ad52a80b53ea'] = $pane;
    $display->panels['middle'][0] = 'new-1adf6f2a-ad92-4c34-01ee-ad52a80b53ea';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['time_information'] = $mini;

  return $export;
}
