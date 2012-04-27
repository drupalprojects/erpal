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
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-erpal-menu:projects/tasks
  $menu_links['menu-erpal-menu:projects/tasks'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'projects/tasks',
    'router_path' => 'projects/tasks',
    'link_title' => 'Tasks',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '1',
    'weight' => '-50',
    'parent_path' => 'projects/projects',
  );
  // Exported menu link: menu-erpal-menu:projects/timetrackings
  $menu_links['menu-erpal-menu:projects/timetrackings'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'projects/timetrackings',
    'router_path' => 'projects/timetrackings',
    'link_title' => 'Timetrackings',
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
    'parent_path' => 'projects/projects',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Projects');
  t('Tasks');
  t('Timetrackings');


  return $menu_links;
}
