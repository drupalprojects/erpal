<?php
/**
 * @file
 * feature_erpal_dashboard.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_dashboard_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_homebox().
 */
function feature_erpal_dashboard_homebox() {
  $homeboxes = array();

  $homeboxes['user_dashboard'] = array (
    'regions' => 2,
    'cache' => 0,
    'color' => 0,
    'colors' => 
    array (
      0 => '#E4F0F8',
      1 => '#E4F0F8',
      2 => '#E4F0F8',
      3 => '#E4F0F8',
      4 => '#E4F0F8',
      5 => '#E4F0F8',
    ),
    'blocks' => 
    array (
      'views_assigned_tasks-block' => 
      array (
        'module' => 'views',
        'delta' => 'assigned_tasks-block',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -24,
      ),
      'views_bookmarks-block' => 
      array (
        'module' => 'views',
        'delta' => 'bookmarks-block',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -23,
      ),
      'views_timetracking_entities-block_1' => 
      array (
        'module' => 'views',
        'delta' => 'timetracking_entities-block_1',
        'region' => 2,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -23,
      ),
      'timetracking_block' => 
      array (
        'module' => 'timetracking',
        'delta' => 'block',
        'region' => 1,
        'movable' => 1,
        'status' => 1,
        'open' => 1,
        'closable' => 1,
        'title' => '',
        'weight' => -24,
      ),
    ),
    'widths' => 
    array (
    ),
    'title' => 'Dashboard',
    'path' => 'dashboard',
    'menu' => 0,
    'enabled' => 1,
    'auto_save' => 1,
    'full' => 1,
    'roles' => 
    array (
      0 => 'authenticated user',
    ),
  );


  return $homeboxes;
}
