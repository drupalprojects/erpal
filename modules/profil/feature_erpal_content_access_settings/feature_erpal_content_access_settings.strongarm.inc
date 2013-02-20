<?php
/**
 * @file
 * feature_erpal_content_access_settings.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_erpal_content_access_settings_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_settings';
  $strongarm->value = array(
    'view' => array(
      'erpal_contact' => array(
        0 => 8,
        1 => 7,
        2 => 4,
        3 => 3,
        4 => 9,
      ),
      'erpal_book' => array(
        0 => 8,
        1 => 7,
        2 => 4,
        3 => 3,
        4 => 9,
      ),
      'erpal_book_page' => array(
        0 => 7,
        1 => 4,
        2 => 3,
        3 => 9,
      ),
      'erpal_date' => array(),
      'erpal_contract' => array(
        0 => 7,
        1 => 4,
        2 => 3,
      ),
      'erpal_crm_activity' => array(
        0 => 7,
        1 => 4,
        2 => 3,
      ),
      'erpal_file' => array(
        0 => 8,
        1 => 7,
        2 => 4,
        3 => 3,
        4 => 9,
      ),
      'erpal_invoice' => array(
        0 => 7,
        1 => 4,
      ),
      'erpal_project' => array(
        0 => 8,
        1 => 7,
        2 => 4,
        3 => 3,
        4 => 9,
      ),
      'erpal_task' => array(
        0 => 8,
        1 => 9,
      ),
      'erpal_timetracking' => array(
        0 => 7,
        1 => 3,
        2 => 9,
      ),
      'erpal_space' => array(
        0 => 3,
        1 => 9,
      ),
    ),
    'view_own' => array(
      'erpal_contact' => array(
        0 => 2,
      ),
      'erpal_book' => array(
        0 => 2,
      ),
      'erpal_book_page' => array(
        0 => 2,
      ),
      'erpal_date' => array(
        0 => 2,
      ),
      'erpal_contract' => array(
        0 => 2,
      ),
      'erpal_crm_activity' => array(
        0 => 2,
      ),
      'erpal_file' => array(
        0 => 2,
      ),
      'erpal_invoice' => array(
        0 => 2,
      ),
      'erpal_project' => array(
        0 => 2,
      ),
      'erpal_task' => array(
        0 => 2,
      ),
      'erpal_timetracking' => array(
        0 => 2,
      ),
      'erpal_space' => array(
        0 => 2,
      ),
    ),
    'per_node' => array(
      'erpal_contact' => 0,
      'erpal_book' => 0,
      'erpal_book_page' => 0,
      'erpal_date' => 0,
      'erpal_contract' => 0,
      'erpal_crm_activity' => 0,
      'erpal_file' => 0,
      'erpal_invoice' => 0,
      'erpal_project' => 0,
      'erpal_task' => 0,
      'erpal_timetracking' => 0,
      'erpal_space' => 0,
    ),
    'priority' => array(
      'erpal_contact' => '0',
      'erpal_book' => '0',
      'erpal_book_page' => '0',
      'erpal_date' => '0',
      'erpal_contract' => '0',
      'erpal_crm_activity' => '0',
      'erpal_file' => '0',
      'erpal_invoice' => '0',
      'erpal_project' => '0',
      'erpal_task' => '0',
      'erpal_timetracking' => '0',
      'erpal_space' => '0',
    ),
  );
  $export['content_access_settings'] = $strongarm;

  return $export;
}
