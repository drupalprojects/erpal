<?php

/**
 * Provides views filter criteria and contextual filter 
 * "Task subtasks: Choses task and subtasks nids".
 * Filter gets nids of tasks and it's subtasks.
 *
 * Argument can work in pare with filter criteria "Task subtasks"(erpal_subtasks)
 * If erpal_subtasks value is "NO" returns single direct task id
 * If erpal_subtasks value is "YES" or doesn't exist returns direct task and 
 * subtasks
 * 
 * Filter criteria "Task subtasks"(erpal_subtasks) doesn't do any logic without
 * contestual filter "Task subtasks"
 */

/**
 * "Task subtasks" contextual filter(argument)
 * Get files of subtasks of task
 */
class erpal_projects_helper_handler_argument_erpal_projects extends views_handler_argument {

  /**
   * Clear query alter
   */
  function query($group_by = FALSE) {

    if (!$nid = $this->argument) // check arg
      return;

    if (!$node = node_load($nid)) // check in node exists
      return;

    // check in node is erpal_project or erpal_task
    if ($node->type != 'erpal_task')
      return;

    // prepare table
    $this->ensure_my_table();
    $alias = $this->table_alias;
    $this->query->distinct = 1; // distinct condition
    // Get filter criteria value
    // If erpal_subtasks value is "NO" get single direct task id
    if (isset($this->view->filter['erpal_subtasks']) && empty($this->view->filter['erpal_subtasks']->value[0])) {
      $this->query->add_where($alias, "{$alias}.nid", $nid);
    }
    // If erpal_subtasks value is "YES" or doesn't exist get direct task and 
    // subtasks
    else {
      $child_nids = _erpal_projects_helper_get_children($nid);
      $nids = array_unique($child_nids);
      $this->query->add_where($alias, "{$alias}.nid", $nids, "IN");
    }
  }

}

/**
 * "Show files of child tasks" erpal_docs_helper filter
 * Get files of project, tasks
 */
class erpal_projects_helper_handler_filter_erpal_projects extends views_handler_filter {

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