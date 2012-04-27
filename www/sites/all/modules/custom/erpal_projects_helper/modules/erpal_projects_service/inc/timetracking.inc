<?php

/**
* @file all functions needed to integrate timetracking nodes with services module
*/

/**
* Create a new timetracking node by services module request
*/
function _erpal_projects_service_timetracking_create($timetracking) {
  module_load_include('inc', 'services', 'resources/node_resource');
  _node_resource_create($timetracking);
}

/**
* Check access for creating a timetracking node
*/
function _erpal_projects_service_timetrackings_access($op, $args) {
  module_load_include('inc', 'services', 'resources/node_resource');
  return _node_resource_access($op, $args); //this is the access handler function of the node resource of the services module
  //@todo check with node access
  
}