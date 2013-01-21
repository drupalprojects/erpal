<?php

/**
* @file all functions needed for make erpal_projects accessible by services
* @author Oskar Bechtold <bechtold@brightsolutions.de>
* @copyright (c) 2013
*/

/**
 * Callback for retrieving single erpal_project resources.
 *
 * @param int $id the nid of the project node that should be retrieved
 * @return object
 */
function _erpal_projects_service_project_retrieve($id) {
  $project_node = _erpal_projects_service_project_out( (int)$id,TRUE);

  return $project_node;
}

/**
* Callback for returning a list of projects given filters
* @param int $start Deliver data from nth element, defaults to 0.
 * @param int $count Delive n elements
 * @param int $changed_since Deliver all elemets changed after date  x. Format: UNIX timestamp in UTC
 * @param bool $details Deliver elements with more detail
*/
function _erpal_projects_service_project_index($start=0, $count=PHP_INT_MAX, $changed_since=0, $details=false, $include_children=  FALSE) {  
  module_load_include('inc', 'erpal_projects_helper', 'inc/projects');

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', 'erpal_project')
    ->range( (int)$start, (int)$count)
    ->propertyCondition('changed',(int)$changed_since,'>=');

  $entities = $query->execute();

  $projects_out = array();

  if (!empty($entities['node'])) {
    //prepare for output!
    foreach (array_keys($entities['node']) as $nid) {
      $projects_out[] = _erpal_projects_service_project_out($nid,$details,$include_children);
    }
  }

  return $projects_out;
}


/**
 * retrieves a project node and returns only simple data
 *
 * @return array with title and url
 * @author  Oskar Bechtold
 */
function _erpal_projects_service_project_out($nid, $details=FALSE, $include_children=FALSE) {
  $project = node_load($nid);
//  dpm($project);
  $project_out = array();
  $project_out['title'] = $project->title;
  $project_out['project'] = url('rest/projects/project/'.$project->nid, array('absolute'=>TRUE) );
  if($details){
    $project_out['tasks'] = url('rest/projects/task',
            array('absolute'=>TRUE,
                      'query'=>array('project'=>$project->nid)) );
    $project_out['description'] = $project->body[LANGUAGE_NONE][0]['value'];
    $project_out['created'] = $project->created;
    $project_out['changed'] = $project->changed;
    
  }
  return $project_out;
}

/**
* Access callback for retrieving a erpal_project object
*/
function _erpal_projects_service_project_access($op, $args) {
  global $user;
  $access = FALSE;

  switch ($op) {
    case 'view':      
      $project = _erpal_projects_service_get_project($args[0], true);

      if (!$project->nid)
        return false;
       
      $access = $project->nid > 0;  //if node_load succeeds, the user has access to load the node.
      //@todo test this with og integration!
      break;
    case 'update':
      $access = FALSE; //no update per remote
      break;
    case 'delete':
      $access = FALSE; //no delete per remote
      break;
  }
  
  return $access;
}

/**
* Loads and returns a project with a given id
* @param int $id the id of the project
* @return object the node, if the node isnt a project node, false will be returned
* @param $return_real_node if true the node will be returned, otherwise a prepared output
*/
function _erpal_projects_service_get_project($id, $return_real_node=true) {
  $project_node = node_load($id);

  if ($project_node->type != 'erpal_project')
    return false;

  if ($return_real_node)
    return $project_node;
    
  $project_node = _erpal_projects_service_project_out($project_node);
  return $project_node;
}

///**
//* Prepares a project node to an easy output
//*/
//function _erpal_projects_service_project_out($project_node) {
//  $customer_nid = 0;
//  if (isset($project_node->field_customer_ref[LANGUAGE_NONE][0]['target_id']))
//    $customer_nid = $project_node->field_customer_ref[LANGUAGE_NONE][0]['target_id'];
//
//  $customer_title = '';
//  if ($customer_nid) {
//    $customer_node = node_load($customer_nid);
//    $customer_title = $customer_node->title;
//  }
//
//  //get project status term
//  $status_tid = isset($project_node->field_project_status_term[LANGUAGE_NONE][0]['tid']) ? $project_node->field_project_status_term[LANGUAGE_NONE][0]['tid'] : false;
//  
//  $status = '';
//  if ($status_tid) {
//    $term = taxonomy_term_load($status_tid);
//    $status = $term->name;
//  }
//  
//  return array(
//    'id' => $project_node->nid,
//    'title' => $project_node->title,
//    'status' => $status,
//    'date_start' => isset($project_node->field_date[LANGUAGE_NONE][0]['value']) ? $project_node->field_date[LANGUAGE_NONE][0]['value'] : 0,
//    'date_end' => isset($project_node->field_date[LANGUAGE_NONE][0]['value2']) ? $project_node->field_date[LANGUAGE_NONE][0]['value2'] : 0,
//    'body' => $project_node->body[LANGUAGE_NONE][0]['value'],
//    'customer' => $customer_title,
//  );
//}
