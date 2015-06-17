<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Project time information'),
  'description' => t('Shows time information of tasks and projects and their children'),
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
function erpal_projects_helper_project_time_info_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $node = $context->data;
  
  if ($node->type != 'erpal_project' && $node->type != 'erpal_task') {
    return;
  }

  $time_information = _erpal_projects_helper_time_information($node);

  //now put all timeinformation into HTML output
  $html = '';
  if ($node->type == 'erpal_task') {
    //local timeinformation
    $class = 'local_time_information';
    if ($time_information['local']['estimated'] < $time_information['local']['timetracking'])
      $class .= ' alert';
      
    $html .= "<div class='$class'>
      <div class='label_this_task'>".t('This task')."</div>
      <div class='time_details'>".$time_information['local']['timetracking']."/".$time_information['local']['estimated']." (".t('h').")</div>
      <div class='time_details_todo'>".t('to do').": ".$time_information['local']['estimated_left']." ".t('h')."</div></div>";
      
    //Children time information
    $class = 'children_time_information';
    if ($time_information['children']['estimated'] < $time_information['children']['timetracking'])
      $class .= ' alert';
      
    $html .= "<div class='$class'>
      <div class='label_subtasks'>".t('Subtasks')."</div>
      <div class='time_details'>".$time_information['children']['timetracking']."/".$time_information['children']['estimated']." (".t('h').")</div>
      <div class='time_details_todo'>".t('to do').": ".$time_information['children']['estimated_left']." ".t('h')."</div></div>";

  }
  elseif ($node->type == 'erpal_project') {
    $class = 'time_information';
    if ($time_information['local']['estimated'] < $time_information['children']['timetracking'])
      $class .= ' alert';
      
    $html .= "<div class='$class'>
      <h3>".t('This Project')."</h3>
      <div>".t('Project estimation').": ".t('!time h', array('!time' => $time_information['local']['estimated']))."</div>
      <div>".t('Subtasks estimated time').": ".t('!time h', array('!time' => $time_information['children']['estimated']))."</div>
      <div>".t('Subtasks consumed time').": ".t('!time h', array('!time' => $time_information['children']['timetracking']))."</div>
      <div>".t('Subtasks estimated time left').": ".t('!time h', array('!time' => $time_information['children']['estimated_left']))."</div></div>";
  }
  
  $block = new stdClass();
  $block->module = 'erpal_projects_helper';
  $block->title = '';
  $block->content = '<div class="field_time_information">'.$html.'</div>';
  return $block;
}

