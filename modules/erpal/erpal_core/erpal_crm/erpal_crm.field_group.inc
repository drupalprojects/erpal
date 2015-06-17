<?php
/**
 * @file
 * erpal_crm.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_crm_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_form_basic|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_activity_form_basic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_account_manager',
      1 => 'field_customer_ref',
      2 => 'field_order_number_extern',
      3 => 'field_order_number_intern',
      4 => 'field_activity_status_term',
      5 => 'field_activity_origin',
      6 => 'field_activity_lost_reasons',
      7 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-activity',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_activity_form_basic|node|erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_form_body|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_activity_form_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '5',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Body',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-body',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_activity_form_body|node|erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_form_contacts|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_activity_form_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '2',
    'children' => array(
      0 => 'field_contacts_ref',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contacts',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-contacts',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_activity_form_contacts|node|erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_form_files|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_activity_form_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '4',
    'children' => array(
      0 => 'field_asset_files',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-file',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_activity_form_files|node|erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_activity_form_next_contact|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_activity_form_next_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Next Contact-Date',
    'weight' => '1',
    'children' => array(
      0 => 'field_next_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Next Contact-Date',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-next-contact',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_activity_form_next_contact|node|erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chance|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_chance';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Chance and financials',
    'weight' => '3',
    'children' => array(
      0 => 'field_chance',
      1 => 'field_volume',
      2 => 'field_expected_date',
      3 => 'field_service_categories',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Chance and financials',
      'instance_settings' => array(
        'required_fields' => 1,
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
  $export['group_chance|node|erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comment_data|comment|comment_node_erpal_crm_activity|form';
  $field_group->group_name = 'group_comment_data';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Comment Data',
    'weight' => '8',
    'children' => array(
      0 => 'group_comment_details',
      1 => 'group_comment',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_comment_data|comment|comment_node_erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comment_details|comment|comment_node_erpal_crm_activity|form';
  $field_group->group_name = 'group_comment_details';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_comment_data';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '11',
    'children' => array(
      0 => 'comment_alter_field_chance',
      1 => 'comment_alter_field_contacts_ref',
      2 => 'comment_alter_field_volume',
      3 => 'comment_alter_field_expected_date',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_comment_details|comment|comment_node_erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_comment|comment|comment_node_erpal_crm_activity|form';
  $field_group->group_name = 'group_comment';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_comment_data';
  $field_group->data = array(
    'label' => 'Comment',
    'weight' => '8',
    'children' => array(
      0 => 'comment_body',
      1 => 'comment_alter_field_next_contact',
      2 => 'comment_alter_field_activity_status_term',
      3 => 'comment_alter_field_activity_lost_reasons',
      4 => 'group_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_comment|comment|comment_node_erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|comment|comment_node_erpal_crm_activity|form';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_comment';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '6',
    'children' => array(
      0 => 'comment_alter_field_asset_files',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Files',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-files field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_files|comment|comment_node_erpal_crm_activity|form'] = $field_group;

  return $export;
}
