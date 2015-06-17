<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('ERPAL forecast node details view'),
  'description' => t('Shows the details of one selected forecast data'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('ERPAL Reports'),
  'defaults' => array(
    'types' => array(),
    'field_name' => '',
  ),
);

/**
 * Render callback.
 */
function erpal_crm_reports_node_forecast_details_view_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }

  $forecast_node = $context->data;

  if (!$forecast_node) {
    return;
  }

 
  //then get the corresponding view to show the data for every forecast field collection
  if ($forecast_node->type == 'erpal_expense_forecast')
    $embed_view = _erpal_crm_reports_get_expense_plan_embed_details_view($forecast_node);
  if ($forecast_node->type == 'erpal_customer_forecast')
    $embed_view = _erpal_crm_reports_get_customer_plan_embed_details_view($forecast_node);
  
  $block = new stdClass();
  $block->module = 'erpal_reports';
  //$block->title = t('Report details');
  $block->content = $embed_view;
  return $block;
}

/**
* Returns the loaded view that will show the details for a drill down of a report. The view is selected by the clicked part of the chart
*/ 
function _erpal_crm_reports_get_expense_plan_embed_details_view($forecast_node) {  
  
  $forecast_node_w = entity_metadata_wrapper('node', $forecast_node);
  $expense_elements = $forecast_node_w->field_expense_elements->value();
  
  $html = '';
  foreach($expense_elements as $expense_element) {   
    $expense_element_w = entity_metadata_wrapper('field_collection_item', $expense_element);
    
    $details = json_decode($expense_element_w->field_report_details->value());

    if (is_array($details)) {
      foreach ($details as $delta => $detail) {
        $html .= _erpal_reports_render_details($detail);
      }
    }
  }
 
  return $html;
}

/**
* Returns the loaded view that will show the details for a drill down of a report. The view is selected by the clicked part of the chart
*/ 
function _erpal_crm_reports_get_customer_plan_embed_details_view($forecast_node) {  
  
  $forecast_node_w = entity_metadata_wrapper('node', $forecast_node);
  $forecast_elements = $forecast_node_w->field_forecast_elements->value();
  
  $html = '';
  foreach($forecast_elements as $forecast_element) {   
    $forecast_element_w = entity_metadata_wrapper('field_collection_item', $forecast_element);
    
    $details = json_decode($forecast_element_w->field_report_details->value());

    if (is_array($details)) {
      foreach ($details as $delta => $detail) {
        $html .= _erpal_reports_render_details($detail);
      }
    }
  }
 
  return $html;
}