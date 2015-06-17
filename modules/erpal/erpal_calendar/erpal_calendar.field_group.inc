<?php
/**
 * @file
 * erpal_calendar.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_calendar_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_form_basics|node|erpal_date|form';
  $field_group->group_name = 'group_date_form_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_date';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '0',
    'children' => array(
      0 => 'field_date_repeat',
      1 => 'field_date_type',
      2 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-date',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_date_form_basics|node|erpal_date|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_form_body|node|erpal_date|form';
  $field_group->group_name = 'group_date_form_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_date';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Body',
    'weight' => '1',
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
  $export['group_date_form_body|node|erpal_date|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_form_contacts|node|erpal_date|form';
  $field_group->group_name = 'group_date_form_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_date';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '3',
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
  $export['group_date_form_contacts|node|erpal_date|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_form_files|node|erpal_date|form';
  $field_group->group_name = 'group_date_form_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_date';
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
  $export['group_date_form_files|node|erpal_date|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_form_participants|node|erpal_date|form';
  $field_group->group_name = 'group_date_form_participants';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_date';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Participants',
    'weight' => '2',
    'children' => array(
      0 => 'field_users',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Participants',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-participants',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_date_form_participants|node|erpal_date|form'] = $field_group;

  return $export;
}
