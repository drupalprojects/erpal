<?php
/**
 * @file
 * erpal_project_book.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function erpal_project_book_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: page_manager_handlers
  $overrides["page_manager_handlers.node_view_panel_context.conf|display|content|new-ae41615e-59fd-1a54-8103-f22606b76458"] = (object) array(
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
    );
  //$overrides["page_manager_handlers.node_view_panel_context.conf|display|content|new-b132471b-bdeb-f304-c9b0-6caaf01a6bfd|position"] = 4;
  $overrides["page_manager_handlers.node_view_panel_context.conf|display|panels|sidebar_second_right|5"] = 'new-ae41615e-59fd-1a54-8103-f22606b76458';

  // Exported overrides for: panels_mini
  $overrides["panels_mini.book_general_fields.display|content|new-9388788c-d8a6-bc84-617e-b1ca65c31ec5"] = (object) array(
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
    );
  $overrides["panels_mini.book_general_fields.display|panels|middle|6"] = 'new-9388788c-d8a6-bc84-617e-b1ca65c31ec5';

  // Exported overrides for: views_view
  $overrides["views_view.book_children.display|panel_pane_2|display_options|filters|type|value|erpal_task"] = 'erpal_task';

 return $overrides;
}
