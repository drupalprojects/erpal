<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Summed timetracking'),
  'description' => t('Shows the sum of timetrackings to a node'),
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
function erpal_projects_helper_timetracking_sum_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = $context->data;
  $summed_time = erpal_projects_helper_summed_timetracking($node);
  if (!$summed_time) {
    return;
  }

  $module = 'erpal_projects_helper';
  $block = new stdClass();
  $block->module = $module;
  $block->title = t('Consumed time');
  $block->content = $summed_time." h";
  return $block;
}

