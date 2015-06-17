<?php
/**
 * @file:
 *   Contains code for the works_at relation mapper
 */

/**
 * Implements hook_feeds_after_save().
 * Relations can only be created after the main node is saved
 * @param $source
 * @param $entity
 * @param $item
 * @param $entity_id
 */
function erpal_contacts_importer_feeds_after_save($source, $entity, $item, $entity_id) {
  if(property_exists($entity, 'type') && $entity->type == 'erpal_contact'){
    $value = drupal_static('erpal_contacts_importer_feeds_processor_works_at_target');
    if(isset($value)){

      $endpoints = array(
        array('entity_bundle' => 'erpal_contact', 'entity_type' => 'node', 'entity_id' => $entity->nid, 'r_index' => 0),
        array('entity_bundle' => 'erpal_contact', 'entity_type' => 'node', 'entity_id' => $value['nid'], 'r_index' => 1),

      );

      $relation = relation_create('works_at', $endpoints);
      // get term or create it
      if(!empty($value['position'])){
        $term = _erpal_contacts_importer_make_sure_term_exists($value['position'], 'company_relation_tags');
        $relation->field_work_at_rel_tags[LANGUAGE_NONE][0]['tid'] = $term->tid;
      }

      $relation->field_date[LANGUAGE_NONE][0] = array(
        'value' => date('Y-m-d H:i:s', strtotime('now')),
        'value2' => NULL,
        'timezone' => 'UTC',
        'timezone_db' => 'UTC',
      );

      $user = user_load(1);
      relation_save($relation, $user);
      drupal_static_reset('erpal_contacts_importer_feeds_processor_works_at_target');
    }
  }
}

/**
 * Maps the works at relation to the given target
 * @param $source
 * @param $entity
 * @param $target
 * @param $value
 * @param array $mapping
 */
function erpal_contacts_importer_feeds_processor_works_at_target($source, $entity, $target, $value, $mapping = array()){

  if(!isset($value[0]) || empty($value[0])){
    return;
  }

  $company = $value[0];
  $position = isset($value[1]) ? $value[1] : '';

  // Load node to link with
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'erpal_contact');
  $query->fieldCondition('field_company_name', 'value', $value[0], '=');
  $result = $query->execute();

  // If node to link does not exist return
  if(empty($result)){
    watchdog('erpal_contacts_importer', t('Relation to "'. $company .'" can not be created. Node not found'));
    return;
  }

  $target = reset($result['node']);

  $found = false;

  // if node is updated
  if(!empty($entity->nid)){

    // get relations attached to this node
    $query = relation_query('node', $entity->nid);
    $query->propertyCondition('relation_type', 'works_at');
    $result = $query->execute();

    if(!empty($result)){
      foreach($result as $relation){
        $relation = relation_load($relation->rid);
        if(_erpal_contacts_importer_compare_field($relation, 'term', 'field_work_at_rel_tags', $value[1])
          && ($relation->endpoints[LANGUAGE_NONE][1]['entity_id'] == $target->nid)){
          $found = true;
          break;
        }
      }
    }
  }
  if(!$found) {
    //create static variable to handle the creation of the relation in hook_feeds_after_save
    $relation = &drupal_static(__FUNCTION__);
    $relation = array(
      'nid' => $target->nid,
      'position' => $position,
    );
  }
}