<?php
/**
 * @file
 * erpal_heartbeat.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_heartbeat_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:heartbeat/all
  $menu_links['menu-erpal-menu:heartbeat/all'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'heartbeat/all',
    'router_path' => 'heartbeat/all',
    'link_title' => 'Heartbeat',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_heartbeat',
        'class' => 'heartbeat',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
  );
  // Exported menu link: user-menu:heartbeat
  $menu_links['user-menu:heartbeat'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'heartbeat',
    'router_path' => 'heartbeat',
    'link_title' => 'Heartbeat',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Heartbeat');


  return $menu_links;
}
