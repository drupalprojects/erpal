<?php
/**
 * @file
 * erpal_contract_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_contract_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:contracts
  $menu_links['menu-erpal-menu:contracts'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'contracts',
    'router_path' => 'contracts',
    'link_title' => 'Contracts',
    'options' => array(),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contracts');


  return $menu_links;
}
