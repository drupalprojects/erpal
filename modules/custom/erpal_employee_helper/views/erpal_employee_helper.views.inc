<?php

/**
 * @file
 * Providing extra functionality for the working_times UI via views.
 */

 
/**
 * Implements hook_views_data_alter()
 */
function erpal_employee_helper_views_data_alter(&$data) {     
  
  //user field integration
  $data['working_times']['uid']['field']['handler'] = 'views_handler_field_user';
  $data['working_times']['uid']['filter']['handler'] = 'views_handler_filter_user_current'; 
  
  
  //created field integration
  $data['working_times']['created']['field']['handler'] = 'views_handler_field_date';
  $data['working_times']['created']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //changed field integration
  $data['working_times']['changed']['field']['handler'] = 'views_handler_field_date';
  $data['working_times']['changed']['filter']['handler'] = 'date_views_filter_handler_simple';

  //holidays_available_till field integration
  $data['working_times']['holidays_available_till']['field']['handler'] = 'views_handler_field_date';
  $data['working_times']['holidays_available_till']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //changed field integration
  $data['working_times']['changed']['field']['handler'] = 'views_handler_field_date';
  $data['working_times']['changed']['filter']['handler'] = 'date_views_filter_handler_simple';
  
   
  //user relation integration
  // Relationship.
  $data['working_times']['uid']['relationship'] = array(
    'handler' => 'views_handler_relationship',
    'base' => 'users',
    'base field' => 'uid',
    'field' => 'uid',
    'label' => t('working times user'),
    'field_name' => 'uid',
    'help' => t('The user the working times are saved for'),
    'title' => t('working times user'),
  );
  
  $data['working_times']['uid']['filter']['handler'] = 'views_handler_filter_many_to_one';
  // Edit link
  $data['working_times']['edit_working_times'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for working time.'),
      'handler' => 'working_times_handler_edit_link_field',
    ),
  );
  // Delete link
  $data['working_times']['delete_working_times'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete working time.'),
      'handler' => 'working_times_handler_delete_link_field',
    ),
  );
}