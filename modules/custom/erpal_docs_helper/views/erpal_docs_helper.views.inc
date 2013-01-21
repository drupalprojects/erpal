<?php

/**
 * Implements of hook_views_api().
 */
function erpal_docs_helper_views_api() {
  return array('api' => 3);
}

/**
 * Implements of hook_views_data().
 */
function erpal_docs_helper_views_data() {
  return array(
    'node' => array(
      'project_tasks_files' => array(
        'group' => t('File Usage'),
        'title' => t('Show files of child tasks'),
        'help' => t('Get files of project\'s tasks or files of task\'s subtasks'),
        'argument' => array(
          'handler' => 'erpal_docs_helper_handler_argument_child_tasks_files'
        ),
        'filter' => array(
          'handler' => 'erpal_docs_helper_handler_filter_child_tasks_files'
        ),
      )
    )
  );
}

/**
 * Get all direct or child files of erpal_project or erpal_task node
 * @param object $node
 * @param string $node_type
 * @param bool $search_children
 * @return array
 *   files nids
 */
function _erpal_docs_helper_search_files($node, $node_type, $search_children = FALSE) {
  $files = array();
  if (!isset($node) || !$nid = $node->nid)
    return $files;

  // check in node is erpal_project or erpal_task
  if ($node_type != 'erpal_project' && $node_type != 'erpal_task')
    return $files;

  $model = new erpal_docs_helper_files();

  // Search children files
  if ($search_children) {
    if ($node_type == 'erpal_task') {
      $result = $model->task_children_get_files($nid);
    }
    if ($node_type == 'erpal_project') {
      $result = $model->project_children_get_files($nid);
    }
  }
  // Search direct files
  else {
    $result = $model->entity_get_files($nid);
  }

  if ($result) {
    foreach ($result as $value) {
      if (!empty($value->field_asset_files_target_id))
        $files[] = $value->field_asset_files_target_id;
    }
  }

  return $files;
}
