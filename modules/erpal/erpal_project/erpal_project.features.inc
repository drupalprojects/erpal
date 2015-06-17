<?php
/**
 * @file
 * erpal_project.features.inc
 */

/**
 * Implements hook_default_budget_type().
 */
function erpal_project_default_budget_type() {
  $items = array();
  $items['budget'] = entity_import('budget_type', '{
    "type" : "budget",
    "label" : "Budget",
    "weight" : 0,
    "description" : ""
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function erpal_project_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function erpal_project_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
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
    'global' => 0,
    'types' => array(
      0 => 'erpal_project',
    ),
    'flag_short' => 'Notifiy project',
    'flag_long' => 'Get notifications on changes of this project',
    'flag_message' => 'Project notified',
    'unflag_short' => 'Don\'t notifiy project',
    'unflag_long' => 'Unsubscribe from notifications on this project',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'teaser' => TRUE,
      'full' => TRUE,
    ),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
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
    'global' => 0,
    'types' => array(
      0 => 'erpal_task',
    ),
    'flag_short' => 'Notify task',
    'flag_long' => 'Get notifications on changes of this task',
    'flag_message' => 'Task notified',
    'unflag_short' => 'Don\'t notifiy task',
    'unflag_long' => 'Unsubscribe from notifications on this task',
    'unflag_message' => 'Task no more notified',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'teaser' => TRUE,
      'full' => TRUE,
    ),
    'show_as_field' => FALSE,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
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
  drupal_alter('node_info', $items);
  return $items;
}
