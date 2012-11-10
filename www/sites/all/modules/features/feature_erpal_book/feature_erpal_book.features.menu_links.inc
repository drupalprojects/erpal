<?php
/**
 * @file
 * feature_erpal_book.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_erpal_book_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:books/books
  $menu_links['menu-erpal-menu:books/books'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'books/books',
    'router_path' => 'books/books',
    'link_title' => 'Books',
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
    'weight' => '-47',
  );
  // Exported menu link: menu-erpal-menu:books/templates
  $menu_links['menu-erpal-menu:books/templates'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'books/templates',
    'router_path' => 'books/templates',
    'link_title' => 'Book templates',
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
    'parent_path' => 'books/books',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Book templates');
  t('Books');


  return $menu_links;
}
