<?php
/**
 * @file
 * erpal_bookmark.cat.inc
 */

/**
 * Implements hook_cat_items_settings_info().
 */
function erpal_bookmark_cat_items_settings_info() {
  $export = array();

  $cat_item = new stdClass();
  $cat_item->api_version = 1;
  $cat_item->machine_name = 'erpal_bookmarks_my_bookmarks';
  $cat_item->name = 'Erpal Bookmarks: My Bookmarks';
  $cat_item->catch_subpaths = 0;
  $cat_item->category = 'Bookmarks';
  $cat_item->path = 'user/bookmarks';
  $cat_item->data = array(
    'api_version' => 1,
    'access' => array(),
    'arguments' => array(),
    'name' => 'Erpal Bookmarks: My Bookmarks',
    'path' => 'user/bookmarks',
    'category' => 'Bookmarks',
    'cat_actions' => array(),
    'cat_tabs' => array(
      0 => array(
        'path' => 'dashboard',
        'path_router' => 'dashboard',
        'path_original' => 'dashboard',
        'path_pattern' => 'dashboard',
        'path_query' => array(),
        'path_destination' => FALSE,
        'title' => 'Home',
        'css_id' => '',
        'css_class' => '',
        'active' => FALSE,
        'reusable' => FALSE,
        'machine_name' => '',
        'reusabled' => TRUE,
        'reusabled_machine_name' => 'erpal_home|erpal_home',
      ),
    ),
    'machine_name' => 'erpal_bookmarks_my_bookmarks',
    'path_original' => 'user/bookmarks',
    'path_pattern' => 'user/%',
    'path_query' => array(),
    'path_router' => 'user/bookmarks',
    'reusable' => 0,
    'cat_remove' => array(),
  );
  $cat_item->weight = -5;
  $export['erpal_bookmarks_my_bookmarks'] = $cat_item;

  return $export;
}
