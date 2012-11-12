<?php
/**
 * @file
 * feature_erpal_bookmark.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_erpal_bookmark_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function feature_erpal_bookmark_flag_default_flags() {
  $flags = array();
  // Exported flag: "bookmark flag".
  $flags['bookmark_flag'] = array(
    'entity_type' => 'node',
    'title' => 'bookmark flag',
    'global' => '0',
    'types' => array(
      0 => 'erpal_crm_activity',
      1 => 'erpal_book',
      2 => 'erpal_book_page',
      3 => 'erpal_contact',
      4 => 'erpal_contract',
      5 => 'erpal_date',
      6 => 'erpal_file',
      7 => 'erpal_invoice',
      8 => 'erpal_project',
      9 => 'erpal_space',
      10 => 'erpal_task',
      11 => 'erpal_timetracking',
    ),
    'flag_short' => 'bookmark this',
    'flag_long' => 'Add content to your bookmarks',
    'flag_message' => 'Added to bookmarks',
    'unflag_short' => 'Don\'t bookmark this',
    'unflag_long' => 'Remove content from your bookmarks',
    'unflag_message' => 'Removed from bookmarks',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'i18n' => 0,
    'module' => 'feature_erpal_bookmark',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
