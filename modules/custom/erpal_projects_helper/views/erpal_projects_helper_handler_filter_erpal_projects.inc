<?php

/**
 * "Task subtasks" contextual filter(argument)
 * Get files of subtasks of task
 */
class erpal_projects_helper_handler_filter_erpal_projects extends views_handler_argument {

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

    $child_nids = _erpal_projects_helper_get_children($nid);
    $nids = array_unique($child_nids);
    $this->query->add_where($alias, "{$alias}.nid", $nids, "IN");
  }

}

