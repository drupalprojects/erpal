<?php
/**
 * @file
 * feature_erpal_layout.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_erpal_layout_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_page_manager_handlers';
  $strongarm->value = array();
  $export['default_page_manager_handlers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_everywhere_site_template_enabled';
  $strongarm->value = TRUE;
  $export['panels_everywhere_site_template_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_page_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:11:"panels_page";s:23:"allowed_layout_settings";a:10:{s:8:"flexible";b:1;s:14:"twocol_stacked";b:1;s:13:"twocol_bricks";b:1;s:6:"twocol";b:1;s:25:"threecol_33_34_33_stacked";b:1;s:17:"threecol_33_34_33";b:1;s:25:"threecol_25_50_25_stacked";b:1;s:17:"threecol_25_50_25";b:1;s:6:"onecol";b:1;s:12:"erpal_layout";b:1;}s:10:"form_state";N;}';
  $export['panels_page_allowed_layouts'] = $strongarm;

  return $export;
}
