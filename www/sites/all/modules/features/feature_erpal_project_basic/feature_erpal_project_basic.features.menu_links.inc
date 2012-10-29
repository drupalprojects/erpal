<?php
/**
 * @file
 * feature_erpal_project_basic.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_erpal_project_basic_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:projects/projects
  $menu_links['menu-erpal-menu:projects/projects'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'projects/projects',
    'router_path' => 'projects/projects',
    'link_title' => 'Projects',
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
    'weight' => '-50',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Projects');


  return $menu_links;
}
