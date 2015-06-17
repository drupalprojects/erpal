<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Book project usage'),
  'description' => t('Shows which projects us the book as specification'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('ERPAL projects'),
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);

/**
 * Render callback.
 */
function erpal_project_book_book_usage_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = $context->data;

  if (!$node) {
    return;
  }
  
  $rendered_content = _erpal_project_book_render_projects_referencing_books($node->nid);

  $block = new stdClass();
  $block->module = 'erpal_projects_helper';
  $block->title = t('Projects');
  $block->content = $rendered_content;
  return $block;
}

