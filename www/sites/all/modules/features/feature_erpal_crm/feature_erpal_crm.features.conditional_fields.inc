<?php
/**
 * @file
 * feature_erpal_crm.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function feature_erpal_crm_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'node',
    'bundle' => 'erpal_crm_activity',
    'dependent' => 'field_chance',
    'dependee' => 'field_activity_status',
    'options' => array(
      'state' => 'visible',
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
      'values_set' => '4',
      'value_form' => '2',
      'values' => array(
        0 => '2',
        1 => '3',
      ),
      'value' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'node',
    'bundle' => 'erpal_crm_activity',
    'dependent' => 'field_volume',
    'dependee' => 'field_activity_status',
    'options' => array(
      'state' => 'visible',
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
      'values_set' => '4',
      'value_form' => '2',
      'values' => array(
        0 => '2',
        1 => '3',
      ),
      'value' => array(),
    ),
  );

  return $items;
}
