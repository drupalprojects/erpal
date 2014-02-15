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

  // Exported menu link: user-menu_my-bookmarks:user/bookmarks
  $menu_links['user-menu_my-bookmarks:user/bookmarks'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/bookmarks',
    'router_path' => 'user/bookmarks',
    'link_title' => 'My bookmarks',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'user_menu_my_bookmarks',
        'class' => 'my-bookmarks',
        'style' => '',
      ),
      'identifier' => 'user-menu_my-bookmarks:user/bookmarks',
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
  t('My bookmarks');


  return $menu_links;
}
