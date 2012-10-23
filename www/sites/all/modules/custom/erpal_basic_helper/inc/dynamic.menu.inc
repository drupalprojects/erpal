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
    
  $item['localized_options']['query'] += drupal_get_destination();
  if (array_key_exists('access', $item) && $item['access']) {
    $data['actions']['output'][] = array(
      '#theme' => 'menu_local_action',
      '#link' => $item,
    );
  }
}