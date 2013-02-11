<?php
/**
 * @file
 * erpal_invoice_ui.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function erpal_invoice_ui_views_default_views() {
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access billables view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
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
    'action::erpal_projects_helper_timetracking_finalise_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::billable_reduce_action' => array(
      'selected' => 0,
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
  /* Field: Billable: Subject_nid */
  $handler->display->display_options['fields']['subject_nid']['id'] = 'subject_nid';
  $handler->display->display_options['fields']['subject_nid']['table'] = 'billable';
  $handler->display->display_options['fields']['subject_nid']['field'] = 'subject_nid';
  $handler->display->display_options['fields']['subject_nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['subject_nid']['separator'] = '';
  /* Field: Billable: Subject */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'billable';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['subject']['alter']['text'] = '<a href="/node/[subject_nid]">[subject]</a>';
  /* Field: Billable: Billed */
  $handler->display->display_options['fields']['billed']['id'] = 'billed';
  $handler->display->display_options['fields']['billed']['table'] = 'billable';
  $handler->display->display_options['fields']['billed']['field'] = 'billed';
  /* Field: Billable: Date_delivery */
  $handler->display->display_options['fields']['date_delivery']['id'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['table'] = 'billable';
  $handler->display->display_options['fields']['date_delivery']['field'] = 'date_delivery';
  $handler->display->display_options['fields']['date_delivery']['label'] = 'Date delivery';
  $handler->display->display_options['fields']['date_delivery']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['date_delivery']['custom_date_format'] = 'Y-m-d';
  /* Field: Billable: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'billable';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['label'] = 'Menge';
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
  $handler->display->display_options['fields']['total_price_no_vat']['label'] = 'Summe Netto';
  $handler->display->display_options['fields']['total_price_no_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price_no_vat']['precision'] = '2';
  /* Field: Billable: Total_vat */
  $handler->display->display_options['fields']['total_vat']['id'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_vat']['field'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['label'] = 'MwSt.';
  $handler->display->display_options['fields']['total_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_vat']['precision'] = '2';
  /* Field: Billable: Total_price */
  $handler->display->display_options['fields']['total_price']['id'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price']['field'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['label'] = 'Summe';
  $handler->display->display_options['fields']['total_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price']['precision'] = '2';
  /* Field: Billable: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'billable';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  $handler->display->display_options['fields']['currency']['label'] = 'Währung';
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
  /* Field: Field: Service category */
  $handler->display->display_options['fields']['field_service_category_term']['id'] = 'field_service_category_term';
  $handler->display->display_options['fields']['field_service_category_term']['table'] = 'field_data_field_service_category_term';
  $handler->display->display_options['fields']['field_service_category_term']['field'] = 'field_service_category_term';
  $handler->display->display_options['fields']['field_service_category_term']['type'] = 'taxonomy_term_reference_plain';
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
  $handler->display->display_options['filters']['contractor_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['contractor_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['customer_nid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['customer_nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['billed']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['billed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  /* Filter criterion: Field: Service category (field_service_category_term) */
  $handler->display->display_options['filters']['field_service_category_term_tid']['id'] = 'field_service_category_term_tid';
  $handler->display->display_options['filters']['field_service_category_term_tid']['table'] = 'field_data_field_service_category_term';
  $handler->display->display_options['filters']['field_service_category_term_tid']['field'] = 'field_service_category_term_tid';
  $handler->display->display_options['filters']['field_service_category_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_service_category_term_tid']['expose']['operator_id'] = 'field_service_category_term_tid_op';
  $handler->display->display_options['filters']['field_service_category_term_tid']['expose']['label'] = 'Service category';
  $handler->display->display_options['filters']['field_service_category_term_tid']['expose']['operator'] = 'field_service_category_term_tid_op';
  $handler->display->display_options['filters']['field_service_category_term_tid']['expose']['identifier'] = 'field_service_category_term_tid';
  $handler->display->display_options['filters']['field_service_category_term_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_service_category_term_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_service_category_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_service_category_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_service_category_term_tid']['vocabulary'] = 'service_category_terms';
  $handler->display->display_options['filters']['field_service_category_term_tid']['error_message'] = FALSE;

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
  $handler->display->display_options['fields']['date_delivery']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['date_delivery']['custom_date_format'] = 'Y-m-d';
  /* Field: Billable: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'billable';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['label'] = 'Menge';
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
  $handler->display->display_options['fields']['total_price_no_vat']['label'] = 'Summe Netto';
  $handler->display->display_options['fields']['total_price_no_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price_no_vat']['precision'] = '2';
  /* Field: Billable: Vat_rate */
  $handler->display->display_options['fields']['vat_rate']['id'] = 'vat_rate';
  $handler->display->display_options['fields']['vat_rate']['table'] = 'billable';
  $handler->display->display_options['fields']['vat_rate']['field'] = 'vat_rate';
  $handler->display->display_options['fields']['vat_rate']['label'] = 'gesetzl. MwSt,';
  /* Field: Billable: Total_vat */
  $handler->display->display_options['fields']['total_vat']['id'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_vat']['field'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['label'] = 'MwSt.';
  $handler->display->display_options['fields']['total_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_vat']['precision'] = '2';
  /* Field: Billable: Total_price */
  $handler->display->display_options['fields']['total_price']['id'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price']['field'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['label'] = 'Summe';
  $handler->display->display_options['fields']['total_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price']['precision'] = '2';
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
  $handler->display->display_options['fields']['date_delivery']['date_format'] = 'erpal_date';
  $handler->display->display_options['fields']['date_delivery']['custom_date_format'] = 'Y-m-d';
  /* Field: Billable: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'billable';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['label'] = 'Menge';
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
  $handler->display->display_options['fields']['total_price_no_vat']['label'] = 'Summe Netto';
  $handler->display->display_options['fields']['total_price_no_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price_no_vat']['precision'] = '2';
  /* Field: Billable: Total_vat */
  $handler->display->display_options['fields']['total_vat']['id'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['table'] = 'billable';
  $handler->display->display_options['fields']['total_vat']['field'] = 'total_vat';
  $handler->display->display_options['fields']['total_vat']['label'] = 'MwSt.';
  $handler->display->display_options['fields']['total_vat']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_vat']['precision'] = '2';
  /* Field: Billable: Total_price */
  $handler->display->display_options['fields']['total_price']['id'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['table'] = 'billable';
  $handler->display->display_options['fields']['total_price']['field'] = 'total_price';
  $handler->display->display_options['fields']['total_price']['label'] = 'Summe';
  $handler->display->display_options['fields']['total_price']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['total_price']['precision'] = '2';
  /* Field: Billable: Currency */
  $handler->display->display_options['fields']['currency']['id'] = 'currency';
  $handler->display->display_options['fields']['currency']['table'] = 'billable';
  $handler->display->display_options['fields']['currency']['field'] = 'currency';
  $handler->display->display_options['fields']['currency']['label'] = 'Währung';
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
  $handler->display->display_options['filters']['billed']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['billed']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: billables pane */
  $handler = $view->new_display('panel_pane', 'billables pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'billable_id' => 'billable_id',
    'subject_nid' => 'subject_nid',
    'subject' => 'subject',
    'billed' => 'billed',
    'date_delivery' => 'date_delivery',
    'quantity' => 'quantity',
    'single_price' => 'single_price',
    'total_price_no_vat' => 'total_price_no_vat',
    'total_vat' => 'total_vat',
    'total_price' => 'total_price',
    'currency' => 'currency',
    'title_1' => 'title_1',
    'title' => 'title',
    'field_service_category_term' => 'field_service_category_term',
    'edit_billable' => 'edit_billable',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'billable_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'subject_nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'subject' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'billed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'date_delivery' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'quantity' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'single_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'total_price_no_vat' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'total_vat' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'total_price' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'currency' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_service_category_term' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'edit_billable' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '2';
  $handler->display->display_options['style_options']['decimal'] = ',';
  $handler->display->display_options['style_options']['separator'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['inherit_panels_path'] = '1';
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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access invoices view';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_invoice_date' => 'field_invoice_date',
    'field_invoice_number' => 'field_invoice_number',
    'field_payed' => 'field_payed',
    'field_payment_date' => 'field_payment_date',
    'field_price_no_vat' => 'field_price_no_vat',
    'field_invoice_total' => 'field_invoice_total',
    'field_currency' => 'field_currency',
    'field_contractor_ref' => 'field_contractor_ref',
    'field_customer_ref' => 'field_customer_ref',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_invoice_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_invoice_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_payed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_payment_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_price_no_vat' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_invoice_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_currency' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_contractor_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_customer_ref' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['style_options']['decimal'] = ',';
  $handler->display->display_options['style_options']['separator'] = '';
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
  $handler->display->display_options['fields']['title']['label'] = 'Invoice title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Invoice Date */
  $handler->display->display_options['fields']['field_invoice_date']['id'] = 'field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['table'] = 'field_data_field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['field'] = 'field_invoice_date';
  $handler->display->display_options['fields']['field_invoice_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Invoice Number */
  $handler->display->display_options['fields']['field_invoice_number']['id'] = 'field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['table'] = 'field_data_field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['field'] = 'field_invoice_number';
  /* Field: Content: Paid */
  $handler->display->display_options['fields']['field_payed']['id'] = 'field_payed';
  $handler->display->display_options['fields']['field_payed']['table'] = 'field_data_field_payed';
  $handler->display->display_options['fields']['field_payed']['field'] = 'field_payed';
  $handler->display->display_options['fields']['field_payed']['type'] = 'editable';
  $handler->display->display_options['fields']['field_payed']['settings'] = array(
    'click_to_edit' => 1,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'list_default',
  );
  /* Field: Content: Payment date */
  $handler->display->display_options['fields']['field_payment_date']['id'] = 'field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['table'] = 'field_data_field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['field'] = 'field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Total excl. VAT */
  $handler->display->display_options['fields']['field_price_no_vat']['id'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['table'] = 'field_data_field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['field'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['label'] = 'Summe Netto';
  $handler->display->display_options['fields']['field_price_no_vat']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Total incl. VAT */
  $handler->display->display_options['fields']['field_invoice_total']['id'] = 'field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['table'] = 'field_data_field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['field'] = 'field_invoice_total';
  $handler->display->display_options['fields']['field_invoice_total']['settings'] = array(
    'thousand_separator' => '.',
    'decimal_separator' => ',',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Currency */
  $handler->display->display_options['fields']['field_currency']['id'] = 'field_currency';
  $handler->display->display_options['fields']['field_currency']['table'] = 'field_data_field_currency';
  $handler->display->display_options['fields']['field_currency']['field'] = 'field_currency';
  $handler->display->display_options['fields']['field_currency']['label'] = 'Währung';
  /* Field: Field: Contractor */
  $handler->display->display_options['fields']['field_contractor_ref']['id'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['table'] = 'field_data_field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['field'] = 'field_contractor_ref';
  $handler->display->display_options['fields']['field_contractor_ref']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_contractor_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field: Customer */
  $handler->display->display_options['fields']['field_customer_ref']['id'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['table'] = 'field_data_field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['field'] = 'field_customer_ref';
  $handler->display->display_options['fields']['field_customer_ref']['type'] = 'entityreference_typed_label';
  $handler->display->display_options['fields']['field_customer_ref']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Paid */
  $handler->display->display_options['fields']['field_payed_1']['id'] = 'field_payed_1';
  $handler->display->display_options['fields']['field_payed_1']['table'] = 'field_data_field_payed';
  $handler->display->display_options['fields']['field_payed_1']['field'] = 'field_payed';
  $handler->display->display_options['fields']['field_payed_1']['exclude'] = TRUE;
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
  $handler->display->display_options['filters']['field_payed_value']['expose']['label'] = 'Paid (field_payed)';
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
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );

  /* Display: Invoices to contact pane */
  $handler = $view->new_display('panel_pane', 'Invoices to contact pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_calc';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_invoice_date' => 'field_invoice_date',
    'field_invoice_number' => 'field_invoice_number',
    'field_payed' => 'field_payed',
    'field_payment_date' => 'field_payment_date',
    'field_price_no_vat' => 'field_price_no_vat',
    'field_invoice_total' => 'field_invoice_total',
    'field_currency' => 'field_currency',
    'field_invoice_exported' => 'field_invoice_exported',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_invoice_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_invoice_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_payed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_payment_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_price_no_vat' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_invoice_total' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 1,
      'calc' => array(
        'SUM' => 'SUM',
      ),
    ),
    'field_currency' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
    'field_invoice_exported' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_calc' => 0,
      'calc' => array(),
    ),
  );
  $handler->display->display_options['style_options']['detailed_values'] = '0';
  $handler->display->display_options['style_options']['precision'] = '0';
  $handler->display->display_options['style_options']['decimal'] = ',';
  $handler->display->display_options['style_options']['separator'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Invoice Number */
  $handler->display->display_options['fields']['field_invoice_number']['id'] = 'field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['table'] = 'field_data_field_invoice_number';
  $handler->display->display_options['fields']['field_invoice_number']['field'] = 'field_invoice_number';
  /* Field: Content: Paid */
  $handler->display->display_options['fields']['field_payed']['id'] = 'field_payed';
  $handler->display->display_options['fields']['field_payed']['table'] = 'field_data_field_payed';
  $handler->display->display_options['fields']['field_payed']['field'] = 'field_payed';
  $handler->display->display_options['fields']['field_payed']['type'] = 'editable';
  $handler->display->display_options['fields']['field_payed']['settings'] = array(
    'click_to_edit' => 1,
    'click_to_edit_style' => 'hover',
    'empty_text' => '',
    'fallback_format' => 'list_default',
  );
  /* Field: Content: Payment date */
  $handler->display->display_options['fields']['field_payment_date']['id'] = 'field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['table'] = 'field_data_field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['field'] = 'field_payment_date';
  $handler->display->display_options['fields']['field_payment_date']['settings'] = array(
    'format_type' => 'erpal_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Total excl. VAT */
  $handler->display->display_options['fields']['field_price_no_vat']['id'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['table'] = 'field_data_field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['field'] = 'field_price_no_vat';
  $handler->display->display_options['fields']['field_price_no_vat']['label'] = 'Summe Netto';
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
  $handler->display->display_options['fields']['field_currency']['label'] = 'Währung';
  /* Field: Content: Exported */
  $handler->display->display_options['fields']['field_invoice_exported']['id'] = 'field_invoice_exported';
  $handler->display->display_options['fields']['field_invoice_exported']['table'] = 'field_data_field_invoice_exported';
  $handler->display->display_options['fields']['field_invoice_exported']['field'] = 'field_invoice_exported';
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
  /* Filter criterion: Content: Payment date (field_payment_date) */
  $handler->display->display_options['filters']['field_payment_date_value']['id'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['table'] = 'field_data_field_payment_date';
  $handler->display->display_options['filters']['field_payment_date_value']['field'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_payment_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['operator_id'] = 'field_payment_date_value_op';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['label'] = 'Paid till';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['operator'] = 'field_payment_date_value_op';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['identifier'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_payment_date_value']['form_type'] = 'date_popup';
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
  $handler->display->display_options['filters']['field_payed_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_payed_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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

  /* Display: Invoices pane */
  $handler = $view->new_display('panel_pane', 'Invoices pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_invoice_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Payment date (field_payment_date) */
  $handler->display->display_options['filters']['field_payment_date_value']['id'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['table'] = 'field_data_field_payment_date';
  $handler->display->display_options['filters']['field_payment_date_value']['field'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_payment_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['operator_id'] = 'field_payment_date_value_op';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['label'] = 'Paid till';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['operator'] = 'field_payment_date_value_op';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['identifier'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_payment_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Paid (field_payed) */
  $handler->display->display_options['filters']['field_payed_value']['id'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['table'] = 'field_data_field_payed';
  $handler->display->display_options['filters']['field_payed_value']['field'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payed_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator_id'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['label'] = 'Paid';
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['identifier'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_payed_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Paid invoices pane */
  $handler = $view->new_display('panel_pane', 'Paid invoices pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Paid (field_payed) */
  $handler->display->display_options['filters']['field_payed_value']['id'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['table'] = 'field_data_field_payed';
  $handler->display->display_options['filters']['field_payed_value']['field'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_payed_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator_id'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['label'] = 'Payed';
  $handler->display->display_options['filters']['field_payed_value']['expose']['operator'] = 'field_payed_value_op';
  $handler->display->display_options['filters']['field_payed_value']['expose']['identifier'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_payed_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Not paid invoices pane */
  $handler = $view->new_display('panel_pane', 'Not paid invoices pane', 'panel_pane_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_invoice_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Payment date (field_payment_date) */
  $handler->display->display_options['filters']['field_payment_date_value']['id'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['table'] = 'field_data_field_payment_date';
  $handler->display->display_options['filters']['field_payment_date_value']['field'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_payment_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_payment_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['operator_id'] = 'field_payment_date_value_op';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['label'] = 'Paid till';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['operator'] = 'field_payment_date_value_op';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['identifier'] = 'field_payment_date_value';
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_payment_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_payment_date_value']['form_type'] = 'date_popup';
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
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_number_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_invoice_exported_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_contractor_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
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
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_customer_ref_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    6 => 0,
    5 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Paid (field_payed) */
  $handler->display->display_options['filters']['field_payed_value']['id'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['table'] = 'field_data_field_payed';
  $handler->display->display_options['filters']['field_payed_value']['field'] = 'field_payed_value';
  $handler->display->display_options['filters']['field_payed_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_payed_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_payed_value']['group'] = 1;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['invoices'] = $view;

  return $export;
}
