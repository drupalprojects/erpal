<?php
/**
 * @file
 * erpal_crm_tasks_ui.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function erpal_crm_tasks_ui_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'in_activity';
  $ds_view_mode->label = 'in-activity';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['in_activity'] = $ds_view_mode;

  return $export;
}
