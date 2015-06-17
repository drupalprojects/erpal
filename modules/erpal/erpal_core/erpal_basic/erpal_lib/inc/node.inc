<?php

/**
* File contains helper functions that work with node data
*/

/**
* Helper function to get the title of a node
* @param $nids a single nid or an array with nids
* @param boolean $skipp_node_access if TRUE no node_access tag will be added to the query
* @return an array with key = nid and value = title
*/
function erpal_lib_helper_node_titles($nids, $skipp_node_access=FALSE) {
  if (is_numeric($nids))
    $nids = array($nids);
  
  if (!count($nids)) {
    return array();
  }
  
  $query = db_select('node', 'n');
  $query
    ->fields('n', array('nid', 'title'))
    ->condition('n.nid', $nids);
    
  if (!$skipp_node_access) {
    $query->addTag('node_access');
  }
  
  $result = $query->execute();
  
  $nodes = array();
  foreach ($result as $record) {
    $nodes[$record->nid] = $record->title;
  }  
  
  return $nodes;
}

/**
* Helper function to get the base data of a nid ore many nids
* @param $nids a single nid or an array with nids
* @return an array with key = nid and value = title
*/
function erpal_lib_helper_node_base_data($nids, $skipp_access_check=false) {
  if (is_numeric($nids))
    $nids = array($nids);
  
  if (!count($nids))
	return array();  //no result if no node is given
  
  $query = db_select('node', 'n');
  $query
    ->fields('n')
    ->condition('n.nid', $nids);
    
  if (!$skipp_access_check) {  
    $query->addTag('node_access');
  }
  
  $result = $query->execute();
  
  $nodes = array();
  foreach ($result as $record) {
    $nodes[$record->nid] = $record;
  }  
  
  return $nodes;
}


/**
* Get node field value, API function that can be used by other modules
* @param $nid the nid of the node we want to get the field value from
* @param $field_name the name of the field we want to get the value from
* @param $field_col the column of the field to return the value from (mostly 'value' or 'target_id')
*/ 
function _erpal_lib_helper_get_field_value($nid, $field_name, $field_col='value') {
  $field_info = field_info_field($field_name);
  $sql_arr = $field_info['storage']['details']['sql']['FIELD_LOAD_CURRENT']; //get the current vid
  $field_name = array_keys($sql_arr);
  $field_name_table = $field_name[0];
  $value_field = $sql_arr[$field_name_table][$field_col];

  $query = db_select($field_name_table, 'f');
  $query->fields('f', array($value_field));
  $query->leftJoin('node', 'n', 'f.revision_id = n.vid');
  $query->condition('n.nid', $nid);
  
  $res = $query->execute()->fetchAssoc();
  return !empty($res[$value_field]) ? $res[$value_field] : false;
}

/**
* Saves the single field field only, not the complete node
*/
function _erpal_lib_helper_save_new_single_field_value($nid, $field_name, $new_value, $column='value') {
  $node_base_data = erpal_lib_helper_node_base_data(array($nid));
  $node = $node_base_data[$nid];
 
  //save only the one field
  $info = field_info_field($field_name);
  $fields = array($info['id']); 

  //Execute the storage function
  $node->{$field_name}[LANGUAGE_NONE][0][$column] = $new_value;   
  field_sql_storage_field_storage_write('node', $node, 'update', $fields);
  entity_get_controller('node')->resetCache(array($nid));  //clear cache
}

/**
* Load a node by a given title
* @param string $title the title of the node to each for
* @param string $type the type of the node to search for
*/
function _erpal_lib_get_node_by_title($title, $type) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $type)
    ->propertyCondition('title', $title)
    ->addMetaData('account', user_load(1)); // Run the query as user 1.
  $result = $query->execute();
  $node = false;
  if (isset($result['node'])) {
    $nids = array_keys($result['node']);
    $nid = reset($nids); //only one nid
    $node = node_load($nid);
  }
  
  return $node;
}
  