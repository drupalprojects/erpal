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
  );
  
  $variables_budget = array(
    'node' => array('type' => 'node', 'label' => t('Node with budget')),
    'available_hours' => array('type' => 'integer', 'label' => t('Available hours at budget of node')),
    'total_hours' => array('type' => 'integer', 'label' => t('Total hours at budget of node')),
  );
  
  $variables_esitmation = array(
    'node' => array('type' => 'node', 'label' => t('Node with recalculation')),
    'estimated_time' => array('type' => 'integer', 'label' => t('Estimated time at a project or a task')),
    'used_time' => array('type' => 'integer', 'label' => t('Used time at a project or a task')),
    'work_time_left' => array('type' => 'integer', 'label' => t('Time to work left at a project or a task')),
    'time_left' => array('type' => 'integer', 'label' => t('Time left at a project or a task')),
    'time_left_percent' => array('type' => 'integer', 'label' => t('Time left in percent at a project or a task')),
  );
  
  return array(
    'budget_warning' => $defaults + array(
      'label' => t('If budget is almost completely used at a task or project'),
      'variables' => $variables_budget,
    ),
    'budget_empty' => $defaults + array(
      'label' => t('If budget is completely used at a task or project'),
      'variables' => $variables_budget,
    ),
    'time_information_recalculated_direct' => $defaults + array(
      'label' => t('If a time direct information is recalculated at a task or project'),
      'variables' => $variables_esitmation,
    ),  
    'time_information_recalculated_sub' => $defaults + array(
      'label' => t('If a time sub task information is recalculated at a task or project'),
      'variables' => $variables_esitmation,
    ),  
  );
}
