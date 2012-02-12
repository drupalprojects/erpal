<?php

/**
 * @file
 * Providing extra functionality for the Billable UI via views.
 */
 
/**
* Implementation of hook_date_api_fields
*/
function to_system_date_api_fields($field) {

  $values = array(
    // The type of date: DATE_UNIX, DATE_ISO, DATE_DATETIME.
    'sql_type' => DATE_UNIX,
    // Timezone handling options: 'none', 'site', 'date', 'utc'.
    'tz_handling' => 'date',
    // Needed only for dates that use 'date' tz_handling.
    'timezone_field' => '',
    // Needed only for dates that use 'date' tz_handling.
    'offset_field' => '',
    // Array of "table.field" values for related fields that should be
    // loaded automatically in the Views SQL.
    'related_fields' => array(),
    // Granularity of this date field's db data.
    'granularity' => array('year', 'month', 'day'),
  );
 
  switch ($field) {
    case 'billable.date_delivery':
    case 'billable.created':
    case 'billable.changed':
      return $values;
  }
}
 

/**
 * Implements hook_views_data()
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



//@TODO Default view for admin!

/**
 * Implements hook_views_default_views().
 */
function billable_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'billables';
  $view->description = 'A list of all billables';
  $view->tag = 'billables';
  $view->base_table = 'billable';
  $view->human_name = 'Billables';
  $view->core = 7;
  $view->api_version = '3.0-alpha1';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Billables';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create any billable type';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'billable_id' => 'billable_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'billable_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No billables have been created yet';
  /* Field: Billable: Billable ID */
  $handler->display->display_options['fields']['billable_id']['id'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['table'] = 'billable';
  $handler->display->display_options['fields']['billable_id']['field'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['billable_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['billable_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['billable_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['billable_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['billable_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['billable_id']['empty_zero'] = 0;
  /* Field: Billable: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'billable';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  /* Field: Billable: Link */
  $handler->display->display_options['fields']['link_billable']['id'] = 'link_billable';
  $handler->display->display_options['fields']['link_billable']['table'] = 'billable';
  $handler->display->display_options['fields']['link_billable']['field'] = 'link_billable';
  $handler->display->display_options['fields']['link_billable']['label'] = 'View';
  $handler->display->display_options['fields']['link_billable']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['link_billable']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['link_billable']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['link_billable']['alter']['external'] = 0;
  $handler->display->display_options['fields']['link_billable']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['link_billable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['link_billable']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['link_billable']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['link_billable']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['link_billable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['link_billable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['link_billable']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['link_billable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['link_billable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['link_billable']['empty_zero'] = 0;
  /* Field: Billable: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'billable';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['operations']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['operations']['empty_zero'] = 0;
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'billables_admin_page');
  $handler->display->display_options['path'] = 'admin/content/billables/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Billables';
  $handler->display->display_options['tab_options']['description'] = 'Manage billables';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $translatables['billables'] = array(
    t('Master'),
    t('Billables'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Empty '),
    t('No billables have been created yet'),
    t('Billable ID'),
    t('.'),
    t(','),
    t('Name'),
    t('View'),
    t('Operations links'),
    t('Page'),
  );
  $views[] = $view;
  return $views;

}
