<?php
/**
 * @file
 * erpal_project_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_project_ui_menu_default_menu_links() {
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
    'weight' => '-48',
  );
  // Exported menu link: user-menu:tasks
  $menu_links['user-menu:tasks'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'tasks',
    'router_path' => 'tasks',
    'link_title' => 'My Tasks',
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
  t('My Tasks');
  t('Projects');


  return $menu_links;
}
