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
    'budget_usage' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
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
    'budget_usage' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
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
 * Implements hook_ds_custom_fields_info().
 */
function feature_erpal_project_basic_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'budget_usage';
  $ds_field->label = 'Budget usage';
  $ds_field->field_type = 3;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array();
  $export['budget_usage'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_erpal_project_basic_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_project|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_project';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'body',
      ),
      'left' => array(
        0 => 'field_date',
        1 => 'field_project_status',
        2 => 'field_project_status_term',
        3 => 'field_project_contacts',
        4 => 'field_customer_ref',
        5 => 'field_activity_ref',
      ),
      'right' => array(
        0 => 'field_project_tags',
        1 => 'field_pricing',
      ),
      'footer' => array(
        0 => 'field_books_ref',
        1 => 'status',
        2 => 'submit',
        3 => 'delete',
      ),
      'hidden' => array(
        0 => 'menu',
        1 => 'name',
        2 => 'enabled',
        3 => 'comment',
        4 => 'date',
        5 => 'alias',
        6 => 'revision',
        7 => 'link_title',
        8 => 'log',
        9 => 'promote',
        10 => 'description',
        11 => 'link',
        12 => 'parent',
        13 => 'sticky',
        14 => 'weight',
        15 => 'preview',
        16 => 'preview_changes',
        17 => 'revision_information',
        18 => 'path',
        19 => 'comment_settings',
        20 => 'author',
        21 => 'options',
        22 => 'additional_settings',
        23 => 'actions',
        24 => 'group_audience',
        25 => 'group_content_access',
        26 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'body' => 'header',
      'field_date' => 'left',
      'field_project_status' => 'left',
      'field_project_status_term' => 'left',
      'field_project_contacts' => 'left',
      'field_customer_ref' => 'left',
      'field_activity_ref' => 'left',
      'field_project_tags' => 'right',
      'field_pricing' => 'right',
      'field_books_ref' => 'footer',
      'status' => 'footer',
      'submit' => 'footer',
      'delete' => 'footer',
      'menu' => 'hidden',
      'name' => 'hidden',
      'enabled' => 'hidden',
      'comment' => 'hidden',
      'date' => 'hidden',
      'alias' => 'hidden',
      'revision' => 'hidden',
      'link_title' => 'hidden',
      'log' => 'hidden',
      'promote' => 'hidden',
      'description' => 'hidden',
      'link' => 'hidden',
      'parent' => 'hidden',
      'sticky' => 'hidden',
      'weight' => 'hidden',
      'preview' => 'hidden',
      'preview_changes' => 'hidden',
      'revision_information' => 'hidden',
      'path' => 'hidden',
      'comment_settings' => 'hidden',
      'author' => 'hidden',
      'options' => 'hidden',
      'additional_settings' => 'hidden',
      'actions' => 'hidden',
      'group_audience' => 'hidden',
      'group_content_access' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_project|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_project|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_project';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'author',
        2 => 'post_date',
        3 => 'field_project_tags',
        4 => 'field_project_status_term',
        5 => 'field_date',
        6 => 'budget_usage',
      ),
      'right' => array(
        0 => 'field_customer_ref',
        1 => 'field_project_contacts',
        2 => 'field_activity_ref',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'author' => 'left',
      'post_date' => 'left',
      'field_project_tags' => 'left',
      'field_project_status_term' => 'left',
      'field_date' => 'left',
      'budget_usage' => 'left',
      'field_customer_ref' => 'right',
      'field_project_contacts' => 'right',
      'field_activity_ref' => 'right',
      'body' => 'right',
    ),
    'classes' => array(),
  );
  $export['node|erpal_project|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_task|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'field_date',
        1 => 'field_estimated_time',
        2 => 'field_task_type_term',
        3 => 'group_task_time_group',
        4 => 'field_parent',
        5 => 'field_progress_percent',
        6 => 'field_task_status_term',
        7 => 'field_task_status',
      ),
      'header' => array(
        0 => 'title',
        1 => 'field_project_ref',
        2 => 'body',
      ),
      'right' => array(
        0 => 'field_pricing',
        1 => 'field_task_assigned_users',
      ),
      'footer' => array(
        0 => 'field_project_tags',
        1 => 'field_task_exclude_from',
        2 => 'status',
        3 => 'submit',
        4 => 'delete',
        5 => 'comment_settings',
      ),
      'hidden' => array(
        0 => 'description',
        1 => 'parent',
        2 => 'revision',
        3 => 'comment',
        4 => 'weight',
        5 => 'menu',
        6 => 'name',
        7 => 'link_title',
        8 => 'enabled',
        9 => 'alias',
        10 => 'date',
        11 => 'link',
        12 => 'promote',
        13 => 'log',
        14 => 'sticky',
        15 => 'preview',
        16 => 'preview_changes',
        17 => 'field_weight',
        18 => 'revision_information',
        19 => 'path',
        20 => 'author',
        21 => 'options',
        22 => 'additional_settings',
        23 => 'actions',
        24 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'field_date' => 'left',
      'field_estimated_time' => 'left',
      'title' => 'header',
      'field_project_ref' => 'header',
      'body' => 'header',
      'field_task_type_term' => 'left',
      'group_task_time_group' => 'left',
      'field_parent' => 'left',
      'field_progress_percent' => 'left',
      'field_task_status_term' => 'left',
      'field_task_status' => 'left',
      'field_pricing' => 'right',
      'field_task_assigned_users' => 'right',
      'field_project_tags' => 'footer',
      'field_task_exclude_from' => 'footer',
      'status' => 'footer',
      'submit' => 'footer',
      'delete' => 'footer',
      'comment_settings' => 'footer',
      'description' => 'hidden',
      'parent' => 'hidden',
      'revision' => 'hidden',
      'comment' => 'hidden',
      'weight' => 'hidden',
      'menu' => 'hidden',
      'name' => 'hidden',
      'link_title' => 'hidden',
      'enabled' => 'hidden',
      'alias' => 'hidden',
      'date' => 'hidden',
      'link' => 'hidden',
      'promote' => 'hidden',
      'log' => 'hidden',
      'sticky' => 'hidden',
      'preview' => 'hidden',
      'preview_changes' => 'hidden',
      'field_weight' => 'hidden',
      'revision_information' => 'hidden',
      'path' => 'hidden',
      'author' => 'hidden',
      'options' => 'hidden',
      'additional_settings' => 'hidden',
      'actions' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_task|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_task|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_task';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'links',
        1 => 'post_date',
        2 => 'author',
        3 => 'body',
        4 => 'field_project_tags',
        5 => 'field_task_type_term',
        6 => 'field_task_status_term',
      ),
      'left' => array(
        0 => 'budget_usage',
        1 => 'field_date',
        2 => 'field_task_assigned_users',
        3 => 'field_parent',
        4 => 'field_task_exclude_from',
      ),
      'right' => array(
        0 => 'field_estimated_time',
        1 => 'field_project_ref',
        2 => 'field_task_status',
        3 => 'field_progress_percent',
      ),
    ),
    'fields' => array(
      'links' => 'header',
      'post_date' => 'header',
      'author' => 'header',
      'body' => 'header',
      'field_project_tags' => 'header',
      'field_task_type_term' => 'header',
      'field_task_status_term' => 'header',
      'budget_usage' => 'left',
      'field_date' => 'left',
      'field_task_assigned_users' => 'left',
      'field_parent' => 'left',
      'field_task_exclude_from' => 'left',
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
