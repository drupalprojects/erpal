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
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Invoices');


  return $menu_links;
}
