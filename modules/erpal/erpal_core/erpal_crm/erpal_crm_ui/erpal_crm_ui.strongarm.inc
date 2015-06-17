<?php
/**
 * @file
 * erpal_crm_ui.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_crm_ui_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_contact';
  $strongarm->value = 'edit-display';
  $export['additional_settings__active_tab_erpal_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_crm_activity';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_erpal_crm_activity';
  $strongarm->value = '65';
  $export['maxlength_js_erpal_crm_activity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_erpal_crm_activity';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_erpal_crm_activity'] = $strongarm;

  return $export;
}
