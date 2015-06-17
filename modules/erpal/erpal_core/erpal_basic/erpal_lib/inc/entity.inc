<?php

/**
 * Some library functions dealing with entities
 */

/**
 * Checks, if an entity of a given type already exits according to the given criteria
 * @param $field_criteria an array with values to check if a contact exists
 */
function erpal_lib_helper_entity_check_exits($field_criteria, $entity_type, $bundle) {
  
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $entity_type)
    ->entityCondition('bundle', $bundle)    
    ->addMetaData('account', user_load(1)); // Run the query as user 1.

  foreach ($field_criteria as $field_name => $field) {
    if (!is_array($field)) {
      //it must be a property
      $query->propertyCondition($field_name, $field);
    } else {
      //its a field
      $query->fieldCondition($field_name, $field['field'], $field['value']);    
    }    
  }
  
  $result = $query->execute();

  $id = false;
  $entity_id = false;
  if (isset($result[$entity_type])) {
    $ids = array_keys($result[$entity_type]);
    $entity_id = reset($ids);
  }

  return $entity_id;
}

/**
 * Returns all children in deep search of a given type with a given parent field
 * CAUTION: Currently works ONLY FOR NODES (because of type query)

 * @param parent_id the id field that specifies the parent id where to start
 * @param $parent_field the field name that specifies the parent in each dataset
 * @param $child_types an array that defines wich child types we want to get (NODE TYPES)
 * @param $deep_search if set true, the function will start a recursion to get all children by a parent.
 * @paran $flat if true, the result array will not keep the tree structure but will  put all nids in one flat array
 */
function erpal_lib_helper_children_by_parent($parent_id, $parent_field, $child_types=array(), $deep_search=false, $flat=false) {
  
  //no start an entity field query for that
  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->fieldCondition($parent_field, 'target_id', $parent_id, '=')
    ->addMetaData('account', user_load(1)); // Run the query as user 1.
  
  //maybe add child type validation
  if (count($child_types)) {
    $query->entityCondition('bundle', $child_types);
  }

  $result = $query->execute();
  
  $nids = array();
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
  }
 
  //now start recursion if there are still children.   
  $new_nids = array();
  if (count($nids) && $deep_search) {    
    foreach ($nids as $delta => $nid) {
          
      $sub_nids = erpal_lib_helper_children_by_parent($nid, $parent_field, $child_types, $deep_search, $flat);

      if ($flat) {
        $new_nids = array_merge($new_nids, $sub_nids);
      } else {
        $new_nids[$nid] = $sub_nids;
      }
    }  
  }

  if ($deep_search && $flat)
    return array_merge($nids, $new_nids);
  else    
    return $new_nids;
 
}

/**
 * Returns all parents in deep search of a given type with a given parent field
 * CAUTION: Currently works ONLY FOR NODES (because of type query)

 * @param parent_id the id field that specifies the child id where to start
 * @param $parent_field the field name that specifies the parent in each dataset (and in this function we want all nodes that are referenced by this field in the current_nid node)
 * @param $parent_types an array that defines wich parent types we want to get (NODE TYPES)
 * @param $deep_search if set true, the function will start a recursion to get all parents by a child.
 * @paran $flat if true, the result array will not keep the tree structure but will  put all nids in one flat array
 */
function erpal_lib_helper_parents_by_children($current_id, $parent_field, $parent_types=array(), $deep_search=false, $flat=false) {
 
  $field_info = field_info_field($parent_field);
  $sql_arr = $field_info['storage']['details']['sql']['FIELD_LOAD_CURRENT'];
  $field_name = array_keys($sql_arr);
  $field_parent_table = $field_name[0];
  $value_field_parent = $sql_arr[$field_parent_table]['target_id'];
  
  $query = db_select('node',"n");
  $query->fields('np', array('nid'));
  $query->leftJoin($field_parent_table, 'p', 'n.vid = p.revision_id');
  $query->leftJoin('node', 'np', 'np.nid = p.'.$value_field_parent);
  $query->condition('n.nid', $current_id);
  
  //may be filter only parent nodes of a given type
  if (count($parent_types)) { 
    $query->condition('np.type', $parent_types);
  }

  $result = $query->execute();  
  $nids = array();
  
  while ($record = $result->fetchObject()) {
    $nids[] = $record->nid;
  }

  //now start recursion if there are still children.  
  $new_nids = array();
  if (count($nids) && $deep_search) {    
    foreach ($nids as $delta => $nid) {
          
      $sub_nids = erpal_lib_helper_parents_by_children($nid, $parent_field, $parent_types, $deep_search, $flat);

      if ($flat) {
        $new_nids = array_merge($new_nids, $sub_nids);
      } else {
        $new_nids[$nid] = $sub_nids;
      }
    }  
  }

  if ($deep_search && $flat)
    return array_merge($nids, $new_nids);
  else    
    return $new_nids;
}