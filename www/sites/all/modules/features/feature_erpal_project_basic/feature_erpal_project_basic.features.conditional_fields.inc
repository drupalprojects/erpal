<?php
/**
 * @file
 * feature_erpal_project_basic.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function feature_erpal_project_basic_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'field_collection_item',
    'bundle' => 'field_pricing',
    'dependent' => 'field_price',
    'dependee' => 'field_price_mode',
    'options' => array(
      'state' => '!visible',
      'condition' => 'value',
      'effect' => 'show',
      'effect_options' => array(),
      'element_view' => array(
        1 => '1',
        2 => '2',
        5 => 0,
        3 => 0,
        4 => 0,
      ),
      'element_view_per_role' => 0,
      'element_view_roles' => array(
        1 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        2 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        3 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
        4 => array(
          1 => '1',
          2 => '2',
          5 => 0,
          3 => 0,
          4 => 0,
        ),
      ),
      'element_edit' => array(
        1 => '1',
        3 => 0,
        2 => 0,
      ),
      'element_edit_per_role' => 0,
      'element_edit_roles' => array(
        1 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        2 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        3 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
        4 => array(
          1 => '1',
          3 => 0,
          2 => 0,
        ),
      ),
      'selector' => '',
      'values_set' => '1',
      'value_form' => 'not_billable',
      'value' => array(
        0 => array(
          'value' => 'not_billable',
        ),
      ),
      'values' => array(),
    ),
  );

  return $items;
}
