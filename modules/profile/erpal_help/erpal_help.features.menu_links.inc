<?php
/**
 * @file
 * erpal_help.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_help_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: user-menu_help:erpal/js/help/start
  $menu_links['user-menu_help:erpal/js/help/start'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'erpal/js/help/start',
    'router_path' => 'erpal/%/help',
    'link_title' => 'ERPAL online help',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_help',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'user-menu_help:erpal/js/help/start',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 100,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('ERPAL online help');


  return $menu_links;
}
