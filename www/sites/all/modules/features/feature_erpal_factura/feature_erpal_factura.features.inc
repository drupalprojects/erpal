<?php
/**
 * @file
 * feature_erpal_factura.features.inc
 */

/**
 * Implements hook_views_api().
 */
function feature_erpal_factura_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
