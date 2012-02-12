<?php
/**
 * @file
 * feature_erpal_factura.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_erpal_factura_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'billables';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'billable';
  $view->human_name = 'Billables';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Billables';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
echo _erpal_factura_helper_view_billables_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Field: Billable: Billable ID */
  $handler->display->display_options['fields']['billable_id']['id'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['table'] = 'billable';
  $handler->display->display_options['fields']['billable_id']['field'] = 'billable_id';
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_customer_ref']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_customer_ref']['field_api_classes'] = 0;
  /* Field: Billable: Billed */
  $handler->display->display_options['fields']['billed']['id'] = 'billed';
  $handler->display->display_options['fields']['billed']['table'] = 'billable';
  $handler->display->display_options['fields']['billed']['field'] = 'billed';
  $handler->display->display_options['fields']['billed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['billed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['billed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['billed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['billed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['billed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['billed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['billed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['billed']['hide_alter_empty'] = 1;
  /* Field: Billable: Date_delivery */
  $handler->display->display_options['fields']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['fields']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['label'] = 'Date delivery';
  $handler->display->display_options['fields']['date_delivery']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['external'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['date_delivery']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['date_delivery']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['date_delivery']['alter']['html'] = 0;
  $handler->display->display_options['fields']['date_delivery']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['date_delivery']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['date_delivery']['hide_empty'] = 0;
  $handler->display->display_options['fields']['date_delivery']['empty_zero'] = 0;
  $handler->display->display_options['fields']['date_delivery']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['date_delivery']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date_delivery']['custom_date_format'] = 'Y-m-d';
  /* Field: Billable: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'billable';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['external'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['quantity']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['quantity']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['quantity']['alter']['html'] = 0;
  $handler->display->display_options['fields']['quantity']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['quantity']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['quantity']['hide_empty'] = 0;
  $handler->display->display_options['fields']['quantity']['empty_zero'] = 0;
  $handler->display->display_options['fields']['quantity']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['quantity']['set_precision'] = 0;
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  $handler->display->display_options['fields']['quantity']['format_plural'] = 0;
  /* Field: Billable: Single_price */
  $handler->display->display_options['fields']['single_price']['id'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['table'] = 'billable';
  $handler->display->display_options['fields']['single_price']['field'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['label'] = 'Single price';
  $handler->display->display_options['fields']['single_price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['single_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['single_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['single_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['single_price']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['single_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['single_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['single_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['single_price']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['single_price']['set_precision'] = 1;
  $handler->display->display_options['fields']['single_price']['precision'] = '2';
  $handler->display->display_options['fields']['single_price']['format_plural'] = 0;
  /* Field: Billable: Total_price_no_vat */
  $handler->display->display_options['fields']['total_price_no_vat']['id'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price_no_vat']['field'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['label'] = 'Total excl. VAT';
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['external'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['alter']['html'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['total_price_no_vat']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['total_price_no_vat']['hide_empty'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['empty_zero'] = 0;
  $handler->display->display_options['fields']['total_price_no_vat']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['total_price_no_vat']['set_precision'] = 1;
  $handler->display->display_options['fields']['total_price_no_vat']['precision'] = '2';
  $handler->display->display_options['fields']['total_price_no_vat']['format_plural'] = 0;
  /* Field: Billable: Total_vat */
  $handler->display->display_options['fields']['total_vat']['id'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_vat']['field'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['label'] = 'Total VAT';
  $handler->display->display_options['fields']['total_vat']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['external'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['total_vat']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['total_vat']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['total_vat']['alter']['html'] = 0;
  $handler->display->display_options['fields']['total_vat']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['total_vat']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['total_vat']['hide_empty'] = 0;
  $handler->display->display_options['fields']['total_vat']['empty_zero'] = 0;
  $handler->display->display_options['fields']['total_vat']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['total_vat']['set_precision'] = 1;
  $handler->display->display_options['fields']['total_vat']['precision'] = '2';
  $handler->display->display_options['fields']['total_vat']['format_plural'] = 0;
  /* Field: Billable: Total_price */
  $handler->display->display_options['fields']['total_price']['id'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price']['field'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['label'] = 'Total';
  $handler->display->display_options['fields']['total_price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['total_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['total_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['total_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['total_price']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['total_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['total_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['total_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['total_price']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['total_price']['set_precision'] = 1;
  $handler->display->display_options['fields']['total_price']['precision'] = '2';
  $handler->display->display_options['fields']['total_price']['format_plural'] = 0;
  /* Field: Billable: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'billable';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  $handler->display->display_options['fields']['currency']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['external'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['currency']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['currency']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['currency']['alter']['html'] = 0;
  $handler->display->display_options['fields']['currency']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['currency']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['currency']['hide_empty'] = 0;
  $handler->display->display_options['fields']['currency']['empty_zero'] = 0;
  $handler->display->display_options['fields']['currency']['hide_alter_empty'] = 1;
  /* Field: Billable: Edit Link */
  $handler->display->display_options['fields']['edit_billable']['id'] = 'edit_billable';
  $handler->display->display_options['fields']['edit_billable']['table'] = 'billable';
  $handler->display->display_options['fields']['edit_billable']['field'] = 'edit_billable';
  $handler->display->display_options['fields']['edit_billable']['label'] = '';
  $handler->display->display_options['fields']['edit_billable']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_billable']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_billable']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_billable']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_billable']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_billable']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_billable']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_billable']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_billable']['hide_alter_empty'] = 1;
  /* Sort criterion: Billable: Date_delivery */
  $handler->display->display_options['sorts']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['sorts']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['sorts']['date_delivery']['field'] = 'date_delivery';
  /* Filter criterion: Field: Customer (field_customer_ref) */
  $handler->display->display_options['filters']['field_customer_ref_nid']['id'] = 'field_customer_ref_nid';
  $handler->display->display_options['filters']['field_customer_ref_nid']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['filters']['field_customer_ref_nid']['field'] = 'field_customer_ref_nid';
  $handler->display->display_options['filters']['field_customer_ref_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['operator_id'] = 'field_customer_ref_nid_op';
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['operator'] = 'field_customer_ref_nid_op';
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['identifier'] = 'field_customer_ref_nid';
  $handler->display->display_options['filters']['field_customer_ref_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Billable: Date_delivery */
  $handler->display->display_options['filters']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['filters']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['operator'] = 'between';
  $handler->display->display_options['filters']['date_delivery']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_delivery']['expose']['operator_id'] = 'date_delivery_op';
  $handler->display->display_options['filters']['date_delivery']['expose']['label'] = 'Delivery';
  $handler->display->display_options['filters']['date_delivery']['expose']['operator'] = 'date_delivery_op';
  $handler->display->display_options['filters']['date_delivery']['expose']['identifier'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['date_delivery']['form_type'] = 'date_popup';
  /* Filter criterion: Billable: Billed */
  $handler->display->display_options['filters']['billed']['id'] = 'billed';
  $handler->display->display_options['filters']['billed']['table'] = 'billable';
  $handler->display->display_options['filters']['billed']['field'] = 'billed';
  $handler->display->display_options['filters']['billed']['value'] = '0';
  $handler->display->display_options['filters']['billed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['billed']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['billed']['expose']['label'] = 'True';
  $handler->display->display_options['filters']['billed']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['billed']['expose']['operator'] = 'billed_op';
  $handler->display->display_options['filters']['billed']['expose']['identifier'] = 'billed';
  $handler->display->display_options['filters']['billed']['expose']['required'] = 1;
  $handler->display->display_options['filters']['billed']['expose']['multiple'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'factura/billables';
  $export['billables'] = $view;

  return $export;
}
