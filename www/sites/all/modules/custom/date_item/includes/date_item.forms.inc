<?php

/**
 * @file
 * Form definitions and callbacks for date_item.
 */

/**
 * Form callback: create or edit a date_item.
 *
 * @param $date_item
 *   The date_item object to edit or for a create form an empty date_item
 *   object with a node defined.
 */
function date_item_form($form, &$form_state, DateItem $date_item) {
  global $user;
  $form_state['date_item'] = $date_item;

  //Just show the subject if available, but should not be edit
  if ($date_item->src_id) {
    $src_entity = $date_item->src_entity();
    $host_label = entity_label($date_item->src_type, $src_entity);
    $host_uri = entity_uri($date_item->src_type, $src_entity);
    $form['src_id'] = array(
      '#type' => 'item',
      '#prefix' => '<div class="field date_item-entity-link">',
      '#markup' => l($host_label, $host_uri['path']),
      '#suffix' => '</div>',
    );
  } 
  
  $form['removed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Removed'),
    '#default_value' => $date_item->removed,
  );
  
  $date_from = $date_item->date_from ? $budget->date_from : time();
  $date_till = $date_item->date_till;

  $format = _date_item_get_date_format(false);
  $popup_default_format = 'Y-m-d H:i:s';
  $form['date_from'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('Date from'),
    '#default_value' => $date_from ? date($popup_default_format, $date_from) : date($date_from),
    '#required' => TRUE,
  );
  
  $form['date_till'] = array(
    '#type' => 'date_popup',
    '#date_format' => $format,
    '#title' => t('Available till'),
    '#default_value' => $date_till ? date($popup_default_format, $date_till) : date($date_till),
    '#required' => FALSE,
  );

  
  field_attach_form('date_item', $date_item, $form, $form_state);

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  // add a delete button for existing date_item
  if (isset($date_item->date_item_id) && entity_access('delete', 'date_item', $date_item)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('date_item_form_delete_submit'),
      "#limit_validation_errors" => array()
    );
  }

  if ($date_item->entity) {
    $uri = entity_uri($date_item->entity_type, $date_item->entity);
    $form['actions']['cancel'] = array(
      '#type' => 'link',
      '#title' => t('Cancel'),
      '#href' => $uri['path'],
    );
  }

  return $form;
}

/**
 * Validation callback for date_item_form().
 */
function date_item_form_validate($form, &$form_state) {
  $date_item = $form_state['date_item'];

  //date from must be bevore date till
  if ($date_item->date_till && $date_item->date_from > $date_item->date_till) {
    form_set_error('date_till', t('Date till must be greater or equal than date from.'));
  }

  // Notify field widgets to validate their data.
  field_attach_form_validate('date_item', $date_item, $form, $form_state);
}

/**
 * Submit callback for date_item_form().
 */
function date_item_form_submit($form, &$form_state) {
  $date_item = $form_state['date_item'];

  // Set the date_item's uid
  if (!isset($date_item->date_item_id)) {
    $date_item->uid = $GLOBALS['user']->uid;
  }

  $date_item->removed = $form_state['values']['removed'];
  $date_item->date_from = $form_state['values']['date_from'];
  $date_item->date_till = $form_state['values']['date_till'];
  
  

  // Notify field widgets.
  field_attach_submit('date_item', $date_item, $form, $form_state);

  // Save the date_item and redirect.
  if (date_item_save($date_item)) {
    drupal_set_message(t('date item has been saved.'));

    // Redirect to date_item
    if (entity_access('view', 'date_item', $date_item)) {
      $uri = entity_uri('date_item', $date_item);
      $form_state['redirect'] = $uri['path'];
    }
    // Redirect to host entity
    else if (entity_access('view', $date_item->entity_type, $date_item->entity)) {
      $uri = entity_uri($date_item->entity_type, $date_item->entity);
      $form_state['redirect'] = $uri['path'];
    }
  }
  else {
    drupal_set_message(t('There was a problem submitting your date item.'));
  }
}

/**
 * Button submit function: handle the 'Delete' button on the node form.
 */
function date_item_form_delete_submit($form, &$form_state) {
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $date_item = $form_state['date_item'];
  $form_state['redirect'] = array(
    'date_item/' .
      $date_item->date_item_id . '/delete',
    array('query' => $destination),
  );
}

/**
 * Menu callback -- ask for confirmation of node deletion
 */
function date_item_delete_confirm($form, &$form_state, $date_item) {
  // Always provide entity id in the same form key as in the entity edit form.
  $form['date_item'] = array(
    '#type' => 'value',
    '#value' => $date_item,
  );
  return confirm_form($form,
    t('Are you sure you want to delete date_item %title?',
      array('%title' => $date_item->defaultLabel())
    ),
    'date_item/' . $date_item->date_item_id,
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Execute node deletion
 */
function date_item_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $date_item = $form_state['values']['date_item'];
    date_item_delete_multiple(array($date_item->date_item_id));
    watchdog('date_item', 'date_item %id deleted.', array('%id' => $date_item->date_item_id));
    drupal_set_message(t('date_item %id has been deleted.', array('%id' => $date_item->date_item_id)));

    $uri = entity_uri($date_item->entity_type, $date_item->entity);
    $form_state['redirect'] = $uri['path'];
  }
}



/**
 * Return a form for an entity's date_item settings.
 *
 * @param array $form
 * @param array $form_state
 * @param object $entity_type
 * @param object $entity
 *
 * @return array $form
 *
 * @see hook_date_item_entity_settings().
 */
function date_item_entity_settings_form($form, &$form_state, $settings, $entity_type = NULL, $entity_id = NULL) {
  if ($entity_id) {
    // we'll need this info when we submit the form
    $form_state['entity'] = array(
      'entity_id' => $entity_id,
      'entity_type' => $entity_type
    );
  }

  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#description' => t('Check to enable date_items.'),
    '#default_value' => isset($settings['status']) ? $settings['status'] : -1,
  );
  $form['capacity'] = array(
    '#type' => 'textfield',
    '#title' => t('Capacity'),
    '#description' => t('The maximum number of registrants. Leave at 0 for no limit.'),
    '#size' => 5,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#default_value' => isset($settings['capacity']) ? $settings['capacity'] : 0,
  );

  $form['scheduling'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scheduling'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE
  );

  $form['scheduling']['open'] = array(
    '#type' => 'textfield',
    '#title' => t('Open Date'),
    '#maxlength' => 25,
    '#description' => t('When to automatically open date_items. Format: %time. The date format is YYYY-MM-DD and %timezone is the time zone offset from UTC. Leave blank to disable.', array(
        '%time' => !empty($settings['open']) ? date_format(date_create($settings['open']), 'Y-m-d H:i:s O') : format_date(time(), 'custom', 'Y-m-d H:i:s O'),
        '%timezone' => !empty($settings['open']) ? date_format(date_create($settings['open']), 'O') : format_date(time(), 'custom', 'O')
      )
    ),
    '#default_value' => !empty($settings['open']) ? $settings['open'] : '',
  );

  $form['scheduling']['close'] = array(
    '#type' => 'textfield',
    '#title' => t('Close Date'),
    '#maxlength' => 25,
    '#description' => t('When to automatically close date_items. Format: %time. The date format is YYYY-MM-DD and %timezone is the time zone offset from UTC. Leave blank to disable.', array(
        '%time' => !empty($settings['close']) ? date_format(date_create($settings['close']), 'Y-m-d H:i:s O') : format_date(time(), 'custom', 'Y-m-d H:i:s O'),
        '%timezone' => !empty($settings['close']) ? date_format(date_create($settings['close']), 'O') : format_date(time(), 'custom', 'O')
      )
    ),
    '#default_value' => !empty($settings['close']) ? $settings['close'] : '',
  );


  $form['reminder'] = array(
    '#type' => 'fieldset',
    '#title' => t('Reminder'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE
  );

  $form['reminder']['send_reminder'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send Reminder'),
    '#description' => t('If checked, a reminder will be sent to registrants on the following date.'),
    '#default_value' => isset($settings['send_reminder']) ? $settings['send_reminder'] : -1,
  );

  $form['reminder']['reminder_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings'),
    '#collapsible' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="send_reminder"]' => array('checked' => TRUE),
      ),
    )
  );

  $form['reminder']['reminder_settings']['reminder_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Reminder Date'),
    '#maxlength' => 25,
    '#description' => t('When to send reminders. Format: %time. The date format is YYYY-MM-DD and %timezone is the time zone offset from UTC.', array(
        '%time' => !empty($settings['open']) ? date_format(date_create($settings['reminder_date']), 'Y-m-d H:i:s O') : format_date(time(), 'custom', 'Y-m-d H:i:s O'),
        '%timezone' => !empty($settings['open']) ? date_format(date_create($settings['reminder_date']), 'O') : format_date(time(), 'custom', 'O')
      )
    ),
    '#default_value' => !empty($settings['reminder_date']) ? $settings['reminder_date'] : '',
  );

  $form['reminder']['reminder_settings']['reminder_template'] = array(
    '#type' => 'textarea',
    '#title' => t('Template'),
    '#default_value' => isset($settings['reminder_template']) ? $settings['reminder_template'] : '',
    '#description' => t('The reminder message sent to registrants. Tokens are supported if the module is enabled, E.g., [node:title].'),
  );

  // add token support
  if (module_exists('token')) {
    $form['reminder']['reminder_settings']['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array(
        'node',
        'date_item'
      ),
      '#global_types' => FALSE,
    );
  }

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE
  );

  $form['settings']['multiple_date_items'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow multiple date_items'),
    '#description' => t('If selected, users can register for more than one slot for this event.'),
    '#default_value' => isset($settings['settings']['multiple_date_items']) ? $settings['settings']['multiple_date_items'] : -1,
  );

  $form['settings']['from_address'] = array(
    '#type' => 'textfield',
    '#title' => t('From Address'),
    '#description' => t('From email address to use for confirmations, reminders, and broadcast emails.'),
    '#required' => TRUE,
    '#default_value' => isset($settings['settings']['from_address']) ? $settings['settings']['from_address'] : variable_get('site_mail', ini_get('sendmail_from')),
  );

  // allow other modules to add their own custom settings
  $form['settings'] += module_invoke_all('date_item_entity_settings', $settings);

  // only show save if we're not on the field instance defaults
  if ($entity_id) {
    $form['save'] = array(
      '#type' => 'submit',
      '#value' => t('Save Settings'),
    );
  }

  return $form;
}