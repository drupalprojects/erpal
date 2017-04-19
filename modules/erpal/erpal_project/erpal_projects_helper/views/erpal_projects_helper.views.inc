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
          'handler' => 'erpal_projects_helper_handler_argument_erpal_projects',
        ),
        'filter' => array(
          'handler' => 'erpal_projects_helper_handler_filter_erpal_projects',
        )
      ),
      'billables_by_project' => array(
        'group' => t('Billables'),
        'title' => t('Billables by projects'),
        'help' => t('Chooses billables IDs by a given project'),
        'argument' => array(
          'handler' => 'erpal_projects_helper_handler_argument_billables_by_projects',
        ),       
      ),      
      'billables_by_project_skipp_grouped' => array(
        'group' => t('Billables'),
        'title' => t('Billables by projects without grouped parents'),
        'help' => t('Chooses billables IDs by a given project and exclude parents billables'),
        'argument' => array(
          'handler' => 'erpal_projects_helper_handler_argument_billables_by_projects_exclude_parents',
        ),       
      ), 
      'operations' => array(
        'field' => array(
          'title' => t('Projects quick links'),
          'help' => t('Display all quick links available for this project.'),
          'handler' => 'erpal_project_helper_handler_project_quicklinkgs_field',
        ),
      ),
    )
  );
}
