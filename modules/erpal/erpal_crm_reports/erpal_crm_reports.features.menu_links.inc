<?php
/**
 * @file
 * erpal_crm_reports.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_crm_reports_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-contact-menu_show-all-forecasts:reports/crm
  $menu_links['menu-contact-menu_show-all-forecasts:reports/crm'] = array(
    'menu_name' => 'menu-contact-menu',
    'link_path' => 'reports/crm',
    'router_path' => 'reports/%',
    'link_title' => 'Show all Forecasts',
    'options' => array(
      'menu_token_link_path' => 'reports/crm?title=[node:title]&qt-crm_report_tabs=5',
      'menu_token_data' => array(
        'node' => array(
          'type' => 'node',
          'plugin' => 'node_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 1,
      ),
      'alter' => TRUE,
      'identifier' => 'menu-contact-menu_show-all-forecasts:reports/crm',
      'query' => array(
        'title' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => 'forecast',
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Show all Forecasts');


  return $menu_links;
}
