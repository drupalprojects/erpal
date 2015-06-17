<?php
/**
 * @file
 * erpal_invoice_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_invoice_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-contact-menu_show-all-invoices:invoice/invoices
  $menu_links['menu-contact-menu_show-all-invoices:invoice/invoices'] = array(
    'menu_name' => 'menu-contact-menu',
    'link_path' => 'invoice/invoices',
    'router_path' => 'invoice/invoices',
    'link_title' => 'Show all Invoices',
    'options' => array(
      'menu_token_link_path' => 'invoice/invoices?title_1=[node:title]',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 1,
      ),
      'alter' => TRUE,
      'query' => array(
        'field_customer_ref_target_id%5B%5D' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => 'invoice',
        'style' => '',
      ),
      'identifier' => 'menu-contact-menu_show-all-invoices:invoice/invoices',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 0,
  );
  // Exported menu link: menu-erpal-menu_invoices:invoice/invoices
  $menu_links['menu-erpal-menu_invoices:invoice/invoices'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'invoice/invoices',
    'router_path' => 'invoice/invoices',
    'link_title' => 'Invoices',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_invoices',
        'class' => 'invoices',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_invoices:invoice/invoices',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Invoices');
  t('Show all Invoices');


  return $menu_links;
}
