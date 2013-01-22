<?php
/**
 * @file
 * feature_erpal_asterisk_profile.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function feature_erpal_asterisk_profile_default_profile2_type() {
  $items = array();
  $items['asterisk_settings'] = entity_import('profile2_type', '{
    "userCategory" : false,
    "userView" : false,
    "type" : "asterisk_settings",
    "label" : "Asterisk settings",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 }
  }');
  return $items;
}
