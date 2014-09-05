<?php
/**
 * @file
 * erpal_bookmark_ui.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_bookmark_ui_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'bookmarks';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Bookmarks';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'bookmarks',
      'display' => 'panel_pane_1',
      'args' => '',
      'title' => 'All bookmarks',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'bookmarks',
      'display' => 'panel_pane_2',
      'args' => '',
      'title' => 'Task bookmarks',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('All bookmarks');
  t('Bookmarks');
  t('Task bookmarks');

  $export['bookmarks'] = $quicktabs;

  return $export;
}
