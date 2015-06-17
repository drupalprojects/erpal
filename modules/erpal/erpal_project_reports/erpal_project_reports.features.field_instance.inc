<?php
/**
 * @file
 * erpal_project_reports.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function erpal_project_reports_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'erpal_reports-erpal_project_active_projects_reports-field_erpal_reports_filter_id'
  $field_instances['erpal_reports-erpal_project_active_projects_reports-field_erpal_reports_filter_id'] = array(
    'bundle' => 'erpal_project_active_projects_reports',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_filter_id',
    'label' => 'Filter id',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_extrawidgets',
      'settings' => array(
        'display_empty' => 0,
        'formatter' => '',
        'formatter_settings' => array(),
      ),
      'type' => 'field_extrawidgets_read_only',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_active_projects_reports-field_erpal_reports_global'
  $field_instances['erpal_reports-erpal_project_active_projects_reports-field_erpal_reports_global'] = array(
    'bundle' => 'erpal_project_active_projects_reports',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_global',
    'label' => 'Is global report',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_onoff',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_active_projects_reports-field_erpal_reports_owners'
  $field_instances['erpal_reports-erpal_project_active_projects_reports-field_erpal_reports_owners'] = array(
    'bundle' => 'erpal_project_active_projects_reports',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'These users will see the report on their personal dashboard.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_owners',
    'label' => 'Owners',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_management_reports-field_erpal_reports_filter_id'
  $field_instances['erpal_reports-erpal_project_management_reports-field_erpal_reports_filter_id'] = array(
    'bundle' => 'erpal_project_management_reports',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_filter_id',
    'label' => 'Filter id',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_extrawidgets',
      'settings' => array(
        'display_empty' => 0,
        'formatter' => '',
        'formatter_settings' => array(),
      ),
      'type' => 'field_extrawidgets_read_only',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_management_reports-field_erpal_reports_global'
  $field_instances['erpal_reports-erpal_project_management_reports-field_erpal_reports_global'] = array(
    'bundle' => 'erpal_project_management_reports',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_global',
    'label' => 'Is global report',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_onoff',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_management_reports-field_erpal_reports_owners'
  $field_instances['erpal_reports-erpal_project_management_reports-field_erpal_reports_owners'] = array(
    'bundle' => 'erpal_project_management_reports',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'These users will see the report on their personal dashboard.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_owners',
    'label' => 'Owners',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_profit_margin_reports-field_erpal_reports_filter_id'
  $field_instances['erpal_reports-erpal_project_profit_margin_reports-field_erpal_reports_filter_id'] = array(
    'bundle' => 'erpal_project_profit_margin_reports',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_filter_id',
    'label' => 'Filter id',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_extrawidgets',
      'settings' => array(
        'display_empty' => 0,
        'formatter' => '',
        'formatter_settings' => array(),
      ),
      'type' => 'field_extrawidgets_read_only',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_profit_margin_reports-field_erpal_reports_global'
  $field_instances['erpal_reports-erpal_project_profit_margin_reports-field_erpal_reports_global'] = array(
    'bundle' => 'erpal_project_profit_margin_reports',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_global',
    'label' => 'Is global report',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_onoff',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_profit_margin_reports-field_erpal_reports_owners'
  $field_instances['erpal_reports-erpal_project_profit_margin_reports-field_erpal_reports_owners'] = array(
    'bundle' => 'erpal_project_profit_margin_reports',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'These users will see the report on their personal dashboard.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_owners',
    'label' => 'Owners',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_timetracking_reports-field_erpal_reports_filter_id'
  $field_instances['erpal_reports-erpal_project_timetracking_reports-field_erpal_reports_filter_id'] = array(
    'bundle' => 'erpal_project_timetracking_reports',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_filter_id',
    'label' => 'Filter id',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'field_extrawidgets',
      'settings' => array(
        'display_empty' => 0,
        'formatter' => '',
        'formatter_settings' => array(),
      ),
      'type' => 'field_extrawidgets_read_only',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_timetracking_reports-field_erpal_reports_global'
  $field_instances['erpal_reports-erpal_project_timetracking_reports-field_erpal_reports_global'] = array(
    'bundle' => 'erpal_project_timetracking_reports',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_global',
    'label' => 'Is global report',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_onoff',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'erpal_reports-erpal_project_timetracking_reports-field_erpal_reports_owners'
  $field_instances['erpal_reports-erpal_project_timetracking_reports-field_erpal_reports_owners'] = array(
    'bundle' => 'erpal_project_timetracking_reports',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => 'These users will see the report on their personal dashboard.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'erpal_reports',
    'field_name' => 'field_erpal_reports_owners',
    'label' => 'Owners',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 30,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Filter id');
  t('Is global report');
  t('Owners');
  t('These users will see the report on their personal dashboard.');

  return $field_instances;
}
