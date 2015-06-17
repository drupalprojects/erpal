<?php

/**
* Modifies some settings or widgets in relation module, integrate with references dialog for example
*/

/**
* This function clears all runtime caches of all related entities in the relation excluded some exceptions
*/
function _erpal_basic_helper_clear_endpoint_entities_cache($relation, $exclude=array()) {
  $to_clear = array();
  if (!empty($relation->endpoints[LANGUAGE_NONE][0])) {
    $endpoints = $relation->endpoints[LANGUAGE_NONE];
    foreach ($endpoints as $delta => $endpoint) {
      $entity_type = $endpoint['entity_type'];
      $entity_id = $endpoint['entity_id'];
      
      $to_clear[$entity_type][$entity_id] = $entity_id;                    
    }
    
    if (!empty($to_clear)) {
      foreach ($to_clear as $entity_type => $ids) {
        entity_load($entity_type, $ids, array(), TRUE);
      }
    }
  }
}

/**
* Callback used in hook_field_formatter_view
*/
function _erpal_basic_helper_formatter_view_relation_endpoint_simple_table($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $build = array();
      
  $build['table'] = _erpal_basic_helper_relation_endpoint_field_create_html_table($items, $entity);

  return $build;
}

/**
* Creates a custom table for viewing endpoints of a relation
*/
function _erpal_basic_helper_relation_endpoint_field_create_html_table($endpoints, $relation_entity) {
  $list_items = array();
  foreach ($endpoints as $delta => $endpoint) {
    $entities = entity_load($endpoint['entity_type'], array($endpoint['entity_id']));
    $entity = reset($entities);
    $label = entity_label($endpoint['entity_type'], $entity);
    $uri = entity_uri($endpoint['entity_type'], $entity);    
    $list_items[$delta] = array(l($label, $uri['path'], $uri['options']));
  }
  
  $relation_links = l('Edit relation', 'relation/'.$relation_entity->rid.'/'.'edit');

  $list_items[$delta][] = $relation_links;
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
function _erpal_basic_helper_relation_add_block_form_alter(&$form, &$form_state) {
  $form['relation_options']['targets']['target_2']['#title'] = t('In relation with');
}

