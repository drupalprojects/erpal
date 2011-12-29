<?php
/**
 * @file
 * erpal_docs_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function erpal_docs_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass;
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_files|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '14',
    'children' => array(
      0 => 'field_asset_files',
      1 => 'field_file',
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
  $export['group_files|node|erpal_crm_activity|form'] = $field_group;

  return $export;
}
