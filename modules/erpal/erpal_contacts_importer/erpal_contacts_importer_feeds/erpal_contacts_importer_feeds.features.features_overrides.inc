<?php
/**
 * @file
 * erpal_contacts_importer_feeds.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function erpal_contacts_importer_feeds_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: cat_items
  $overrides["cat_items.erpal_contacts.data|cat_tabs|1"] = array(
    'path' => 'import/erpal-contacts-import',
    'path_router' => 'import/erpal-contacts-import',
    'path_original' => 'import/erpal-contacts-import',
    'path_pattern' => 'import/%',
    'path_query' => array(),
    'path_destination' => FALSE,
    'title' => 'Contacts importer',
    'css_id' => '',
    'css_class' => '',
    'active' => FALSE,
    'reusable' => FALSE,
    'machine_name' => '',
    'reusabled' => FALSE,
    'reusabled_machine_name' => NULL,
  );

 return $overrides;
}
