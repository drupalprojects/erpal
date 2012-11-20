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

  $view = new view();
  $view->name = 'cancelations_by_contract';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'date_item';
  $view->human_name = 'Cancelations by Contract';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'date_item_id' => 'date_item_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'date_item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Date item: Date item date from */
  $handler->display->display_options['fields']['date_from']['id'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['table'] = 'date_item';
  $handler->display->display_options['fields']['date_from']['field'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['label'] = 'Next cancelation deadline';
  $handler->display->display_options['fields']['date_from']['date_format'] = 'erpal_date';
  /* Field: date item: Date tags */
  $handler->display->display_options['fields']['field_date_item_tags']['id'] = 'field_date_item_tags';
  $handler->display->display_options['fields']['field_date_item_tags']['table'] = 'field_data_field_date_item_tags';
  $handler->display->display_options['fields']['field_date_item_tags']['field'] = 'field_date_item_tags';
  $handler->display->display_options['fields']['field_date_item_tags']['label'] = 'Category';
  $handler->display->display_options['fields']['field_date_item_tags']['type'] = 'taxonomy_term_reference_plain';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['cancelations_by_contract'] = $view;

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access contracts view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
echo _erpal_contract_helper_view_contracts_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No contract available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Contract payment (field_contract_payment) */
  $handler->display->display_options['relationships']['field_contract_payment_value']['id'] = 'field_contract_payment_value';
  $handler->display->display_options['relationships']['field_contract_payment_value']['table'] = 'field_data_field_contract_payment';
  $handler->display->display_options['relationships']['field_contract_payment_value']['field'] = 'field_contract_payment_value';
  $handler->display->display_options['relationships']['field_contract_payment_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Contractor */
  $handler->display->display_options['fields']['field_contractor_ref']['id'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['table'] = 'field_data_field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['field'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_contractor_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Contract type */
  $handler->display->display_options['fields']['field_contract_type']['id'] = 'field_contract_type';
  $handler->display->display_options['fields']['field_contract_type']['table'] = 'field_data_field_contract_type';
  $handler->display->display_options['fields']['field_contract_type']['field'] = 'field_contract_type';
  $handler->display->display_options['fields']['field_contract_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_contract_type']['delta_offset'] = '0';
  /* Field: Field: Period */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
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
  /* Field: Field collection item: Price per month */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['relationship'] = 'field_contract_payment_value';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
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

  /* Display: Contracts */
  $handler = $view->new_display('page', 'Contracts', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'contracts';

  /* Display: Budgets by contract pane */
  $handler = $view->new_display('panel_pane', 'Budgets by contract pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Budgets';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No budget available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Budget booking (field_budget_booking) */
  $handler->display->display_options['relationships']['field_budget_booking_value']['id'] = 'field_budget_booking_value';
  $handler->display->display_options['relationships']['field_budget_booking_value']['table'] = 'field_data_field_budget_booking';
  $handler->display->display_options['relationships']['field_budget_booking_value']['field'] = 'field_budget_booking_value';
  $handler->display->display_options['relationships']['field_budget_booking_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_budgets_target_id']['id'] = 'field_budgets_target_id';
  $handler->display->display_options['relationships']['field_budgets_target_id']['table'] = 'field_data_field_budgets';
  $handler->display->display_options['relationships']['field_budgets_target_id']['field'] = 'field_budgets_target_id';
  $handler->display->display_options['relationships']['field_budgets_target_id']['relationship'] = 'field_budget_booking_value';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Budget: Budget ID */
  $handler->display->display_options['fields']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['table'] = 'budget';
  $handler->display->display_options['fields']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['fields']['budget_id']['relationship'] = 'field_budgets_target_id';
  $handler->display->display_options['fields']['budget_id']['separator'] = '';
  /* Field: Budget: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'budget';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'field_budgets_target_id';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Budget: Total_hours */
  $handler->display->display_options['fields']['total_hours']['id'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['table'] = 'budget';
  $handler->display->display_options['fields']['total_hours']['field'] = 'total_hours';
  $handler->display->display_options['fields']['total_hours']['relationship'] = 'field_budgets_target_id';
  $handler->display->display_options['fields']['total_hours']['label'] = 'Total hours';
  $handler->display->display_options['fields']['total_hours']['precision'] = '0';
  /* Field: Budget: Available_hours */
  $handler->display->display_options['fields']['available_hours']['id'] = 'available_hours';
  $handler->display->display_options['fields']['available_hours']['table'] = 'budget';
  $handler->display->display_options['fields']['available_hours']['field'] = 'available_hours';
  $handler->display->display_options['fields']['available_hours']['relationship'] = 'field_budgets_target_id';
  $handler->display->display_options['fields']['available_hours']['label'] = 'Available hours';
  $handler->display->display_options['fields']['available_hours']['precision'] = '0';
  /* Field: Budget: Date_from */
  $handler->display->display_options['fields']['date_from']['id'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['table'] = 'budget';
  $handler->display->display_options['fields']['date_from']['field'] = 'date_from';
  $handler->display->display_options['fields']['date_from']['relationship'] = 'field_budgets_target_id';
  $handler->display->display_options['fields']['date_from']['label'] = 'Date from';
  $handler->display->display_options['fields']['date_from']['date_format'] = 'short';
  /* Field: Budget: Date_till */
  $handler->display->display_options['fields']['date_till']['id'] = 'date_till';
  $handler->display->display_options['fields']['date_till']['table'] = 'budget';
  $handler->display->display_options['fields']['date_till']['field'] = 'date_till';
  $handler->display->display_options['fields']['date_till']['relationship'] = 'field_budgets_target_id';
  $handler->display->display_options['fields']['date_till']['label'] = 'Date till';
  $handler->display->display_options['fields']['date_till']['date_format'] = 'short';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Budget: Created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'budget';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['relationship'] = 'field_budgets_target_id';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['form_type'] = 'date_popup';
  /* Filter criterion: Budget: Budget ID */
  $handler->display->display_options['filters']['budget_id']['id'] = 'budget_id';
  $handler->display->display_options['filters']['budget_id']['table'] = 'budget';
  $handler->display->display_options['filters']['budget_id']['field'] = 'budget_id';
  $handler->display->display_options['filters']['budget_id']['relationship'] = 'field_budgets_target_id';
  $handler->display->display_options['filters']['budget_id']['operator'] = '>';
  $handler->display->display_options['filters']['budget_id']['value']['value'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['contracts'] = $view;

  return $export;
}
