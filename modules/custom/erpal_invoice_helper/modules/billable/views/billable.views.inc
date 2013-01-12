<?php

/**
 * @file
 * Providing extra functionality for the Billable UI via views.
 */

 
/**
 * Implements hook_views_data_alter()
 */
function billable_views_data_alter(&$data) {     
  
  //make date fields handled like date fields!
  //date_delivery field integration
  $data['billable']['date_delivery']['field']['handler'] = 'views_handler_field_date';
  $data['billable']['date_delivery']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //created field integration
  $data['billable']['created']['field']['handler'] = 'views_handler_field_date';
  $data['billable']['created']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //changed field integration
  $data['billable']['changed']['field']['handler'] = 'views_handler_field_date';
  $data['billable']['changed']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  $data['billable']['billed']['field']['handler'] = 'views_handler_field_boolean';
  $data['billable']['billed']['filter']['handler'] = 'views_handler_filter_boolean_operator';
 
  //nodereference handler for customer_nid
  // Relationship.
  $data['billable']['customer_nid']['relationship'] = array(
    'handler' => 'views_handler_relationship',
    'base' => 'node',
    'base field' => 'nid',
    'field' => 'customer_nid',
    'label' => t('Customer'),
    'field_name' => 'customer_nid',
    'help' => t('The customer nid of a billable'),
    'title' => t('Customer'),
  );
  
  $data['billable']['customer_nid']['filter']['handler'] = 'views_handler_filter_many_to_one';
  $data['billable']['customer_nid']['filter']['options callback'] = '_billable_get_customers';


  //nodereference handler for contractor_nid
  // Relationship.
  $data['billable']['contractor_nid']['relationship'] = array(
    'handler' => 'views_handler_relationship',
    'base' => 'node',
    'base field' => 'nid',
    'field' => 'contractor_nid',
    'label' => t('Contractor'),
    'field_name' => 'contractor_nid',
    'help' => t('The contractor nid of a billable'),
    'title' => t('Contractor'),
  );
  
  $data['billable']['contractor_nid']['filter']['handler'] = 'views_handler_filter_many_to_one';
  $data['billable']['contractor_nid']['filter']['options callback'] = '_billable_get_customers';

  //nodereference handler for subject_nid
  // Relationship.
  $data['billable']['subject_nid']['relationship'] = array(
    'handler' => 'views_handler_relationship',
    'base' => 'node',
    'base field' => 'nid',
    'field' => 'subject_nid',
    'label' => t('Billable subject'),
    'field_name' => 'subject_nid',
    'help' => t('The node nid of a billable Subject'),
    'title' => t('Billable subject'),
  );
  
  //add fields for the links
  $data['billable']['link_billable'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the billable.'),
      'handler' => 'billable_handler_link_field',
    ),
  );
  $data['billable']['edit_billable'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the billable.'),
      'handler' => 'billable_handler_edit_link_field',
    ),
  );
  $data['billable']['delete_billable'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the billable.'),
      'handler' => 'billable_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows billables/billable/%billable_id/op
  $data['billable']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this billable.'),
      'handler' => 'billable_handler_billable_operations_field',
    ),
  );
}


//@TODO perhaps provide a default view