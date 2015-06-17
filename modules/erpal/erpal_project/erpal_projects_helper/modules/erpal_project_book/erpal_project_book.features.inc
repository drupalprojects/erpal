<?php
/**
 * @file
 * erpal_project_book.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_project_book_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_page_manager_handlers_alter().
 */
function erpal_project_book_default_page_manager_handlers_alter(&$data) {
  if (isset($data['node_view_panel_context'])) {
    $data['node_view_panel_context']->conf['display']->content['new-ae41615e-59fd-1a54-8103-f22606b76458'] = (object) array(
          'pid' => 'new-ae41615e-59fd-1a54-8103-f22606b76458',
          'panel' => 'sidebar_second_right',
          'type' => 'entity_field',
          'subtype' => 'node:field_books_ref',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'label' => 'title',
            'formatter' => 'entityreference_label',
            'delta_limit' => 0,
            'delta_offset' => 0,
            'delta_reversed' => 0,
            'formatter_settings' => array(
              'link' => 1,
            ),
            'context' => 'argument_entity_id:node_1',
            'override_title' => 0,
            'override_title_text' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 5,
          'locks' => array(),
          'uuid' => 'ae41615e-59fd-1a54-8103-f22606b76458',
        ); /* WAS: '' */
        
    //$data['node_view_panel_context']->conf['display']->content['new-b132471b-bdeb-f304-c9b0-6caaf01a6bfd']->position = 4; /* WAS: 5 */
    $data['node_view_panel_context']->conf['display']->panels['sidebar_second_right']['5'] = 'new-ae41615e-59fd-1a54-8103-f22606b76458'; /* WAS: '' */
  }
}

/**
 * Implements hook_default_panels_mini_alter().
 */
function erpal_project_book_default_panels_mini_alter(&$data) {
  if (isset($data['book_general_fields'])) {
    $data['book_general_fields']->display->content['new-9388788c-d8a6-bc84-617e-b1ca65c31ec5'] = (object) array(
          'pid' => 'new-9388788c-d8a6-bc84-617e-b1ca65c31ec5',
          'panel' => 'middle',
          'type' => 'book_usage',
          'subtype' => 'book_usage',
          'shown' => TRUE,
          'access' => array(),
          'configuration' => array(
            'types' => array(),
            'field_name' => '',
          ),
          'cache' => array(),
          'style' => array(
            'settings' => NULL,
          ),
          'css' => array(),
          'extras' => array(),
          'position' => 6,
          'locks' => array(),
          'uuid' => '9388788c-d8a6-bc84-617e-b1ca65c31ec5',
        ); /* WAS: '' */
    $data['book_general_fields']->display->panels['middle']['6'] = 'new-9388788c-d8a6-bc84-617e-b1ca65c31ec5'; /* WAS: '' */
  }
}
