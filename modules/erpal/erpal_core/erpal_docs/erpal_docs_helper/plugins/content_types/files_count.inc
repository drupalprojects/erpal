<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Asset files count'),
  'description' => t('Shows the number of attached files to a node'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('ERPAL docs'),
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);

/**
 * Render callback.
 */
function erpal_docs_helper_files_count_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = $context->data;

  if (isset($node->field_asset_files)) {
    $files_count = 0;
    if (isset($node->field_asset_files[LANGUAGE_NONE]))
      $files_count = count($node->field_asset_files[LANGUAGE_NONE]);
    $module = 'erpal_docs_helper';
    $block = new stdClass();
    $block->module = $module;
    $block->title = t('Files');
    $block->content = '<div class="field_files_count">'.$files_count.' '.t('files').'</div>';
    return $block;
  } else
    return;
}

