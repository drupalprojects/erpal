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
  
  //add a container for colapsible elements if there are more than 3 items
  if (count($links) > 3) {
    $data['actions']['output']['container'] = array(
      '#prefix' => '<div class="local_tasks_menu"><ul class="local_tasks"><li><a href="#">Actions</a><ul>',
      '#suffix' => '</ul></li></ul></div>',
    );
  } else {
    $data['actions']['output']['container'] = array(
      '#prefix' => '<div class="local_tasks_menu_no_popup"><ul class="local_tasks">',
      '#suffix' => '</ul></div>',
    );
  }
  
  foreach ($links as $link) {
    $data['actions']['output']['container'][] = $link;
  }
  
  //if there is no tab, add a tab so the navigation will be shown
  if (!count($data['tabs'])) {
    erpal_make_local_tab($data, t('Home'), 'dashboard', array(), false);
  }
    
  
  if (isset($data['tabs'][0]['count']) && $data['tabs'][0]['count'] == 1) {
    $data['tabs'][0]['count'] = 2;  //we do this so single menu tabs will be shown, otherwise they wont display if there is only 1 item
  }
 
  
  //add javascript to show local tasks as popup!
  $mod_path = drupal_get_path('module', 'erpal_basic_helper');
  $js_path = $mod_path.'/js/local_tasks.js';
  drupal_add_js($js_path);
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
      
      //and if this is the view button remove it
      if ($path == 'node/%/view') {
        unset($data['tabs'][$delta]['output'][$inner_delta]);
      }
      
      //and if this is the revision button remove it
      if ($path == 'node/%/revisions') {
        unset($data['tabs'][$delta]['output'][$inner_delta]);
      }
    }
  }
  
  //finally at the end...
  _erpal_basic_helper_alter_local_tasks_output($data); //to correct markup
}


/**
* Return the object of an argument (direct entity or ctools context) at the given $position
*/ 
function _erpal_basic_helper_router_object($position, $router_item) {
  $entity = isset($router_item['map'][$position]) && is_object($router_item['map'][$position]) ? $router_item['map'][$position] : false;
    
  //may be we have a ctools context    
  if (is_object($entity) && get_class($entity) == 'ctools_context')
    $entity = $entity->data;
    
  return $entity;
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
function erpal_make_local_tab(&$data, $title, $path, $query = array(), $active=false, $options=array()) {
  $item = erpal_make_local_link($data, $title, $path, $query);

  if (array_key_exists('access', $item) && $item['access']) {
    
    if (count($options)) {
      $class = isset($options['class']) ? $options['class'] : array();
      $item['localized_options']['attributes']['class'] = $class;
    }
    
    if ($item['href'] == $_GET['q'])
      $active = true;
    
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

  if (in_array($menu_item['#href'], $menu_parent_path)) {
    //its a menu item that should be set active    
    $menu_item['#attributes']['class'][] = 'active-trail';
    $menu_item['#attributes']['class'][] = 'active';
    $menu_item['#active'] = true;
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
  $item = menu_get_item($path, NULL, true);

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


//###############################################################################
/**
* Functions mostly copied from menu_css_names module but we need more flexibility
*/
//###############################################################################

/**
 * This is the modified version of the default theme_links() function (this
 * is the function that is used to theme Primary and Secondary links).
 * Extra code has been added which puts the name of the link into the <li> 
 * element's class name.
 */

function erpal_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading. 
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);
			
			// new menu_css_names code starts here
		  //
		  // add a class that is equal to the title of the menu link,
		  // replacing special characters with dashes.
		  if (!empty($link['title'])) {
		    $class[] = erpal_make_class_name($link['title']);
			}
			// end of menu_css_names code
			
      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
           && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}


/**
 * This is the modified version of the default theme_menu_link() function
 *
 **/
function erpal_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  
  // new menu_css_names code starts here
  //
  // add a class that is equal to the title of the menu link,
  // replacing special characters with dashes.
  if (!empty($element['title'])) {
    $element['#attributes']['class'][] = erpal_make_class_name($element['title']);
	}
  
	// end of menu_css_names code
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li ' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * This is the modified version of the default theme_menu_tree() function
 *
 * Note that this function wasn't overrided in the D6 version of this module.
 *
 **/
function erpal_menu_tree($variables) {
	$menu = $variables['tree'];
	$menu = preg_replace('/(<li\s+class="[^"]+)("><a\s+[^>]+>)(.+?)(<\/a>)/e', "'\\1 ' . erpal_make_class_name('\\3') . '\\2\\3\\4'", $menu);
	
  return '<ul class="menu">' . stripslashes($menu) . '</ul>';
}


/**
 * This is the modified version of the default theme_menu_local_task() function
 *
 **/
function erpal_menu_local_task($variables) {
  $link = $variables['element']['#link'];
  $link_text = $link['title'];

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link['localized_options']['html'] = TRUE;
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
  }
	// new menu_css_names code starts here
  $class = erpal_make_class_name($link_text);
	
  //add ERPAL classes here
  if (!empty($link['localized_options']['attributes']['class']))
    $class .= ' '.implode(' ', $link['localized_options']['attributes']['class']);
  
  $variables['element']['#href'] = $variables['element']['#link']['href'];
  
  return '<li' . ' class="' . $class . '"' . '>' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
  // end of menu_css_names code
}

//
// helper function to build class names, with tags and other characters stripped out.
//
function erpal_make_class_name($text) {
	// do main text conversion to class name,
	// then remove double hyphens or hyphens at beginning or end of class name
	$text = drupal_strtolower(preg_replace('/(\s?&amp;\s?|[^-_\w\d])/i', '-', trim(strip_tags($text))));
	$text = preg_replace('/(^-+|-+$)/', '', $text);
	$text = preg_replace('/--+/', '-', $text);
	return $text;
}
