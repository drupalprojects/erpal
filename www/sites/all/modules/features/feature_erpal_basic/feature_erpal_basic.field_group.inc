<?php
/**
 * @file
 * feature_erpal_basic.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_erpal_basic_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_weblinks|node|erpal_contact|form';
  $field_group->group_name = 'group_weblinks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_contact';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Weblinks',
    'weight' => '9',
    'children' => array(
      0 => 'field_website',
      1 => 'field_xing',
      2 => 'field_facebook',
      3 => 'field_twitter',
    ),
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
  $export['group_weblinks|node|erpal_contact|form'] = $field_group;

  return $export;
}
