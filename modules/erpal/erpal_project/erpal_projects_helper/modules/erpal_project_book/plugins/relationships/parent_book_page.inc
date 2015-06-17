<?php

/**
 * @file
 * Plugin to provide an relationship handler to between the current node and the next parent book page.
 * @see this is similar to book_parent plugin in ctools module
 */

$plugin = array(
  'title' => t('First book page parent'),
  'description' => t('Creates an entity context from a nodes parent field to a parent book page'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'context' => 'erpal_project_book_ctools_relationships_prarent_book_page_context',
  'defaults' => array('delta' => 0),
);


/**
 * Return a new context based on an existing context.
 */
function erpal_project_book_ctools_relationships_prarent_book_page_context($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data)) {
    return ctools_context_create_empty('node');
  }
  
  //get the first parent book page if there is none, return false
  $context_node = $context->data;
  $node = _erpal_project_book_get_parent_book_page($context_node);
  return ctools_context_create('node', $node);
}
