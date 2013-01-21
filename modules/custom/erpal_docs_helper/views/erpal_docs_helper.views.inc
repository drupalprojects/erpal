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
        'title' => t('Show files of project tasks'),
        'help' => t('Get project subfiles'),
        'argument' => array(
          'handler' => 'erpal_docs_helper_handler_argument_project_file_children'
        ),
        'filter' => array(
          'handler' => 'erpal_docs_helper_handler_filter_project_file_children'
        ),
      )
    )
  );
}

function _erpal_docs_helper_search_files($node) {
  $files = array();
  if (!isset($node) || !$nid = $node->nid)
    return $files;

  // Get files of project and it's child tasks
  $query = db_select('field_data_field_asset_files', 'f');
  $query->leftJoin('field_data_field_project_ref', 'p', 'p.entity_id = f.entity_id');
  $query->condition(
    db_or()
    ->condition('p.field_project_ref_target_id', $nid)
    ->condition('f.entity_id', $nid)
    );
  $query->fields('f', array('field_asset_files_target_id'));
  
  if (!$result = $query->execute())
    return $files;

  foreach ($result as $value) {
    if (!empty($value->field_asset_files_target_id))
      $files[] = $value->field_asset_files_target_id;
  }
  return $files;
}
