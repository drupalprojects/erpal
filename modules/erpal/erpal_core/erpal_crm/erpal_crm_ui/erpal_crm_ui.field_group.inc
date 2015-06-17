<?php
/**
 * @file
 * erpal_crm_ui.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_crm_ui_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_basics|node|erpal_crm_activity|node_view';
  $field_group->group_name = 'group_activity_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_activity_view';
  $field_group->data = array(
    'label' => 'Basics & Financials',
    'weight' => '22',
    'children' => array(
      0 => 'group_activity_basic',
      1 => 'group_activity_chance',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basics & Financials',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_activity_basics|node|erpal_crm_activity|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_basic|node|erpal_crm_activity|node_view';
  $field_group->group_name = 'group_activity_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_activity_basics';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '16',
    'children' => array(
      0 => 'body',
      1 => 'field_account_manager',
      2 => 'field_activity_origin',
      3 => 'field_activity_status_term',
      4 => 'field_customer_ref',
      5 => 'field_order_number_extern',
      6 => 'field_order_number_intern',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'classes' => '-label-activity',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_activity_basic|node|erpal_crm_activity|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_chance|node|erpal_crm_activity|node_view';
  $field_group->group_name = 'group_activity_chance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_activity_basics';
  $field_group->data = array(
    'label' => 'Chance & Financials',
    'weight' => '17',
    'children' => array(
      0 => 'field_chance',
      1 => 'field_expected_date',
      2 => 'field_volume',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Chance & Financials',
      'instance_settings' => array(
        'classes' => '-label-chance',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_activity_chance|node|erpal_crm_activity|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_contacts|node|erpal_crm_activity|node_view';
  $field_group->group_name = 'group_activity_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_activity_view';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '24',
    'children' => array(
      0 => 'field_contacts_ref',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_activity_contacts|node|erpal_crm_activity|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_files|node|erpal_crm_activity|node_view';
  $field_group->group_name = 'group_activity_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_activity_view';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '25',
    'children' => array(
      0 => 'field_asset_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_activity_files|node|erpal_crm_activity|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_sales|node|erpal_crm_activity|node_view';
  $field_group->group_name = 'group_activity_sales';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_activity_view';
  $field_group->data = array(
    'label' => 'Sales',
    'weight' => '23',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_activity_sales|node|erpal_crm_activity|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_view|node|erpal_crm_activity|node_view';
  $field_group->group_name = 'group_activity_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'node_view';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Activityview',
    'weight' => '0',
    'children' => array(
      0 => 'group_activity_files',
      1 => 'group_activity_basics',
      2 => 'group_activity_contacts',
      3 => 'group_activity_sales',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_activity_view|node|erpal_crm_activity|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_addresses|node|erpal_contact|node_view';
  $field_group->group_name = 'group_contact_addresses';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_contact_view';
  $field_group->data = array(
    'label' => 'Addresses',
    'weight' => '2',
    'children' => array(
      0 => 'field_addresses',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_contact_addresses|node|erpal_contact|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_banking|node|erpal_contact|node_view';
  $field_group->group_name = 'group_contact_banking';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_contact_view';
  $field_group->data = array(
    'label' => 'Banking Accounts',
    'weight' => '4',
    'children' => array(
      0 => 'field_bank_accounts',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_contact_banking|node|erpal_contact|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_basics_content|node|erpal_contact|node_view';
  $field_group->group_name = 'group_contact_basics_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_contact_basics';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '12',
    'children' => array(
      0 => 'body',
      1 => 'field_activity_origin',
      2 => 'field_birthday',
      3 => 'field_communication',
      4 => 'field_company_name',
      5 => 'field_contact_tags',
      6 => 'field_customer_category',
      7 => 'field_firstname',
      8 => 'field_gender',
      9 => 'field_lastname',
      10 => 'field_legal_other',
      11 => 'field_vat_number',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_basics_content|node|erpal_contact|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_basics|node|erpal_contact|node_view';
  $field_group->group_name = 'group_contact_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_contact_view';
  $field_group->data = array(
    'label' => 'Basics & Communication',
    'weight' => '1',
    'children' => array(
      0 => 'group_contact_basics_content',
      1 => 'group_contact_image',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_contact_basics|node|erpal_contact|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_files|node|erpal_contact|node_view';
  $field_group->group_name = 'group_contact_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_contact_view';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '5',
    'children' => array(
      0 => 'field_asset_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_contact_files|node|erpal_contact|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_image|node|erpal_contact|node_view';
  $field_group->group_name = 'group_contact_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_contact_basics';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '11',
    'children' => array(
      0 => 'field_contact_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_image|node|erpal_contact|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_relations|node|erpal_contact|node_view';
  $field_group->group_name = 'group_contact_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'node_view';
  $field_group->parent_name = 'group_contact_view';
  $field_group->data = array(
    'label' => 'Relations',
    'weight' => '3',
    'children' => array(
      0 => 'field_contact_relations',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_contact_relations|node|erpal_contact|node_view'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_view|node|erpal_contact|node_view';
  $field_group->group_name = 'group_contact_view';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'node_view';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contactview',
    'weight' => '0',
    'children' => array(
      0 => 'group_contact_addresses',
      1 => 'group_contact_banking',
      2 => 'group_contact_basics',
      3 => 'group_contact_files',
      4 => 'group_contact_relations',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_contact_view|node|erpal_contact|node_view'] = $field_group;

  return $export;
}
