<?php
/**
 * @file
 * feature_erpal_book.rel.inc
 */

/**
 * Implements hook_rel_build_info().
 */
function feature_erpal_book_rel_build_info() {
  $export = array();

  $rel = new stdClass();
  $rel->api_version = 1;
  $rel->build_id = 'erpal_book_node_form';
  $rel->label = 'erpal_book_node_form';
  $rel->entity_type = 'node';
  $rel->bundle = 'erpal_book';
  $rel->view_mode = 'form';
  $rel->context = 'form';
  $rel->path = 'admin/structure/types/manage/erpal-book/fields';
  $rel->elements = array(
    'title' => array(
      'owner' => 'drupal',
      'label' => 'Title',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => -5,
      'element_type' => 'textfield',
    ),
    'field_book_origin' => array(
      'owner' => 'drupal',
      'label' => 'Field book origin',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '7',
      'element_type' => 'container',
    ),
    'field_book_tags' => array(
      'owner' => 'drupal',
      'label' => 'Field book tags',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '5',
      'element_type' => 'container',
    ),
    'field_is_template' => array(
      'owner' => 'drupal',
      'label' => 'Field is template',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '6',
      'element_type' => 'container',
    ),
    'field_address_id' => array(
      'owner' => 'drupal',
      'label' => 'Field address id',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '2',
      'element_type' => 'container',
    ),
    'field_contact_ref' => array(
      'owner' => 'drupal',
      'label' => 'Field contact ref',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '1',
      'element_type' => 'container',
    ),
  );
  $rel->duplicate = array();
  $export['erpal_book_node_form'] = $rel;

  $rel = new stdClass();
  $rel->api_version = 1;
  $rel->build_id = 'erpal_book_page_node_form';
  $rel->label = 'erpal_book_page_node_form';
  $rel->entity_type = 'node';
  $rel->bundle = 'erpal_book_page';
  $rel->view_mode = 'form';
  $rel->context = 'form';
  $rel->path = 'admin/structure/types/manage/erpal-book-page/fields';
  $rel->elements = array(
    'title' => array(
      'owner' => 'drupal',
      'label' => 'Title',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => -5,
      'element_type' => 'textfield',
    ),
    'field_book_origin' => array(
      'owner' => 'drupal',
      'label' => 'Field book origin',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '-2',
      'element_type' => 'container',
    ),
    'field_is_template' => array(
      'owner' => 'drupal',
      'label' => 'Field is template',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '-1',
      'element_type' => 'container',
    ),
    'field_book_tags' => array(
      'owner' => 'drupal',
      'label' => 'Field book tags',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '1',
      'element_type' => 'container',
    ),
    'field_estimated_duration' => array(
      'owner' => 'drupal',
      'label' => 'Field estimated duration',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '2',
      'element_type' => 'container',
    ),
    'field_weight' => array(
      'owner' => 'drupal',
      'label' => 'Field weight',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '3',
      'element_type' => 'container',
    ),
    'field_parent' => array(
      'owner' => 'drupal',
      'label' => 'Field parent',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '4',
      'element_type' => 'container',
    ),
    'field_book_ref' => array(
      'owner' => 'drupal',
      'label' => 'Field book ref',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '5',
      'element_type' => 'container',
    ),
    'field_page_exclude_from' => array(
      'owner' => 'drupal',
      'label' => 'Field page exclude from',
      'parent' => '',
      'group_info' => FALSE,
      'weight' => '6',
      'element_type' => 'container',
    ),
  );
  $rel->duplicate = array();
  $export['erpal_book_page_node_form'] = $rel;

  return $export;
}
