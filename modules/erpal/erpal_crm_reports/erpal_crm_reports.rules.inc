<?php

/**
* @file Rules integration for crm reports
*/

/**
 * Implements hook_rules_event_info().
 */
function erpal_crm_reports_rules_event_info() {
  $defaults = array(
    'group' => t('ERPAL CRM Reports'),
    'module' => 'erpal_crm_reports',
  );
  
  $variables = array(
    'node' => array('type' => 'node', 'label' => t('Forecast Node')),
    'year' => array('type' => 'integer', 'label' => t('Year of the expense plan value')),
    'planned_value' => array('type' => 'integer', 'label' => t('Planned value of the expense plan')),
    'dynamic_planned_value' => array('type' => 'integer', 'label' => t('Dynamic planned value of the expense plan')),
    'current_value' => array('type' => 'integer', 'label' => t('Current value of the expense plan')),
    'current_percent' => array('type' => 'integer', 'label' => t('Current percent value of the expense plan')),
    'dynamic_current_percent' => array('type' => 'integer', 'label' => t('Current dynamic percent value of the expense plan')),
  );
  
  
  return array(
    'expense_plan_recalculation' => $defaults + array(
      'label' => t('Expense plan values have been recalculated'),
      'variables' => $variables,
    ),
    'sales_plan_recalculation' => $defaults + array(
      'label' => t('Customer sales plan values have been recalculated'),
      'variables' => $variables,
    ),
    
  );
}