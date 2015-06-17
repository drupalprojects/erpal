<?php
/**
 * @file
 * erpal_invoice_ui.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_invoice_ui_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'invoice_content_panel';
  $mini->category = 'erpal invoices';
  $mini->admin_title = 'Invoice content panel';
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
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4bbc6afe-9508-0fb4-3124-0c6393055876';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6fc61225-be8c-c8e4-b931-530c81c578b2';
    $pane->panel = 'top';
    $pane->type = 'views_panes';
    $pane->subtype = 'billables-panel_pane_1';
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
    $pane->uuid = '6fc61225-be8c-c8e4-b931-530c81c578b2';
    $display->content['new-6fc61225-be8c-c8e4-b931-530c81c578b2'] = $pane;
    $display->panels['top'][0] = 'new-6fc61225-be8c-c8e4-b931-530c81c578b2';
    $pane = new stdClass();
    $pane->pid = 'new-78f9f883-ea8b-edc4-7159-664de33dd811';
    $pane->panel = 'top';
    $pane->type = 'views_panes';
    $pane->subtype = 'payment-panel_pane_1';
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
    $pane->uuid = '78f9f883-ea8b-edc4-7159-664de33dd811';
    $display->content['new-78f9f883-ea8b-edc4-7159-664de33dd811'] = $pane;
    $display->panels['top'][1] = 'new-78f9f883-ea8b-edc4-7159-664de33dd811';
    $pane = new stdClass();
    $pane->pid = 'new-1d34b4b9-5b99-1464-ddec-c2408ec449e2';
    $pane->panel = 'top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_saldo';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1d34b4b9-5b99-1464-ddec-c2408ec449e2';
    $display->content['new-1d34b4b9-5b99-1464-ddec-c2408ec449e2'] = $pane;
    $display->panels['top'][2] = 'new-1d34b4b9-5b99-1464-ddec-c2408ec449e2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['invoice_content_panel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'invoice_detailed_fields';
  $mini->category = 'erpal invoices';
  $mini->admin_title = 'Invoice detailed fields';
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
  $display->uuid = 'fc357057-ee2c-ec84-19c1-e76b52625665';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-35888e50-d924-85d4-0589-3d45470c6cc7';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_price_no_vat';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '35888e50-d924-85d4-0589-3d45470c6cc7';
    $display->content['new-35888e50-d924-85d4-0589-3d45470c6cc7'] = $pane;
    $display->panels['middle'][0] = 'new-35888e50-d924-85d4-0589-3d45470c6cc7';
    $pane = new stdClass();
    $pane->pid = 'new-63afe46e-2eeb-ba04-fd1f-78abd1a2fb54';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_invoice_vat';
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
    $pane->uuid = '63afe46e-2eeb-ba04-fd1f-78abd1a2fb54';
    $display->content['new-63afe46e-2eeb-ba04-fd1f-78abd1a2fb54'] = $pane;
    $display->panels['middle'][1] = 'new-63afe46e-2eeb-ba04-fd1f-78abd1a2fb54';
    $pane = new stdClass();
    $pane->pid = 'new-7822bb6a-cac2-d874-c9f9-be425581b600';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_invoice_total';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7822bb6a-cac2-d874-c9f9-be425581b600';
    $display->content['new-7822bb6a-cac2-d874-c9f9-be425581b600'] = $pane;
    $display->panels['middle'][2] = 'new-7822bb6a-cac2-d874-c9f9-be425581b600';
    $pane = new stdClass();
    $pane->pid = 'new-e17bc5fb-9b15-5c44-7943-be039c07590c';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_currency';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e17bc5fb-9b15-5c44-7943-be039c07590c';
    $display->content['new-e17bc5fb-9b15-5c44-7943-be039c07590c'] = $pane;
    $display->panels['middle'][3] = 'new-e17bc5fb-9b15-5c44-7943-be039c07590c';
    $pane = new stdClass();
    $pane->pid = 'new-1f8e3a81-a109-efe4-adaa-4027a6d0e85e';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_skonto';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'field_collection_table_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '1f8e3a81-a109-efe4-adaa-4027a6d0e85e';
    $display->content['new-1f8e3a81-a109-efe4-adaa-4027a6d0e85e'] = $pane;
    $display->panels['middle'][4] = 'new-1f8e3a81-a109-efe4-adaa-4027a6d0e85e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['invoice_detailed_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'invoice_general_fields';
  $mini->category = 'erpal invoices';
  $mini->admin_title = 'Invoice general fields';
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
  $display->uuid = '828a3f9e-6d4d-17f4-5d37-39fc60a9a1bd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cfebe29b-807a-9494-8525-6887fd5410c0';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_invoice_number';
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
    $pane->uuid = 'cfebe29b-807a-9494-8525-6887fd5410c0';
    $display->content['new-cfebe29b-807a-9494-8525-6887fd5410c0'] = $pane;
    $display->panels['middle'][0] = 'new-cfebe29b-807a-9494-8525-6887fd5410c0';
    $pane = new stdClass();
    $pane->pid = 'new-2b4bddfd-d3bf-5064-892a-ab4b6df79219';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_invoice_date';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2b4bddfd-d3bf-5064-892a-ab4b6df79219';
    $display->content['new-2b4bddfd-d3bf-5064-892a-ab4b6df79219'] = $pane;
    $display->panels['middle'][1] = 'new-2b4bddfd-d3bf-5064-892a-ab4b6df79219';
    $pane = new stdClass();
    $pane->pid = 'new-9d089a31-71b0-90b4-c5bf-4690bf70aaf3';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_credit_period';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '9d089a31-71b0-90b4-c5bf-4690bf70aaf3';
    $display->content['new-9d089a31-71b0-90b4-c5bf-4690bf70aaf3'] = $pane;
    $display->panels['middle'][2] = 'new-9d089a31-71b0-90b4-c5bf-4690bf70aaf3';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['invoice_general_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'invoice_header_fields';
  $mini->category = 'erpal invoices';
  $mini->admin_title = 'Invoice header fields';
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
  $display->uuid = 'e30b8b8f-8f15-26a4-b5b6-83c4b5713d69';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ca90470a-aa90-4fe4-11d0-319681af6c0d';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contractor_ref';
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
    $pane->uuid = 'ca90470a-aa90-4fe4-11d0-319681af6c0d';
    $display->content['new-ca90470a-aa90-4fe4-11d0-319681af6c0d'] = $pane;
    $display->panels['middle'][0] = 'new-ca90470a-aa90-4fe4-11d0-319681af6c0d';
    $pane = new stdClass();
    $pane->pid = 'new-9fcc81c9-4a39-8884-c9c0-99674f934942';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9fcc81c9-4a39-8884-c9c0-99674f934942';
    $display->content['new-9fcc81c9-4a39-8884-c9c0-99674f934942'] = $pane;
    $display->panels['middle'][1] = 'new-9fcc81c9-4a39-8884-c9c0-99674f934942';
    $pane = new stdClass();
    $pane->pid = 'new-b072fd10-2fc7-8054-415b-906d96054654';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_invoice_address_id';
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
    $pane->uuid = 'b072fd10-2fc7-8054-415b-906d96054654';
    $display->content['new-b072fd10-2fc7-8054-415b-906d96054654'] = $pane;
    $display->panels['middle'][2] = 'new-b072fd10-2fc7-8054-415b-906d96054654';
    $pane = new stdClass();
    $pane->pid = 'new-06407cd0-2be3-0d04-dd34-ab39d571a399';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_shipping_address_id';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '06407cd0-2be3-0d04-dd34-ab39d571a399';
    $display->content['new-06407cd0-2be3-0d04-dd34-ab39d571a399'] = $pane;
    $display->panels['middle'][3] = 'new-06407cd0-2be3-0d04-dd34-ab39d571a399';
    $pane = new stdClass();
    $pane->pid = 'new-592543ac-fd36-8324-9dd1-9e3bf8bcf879';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_payment_date';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '592543ac-fd36-8324-9dd1-9e3bf8bcf879';
    $display->content['new-592543ac-fd36-8324-9dd1-9e3bf8bcf879'] = $pane;
    $display->panels['middle'][4] = 'new-592543ac-fd36-8324-9dd1-9e3bf8bcf879';
    $pane = new stdClass();
    $pane->pid = 'new-595d521e-338c-a414-e5c7-c8e906511f77';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_payed';
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
        'click_to_edit' => 1,
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '595d521e-338c-a414-e5c7-c8e906511f77';
    $display->content['new-595d521e-338c-a414-e5c7-c8e906511f77'] = $pane;
    $display->panels['middle'][5] = 'new-595d521e-338c-a414-e5c7-c8e906511f77';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['invoice_header_fields'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'invoice_pdf';
  $mini->category = 'erpal invoices';
  $mini->admin_title = 'Invoice PDF';
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
  $display->uuid = '68ddb69e-97fb-faa4-2994-c0d33aaefc68';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-69db3e21-e49e-0684-f922-d169a8bbff25';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '69db3e21-e49e-0684-f922-d169a8bbff25';
    $display->content['new-69db3e21-e49e-0684-f922-d169a8bbff25'] = $pane;
    $display->panels['middle'][0] = 'new-69db3e21-e49e-0684-f922-d169a8bbff25';
    $pane = new stdClass();
    $pane->pid = 'new-8da96c7c-0f2b-4eb4-fdc4-1373c6b2275e';
    $pane->panel = 'middle';
    $pane->type = 'invoice_recreate_link';
    $pane->subtype = 'invoice_recreate_link';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8da96c7c-0f2b-4eb4-fdc4-1373c6b2275e';
    $display->content['new-8da96c7c-0f2b-4eb4-fdc4-1373c6b2275e'] = $pane;
    $display->panels['middle'][1] = 'new-8da96c7c-0f2b-4eb4-fdc4-1373c6b2275e';
    $pane = new stdClass();
    $pane->pid = 'new-de093428-54ee-3c64-49e6-394b4d16305a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_invoice_exported';
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
    $pane->uuid = 'de093428-54ee-3c64-49e6-394b4d16305a';
    $display->content['new-de093428-54ee-3c64-49e6-394b4d16305a'] = $pane;
    $display->panels['middle'][2] = 'new-de093428-54ee-3c64-49e6-394b4d16305a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['invoice_pdf'] = $mini;

  return $export;
}
