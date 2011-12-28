<?php
/**
 * @file
 * erpal_docs_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_docs_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:documents
  $menu_links['menu-erpal-menu:documents'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'documents',
    'router_path' => 'documents',
    'link_title' => 'Documents',
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
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');


  return $menu_links;
}
