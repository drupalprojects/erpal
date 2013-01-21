<?php

/**
 * "Show files of project tasks" erpal_docs_helper filter
 * Get files of project, tasks
 */

class erpal_docs_helper_handler_argument_project_file_children extends views_handler_argument {

  /**
   * Clear query alter
   */
  function query() {
    if (!$nid = $this->argument) // check arg
      return;
    if (!$node = node_load($nid)) // check in node exists
      return;
    if ($node->type != 'erpal_project') // check in node is erpal_project
      return;
    
    // get project and it's child tasks files
    $files = _erpal_docs_helper_search_files($node);
    $nids = array_unique($files);
    // filter users that belong to project team
    if (!empty($nids)) {
      $this->ensure_my_table();
      $alias = $this->table_alias;
      $this->query->distinct = 1;
      $this->query->add_where($alias, "$alias.nid", $nids, "IN");
    }
  }
}
