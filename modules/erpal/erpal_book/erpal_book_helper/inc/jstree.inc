<?php

//@TODO: This is mostly copied from erpal_book_helper/inc/jstree.inc may be abstract or better do this in js tree module?
//the thing that hints from integrating this into jstree module is some dependend functions like erpal_lib_... and erpal_basic_...

/**
* Implements hook_views_tree_before_move provided by views_jstree module after the moved node is saved
* @param the node that is moved
*/
function erpal_book_helper_views_tree_before_move($node, $position, $view_name, $display_id) {
  //get the predecessor of the node and add 5 to its weight, this is the weight of the node
  if ($view_name != 'book_children') 
    return;
          
  $types = array('erpal_task', 'erpal_book_page');
  $order_field = 'field_book_weight';

  $parent_nid = $node->field_book_parent[LANGUAGE_NONE][0]['target_id'];
  $child_nids = _erpal_basic_helper_get_direct_children($parent_nid, $types, $order_field, 'field_book_parent');
  $pre_position = $position -1; //the node before our given $node

  $pre_nid = false;
  if ($pre_position < 0)
    $weight = 0;
  else {
    $pre_nid = $child_nids[$pre_position];
    $weight = _erpal_lib_helper_get_field_value($pre_nid, 'field_book_weight', 'value');
  }

  $new_weight = $weight + 10;
  $node->field_book_weight[LANGUAGE_NONE][0]['value'] = $new_weight; //add 5 because we have always distance 5 between the nodes
  
  //now reorder all other nodes from the "position" on, if there was no pre_nid, reorder all and this node is the first!
  $start_reorder = !$pre_nid;
  $next_weight = $new_weight +10; //all after the current moved node
  
  foreach ($child_nids as $delta=>$child_nid) {
    //do nothing for the node that is moved as weight was already set.
    if ($child_nid == $node->nid)
      continue;
  
    //check when to start!    
    if ($delta >= $position)
      $start_reorder = true;
  
    if ($start_reorder) {
      //do reordering!            
      _erpal_lib_helper_save_new_single_field_value($child_nid, 'field_book_weight', $next_weight);
      $next_weight = $next_weight +10;
    } 
  }  
}