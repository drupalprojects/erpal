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

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access billables view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
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
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No billable available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Billable: Contractor */
  $handler->display->display_options['relationships']['contractor_nid']['id'] = 'contractor_nid';
  $handler->display->display_options['relationships']['contractor_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['contractor_nid']['field'] = 'contractor_nid';
  /* Relationship: Billable: Customer */
  $handler->display->display_options['relationships']['customer_nid']['id'] = 'customer_nid';
  $handler->display->display_options['relationships']['customer_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['customer_nid']['field'] = 'customer_nid';
  /* Relationship: Billable: Billable subject */
  $handler->display->display_options['relationships']['subject_nid']['id'] = 'subject_nid';
  $handler->display->display_options['relationships']['subject_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['subject_nid']['field'] = 'subject_nid';
  /* Field: Bulk operations: Billable */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'billable';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::erpal_invoice_helper_invoice_from_billables_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_delete_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_reduce_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_billed_action' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_unbilled_action' => array(
      'selected' => 1,
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
  $handler->display->display_options['fields']['billable_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['billable_id']['alter']['path'] = 'billable/[billable_id]/view';
  $handler->display->display_options['fields']['billable_id']['separator'] = '';
  /* Field: Billable: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'billable';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  /* Field: Billable: Billed */
  $handler->display->display_options['fields']['billed']['id'] = 'billed';
  $handler->display->display_options['fields']['billed']['table'] = 'billable';
  $handler->display->display_options['fields']['billed']['field'] = 'billed';
  /* Field: Billable: Date_delivery */
  $handler->display->display_options['fields']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['fields']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['label'] = 'Date delivery';
  $handler->display->display_options['fields']['date_delivery']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date_delivery']['custom_date_format'] = 'Y-m-d';
  /* Field: Billable: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'billable';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Billable: Single_price */
  $handler->display->display_options['fields']['single_price']['id'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['table'] = 'billable';
  $handler->display->display_options['fields']['single_price']['field'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['label'] = 'Single price';
  $handler->display->display_options['fields']['single_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['single_price']['precision'] = '2';
  /* Field: Billable: Total_price_no_vat */
  $handler->display->display_options['fields']['total_price_no_vat']['id'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price_no_vat']['field'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['label'] = 'Total excl. VAT';
  $handler->display->display_options['fields']['total_price_no_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price_no_vat']['precision'] = '2';
  /* Field: Billable: Total_vat */
  $handler->display->display_options['fields']['total_vat']['id'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_vat']['field'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['label'] = 'Total VAT';
  $handler->display->display_options['fields']['total_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_vat']['precision'] = '2';
  /* Field: Billable: Total_price */
  $handler->display->display_options['fields']['total_price']['id'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price']['field'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['label'] = 'Total';
  $handler->display->display_options['fields']['total_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price']['precision'] = '2';
  /* Field: Billable: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'billable';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'contractor_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Contractor';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'customer_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Customer';
  /* Field: Billable: Edit Link */
  $handler->display->display_options['fields']['edit_billable']['id'] = 'edit_billable';
  $handler->display->display_options['fields']['edit_billable']['table'] = 'billable';
  $handler->display->display_options['fields']['edit_billable']['field'] = 'edit_billable';
  $handler->display->display_options['fields']['edit_billable']['label'] = '';
  $handler->display->display_options['fields']['edit_billable']['element_label_colon'] = FALSE;
  /* Sort criterion: Billable: Billable ID */
  $handler->display->display_options['sorts']['billable_id']['id'] = 'billable_id';
  $handler->display->display_options['sorts']['billable_id']['table'] = 'billable';
  $handler->display->display_options['sorts']['billable_id']['field'] = 'billable_id';
  $handler->display->display_options['sorts']['billable_id']['order'] = 'DESC';
  /* Filter criterion: Billable: Contractor_nid */
  $handler->display->display_options['filters']['contractor_nid']['id'] = 'contractor_nid';
  $handler->display->display_options['filters']['contractor_nid']['table'] = 'billable';
  $handler->display->display_options['filters']['contractor_nid']['field'] = 'contractor_nid';
  $handler->display->display_options['filters']['contractor_nid']['group'] = 0;
  $handler->display->display_options['filters']['contractor_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['contractor_nid']['expose']['operator_id'] = 'contractor_nid_op';
  $handler->display->display_options['filters']['contractor_nid']['expose']['label'] = 'Contractor';
  $handler->display->display_options['filters']['contractor_nid']['expose']['operator'] = 'contractor_nid_op';
  $handler->display->display_options['filters']['contractor_nid']['expose']['identifier'] = 'contractor_nid';
  /* Filter criterion: Billable: Customer_nid */
  $handler->display->display_options['filters']['customer_nid']['id'] = 'customer_nid';
  $handler->display->display_options['filters']['customer_nid']['table'] = 'billable';
  $handler->display->display_options['filters']['customer_nid']['field'] = 'customer_nid';
  $handler->display->display_options['filters']['customer_nid']['group'] = 0;
  $handler->display->display_options['filters']['customer_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['customer_nid']['expose']['operator_id'] = 'customer_nid_op';
  $handler->display->display_options['filters']['customer_nid']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['customer_nid']['expose']['operator'] = 'customer_nid_op';
  $handler->display->display_options['filters']['customer_nid']['expose']['identifier'] = 'customer_nid';
  /* Filter criterion: Billable: Billed */
  $handler->display->display_options['filters']['billed']['id'] = 'billed';
  $handler->display->display_options['filters']['billed']['table'] = 'billable';
  $handler->display->display_options['filters']['billed']['field'] = 'billed';
  $handler->display->display_options['filters']['billed']['value'] = '0';
  $handler->display->display_options['filters']['billed']['group'] = 0;
  $handler->display->display_options['filters']['billed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['billed']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['billed']['expose']['label'] = 'Billed';
  $handler->display->display_options['filters']['billed']['expose']['operator'] = 'billed_op';
  $handler->display->display_options['filters']['billed']['expose']['identifier'] = 'billed';
  $handler->display->display_options['filters']['billed']['expose']['required'] = TRUE;
  /* Filter criterion: Billable: Date_delivery */
  $handler->display->display_options['filters']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['filters']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['operator'] = 'between';
  $handler->display->display_options['filters']['date_delivery']['group'] = 0;
  $handler->display->display_options['filters']['date_delivery']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_delivery']['expose']['operator_id'] = 'date_delivery_op';
  $handler->display->display_options['filters']['date_delivery']['expose']['label'] = 'Delivery';
  $handler->display->display_options['filters']['date_delivery']['expose']['operator'] = 'date_delivery_op';
  $handler->display->display_options['filters']['date_delivery']['expose']['identifier'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['form_type'] = 'date_popup';
  /* Filter criterion: Billable: Parent_billable */
  $handler->display->display_options['filters']['parent_billable']['id'] = 'parent_billable';
  $handler->display->display_options['filters']['parent_billable']['table'] = 'billable';
  $handler->display->display_options['filters']['parent_billable']['field'] = 'parent_billable';
  $handler->display->display_options['filters']['parent_billable']['value']['value'] = '0';
  $handler->display->display_options['filters']['parent_billable']['group'] = 0;

  /* Display: Billables */
  $handler = $view->new_display('page', 'Billables', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'invoice/billables';

  /* Display: Billables by invoice pane */
  $handler = $view->new_display('panel_pane', 'Billables by invoice pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_billables_ref_node']['id'] = 'reverse_field_billables_ref_node';
  $handler->display->display_options['relationships']['reverse_field_billables_ref_node']['table'] = 'billable';
  $handler->display->display_options['relationships']['reverse_field_billables_ref_node']['field'] = 'reverse_field_billables_ref_node';
  /* Relationship: Billable: Billable subject */
  $handler->display->display_options['relationships']['subject_nid']['id'] = 'subject_nid';
  $handler->display->display_options['relationships']['subject_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['subject_nid']['field'] = 'subject_nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Billable: Billable ID */
  $handler->display->display_options['fields']['billable_id']['id'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['table'] = 'billable';
  $handler->display->display_options['fields']['billable_id']['field'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['billable_id']['alter']['path'] = 'billable/[billable_id]/view';
  $handler->display->display_options['fields']['billable_id']['separator'] = '';
  /* Field: Billable: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'billable';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  /* Field: Billable: Date_delivery */
  $handler->display->display_options['fields']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['fields']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['label'] = 'Date delivery';
  $handler->display->display_options['fields']['date_delivery']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date_delivery']['custom_date_format'] = 'Y-m-d';
  /* Field: Billable: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'billable';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Billable: Single_price */
  $handler->display->display_options['fields']['single_price']['id'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['table'] = 'billable';
  $handler->display->display_options['fields']['single_price']['field'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['label'] = 'Single price';
  $handler->display->display_options['fields']['single_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['single_price']['precision'] = '2';
  /* Field: Billable: Total_price_no_vat */
  $handler->display->display_options['fields']['total_price_no_vat']['id'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price_no_vat']['field'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['label'] = 'Total excl. VAT';
  $handler->display->display_options['fields']['total_price_no_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price_no_vat']['precision'] = '2';
  /* Field: Billable: Vat_rate */
  $handler->display->display_options['fields']['vat_rate']['id'] = 'vat_rate';
  $handler->display->display_options['fields']['vat_rate']['table'] = 'billable';
  $handler->display->display_options['fields']['vat_rate']['field'] = 'vat_rate';
  $handler->display->display_options['fields']['vat_rate']['label'] = 'VAT rate';
  /* Field: Billable: Total_vat */
  $handler->display->display_options['fields']['total_vat']['id'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_vat']['field'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['label'] = 'Total VAT';
  $handler->display->display_options['fields']['total_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_vat']['precision'] = '2';
  /* Field: Billable: Total_price */
  $handler->display->display_options['fields']['total_price']['id'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price']['field'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['label'] = 'Total';
  $handler->display->display_options['fields']['total_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price']['precision'] = '2';
  /* Field: Billable: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'billable';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Billable: Date_delivery */
  $handler->display->display_options['sorts']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['sorts']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['sorts']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_billables_ref_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['argument'] = 'No invoice line items found';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Billables by contract pane */
  $handler = $view->new_display('panel_pane', 'Billables by contract pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Billable: Billable subject */
  $handler->display->display_options['relationships']['subject_nid']['id'] = 'subject_nid';
  $handler->display->display_options['relationships']['subject_nid']['table'] = 'billable';
  $handler->display->display_options['relationships']['subject_nid']['field'] = 'subject_nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Billable: Billable ID */
  $handler->display->display_options['fields']['billable_id']['id'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['table'] = 'billable';
  $handler->display->display_options['fields']['billable_id']['field'] = 'billable_id';
  $handler->display->display_options['fields']['billable_id']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['billable_id']['alter']['path'] = 'billable/[billable_id]/view';
  $handler->display->display_options['fields']['billable_id']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'subject_nid';
  $handler->display->display_options['fields']['title']['label'] = 'Subject';
  /* Field: Billable: Billed */
  $handler->display->display_options['fields']['billed']['id'] = 'billed';
  $handler->display->display_options['fields']['billed']['table'] = 'billable';
  $handler->display->display_options['fields']['billed']['field'] = 'billed';
  /* Field: Billable: Date_delivery */
  $handler->display->display_options['fields']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['fields']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['label'] = 'Date delivery';
  $handler->display->display_options['fields']['date_delivery']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date_delivery']['custom_date_format'] = 'Y-m-d';
  /* Field: Billable: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'billable';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Billable: Single_price */
  $handler->display->display_options['fields']['single_price']['id'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['table'] = 'billable';
  $handler->display->display_options['fields']['single_price']['field'] = 'single_price';
  $handler->display->display_options['fields']['single_price']['label'] = 'Single price';
  $handler->display->display_options['fields']['single_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['single_price']['precision'] = '2';
  /* Field: Billable: Total_price_no_vat */
  $handler->display->display_options['fields']['total_price_no_vat']['id'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price_no_vat']['field'] = 'total_price_no_vat';
  $handler->display->display_options['fields']['total_price_no_vat']['label'] = 'Total excl. VAT';
  $handler->display->display_options['fields']['total_price_no_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price_no_vat']['precision'] = '2';
  /* Field: Billable: Total_vat */
  $handler->display->display_options['fields']['total_vat']['id'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_vat']['field'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['label'] = 'Total VAT';
  $handler->display->display_options['fields']['total_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_vat']['precision'] = '2';
  /* Field: Billable: Total_price */
  $handler->display->display_options['fields']['total_price']['id'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price']['field'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['label'] = 'Total';
  $handler->display->display_options['fields']['total_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price']['precision'] = '2';
  /* Field: Billable: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'billable';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  /* Field: Billable: Edit Link */
  $handler->display->display_options['fields']['edit_billable']['id'] = 'edit_billable';
  $handler->display->display_options['fields']['edit_billable']['table'] = 'billable';
  $handler->display->display_options['fields']['edit_billable']['field'] = 'edit_billable';
  $handler->display->display_options['fields']['edit_billable']['label'] = '';
  $handler->display->display_options['fields']['edit_billable']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Billable: Subject_nid */
  $handler->display->display_options['arguments']['subject_nid']['id'] = 'subject_nid';
  $handler->display->display_options['arguments']['subject_nid']['table'] = 'billable';
  $handler->display->display_options['arguments']['subject_nid']['field'] = 'subject_nid';
  $handler->display->display_options['arguments']['subject_nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['subject_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['subject_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['subject_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['subject_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Billable: Billed */
  $handler->display->display_options['filters']['billed']['id'] = 'billed';
  $handler->display->display_options['filters']['billed']['table'] = 'billable';
  $handler->display->display_options['filters']['billed']['field'] = 'billed';
  $handler->display->display_options['filters']['billed']['value'] = '0';
  $handler->display->display_options['filters']['billed']['group'] = 0;
  $handler->display->display_options['filters']['billed']['exposed'] = TRUE;
  $handler->display->display_options['filters']['billed']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['billed']['expose']['label'] = 'Billed';
  $handler->display->display_options['filters']['billed']['expose']['operator'] = 'billed_op';
  $handler->display->display_options['filters']['billed']['expose']['identifier'] = 'billed';
  $handler->display->display_options['filters']['billed']['expose']['required'] = TRUE;
  /* Filter criterion: Billable: Date_delivery */
  $handler->display->display_options['filters']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['filters']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['operator'] = 'between';
  $handler->display->display_options['filters']['date_delivery']['group'] = 0;
  $handler->display->display_options['filters']['date_delivery']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_delivery']['expose']['operator_id'] = 'date_delivery_op';
  $handler->display->display_options['filters']['date_delivery']['expose']['label'] = 'Delivery';
  $handler->display->display_options['filters']['date_delivery']['expose']['operator'] = 'date_delivery_op';
  $handler->display->display_options['filters']['date_delivery']['expose']['identifier'] = 'date_delivery';
  $handler->display->display_options['filters']['date_delivery']['form_type'] = 'date_popup';
  /* Filter criterion: Billable: Parent_billable */
  $handler->display->display_options['filters']['parent_billable']['id'] = 'parent_billable';
  $handler->display->display_options['filters']['parent_billable']['table'] = 'billable';
  $handler->display->display_options['filters']['parent_billable']['field'] = 'parent_billable';
  $handler->display->display_options['filters']['parent_billable']['value']['value'] = '0';
  $handler->display->display_options['filters']['parent_billable']['group'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'subject_nid' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Billable: Subject_nid',
    ),
  );
  $export['billables'] = $view;

  $view = new view();
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access invoices view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
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
echo _erpal_invoice_helper_view_invoices_header_content();
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['content'] = 'No invoices available';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Invoice Date */
  $handler->display->display_options['fields']['field_invoice_date']['id'] = 'field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['table'] = 'field_data_field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['field'] = 'field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Invoice Number */
  $handler->display->display_options['fields']['field_invoice_number']['id'] = 'field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['table'] = 'field_data_field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['field'] = 'field_invoice_number';
  /* Field: Content: Paid */
  $handler->display->display_options['fields']['field_payed']['id'] = 'field_payed';
  $handler->display->display_options['fields']['field_payed']['table'] = 'field_data_field_payed';
  $handler->display->display_options['fields']['field_payed']['field'] = 'field_payed';
  /* Field: Content: Payment date */
  $handler->display->display_options['fields']['field_payment_date']['id'] = 'field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['table'] = 'field_data_field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['field'] = 'field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_payment_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Total excl. VAT */
  $handler->display->display_options['fields']['field_price_no_vat']['id'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['table'] = 'field_data_field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['field'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Total incl. VAT */
  $handler->display->display_options['fields']['field_invoice_total']['id'] = 'field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['table'] = 'field_data_field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['field'] = 'field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Currency */
  $handler->display->display_options['fields']['field_currency']['id'] = 'field_currency';
  $handler->display->display_options['fields']['field_currency']['table'] = 'field_data_field_currency';
  $handler->display->display_options['fields']['field_currency']['field'] = 'field_currency';
  /* Field: Field: Contractor */
  $handler->display->display_options['fields']['field_contractor_ref']['id'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['table'] = 'field_data_field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['field'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Exported */
  $handler->display->display_options['fields']['field_invoice_exported']['id'] = 'field_invoice_exported';
  $handler->display->display_options['fields']['field_invoice_exported']['table'] = 'field_data_field_invoice_exported';
  $handler->display->display_options['fields']['field_invoice_exported']['field'] = 'field_invoice_exported';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Paid (field_payed) */
  $handler->display->display_options['filters']['field_payed_value']['id'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['table'] = 'field_data_field_payed';
  $handler->display->display_options['filters']['field_payed_value']['field'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator_id'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['label'] = 'Payed';
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['identifier'] = 'field_payed_value';
  /* Filter criterion: Content: Invoice Date (field_invoice_date) */
  $handler->display->display_options['filters']['field_invoice_date_value']['id'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['table'] = 'field_data_field_invoice_date';
  $handler->display->display_options['filters']['field_invoice_date_value']['field'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_invoice_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['operator_id'] = 'field_invoice_date_value_op';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['label'] = 'Invoice Date';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['operator'] = 'field_invoice_date_value_op';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['identifier'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Invoice Number (field_invoice_number) */
  $handler->display->display_options['filters']['field_invoice_number_value']['id'] = 'field_invoice_number_value';
  $handler->display->display_options['filters']['field_invoice_number_value']['table'] = 'field_data_field_invoice_number';
  $handler->display->display_options['filters']['field_invoice_number_value']['field'] = 'field_invoice_number_value';
  $handler->display->display_options['filters']['field_invoice_number_value']['group'] = 1;
  $handler->display->display_options['filters']['field_invoice_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['operator_id'] = 'field_invoice_number_value_op';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['label'] = 'Invoice Number';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['operator'] = 'field_invoice_number_value_op';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['identifier'] = 'field_invoice_number_value';
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
    'erpal_invoice' => 'erpal_invoice',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Exported (field_invoice_exported) */
  $handler->display->display_options['filters']['field_invoice_exported_value']['id'] = 'field_invoice_exported_value';
  $handler->display->display_options['filters']['field_invoice_exported_value']['table'] = 'field_data_field_invoice_exported';
  $handler->display->display_options['filters']['field_invoice_exported_value']['field'] = 'field_invoice_exported_value';
  $handler->display->display_options['filters']['field_invoice_exported_value']['group'] = 1;
  $handler->display->display_options['filters']['field_invoice_exported_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['operator_id'] = 'field_invoice_exported_value_op';
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['label'] = 'Exported';
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['operator'] = 'field_invoice_exported_value_op';
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['identifier'] = 'field_invoice_exported_value';
  /* Filter criterion: Field: Contractor (field_contractor_ref) */
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['id'] = 'field_contractor_ref_target_id';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['table'] = 'field_data_field_contractor_ref';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['field'] = 'field_contractor_ref_target_id';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['operator_id'] = 'field_contractor_ref_target_id_op';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['label'] = 'Contractor';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['operator'] = 'field_contractor_ref_target_id_op';
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['identifier'] = 'field_contractor_ref_target_id';
  /* Filter criterion: Field: Customer (field_customer_ref) */
  $handler->display->display_options['filters']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator_id'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['label'] = 'Customer';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['operator'] = 'field_customer_ref_target_id_op';
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['identifier'] = 'field_customer_ref_target_id';

  /* Display: Invoices */
  $handler = $view->new_display('page', 'Invoices', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'invoice/invoices';

  /* Display: Invoices to contact pane */
  $handler = $view->new_display('panel_pane', 'Invoices to contact pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Customer (field_customer_ref) */
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['id'] = 'field_customer_ref_target_id';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['field'] = 'field_customer_ref_target_id';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_customer_ref_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Paid (field_payed) */
  $handler->display->display_options['filters']['field_payed_value']['id'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['table'] = 'field_data_field_payed';
  $handler->display->display_options['filters']['field_payed_value']['field'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['group'] = 0;
  $handler->display->display_options['filters']['field_payed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator_id'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['label'] = 'Payed';
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['identifier'] = 'field_payed_value';
  /* Filter criterion: Content: Invoice Date (field_invoice_date) */
  $handler->display->display_options['filters']['field_invoice_date_value']['id'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['table'] = 'field_data_field_invoice_date';
  $handler->display->display_options['filters']['field_invoice_date_value']['field'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['group'] = 0;
  $handler->display->display_options['filters']['field_invoice_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['operator_id'] = 'field_invoice_date_value_op';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['label'] = 'Invoice Date';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['operator'] = 'field_invoice_date_value_op';
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['identifier'] = 'field_invoice_date_value';
  $handler->display->display_options['filters']['field_invoice_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Invoice Number (field_invoice_number) */
  $handler->display->display_options['filters']['field_invoice_number_value']['id'] = 'field_invoice_number_value';
  $handler->display->display_options['filters']['field_invoice_number_value']['table'] = 'field_data_field_invoice_number';
  $handler->display->display_options['filters']['field_invoice_number_value']['field'] = 'field_invoice_number_value';
  $handler->display->display_options['filters']['field_invoice_number_value']['group'] = 0;
  $handler->display->display_options['filters']['field_invoice_number_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['operator_id'] = 'field_invoice_number_value_op';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['label'] = 'Invoice Number';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['operator'] = 'field_invoice_number_value_op';
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['identifier'] = 'field_invoice_number_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'erpal_invoice' => 'erpal_invoice',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Exported (field_invoice_exported) */
  $handler->display->display_options['filters']['field_invoice_exported_value']['id'] = 'field_invoice_exported_value';
  $handler->display->display_options['filters']['field_invoice_exported_value']['table'] = 'field_data_field_invoice_exported';
  $handler->display->display_options['filters']['field_invoice_exported_value']['field'] = 'field_invoice_exported_value';
  $handler->display->display_options['filters']['field_invoice_exported_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['operator_id'] = 'field_invoice_exported_value_op';
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['label'] = 'Exported';
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['operator'] = 'field_invoice_exported_value_op';
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['identifier'] = 'field_invoice_exported_value';
  $handler->display->display_options['argument_input'] = array(
    'field_customer_ref_target_id' => array(
      'type' => 'panel',
      'context' => 'entity:billable.billable-id',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Customer (field_customer_ref)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['invoices'] = $view;

  return $export;
}
