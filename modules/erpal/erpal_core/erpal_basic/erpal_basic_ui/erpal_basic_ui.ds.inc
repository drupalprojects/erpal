<?php
/**
 * @file
 * erpal_basic_ui.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function erpal_basic_ui_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'comment_count';
  $ds_field->label = 'comment_count';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['comment_count'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function erpal_basic_ui_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|erpal_contact|form';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'erpal_contact';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'erpal_forms';
  $ds_layout->settings = array(
    'hide_empty_regions' => 1,
    'hide_sidebars' => FALSE,
    'regions' => array(
      'left' => array(
        0 => 'group_basics',
        1 => 'group_relations',
        2 => 'group_communication',
        3 => 'field_contact_relations',
        4 => 'group_addresses',
        5 => 'field_communication',
        6 => 'field_addresses',
        7 => 'group_banking',
        8 => 'group_notes',
        9 => 'field_bank_accounts',
        10 => 'body',
        11 => 'group_files',
        12 => 'field_asset_files',
        13 => 'field_legal_other',
        14 => '_add_existing_field',
        15 => 'field_contact_type',
        16 => 'field_company_name',
        17 => 'field_salutation',
        18 => 'field_gender',
        19 => 'field_firstname',
        20 => 'field_lastname',
        21 => 'field_activity_origin',
        22 => 'field_target_audience',
        23 => 'field_contact_tags',
        24 => 'field_birthday',
        25 => 'field_languages',
        26 => 'field_vat_number',
        27 => 'field_customer_category',
      ),
      'right' => array(
        0 => 'field_contact_image',
        1 => 'field_service_categories',
      ),
      'hidden' => array(
        0 => 'group_legal',
        1 => 'title',
        2 => 'path',
      ),
    ),
    'fields' => array(
      'group_basics' => 'left',
      'group_relations' => 'left',
      'group_communication' => 'left',
      'field_contact_relations' => 'left',
      'group_addresses' => 'left',
      'field_communication' => 'left',
      'field_addresses' => 'left',
      'group_banking' => 'left',
      'group_notes' => 'left',
      'field_bank_accounts' => 'left',
      'body' => 'left',
      'group_files' => 'left',
      'field_asset_files' => 'left',
      '_add_existing_field' => 'left',
      'field_legal_other' => 'left',
      'field_contact_type' => 'left',
      'field_contact_image' => 'right',
      'field_company_name' => 'left',
      'field_service_categories' => 'right',
      'group_legal' => 'hidden',
      'field_salutation' => 'left',
      'field_gender' => 'left',
      'title' => 'hidden',
      'field_firstname' => 'left',
      'path' => 'hidden',
      'field_lastname' => 'left',
      'field_activity_origin' => 'left',
      'field_target_audience' => 'left',
      'field_contact_tags' => 'left',
      'field_birthday' => 'left',
      'field_languages' => 'left',
      'field_vat_number' => 'left',
      'field_customer_category' => 'left',
    ),
    'classes' => array(),
  );
  $export['node|erpal_contact|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'relation|works_at|relation_with_endpoints';
  $ds_layout->entity_type = 'relation';
  $ds_layout->bundle = 'works_at';
  $ds_layout->view_mode = 'relation_with_endpoints';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'endpoints',
        1 => 'field_date',
        2 => 'field_work_at_rel_tags',
      ),
    ),
    'fields' => array(
      'endpoints' => 'ds_content',
      'field_date' => 'ds_content',
      'field_work_at_rel_tags' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['relation|works_at|relation_with_endpoints'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function erpal_basic_ui_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'in_pane';
  $ds_view_mode->label = 'in-pane';
  $ds_view_mode->entities = array(
    'field_collection_item' => 'field_collection_item',
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['in_pane'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'minimal';
  $ds_view_mode->label = 'minimal';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['minimal'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'relation_with_endpoints';
  $ds_view_mode->label = 'relation with endpoints';
  $ds_view_mode->entities = array(
    'relation' => 'relation',
  );
  $export['relation_with_endpoints'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'visual';
  $ds_view_mode->label = 'visual';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['visual'] = $ds_view_mode;

  return $export;
}
