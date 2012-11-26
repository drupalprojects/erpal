<?php
/**
* @file provides all functions to have dynamic local actions on pages
*/

/**
* Checks, if a current page has a certain context
*/
function _erpal_basic_helper_has_context($context, $router_item = false) {
  $contexts = _erpal_basic_helper_get_contexts($router_item);
  
  return isset($contexts[$context]) && $contexts[$context];
}

/**
* Alters the menu local tasks output to have ul tag arround
*/
function _erpal_basic_helper_alter_local_tasks_output(&$data) {
  $links = $data['actions']['output'];
  unset($data['actions']['output']);
  $data['actions']['output']['container'] = array(
    '#prefix' => '<ul class="local_tasks">',
    '#suffix' => '</ul>',
  );
  
  foreach ($links as $link) {
    $data['actions']['output']['container'][] = $link;
  }
}

/**
* Implements hook_menu_local_tasks_alter()
*/
function erpal_basic_helper_menu_local_tasks_alter(&$data, $router_item, $root_path) {  
  
  //allow other modules to add dynamic menu items
  drupal_alter('dynamic_menu_items', $data, $router_item, $root_path);  
  
  //allways remove the node/%/edit link from local tasks
  foreach ($data['tabs'] as $delta=>$output) {
    foreach ($output['output'] as $inner_delta=>$a_output) {
      $path = $a_output['#link']['path'];
      if ($path == 'node/%/edit') {
        unset($data['tabs'][$delta]['output'][$inner_delta]);
      }
      
      //and if this is the view button, rename it
      if ($path == 'node/%/view') {
        $data['tabs'][$delta]['output'][$inner_delta]['#link']['title'] = t('Summary');
      }
    }
  }
  
  //finally at the end...
  _erpal_basic_helper_alter_local_tasks_output($data); //to correct markup
}

/**
* Module determines the context(s) of the current page
*/
function _erpal_basic_helper_get_contexts($router_item = false) {
  $my_contexts = array();
  
  if (!$router_item) {
    //get a router item
    $router_item = menu_get_item();
  }

  $other_contexts = module_invoke_all('erpal_contexts', $router_item);
  
  return array_merge($my_contexts, $other_contexts);
}

/**
* Returns a local action item to path if user has access
*/
function erpal_make_action(&$data, $title, $path, $query = array()) {
  
  $item = erpal_make_local_link($data, $title, $path, $query);
  
  if (array_key_exists('access', $item) && $item['access']) {
  
    $data['actions']['output'][] = array(
      '#theme' => 'menu_local_action',
      '#link' => $item,
    );
  }
}

/**
* Returns a local action item to path if user has access
*/
function erpal_make_local_tab(&$data, $title, $path, $query = array(), $active=false) {
  
  $item = erpal_make_local_link($data, $title, $path, $query);
 
  if (array_key_exists('access', $item) && $item['access']) {
    //may be make active
    
    if ($active) {
      $item['localized_options']['attributes']['class'][] = 'active-trail';
      $item['localized_options']['attributes']['class'][] = 'active';      
    }
    
    $data['tabs'][0]['output'][] = array(
      '#theme' => 'menu_local_task',
      '#link' => $item,
      '#active' => $active,
    );
    $data['tabs'][0]['count'] = count($data['tabs'][0]['output']);
  }
}

/**
* sets a current menu item active
* Called by @see erpal_basic_helper_preprocess_menu_link
*/
function erpal_set_menu_item_active(&$menu_item) {
  static $current_menu_item_cache = false;
  
  if ($current_menu_item_cache)
    $current_menu_item = $current_menu_item_cache;
  else {
    $current_menu_item = menu_get_item();
    //now cache it
    $current_menu_item_cache = $current_menu_item;
  }
 
  $menu_parent_path = erpal_get_menu_parents($current_menu_item);

  if (in_array($menu_item['element']['#href'], $menu_parent_path)) {
    //its a menu item that should be set active    
    $menu_item['element']['#attributes']['class'][] = 'active-trail';
    $menu_item['element']['#attributes']['class'][] = 'active';
    
  }
}

/**
* Returns the menu parent of a path
*/
function erpal_get_menu_parents($router_item) {
  $parents = module_invoke_all('erpal_menu_parents', $router_item);
  return $parents;
}

/**
* Basic processing for local menu links, should not be called directely by other modules
*/
function erpal_make_local_link(&$data, $title, $path, $query = array()) {
  $item = menu_get_item($path);
  $item['title'] = $title;
  // The add new content page would redirect to the new event
  // if we did not override that here. This way they will
  // redirect back to the calendar.
  if (!isset($item['localized_options']) || !$item['localized_options'])
    $item['localized_options'] = array();
    
  $item['localized_options'] += array('query' => array());
  if (count($query))
    $item['localized_options']['query'] += $query;
  
  return $item;
}