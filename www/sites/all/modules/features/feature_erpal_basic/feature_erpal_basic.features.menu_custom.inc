<?php
/**
 * @file
 * feature_erpal_basic.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_erpal_basic_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-erpal-menu.
  $menus['menu-erpal-menu'] = array(
    'menu_name' => 'menu-erpal-menu',
    'title' => 'ERPAL Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('ERPAL Menu');


  return $menus;
}
