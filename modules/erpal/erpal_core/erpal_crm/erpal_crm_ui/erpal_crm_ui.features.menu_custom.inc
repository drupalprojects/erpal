<?php
/**
 * @file
 * erpal_crm_ui.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function erpal_crm_ui_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-contact-menu.
  $menus['menu-contact-menu'] = array(
    'menu_name' => 'menu-contact-menu',
    'title' => 'Contact Menu',
    'description' => 'Links shown on the right side on the contact page.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contact Menu');
  t('Links shown on the right side on the contact page.');


  return $menus;
}
