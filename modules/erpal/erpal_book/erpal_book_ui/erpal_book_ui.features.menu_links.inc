<?php
/**
 * @file
 * erpal_book_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_book_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu_documents:books/books
  $menu_links['menu-erpal-menu_documents:books/books'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'books/books',
    'router_path' => 'books/%',
    'link_title' => 'Documents',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_documents',
        'class' => 'documents',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_documents:books/books',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');


  return $menu_links;
}
