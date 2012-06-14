<?php

/**
* Add field conditions as long as conditional fields module is in dev state....
*/
function _erpal_basic_helper_contact_node_form_field_conditions(&$form, &$form_state) {
  //hide field_company_name if field_contact_type is person
  $form['field_company_name']['#states'] = array(    
    'invisible' => array(
      ':input[name="field_contact_type[und]"]' => array('value' => 'person'),
    ),
  );
  
  //hide field_firstname, field_lastname, field_gender if field_contact_type is person
  $form['field_firstname']['#states'] = array(    
    'invisible' => array(
      ':input[name="field_contact_type[und]"]' => array('value' => 'company'),
    ),
  );
  $form['field_lastname']['#states'] = array(    
    'invisible' => array(
      ':input[name="field_contact_type[und]"]' => array('value' => 'company'),
    ),
  );
  $form['field_gender']['#states'] = array(    
    'invisible' => array(
      ':input[name="field_contact_type[und]"]' => array('value' => 'company'),
    ),
  );
}