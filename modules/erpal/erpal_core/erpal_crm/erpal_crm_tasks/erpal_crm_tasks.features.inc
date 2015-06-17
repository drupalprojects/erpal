<?php
/**
 * @file
 * erpal_crm_tasks.features.inc
 */

/**
 * Implements hook_views_api().
 */
function erpal_crm_tasks_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_panels_mini_alter().
 */
function erpal_crm_tasks_default_panels_mini_alter(&$data) {
  if (isset($data['task_general_fields'])) {
    $data['task_general_fields']->display->content['new-53230bce-bb3c-44b5-bc57-3a0af25a0f27'] = (object) array(
          'pid' => 'new-53230bce-bb3c-44b5-bc57-3a0af25a0f27',
          'panel' => 'middle',
          'type' => 'views_panes',
          'subtype' => 'crm_activity_by_task-panel_pane_1',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(),
          'cache' => array(),
          'style' => '',
          'css' => array(),
          'extras' => array(),
          'position' => 7,
          'locks' => array(),
          'uuid' => '53230bce-bb3c-44b5-bc57-3a0af25a0f27',
        ); /* WAS: '' */
    $data['task_general_fields']->display->panels['middle'][7] = 'new-53230bce-bb3c-44b5-bc57-3a0af25a0f27'; /* WAS: '' */
  }
}
