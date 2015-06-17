<?php
/**
 * @file
 * erpal_crm_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_crm_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-contact-menu_show-all-activities:activities
  $menu_links['menu-contact-menu_show-all-activities:activities'] = array(
    'menu_name' => 'menu-contact-menu',
    'link_path' => 'activities',
    'router_path' => 'activities',
    'link_title' => 'Show all Activities',
    'options' => array(
      'alter' => TRUE,
      'menu_token_link_path' => 'activities?title_1=[node:title]',
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
      'query' => array(
        'field_customer_ref_target_id%5B%5D' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => 'activities',
        'style' => '',
      ),
      'identifier' => 'menu-contact-menu_show-all-activities:activities',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
  );
  // Exported menu link: menu-erpal-menu_activities:activities
  $menu_links['menu-erpal-menu_activities:activities'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'activities',
    'router_path' => 'activities',
    'link_title' => 'Activities',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_activities',
        'class' => 'activities',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_activities:activities',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Activities');
  t('Show all Activities');


  return $menu_links;
}
