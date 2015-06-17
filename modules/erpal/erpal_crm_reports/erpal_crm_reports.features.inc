<?php
/**
 * @file
 * erpal_crm_reports.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_crm_reports_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cat" && $api == "cat") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_crm_reports_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_erpal_reports_type().
 */
function erpal_crm_reports_default_erpal_reports_type() {
  $items = array();
  $items['erpal_crm_customer_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_crm_customer_reports",
    "name" : "Erpal CRM Customer Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  $items['erpal_crm_expense_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_crm_expense_reports",
    "name" : "Erpal CRM Expense Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  $items['erpal_crm_lead_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_crm_lead_reports",
    "name" : "Erpal CRM Lead Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  $items['erpal_crm_sales_forecast_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_crm_sales_forecast_reports",
    "name" : "Erpal CRM Sales Forecast Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  $items['erpal_crm_sales_reports'] = entity_import('erpal_reports_type', '{
    "type" : "erpal_crm_sales_reports",
    "name" : "Erpal CRM Sales Reports",
    "weight" : "0",
    "locked" : "0",
    "data" : null
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function erpal_crm_reports_node_info() {
  $items = array(
    'erpal_customer_forecast' => array(
      'name' => t('Customer Forecast'),
      'base' => 'node_content',
      'description' => t('Forecasts for a customer'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'erpal_expense_forecast' => array(
      'name' => t('Expense forecast'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
