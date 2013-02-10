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
  // Exported menu link: user-menu:user/projects
  $menu_links['user-menu:user/projects'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/projects',
    'router_path' => 'user/projects',
    'link_title' => 'My projects',
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
    'weight' => '-47',
  );
  // Exported menu link: user-menu:user/tasks
  $menu_links['user-menu:user/tasks'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/tasks',
    'router_path' => 'user/tasks',
    'link_title' => 'My tasks',
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
    'weight' => '-46',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('My projects');
  t('My tasks');
  t('Projects');


  return $menu_links;
}
