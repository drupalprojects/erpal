<?php

//@TODO: This is mostly copied from erpal_book_helper/inc/jstree.inc may be abstract or better do this in js tree module?
//the thing that hints from integrating this into jstree module is some dependend functions like erpal_lib_... and erpal_basic_...

/**
* Implements hook_views_tree_before_move provided by views_jstree module after the moved node is saved
* @param the node that is moved
*/
function erpal_projects_helper_views_tree_before_move($node, $position, $view_name, $display_id) {
  //get the precessor of the node and add 5 to its weight, this is the weight of the node
  if ($view_name != 'tasks') 
    return;
  
  $types = array('erpal_task');
  $order_field = 'field_weight';

  $parent_nid = $node->field_parent[LANGUAGE_NONE][0]['target_id'];
  $child_nids = _erpal_projects_helper_get_child_tasks($parent_nid, $types, $order_field);
  $pre_position = $position -1; //the node before our given $node

  $pre_nid = false;
  if ($pre_position < 0)
    $weight = 0;
  else {
    $pre_nid = $child_nids[$pre_position];
 
    //$pre_node = node_load($pre_nid);
    //$weight = $pre_node->field_weight[LANGUAGE_NONE][0]['value'];
    module_load_include('inc', 'erpal_lib', 'inc/node');
    $weight = _erpal_lib_helper_get_field_value($pre_nid, 'field_weight', 'value');
  }

  $new_weight = $weight + 10;
  $node->field_weight[LANGUAGE_NONE][0]['value'] = $new_weight; //add 5 because we have always distance 5 between the nodes
  
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
      module_load_include('inc', 'erpal_lib', 'inc/node');
      _erpal_lib_helper_save_new_single_field_value($child_nid, 'field_weight', $next_weight);
      $next_weight = $next_weight +10;
    } 
  } 
  
}

/**
* Returns child tasks of a parent task. If parent is a project, return all tasks on the top level of the project having no parent set
*/
function _erpal_projects_helper_get_child_tasks($parent_nid, $types, $order_field) {
  static $children = array();
  
  if (!empty($children[$parent_nid][$order_field]))
    return $children[$parent_nid][$order_field];

  $parent_node = node_load($parent_nid);
  //calculate children
  $child_nids = _erpal_basic_helper_get_direct_children($parent_nid, $types, $order_field, 'field_parent');

  if ($parent_node->type == 'erpal_project') {
    //get all tasks in the given project but having no parent or having no parent of type "erpal_task"
    //This is necessary because a task could have no parent, a book_page or a task as parent.
    $top_level_nids = _erpal_projects_helper_get_tasks_of_project_having_no_task_parent($parent_node);
    $child_nids = array_merge($child_nids, $top_level_nids);
    
    //now create a all over order of all merged nids
    $child_nids = _erpal_basic_helper_get_ordered_nids_by_weight($child_nids, $order_field);
  } 

  //cache the values
  $children[$parent_nid][$order_field] = $child_nids;
  
  return $child_nids;  
}