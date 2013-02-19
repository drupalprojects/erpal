<?php
/**
 * @file
 * erpal_basic_ui.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function erpal_basic_ui_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-erpal-menu.
  $menus['menu-erpal-menu'] = array(
    'menu_name' => 'menu-erpal-menu',
    'title' => 'ERPAL Menu',
    'description' => '',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('ERPAL Menu');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');


  return $menus;
}
