<?php
/**
 * @file
 * erpal_contract_projects.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function erpal_contract_projects_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'contract_budget_information';
  $mini->category = 'ERPAL contract';
  $mini->admin_title = 'Contract budget information';
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
      'identifier' => 'Budget booking field collection (field_budget_booking) from node (erpal_contract)',
      'keyword' => 'Field collection',
      'name' => 'field_collection_from_field:node:erpal_contract:field_budget_booking',
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
  $display->uuid = '1351f4dd-b4b5-f9f4-e1f7-3d420126646c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-49ec9c27-6b61-a484-7d92-26caa9f74d8b';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'contract_budget_time_information';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'requiredcontext_entity:node_1',
      ),
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
    $pane->uuid = '49ec9c27-6b61-a484-7d92-26caa9f74d8b';
    $display->content['new-49ec9c27-6b61-a484-7d92-26caa9f74d8b'] = $pane;
    $display->panels['middle'][0] = 'new-49ec9c27-6b61-a484-7d92-26caa9f74d8b';
    $pane = new stdClass();
    $pane->pid = 'new-b8765487-8b0e-e1f4-39bc-cebfe4854779';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_budget_destination';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_typed_label',
      'delta_limit' => 0,
      'delta_offset' => 0,
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_budget_booking_1',
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
    $pane->uuid = 'b8765487-8b0e-e1f4-39bc-cebfe4854779';
    $display->content['new-b8765487-8b0e-e1f4-39bc-cebfe4854779'] = $pane;
    $display->panels['middle'][1] = 'new-b8765487-8b0e-e1f4-39bc-cebfe4854779';
    $pane = new stdClass();
    $pane->pid = 'new-6ba50499-52f0-3f44-1166-2768450dd80d';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_budgets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => 0,
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'links' => 1,
        'link' => 1,
      ),
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_budget_booking_1',
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
    $pane->uuid = '6ba50499-52f0-3f44-1166-2768450dd80d';
    $display->content['new-6ba50499-52f0-3f44-1166-2768450dd80d'] = $pane;
    $display->panels['middle'][2] = 'new-6ba50499-52f0-3f44-1166-2768450dd80d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['contract_budget_information'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'contract_budget_time_information';
  $mini->category = 'ERPAL contract';
  $mini->admin_title = 'Contract budget time information';
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
      'identifier' => 'Budget booking field collection (field_budget_booking) from node (erpal_contract)',
      'keyword' => 'Field collection',
      'name' => 'field_collection_from_field:node:erpal_contract:field_budget_booking',
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
  $display->uuid = 'd03fcc84-8130-c2c4-9db3-2b4b64c7b9d0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d1fae3a2-8f4a-6a34-0950-fec18543aae1';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_budget_period';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_budget_booking_1',
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
    $pane->uuid = 'd1fae3a2-8f4a-6a34-0950-fec18543aae1';
    $display->content['new-d1fae3a2-8f4a-6a34-0950-fec18543aae1'] = $pane;
    $display->panels['middle'][0] = 'new-d1fae3a2-8f4a-6a34-0950-fec18543aae1';
    $pane = new stdClass();
    $pane->pid = 'new-adeb34be-7229-5e14-0de8-0bb962460641';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_budget_booking_1',
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
    $pane->uuid = 'adeb34be-7229-5e14-0de8-0bb962460641';
    $display->content['new-adeb34be-7229-5e14-0de8-0bb962460641'] = $pane;
    $display->panels['middle'][1] = 'new-adeb34be-7229-5e14-0de8-0bb962460641';
    $pane = new stdClass();
    $pane->pid = 'new-0f34b0ed-0075-21d4-ddca-2ebe6c9f801a';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_budget_booking_1',
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
    $pane->uuid = '0f34b0ed-0075-21d4-ddca-2ebe6c9f801a';
    $display->content['new-0f34b0ed-0075-21d4-ddca-2ebe6c9f801a'] = $pane;
    $display->panels['middle'][2] = 'new-0f34b0ed-0075-21d4-ddca-2ebe6c9f801a';
    $pane = new stdClass();
    $pane->pid = 'new-4e9c5e55-a4c7-c804-591b-3134d10c3fca';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_expire_period';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_budget_booking_1',
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
    $pane->uuid = '4e9c5e55-a4c7-c804-591b-3134d10c3fca';
    $display->content['new-4e9c5e55-a4c7-c804-591b-3134d10c3fca'] = $pane;
    $display->panels['middle'][3] = 'new-4e9c5e55-a4c7-c804-591b-3134d10c3fca';
    $pane = new stdClass();
    $pane->pid = 'new-e53d3a70-bbd4-c2d4-d934-75557e3929ca';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'field_collection_item:field_budget_hours';
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
      'context' => 'relationship_field_collection_from_field:node:erpal_contract:field_budget_booking_1',
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
    $pane->uuid = 'e53d3a70-bbd4-c2d4-d934-75557e3929ca';
    $display->content['new-e53d3a70-bbd4-c2d4-d934-75557e3929ca'] = $pane;
    $display->panels['middle'][4] = 'new-e53d3a70-bbd4-c2d4-d934-75557e3929ca';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['contract_budget_time_information'] = $mini;

  return $export;
}
