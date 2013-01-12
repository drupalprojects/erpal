<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Project time estimation summed'),
  'description' => t('Shows estimated time of a project (sum of all tasks)'),
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
function erpal_projects_helper_project_time_estimation_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = $context->data;
  
  if ($node->type != 'erpal_project') {
    return;
  }
  
  $summed_estimation = _erpal_projects_helper_summed_project_estimation($node);
  
  $module = 'erpal_projects_helper';
  $block = new stdClass();
  $block->module = $module;
  $block->title = t('Estimated time');
  $block->content = '<div class="field_time_estimation_sumed">'.number_format($summed_estimation, 2).'</div>';
  return $block;
}

