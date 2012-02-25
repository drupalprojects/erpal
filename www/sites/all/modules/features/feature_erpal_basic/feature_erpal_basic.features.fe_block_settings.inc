<?php
/**
 * @file
 * feature_erpal_basic.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_erpal_basic_default_fe_block_settings() {
  $export = array();

  // bartik
  $theme = array();

  $theme['menu-menu-erpal-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-erpal-menu',
    'theme' => 'bartik',
    'status' => '1',
    'weight' => '-10',
    'region' => 'sidebar_first',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['bartik'] = $theme;

  // seven
  $theme = array();

  $theme['menu-menu-erpal-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-erpal-menu',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['seven'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
