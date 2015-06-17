<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Custom node content'),
  'description' => t('Provide custom modules to add custom content to node views, when this pane is added'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'no title override' => TRUE,
  'defaults' => array('admin_title' => '', 'title' => ''),
  'category' => t('ERPAL'),
  //'edit form' => '_erpal_basic_helper_custom_node_content_edit',  //@TODO add config form for edition the title of the block
  'edit text' => t('Edit'),
  'add form' => '',  
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);


/**
 * Render callback.
 */
function erpal_basic_helper_custom_node_content_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = $context->data;
  
  $module = 'erpal_basic_helper';
  $block = new stdClass();
  $block->module = $module;

  $block->title = ''; //@TODO take title from edit form
  $block->content = _erpal_basic_helper_custom_content_block_content($node);
  return $block;
}

/**
* Returns content for the custom content block. Asks other modules using a hook to add some content
*/
function _erpal_basic_helper_custom_content_block_content($node) {
  $renderable = module_invoke_all('custom_node_content_block_content', $node);

  //now give other modules the chance to alter
  drupal_alter('custom_node_content_block_content', $node, $renderable);
  
  return drupal_render($renderable);
}

