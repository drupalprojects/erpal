<?php
/**
 * @file
 * feature_erpal_invoice.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_erpal_invoice_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:invoice/billables
  $menu_links['menu-erpal-menu:invoice/billables'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'invoice/billables',
    'router_path' => 'invoice/billables',
    'link_title' => 'Billbles',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => 'invoice/invoices',
  );
  // Exported menu link: menu-erpal-menu:invoice/invoices
  $menu_links['menu-erpal-menu:invoice/invoices'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'invoice/invoices',
    'router_path' => 'invoice/invoices',
    'link_title' => 'Invoices',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Billbles');
  t('Invoices');


  return $menu_links;
}
