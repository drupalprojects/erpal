<?php
/**
 * @file
 * erpal_crm.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function erpal_crm_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-contact-menu.
  $menus['menu-contact-menu'] = array(
    'menu_name' => 'menu-contact-menu',
    'title' => 'Contact Menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Menu');


  return $menus;
}
