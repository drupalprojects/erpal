<?php

/**
* @file all functions needed to make erpal_crm accessible by services
* @author Manuel Pistner <pistner@brightsolutions.de>
* @copyright (c) 2013
*/


/**
 * Create a new crm_activity node by services module request
 * @param array $activity the data delivered by the webservice, $activity['crm_activity'] must be an array
 * @return the activity that was created or an error of activity could not be created
 * @TODO: maybe use drupal_form_submit or _node_resource_create to have validation instead of node_save
 */
function _erpal_crm_service_crm_activity_create($activity) {
  $returns = array();
  global $user;

  $value = $activity['crm_activity'];

  //if we don't have title, take the first 65 chars from body
  $body = isset($value['body']) ? $value['body'] : '';
  $title = isset($value['title']) ? $value['title'] : substr($body, 1, 65);
  $origin = isset($value['origin']) ? $value['origin'] : '';
  $customer_nid = isset($value['customer_nid']) ? $value['customer_nid'] : false;
  
  //Find the term to the origin string
  $origin_term_id = taxonomy_get_term_by_name($origin, 'activity_origin');
  $origin_term_id = reset($origin_term_id);
  $origin_term_id = $origin_term_id->tid;

  //@TODO: set next contact and make it configurable in ERPAL settings

  
  $form_id = 'erpal_crm_activity_node_form';
  $form_values = array(
    'title' => $title,
    'body' => array(LANGUAGE_NONE => array(0 => array('value' => $body, 'format' => 'filtered_html'))),
    'language' => LANGUAGE_NONE,    
    'name' => $user->name,
    'status' => 1,
    'type' => 'erpal_crm_activity',
    'promote' => 0,
    'sticky' => 0,
  );
  
  if ($origin_term_id || true) {
    $form_values['field_activity_origin'][LANGUAGE_NONE]['tid'] = $origin_term_id;
  }
  
  if ($customer_nid) {
    $form_values['field_customer_ref'][LANGUAGE_NONE][0]['target_id'] = _erpal_basic_helper_autocomplete_string_from_nid($customer_nid);
  }

  // node module stores form processing functions in a
  // seperate include entitled node.pages.inc
  // so must load that before executing form
  module_load_include('inc', 'node', 'node.pages');   
  $form_values['op'] = t('Save');  // this seems to be a required value
  $form_state['values'] = $form_values;
  
  $activity_node = array('type' => 'erpal_crm_activity');
  drupal_form_submit($form_id, $form_state, (object)$activity_node);
  $node = $form_state['node'];
  
  $errors = form_get_errors();
  //die(print_r($form_state['node']));
  
  if (!empty($errors)) {
    $returns['error'] = TRUE;
    $error_strings = '';
    foreach ($errors as $key => $value) {
      $error_string .= $key.": ".$value."<br/>";
    }
    $returns['message'] = 'Activity could not be created because of some errors: <br/>'.$error_string;
  } else {
    $returns['node'] = (array)$activity_node;
    $returns['error'] = false;
    $returns['message'] = '';
  }

  return $returns;
}

/**
 * Check access for creating a crm_activity node
 */
function _erpal_crm_service_crm_activity_access($op, $args) {

  return node_access($op, 'erpal_crm_activity');
}