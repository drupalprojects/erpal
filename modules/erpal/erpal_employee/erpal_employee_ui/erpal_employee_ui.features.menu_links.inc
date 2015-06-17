<?php
/**
 * @file
 * erpal_employee_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_employee_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu_timekeeping:timekeeping
  $menu_links['menu-erpal-menu_timekeeping:timekeeping'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'timekeeping',
    'router_path' => 'timekeeping',
    'link_title' => 'Timekeeping',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_timekeeping',
        'class' => 'timekeeping',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_timekeeping:timekeeping',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'customized' => 1,
  );
  // Exported menu link: user-menu_timekeeping:timekeeping
  $menu_links['user-menu_timekeeping:timekeeping'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'timekeeping',
    'router_path' => 'timekeeping',
    'link_title' => 'timekeeping',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'user_menu_timekeeping',
        'class' => 'timekeeping',
        'style' => '',
      ),
      'identifier' => 'user-menu_timekeeping:timekeeping',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Timekeeping');
  t('timekeeping');


  return $menu_links;
}
