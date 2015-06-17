<?php
/**
 * @file
 * erpal_project_ui.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function erpal_project_ui_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-contact-menu_show-all-projects:projects/projects
  $menu_links['menu-contact-menu_show-all-projects:projects/projects'] = array(
    'menu_name' => 'menu-contact-menu',
    'link_path' => 'projects/projects',
    'router_path' => 'projects/projects',
    'link_title' => 'Show all Projects',
    'options' => array(
      'menu_token_link_path' => 'projects/projects?title_1=[node:title]',
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
        'class' => 'projects',
        'style' => '',
      ),
      'identifier' => 'menu-contact-menu_show-all-projects:projects/projects',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 0,
  );
  // Exported menu link: menu-erpal-menu_projects:projects/projects
  $menu_links['menu-erpal-menu_projects:projects/projects'] = array(
    'menu_name' => 'menu-erpal-menu',
    'link_path' => 'projects/projects',
    'router_path' => 'projects/projects',
    'link_title' => 'Projects',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'erpal_menu_projects',
        'class' => 'projects',
        'style' => '',
      ),
      'identifier' => 'menu-erpal-menu_projects:projects/projects',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 0,
  );
  // Exported menu link: user-menu_my-projects:user/projects
  $menu_links['user-menu_my-projects:user/projects'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/projects',
    'router_path' => 'user/projects',
    'link_title' => 'My projects',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'user_menu_my_projects',
        'class' => 'my-projects',
        'style' => '',
      ),
      'identifier' => 'user-menu_my-projects:user/projects',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 0,
  );
  // Exported menu link: user-menu_my-tasks:user/tasks
  $menu_links['user-menu_my-tasks:user/tasks'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/tasks',
    'router_path' => 'user/tasks',
    'link_title' => 'My tasks',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => 'user_menu_my_tasks',
        'class' => 'my-tasks',
        'style' => '',
      ),
      'identifier' => 'user-menu_my-tasks:user/tasks',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('My projects');
  t('My tasks');
  t('Projects');
  t('Show all Projects');


  return $menu_links;
}
