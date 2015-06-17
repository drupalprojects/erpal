<?php
/**
 * @file
 * erpal_project_ui.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function erpal_project_ui_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_project';
  $strongarm->value = 'edit-auto-nodetitle';
  $export['additional_settings__active_tab_erpal_project'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_erpal_task';
  $strongarm->value = 'edit-notifications';
  $export['additional_settings__active_tab_erpal_task'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__priority_terms';
  $strongarm->value = array(
    'view_modes' => array(
      'minimal' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'in_pane' => array(
        'custom_settings' => FALSE,
      ),
      'visual' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'description' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'minimal' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__priority_terms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__task_status_terms';
  $strongarm->value = array(
    'view_modes' => array(
      'in_pane' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'minimal' => array(
        'custom_settings' => TRUE,
      ),
      'visual' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'description' => array(
          'default' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'in_pane' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'minimal' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'visual' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__task_status_terms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__task_type_terms';
  $strongarm->value = array(
    'view_modes' => array(
      'minimal' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'in_pane' => array(
        'custom_settings' => FALSE,
      ),
      'visual' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'description' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'minimal' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__task_type_terms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pm_existing_pages_disabled_budget_view_page';
  $strongarm->value = FALSE;
  $export['pm_existing_pages_disabled_budget_view_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'timetracking_subject_display';
  $strongarm->value = 'entityreference_1';
  $export['timetracking_subject_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'timetracking_subject_view';
  $strongarm->value = 'task_entityreference';
  $export['timetracking_subject_view'] = $strongarm;

  return $export;
}
