<?php

/**
 * "Show files of child tasks" erpal_docs_helper contextual filter(argiment)
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
    
    $this->ensure_my_table();
    $alias = $this->table_alias;
    
    // If project_tasks_files value is "NO" get all direct files
    if (empty($this->view->filter['project_tasks_files']->value[0])){
      $files = _erpal_docs_helper_search_files($node, $node->type);
    } 
    // If project_tasks_files value is "YES" get all child files
    else {
      $files = _erpal_docs_helper_search_files($node, $node->type, TRUE);
    }

    if(!$files && !is_array($files))
      return;

    $nids = array_unique($files);

    // filter files that belong to project team
    if (!empty($nids)) {
      $this->query->distinct = 1;
      $this->query->add_where($alias, "$alias.nid", $nids, "IN");
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

