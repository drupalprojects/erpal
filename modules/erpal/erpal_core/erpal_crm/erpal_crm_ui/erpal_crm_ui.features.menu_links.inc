<?php
/**
 * @file
 * erpal_crm_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_crm_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:activities
  $menu_links['menu-erpal-menu:activities'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'activities',
    'router_path' => 'activities',
    'link_title' => 'Activities',
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
  t('Activities');


  return $menu_links;
}
