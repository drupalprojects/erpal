<?php
/**
 * @file
 * feature_erpal_spaces.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_erpal_spaces_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:spaces/spaces
  $menu_links['menu-erpal-menu:spaces/spaces'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'spaces/spaces',
    'router_path' => 'spaces/spaces',
    'link_title' => 'Spaces',
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
    'weight' => '-43',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Spaces');


  return $menu_links;
}
