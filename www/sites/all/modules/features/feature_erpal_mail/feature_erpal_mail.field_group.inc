<?php
/**
 * @file
 * feature_erpal_mail.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function feature_erpal_mail_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mails|node|erpal_crm_activity|form';
  $field_group->group_name = 'group_mails';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_crm_activity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mails',
    'weight' => '12',
    'children' => array(
      0 => 'field_mails',
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
  $export['group_mails|node|erpal_crm_activity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mails|node|erpal_task|form';
  $field_group->group_name = 'group_mails';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'erpal_task';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mails',
    'weight' => '20',
    'children' => array(
      0 => 'field_mails',
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
  $export['group_mails|node|erpal_task|form'] = $field_group;

  return $export;
}
