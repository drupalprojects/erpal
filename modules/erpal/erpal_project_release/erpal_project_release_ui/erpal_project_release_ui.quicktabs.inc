<?php
/**
 * @file
 * erpal_project_release_ui.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_project_release_ui_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'release_content_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Release content tabs';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_body_and_comments',
      'hide_title' => 1,
      'title' => 'Details',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'vid' => 'tasks_for_release',
      'display' => 'panel_pane_2',
      'args' => '%1',
      'title' => 'Tasks',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Release content tabs');
  t('Tasks');

  $export['release_content_tabs'] = $quicktabs;

  return $export;
}
