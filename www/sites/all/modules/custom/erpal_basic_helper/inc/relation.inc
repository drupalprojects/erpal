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
      $build['table'] = _erpal_basic_helper_relation_endpoint_field_create_html_table($items, $entity);
  }

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

/**
* Implements access validation to add a relation (custom relation add form)
*/
function _erpal_basic_helper_relation_add_access($node) {
  //@TODO validation handling for relation create page
  return user_access('create relations');
}

/**
* Menu callback for adding a relation
*/
function _erpal_basic_helper_relation_add_page_callback($node) {
  return drupal_get_form('erpal_basic_helper_node_relation_add_form', $node);
}

/**
* Form to add a relation to a node using the form of the relation add block
*/
function erpal_basic_helper_node_relation_add_form($form, $form_state, $node) {

  $form = relation_add_block_form($form, $form_state);  //brings his own submit handler
  $form['relation_options']['save']['#submit'] = array('relation_add_save', 'erpal_basic_helper_node_relation_add_form_save');  //add my submithandler and the one of the relation add block form
  
  $form['selected_nid'] = array(
    '#type' => 'value',
    '#value' => $node->nid,
  );
  
  return $form;
}

/**
* Submit handler for node relation add form
*/
function erpal_basic_helper_node_relation_add_form_save($form, &$form_state) {
  $values = $form_state['values'];
  $selected_nid = $values['selected_nid'];
  $form_state['redirect'] = 'node/'.$selected_nid.'/relations';
}

