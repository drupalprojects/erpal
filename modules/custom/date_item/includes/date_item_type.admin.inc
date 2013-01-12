<?php

/**
 * @file
 * Model type editing UI.
 */

/**
 * Generates the model type editing form.
 */
function date_item_type_form($form, &$form_state, $date_item_type, $op = 'edit') {
  if ($op == 'clone') {
    $date_item_type->label .= ' (cloned)';
    $date_item_type->name = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $date_item_type->label,
    '#description' => t('The human-readable name of this date item type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  
  // Machine-readable type name.
  $form['name'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($date_item_type->name) ? $date_item_type->name : '',
    '#maxlength' => 32,
    '#disabled' => ($date_item_type->locked) && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'date_item_get_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this date_item type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save date item type'),
    '#weight' => 40,
  );

  if (!$date_item_type->locked && $op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete date_item type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('date_item_type_form_submit_delete')
    );
  }

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function date_item_type_form_submit(&$form, &$form_state) {
  $date_item_type = entity_ui_form_submit_build_entity($form, $form_state);
  $date_item_type->save();
  $form_state['redirect'] = 'admin/structure/date_item/date_item_types';
}

/**
 * Form API submit callback for the delete button.
 */
function date_item_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/date_item/date_item_types/manage/' . $form_state['date_item_type']->type . '/delete';
}
