<?php
/**
 * @file
 * Various page callbacks.
 */

/**
 * Callback for viewing all Erpal Reports.
 */
function erpal_reports_view_all() {
  // @todo - here we are using view - we need to define it also in generator.
  return views_embed_view('erpal_reports') . '';
}

/**
 * Callback for adding new Erpal Reports.
 *
 * @type string
 *   Entity bundle type.
 */
function erpal_reports_add($type) {
  $erpal_reports = erpal_reports_create(array('type' => $type));
  return drupal_get_form('erpal_reports_form', $erpal_reports);
}

/**
 * Callback for single Erpal Reports view.
 */
function erpal_reports_view($erpal_reports) {
  drupal_set_title(entity_label('erpal_reports', $erpal_reports));
  $report = entity_view('erpal_reports', array($erpal_reports->identifier() => $erpal_reports), 'full', NULL, TRUE);
}

/**
 * Erpal Reports form.
 */
function erpal_reports_form($form, &$form_state, $erpal_reports) {
  $form_state['erpal_reports'] = $erpal_reports;
  $is_new = !empty($erpal_reports->is_new);

  $wrapper = entity_metadata_wrapper($erpal_reports->entityType(), $erpal_reports);

  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => $wrapper->title->value(),
    '#required' => TRUE,
  );

  $form['dirty'] = array(
      '#title' => t('Dirty'),
      '#type' => 'checkbox',
      '#default_value' => $wrapper->dirty->value(),      
  );

  // Attach all fields and also sort all form items by weight.
  field_attach_form('erpal_reports', $erpal_reports, $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => $is_new ? t('Create') : t('Update'),
  );
  if (!$is_new) {
    $form['actions']['delete'] = array(
      '#type' => 'markup',      
      '#markup' => l(t('Delete'), 'erpal/reports/'.$erpal_reports->id.'/delete'),    
    );
  }

  return $form;
}

/**
 * Erpal Reports form submit handler.
 */
function erpal_reports_form_submit($form, &$form_state) {
  $erpal_reports = $form_state['erpal_reports'];
  $is_new = !empty($erpal_reports->is_new);

  form_state_values_clean($form_state);
  entity_form_submit_build_entity('erpal_reports', $erpal_reports, $form, $form_state);
  erpal_reports_save($erpal_reports);

  $uri = entity_uri('erpal_reports', $erpal_reports);
  $form_state['redirect'] = $uri['path'];

  if ($is_new) {
    drupal_set_message(t('Erpal Reports created.'));
  }
  else {
    drupal_set_message(t('Erpal Reports updated.'));
  }
}

/**
 * Erpal Reports delete form.
 */
function erpal_reports_delete_form($form, &$form_state, ErpalReports $erpal_reports) {
  $form_state['erpal_reports'] = $erpal_reports;

  drupal_set_title(t('Are you sure you want to remove !erpal_reports Erpal Reports? This action can not be undone.',
    array('!erpal_reports' => $erpal_reports->label())));

  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );  
  
  return $form;
}

/**
 * Delete Erpal Reports from submit handler.
 */
function erpal_reports_delete_form_submit($form, &$form_state) {
  $erpal_reports = $form_state['erpal_reports'];
  erpal_reports_delete($erpal_reports);
  drupal_set_message(t('ERPAL Reports %erpal_reports removed.', array('%erpal_reports' => $erpal_reports->label())));
  $form_state['redirect'] = 'reports/dashboard';  
}

/**
 * Configuration page callback.
 */
function erpal_reports_config($form) {
  $form = array();

  $form['date_format_erpal_reports_day'] = array(
      '#type' => 'textfield',
      '#title' => t('Date-Scaling Day Format'),
      '#default_value' => variable_get('date_format_erpal_reports_day', 'Y-m-d'),
      '#size' => 5,
      '#maxlength' => 5,
      '#description' => t("The Date Format used to Display Day Date Scaling"),
      '#required' => TRUE,
  );

  $form['date_format_erpal_reports_month'] = array(
      '#type' => 'textfield',
      '#title' => t('Date-Scaling Month Format'),
      '#default_value' => variable_get('date_format_erpal_reports_month', 'Y-m'),
      '#size' => 5,
      '#maxlength' => 5,
      '#description' => t("The Date Format used to Display Month Date Scaling"),
      '#required' => TRUE,
  );

  $form['date_format_erpal_reports_year'] = array(
      '#type' => 'textfield',
      '#title' => t('Date-Scaling Year Format'),
      '#default_value' => variable_get('date_format_erpal_reports_year', 'Y'),
      '#size' => 5,
      '#maxlength' => 5,
      '#description' => t("The Date Format used to Display Year Date Scaling"),
      '#required' => TRUE,
  );

  $form['#submit'] = array('erpal_reports_config_submit');

  return system_settings_form($form);
}
