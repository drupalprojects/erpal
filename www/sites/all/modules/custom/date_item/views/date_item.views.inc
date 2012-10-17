<?php

/**
 * @file
 * Providing extra functionality for date item views integration.
 */
 
/**
 * Implements hook_views_data_alter()
 */
function date_item_views_data_alter(&$data) {     
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

  foreach (entity_get_info() as $type => $entity_info) {
    $data['date_item'][$type] = array(
      'title' => t('Date item: @entity_type', array('@entity_type' => $type)),
      'help' => 'TODO',
      'relationship' => array(
        'base' => $entity_info['base table'],
        'base field' => $entity_info['entity keys']['id'],
        'relationship field' => 'src_id',
        'extra' => array(
          0 => array(
            'field' => 'src_type',
            'value' => $type,
          ),
        ),
      ),
    );
  }

}


//@TODO perhaps provide a default view