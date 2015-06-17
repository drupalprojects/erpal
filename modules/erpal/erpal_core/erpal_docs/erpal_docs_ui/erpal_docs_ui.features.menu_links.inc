<?php
/**
 * @file
 * erpal_docs_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_docs_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu_files:files
  $menu_links['menu-erpal-menu_files:files'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'files',
    'router_path' => 'files',
    'link_title' => 'Files',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_files',
        'class' => 'files',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_files:files',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Files');


  return $menu_links;
}
