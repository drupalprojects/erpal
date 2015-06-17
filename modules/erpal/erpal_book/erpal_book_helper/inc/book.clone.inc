<?php

/**
* Provide functions to clone books, book pages (with tasks)
*/

/**
* Callback to clone complete books
* @param $book_node the book node to clone
*/
function _erpal_books_helper_book_clone_callback($book_node) {
  //first we prepare the project and the upper book, then we start the batch operation
  //to clone a book_page as a new subpage. 
  $form = drupal_get_form('erpal_books_helper_book_clone_form', $book_node);
  
  return $form;
}

/**
* Form to configure clone process for complete books
*/
function erpal_books_helper_book_clone_form($form, $form_state, $book_node) {
  $form = array();
  
  //we dont ask to clone children because it doesn't make sense to clone only the top book page
  $book_link = l($book_node->title, "node/".$book_node->nid);
  $form['information'] = array(
    '#type' => 'item',
    '#markup' => "<h2>".t('Clone !book_link as new book', array('!book_link' => $book_link))."</h2>",
    '#weight' => -20,
  );
  
  $form['book_nid'] = array(
    '#type' => 'value',
    '#value' => $book_node->nid,
  );
  
  $form['title'] = array(
    '#title' => t('New books title'),
    '#type' => 'textfield',
    '#required' => true,
    '#default_value' => t('Clone of')." ".$book_node->title,
  );
  
  $form['contact'] = array(
    '#title' => t('Contact'),
    '#type' => 'textfield',
    '#autocomplete_path' => 'crm/contacts/autocomplete',
    '#ajax' => array(
      'callback' => '_erpal_book_helper_ajax_company_preselect_addresses_config',
      'wrapper' => 'basic_address_wrapper',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );
  
  $form['ajax_wrapper'] = array(
    '#prefix' => '<div id="basic_address_wrapper">',
    '#suffix' => '</div>',
  );
  
  if (isset($form_state['triggering_element']) && $form_state['triggering_element']['#name'] == 'contact') {
    //try to get a contact nid
    $contact_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($form_state['values']['contact']);
    
    if ($contact_nid) {
      $contact_node = node_load($contact_nid);
      $form['ajax_wrapper']['address_id'] = array(
        '#type' => 'select',
        '#title' => t('Address to replace tokens in book'),
        '#options' => _erpal_basic_helper_get_contact_adresses($contact_node, true),
      );
    }
  }
  
  //ask other modules form config form
  $args = array('book_node' => $book_node);
  drupal_alter('clone_book_action_form', $form, $form_state, $args);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Clone'),
  );
  
  return $form;
}

/**
* Callback for AJAX request to update contact address
*/
function _erpal_book_helper_ajax_company_preselect_addresses_config($form, $form_state) {

  if (isset($form['ajax_wrapper']))
    return $form['ajax_wrapper'];  //form has already been processed, so just return the elements
    
  return array();
}

/**
* Submit handler for book clone form
*/
function erpal_books_helper_book_clone_form_submit($form, $form_state) {
  $values = $form_state['values'];
    
  $book_nid = $values['book_nid'];
  $book_node = node_load($book_nid);
  
  $values['clone_children'] = 1; //allways clone children in complete book clone, otherwise it makes no sense
  $options = _erpal_books_helper_options_for_clone($values);
  
  //get child nodes that should be copied as children of the book
  $child_nodes = _erpal_book_helper_get_children($book_node, $book_node, $options, array());
  $child_nids = array();
  foreach ($child_nodes as $child_node) {
    $child_nids[] = $child_node->nid;
  }
  
  //clone the parent node and call other modules to do their thing
  //then call batch operation to clone all subpages of the book node as usual
  $new_book_node = _erpal_book_helper_clone_node($book_node->nid, false, false, $options);

  unset($new_book_node->field_asset_files);
  
  //now start batch operation with all children of the node  
  unset($options['title']);  //otherwise title of all subpages will be set to this!
  _erpal_book_helper_clone_pages_batch($child_nids, $new_book_node->nid, $options);
  
  drupal_set_message(t('The book has successfully been cloned'));
  drupal_goto("node/".$new_book_node);
}

/**
* creates clone options from clone form submit values
* @param $form_values the form values from clone config form submit or the context from bulk operation config form submit
*/
function _erpal_books_helper_options_for_clone($form_values) {
  $options = array();
  
  $types = array('erpal_book_page');
  if (!empty($form_values['clone_tasks']))
    $types[] = 'erpal_task';
    
  $options = array(
    'clone_children' => isset($form_values['clone_children']) ? $form_values['clone_children'] : 1,
    'clone_tasks' => !empty($form_values['clone_tasks']) ? 1 : 0,
    'types' => $types,
    'title' => isset($form_values['title']) ? $form_values['title'] : false,
    'contact_nid' => isset($form_values['contact']) ? _erpal_basic_helper_get_nid_from_autocomplete_string($form_values['contact']) : '',
    'address_id' => isset($form_values['address_id']) ? $form_values['address_id'] : false,
  );

  //let other module add their options from submit values  
  drupal_alter('options_for_clone', $options, $form_values);

  return $options;
}

/**
* Clones all page nids including all children in deep search with a batch process
* @param $page_nids an array of nids of book_pages to clone
* @param $top_parent_nid all new cloned book pages at top most level will be assigned to this parent
*/
function _erpal_book_helper_clone_pages_batch($page_nids, $top_parent_nid, $options=array()) {

  $batch = array(
    'operations' => array(
      array('_erpal_book_helper_clone_pages_batch_operation', array($page_nids, $top_parent_nid, $options)),
      ),
    'finished' => '_erpal_book_helper_clone_pages_finished',
    'title' => t('Processing Clone Batch'),
    'init_message' => t('Clone Batch is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Clone Batch has encountered an error.'),
  );
  batch_set($batch);

  // If this function was called from a form submit handler, stop here,
  // FAPI will handle calling batch_process().

  // If not called from a submit handler, add the following,
  // noting the url the user should be sent to once the batch
  // is finished.
  // IMPORTANT: 
  // If you set a blank parameter, the batch_process() will cause an infinite loop

  batch_process('node/'.$top_parent_nid); //return to the parent
}

/**
* Clones all given nodes
* @param $page_nids an array of nids of book_pages to clone
* @param $parent_nid all new cloned book pages will be assigned to this parent
*/
function _erpal_book_helper_clone_pages_batch_operation($page_nids, $parent_nid, $options=array(), &$context) {  
  if (!isset($context['sandbox']['progress'])) {
    //get all children to clone
    $all_children = array();
    $total = 0;
    foreach ($page_nids as $page_nid) {
      $types = isset($options['types']) ? $options['types'] : false;
      if (!$types)
        $types = array('erpal_book_page');

      //clone children?
      if ($options['clone_children'])
        $new_children = _erpal_basic_helper_get_all_child_nids_deep_search($page_nid, $types);
      else
        $new_children = array();
        
      $top_node = array('parent' => $parent_nid, 'child' => $page_nid);
      $all_children[$page_nid] = array_merge(array($top_node), $new_children);
            
      $total += count($all_children[$page_nid]);
    }

    //add the book, all book_pages will be added to
    $parent_node = node_load($parent_nid);
    if ($parent_node->type == 'erpal_book')
      $book_nid = $parent_node->nid;
    elseif ($parent_node->type == 'erpal_book_page')
      $book_nid = $parent_node->field_book_parent[LANGUAGE_NONE][0]['target_id'];
    
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['book_nid'] = $book_nid;  //the book_nid where all book_pages will be added to
    $context['sandbox']['current_delta'] = -1;  //the current delta in queue of all children
    $context['sandbox']['current_parent'] = 0; //the current parent_nid of all page_nids
    $context['sandbox']['all_children'] = $all_children;
    $context['sandbox']['max'] = $total;
  }
  
  //only process one node at a time
  $all_children = $context['sandbox']['all_children'];
  $book_nid = $context['sandbox']['book_nid'];
  $clone_parent_nid = $context['sandbox']['current_parent'];
  //if no parent is set, take the first for our flat childrens array
  if (!$clone_parent_nid) {
    $all_parents = array_keys($all_children);
    $clone_parent_nid = $all_parents[0];
  }
   
  $delta = $context['sandbox']['current_delta'];
  
  $children = $all_children[$clone_parent_nid];
  $child = ($delta > -1) ? $children[$delta] : $children[0];

  //if we process the first delta, of a tree parent, we use the given function argument parent_nid to add the new top level
  //children.
  if ($delta > -1) {
    $parent_nid = $child['parent'];    
  } else {
    $delta = 0;
  }
  //otherwise keep the value from function argument
  
  $old_child_nid = $child['child'];
  // Here we actually perform our processing on the current node.
  $new_node = _erpal_book_helper_clone_node($old_child_nid, $parent_nid, $book_nid, $options);

  //now change the parent of all child nodes to new nid if parent_nid is set
  foreach ($all_children as $a_parent_nid=>$a_children) {
    foreach ($all_children[$a_parent_nid] as $a_delta=>$a_child) {
      $a_parent = $a_child['parent'];
      if ($a_parent == $old_child_nid) {
        //set parent_nid to new cloned node
        $all_children[$a_parent_nid][$a_delta]['parent'] = $new_node->nid;
      }
    }
  }
  
  //set new delta and parent_nid values
  //check if there is a next delta
  
  if (isset($all_children[$clone_parent_nid][$delta +1])) {
    //use this one for the next step
    $delta = $delta +1;    
  } else {
    //otherwise stept to next parent if there is one to clone
    $parents = array_keys($all_children);
    $current_index = array_search($clone_parent_nid, $parents);
    $next_index = $current_index +1;

    if (!isset($parents[$next_index]))
      $clone_parent_nid = 0;
    else
      $clone_parent_nid = $parents[$next_index];
      
    $delta = -1;  //reset delta
  }
  
  // Store some result for post-processing in the finished callback.
  $context['results'][] = check_plain($new_node->title);

  //set the new children with updated parent nids
  $context['sandbox']['all_children'] = $all_children;
  // Update our progress information.
  $context['sandbox']['progress']++;
  $context['sandbox']['current_delta'] = $delta;
  $context['sandbox']['current_parent'] = $clone_parent_nid;

  if (!$clone_parent_nid) {
    $context['finished'] = 1; //finsihed because there is no other parent to process
  } else {
    // Inform the batch engine that we are not finished,
    // and provide an estimation of the completion level we reached.
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    } else
      $context['finished'] = 1;
  }
  
  $context['message'] = t('Now processing %node', array('%node' => $node->title));
}

/**
* Callback of erpal book clone batch process finished
*/
function _erpal_book_helper_clone_pages_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = count($results) .' processed.';
    $message .= theme('item_list', $results);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
  }
  drupal_set_message($message);
}

/**
* Clones a simple node and saves it
*/
function _erpal_book_helper_clone_node($nid, $parent_nid, $book_nid, $options) {

  if (is_numeric($nid)) {
    global $user;

    $node = node_load($nid);
    if (isset($node->nid)) {
      $original_node = clone $node; //clone the total node object!

      //alter some variables of this node
      $node->nid = NULL;
      $node->vid = NULL;
      $node->tnid = NULL;
      $node->name = $user->name;
      $node->uid = $user->uid;
      $node->created = NULL;
      $node->menu = NULL;
      $node->path = NULL;
      $node->files = array();
    
      //unset the template flag because if a book was a template, the cloned one should not be a template
      unset($node->field_is_template);
    
      //Set the parent if give (not given if we clone a book
      if ($parent_nid)
        $node->field_book_parent[LANGUAGE_NONE][0]['target_id'] = $parent_nid;
      //add new node to book if given, not given if we clone a book
      if ($book_nid)
        $node->field_book_ref[LANGUAGE_NONE][0]['target_nid'] = $book_nid;
      
      // Add an extra property as a flag.
      if ($node->type == 'erpal_book_page' || $node->type == 'erpal_book') {
        $node->field_book_origin[LANGUAGE_NONE][0]['target_id'] = $original_node->nid;
      }

      $title = isset($options['title']) ? $options['title'] : $original_node->title;
      if ($title)
        $node->title = $title;
      
      $original_contact_nid = isset($original_node->field_contact_ref[LANGUAGE_NONE][0]['target_id']) ? $original_node->field_contact_ref[LANGUAGE_NONE][0]['target_id'] : false;
      $contact_nid = isset($options['contact_nid']) ? $options['contact_nid'] : $original_contact_nid;
      
      if ($contact_nid)
        $node->field_contact_ref[LANGUAGE_NONE][0]['target_id'] = $contact_nid;
      
      $original_address_id = isset($original_node->field_address_id[LANGUAGE_NONE][0]['value']) ? $original_node->field_address_id[LANGUAGE_NONE][0]['value'] : false;
      $address_id = isset($options['address_id']) ? $options['address_id'] : $original_address_id;
      
      if ($address_id)
        $node->field_address_id[LANGUAGE_NONE][0]['value'] = $address_id;
      
      //Hook to let other modules clone children or set some properties
      $args = array('parent_nid' => $parent_nid, 'original_node' => $original_node, 'options' => $options, 'original_node' => $original_node);
      drupal_alter('erpal_clone_node', $node, $args);

      node_save($node);
      
      drupal_alter('erpal_clone_node_postprocess', $node, $args);
      return $node;
    }
  }
}

