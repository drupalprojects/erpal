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
  $features_plumber_record->name = 'feature_erpal_crm__field__node-erpal_crm_activity-field_customer_ref';
  $features_plumber_record->feature = 'feature_erpal_crm';
  $features_plumber_record->component = 'field';
  $features_plumber_record->component_val = 'node-erpal_crm_activity-field_customer_ref';
  $export['feature_erpal_crm__field__node-erpal_crm_activity-field_customer_ref'] = $features_plumber_record;

  return $export;
}
