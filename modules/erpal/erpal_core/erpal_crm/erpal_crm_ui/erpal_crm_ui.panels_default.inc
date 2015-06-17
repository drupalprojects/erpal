<?php
/**
 * @file
 * erpal_crm_ui.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_crm_ui_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'activity_general_fields';
  $mini->category = 'erpal crm';
  $mini->admin_title = 'Activity general fields';
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
  $display->layout = 'threecol_33_34_33_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '33322d30-e790-eef4-1d54-1607e500df72';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-434bf0b7-8723-1864-81bb-e8ffff975cd2';
    $pane->panel = 'left';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '434bf0b7-8723-1864-81bb-e8ffff975cd2';
    $display->content['new-434bf0b7-8723-1864-81bb-e8ffff975cd2'] = $pane;
    $display->panels['left'][0] = 'new-434bf0b7-8723-1864-81bb-e8ffff975cd2';
    $pane = new stdClass();
    $pane->pid = 'new-fc4a12f3-75ef-d0d4-2da1-589dd1d86c00';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_volume';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'number_decimal',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => '.',
        'decimal_separator' => ',',
        'scale' => '2',
        'prefix_suffix' => 1,
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
    $pane->uuid = 'fc4a12f3-75ef-d0d4-2da1-589dd1d86c00';
    $display->content['new-fc4a12f3-75ef-d0d4-2da1-589dd1d86c00'] = $pane;
    $display->panels['left'][1] = 'new-fc4a12f3-75ef-d0d4-2da1-589dd1d86c00';
    $pane = new stdClass();
    $pane->pid = 'new-c51b4b3f-5a5b-9a14-ade8-c4b5fd9a9bcb';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_order_number_intern';
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
    $pane->uuid = 'c51b4b3f-5a5b-9a14-ade8-c4b5fd9a9bcb';
    $display->content['new-c51b4b3f-5a5b-9a14-ade8-c4b5fd9a9bcb'] = $pane;
    $display->panels['left'][2] = 'new-c51b4b3f-5a5b-9a14-ade8-c4b5fd9a9bcb';
    $pane = new stdClass();
    $pane->pid = 'new-4879e6c1-a9e9-2d14-292f-822c9474f95b';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_order_number_extern';
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
    $pane->uuid = '4879e6c1-a9e9-2d14-292f-822c9474f95b';
    $display->content['new-4879e6c1-a9e9-2d14-292f-822c9474f95b'] = $pane;
    $display->panels['left'][3] = 'new-4879e6c1-a9e9-2d14-292f-822c9474f95b';
    $pane = new stdClass();
    $pane->pid = 'new-b0dcaa74-8505-7e54-9dc0-7bf6901399e6';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_next_contact';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b0dcaa74-8505-7e54-9dc0-7bf6901399e6';
    $display->content['new-b0dcaa74-8505-7e54-9dc0-7bf6901399e6'] = $pane;
    $display->panels['middle'][0] = 'new-b0dcaa74-8505-7e54-9dc0-7bf6901399e6';
    $pane = new stdClass();
    $pane->pid = 'new-2b67391d-471e-1e04-3d4f-a031c4151866';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_chance';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2b67391d-471e-1e04-3d4f-a031c4151866';
    $display->content['new-2b67391d-471e-1e04-3d4f-a031c4151866'] = $pane;
    $display->panels['middle'][1] = 'new-2b67391d-471e-1e04-3d4f-a031c4151866';
    $pane = new stdClass();
    $pane->pid = 'new-978d11f3-4f5f-9b44-c54a-bfbbc0c2b761';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_activity_status_term';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '978d11f3-4f5f-9b44-c54a-bfbbc0c2b761';
    $display->content['new-978d11f3-4f5f-9b44-c54a-bfbbc0c2b761'] = $pane;
    $display->panels['middle'][2] = 'new-978d11f3-4f5f-9b44-c54a-bfbbc0c2b761';
    $pane = new stdClass();
    $pane->pid = 'new-cf24182f-f19c-fcc4-65a2-4aeff5731dbd';
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
    $pane->uuid = 'cf24182f-f19c-fcc4-65a2-4aeff5731dbd';
    $display->content['new-cf24182f-f19c-fcc4-65a2-4aeff5731dbd'] = $pane;
    $display->panels['middle'][3] = 'new-cf24182f-f19c-fcc4-65a2-4aeff5731dbd';
    $pane = new stdClass();
    $pane->pid = 'new-6ee2fdfe-8d78-dc84-6dc0-49b9c8eeb1fa';
    $pane->panel = 'top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_customer_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
        'view_mode' => 'in_activity',
        'links' => 1,
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
    $pane->uuid = '6ee2fdfe-8d78-dc84-6dc0-49b9c8eeb1fa';
    $display->content['new-6ee2fdfe-8d78-dc84-6dc0-49b9c8eeb1fa'] = $pane;
    $display->panels['top'][0] = 'new-6ee2fdfe-8d78-dc84-6dc0-49b9c8eeb1fa';
    $pane = new stdClass();
    $pane->pid = 'new-59f163a5-fd26-5db4-3597-05d2e5f86f5a';
    $pane->panel = 'top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_account_manager';
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
    $pane->uuid = '59f163a5-fd26-5db4-3597-05d2e5f86f5a';
    $display->content['new-59f163a5-fd26-5db4-3597-05d2e5f86f5a'] = $pane;
    $display->panels['top'][1] = 'new-59f163a5-fd26-5db4-3597-05d2e5f86f5a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['activity_general_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'activity_status_panel';
  $mini->category = 'erpal crm';
  $mini->admin_title = 'Activity status panel';
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
  $display->uuid = 'ad139f37-d1d0-8754-9df1-4e773e144748';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b79e4b30-8550-9094-b98d-f9e701686256';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_activity_status_term';
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
    $pane->uuid = 'b79e4b30-8550-9094-b98d-f9e701686256';
    $display->content['new-b79e4b30-8550-9094-b98d-f9e701686256'] = $pane;
    $display->panels['middle'][0] = 'new-b79e4b30-8550-9094-b98d-f9e701686256';
    $pane = new stdClass();
    $pane->pid = 'new-8f2e9028-d6df-0d04-d1a6-637496cc309a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_next_contact';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'editable',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'erpal_date_time',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
        'show_repeat_rule' => 'show',
        'fallback_format' => 'date_default',
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
    $pane->uuid = '8f2e9028-d6df-0d04-d1a6-637496cc309a';
    $display->content['new-8f2e9028-d6df-0d04-d1a6-637496cc309a'] = $pane;
    $display->panels['middle'][1] = 'new-8f2e9028-d6df-0d04-d1a6-637496cc309a';
    $pane = new stdClass();
    $pane->pid = 'new-bbe3fa8c-f127-89f4-c560-e90dd0c63e8b';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_task_ref';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'in_activity',
        'links' => 0,
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Timetracking',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bbe3fa8c-f127-89f4-c560-e90dd0c63e8b';
    $display->content['new-bbe3fa8c-f127-89f4-c560-e90dd0c63e8b'] = $pane;
    $display->panels['middle'][2] = 'new-bbe3fa8c-f127-89f4-c560-e90dd0c63e8b';
    $pane = new stdClass();
    $pane->pid = 'new-30e560f5-e99b-49d2-bb8b-a4add3553bfa';
    $pane->panel = 'middle';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Author',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '30e560f5-e99b-49d2-bb8b-a4add3553bfa';
    $display->content['new-30e560f5-e99b-49d2-bb8b-a4add3553bfa'] = $pane;
    $display->panels['middle'][3] = 'new-30e560f5-e99b-49d2-bb8b-a4add3553bfa';
    $pane = new stdClass();
    $pane->pid = 'new-09d1fac9-7b3b-4920-a07f-a16bd810b8b5';
    $pane->panel = 'middle';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'long',
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Sumitted',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '09d1fac9-7b3b-4920-a07f-a16bd810b8b5';
    $display->content['new-09d1fac9-7b3b-4920-a07f-a16bd810b8b5'] = $pane;
    $display->panels['middle'][4] = 'new-09d1fac9-7b3b-4920-a07f-a16bd810b8b5';
    $pane = new stdClass();
    $pane->pid = 'new-6c7453f6-e4f4-4e4f-8978-78271d559f45';
    $pane->panel = 'middle';
    $pane->type = 'node_updated';
    $pane->subtype = 'node_updated';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'long',
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Updated',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '6c7453f6-e4f4-4e4f-8978-78271d559f45';
    $display->content['new-6c7453f6-e4f4-4e4f-8978-78271d559f45'] = $pane;
    $display->panels['middle'][5] = 'new-6c7453f6-e4f4-4e4f-8978-78271d559f45';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['activity_status_panel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'contact_details_panel';
  $mini->category = 'erpal contacts';
  $mini->admin_title = 'Contact details panel';
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
  $display->uuid = 'ed15599b-a144-acd4-adf1-1f6e52fa3ea6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0057d4cf-dc1d-94d4-4109-3c219334c139';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_addresses';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => '',
        'delete' => '',
        'add' => 'add address',
        'description' => 1,
        'view_mode' => 'full',
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Addresses',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0057d4cf-dc1d-94d4-4109-3c219334c139';
    $display->content['new-0057d4cf-dc1d-94d4-4109-3c219334c139'] = $pane;
    $display->panels['middle'][0] = 'new-0057d4cf-dc1d-94d4-4109-3c219334c139';
    $pane = new stdClass();
    $pane->pid = 'new-b9b1e167-a7b4-bb74-e11c-8660e5e71111';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_communication';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_table_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => '',
        'delete' => '',
        'add' => '',
        'description' => 1,
        'view_mode' => 'full',
        'empty' => 1,
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
    $pane->uuid = 'b9b1e167-a7b4-bb74-e11c-8660e5e71111';
    $display->content['new-b9b1e167-a7b4-bb74-e11c-8660e5e71111'] = $pane;
    $display->panels['middle'][1] = 'new-b9b1e167-a7b4-bb74-e11c-8660e5e71111';
    $pane = new stdClass();
    $pane->pid = 'new-5533df42-54d3-8044-c911-9ac2040fdde1';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_bank_accounts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => '',
        'delete' => '',
        'add' => 'add bank account',
        'description' => 0,
        'view_mode' => 'full',
      ),
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Bank accounts',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5533df42-54d3-8044-c911-9ac2040fdde1';
    $display->content['new-5533df42-54d3-8044-c911-9ac2040fdde1'] = $pane;
    $display->panels['middle'][2] = 'new-5533df42-54d3-8044-c911-9ac2040fdde1';
    $pane = new stdClass();
    $pane->pid = 'new-446d08e0-0d16-bc84-45b7-7793fb7b903a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_vat_number';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '446d08e0-0d16-bc84-45b7-7793fb7b903a';
    $display->content['new-446d08e0-0d16-bc84-45b7-7793fb7b903a'] = $pane;
    $display->panels['middle'][3] = 'new-446d08e0-0d16-bc84-45b7-7793fb7b903a';
    $pane = new stdClass();
    $pane->pid = 'new-0a5c357a-67d5-5e04-d103-5a7afd0065f4';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_legal_other';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '0a5c357a-67d5-5e04-d103-5a7afd0065f4';
    $display->content['new-0a5c357a-67d5-5e04-d103-5a7afd0065f4'] = $pane;
    $display->panels['middle'][4] = 'new-0a5c357a-67d5-5e04-d103-5a7afd0065f4';
    $pane = new stdClass();
    $pane->pid = 'new-0767edbc-7939-2ca4-ed80-52be2e22c1ac';
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
    $pane->uuid = '0767edbc-7939-2ca4-ed80-52be2e22c1ac';
    $display->content['new-0767edbc-7939-2ca4-ed80-52be2e22c1ac'] = $pane;
    $display->panels['middle'][5] = 'new-0767edbc-7939-2ca4-ed80-52be2e22c1ac';
    $pane = new stdClass();
    $pane->pid = 'new-6398e33b-19fe-ee64-0da7-6d9a127feb5a';
    $pane->panel = 'middle';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '30',
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '6398e33b-19fe-ee64-0da7-6d9a127feb5a';
    $display->content['new-6398e33b-19fe-ee64-0da7-6d9a127feb5a'] = $pane;
    $display->panels['middle'][6] = 'new-6398e33b-19fe-ee64-0da7-6d9a127feb5a';
    $pane = new stdClass();
    $pane->pid = 'new-b9a233b6-bb91-5004-794e-dcfe599d6576';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'b9a233b6-bb91-5004-794e-dcfe599d6576';
    $display->content['new-b9a233b6-bb91-5004-794e-dcfe599d6576'] = $pane;
    $display->panels['middle'][7] = 'new-b9a233b6-bb91-5004-794e-dcfe599d6576';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['contact_details_panel'] = $mini;

  return $export;
}
