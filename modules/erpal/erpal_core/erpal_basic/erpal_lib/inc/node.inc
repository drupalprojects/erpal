<?php

/**
* File contains helper functions that work with node data
*/

/**
* Helper function to get the title of a node
* @param $nids a single nid or an array with nids
* @return an array with key = nid and value = title
*/
function erpal_lib_helper_node_titles($nids) {
  if (is_numeric($nids))
    $nids = array($nids);
  
  $query = db_select('node', 'n');
  $query
    ->fields('n', array('nid', 'title'))
    ->condition('n.nid', $nids)
    ->addTag('node_access');
  
  $result = $query->execute();
  
  $nodes = array();
  foreach ($result as $record) {
    $nodes[$record->nid] = $record->title;
  }  
  
  return $nodes;
}