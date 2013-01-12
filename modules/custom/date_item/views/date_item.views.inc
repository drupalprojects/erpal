<?php

/**
 * @file
 * Providing extra functionality for date item views integration.
 */
 
/**
* Implements hook_views_data
*/
function date_item_views_data() {
  // Define the base group of this table.
  $data['date_item']['table']['group']  = t('Date item');
  
  // Advertise this table as a possible base table
  $data['date_item']['table']['base'] = array(
    'field' => 'date_item_id',
    'title' => t('Date item'),
    'weight' => -10,
  );
  $data['date_item']['table']['entity type'] = 'date_item';
  $data['date_item']['date_item_id'] = array(
    'title' => t('Date item ID'),
    'help' => t('The date item ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['date_item']['type'] = array(
    'title' => t('Date item type'),
    'help' => t('The date item type.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'options callback' => 'date_item_get_types_options',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['date_item']['uid'] = array(
    'title' => t('Uid'),
    'help' => t('The date item uid.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'label' => 'relation author',
      'title' => t('Relation Author'),
      'base' => 'users',
      'base field' => 'uid',
    ),
  );
  
  //@TODO actually this only works for nodes, later we should prepare this to be compatible with all entities
  $data['date_item']['src_id'] = array(
    'title' => t('Src node'),
    'help' => t('The referenced source entity'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'label' => 'relation src node',
      'title' => t('Referenced source node'),
      'base' => 'node',
      'base field' => 'nid',
    ),
  );
  
  $data['date_item']['created'] = array(
    'title' => t('Create Date'),
    'help' => t('The date when the date item was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['date_item']['updated'] = array(
    'title' => t('Update Date'),
    'help' => t('The date when the date item was updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  
  $data['date_item']['date_from'] = array(
    'title' => t('Date item date from'),
    'help' => t('The date till of the date item.'),    
    'field' => array(
      'handler' => 'views_handler_field_date',
      'real field' => 'date_from',
      'additional fields' => array('date_from', 'date_till'),
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['date_item']['date_till'] = array(
    'title' => t('Date item date till'),
    'help' => t('The date till of the date item.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'real field' => 'date_from',
      'additional fields' => array('date_from', 'date_till'),
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['date_item']['entity_label'] = array(
    'title' => t('Entity label'),
    'help' => t('A label of the entity the date_item is coming from, optionally linked'),
    'field' => array(
      'handler' => 'date_item_handler_field_entity_label',
      'real field' => 'src_id',
    ),
  );
  
  return $data;
}
