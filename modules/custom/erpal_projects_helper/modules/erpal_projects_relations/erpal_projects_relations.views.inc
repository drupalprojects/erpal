<?php

/**
 * Implements of hook_views_data().
 */
function erpal_projects_relations_views_data() {
  return array(
    'users' => array(
      'erpal_projects_relations' => array(
        'group' => t('User'),
        'title' => t('Belongs to project team'),
        'help' => t('User belongs to current project'),
        'filter' => array(
          'handler' => 'erpal_projects_relations_handler_erpal_projects_relations_filter'
        ),
      ),
    ),
    'field_data_field_task_assigned_users' => array(
      'erpal_projects_relations_assigned' => array(
        'group' => t('Content'),
        'title' => t('Assigned to users of project team'),
        'help' => t('Shows users of current project team'),
        'filter' => array(
          'handler' => 'erpal_projects_relations_handler_erpal_projects_relations_team_filter'
        ),
      ),
    ),
  );
}
