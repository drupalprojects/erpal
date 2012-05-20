<?php


/**
* Implements hook_jstree_context_menu to provide custom menu for book js tree, dependent on the node type
*/
function erpal_projects_helper_jstree_context_menu($entity_type, $type, $id, $root_id) {
  
  $current_viewed_url = $_SESSION['view_jstree']['current_tree_url']; //@TODO dirty but works, if we delete a node in the tree we want to be redirected to the curent tree view againt und this is where we are actually.
  $query_back = array('destination' => $current_viewed_url);
  
  $parent_node = node_load($id);

  $has_project = _erpal_projects_helper_has_project($parent_node);
  
  if ($type == 'erpal_task') {
    
    $menu = array(
      array('title' => t('View'), 'url' => url('node/'.$id)),
      array('title' => t('Edit'), 'url' => url('node/'.$id.'/edit', array('query' => $query_back))),
      array('title' => t('Delete'), 'url' => url('node/'.$id.'/delete', array('query' => $query_back))),            
    );
    
    if ($has_project) {
      $menu[] = array('title' => t('Add sub task'), 'url' => url('node/add/erpal-task/'.$id, array('query' => $query_back)));
      $menu[] = array('title' => t('Add timetracking'), 'url' => url('node/add/erpal-timetracking/'.$id, array('query' => $query_back)));
    }
    
    return $menu;
  }
  
  if ($type == 'erpal_book_page') {            
    if ($has_project) {
      $menu = array(
        array('title' => t('Add task'), 'url' => url('node/add/erpal-task/'.$id, array('query' => $query_back))),
      );
      
      return $menu;
    }    
  }
}
