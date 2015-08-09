<?php
/**
 * @file
 * erpal_invoice_ui.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_invoice_ui_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts_contact_view_invoices';
  $cat_item->name = 'Erpal contacts: Contact view: invoices';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contacts';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_contact' => 'erpal_contact',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => '',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal contacts: Contact view: invoices',
    'path' => 'node/%',
    'category' => 'Contacts',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-invoice',
        'path_router' => 'node/add/erpal-invoice',
        'path_original' => 'node/add/erpal-invoice',
        'path_pattern' => 'node/%/%',
        'path_query' => array(
          'field_customer_ref' => '[node:nid]',
        ),
        'path_destination' => FALSE,
        'title' => 'Create a new invoice',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      1 => array(
        'path' => 'node/[node:nid]/invoices/defaults',
        'path_router' => 'node/[node:nid]/invoices/defaults',
        'path_original' => 'node/[node:nid]/invoices/defaults',
        'path_pattern' => 'node/%/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoice defaults',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(),
    'machine_name' => 'erpal_contacts_contact_view_invoices',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -97;
  $export['erpal_contacts_contact_view_invoices'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_contacts_invoice_defaults';
  $cat_item->name = 'Erpal Contacts: Invoice defaults';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Contacts';
  $cat_item->path = 'node/%node/invoices/defaults';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_contact' => 'erpal_contact',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'contacts',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal Contacts: Invoice defaults',
    'path' => 'node/%node/invoices/defaults',
    'category' => 'Contacts',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'dashboard',
        'path_router' => 'dashboard',
        'path_original' => 'dashboard',
        'path_pattern' => 'dashboard',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Home',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_home|erpal_home',
      ),
    ),
    'machine_name' => 'erpal_contacts_invoice_defaults',
    'path_original' => 'node/%node/invoices/defaults',
    'path_pattern' => 'node/%/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/invoices/defaults',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -92;
  $export['erpal_contacts_invoice_defaults'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoice_edit_payment';
  $cat_item->name = 'Erpal invoice: edit payment';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'payment/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(
      1 => array(
        'argument_name' => 'payment',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:payment',
        'settings' => array(
          'identifier' => 'Payment: ID',
        ),
      ),
    ),
    'name' => 'Erpal invoice: edit payment',
    'path' => 'payment/%/edit',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoice_edit_payment',
    'path_original' => 'payment/%payment/edit',
    'path_pattern' => 'payment/%/%',
    'path_query' => array(),
    'path_router' => 'payment/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_invoice_edit_payment'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoice_hide_billable_tabs';
  $cat_item->name = 'Erpal invoice: hide billable tabs';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'billable/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => '',
    'arguments' => array(
      1 => array(
        'argument_name' => 'billable',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:billable',
        'settings' => array(
          'identifier' => 'Billable: ID',
        ),
      ),
    ),
    'name' => 'Erpal invoice: hide billable tabs',
    'path' => 'billable/%',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(),
    'machine_name' => 'erpal_invoice_hide_billable_tabs',
    'path_original' => 'billable/%billable',
    'path_pattern' => 'billable/%',
    'path_query' => array(),
    'path_router' => 'billable/%',
    'reusable' => 0,
    'cat_remove' => array(
      0 => array(
        'path' => 'billable/%/view',
        'path_router' => 'billable/%/view',
        'path_original' => 'billable/%billable/view',
        'path_pattern' => 'billable/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
      1 => array(
        'path' => 'billable/%/edit',
        'path_router' => 'billable/%/edit',
        'path_original' => 'billable/%billable/edit',
        'path_pattern' => 'billable/%/%',
        'remove_settings' => array(
          'tab' => 'tab',
          'action' => 0,
        ),
      ),
    ),
  );
  $cat_item->weight = 0;
  $export['erpal_invoice_hide_billable_tabs'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoice_payment_view_single';
  $cat_item->name = 'Erpal invoice: payment view single';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'payment/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(
      1 => array(
        'argument_name' => 'payment',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:payment',
        'settings' => array(
          'identifier' => 'Payment: ID',
        ),
      ),
    ),
    'name' => 'Erpal invoice: payment view single',
    'path' => 'payment/%',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoice_payment_view_single',
    'path_original' => 'payment/%payment',
    'path_pattern' => 'payment/%',
    'path_query' => array(),
    'path_router' => 'payment/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_invoice_payment_view_single'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoice_view_payments';
  $cat_item->name = 'Erpal invoice: view payments';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'invoice/payments';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(),
    'name' => 'Erpal invoice: view payments',
    'path' => 'invoice/payments',
    'category' => 'Invoices',
    'cat_actions' => array(
      0 => array(
        'path' => 'payment/add',
        'path_router' => 'payment/add',
        'path_original' => 'payment/add',
        'path_pattern' => 'payment/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Add payment',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoice_view_payments',
    'path_original' => 'invoice/payments',
    'path_pattern' => 'invoice/%',
    'path_query' => array(),
    'path_router' => 'invoice/payments',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_invoice_view_payments'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices';
  $cat_item->name = 'Erpal Invoices (default)';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'invoice/invoices';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(),
    'name' => 'Erpal Invoices (default)',
    'path' => 'invoice/invoices',
    'category' => 'Invoices',
    'cat_actions' => array(
      0 => array(
        'path' => 'node/add/erpal-invoice',
        'path_router' => 'node/add/erpal-invoice',
        'path_original' => 'node/add/erpal-invoice',
        'path_pattern' => 'node/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new invoice',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => TRUE,
        'machine_name' => 'invoices',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'billables',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => TRUE,
        'machine_name' => 'payments',
        'reusabled' => FALSE,
        'reusabled_machine_name' => NULL,
      ),
    ),
    'machine_name' => 'erpal_invoices',
    'path_original' => 'invoice/invoices',
    'path_pattern' => 'invoice/%',
    'path_query' => array(),
    'path_router' => 'invoice/invoices',
    'reusable' => 1,
    'cat_remove' => array(),
  );
  $cat_item->weight = -26;
  $export['erpal_invoices'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_add_billable';
  $cat_item->name = 'Erpal Invoices: Add billable';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'billable/add';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(),
    'name' => 'Erpal Invoices: Add billable',
    'path' => 'billable/add',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_add_billable',
    'path_original' => 'billable/add',
    'path_pattern' => 'billable/%',
    'path_query' => array(),
    'path_router' => 'billable/add',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -20;
  $export['erpal_invoices_add_billable'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_billable_view';
  $cat_item->name = 'Erpal invoices: billable view';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'billable/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(
      1 => array(
        'argument_name' => 'billable',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:billable',
        'settings' => array(
          'identifier' => 'Billable: ID',
        ),
      ),
    ),
    'name' => 'Erpal invoices: billable view',
    'path' => 'billable/%',
    'category' => 'Invoices',
    'cat_actions' => array(
      0 => array(
        'path' => 'billable/[billable:id]/edit',
        'path_router' => 'billable/[billable:id]/edit',
        'path_original' => 'billable/[billable:id]/edit',
        'path_pattern' => 'billable/%/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Edit this billable',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_billable_view',
    'path_original' => 'billable/%billable',
    'path_pattern' => 'billable/%',
    'path_query' => array(),
    'path_router' => 'billable/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_invoices_billable_view'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_billables';
  $cat_item->name = 'Erpal Invoices: Billables';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'invoice/billables';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(),
    'name' => 'Erpal Invoices: Billables',
    'path' => 'invoice/billables',
    'category' => 'Invoices',
    'cat_actions' => array(
      0 => array(
        'path' => 'billable/add/billable',
        'path_router' => 'billable/add/billable',
        'path_original' => 'billable/add/billable',
        'path_pattern' => 'billable/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Create a new billable',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_billables',
    'path_original' => 'invoice/billables',
    'path_pattern' => 'invoice/%',
    'path_query' => array(),
    'path_router' => 'invoice/billables',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -25;
  $export['erpal_invoices_billables'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_create_billable';
  $cat_item->name = 'Erpal Invoices: Create billable';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'billable/add/billable';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(),
    'name' => 'Erpal Invoices: Create billable',
    'path' => 'billable/add/billable',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_create_billable',
    'path_original' => 'billable/add/billable',
    'path_pattern' => 'billable/%/%',
    'path_query' => array(),
    'path_router' => 'billable/add/billable',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -22;
  $export['erpal_invoices_create_billable'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_create_invoice';
  $cat_item->name = 'Erpal Invoices: Create Invoice';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'node/add/erpal-invoice';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(),
    'name' => 'Erpal Invoices: Create Invoice',
    'path' => 'node/add/erpal-invoice',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_create_invoice',
    'path_original' => 'node/add/erpal-invoice',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/add/erpal-invoice',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -19;
  $export['erpal_invoices_create_invoice'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_create_unbillable';
  $cat_item->name = 'Erpal Invoices: Create Unbillable';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'billable/add/unbillable';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(),
    'name' => 'Erpal Invoices: Create Unbillable',
    'path' => 'billable/add/unbillable',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_create_unbillable',
    'path_original' => 'billable/add/unbillable',
    'path_pattern' => 'billable/%/%',
    'path_query' => array(),
    'path_router' => 'billable/add/unbillable',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -21;
  $export['erpal_invoices_create_unbillable'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_edit_billable';
  $cat_item->name = 'Erpal Invoices: Edit billable';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'billable/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:billable',
          'settings' => array(
            'type' => array(
              'billable' => 'billable',
            ),
          ),
          'context' => 'billable',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(
      1 => array(
        'argument_name' => 'billable',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:billable',
        'settings' => array(
          'identifier' => 'Billable: ID',
        ),
      ),
    ),
    'name' => 'Erpal Invoices: Edit billable',
    'path' => 'billable/%/edit',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_edit_billable',
    'path_original' => 'billable/%billable/edit',
    'path_pattern' => 'billable/%/%',
    'path_query' => array(),
    'path_router' => 'billable/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -23;
  $export['erpal_invoices_edit_billable'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_invoice_edit';
  $cat_item->name = 'Erpal invoices: invoice edit';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'node/%/edit';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_invoice' => 'erpal_invoice',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal invoices: invoice edit',
    'path' => 'node/%/edit',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_invoice_edit',
    'path_original' => 'node/%node/edit',
    'path_pattern' => 'node/%/%',
    'path_query' => array(),
    'path_router' => 'node/%/edit',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_invoices_invoice_edit'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_invoice_view';
  $cat_item->name = 'Erpal invoices: invoice view';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'node/%';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_invoice' => 'erpal_invoice',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(
      1 => array(
        'argument_name' => 'node',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'name' => 'Erpal invoices: invoice view',
    'path' => 'node/%',
    'category' => 'Invoices',
    'cat_actions' => array(
      0 => array(
        'path' => 'payment/add/[node:nid]',
        'path_router' => 'payment/add/[node:nid]',
        'path_original' => 'payment/add/[node:nid]',
        'path_pattern' => 'payment/%/%',
        'path_query' => array(),
        'path_destination' => TRUE,
        'title' => 'Add new payment',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
      1 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(
          'invoices' => '[node:nid]',
        ),
        'path_destination' => TRUE,
        'title' => 'Add existing payment',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
      ),
    ),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_invoice_view',
    'path_original' => 'node/%node',
    'path_pattern' => 'node/%',
    'path_query' => array(),
    'path_router' => 'node/%',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = 0;
  $export['erpal_invoices_invoice_view'] = $cat_item;

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_invoices_view_billable';
  $cat_item->name = 'Erpal Invoices: View billable';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Invoices';
  $cat_item->path = 'billable/%/view';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:billable',
          'settings' => array(
            'type' => array(
              'billable' => 'billable',
            ),
          ),
          'context' => 'billable',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'active_trail_path' => 'invoice/invoices',
    'arguments' => array(
      1 => array(
        'argument_name' => 'billable',
        'argument_type' => 'path',
        'position' => 1,
        'argument' => 'entity_id:billable',
        'settings' => array(
          'identifier' => 'Billable: ID',
        ),
      ),
    ),
    'name' => 'Erpal Invoices: View billable',
    'path' => 'billable/%/view',
    'category' => 'Invoices',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'invoice/invoices',
        'path_router' => 'invoice/invoices',
        'path_original' => 'invoice/invoices',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Invoices',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|invoices',
      ),
      1 => array(
        'path' => 'invoice/billables',
        'path_router' => 'invoice/billables',
        'path_original' => 'invoice/billables',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Billables',
        'css_id' => '',
        'css_class' => 'active-trail active',
        'active' => TRUE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|billables',
      ),
      2 => array(
        'path' => 'invoice/payments',
        'path_router' => 'invoice/payments',
        'path_original' => 'invoice/payments',
        'path_pattern' => 'invoice/%',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Payments',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_invoices|payments',
      ),
    ),
    'machine_name' => 'erpal_invoices_view_billable',
    'path_original' => 'billable/%billable/view',
    'path_pattern' => 'billable/%/%',
    'path_query' => array(),
    'path_router' => 'billable/%/view',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -24;
  $export['erpal_invoices_view_billable'] = $cat_item;

  return $export;
}
