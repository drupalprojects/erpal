<?php

/**
* @file custom code of erpal_project_book feature
*/

/**
* Checks if projects module is enabled and if it is, call a function that shows at which projects the given book is referenced
*/
function _erpal_project_book_render_projects_referencing_books($book_nid) {
  return _erpal_projects_helper_render_projects_referencing_books($book_nid);
}

/**
* Returns the first book page node of a given node where the book page is a parent of the given node, otherwise return false
*/
function _erpal_project_book_get_parent_book_page($node) {
  if (is_numeric($node)) {
    $node = node_load($node);
  }
  
  $parent_field_name = 'field_book_parent';
  
  //if this is a book page return it immideately
  if ($node->type == 'erpal_book_page') {
    return $node;
  }
  
  if (empty($node->{$parent_field_name}[LANGUAGE_NONE][0]['target_id'])) {
    //has no parent. If the current node is a book_page return this, otherwise false
    return false;
  } else {
    //there is another parent, check this one
    $parent_nid = $node->{$parent_field_name}[LANGUAGE_NONE][0]['target_id'];    
    return _erpal_project_book_get_parent_book_page($parent_nid);
  }
}