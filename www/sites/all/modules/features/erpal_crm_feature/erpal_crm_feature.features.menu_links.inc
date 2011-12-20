<?php
/**
 * @file
 * erpal_crm_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_crm_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:crm/contacts
  $menu_links['main-menu:crm/contacts'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'crm/contacts',
    'router_path' => 'crm/contacts',
    'link_title' => 'CRM',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CRM');


  return $menu_links;
}
