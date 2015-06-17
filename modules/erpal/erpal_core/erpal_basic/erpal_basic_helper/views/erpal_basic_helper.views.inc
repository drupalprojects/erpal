<?php

/**
 * @file
 * Adds custom handler for views filter for all entityreference fields that have
 * 'erpal_contact' in target bundles
 */

/**
 * Implements hook_views_data_alter().
 */
function erpal_basic_helper_views_data_alter(&$data) {
  
  // Loop all field filters.
  foreach ($data as $data_key => $data_field) {
    if (strpos($data_key, 'field_data_') !== FALSE) {
      // Get field name
      $field_name = str_replace('field_data_', '', $data_key);
      
      // Check if field filter is entity reference 
      if (isset($data_field[$field_name . '_target_id']['filter']['handler'])) {
        if ($data_field[$field_name . '_target_id']['filter']['handler'] == 'views_handler_filter_in_operator') {
          
          // Get field information
          $field_info = field_info_field($field_name);

          // Get entityreference target bundles of field
          if (isset($field_info['settings']['handler_settings']['target_bundles'])) {
            $target_bundles = $field_info['settings']['handler_settings']['target_bundles'];
            
            // Check if 'erpal_contact' is in target bundles
            if (in_array('erpal_contact', $target_bundles)) {
              
              // Name of custom handler class
              $custom = 'erpal_basic_helper_own_company_filter_handler';
              // Add custom handler
              $data[$data_key][$field_name . '_target_id']['filter']['handler'] = $custom;
            }
          }
        }
      }
    }
  }
}
