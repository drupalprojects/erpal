<?php
/**
 * @file
 * feature_erpal_crm.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_erpal_crm_taxonomy_default_vocabularies() {
  return array(
    'activity_status_terms' => array(
      'name' => 'Activity status terms',
      'machine_name' => 'activity_status_terms',
      'description' => 'Terms for activity status',
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
