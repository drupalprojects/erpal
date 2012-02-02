<?php
/**
 * @file
 * feature_erpal_project_basic.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_erpal_project_basic_taxonomy_default_vocabularies() {
  return array(
    'project_role_tags' => array(
      'name' => 'Project role relation tags',
      'machine_name' => 'project_role_tags',
      'description' => 'Describes the roles an contact has in a project',
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
