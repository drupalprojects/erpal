<?php
/**
* @file provides all functions to have dynamic local actions on pages
*/

//define some contexts
define('ERPAL_CONTEXT_PROJECTS', 'projects'); //projects list
define('ERPAL_CONTEXT_PROJECTS_GLOBAL', 'projects_global'); //we are in projects view or in a tab that belongs to the projects
define('ERPAL_CONTEXT_PROJECT', 'project');
define('ERPAL_CONTEXT_TASKS', 'tasks');
define('ERPAL_CONTEXT_TICKETS', 'tickets');
define('ERPAL_CONTEXT_TASK', 'task');
define('ERPAL_CONTEXT_TICKET', 'ticket');
define('ERPAL_CONTEXT_NODE_TIMETRACKINGS', 'node_timetrackings');


/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_projects_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();
  
  //CHECK PROJECT CONTEXT
  if (drupal_match_path($path, 'node/%*') ) {
    $node = isset($router_item['map'][1]) ? $router_item['map'][1] : false;
    
    if (!$node)
      return $contexts;
    
    //may be we have a ctools context
    if (get_class($node) == 'ctools_context')
      $node = $node->data;    
    
    switch ($node->type) {
      case 'erpal_project':
        $contexts[ERPAL_CONTEXT_PROJECT] = true;  
        $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
        
        break;
      case 'erpal_task':
        //task or ticket?
        $is_ticket = _erpal_projects_helper_is_ticket($node);
        if ($is_ticket) {
          $contexts[ERPAL_CONTEXT_TICKET] = true;  
          $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
        }  
        else {
          $contexts[ERPAL_CONTEXT_TASK] = true;  
          $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
        }
        break;
      case 'erpal_timetrscking':
        $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
        break;
    }
  }

  //CHECK PROJECTS Global CONTEXT
  if (drupal_match_path($path, 'projects/*')) {        
    $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;      
  }
  
  //CHECK NODE TIMETRACKINGS CONTEXT
  if ($path == 'node/%/timetracking') {        
    $contexts[ERPAL_CONTEXT_NODE_TIMETRACKINGS] = true;      
  }
  
  //CHECK PROJECTS list CONTEXT
  if ($path == 'projects/projects') {        
    $contexts[ERPAL_CONTEXT_PROJECTS] = true;      
  }

  //CHECK TASKS CONTEXT
  if ($path == 'node/%/tasks') {        
    $contexts[ERPAL_CONTEXT_TASKS] = true;      
  }
  
  //CHECK TASKS CONTEXT
  if ($path == 'node/%/tickets') {        
    $contexts[ERPAL_CONTEXT_TICKETS] = true;      
  }

  return $contexts;  
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_projects_helper_get_menu_parents($router_item) {
  $projects_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECTS_GLOBAL, $router_item);
  $project = _erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT, $router_item);
  
  if ($projects_global) {
    return 'projects/projects';
  }
}

/**
* Implements hook_dynamic_menu_items provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_projects_helper.module
*/
function erpal_projects_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {

  //projects list context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECTS, $router_item)) {    
    _erpal_projects_helper_projects_links($data);       
  } 
  
  //projects global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECTS_GLOBAL, $router_item)) {    
    _erpal_projects_helper_projects_global_links($data, $router_item);       
  } 
  
  //Node Timetracking Context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_NODE_TIMETRACKINGS, $router_item)) {
    $node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_projects_helper_node_timetrackings_links($data, $node); 
  }
  
  //project context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT, $router_item)) {    
    $project_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_projects_helper_project_links($data, $project_node, $router_item);       
  } 
  
  //Tasks context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TASKS, $router_item)) {    
    $project_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_projects_helper_tasks_links($data, $project_node, $router_item);       
  } 
  
  //Tickets context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TICKETS, $router_item)) {    
    $project_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_projects_helper_tickets_links($data, $project_node, $router_item);       
  } 
  
  //Task context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TASK, $router_item)) {    
    $task_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_projects_helper_task_links($data, $task_node, $router_item);       
  } 
  
  //Ticket context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TICKET, $router_item)) {    
    $ticket_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_projects_helper_ticket_links($data, $ticket_node, $router_item);       
  } 
  
}

/**
* Adds all projects context links
*/
function _erpal_projects_helper_projects_links(&$data) {
  //single project context
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Create a new project'), 'node/add/erpal-project', $query);
}

/**
* Show all Links on timetrackings list of a node
*/
function _erpal_projects_helper_node_timetrackings_links(&$data, $node) {
  $query = array('field_timetracking_subject' => $node->nid);  
  erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query); 
}

/**
* Adds all projects global context links
*/
function _erpal_projects_helper_projects_global_links(&$data, $router_item) {
  //single project context
  erpal_make_local_tab($data, t('Project list'), 'projects/projects');
  
  if (!_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT, $router_item)) {
    erpal_make_local_tab($data, t('Active timetrackings'), 'projects/timetrackings/tmp');
    erpal_make_local_tab($data, t('Timetrackings'), 'projects/timetrackings');  
  }
}

/**
* Add all tasks list links
*/
function _erpal_projects_helper_tasks_links(&$data, $project_node, $router_item=false) {
  
  $query = array('field_project_ref' => $project_node->nid, 'destination' => $_GET['q'], 'field_is_ticket' => 1);
  erpal_make_action($data, t('Add a task'), 'node/add/erpal-task', $query);
  
}

/**
* Add all tickets list links
*/
function _erpal_projects_helper_tickets_links(&$data, $project_node, $router_item=false) {
  
  $query = array('field_project_ref' => $project_node->nid, 'field_is_ticket' => 1, 'destination'=>$_GET['q']);
  erpal_make_action($data, t('Add a ticket'), 'node/add/erpal-task', $query);
}


/**
* Add all project links
*/
function _erpal_projects_helper_project_links(&$data, $project_node, $router_item=false) {

  erpal_make_action($data, t('Edit this project'), 'node/'.$project_node->nid.'/edit');  
}

/**
* Add all project links
*/
function _erpal_projects_helper_task_links(&$data, $task_node, $router_item=false) {
  
  erpal_make_action($data, t('Edit this task'), 'node/'.$task_node->nid.'/edit');
   
  $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id']; 
  $query = array('field_parent' => $task_node->nid, 'field_project_ref' => $project_nid);  
  erpal_make_action($data, t('Create a subtask'), 'node/add/erpal-task', $query);
   
  $query = array('field_timetracking_subject' => $task_node->nid);  
  erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query); 
  
  erpal_make_action($data, t('Print'), 'projects/project/task/'.$task_node->nid.'/print'); 
   
  erpal_make_local_tab($data, t('Tasks'), 'node/'.$project_nid.'/tasks');   

  if (user_access('use quick timetracking')) {
    $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($task_node->nid);
    $data['actions']['output'][] = array(
      '#markup' => '<li>'.$timetracking_button.'</li>',
    );    
  }
}

/**
* Add all project links
*/
function _erpal_projects_helper_ticket_links(&$data, $ticket_node, $router_item=false) {
    
  erpal_make_action($data, t('Edit this ticket'), 'node/'.$ticket_node->nid.'/edit');
   
  $project_nid = $ticket_node->field_project_ref[LANGUAGE_NONE][0]['target_id']; 
  $query = array('field_parent' => $ticket_node->nid, 'field_project_ref' => $project_nid, 'field_is_ticket' => 1);  
  erpal_make_action($data, t('Create a subticket'), 'node/add/erpal-task', $query);
   
  $query = array('field_timetracking_subject' => $ticket_node->nid);  
  erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query);
  
  erpal_make_action($data, t('Print'), 'projects/project/task/'.$ticket_node->nid.'/print'); 
   
  erpal_make_local_tab($data, t('Tickets'), 'node/'.$project_nid.'/tickets');    
   
  if (user_access('use quick timetracking')) {
    $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($ticket_node->nid);
    $data['actions']['output'][] = array(
      '#markup' => '<li>'.$timetracking_button.'</li>',
    );    
  }
}

