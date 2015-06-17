<?php
/**
 * @file
 * erpal_employee.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function erpal_employee_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_duration_calc'
  $field_bases['field_duration_calc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_duration_calc',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'computed_field',
    'settings' => array(
      'code' => '$entity_field[0][\'value\'] = "";',
      'database' => array(
        'data_default' => 0,
        'data_index' => 0,
        'data_length' => 32,
        'data_not_NULL' => 1,
        'data_precision' => 10,
        'data_scale' => 2,
        'data_size' => 'normal',
        'data_type' => 'numeric',
      ),
      'display_format' => '$display_output = $entity_field_item[\'value\'];',
      'store' => 1,
    ),
    'translatable' => 0,
    'type' => 'computed',
  );

  // Exported field_base: 'field_working_time_type'
  $field_bases['field_working_time_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_working_time_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'work' => 'Working time',
        'holiday' => 'Holiday',
        'ill' => 'Ill',
        'day_off' => 'Day off',
        'reduce_hours' => 'Reduce hours (got paid)',
      ),
      'allowed_values_function' => '',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
