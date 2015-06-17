<?php
/**
 * @file
 * erpal_book.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_book_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_book_form_basics|node|erpal_book|form';
  $field_group->group_name = 'group_book_form_basics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_book';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_book_tags',
      2 => 'field_is_template',
      3 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '-label-document',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_book_form_basics|node|erpal_book|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_book_form_contact|node|erpal_book|form';
  $field_group->group_name = 'group_book_form_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_book';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '5',
    'children' => array(
      0 => 'field_address_id',
      1 => 'field_contact_ref',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact',
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
  $export['group_book_form_contact|node|erpal_book|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_book_form_files|node|erpal_book|form';
  $field_group->group_name = 'group_book_form_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_book';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '6',
    'children' => array(
      0 => 'field_files_ref',
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
  $export['group_book_form_files|node|erpal_book|form'] = $field_group;

  return $export;
}
