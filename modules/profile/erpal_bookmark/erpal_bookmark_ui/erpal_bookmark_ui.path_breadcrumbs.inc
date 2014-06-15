<?php
/**
 * @file
 * erpal_bookmark_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_bookmark_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'bookmarks_view_breadcrumb';
  $path_breadcrumb->name = 'Bookmarks view breadcrumb';
  $path_breadcrumb->path = 'user/bookmarks';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Bookmarks',
    ),
    'paths' => array(
      0 => 'user/bookmarks',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['bookmarks_view_breadcrumb'] = $path_breadcrumb;

  return $export;
}
