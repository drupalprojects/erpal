<?php
/**
 * @file
 * feature_erpal_calendar.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_erpal_calendar_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-erpal-menu:calendar/global
  $menu_links['menu-erpal-menu:calendar/global'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'calendar/global',
    'router_path' => 'calendar/global',
    'link_title' => 'Calendar',
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
  t('Calendar');


  return $menu_links;
}
