<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Task customer'),
  'description' => t('Shows the customer of a task'),
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
function erpal_projects_helper_task_customer_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = $context->data;
  
  if (!$node->nid || $node->type != 'erpal_task')
    return '';
    
  $project_nid = isset($node->field_project_ref[LANGUAGE_NONE][0]['target_id']) ? $node->field_project_ref[LANGUAGE_NONE][0]['target_id'] : false;
  
  if (!$project_nid)
    return;
    
  $project_node = node_load($project_nid);
  $customer_nid = $project_node->field_customer_ref[LANGUAGE_NONE][0]['target_id'];
  $customer_node = node_load($customer_nid);
  
  $customer_link = l($customer_node->title, 'node/'.$customer_node->nid);
  
  $module = 'erpal_projects_helper';
  $block = new stdClass();
  $block->module = $module;
  $block->title = t('Customer');
  $block->content = '<div class="field_customer">'.$customer_link.'</div>';
  return $block;
}

