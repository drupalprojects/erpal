<?php

/**
 * @file
 * Contains Entity API hooks and callbacks.
 */

/**
 * Implements hook_entity_property_info_alter().
 */
function erpal_project_entity_property_info_alter(&$info) {
  $info['node']['bundles']['erpal_timetracking']['properties']['project'] = array(
    'label' => t("Project of Timetracking"),
    'description' => t("The project of the timetracking"),
    'getter callback' => 'erpal_project_entity_get_properties',
    'type' => 'node',
  );
}

/**
 * Entity API property 'pb_join' getter callback.
 *
 * Support for %term:pb-join:name and %term:pb-join:url tokens.
 */
function erpal_project_entity_get_properties($data, array $options, $name, $type, $info) {

  if (empty($data)) {
    return;
  }
  
  if ($name == 'project' && $type == 'node') {
    $timetracking_node = $data;
    $project_nid = _erpal_projects_helper_has_project($timetracking_node);
    return node_load($project_nid);
  }

}
