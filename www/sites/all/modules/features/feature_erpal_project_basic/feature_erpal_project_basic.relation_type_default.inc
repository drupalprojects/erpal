<?php
/**
 * @file
 * feature_erpal_project_basic.relation_type_default.inc
 */

/**
 * Implements hook_relation_default_relation_types().
 */
function feature_erpal_project_basic_relation_default_relation_types() {
  $export = array();

  $relation_type = new stdClass();
  $relation_type->disabled = FALSE; /* Edit this to true to make a default relation_type disabled initially */
  $relation_type->api_version = 1;
  $relation_type->relation_type = 'participate_in';
  $relation_type->label = 'has as stakeholder';
  $relation_type->reverse_label = 'is project member';
  $relation_type->directional = 1;
  $relation_type->transitive = 0;
  $relation_type->r_unique = 1;
  $relation_type->min_arity = 2;
  $relation_type->max_arity = 2;
  $relation_type->source_bundles = array(
    0 => 'node:erpal_project',
  );
  $relation_type->target_bundles = array(
    0 => 'node:erpal_contact',
  );
  $export['participate_in'] = $relation_type;

  return $export;
}
