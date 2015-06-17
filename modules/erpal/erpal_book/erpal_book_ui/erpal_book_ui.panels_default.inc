<?php
/**
 * @file
 * erpal_book_ui.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_book_ui_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'book_general_fields';
  $mini->category = 'erpal books';
  $mini->admin_title = 'Book general fields';
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
  $display->uuid = '01f3cca4-d096-63e4-edb6-7b760f290700';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d4a943b5-748d-47ba-a198-8ca0a42d4dad';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd4a943b5-748d-47ba-a198-8ca0a42d4dad';
    $display->content['new-d4a943b5-748d-47ba-a198-8ca0a42d4dad'] = $pane;
    $display->panels['middle'][0] = 'new-d4a943b5-748d-47ba-a198-8ca0a42d4dad';
    $pane = new stdClass();
    $pane->pid = 'new-1b8669cf-47df-4a8f-a2fe-d8e7a0671f76';
    $pane->panel = 'middle';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'erpal_date_time',
      'context' => 'requiredcontext_entity:node_1',
      'override_title' => 1,
      'override_title_text' => 'Created',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1b8669cf-47df-4a8f-a2fe-d8e7a0671f76';
    $display->content['new-1b8669cf-47df-4a8f-a2fe-d8e7a0671f76'] = $pane;
    $display->panels['middle'][1] = 'new-1b8669cf-47df-4a8f-a2fe-d8e7a0671f76';
    $pane = new stdClass();
    $pane->pid = 'new-17c07e5a-446a-4f18-9cbc-687e914b5c30';
    $pane->panel = 'middle';
    $pane->type = 'node_updated';
    $pane->subtype = 'node_updated';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'erpal_date_time',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '17c07e5a-446a-4f18-9cbc-687e914b5c30';
    $display->content['new-17c07e5a-446a-4f18-9cbc-687e914b5c30'] = $pane;
    $display->panels['middle'][2] = 'new-17c07e5a-446a-4f18-9cbc-687e914b5c30';
    $pane = new stdClass();
    $pane->pid = 'new-053020e1-17d3-c9f4-d9d9-14f311e3b409';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_is_template';
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
    $pane->uuid = '053020e1-17d3-c9f4-d9d9-14f311e3b409';
    $display->content['new-053020e1-17d3-c9f4-d9d9-14f311e3b409'] = $pane;
    $display->panels['middle'][3] = 'new-053020e1-17d3-c9f4-d9d9-14f311e3b409';
    $pane = new stdClass();
    $pane->pid = 'new-182c427d-7ede-88c4-29d0-6f8625ff9aa7';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_book_origin';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '182c427d-7ede-88c4-29d0-6f8625ff9aa7';
    $display->content['new-182c427d-7ede-88c4-29d0-6f8625ff9aa7'] = $pane;
    $display->panels['middle'][4] = 'new-182c427d-7ede-88c4-29d0-6f8625ff9aa7';
    $pane = new stdClass();
    $pane->pid = 'new-24a91acd-052d-a474-5dc6-d65e8dd7bac9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_book_tags';
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
    $pane->uuid = '24a91acd-052d-a474-5dc6-d65e8dd7bac9';
    $display->content['new-24a91acd-052d-a474-5dc6-d65e8dd7bac9'] = $pane;
    $display->panels['middle'][5] = 'new-24a91acd-052d-a474-5dc6-d65e8dd7bac9';
    $pane = new stdClass();
    $pane->pid = 'new-56495ede-23d6-e9c4-65b7-a370d3bea1b9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contact_ref';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '56495ede-23d6-e9c4-65b7-a370d3bea1b9';
    $display->content['new-56495ede-23d6-e9c4-65b7-a370d3bea1b9'] = $pane;
    $display->panels['middle'][6] = 'new-56495ede-23d6-e9c4-65b7-a370d3bea1b9';
    $pane = new stdClass();
    $pane->pid = 'new-d1e93f6e-bdcf-a7e4-29ca-188e634122f9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_address_id';
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'd1e93f6e-bdcf-a7e4-29ca-188e634122f9';
    $display->content['new-d1e93f6e-bdcf-a7e4-29ca-188e634122f9'] = $pane;
    $display->panels['middle'][7] = 'new-d1e93f6e-bdcf-a7e4-29ca-188e634122f9';
    $pane = new stdClass();
    $pane->pid = 'new-843dc0e9-c9c9-0db4-55bd-764c5f2f024d';
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '843dc0e9-c9c9-0db4-55bd-764c5f2f024d';
    $display->content['new-843dc0e9-c9c9-0db4-55bd-764c5f2f024d'] = $pane;
    $display->panels['middle'][8] = 'new-843dc0e9-c9c9-0db4-55bd-764c5f2f024d';
    $pane = new stdClass();
    $pane->pid = 'new-9388788c-d8a6-bc84-617e-b1ca65c31ec5';
    $pane->panel = 'middle';
    $pane->type = 'book_usage';
    $pane->subtype = 'book_usage';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '9388788c-d8a6-bc84-617e-b1ca65c31ec5';
    $display->content['new-9388788c-d8a6-bc84-617e-b1ca65c31ec5'] = $pane;
    $display->panels['middle'][9] = 'new-9388788c-d8a6-bc84-617e-b1ca65c31ec5';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['book_general_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'book_page_fields';
  $mini->category = 'erpal books';
  $mini->admin_title = 'Book page fields';
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
      'sidebar_first_left' => NULL,
      'sidebar_first_right' => NULL,
      'sidebar_second_left' => NULL,
      'sidebar_second_right' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '65010657-9a9b-3b74-f182-eaf92acf5a1c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bfcd4983-4477-ee54-b1e5-112176a713cd';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_book_ref';
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
    $pane->uuid = 'bfcd4983-4477-ee54-b1e5-112176a713cd';
    $display->content['new-bfcd4983-4477-ee54-b1e5-112176a713cd'] = $pane;
    $display->panels['middle'][0] = 'new-bfcd4983-4477-ee54-b1e5-112176a713cd';
    $pane = new stdClass();
    $pane->pid = 'new-28ef067f-8df1-db14-65c4-d0f33741deb7';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_estimated_duration';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'number_decimal',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'decimal_separator' => '.',
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
    $pane->uuid = '28ef067f-8df1-db14-65c4-d0f33741deb7';
    $display->content['new-28ef067f-8df1-db14-65c4-d0f33741deb7'] = $pane;
    $display->panels['middle'][1] = 'new-28ef067f-8df1-db14-65c4-d0f33741deb7';
    $pane = new stdClass();
    $pane->pid = 'new-1c2d3c4b-ffd7-7b94-d5a4-c6921908ea6a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_page_exclude_from';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'list_default',
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
    $pane->uuid = '1c2d3c4b-ffd7-7b94-d5a4-c6921908ea6a';
    $display->content['new-1c2d3c4b-ffd7-7b94-d5a4-c6921908ea6a'] = $pane;
    $display->panels['middle'][2] = 'new-1c2d3c4b-ffd7-7b94-d5a4-c6921908ea6a';
    $pane = new stdClass();
    $pane->pid = 'new-314da4f3-23ce-4213-82e1-6e90e321c7a9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_book_parent';
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
      'override_title' => 1,
      'override_title_text' => 'Parent page',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '314da4f3-23ce-4213-82e1-6e90e321c7a9';
    $display->content['new-314da4f3-23ce-4213-82e1-6e90e321c7a9'] = $pane;
    $display->panels['middle'][3] = 'new-314da4f3-23ce-4213-82e1-6e90e321c7a9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['book_page_fields'] = $mini;

  return $export;
}
