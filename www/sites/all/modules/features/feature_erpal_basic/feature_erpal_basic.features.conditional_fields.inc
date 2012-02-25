<?php
/**
 * @file
 * feature_erpal_basic.features.conditional_fields.inc
 */

/**
 * Implements hook_conditional_fields_default_fields().
 */
function feature_erpal_basic_conditional_fields_default_fields() {
  $items = array();

  $items[] = array(
    'entity' => 'node',
    'bundle' => 'erpal_contact',
    'dependent' => 'field_company_name',
    'dependee' => 'field_contact_type',
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
      ),
      'selector' => '',
      'values_set' => '1',
      'value_form' => 'company',
      'value' => array(
        0 => array(
          'value' => 'company',
        ),
      ),
      'values' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'node',
    'bundle' => 'erpal_contact',
    'dependent' => 'field_firstname',
    'dependee' => 'field_contact_type',
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
      ),
      'selector' => '',
      'values_set' => '1',
      'value_form' => 'person',
      'value' => array(
        0 => array(
          'value' => 'person',
        ),
      ),
      'values' => array(),
    ),
  );

  $items[] = array(
    'entity' => 'node',
    'bundle' => 'erpal_contact',
    'dependent' => 'field_lastname',
    'dependee' => 'field_contact_type',
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
      ),
      'selector' => '',
      'values_set' => '1',
      'value_form' => 'person',
      'value' => array(
        0 => array(
          'value' => 'person',
        ),
      ),
      'values' => array(),
    ),
  );

  return $items;
}
