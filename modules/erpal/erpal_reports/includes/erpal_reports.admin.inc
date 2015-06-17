<?php

/**
 * @file
 * Provides basic report management functionality.
 */

/**
 * Generates the reports type editing form.
 */
function erpal_reports_type_form($form, &$form_state, $erpal_reports_type, $op = 'edit') {

  if ($op == 'clone') {
    $erpal_reports_type->label .= ' (cloned)';
    $erpal_reports_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $erpal_reports_type->name,
    '#description' => t('The human-readable name of this reports type.'),
    '#required' => TRUE,
    '#size' => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($erpal_reports_type->type) ? $erpal_reports_type->type : '',
    '#maxlength' => 32,    
    '#machine_name' => array(
      'exists' => 'erpal_reports_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this reports type. It must only contain lowercase letters, numbers, and underscores.'),
  );
  
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save reports type'),
    '#weight' => 40,
  );

  if ($op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete reports type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('erpal_reports_type_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * Submit handler for creating/editing erpal_reports_type.
 */
function erpal_reports_type_form_submit(&$form, &$form_state) {
  $erpal_reports_type = entity_ui_form_submit_build_entity($form, $form_state);
  $erpal_reports_type->name = $erpal_reports_type->label;
  // Save and go back.
  $erpal_reports_type->save();

  // Redirect user back to list of reports types.
  $form_state['redirect'] = 'admin/structure/erpal/report-types';
}

/**
 * Submit handler for deletion button for erpal_reports_type.
 */
function erpal_reports_type_form_submit_delete(&$form, &$form_state) {
  variable_del('reports_' . $form_state['erpal_reports_type']->type);
  $form_state['redirect'] = 'admin/erpal/reports-types/manage/' . $form_state['erpal_reports_type']->type . '/delete';
}
