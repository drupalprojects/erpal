<?php
/**
 * @file
 * erpal_calendar_crm.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function erpal_calendar_crm_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field_instance
  $overrides["field_instance.node-erpal_crm_activity-field_expected_date.date_item"] = array(
    'create_date_item' => 0,
    'date_item_type' => 'simple_date',
    'handle_range' => 'range',
  );
  $overrides["field_instance.node-erpal_crm_activity-field_next_contact.date_item"] = array(
    'create_date_item' => 1,
    'date_item_type' => 'simple_date',
    'handle_range' => 'range',
  );

 return $overrides;
}
