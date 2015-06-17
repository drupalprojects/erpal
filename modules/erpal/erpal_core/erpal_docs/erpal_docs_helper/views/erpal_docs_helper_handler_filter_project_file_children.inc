<?php

/**
 * "Show files of child tasks" contextual filter(argument)
 * Get files of project, tasks
 */
class erpal_docs_helper_handler_argument_child_tasks_files extends views_handler_argument {

  /**
   * Clear query alter
   * @TODO: better solution would be to get files directly from comments.
   * It requires joins for comments, WHERE OR conditions(to find files in 
   * comments) and views ui configuration because we need to show title of 
   * comment's task where the file is attached. Then we won't need to store all
   * files of comments in task via _erpal_docs_helper_form_submit function.
   */
  function query($group_by = FALSE) {

    if (!$nid = $this->argument) // check arg
      return;

    if (!$node = node_load($nid)) // check in node exists
      return;

    // check in node is erpal_project or erpal_task
    if ($node->type != 'erpal_project' && $node->type != 'erpal_task')
      return;

    // prepare table
    $this->ensure_my_table();
    $alias = $this->table_alias;
    $this->query->distinct = 1; // distinct condition

    // Join files node
    $join_node = new views_join();
    $join_node->construct('node', $alias, 'entity_id', 'nid', array(), 'LEFT');
    $this->query->ensure_table('node', $this->relationship, $join_node);
    $alias_node = 'field_asset_files_node';
    $this->query->table_queue[$alias_node] = array(
      'alias' => $alias_node,
      'table' => 'node',
      'relationship' => 'node',
      'join' => $join_node,
    );
    // Join field_data_field_asset_files
    $join_asset_files = new views_join();
    $join_asset_files->construct('field_data_field_asset_files', 'node', 'nid', 'field_asset_files_target_id', array(), 'INNER');
    $alias_asset_files = $this->query->ensure_table('field_data_field_asset_files', $this->relationship, $join_asset_files);
    $this->query->table_queue[$alias_asset_files] = array(
      'alias' => $alias_asset_files,
      'table' => 'field_data_field_asset_files',
      'relationship' => 'field_data_field_asset_files',
      'join' => $join_asset_files,
    );

    // If project_tasks_files value is "NO" get all direct files
    if (empty($this->view->filter['child_tasks_files']->value[0])) {
      // Get direct files of entity
      $this->query->add_where($alias, "{$alias}.entity_id", $nid);
    }

    // If project_tasks_files value is "YES" get all direct and child files
    else {
      // Get files of task and it's subtasks tree
      if ($node->type == 'erpal_task') {
        $child_nids = _erpal_projects_helper_get_children($nid);
        $nids = array_unique($child_nids);
        $this->query->add_where($alias, "{$alias}.entity_id", $nids, "IN");
      } else

      // Get files of project and it's tasks tree
      if ($node->type == 'erpal_project') {
        $join_project_ref = new views_join();
        $join_project_ref->construct('field_data_field_project_ref', $alias, 'entity_id', 'entity_id');
        $joined_table = $this->query->ensure_table('field_data_field_project_ref', $this->relationship, $join_project_ref);

        $expression = "{$alias}.entity_id = {$nid} OR {$joined_table}.field_project_ref_target_id = {$nid}";
        $this->query->add_where_expression(0, $expression);
      }
    }
  }

}

/**
 * "Show files of child tasks" erpal_docs_helper filter
 * Get files of project, tasks
 */
class erpal_docs_helper_handler_filter_child_tasks_files extends views_handler_filter {

  /**
   * Clear query alter
   */
  function query() {
    
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['expose']['required']['#prefix'] = '<div class="element-invisible">';
    $form['expose']['required']['#value'] = TRUE;
    $form['expose']['required']['#suffix'] = '</div>';
  }

  /**
   * Subfiles checkbox. Provides show/hide choise
   */
  function value_form(&$form, &$form_state) {
    $options = array(
      '0' => 'No',
      '1' => 'Yes',
    );
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Show files of child tasks'),
      '#default_value' => isset($this->value) ? $this->value : NULL,
      '#options' => $options,
    );
    return $form;
  }

}

/**
 * "Has attached file" contextual filter(argument)
 * Shows all nodes that have the file
 */
class erpal_docs_helper_handler_argument_file_parent_nids extends views_handler_argument {

  /**
   * Clear query alter
   */
  function query($group_by = FALSE) {
    // check arg
    if (!$nid = $this->argument) {
      return;
    }
    // Get nids of all node entity referers of target erpal file
    $nids = _erpal_docs_helper_refererers_nids($nid,'erpal_file');

    if(empty($nids)){
      // Return no results if file doesn't have parents 
      $nids = array(0);
    }
    
    // prepare table
    $this->ensure_my_table();
    $alias = $this->table_alias;
    
    $this->query->add_where($alias, "{$alias}.nid", $nids, 'IN');
  }

}