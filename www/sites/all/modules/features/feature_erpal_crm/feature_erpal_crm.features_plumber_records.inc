<?php
/**
 * @file
 * feature_erpal_crm.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function feature_erpal_crm_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass();
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'feature_erpal_crm__dependencies__field_group';
  $features_plumber_record->feature = 'feature_erpal_crm';
  $features_plumber_record->component = 'dependencies';
  $features_plumber_record->component_val = 'field_group';
  $export['feature_erpal_crm__dependencies__field_group'] = $features_plumber_record;

  return $export;
}
