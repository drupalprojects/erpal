<?php

/**
* @file all functions to integrate with rules API
*/

/**
 * Implements hook_rules_event_info().
 */
function erpal_project_reports_rules_event_info() {
  $defaults = array(
    'group' => t('ERPAL projects'),
    'module' => 'erpal_project_reports',
  );
  
  $variables = array(
    'project' => array('type' => 'node', 'label' => t('project with the profit report.')),
    'revenue' => array('type' => 'decimal', 'label' => t('Estimated time at a project or a task')),
    'expense' => array('type' => 'decimal', 'label' => t('Used time at a project or a task')),
    'profit' => array('type' => 'decimal', 'label' => t('Time to work left at a project or a task')),
    'profit_percent' => array('type' => 'decimal', 'label' => t('Time left at a project or a task')),    
  );
  
  return array(
    'project_profit_calcualted' => $defaults + array(
      'label' => t('If budget a projects profit is calculated'),
      'variables' => $variables,
    ),
  );
}
