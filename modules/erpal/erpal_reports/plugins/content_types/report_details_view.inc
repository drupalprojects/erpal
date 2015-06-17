<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('ERPAL Report details view'),
  'description' => t('Shows the details of one selected report data'),
  'required context' => new ctools_context_required(t('ERPAL Reports'), 'erpal_reports'),
  'category' => t('ERPAL Reports'),
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);

/**
 * Render callback.
 */
function erpal_reports_report_details_view_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $report = $context->data;

  if (!$report) {
    return;
  }

  //first determine what should be shown (which collected data)
  $x_axis = !empty($args[1][1]) ? $args[1][1] : false;
  $z_axis = !empty($args[1][2]) ? $args[1][2] : false;
  
  if (!$x_axis || !$z_axis) {
    return false;
  }
  
  //then get the corresponding view to show the data
  $embed_view = _erpal_reports_get_embed_details_view($report->id, $x_axis, $z_axis);
  
  
  $block = new stdClass();
  $block->module = 'erpal_reports';
  //$block->title = t('Report details');
  $block->content = $embed_view;
  return $block;
}

/**
* Returns the loaded view that will show the details for a drill down of a report. The view is selected by the clicked part of the chart
*/ 
function _erpal_reports_get_embed_details_view($report_id, $x_axis, $z_axis) {  
  $details = _erpal_reports_load_details($report_id, $x_axis, $z_axis);

  $html = _erpal_reports_render_details($details);
  return $html;
}