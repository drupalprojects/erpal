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
    'weight' => '-50',
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
    'weight' => '-50',
    'parent_path' => 'projects/projects',
  );
  // Exported menu link: menu-erpal-menu:projects/timetrackings/tmp
  $menu_links['menu-erpal-menu:projects/timetrackings/tmp'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'projects/timetrackings/tmp',
    'router_path' => 'projects/timetrackings/tmp',
    'link_title' => 'Active timetrackings',
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
  t('Active timetrackings');
  t('Projects');
  t('Timetrackings');


  return $menu_links;
}
