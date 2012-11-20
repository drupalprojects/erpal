<?php
/**
 * @file
 * feature_erpal_basic.features_plumber_records.inc
 */

/**
 * Implements hook_features_plumber_defaults().
 */
function feature_erpal_basic_features_plumber_defaults() {
  $export = array();

  $features_plumber_record = new stdClass();
  $features_plumber_record->disabled = FALSE; /* Edit this to true to make a default features_plumber_record disabled initially */
  $features_plumber_record->api_version = 1;
  $features_plumber_record->name = 'feature_erpal_basic__field__date_item-simple_date-field_date_item_tags';
  $features_plumber_record->feature = 'feature_erpal_basic';
  $features_plumber_record->component = 'field';
  $features_plumber_record->component_val = 'date_item-simple_date-field_date_item_tags';
  $export['feature_erpal_basic__field__date_item-simple_date-field_date_item_tags'] = $features_plumber_record;

  return $export;
}
