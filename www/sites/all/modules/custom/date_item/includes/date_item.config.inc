<?php

/**
* @file all functions for configuring the date item module
*/
function date_item_admin_settings_form($form, $form_state) {
  $form = array();
  
  $form['date_item_prepopulate_days'] = array(
    '#type' => 'textfield',
    '#title' => t('Days to prepopulate date items'),
    '#description' => t('Date items will be prepopulated. This variable definies for how many days in the future.'),
    '#default_value' => _date_item_get_prepopulate_days(),
  );

  return system_settings_form($form);
}

/**
* Returns the number of prepopulating days for date items
*/
function _date_item_get_prepopulate_days() {
  return variable_get('date_item_prepopulate_days', 10);
}