<?php
/**
 * @file
 * erpal_project.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function erpal_project_taxonomy_default_vocabularies() {
  return array(
    'priority_terms' => array(
      'name' => 'Priority terms',
      'machine_name' => 'priority_terms',
      'description' => 'Terms for tasks priorities',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'project_role_tags' => array(
      'name' => 'Project role relation tags',
      'machine_name' => 'project_role_tags',
      'description' => 'Describes the roles an contact has in a project',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'project_status_terms' => array(
      'name' => 'Project status terms',
      'machine_name' => 'project_status_terms',
      'description' => 'Terms for project status',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'task_status_terms' => array(
      'name' => 'Task status terms',
      'machine_name' => 'task_status_terms',
      'description' => 'Terms for task status',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'task_type_terms' => array(
      'name' => 'Task type terms',
      'machine_name' => 'task_type_terms',
      'description' => 'Terms for task types',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
