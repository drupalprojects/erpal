<?php
/**
 * @file
 * feature_erpal_docs.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function feature_erpal_docs_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass();
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'feature_erpal_docs__dependencies__og';
  $features_plumber_record->feature = 'feature_erpal_docs';
  $features_plumber_record->component = 'dependencies';
  $features_plumber_record->component_val = 'og';
  $export['feature_erpal_docs__dependencies__og'] = $features_plumber_record;

  $features_plumber_record = new stdClass();
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'feature_erpal_docs__field__node-erpal_file-group_audience';
  $features_plumber_record->feature = 'feature_erpal_docs';
  $features_plumber_record->component = 'field';
  $features_plumber_record->component_val = 'node-erpal_file-group_audience';
  $export['feature_erpal_docs__field__node-erpal_file-group_audience'] = $features_plumber_record;

  return $export;
}
