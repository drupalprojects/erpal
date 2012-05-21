<?php
/**
 * @file
 * feature_erpal_book.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_erpal_book_taxonomy_default_vocabularies() {
  return array(
    'book_tags' => array(
      'name' => 'Book tags',
      'machine_name' => 'book_tags',
      'description' => 'Tags for books and book pages',
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