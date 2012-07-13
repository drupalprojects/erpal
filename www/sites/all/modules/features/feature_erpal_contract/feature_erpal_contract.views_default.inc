<?php
/**
 * @file
 * feature_erpal_contract.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_erpal_contract_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'contracts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Contracts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contracts';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access contracts view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Contract payment (field_contract_payment) */
  $handler->display->display_options['relationships']['field_contract_payment_value']['id'] = 'field_contract_payment_value';
  $handler->display->display_options['relationships']['field_contract_payment_value']['table'] = 'field_data_field_contract_payment';
  $handler->display->display_options['relationships']['field_contract_payment_value']['field'] = 'field_contract_payment_value';
  $handler->display->display_options['relationships']['field_contract_payment_value']['required'] = 0;
  $handler->display->display_options['relationships']['field_contract_payment_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Field: Contractor */
  $handler->display->display_options['fields']['field_contractor_ref']['id'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['table'] = 'field_data_field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['field'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contractor_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contractor_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contractor_ref']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contractor_ref']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_contractor_ref']['field_api_classes'] = 0;
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_customer_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_customer_ref']['field_api_classes'] = 0;
  /* Field: Content: Contract type */
  $handler->display->display_options['fields']['field_contract_type']['id'] = 'field_contract_type';
  $handler->display->display_options['fields']['field_contract_type']['table'] = 'field_data_field_contract_type';
  $handler->display->display_options['fields']['field_contract_type']['field'] = 'field_contract_type';
  $handler->display->display_options['fields']['field_contract_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contract_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contract_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contract_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contract_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contract_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_contract_type']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_contract_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_contract_type']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_contract_type']['field_api_classes'] = 0;
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_date']['field_api_classes'] = 0;
  /* Field: Field collection item: Payment period */
  $handler->display->display_options['fields']['field_payment_period']['id'] = 'field_payment_period';
  $handler->display->display_options['fields']['field_payment_period']['table'] = 'field_data_field_payment_period';
  $handler->display->display_options['fields']['field_payment_period']['field'] = 'field_payment_period';
  $handler->display->display_options['fields']['field_payment_period']['relationship'] = 'field_contract_payment_value';
  /* Field: Field collection item: Payment type */
  $handler->display->display_options['fields']['field_payment_type']['id'] = 'field_payment_type';
  $handler->display->display_options['fields']['field_payment_type']['table'] = 'field_data_field_payment_type';
  $handler->display->display_options['fields']['field_payment_type']['field'] = 'field_payment_type';
  $handler->display->display_options['fields']['field_payment_type']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_payment_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_payment_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_payment_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_payment_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_payment_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_payment_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_payment_type']['field_api_classes'] = 0;
  /* Field: Field collection item: Price per month */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_price']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_price']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_price']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_price']['field_api_classes'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_contract' => 'erpal_contract',
  );
  /* Filter criterion: Field: Customer (field_customer_ref) */
  $handler->display->display_options['filters']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator_id'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['identifier'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['reduce'] = 0;
  /* Filter criterion: Field: Contractor (field_contractor_ref) */
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['id'] = 'field_contractor_ref_target_id';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['table'] = 'field_data_field_contractor_ref';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['field'] = 'field_contractor_ref_target_id';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['operator_id'] = 'field_contractor_ref_target_id_op';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['label'] = 'Contractor';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['operator'] = 'field_contractor_ref_target_id_op';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['identifier'] = 'field_contractor_ref_target_id';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['reduce'] = 0;

  /* Display: Contracts */
  $handler = $view->new_display('page', 'Contracts', 'page');
  $handler->display->display_options['path'] = 'contracts';
  $export['contracts'] = $view;

  return $export;
}
