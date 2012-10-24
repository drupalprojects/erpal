<?php
/**
* @file provides all functions to have dynamic local actions on pages
*/

//define some contexts
define('ERPAL_CONTEXT_PROJECTS', 'projects');
define('ERPAL_CONTEXT_PROJECT', 'project');
define('ERPAL_CONTEXT_TASKS', 'tasks');
define('ERPAL_CONTEXT_TICKETS', 'tickets');
define('ERPAL_CONTEXT_TASK', 'task');
define('ERPAL_CONTEXT_TICKET', 'ticket');

/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_projects_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();
  
  //CHECK PROJECT CONTEXT
  if ($path == 'node/%') {
    $node = $router_item['map'][1];
    
    switch ($node->type) {
      case 'erpal_project':
        $contexts[ERPAL_CONTEXT_PROJECT] = true;
        break;
      case 'erpal_task':
        //task or ticket?
        $is_ticket = _erpal_projects_helper_is_ticket($node);
        if ($is_ticket)
          $contexts[ERPAL_CONTEXT_TICKET] = true;    
        else
          $contexts[ERPAL_CONTEXT_TASK] = true;  
        break;
    }
  }

  //CHECK PROJECTS CONTEXT
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
* Returns all dynamic contextual menu items, @see erpal_projects_helper.module
*/
function _erpal_projects_helper_dynamic_menu_items(&$data, $router_item, $root_path) {

  //projects context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECTS, $router_item)) {    
    _erpal_projects_helper_projects_links($data);       
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
  $query = array('field_parent' => $ticket_node->nid, 'field_project_ref' => $project_nid);  
  erpal_make_action($data, t('Create a subticket'), 'node/add/erpal-task', $query);
   
  if (user_access('use quick timetracking')) {
    $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($ticket_node->nid);
    $data['actions']['output'][] = array(
      '#markup' => '<li>'.$timetracking_button.'</li>',
    );    
  }
}

