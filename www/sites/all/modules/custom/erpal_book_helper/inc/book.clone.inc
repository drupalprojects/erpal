<?php

/**
* Provide functions to clone books, book pages (with tasks)
*/

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
    'title' => t('Processing Example Batch'),
    'init_message' => t('Example Batch is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Example Batch has encountered an error.'),
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
        $new_children = _erpal_book_helper_get_all_child_nids_deep_search($page_nid, $types);
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
      $book_nid = $parent_node->field_parent[LANGUAGE_NONE][0]['target_id'];
    
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
    
      //Set the parent
      $node->field_parent[LANGUAGE_NONE][0]['target_id'] = $parent_nid;
      //add new node to book
      $node->field_book_ref[LANGUAGE_NONE][0]['target_nid'] = $book_nid;
      
      // Add an extra property as a flag.
      if ($node->type == 'erpal_book_page' || $node->type == 'erpal_book') {
        $node->field_book_origin[LANGUAGE_NONE][0]['target_id'] = $original_node->nid;
      }

      //Hook to let other modules clone children or set some properties
      drupal_alter('erpal_clone_node', $node, $parent_nid, $original_node, $options);

      node_save($node);
      return $node;
    }
  }
}

/**
* Gets all child nodes of a given parent by deepsearch.
* @return a flat array with all children in deep search order
* @param $types the node types that should be returned and deep searched as children
*/
function _erpal_book_helper_get_all_child_nids_deep_search($nid, $types=array()) {
  $children = _erpal_book_helper_get_direct_children($nid, $types);
 
  $all_children = array();
  foreach ($children as $delta=>$child_nid) {    
    $sub_children = _erpal_book_helper_get_all_child_nids_deep_search($child_nid, $types);
    $all_children[] = array('parent' => $nid, 'child' => $child_nid);
    $all_children = array_merge($all_children, $sub_children);
  }
  
  return $all_children;
}

/**
* returns an array of direct children of a node using field_parent
* @param $nid the parent nid to search children for
* @param $types only those node types are returned
*/
function _erpal_book_helper_get_direct_children($nid, $types=array()) {
  
  $children = array();
  if (!count($types))
    return $children;
 
  foreach ($types as $type) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $type)
    ->fieldCondition('field_parent', 'target_id', $nid, '=')
    ->addMetaData('account', user_load(1)); // run the query as user 1

    $result = $query->execute();
    if (isset($result['node'])) {
      $new_nids = array_keys($result['node']);
      $children = array_merge($children, $new_nids);
    }
  }
  
  return $children;
}
