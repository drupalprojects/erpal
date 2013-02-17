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
    $taxonomy = taxonomy_vocabulary_machine_name_load( mysql_real_escape_string($vocabname) );

    $tree = taxonomy_get_tree($taxonomy->vid);

    $tags_out = array();

    if (!empty($tree)) {
      //prepare for output!
      foreach ($tree as $term) {
        $term_out['tid'] = $term->tid;
        $term_out['name'] = $term->name;

        $tags_out[] = $term_out;
      }
    }

    return $tags_out;
  }
}

