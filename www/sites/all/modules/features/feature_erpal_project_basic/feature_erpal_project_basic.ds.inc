<?php
/**
 * @file
 * feature_erpal_project_basic.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function feature_erpal_project_basic_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_project|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_project';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|erpal_project|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|erpal_task|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'erpal_task';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_long',
    ),
  );
  $export['node|erpal_task|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_erpal_project_basic_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'author',
        2 => 'post_date',
        3 => 'field_project_tags',
        4 => 'field_date',
        5 => 'field_project_status',
        6 => 'field_pricing',
      ),
      'right' => array(
        0 => 'field_customer_ref',
        1 => 'field_project_contacts',
        2 => 'field_book_ref',
        3 => 'field_activity_ref',
        4 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'author' => 'left',
      'post_date' => 'left',
      'field_project_tags' => 'left',
      'field_date' => 'left',
      'field_project_status' => 'left',
      'field_pricing' => 'left',
      'field_customer_ref' => 'right',
      'field_project_contacts' => 'right',
      'field_book_ref' => 'right',
      'field_activity_ref' => 'right',
      'body' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|erpal_project|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_task|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'links',
        1 => 'post_date',
        2 => 'author',
        3 => 'body',
        4 => 'field_project_tags',
      ),
      'left' => array(
        0 => 'field_task_type',
        1 => 'field_date',
        2 => 'field_task_assigned_users',
        3 => 'field_parent',
        4 => 'field_task_exclude_from',
      ),
      'right' => array(
        0 => 'field_pricing',
        1 => 'field_estimated_time',
        2 => 'field_project_ref',
        3 => 'field_task_status',
        4 => 'field_progress_percent',
      ),
    ),
    'fields' => array(
      'links' => 'header',
      'post_date' => 'header',
      'author' => 'header',
      'body' => 'header',
      'field_project_tags' => 'header',
      'field_task_type' => 'left',
      'field_date' => 'left',
      'field_task_assigned_users' => 'left',
      'field_parent' => 'left',
      'field_task_exclude_from' => 'left',
      'field_pricing' => 'right',
      'field_estimated_time' => 'right',
      'field_project_ref' => 'right',
      'field_task_status' => 'right',
      'field_progress_percent' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|erpal_task|full'] = $ds_layout;

  return $export;
}
