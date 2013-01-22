<?php

/**
 * "Show files of child tasks" contextual filter(argiment)
 * Get files of project, tasks
 */
class erpal_docs_helper_handler_argument_child_tasks_files extends views_handler_argument {

  /**
   * Clear query alter
   */
  function query() {

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
    
    // If project_tasks_files value is "NO" get all direct files
    if (empty($this->view->filter['project_tasks_files']->value[0])) {
      // Get direct files of entity
      $this->query->add_where($alias, "{$alias}.entity_id", $nid);
    }
    
    // If project_tasks_files value is "YES" get all direct and child files
    else {

      // Get files of task and it's subtasks tree
      if ($node->type == 'erpal_task') {
        $child_nids = _erpal_timetracking_helper_get_children($nid);
        $nids = array_unique($child_nids);
        $this->query->add_where($alias, "{$alias}.entity_id", $nids, "IN");
      } else

      // Get files of project and it's tasks tree
      if ($node->type == 'erpal_project') {
        $join = new views_join();
        $join->construct('field_data_field_project_ref', $alias, 'entity_id', 'entity_id');
        $join_table = $this->query->ensure_table('field_data_field_project_ref', $this->relationship, $join);
        $expression = "{$alias}.entity_id = {$nid} OR {$join_table}.field_project_ref_target_id = {$nid}";
        $this->query->add_where_expression($this->options['group'], $expression);
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
