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
    'weight' => '-48',
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
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Active timetrackings');
  t('Timetrackings');


  return $menu_links;
}
