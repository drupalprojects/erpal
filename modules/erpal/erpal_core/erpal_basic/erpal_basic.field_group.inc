<?php
/**
 * @file
 * erpal_basic.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_basic_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_addresses|node|erpal_contact|form';
  $field_group->group_name = 'group_addresses';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Addresses',
    'weight' => '3',
    'children' => array(
      0 => 'field_addresses',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Addresses',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-address',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_addresses|node|erpal_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_banking|node|erpal_contact|form';
  $field_group->group_name = 'group_banking';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banking Accounts',
    'weight' => '4',
    'children' => array(
      0 => 'field_bank_accounts',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banking Accounts',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-banking',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_banking|node|erpal_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basics|node|erpal_contact|form';
  $field_group->group_name = 'group_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_birthday',
      1 => 'field_company_name',
      2 => 'field_contact_tags',
      3 => 'field_contact_type',
      4 => 'field_customer_category',
      5 => 'field_firstname',
      6 => 'field_gender',
      7 => 'field_lastname',
      8 => 'field_vat_number',
      9 => 'field_activity_origin',
      10 => 'field_languages',
      11 => 'field_target_audience',
      12 => 'field_salutation',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basic Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-user',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_basics|node|erpal_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_communication|node|erpal_contact|form';
  $field_group->group_name = 'group_communication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Communication',
    'weight' => '2',
    'children' => array(
      0 => 'field_communication',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Communication',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-communication',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_communication|node|erpal_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|node|erpal_contact|form';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '6',
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
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_files|node|erpal_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_legal|node|erpal_contact|form';
  $field_group->group_name = 'group_legal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Legal information',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_legal|node|erpal_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notes|node|erpal_contact|form';
  $field_group->group_name = 'group_notes';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notes',
    'weight' => '5',
    'children' => array(
      0 => 'field_legal_other',
      1 => 'body',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Notes',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-info',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_notes|node|erpal_contact|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relations|node|erpal_contact|form';
  $field_group->group_name = 'group_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relations',
    'weight' => '1',
    'children' => array(
      0 => 'field_contact_relations',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Relations',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-link',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_relations|node|erpal_contact|form'] = $field_group;

  return $export;
}
