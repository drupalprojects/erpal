<?php
/**
 * @file
 * erpal_bookmark_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_bookmark_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu:bookmarks
  $menu_links['user-menu:bookmarks'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'bookmarks',
    'router_path' => 'bookmarks',
    'link_title' => 'My bookmarks',
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
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('My bookmarks');


  return $menu_links;
}
