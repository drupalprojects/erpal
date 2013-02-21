<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Node referencing budget'),
  'description' => t('Shows the task or project where a budget is referenced'),
  'required context' => new ctools_context_required(t('Budget'), 'budget'),
  'category' => t('ERPAL projects'),
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);

/**
 * Render callback.
 */
function erpal_projects_helper_budget_node_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $budget = $context->data;
  $node = _erpal_projects_helper_get_node_by_budget($budget->budget_id);

  if (!$node) {
    return;
  }

  $block = new stdClass();
  $block->module = 'erpal_projects_helper';
  $block->title = t('Referecing node');
  $block->content = '<div class="budget_referencing_node">'.l($node->title, 'node/'.$node->nid).'</div>';
  return $block;
}

