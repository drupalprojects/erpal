<?php
/**
 * @file
 * erpal_project_ui.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function erpal_project_ui_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'project_calendar_view_breadcrumb';
  $path_breadcrumb->name = 'Project calendar view breadcrumb';
  $path_breadcrumb->path = 'node/%node/calendar';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:title',
      2 => 'Calendar',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:nid',
      2 => 'node/%node:nid/calendar',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -89;
  $export['project_calendar_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'project_files_view_breadcrumb';
  $path_breadcrumb->name = 'Project files view breadcrumb';
  $path_breadcrumb->path = 'node/%node/files';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:title',
      2 => 'Files',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:nid',
      2 => 'node/%node:nid/files',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -87;
  $export['project_files_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'project_node_breadcrumb';
  $path_breadcrumb->name = 'Project node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -95;
  $export['project_node_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'project_timetrackings_view_breadcrumb';
  $path_breadcrumb->name = 'Project timetrackings view breadcrumb';
  $path_breadcrumb->path = 'node/%node/timetracking';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:title',
      2 => 'Timetracking',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:nid',
      2 => 'node/%node:nid/timetracking',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -91;
  $export['project_timetrackings_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'projects_view_breadcrumb';
  $path_breadcrumb->name = 'Projects view breadcrumb';
  $path_breadcrumb->path = 'projects/projects';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
    ),
    'paths' => array(
      0 => 'projects/projects',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -96;
  $export['projects_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'task_node_breadcrumb';
  $path_breadcrumb->name = 'Task node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:field-project-ref:title',
      2 => '%node:field-parent:title',
      3 => '%node:title',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:field-project-ref:nid',
      2 => 'node/%node:field-parent:nid',
      3 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_task' => 'erpal_task',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -93;
  $export['task_node_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'tasks_view_breadcrumb';
  $path_breadcrumb->name = 'Tasks view breadcrumb';
  $path_breadcrumb->path = 'node/%node/tasks';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:title',
      2 => 'Tasks',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:nid',
      2 => 'node/%node:nid/tasks',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -94;
  $export['tasks_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'tickets_view_breadcrumb';
  $path_breadcrumb->name = 'Tickets view breadcrumb';
  $path_breadcrumb->path = 'node/%node/tickets';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:title',
      2 => 'Tickets',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:nid',
      2 => 'node/%node:nid/tasks',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_project' => 'erpal_project',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -92;
  $export['tickets_view_breadcrumb'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'timetracking_node_breadcrumb';
  $path_breadcrumb->name = 'Timetracking node breadcrumb';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Projects',
      1 => '%node:project:title',
      2 => '%node:field-timetracking-subject:title',
      3 => '%node:title',
    ),
    'paths' => array(
      0 => 'projects/projects',
      1 => 'node/%node:project:nid',
      2 => 'node/%node:field-timetracking-subject:nid',
      3 => 'node/%node:nid',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'erpal_timetracking' => 'erpal_timetracking',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -90;
  $export['timetracking_node_breadcrumb'] = $path_breadcrumb;

  return $export;
}
