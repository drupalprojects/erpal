<?php

/**
 * Implements of hook_views_data().
 */
function erpal_projects_helper_views_data() {
  return array(
    'node' => array(
      'erpal_subtasks' => array(
        'group' => t('Task'),
        'title' => t('Task subtasks'),
        'help' => t('Choses task and subtasks nids'),
        'argument' => array(
          'handler' => 'erpal_projects_helper_handler_filter_erpal_projects'
        ),
      )
    )
  );
}
