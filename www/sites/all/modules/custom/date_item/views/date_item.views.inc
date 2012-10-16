<?php

/**
 * @file
 * Providing extra functionality for date item views integration.
 */
 
/**
 * Implements hook_views_data_alter()
 */
function budget_views_data_alter(&$data) {     
  
  //make date fields handled like date fields!
  //date_from field integration
  $data['date_item']['date_from']['field']['handler'] = 'views_handler_field_date';
  $data['date_item']['date_from']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //date_till field integration
  $data['date_item']['date_till']['field']['handler'] = 'views_handler_field_date';
  $data['date_item']['date_till']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //created field integration
  $data['date_item']['created']['field']['handler'] = 'views_handler_field_date';
  $data['date_item']['created']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //updated field integration
  $data['date_item']['updated']['field']['handler'] = 'views_handler_field_date';
  $data['date_item']['updated']['filter']['handler'] = 'date_views_filter_handler_simple';

/*  @TODO hier muss für src_id ein entity referenz handler hin, damit wir auf den src entity referenzieren können 
siehe auch entityreference.views.inc im entityreference modul 
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
*/


}


//@TODO perhaps provide a default view