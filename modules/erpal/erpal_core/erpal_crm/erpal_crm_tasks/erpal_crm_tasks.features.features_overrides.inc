<?php
/**
 * @file
 * erpal_crm_tasks.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function erpal_crm_tasks_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: panels_mini
  $overrides["panels_mini.task_general_fields.display|content|new-53230bce-bb3c-44b5-bc57-3a0af25a0f27"] = (object) array(
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
    );
  $overrides["panels_mini.task_general_fields.display|panels|middle|7"] = 'new-53230bce-bb3c-44b5-bc57-3a0af25a0f27';

 return $overrides;
}
