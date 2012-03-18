<?php
/**
 * @file
 * feature_erpal_invoice.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_erpal_invoice_views_default_views() {
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
echo _erpal_invoice_helper_view_billables_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Relationship: Billable: Customer */
  $handler->display->display_options['relationships']['customer_nid']['id'] = 'customer_nid';
  $handler->display->display_options['relationships']['customer_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['customer_nid']['field'] = 'customer_nid';
  $handler->display->display_options['relationships']['customer_nid']['required'] = 0;
  /* Field: Billable: Bulk operations */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'billable';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'erpal_invoice_helper_invoice_from_billables_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'erpal_invoice_helper_invoice_from_billables_reduced_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'billable_reduce_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'billable_reduce_by_single_price_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Billable: Billable ID */
  $handler->display->display_options['fields']['billable_id']['id'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['table'] = 'billable';
  $handler->display->display_options['fields']['billable_id']['field'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['billable_id']['alter']['path'] = 'billable/[billable_id]/view';
  $handler->display->display_options['fields']['billable_id']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['external'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['billable_id']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['billable_id']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['billable_id']['alter']['html'] = 0;
  $handler->display->display_options['fields']['billable_id']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['billable_id']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['billable_id']['hide_empty'] = 0;
  $handler->display->display_options['fields']['billable_id']['empty_zero'] = 0;
  $handler->display->display_options['fields']['billable_id']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['billable_id']['separator'] = '';
  $handler->display->display_options['fields']['billable_id']['format_plural'] = 0;
  /* Field: Billable: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'billable';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['external'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['subject']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['subject']['alter']['html'] = 0;
  $handler->display->display_options['fields']['subject']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['subject']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['subject']['hide_empty'] = 0;
  $handler->display->display_options['fields']['subject']['empty_zero'] = 0;
  $handler->display->display_options['fields']['subject']['hide_alter_empty'] = 1;
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'customer_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Customer';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Billable: Date_delivery */
  $handler->display->display_options['sorts']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['sorts']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['sorts']['date_delivery']['field'] = 'date_delivery';
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
  $handler->display->display_options['filters']['billed']['expose']['label'] = 'Billed';
  $handler->display->display_options['filters']['billed']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['billed']['expose']['operator'] = 'billed_op';
  $handler->display->display_options['filters']['billed']['expose']['identifier'] = 'billed';
  $handler->display->display_options['filters']['billed']['expose']['required'] = 1;
  $handler->display->display_options['filters']['billed']['expose']['multiple'] = FALSE;
  /* Filter criterion: Billable: Customer_nid */
  $handler->display->display_options['filters']['customer_nid']['id'] = 'customer_nid';
  $handler->display->display_options['filters']['customer_nid']['table'] = 'billable';
  $handler->display->display_options['filters']['customer_nid']['field'] = 'customer_nid';
  $handler->display->display_options['filters']['customer_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['customer_nid']['expose']['operator_id'] = 'customer_nid_op';
  $handler->display->display_options['filters']['customer_nid']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['customer_nid']['expose']['operator'] = 'customer_nid_op';
  $handler->display->display_options['filters']['customer_nid']['expose']['identifier'] = 'customer_nid';
  $handler->display->display_options['filters']['customer_nid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['customer_nid']['reduce_duplicates'] = 0;
  /* Filter criterion: Billable: Parent_billable */
  $handler->display->display_options['filters']['parent_billable']['id'] = 'parent_billable';
  $handler->display->display_options['filters']['parent_billable']['table'] = 'billable';
  $handler->display->display_options['filters']['parent_billable']['field'] = 'parent_billable';
  $handler->display->display_options['filters']['parent_billable']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'invoice/billables';
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
    t('<?php
echo _erpal_invoice_helper_view_billables_header_content();
?>'),
    t('Customer'),
    t('Billable ID'),
    t('billable/[billable_id]/view'),
    t('.'),
    t('Subject'),
    t('Billed'),
    t('Date delivery'),
    t('Quantity'),
    t(','),
    t('Single price'),
    t('Total excl. VAT'),
    t('Total VAT'),
    t('Total'),
    t('Currency'),
    t('Delivery'),
    t('Page'),
  );
  $export['billables'] = $view;

  $view = new view;
  $view->name = 'invoices';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Invoices';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Invoices';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    7 => '7',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 1;
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
echo _erpal_invoice_helper_view_invoices_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
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
  /* Field: Content: Contacts */
  $handler->display->display_options['fields']['field_contact_ref']['id'] = 'field_contact_ref';
  $handler->display->display_options['fields']['field_contact_ref']['table'] = 'field_data_field_contact_ref';
  $handler->display->display_options['fields']['field_contact_ref']['field'] = 'field_contact_ref';
  $handler->display->display_options['fields']['field_contact_ref']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_contact_ref']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_contact_ref']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_contact_ref']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_contact_ref']['field_api_classes'] = 0;
  /* Field: Content: Invoice Date */
  $handler->display->display_options['fields']['field_invoice_date']['id'] = 'field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['table'] = 'field_data_field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['field'] = 'field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_invoice_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_invoice_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_invoice_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_invoice_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_invoice_date']['field_api_classes'] = 0;
  /* Field: Content: Invoice Number */
  $handler->display->display_options['fields']['field_invoice_number']['id'] = 'field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['table'] = 'field_data_field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['field'] = 'field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_invoice_number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_invoice_number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_invoice_number']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_invoice_number']['field_api_classes'] = 0;
  /* Field: Content: Payed */
  $handler->display->display_options['fields']['field_payed']['id'] = 'field_payed';
  $handler->display->display_options['fields']['field_payed']['table'] = 'field_data_field_payed';
  $handler->display->display_options['fields']['field_payed']['field'] = 'field_payed';
  $handler->display->display_options['fields']['field_payed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_payed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_payed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_payed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_payed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_payed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_payed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_payed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_payed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_payed']['field_api_classes'] = 0;
  /* Field: Content: Payment date */
  $handler->display->display_options['fields']['field_payment_date']['id'] = 'field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['table'] = 'field_data_field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['field'] = 'field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_payment_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_payment_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_payment_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_payment_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_payment_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_payment_date']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_payment_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_payment_date']['field_api_classes'] = 0;
  /* Field: Content: Total excl. VAT */
  $handler->display->display_options['fields']['field_price_no_vat']['id'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['table'] = 'field_data_field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['field'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_price_no_vat']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_price_no_vat']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_price_no_vat']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_price_no_vat']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_price_no_vat']['field_api_classes'] = 0;
  /* Field: Content: Total incl. VAT */
  $handler->display->display_options['fields']['field_invoice_total']['id'] = 'field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['table'] = 'field_data_field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['field'] = 'field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_invoice_total']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_invoice_total']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_invoice_total']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_invoice_total']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_invoice_total']['field_api_classes'] = 0;
  /* Field: Field: Currency */
  $handler->display->display_options['fields']['field_currency']['id'] = 'field_currency';
  $handler->display->display_options['fields']['field_currency']['table'] = 'field_data_field_currency';
  $handler->display->display_options['fields']['field_currency']['field'] = 'field_currency';
  $handler->display->display_options['fields']['field_currency']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_currency']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_currency']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_currency']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_currency']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_currency']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_currency']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_currency']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_currency']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_currency']['field_api_classes'] = 0;
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
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Contacts (field_contact_ref) */
  $handler->display->display_options['filters']['field_contact_ref_nid']['id'] = 'field_contact_ref_nid';
  $handler->display->display_options['filters']['field_contact_ref_nid']['table'] = 'field_data_field_contact_ref';
  $handler->display->display_options['filters']['field_contact_ref_nid']['field'] = 'field_contact_ref_nid';
  $handler->display->display_options['filters']['field_contact_ref_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_ref_nid']['expose']['operator_id'] = 'field_contact_ref_nid_op';
  $handler->display->display_options['filters']['field_contact_ref_nid']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_contact_ref_nid']['expose']['operator'] = 'field_contact_ref_nid_op';
  $handler->display->display_options['filters']['field_contact_ref_nid']['expose']['identifier'] = 'field_contact_ref_nid';
  $handler->display->display_options['filters']['field_contact_ref_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Invoice Date (field_invoice_date) */
  $handler->display->display_options['filters']['field_invoice_date_value']['id'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['table'] = 'field_data_field_invoice_date';
  $handler->display->display_options['filters']['field_invoice_date_value']['field'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['operator_id'] = 'field_invoice_date_value_op';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['label'] = 'Invoice Date';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['operator'] = 'field_invoice_date_value_op';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['identifier'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Invoice Number (field_invoice_number) */
  $handler->display->display_options['filters']['field_invoice_number_value']['id'] = 'field_invoice_number_value';
  $handler->display->display_options['filters']['field_invoice_number_value']['table'] = 'field_data_field_invoice_number';
  $handler->display->display_options['filters']['field_invoice_number_value']['field'] = 'field_invoice_number_value';
  $handler->display->display_options['filters']['field_invoice_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['operator_id'] = 'field_invoice_number_value_op';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['label'] = 'Invoice Number';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['operator'] = 'field_invoice_number_value_op';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['identifier'] = 'field_invoice_number_value';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Payed (field_payed) */
  $handler->display->display_options['filters']['field_payed_value']['id'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['table'] = 'field_data_field_payed';
  $handler->display->display_options['filters']['field_payed_value']['field'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator_id'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['label'] = 'Payed';
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['identifier'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_invoice' => 'erpal_invoice',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'invoice/invoices';
  $translatables['invoices'] = array(
    t('Master'),
    t('Invoices'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('<?php
echo _erpal_invoice_helper_view_invoices_header_content();
?>'),
    t('Contacts'),
    t('Invoice Date'),
    t('Invoice Number'),
    t('Payed'),
    t('Payment date'),
    t('Total excl. VAT'),
    t('Total incl. VAT'),
    t('Currency'),
    t('Customer'),
    t('Page'),
  );
  $export['invoices'] = $view;

  return $export;
}
