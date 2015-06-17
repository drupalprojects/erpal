<?php

/**
 * @file
 * Providing extra functionality for the budget UI via views.
 */
 
/**
 * Implements hook_views_data_alter()
 */
function budget_views_data_alter(&$data) {     
  
  //make date fields handled like date fields!
  //date_from field integration
  $data['budget']['date_from']['field']['handler'] = 'views_handler_field_date';
  $data['budget']['date_from']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //date_till field integration
  $data['budget']['date_till']['field']['handler'] = 'views_handler_field_date';
  $data['budget']['date_till']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //created field integration
  $data['budget']['created']['field']['handler'] = 'views_handler_field_date';
  $data['budget']['created']['filter']['handler'] = 'date_views_filter_handler_simple';
  
  //changed field integration
  $data['budget']['changed']['field']['handler'] = 'views_handler_field_date';
  $data['budget']['changed']['filter']['handler'] = 'date_views_filter_handler_simple';

  //add fields for the links
  $data['budget']['link_budget'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a link to the budget.'),
      'handler' => 'budget_handler_link_field',
    ),
  );
  $data['budget']['edit_budget'] = array(
    'field' => array(
      'title' => t('Edit Link'),
      'help' => t('Provide a link to the edit form for the budget.'),
      'handler' => 'budget_handler_edit_link_field',
    ),
  );
  $data['budget']['delete_budget'] = array(
    'field' => array(
      'title' => t('Delete Link'),
      'help' => t('Provide a link to delete the budget.'),
      'handler' => 'budget_handler_delete_link_field',
    ),
  );
  // This content of this field are decided based on the menu structure that
  // follows budgets/budget/%budget_id/op
  $data['budget']['operations'] = array(
    'field' => array(
      'title' => t('Operations links'),
      'help' => t('Display all operations available for this budget.'),
      'handler' => 'budget_handler_budget_operations_field',
    ),
  );
}