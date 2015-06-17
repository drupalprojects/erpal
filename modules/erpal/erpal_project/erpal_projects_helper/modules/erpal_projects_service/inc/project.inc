<?php

/**
* @file all functions needed to make erpal_projects accessible by services
* @author Oskar Bechtold <bechtold@brightsolutions.de>
* @copyright (c) 2013
*/


/**
 * Callback for retrieving single erpal_project resources.
 *
 * @param int $id the nid of the project node that should be retrieved
 * @param bool $inlude_children, instead of url, include short version of children, defaults to false
 * @return object
 */
function _erpal_projects_service_project_retrieve($id, $include_children=FALSE) {
  $project_node = _erpal_projects_service_project_out( (int)$id,TRUE, (bool)$include_children);

  return $project_node;
}

/**
* Callback for returning a list of projects respecting given filters
* @param int $start number to start list from, defaults to 0
* @param int $count number of item to return, defaults to PHP_INT_MAX
* @param int $changed_since UTC timestamp, deliver only tasks changed after that timestamp , defaults to 0
* @param bool $details whether tasks will be returned with details , defaults to false
* @return array array of tasks, prepared for output
*/
function _erpal_projects_service_project_index($start=0, $count=PHP_INT_MAX, $changed_since=0, $details=false) {
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
      $projects_out[] = _erpal_projects_service_project_out($nid,$details);
    }
  }

  return $projects_out;
}


/**
 * retrieves a project node and returns only simple data
 * @param int $nid the node id of the project to return
 * @param bool $details whether or not to return the project with details
 * @param bool $include_children wheter or not no include children
 * @return array the project prepared for output
 * @author  Oskar Bechtold
 */
function _erpal_projects_service_project_out($nid, $details=FALSE, $include_children=FALSE) {
  $project = node_load($nid);
  $project_out = array();
  $project_out['title'] = $project->title;
  $project_out['project'] = url('rest/projects/project/'.$project->nid, array('absolute'=>TRUE) );
  if($details){
    if($include_children){
      module_load_include('inc', 'erpal_projects_service', 'inc/task');
      $tasks= _erpal_projects_service_task_index(0, PHP_INT_MAX, 0, false, $nid);
      $project_out['tasks'] = $tasks;
    }else{
      $project_out['tasks'] = url('rest/projects/task',
              array('absolute'=>TRUE,
                        'query'=>array('project'=>$project->nid)) );
    }
    $project_out['description'] = strip_tags($project->body[LANGUAGE_NONE][0]['value']);
    $project_out['created'] = (int)$project->created;
    $project_out['changed'] = (int)$project->changed;
    $project_out['status'] = (int)$project->field_project_status_term[LANGUAGE_NONE][0]['tid'];
    $project_out['priority'] = (int)$project->field_priority_term[LANGUAGE_NONE][0]['tid'];

    $project_out['nid'] = $nid;
    $project_out['url']['dev'] = !empty($project->field_development_url[LANGUAGE_NONE][0]['value']) ? $project->field_development_url[LANGUAGE_NONE][0]['value'] : false;
    $project_out['url']['live'] = !empty($project->field_live_url[LANGUAGE_NONE][0]['value']) ? $project->field_live_url[LANGUAGE_NONE][0]['value'] : false;
    $project_out['url']['stage'] = !empty($project->field_stage_url[LANGUAGE_NONE][0]['value']) ? $project->field_stage_url[LANGUAGE_NONE][0]['value'] : false;
  }

  return $project_out;
}

/**
* Access callback for retrieving a erpal_project object
*/
function _erpal_projects_service_project_access($op, $args) {
  module_load_include('inc', 'services', 'resources/node_resource');
  return _node_resource_access($op, $args); //this is the access handler function of the node resource of the services module
  //@todo check with node access
}

