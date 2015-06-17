<?php

/**
 * @file
 * Common functions for the erpal_contacts_importer module
 */

/**
 * Return a taxonomy term with the given name and taxonomy. Creates the term if
 * it doesn't exist.
 * @param string $name Term name
 * @param string $taxonomy Taxonomy name
 * @return mixed|stdClass Taxonomy term object
 */
function _erpal_contacts_importer_make_sure_term_exists($name, $taxonomy){

  $term = taxonomy_get_term_by_name($name, $taxonomy);
  $term = array_shift($term);

  if(empty($term)){
    $vocabulary = taxonomy_vocabulary_machine_name_load($taxonomy);
    $term = new stdClass();
    $term->name = $name;
    $term->vid = $vocabulary->vid;
    taxonomy_term_save($term);
  }
  return $term;
}
/**
 * Checks if the given entity has a field with a given value
 * @param stdClass $entity Entity to check
 * @param string $type ('term' | 'text') Field type to check
 * @param string $name Field name
 * @param string $value Value to check
 * @return bool
 */
function _erpal_contacts_importer_compare_field($entity, $type, $name, $value = ''){
  $field = $entity->$name;
  if(empty($value)){
    return !isset($field[LANGUAGE_NONE][0]);
  }
  switch($type){
    case 'term':
      if(isset($field[LANGUAGE_NONE])){
        $term = taxonomy_term_load($field[LANGUAGE_NONE][0]['tid']);
        return $term->name == $value;
      }
      break;
    case 'text':
      if(isset($field[LANGUAGE_NONE])){
        return $field[LANGUAGE_NONE][0]['value'] == $value;
      }
      break;
  }
  return false;
}