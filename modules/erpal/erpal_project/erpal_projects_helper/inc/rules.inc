<?php

/**
* @file all functions to integrate with rules API
*/

/**
 * Implements hook_rules_event_info().
 */
function erpal_projects_helper_rules_event_info() {
  $defaults = array(
    'group' => t('ERPAL projects'),
    'module' => 'erpal_projects_helper',
    'access callback' => 'rules_erpal_projects_integration_access',
  );
  
  $variables = array(
    'node' => array('type' => 'node', 'label' => t('Node with budget')),
    'available_hours' => array('type' => 'integer', 'label' => t('Available hours at budget of node')),
    'total_hours' => array('type' => 'integer', 'label' => t('Total hours at budget of node')),
  );
  
  return array(
    'budget_warning' => $defaults + array(
      'label' => t('If budget is almost completly used at a task or project'),
      'variables' => $variables,
    ),
    'budget_empty' => $defaults + array(
      'label' => t('If budget is completly used at a task or project'),
      'variables' => $variables,
    ),    
  );
}

/**
 * erpal projects integration access callback.
 */
function rules_erpal_projects_integration_access($type, $name) {
  //@TODO does this work? Do we need it really?
  if ($type == 'event' || $type == 'condition') {
    return entity_access('view', 'node');
  }
}