<?php
/**
 * @file
 * erpal_contract_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_contract_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-contact-menu_show-all-contracts:contracts
  $menu_links['menu-contact-menu_show-all-contracts:contracts'] = array(
    'menu_name' => 'menu-contact-menu',
    'link_path' => 'contracts',
    'router_path' => 'contracts',
    'link_title' => 'Show all Contracts',
    'options' => array(
      'menu_token_link_path' => 'contracts?title_1=[node:title]',
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
      'alter' => TRUE,
      'query' => array(
        'field_customer_ref_target_id%5B%5D' => '',
      ),
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => 'contract',
        'style' => '',
      ),
      'identifier' => 'menu-contact-menu_show-all-contracts:contracts',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 0,
  );
  // Exported menu link: menu-erpal-menu_contracts:contracts
  $menu_links['menu-erpal-menu_contracts:contracts'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'contracts',
    'router_path' => 'contracts',
    'link_title' => 'Contracts',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_contracts',
        'class' => 'contracts',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_contracts:contracts',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contracts');
  t('Show all Contracts');


  return $menu_links;
}
