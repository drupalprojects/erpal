<?php

/**
* @file all functions needed to make contacts accessible by services
* @author Manuel Pistner <pistner@brightsolutions.de>
* @copyright (c) 2013
*/


/**
 * Create a new contact node by services module request
 * @param array $contact the data delivered by the webservice, $contact['contact'] must be an array
 * @return the activity that was created or an error of activity could not be created
 * @TODO: maybe use drupal_form_submit or _node_resource_create to have validation instead of node_save
 */
function _erpal_basic_service_contact_create($contact) {
  $returns = array();
  global $user;

  $value = $contact['contact'];

  //if we don't have title, take the first 65 chars from body
  $firstname = isset($value['firstname']) ? $value['firstname'] : '';
  $lastname = isset($value['lastname']) ? $value['lastname'] : '';
  $email = isset($value['email']) ? $value['email'] : '';
  $customer_nid = isset($value['customer_nid']) ? $value['customer_nid'] : false;
  $type = 'person'; //@TODO: maybe later this should be selectable via rest service..
 
  
  $form_id = 'erpal_contact_node_form';
  $form_values = array(
    'field_firstname' => array(LANGUAGE_NONE => array(0 => array('value' => $firstname))),
    'field_lastname' => array(LANGUAGE_NONE => array(0 => array('value' => $lastname))),    
    'language' => LANGUAGE_NONE,    
    'name' => $user->name,
    'status' => 1,
    'type' => 'erpal_contact',
    'promote' => 0,
    'sticky' => 0,
  );
 todfo ab hier ungetestet!
  //check if there is already a contact with the given name and emailadress, if so, return this nid
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'erpal_contact')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_firstname', 'value', $firstname)
    ->fieldCondition('field_lastname', 'value', $lastname)
    ->fieldCondition('field_email', ' value', $email)   
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  $result = $query->execute();

  $contact_nid = false;
  if (isset($result['node'])) {
    $contact_nids = array_keys($result['node']);
    $contact_nid = reset($contact_nids);
  }
  
  if (!$contact_nid) {  //if there is no contact, create one
    // node module stores form processing functions in a
    // seperate include entitled node.pages.inc
    // so must load that before executing form
    module_load_include('inc', 'node', 'node.pages');   
    $form_values['op'] = t('Save');  // this seems to be a required value
    $form_state['values'] = $form_values;
    
    $activity_node = array('type' => 'erpal_crm_activity');
    drupal_form_submit($form_id, $form_state, (object)$contact_node);
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
      $returns['nid'] = (array)$contact_node;
      $returns['error'] = false;
      $returns['message'] = '';
    }
  } else {
    //node already exists
    $returns['nid'] = $contact_nid;
    $returns['error'] = false;
    $returns['message'] = '';
  }

  return $returns;
}

/**
 * Check access for creating a contact node
 */
function _erpal_basic_service_contact_access($op, $args) {

  return node_access($op, 'erpal_contact');
}