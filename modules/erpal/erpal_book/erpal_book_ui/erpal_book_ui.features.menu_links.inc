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

  // Exported menu link: menu-erpal-menu:books/books
  $menu_links['menu-erpal-menu:books/books'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'books/books',
    'router_path' => 'books/%',
    'link_title' => 'Documents',
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
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');


  return $menu_links;
}
