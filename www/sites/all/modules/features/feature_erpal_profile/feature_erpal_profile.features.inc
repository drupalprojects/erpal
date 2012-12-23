<?php
/**
 * @file
 * feature_erpal_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_profile_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_profile2_type().
 */
function feature_erpal_profile_default_profile2_type() {
  $items = array();
  $items['asterisk_settings'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "asterisk_settings",
    "label" : "Asterisk settings",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 }
  }');
  $items['contract'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "contract",
    "label" : "Contract",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 0 }
  }');
  $items['main'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "main",
    "label" : "Main profile",
    "weight" : "0",
    "data" : { "registration" : 1, "use_page" : 0 }
  }');
  return $items;
}
