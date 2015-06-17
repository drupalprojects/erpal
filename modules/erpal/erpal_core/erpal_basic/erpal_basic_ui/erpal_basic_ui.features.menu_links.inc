<?php
/**
 * @file
 * erpal_basic_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_basic_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu_contacts:contacts
  $menu_links['menu-erpal-menu_contacts:contacts'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'contacts',
    'router_path' => 'contacts',
    'link_title' => 'Contacts',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_contacts',
        'class' => 'contacts',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_contacts:contacts',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
  );
  // Exported menu link: user-menu_user-account:user
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => 'my-account',
        'style' => '',
      ),
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contacts');
  t('Log out');
  t('User account');


  return $menu_links;
}
