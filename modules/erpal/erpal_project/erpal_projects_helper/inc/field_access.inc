<?php

/**
* @file provide functions to handle field access for content types of feature_erpal_project_basic
*/

/**
* Provides form element that will be added to the config form
*/ 
function _erpal_projects_helper_field_access_config_form(&$form) {
  $form['field_access'] = array(
    '#type' => 'fieldset',
    '#title' => t('Field access permissions'),
    '#collapsible' => false,
    '#collapsed' => true,
  );
    
  //just set a link to config the permissions
  $form['field_access']['link'] = array(
    '#type' => 'item',
    '#markup' => l('Configure projects permissions', 'admin/people/permissions', array('fragment' => 'module-erpal_projects_helper')),
  );
}

/**
* return all available permissions, calles by hook_permission
*/
function _erpal_projects_helper_field_access_permissions() {
  return array(
    //PRINCING
    'field view pricing' => array(
      'title' => t('Field: View the pricing of nodes'),
      'description' => t('User can view the pricing information of task and project nodes'),
    ),
    'field edit pricing' => array(
      'title' => t('Field: Edit the pricing of nodes'),
      'description' => t('User can edit the pricing information of task and project nodes'),
    ),
    
    //DURATION
    'field view timetracking duration' => array(
      'title' => t('Field: View the duration of timetrackings'),
      'description' => t('User can view the duration of timetracking nodes'),
    ),
    'field edit timetracking duration' => array(
      'title' => t('Field: Edit the duration of timetrackings'),
      'description' => t('User can edit the duration of timetracking nodes'),
    ),
    
    //advanced fields
    'field view task advanced' => array(
      'title' => t('Field: View advanced task fields'),
      'description' => t('User can view the advanced fields on tasks'),
    ),
    'field edit task advanced' => array(
      'title' => t('Field: Edit advanced task fields'),
      'description' => t('User can edit the advanced fields on tasks'),
    ),
  );
}

/**
* Check permissions for fields, called by hook_field_access implementation of this module
*/
function _erpal_projects_helper_field_access($op, $field, $entity_type, $entity = NULL, $account = NULL) {
 
  if ($field['field_name'] == 'field_pricing') {
    if ($op == 'view') {
      return user_access('field view pricing');
    } elseif ($op == 'edit') {
      return user_access('field edit pricing');
    }
  }
  
  if ($field['field_name'] == 'field_timetracking_duration') {
    if ($op == 'view') {
      return user_access('field view timetracking duration');
    } elseif ($op == 'edit') {
      return user_access('field edit timetracking duration');
    }
  }
  
  //advanced fields
  $advanced_fields = array('field_estimated_time', 'field_progress_percent', 'field_task_exclude_from', 'field_project_tags', 'field_task_assigned_users');
  if (in_array($field['field_name'], $advanced_fields)) {
    if ($op == 'view') {
      return user_access('field view task advanced');
    } elseif ($op == 'edit') {
      return user_access('field edit task advanced');
    }
  }
  
  //Timetracking toggle button in task form is only visible if user has right "create timetracking" from timetracking module
  if ($field['field_name'] == 'field_timetracking_button') {
    return user_access('create timetracking') && user_access('use quick timetracking');
  }

}