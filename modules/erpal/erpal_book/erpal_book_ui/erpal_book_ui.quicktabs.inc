<?php
/**
 * @file
 * erpal_book_ui.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function erpal_book_ui_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'book_and_page_node_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Book and page node tabs';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_body_and_comments',
      'hide_title' => 1,
      'title' => 'Details',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'vid' => 'book_and_page_revisions',
      'display' => 'panel_pane_1',
      'args' => '%1',
      'title' => 'History',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'erpal_no_js_tabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Book and page node tabs');
  t('Details');
  t('History');

  $export['book_and_page_node_tabs'] = $quicktabs;

  return $export;
}
