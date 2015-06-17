<?php
/**
 * @file
 * erpal_contract_projects.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function erpal_contract_projects_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.node_view_panel_context_9.conf|display|content|new-6cbac466-b1f1-3bc4-e1a3-d3d1b4f6d5f6"] = (object) array(
      'pid' => 'new-6cbac466-b1f1-3bc4-e1a3-d3d1b4f6d5f6',
      'panel' => 'sidebar_second_left',
      'type' => 'panels_mini',
      'subtype' => 'contract_budget_information',
      'shown' => TRUE,
      'access' => array(),
      'configuration' => array(
        'context' => array(
          0 => 'argument_entity_id:node_1',
        ),
        'override_title' => 1,
        'override_title_text' => '<none>',
      ),
      'cache' => array(),
      'style' => array(
        'settings' => NULL,
      ),
      'css' => array(),
      'extras' => array(),
      'position' => 2,
      'locks' => array(),
      'uuid' => '6cbac466-b1f1-3bc4-e1a3-d3d1b4f6d5f6',
    );
  $overrides["page_manager_handlers.node_view_panel_context_9.conf|display|content|new-fa3436a7-e353-3584-fdda-360a36de23cf|position"] = 3;
  $overrides["page_manager_handlers.node_view_panel_context_9.conf|display|panels|sidebar_second_left|2"] = 'new-6cbac466-b1f1-3bc4-e1a3-d3d1b4f6d5f6';
  $overrides["page_manager_handlers.node_view_panel_context_9.conf|display|panels|sidebar_second_left|3"] = 'new-fa3436a7-e353-3584-fdda-360a36de23cf';

 return $overrides;
}
