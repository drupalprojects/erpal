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
    'field_data_field_asset_files' => array(
      'child_tasks_files' => array(
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
