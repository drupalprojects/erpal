<?php
/**
 * @file
 * feature_erpal_book.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_book_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_erpal_book_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_erpal_book_node_info() {
  $items = array(
    'erpal_book' => array(
      'name' => t('Book'),
      'base' => 'node_content',
      'description' => t('A document representing a book or a document like a proposal or a project specification'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'erpal_book_page' => array(
      'name' => t('Book page'),
      'base' => 'node_content',
      'description' => t('A page with subpages of a book'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
