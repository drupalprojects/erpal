<?php

/**
* @file all functions needed to make erpal_taxonomy accessible by services
* @author Oskar Bechtold <bechtold@brightsolutions.de>
* @copyright (c) 2013
*/

/**
 * Callback for returning a list of erpal specific taxonomy terms
 * @param string $vocabname the machine name of the vocabulary, to get the taxonomy terms
 * @return array taxonomy terms prepared for output
 */
function _erpal_projects_service_taxonomy_index($vocabname) {
  if ($vocabname != 'FALSE') {
    $taxonomy = taxonomy_vocabulary_machine_name_load( $vocabname );

    $tree = taxonomy_get_tree($taxonomy->vid);

    $tags_out = array();

    if (!empty($tree)) {
      //prepare for output!
      foreach ($tree as $term) {
        $full_term = taxonomy_term_load($term->tid);
        $term_out['tid'] = (int)$term->tid;
        $term_out['name'] = $term->name;
        $term_image = field_get_items('taxonomy_term', $full_term, 'field_term_image');
        if(!empty($term_image)){
          $term_out['term_image'] = file_create_url($term_image[0]['uri']);
        }
        $term_simple_process_status = field_get_items('taxonomy_term', $full_term, 'field_simple_process_status');
        if(!empty($term_simple_process_status)){
          $term_out['term_simple_process_status'] = $term_simple_process_status[0]['value'];
        }
        $tags_out[] = $term_out;
      }
    }

    return $tags_out;
  }
}
