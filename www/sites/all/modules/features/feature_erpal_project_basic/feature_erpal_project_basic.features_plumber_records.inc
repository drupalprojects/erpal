<?php
/**
 * @file
 * feature_erpal_project_basic.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function feature_erpal_project_basic_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass;
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'feature_erpal_project_basic__field__node-erpal_task-field_spec_ref';
  $features_plumber_record->feature = 'feature_erpal_project_basic';
  $features_plumber_record->component = 'field';
  $features_plumber_record->component_val = 'node-erpal_task-field_spec_ref';
  $export['feature_erpal_project_basic__field__node-erpal_task-field_spec_ref'] = $features_plumber_record;

  return $export;
}
