<?php
/**
 * @file
 * erpal_profile.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function erpal_profile_taxonomy_default_vocabularies() {
  return array(
    'project_tags' => array(
      'name' => 'Project Tags',
      'machine_name' => 'project_tags',
      'description' => 'Free tags for tasks and projects',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
