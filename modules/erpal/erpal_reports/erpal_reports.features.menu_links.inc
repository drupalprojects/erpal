<?php
/**
 * @file
 * erpal_reports.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_reports_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu_reporting:reports/dashboard
  $menu_links['menu-erpal-menu_reporting:reports/dashboard'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'reports/dashboard',
    'router_path' => 'reports/%',
    'link_title' => 'Reporting',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_reports',
        'class' => 'reports',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_reporting:reports/dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Reporting');


  return $menu_links;
}
