<?php
/**
 * @file
 * erpal_contract_ui.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_contract_ui_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'contract_basic_info_panel';
  $mini->category = 'ERPAL contract';
  $mini->admin_title = 'Contract basic info panel';
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
      'identifier' => 'Contract payment field collection (field_contract_payment) from node (erpal_contract)',
      'keyword' => 'Field collection',
      'name' => 'field_collection_from_field:node:erpal_contract:field_contract_payment',
      'delta' => '0',
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
  $display->uuid = '86d10a9f-6007-3ce4-a92f-b0a1fe16733e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ec890e93-8db0-6564-595b-1792ac88fad8';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>Contract between</p>
',
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
    $pane->uuid = 'ec890e93-8db0-6564-595b-1792ac88fad8';
    $display->content['new-ec890e93-8db0-6564-595b-1792ac88fad8'] = $pane;
    $display->panels['middle'][0] = 'new-ec890e93-8db0-6564-595b-1792ac88fad8';
    $pane = new stdClass();
    $pane->pid = 'new-0d02216d-0378-2e94-e51f-afeb8a125736';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_contractor_ref';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'admin_title' => '',
      'title' => '',
      'body' => ':',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0d02216d-0378-2e94-e51f-afeb8a125736';
    $display->content['new-0d02216d-0378-2e94-e51f-afeb8a125736'] = $pane;
    $display->panels['middle'][1] = 'new-0d02216d-0378-2e94-e51f-afeb8a125736';
    $pane = new stdClass();
    $pane->pid = 'new-acc436d1-5e82-b454-a941-3c0dc292ea41';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>and</p>
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'acc436d1-5e82-b454-a941-3c0dc292ea41';
    $display->content['new-acc436d1-5e82-b454-a941-3c0dc292ea41'] = $pane;
    $display->panels['middle'][2] = 'new-acc436d1-5e82-b454-a941-3c0dc292ea41';
    $pane = new stdClass();
    $pane->pid = 'new-81955a6e-641c-c4a4-79a8-fdc40edbfe0b';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_customer_ref';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
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
    $pane->uuid = '81955a6e-641c-c4a4-79a8-fdc40edbfe0b';
    $display->content['new-81955a6e-641c-c4a4-79a8-fdc40edbfe0b'] = $pane;
    $display->panels['middle'][3] = 'new-81955a6e-641c-c4a4-79a8-fdc40edbfe0b';
    $pane = new stdClass();
    $pane->pid = 'new-223268a6-db16-5874-f598-0368a7c3830b';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => ':',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '223268a6-db16-5874-f598-0368a7c3830b';
    $display->content['new-223268a6-db16-5874-f598-0368a7c3830b'] = $pane;
    $display->panels['middle'][4] = 'new-223268a6-db16-5874-f598-0368a7c3830b';
    $pane = new stdClass();
    $pane->pid = 'new-d2234ed4-6a52-4e74-2936-ef9fd9816082';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_price';
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
        'prefix_suffix' => 0,
      ),
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'd2234ed4-6a52-4e74-2936-ef9fd9816082';
    $display->content['new-d2234ed4-6a52-4e74-2936-ef9fd9816082'] = $pane;
    $display->panels['middle'][5] = 'new-d2234ed4-6a52-4e74-2936-ef9fd9816082';
    $pane = new stdClass();
    $pane->pid = 'new-973b9aac-f296-c8a4-2146-77378fda7052';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_currency';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
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
    $pane->uuid = '973b9aac-f296-c8a4-2146-77378fda7052';
    $display->content['new-973b9aac-f296-c8a4-2146-77378fda7052'] = $pane;
    $display->panels['middle'][6] = 'new-973b9aac-f296-c8a4-2146-77378fda7052';
    $pane = new stdClass();
    $pane->pid = 'new-b3549172-6f91-f614-6d67-33cdbf4b465f';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p>per month with VAT</p>
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'b3549172-6f91-f614-6d67-33cdbf4b465f';
    $display->content['new-b3549172-6f91-f614-6d67-33cdbf4b465f'] = $pane;
    $display->panels['middle'][7] = 'new-b3549172-6f91-f614-6d67-33cdbf4b465f';
    $pane = new stdClass();
    $pane->pid = 'new-a556ba2e-bfb5-5af4-0571-6a8299b89bd7';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_vat_rate';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'a556ba2e-bfb5-5af4-0571-6a8299b89bd7';
    $display->content['new-a556ba2e-bfb5-5af4-0571-6a8299b89bd7'] = $pane;
    $display->panels['middle'][8] = 'new-a556ba2e-bfb5-5af4-0571-6a8299b89bd7';
    $pane = new stdClass();
    $pane->pid = 'new-0a22bf92-ecc1-5f14-698e-9f551db206f1';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_payment_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '0a22bf92-ecc1-5f14-698e-9f551db206f1';
    $display->content['new-0a22bf92-ecc1-5f14-698e-9f551db206f1'] = $pane;
    $display->panels['middle'][9] = 'new-0a22bf92-ecc1-5f14-698e-9f551db206f1';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['contract_basic_info_panel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'contract_basic_panel';
  $mini->category = 'ERPAL contract';
  $mini->admin_title = 'Contract basic panel';
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
      'identifier' => 'Contract payment field collection (field_contract_payment) from node (erpal_contract)',
      'keyword' => 'Field collection',
      'name' => 'field_collection_from_field:node:erpal_contract:field_contract_payment',
      'delta' => '0',
      'context' => 'requiredcontext_entity:node_1',
      'id' => 1,
    ),
    1 => array(
      'identifier' => 'Node from Field collection item (on Field collection item: Contractor [field_contractor_ref])',
      'keyword' => 'contractor',
      'name' => 'entity_from_field:field_contractor_ref-field_collection_item-node',
      'delta' => 0,
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
      'id' => 1,
    ),
    2 => array(
      'identifier' => 'Node from Field collection item (on Field collection item: Customer [field_customer_ref])',
      'keyword' => 'customer',
      'name' => 'entity_from_field:field_customer_ref-field_collection_item-node',
      'delta' => 0,
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
      'id' => 1,
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
  $display->uuid = '5be259fd-2580-35e4-7d52-c58f8aa20b37';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ebb92370-24b0-6534-7d67-034c998ac7a0';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'contract_basic_info_panel';
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
    $pane->uuid = 'ebb92370-24b0-6534-7d67-034c998ac7a0';
    $display->content['new-ebb92370-24b0-6534-7d67-034c998ac7a0'] = $pane;
    $display->panels['middle'][0] = 'new-ebb92370-24b0-6534-7d67-034c998ac7a0';
    $pane = new stdClass();
    $pane->pid = 'new-71a3e750-c09f-2bc4-cd24-27a1975cb3cb';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contract_type';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '71a3e750-c09f-2bc4-cd24-27a1975cb3cb';
    $display->content['new-71a3e750-c09f-2bc4-cd24-27a1975cb3cb'] = $pane;
    $display->panels['middle'][1] = 'new-71a3e750-c09f-2bc4-cd24-27a1975cb3cb';
    $pane = new stdClass();
    $pane->pid = 'new-2a4c9f57-2dab-9534-d58d-95844f0ec295';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_service_category_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
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
    $pane->uuid = '2a4c9f57-2dab-9534-d58d-95844f0ec295';
    $display->content['new-2a4c9f57-2dab-9534-d58d-95844f0ec295'] = $pane;
    $display->panels['middle'][2] = 'new-2a4c9f57-2dab-9534-d58d-95844f0ec295';
    $pane = new stdClass();
    $pane->pid = 'new-a29f3847-4e2b-7774-99ff-a02f1d8518d8';
    $pane->panel = 'middle';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a29f3847-4e2b-7774-99ff-a02f1d8518d8';
    $display->content['new-a29f3847-4e2b-7774-99ff-a02f1d8518d8'] = $pane;
    $display->panels['middle'][3] = 'new-a29f3847-4e2b-7774-99ff-a02f1d8518d8';
    $pane = new stdClass();
    $pane->pid = 'new-3117ca07-f0d2-c5b4-9511-43020505b70a';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Cancelation description',
      'title' => '',
      'body' => 'The cancelation period for %contractor:title is %node:field_cancelation_period_con %node:field_cancelation_period_unit.
The cancelation period for %customer:title is %node:field_cancelation_period %node:field_cancelation_period_unit.
',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '3117ca07-f0d2-c5b4-9511-43020505b70a';
    $display->content['new-3117ca07-f0d2-c5b4-9511-43020505b70a'] = $pane;
    $display->panels['middle'][4] = 'new-3117ca07-f0d2-c5b4-9511-43020505b70a';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['contract_basic_panel'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'contract_time_information';
  $mini->category = 'ERPAL contract';
  $mini->admin_title = 'Contract time information';
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
      'identifier' => 'Contract payment field collection (field_contract_payment) from node (erpal_contract)',
      'keyword' => 'Field collection',
      'name' => 'field_collection_from_field:node:erpal_contract:field_contract_payment',
      'delta' => '0',
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
  $display->uuid = '1680f32c-46c9-d304-d180-6ce9c895fd07';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a78ee58f-7895-ebd4-e584-28085c38460b';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_payment_period';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
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
    $pane->uuid = 'a78ee58f-7895-ebd4-e584-28085c38460b';
    $display->content['new-a78ee58f-7895-ebd4-e584-28085c38460b'] = $pane;
    $display->panels['middle'][0] = 'new-a78ee58f-7895-ebd4-e584-28085c38460b';
    $pane = new stdClass();
    $pane->pid = 'new-7117ce59-d12d-41d4-6514-004e1b4abfac';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_last_booking_date';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
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
    $pane->uuid = '7117ce59-d12d-41d4-6514-004e1b4abfac';
    $display->content['new-7117ce59-d12d-41d4-6514-004e1b4abfac'] = $pane;
    $display->panels['middle'][1] = 'new-7117ce59-d12d-41d4-6514-004e1b4abfac';
    $pane = new stdClass();
    $pane->pid = 'new-32d3f114-8351-89d4-d57f-ffa2af18d0f6';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_next_booking_date';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_contract_payment_1',
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
    $pane->uuid = '32d3f114-8351-89d4-d57f-ffa2af18d0f6';
    $display->content['new-32d3f114-8351-89d4-d57f-ffa2af18d0f6'] = $pane;
    $display->panels['middle'][2] = 'new-32d3f114-8351-89d4-d57f-ffa2af18d0f6';
    $pane = new stdClass();
    $pane->pid = 'new-a33d8e96-f352-2fb4-91e9-4cba523a135e';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contract_duration';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a33d8e96-f352-2fb4-91e9-4cba523a135e';
    $display->content['new-a33d8e96-f352-2fb4-91e9-4cba523a135e'] = $pane;
    $display->panels['middle'][3] = 'new-a33d8e96-f352-2fb4-91e9-4cba523a135e';
    $pane = new stdClass();
    $pane->pid = 'new-3add167c-821e-7c94-c11d-74c7a04a42ec';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_repeating_duration';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '3add167c-821e-7c94-c11d-74c7a04a42ec';
    $display->content['new-3add167c-821e-7c94-c11d-74c7a04a42ec'] = $pane;
    $display->panels['middle'][4] = 'new-3add167c-821e-7c94-c11d-74c7a04a42ec';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['contract_time_information'] = $mini;

  return $export;
}
