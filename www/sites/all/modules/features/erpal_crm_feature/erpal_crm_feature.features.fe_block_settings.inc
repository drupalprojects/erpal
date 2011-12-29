<?php
/**
 * @file
 * erpal_crm_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function erpal_crm_feature_default_fe_block_settings() {
  $export = array();

  // bartik
  $theme = array();

  $theme['views-crm_activities-block_1'] = array(
    'module' => 'views',
    'delta' => 'crm_activities-block_1',
    'theme' => 'bartik',
    'status' => '1',
    'weight' => '-11',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'crm
crm/*',
    'title' => 'Upcoming CRM activities',
    'cache' => -1,
  );

  $theme['views-crm_activities-block_3'] = array(
    'module' => 'views',
    'delta' => 'crm_activities-block_3',
    'theme' => 'bartik',
    'status' => '1',
    'weight' => '-10',
    'region' => 'sidebar_second',
    'custom' => '0',
    'visibility' => '1',
    'pages' => 'crm
crm/*',
    'title' => 'Missed CRM activities',
    'cache' => -1,
  );

  $export['bartik'] = $theme;

  // seven
  $theme = array();

  $theme['views-crm_activities-block_1'] = array(
    'module' => 'views',
    'delta' => 'crm_activities-block_1',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'crm
crm/*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-crm_activities-block_3'] = array(
    'module' => 'views',
    'delta' => 'crm_activities-block_3',
    'theme' => 'seven',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'crm
crm/*',
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
