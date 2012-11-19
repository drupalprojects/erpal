<?php
/**
 * @file
 * feature_erpal_project_basic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_erpal_project_basic_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "features_plumber" && $api == "features_plumber_records") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "rel" && $api == "rel") {
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
 * Implements hook_views_api().
 */
function feature_erpal_project_basic_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function feature_erpal_project_basic_flag_default_flags() {
  $flags = array();
  // Exported flag: "Project subscriptions".
  $flags['project_subscriptions'] = array(
    'entity_type' => 'node',
    'title' => 'Project subscriptions',
    'global' => '0',
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
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'i18n' => 0,
    'module' => 'feature_erpal_project_basic',
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
    'flag_short' => 'Notify task',
    'flag_long' => 'Get notifications on changes of this task',
    'flag_message' => 'Task notified',
    'unflag_short' => 'Don\'t notifiy task',
    'unflag_long' => 'Unsubscribe from notifications on this task',
    'unflag_message' => 'Task no more notified',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'i18n' => 0,
    'module' => 'feature_erpal_project_basic',
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
function feature_erpal_project_basic_node_info() {
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
