<?php

/**
 * @file
 * Drush integration for the Simpletest Fixture module.
 */

/**
 * Implements hook_drush_command().
 */
function simpletest_fixture_drush_command() {
  $items['fixture-generate'] = array(
    'description' => dt('Generate new fixtures from default database.'),
    'arguments' => array(),
    'options' => array(
      '--full' => 'Regenerate drupal and fixture tables (standard is only fixture tables)',
    ),    
    'aliases' => array('fxg'),
  );
  return $items;
}

/**
 * A command callback.
 */
function drush_simpletest_fixture_fixture_generate() {
  $mode = drush_get_option('full') ? 'full' : 'fixtures';
  $res = simpletest_fixture_generate($mode);
  if ($res != FALSE) {
    drush_print(dt('Dropped @dropped_tables_count tables.', array('@dropped_tables_count' => $res['dropped_tables_count'])));
    drush_print(dt('Cloned @cloned_tables_count tables.', array('@cloned_tables_count' => $res['cloned_tables_count'])));
    drush_log('New fixtures generated.', 'ok');  
  }
  else {
    drush_log('Generating new fixtures failed.', 'error');  
  }
}
