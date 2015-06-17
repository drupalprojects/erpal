<?php

/**
* @file This file contains all functions for migration data after updates where the user has the choice wether to process them or not
*/

/**
* User should confirm the deletion of fields
*/
function erpal_basic_helper_migrate_remove_contact_fields_confirm_form() {
  $path = ''; //redirect to the frontpage
  $question = t('Do you want to remove the following fields?');
  $fields = _erpal_basic_helper_migrate_fields();

  $field_list = theme('item_list', array('items' => $fields));
  $description = t('These fields will be removed from the contact node type: !field_list', array('!field_list' => $field_list));
  $form = array();
  $form = confirm_form($form, $question, $path, $description);
  return $form;
}

/**
* submit handler for field delete confirm form
*/
function erpal_basic_helper_migrate_remove_contact_fields_confirm_form_submit($form, &$form_state) {
  _erpal_basic_helper_migrate_remove_contact_fields();
  drupal_set_message('The fields have been removed from the contact node type.');
  $form_state['redirect'] = '';
}

/**
* Remove unused field instances
*/
function _erpal_basic_helper_migrate_remove_contact_fields() {
  //remove field instance we don't need any more
  $fields = _erpal_basic_helper_migrate_fields();
  foreach ($fields as $field_name) {
    $instance = field_info_instance('node', $field_name, 'erpal_contact');
    field_delete_instance($instance);
  }
  
  //delete communication field group
  $group = field_group_load_field_group('group_communication', 'node', 'erpal_contact', 'form');
  if ($group)
    ctools_export_crud_delete('field_group', $group);
  
  $group = field_group_load_field_group('group_weblinks', 'node', 'erpal_contact', 'form');
  if ($group)
    ctools_export_crud_delete('field_group', $group);
}

/**
* Returns fields to be removed
*/
function _erpal_basic_helper_migrate_fields() {
  return array('field_xing', 'field_website', 'field_facebook', 'field_twitter', 'field_google_plus', 'field_fax', 'field_email', 'field_phone', 'field_skype');
}