<?php

/**
 * Sync pending orders
 */
function _erpal_docs_access_permissions($form, &$form_state) {
  $form = array();
  
  $form['info'] = array(
    '#type' => 'item',
    '#title' => t('Run it to rebuild permissions of attached files manualy'),
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuid permissions'),
  );
  return $form;
}

/**
 * Run sync
 */
function _erpal_docs_access_permissions_submit($form, &$form_state) {
  erpal_docs_access_batch_start();
}

function _erpal_docs_access_settings($form, &$form_state) {
  $form = array();

  $form['erpal_docs_access_users_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Users count for rebuild process'),
    '#description' => t('This is limit of users that will be processed after any entity with attached file wase created/updated/deleted. But if in database there are more users than value of this field, permissions rebuild process will be handled on cron run.'),
    '#default_value' => variable_get('erpal_docs_access_users_count', 30),
  );

  return system_settings_form($form);
}