<?php
/**
 * @file
 * erpal_book.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_book_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function erpal_book_node_info() {
  $items = array(
    'erpal_book' => array(
      'name' => t('Document'),
      'base' => 'node_content',
      'description' => t('A document representing a documentation or a proposal or a project specification'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'erpal_book_page' => array(
      'name' => t('Document page'),
      'base' => 'node_content',
      'description' => t('A page with subpages of a document'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
