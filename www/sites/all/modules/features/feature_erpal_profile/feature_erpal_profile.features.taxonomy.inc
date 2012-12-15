<?php
/**
 * @file
 * feature_erpal_profile.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_erpal_profile_taxonomy_default_vocabularies() {
  return array(
    'project_tags' => array(
      'name' => 'Project Tags',
      'machine_name' => 'project_tags',
      'description' => 'Free tags for tasks and projects',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
