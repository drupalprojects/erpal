<?php
/**
 * @file
 * erpal_project_ui.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_project_ui_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "cat" && $api == "cat") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "pm_existing_pages" && $api == "pm_existing_pages") {
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
function erpal_project_ui_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function erpal_project_ui_image_default_styles() {
  $styles = array();

  // Exported image style: icon16x16.
  $styles['icon16x16'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 16,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'icon16x16',
  );

  return $styles;
}
