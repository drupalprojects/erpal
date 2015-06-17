<?php

/**
* Implements hook_book_child_nodes provided by erpal_book_helper module
* @param $nids_only if true only nids are returned otherwise node objects are fully loaded
*/
function erpal_projects_helper_book_child_nodes($parent_node, $book_node, $options, $nids_only, $context='project') {
  
  if(isset($options['pages']['export_tasks']) && $options['pages']['export_tasks'])
    $options['export_tasks'] = true;
  
  //set default value if not set
  if (!isset($options['export_tasks']))
    $options['export_tasks'] = false;
    
  if (!$options['export_tasks'])
    return array();

  $child_task_nodes = _erpal_projects_helper_get_tasks_child_nodes($parent_node, $options, $nids_only, false, $context);

  return $child_task_nodes;
}

/**
* Return all Task children
* @param $skipp_access if set all tasks are returned no matter if the user has access or not
*/
function _erpal_projects_helper_get_tasks_child_nodes($parent_node, $options, $nids_only, $skipp_access=false, $context='project') {
  //we return all tasks that have the given parent_node as parent
  if ($context == 'project') {
    $weight_field = 'field_weight';
    $parent_field = 'field_parent';
  }
  
  if ($context == 'book') {
    $weight_field = 'field_book_weight';
    $parent_field = 'field_book_parent';
  }
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'erpal_task')
  ->propertyCondition('status', 1)
  ->fieldCondition($parent_field, 'target_id', $parent_node->nid, '=')
  ->fieldOrderBy($weight_field, 'value', 'ASC');
  
  if ($skipp_access)
    $query->addMetaData('account', user_load(1)); // Run the query as user 1 to skipp access
    
  //set some default values
  if (!isset($options['options']['ignore_exclude']))
    $options['options']['ignore_exclude'] = true;
  
  if (!$options['options']['ignore_exclude']) {
    //exclude some node from export
    $exclude = array('export');
    
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
* Check, if a book has been removed comparing project and old_project params
*/
function _erpal_projects_helper_handle_removed_book_nodes($project_node, $old_project_node) {
  $old_books = isset($old_project_node->field_books_ref[LANGUAGE_NONE]) ? $old_project_node->field_books_ref[LANGUAGE_NONE] : array();
  $new_books = isset($project_node->field_books_ref[LANGUAGE_NONE]) ? $project_node->field_books_ref[LANGUAGE_NONE] : array();

  //is there a book in old_books that is no more in new books?
  $no_more_linked = array();
  foreach ($old_books as $old_delta => $old_nid) {
    $old_nid = $old_nid['target_id'];
    $is_linked = false;
    foreach ($new_books as $new_delta => $new_nid) {
      $new_nid = $new_nid['target_id'];
      if ($old_nid == $new_nid)
        $is_linked = true;
    }
    
    if (!$is_linked)
      $no_more_linked[] = $old_nid;
  }

  //now go throug all book nids that are no more linked, load their deep searched children but only tasks and
  //remove the parent link of each task that links to one of these pages
  $types = array('erpal_task', 'erpal_book_page');
  $all_task_nids = array();
  foreach ($no_more_linked as $book_nid) {
    $nids = _erpal_basic_helper_get_all_child_nids_deep_search($book_nid, $types);
    $all_task_nids = array_merge($all_task_nids, $nids);
  }

  //now update and delete the parent of these tasks if they really belong to the project given
  foreach ($all_task_nids as $nid) {
    $nid = $nid['child'];
    $a_node = node_load($nid);
    $task_project_nid = isset($a_node->field_project_ref[LANGUAGE_NONE][0]['target_id']) ? $a_node->field_project_ref[LANGUAGE_NONE][0]['target_id'] : false;
    if ($a_node->type == 'erpal_task' && $task_project_nid == $project_node->nid) {
      unset($a_node->field_parent[LANGUAGE_NONE]);
      node_save($a_node);
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
