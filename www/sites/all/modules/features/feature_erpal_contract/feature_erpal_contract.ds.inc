<?php
/**
 * @file
 * feature_erpal_contract.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_erpal_contract_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_contract|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_contract';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_form';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        0 => 'field_contract_type',
        1 => 'field_contract_payment',
      ),
      'right' => array(
        0 => 'group_cancelation',
        1 => 'field_date',
        2 => 'field_cancelation_period',
        3 => 'field_cancelation_period_con',
        4 => 'field_budget_booking',
        5 => 'field_cancelation_period_unit',
      ),
      'footer' => array(
        0 => 'field_asset_files',
        1 => 'body',
        2 => 'status',
        3 => 'submit',
      ),
      'hidden' => array(
        0 => 'menu',
        1 => 'name',
        2 => 'options',
        3 => 'revision',
        4 => 'comment',
        5 => 'enabled',
        6 => 'alias',
        7 => 'link_title',
        8 => 'date',
        9 => 'link',
        10 => 'description',
        11 => 'promote',
        12 => 'log',
        13 => 'sticky',
        14 => 'parent',
        15 => 'weight',
        16 => 'preview',
        17 => 'revision_information',
        18 => 'comment_settings',
        19 => 'path',
        20 => 'author',
        21 => 'additional_settings',
        22 => 'actions',
        23 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_contract_type' => 'left',
      'field_contract_payment' => 'left',
      'group_cancelation' => 'right',
      'field_date' => 'right',
      'field_cancelation_period' => 'right',
      'field_cancelation_period_con' => 'right',
      'field_budget_booking' => 'right',
      'field_cancelation_period_unit' => 'right',
      'field_asset_files' => 'footer',
      'body' => 'footer',
      'status' => 'footer',
      'submit' => 'footer',
      'menu' => 'hidden',
      'name' => 'hidden',
      'options' => 'hidden',
      'revision' => 'hidden',
      'comment' => 'hidden',
      'enabled' => 'hidden',
      'alias' => 'hidden',
      'link_title' => 'hidden',
      'date' => 'hidden',
      'link' => 'hidden',
      'description' => 'hidden',
      'promote' => 'hidden',
      'log' => 'hidden',
      'sticky' => 'hidden',
      'parent' => 'hidden',
      'weight' => 'hidden',
      'preview' => 'hidden',
      'revision_information' => 'hidden',
      'comment_settings' => 'hidden',
      'path' => 'hidden',
      'author' => 'hidden',
      'additional_settings' => 'hidden',
      'actions' => 'hidden',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(),
  );
  $export['node|erpal_contract|form'] = $ds_layout;

  return $export;
}
