<?php
/**
 * @file
 * feature_erpal_crm.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_erpal_crm_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:crm/activities
  $menu_links['menu-erpal-menu:crm/activities'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'crm/activities',
    'router_path' => 'crm/activities',
    'link_title' => 'CRM Activities',
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
  t('CRM Activities');


  return $menu_links;
}
