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

  // Exported menu link: user-menu:timekeeping
  $menu_links['user-menu:timekeeping'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'timekeeping',
    'router_path' => 'timekeeping',
    'link_title' => 'timekeeping',
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
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('timekeeping');


  return $menu_links;
}
