<?php

/**
* Implements hook_book_child_nodes provided by erpal_book_helper module
* @param $nids_only if true only nids are returned otherwise node objects are fully loaded
*/
function erpal_projects_helper_book_child_nodes($parent_node, $book_node, $options, $nids_only) {
  
  //set default value if not set
  if (!isset($options['export_tasks']))
    $options['export_tasks'] = false;
    
  if (!$options['export_tasks'])
    return array();

  $child_task_nodes = _erpal_projects_helper_get_tasks_child_nodes($parent_node, $options, $nids_only);

  return $child_task_nodes;
}

/**
* Return all Task children
*/
function _erpal_projects_helper_get_tasks_child_nodes($parent_node, $options, $nids_only) {
  //we return all tasks that have the given parent_node as parent
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_task')
  ->propertyCondition('status', 1)
  ->fieldCondition('field_parent', 'target_id', $parent_node->nid, '=')
  ->fieldOrderBy('field_weight', 'value', 'ASC');

  //set some default values
  if (!isset($options['ignore_exclude']['pdf']))
    $options['ignore_exclude']['pdf'] = true;
  
  if (!$options['ignore_exclude']['pdf']) {
    //exclude some node from export
    $exclude = array('pdf');
    
    //normally we would do it like
    //$query->fieldCondition('field_task_exclude_from', 'value', 'pdf', '!=');
    //but that doenst work if field has no value, not even NULL at all. So we get all excluded nids and
    //exclude them in the query.
    $field['field'] = 'field_task_exclude_from';
    $field['column'] = 'value';
    $excluded = _erpal_book_helper_get_excluded_nodes_by_parent($parent_node, $exclude, $field);

    if (count($excluded) > 0)
      $query->propertyCondition('nid', $excluded, 'NOT IN');
  } 
  
  $result = $query->execute();
dpm($result);
dpm($parent_node);
  $child_task_nodes = array();
  if (isset($result['node'])) {
    $child_nids = array_keys($result['node']);
    
    if (!$nids_only)
      $child_task_nodes = entity_load('node', $child_nids);
    else
      $child_task_nodes = $child_nids;
  }
  
  return $child_task_nodes;
}

/**
* alter pdf create form provided by erpal_book_helper module
*/
function _erpal_projects_helper_book_pdf_form_alter(&$form, &$form_state) {
  $book_nid = $form['nid']['#value'];
  $book_node = node_load($book_nid); //may be a book node or a book-page node
  $has_project = _erpal_projects_helper_has_project($book_node);
  if ($has_project) {
    $form['export_tasks'] = array(
      '#type' => 'checkbox',
      '#title' => t('Export tasks'),
      '#default_value' => false,
      '#weight' => -1,
    );
  } else {
    $form['export_tasks'] = array(
      '#type' => 'value',
      '#default_value' => false,
    );
  }
    
}

/**
* Implements hook_jstree_context_menu to provide custom menu for book js tree, dependent on the node type
*/
function erpal_projects_helper_jstree_context_menu($entity_type, $type, $id, $root_id) {
  
  $current_viewed_url = $_SESSION['view_jstree']['current_tree_url']; //@TODO dirty but works, if we delete a node in the tree we want to be redirected to the curent tree view againt und this is where we are actually.
  $query_back = array('destination' => $current_viewed_url);
  $query_add = $query_back;
  $query_add['field_parent'] = $id;
  
  $query_timetracking_add = $query_back;
  $query_timetracking_add['field_timetracking_subject'] = $id;
  $parent_node = node_load($id);

  $has_project = _erpal_projects_helper_has_project($parent_node);
  
  if ($type == 'erpal_task') {
    
    $menu = array(
      array('title' => t('View'), 'url' => url('node/'.$id)),
      array('title' => t('Edit'), 'url' => url('node/'.$id.'/edit', array('query' => $query_back))),
      array('title' => t('Delete'), 'url' => url('node/'.$id.'/delete', array('query' => $query_back))),            
    );
    
    if ($has_project) {
      $query_add['field_project_ref'] = $has_project;
      $menu[] = array('title' => t('Add sub task'), 'url' => url('node/add/erpal-task', array('query' => $query_add)));
      $menu[] = array('title' => t('Add timetracking'), 'url' => url('node/add/erpal-timetracking', array('query' => $query_timetracking_add)));
    }
    
    return $menu;
  }
  
  if ($type == 'erpal_book_page') {            
    if ($has_project) {
      $query_add['field_project_ref'] = $has_project;
      $menu = array(
        array('title' => t('Add task'), 'url' => url('node/add/erpal-task', array('query' => $query_add))),
      );
      
      return $menu;
    }    
  }
}

/**
* Definie which node types are allowed as children of a parent in jstree
* structure is 'parent_type' => array with possible child types
* @see views_jstree.module function theme_views_jstree
*/
function erpal_projects_helper_jstree_allowed_child_types() {
  return array(
    'erpal_task' => array('erpal_task'),
  );
}
