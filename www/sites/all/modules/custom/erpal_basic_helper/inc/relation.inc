<?php

/**
* Modifies some settings or widgets in relation module, integrate with references dialog for example
*/

/**
* Implements hook_field_formatter_info().
*/
function erpal_basic_helper_field_formatter_info() {
  $info = array(
    'relation_endpoint_simple_table' => array(
      'label' => t('Endpoints simple table'),
      'field types' => array('relation_endpoint'),
    ),    
  );

  return $info;
}

/**
 * Implements hook_field_formatter_view().
 */
function erpal_basic_helper_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $build = array();
  switch ($display['type']) {
    case 'relation_endpoint_simple_table':      
      $build['table'] = _erpal_basic_helper_relation_endpoint_field_create_html_table($items);
  }

  return $build;
}

/**
* Creates a custom table for viewing endpoints of a relation
*/
function _erpal_basic_helper_relation_endpoint_field_create_html_table($endpoints) {
  $list_items = array();
  foreach ($endpoints as $delta => $endpoint) {
    $entities = entity_load($endpoint['entity_type'], array($endpoint['entity_id']));
    $entity = reset($entities);
    $label = entity_label($endpoint['entity_type'], $entity);
    $uri = entity_uri($endpoint['entity_type'], $entity);
    $list_items[$delta] = array(l($label, $uri['path'], $uri['options']));
  }
  $headers = array(
    '',
  );
  return array(
    '#theme' => 'table',
    '#header' => $headers,
    '#rows' => $list_items,
  );
}

/**
* Alter the relation add block,to replace "Endpoint 2" label with something concrete!
*/
function _erpal_invoice_helper_relation_add_block_form_alter(&$form, &$form_state) {
  $form['relation_options']['targets']['target_2']['#title'] = t('In relation with');
}