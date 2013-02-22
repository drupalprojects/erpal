<?php

/**
 * @file
 * Providing extra functionality for the timetracking UI via views.
 */
 
module_load_include('inc', 'timetracking', 'timetracking.configurable');
 
/**
 * Implements hook_views_data_alter()
 */
function timetracking_views_data_alter(&$data) {     
  
  //make date fields handled like date fields!
  //time_from field integration
  $data['timetracking']['time_start']['field']['handler'] = 'views_handler_field_date';
  $data['timetracking']['time_start']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //date_till field integration
  $data['timetracking']['time_end']['field']['handler'] = 'views_handler_field_date';
  $data['timetracking']['time_end']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //created field integration
  $data['timetracking']['created']['field']['handler'] = 'views_handler_field_date';
  $data['timetracking']['created']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //changed field integration
  $data['timetracking']['changed']['field']['handler'] = 'views_handler_field_date';
  $data['timetracking']['changed']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //user field integration
  $data['timetracking']['uid']['field']['handler'] = 'views_handler_field_user';
  $data['timetracking']['uid']['filter']['handler'] = 'views_handler_filter_user_current';  

  //nodereference handler for subject_nid
  // Relationship.
  $data['timetracking']['subject_id']['relationship'] = array(
    'handler' => 'views_handler_relationship',
    'base' => 'node',
    'base field' => 'nid',
    'field' => 'subject_id',
    'label' => t('Timetracking subject'),
    'field_name' => 'subject_id',
    'help' => t('The node nid of a timetracking Subject'),
    'title' => t('Timetracking subject'),
  );
  
  $data['timetracking']['subject_id']['filter']['handler'] = 'views_handler_filter_many_to_one';
  
  //user relation integration
  //nodereference handler for subject_nid
  // Relationship.
  $data['timetracking']['uid']['relationship'] = array(
    'handler' => 'views_handler_relationship',
    'base' => 'users',
    'base field' => 'uid',
    'field' => 'uid',
    'label' => t('Timetracking user'),
    'field_name' => 'uid',
    'help' => t('The user that created the timetracking'),
    'title' => t('Timetracking user'),
  );
  
  $data['timetracking']['uid']['filter']['handler'] = 'views_handler_filter_many_to_one';
  
  $data['timetracking']['edit_timetracking'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the timetracking.'),
      'handler' => 'timetracking_handler_edit_link_field',
    ),
  );
  $data['timetracking']['delete_timetracking'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the timetracking.'),
      'handler' => 'timetracking_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows timetrackings/timetracking/%timetracking_id/op
  $data['timetracking']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this timetracking.'),
      'handler' => 'timetracking_handler_timetracking_operations_field',
    ),
  );
}