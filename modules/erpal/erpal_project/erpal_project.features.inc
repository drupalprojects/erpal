<?php
/**
 * @file
 * erpal_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_project_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function erpal_project_flag_default_flags() {
  $flags = array();
  // Exported flag: "Project subscriptions".
  $flags['project_subscriptions'] = array(
    'entity_type' => 'node',
    'title' => 'Project subscriptions',
    'global' => '0',
    'types' => array(
      0 => 'erpal_project',
    ),
    'flag_short' => '',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => '',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_on_form' => FALSE,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'show_on_page' => TRUE,
    'show_on_teaser' => TRUE,
    'i18n' => 0,
    'module' => 'erpal_project',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Task subscriptions".
  $flags['task_subscriptions'] = array(
    'entity_type' => 'node',
    'title' => 'Task subscriptions',
    'global' => '0',
    'types' => array(
      0 => 'erpal_task',
    ),
    'flag_short' => '',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => '',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_on_form' => FALSE,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'show_on_page' => TRUE,
    'show_on_teaser' => TRUE,
    'i18n' => 0,
    'module' => 'erpal_project',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function erpal_project_node_info() {
  $items = array(
    'erpal_project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A Project in ERPAL'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'erpal_task' => array(
      'name' => t('Task'),
      'base' => 'node_content',
      'description' => t('Basic content type for tasks'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'erpal_timetracking' => array(
      'name' => t('Timetracking'),
      'base' => 'node_content',
      'description' => t('Content type to create timetracking to nodes'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
