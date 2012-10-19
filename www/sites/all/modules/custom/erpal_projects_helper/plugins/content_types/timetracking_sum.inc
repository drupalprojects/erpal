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

  //if estimation is set and summed time is higher than estimation mark the div but only for tasks
  $class_string = 'time_ok';
  if ($node->type == 'erpal_task') {
    $estimated_time = isset($node->field_estimated_time[LANGUAGE_NONE][0]['value']) && $node->field_estimated_time[LANGUAGE_NONE][0]['value'] ? $node->field_estimated_time[LANGUAGE_NONE][0]['value'] : false;
    
    if ($estimated_time) {
      if ($summed_time > $estimated_time)
        $class_string = 'to_much_time';
    }
  }
  
  $module = 'erpal_projects_helper';
  $block = new stdClass();
  $block->module = $module;
  $block->title = t('Consumed time');
  $block->content = '<div class="'.$class_string.'">'.$summed_time." h".'</div>';
  return $block;
}

