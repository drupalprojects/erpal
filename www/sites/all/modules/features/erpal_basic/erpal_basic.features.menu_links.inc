<?php
/**
 * @file
 * erpal_basic.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_basic_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:contacts
  $menu_links['menu-erpal-menu:contacts'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'contacts',
    'router_path' => 'contacts',
    'link_title' => 'Contacts',
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
  t('Contacts');


  return $menu_links;
}
