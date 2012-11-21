<?php
/**
* @file provides all functions to have dynamic local actions on pages
*/
//define some contexts
define('ERPAL_CONTEXT_PROJECTS', 'projects'); //projects list
define('ERPAL_CONTEXT_PROJECTS_GLOBAL', 'projects_global'); //we are in projects view or in a tab that belongs to the projects
define('ERPAL_CONTEXT_PROJECT_EDIT', 'project_edit');
define('ERPAL_CONTEXT_PROJECT_ADD', 'project_add');
define('ERPAL_CONTEXT_PROJECT', 'project');
define('ERPAL_CONTEXT_TASKS', 'tasks');
define('ERPAL_CONTEXT_TICKETS', 'tickets');
define('ERPAL_CONTEXT_TASK', 'task');
define('ERPAL_CONTEXT_TIMETRACKING', 'timetracking');
define('ERPAL_CONTEXT_TASK_ADD', 'task_add');
define('ERPAL_CONTEXT_TASK_EDIT', 'task_edit');
define('ERPAL_CONTEXT_TIMETRACKING_ADD', 'task_add');
define('ERPAL_CONTEXT_TICKET', 'ticket');
define('ERPAL_CONTEXT_NODE_TIMETRACKINGS', 'node_timetrackings');


/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_projects_helper_erpal_contexts($router_item) {
  
  $path = $router_item['path'];
  $contexts = array();
  
  $is_node_view = !isset($router_item['original_map'][2]) || (isset($router_item['original_map'][2]) && $router_item['original_map'][2] == 'view');
  
  $is_node_edit = (isset($router_item['original_map'][2]) && $router_item['original_map'][2] == 'edit');

  //do we have node add form of tasks, show the same navigation as in single task view
  if (drupal_match_path($path, 'node/add/erpal-task*')) {
    $contexts[ERPAL_CONTEXT_TASK_ADD] = true;  
  }
  
  if ($path == 'node/%/edit') {
    $node = isset($router_item['map'][1]) ? $router_item['map'][1] : false;
    if ($node->type == 'erpal_task')
      $contexts[ERPAL_CONTEXT_TASK_EDIT] = true;
    elseif ($node->type == 'erpal_project') 
      $contexts[ERPAL_CONTEXT_PROJECT_EDIT] = true;
  }
  
  //do we have node add form of tasks, show the same navigation as in single task view
  if (drupal_match_path($path, 'node/add/erpal-timetracking*')) {
    $contexts[ERPAL_CONTEXT_TIMETRACKING_ADD] = true;  
  }
     
  //CHECK PROJECT CONTEXT
  if (drupal_match_path($path, 'node/%*') ) {
    $node = isset($router_item['map'][1]) ? $router_item['map'][1] : false;
    
    if (!$node || !is_object($node))
      return $contexts;
    
    //may be we have a ctools context
    
    if (get_class($node) == 'ctools_context')
      $node = $node->data;    
    
    switch ($node->type) {
      case 'erpal_project':                
        if (!$is_node_view && !$is_node_edit)
          $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
        else { 
          if (!$is_node_edit)
            $contexts[ERPAL_CONTEXT_PROJECT] = true;  
        }
        
        break;
      case 'erpal_task':
        //task or ticket?
        $is_ticket = _erpal_projects_helper_is_ticket($node);
        if ($is_ticket) {          
          if (!$is_node_view && !$is_node_edit)
            $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
          else {
            if(!$is_node_edit)
              $contexts[ERPAL_CONTEXT_TICKET] = true;  
          }
        }  
        else {          
          if (!$is_node_view && !$is_node_edit)
            $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
          else {
            if(!$is_node_edit)
              $contexts[ERPAL_CONTEXT_TASK] = true;  
          }
        }
        break;
      case 'erpal_timetracking':
        if (!$is_node_view && !$is_node_edit)
            $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
          else {
            if(!$is_node_edit)
              $contexts[ERPAL_CONTEXT_TIMETRACKING] = true;  
          }
        
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
* Implements hook_erpal_menu_parents provided by erpal_basic_helper
*/
function erpal_projects_helper_erpal_menu_parents($router_item) {
  return _erpal_projects_helper_get_menu_parents($router_item);
}

/**
* returns the menu parents for a given router item, according to its context
*/
function _erpal_projects_helper_get_menu_parents($router_item) {
  $projects_global = _erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECTS_GLOBAL, $router_item);
  
  if ($projects_global) {
    return 'projects/projects';
  }
  
  $task_add = _erpal_basic_helper_has_context(ERPAL_CONTEXT_TASK_ADD, $router_item);
  $task_edit = _erpal_basic_helper_has_context(ERPAL_CONTEXT_TASK_EDIT, $router_item);
  
  $timetracking_add = _erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMETRACKING_ADD, $router_item);
  
  if ($task_add || $timetracking_add || $task_edit)  {
    return 'projects/projects';
  }

}

/**
* Implements hook_dynamic_menu_items provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
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
    if ($router_item['path'] == 'node/%') {
      $project_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
      _erpal_projects_helper_project_links($data, $project_node, $router_item);       
    }
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
    $is_node_view = !isset($router_item['original_map'][2]) || $router_item['original_map'][2] == 'view'; 
    _erpal_projects_helper_task_links($data, $task_node);       
  } 
  
  //Timetracking context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMETRACKING, $router_item)) {    
    $timetrackings_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    $is_node_view = !isset($router_item['original_map'][2]) || $router_item['original_map'][2] == 'view'; 
    _erpal_projects_helper_timetracking_links($data, $timetrackings_node);       
  } 
  
  
  //Ticket context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TICKET, $router_item)) {    
    $ticket_node = is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : $router_item['map'][1];
    _erpal_projects_helper_ticket_links($data, $ticket_node);       
  }   
  
  //node add task context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TASK_ADD, $router_item)) {    
    _erpal_projects_helper_task_add_links($data);       
  } 
  
  //node edit task context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TASK_EDIT, $router_item)) {    
    _erpal_projects_helper_task_edit_links($data);       
  } 
  
  //node add timetracking context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMETRACKING_ADD, $router_item)) {    
    _erpal_projects_helper_timetracking_add_links($data);       
  } 
}

/**
* Functions displays the top navigation in timetracking add / edit form
*/
function _erpal_projects_helper_timetracking_add_links(&$data) {
  //the task should already be referenced in the  url. Get it and show the navigation of project view
  $task_nid = isset($_GET['field_timetracking_subject']) ? $_GET['field_timetracking_subject'] : false;
  
  if (!$task_nid)
    return;
  
  //get the project of the task to set context menu items
  $task_node = node_load($task_nid);
  $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
  _erpal_projects_helper_node_add_links_project_context($data, $project_nid, $task_nid);
}

/**
* Functions displays the top navigation in task edit form
*/
function _erpal_projects_helper_task_edit_links(&$data) {
  $task_nid = arg(1);
  
  if (!$task_nid)
    return;
    
  $task_node = node_load($task_nid);
  _erpal_projects_helper_task_links($data, $task_node);  
}

/**
* Functions displays the top navigation in task add form
*/
function _erpal_projects_helper_task_add_links(&$data) {
  //the project should already be referenced in the  url. Get it and show the navigation of project view
  $project_nid = isset($_GET['field_project_ref']) ? $_GET['field_project_ref'] : false;
  
  //if we edit the task, there is no project id in url but on the task
  if (is_numeric(arg(1))) {
    //load the task
    $task_node = node_load(arg(1));
    $project_nid = isset($task_node->field_project_ref[LANGUAGE_NONE][0]['target_id']) ? $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'] : false;
  }
  
  if (!$project_nid)
    return;
    
  _erpal_projects_helper_node_add_links_project_context($data, $project_nid);
  
}

/**
* General navigation element on node add forms in project context
*/
function _erpal_projects_helper_node_add_links_project_context(&$data, $project_nid, $task_nid=false) {
  
  $subject_is_ticket = false;
  if ($task_nid) {
    $task_node = node_load($task_nid);
    $subject_is_ticket = isset($task_node->field_is_ticket[LANGUAGE_NONE][0]) ? $task_node->field_is_ticket[LANGUAGE_NONE][0]['value'] : false;
  }
  
  if (isset($_GET['field_is_ticket']) && $_GET['field_is_ticket'] || $subject_is_ticket) {
    $tasks_tab_active = false;
    $tickets_tab_active = true;
  } else {
    $tasks_tab_active = true;
    $tickets_tab_active = false;
  }
  
  erpal_make_local_tab($data, t('Summary'), 'node/'.$project_nid);
  erpal_make_local_tab($data, t('Pricing'), 'node/'.$project_nid.'/pricing');  
  erpal_make_local_tab($data, t('Relations'), 'node/'.$project_nid.'/relations');  
  erpal_make_local_tab($data, t('Tasks'), 'node/'.$project_nid.'/tasks', array(), $tasks_tab_active);  
  erpal_make_local_tab($data, t('Tickets'), 'node/'.$project_nid.'/tickets', array(), $tickets_tab_active);
  erpal_make_local_tab($data, t('Timetrackings'), 'node/'.$project_nid.'/timetracking');
}

/**
* Adds all projects context links
*/
function _erpal_projects_helper_projects_links(&$data) {
  //single project context
  $query = array('destination' => $_GET['q']);
  erpal_make_local_tab($data, t('Project list'), 'projects/projects');
  erpal_make_action($data, t('Create a new project'), 'node/add/erpal-project', $query);
}

/**
* Show all Links on timetrackings list of a node
*/
function _erpal_projects_helper_node_timetrackings_links(&$data, $node) {
  //may be add links here. But no timetracking, because timetrackings need a task, not only a project
  //if this is a task node, add timetracking links here.
  if ($node->type == 'erpal_task') {
    $query = array('field_timetracking_subject' => $node->nid, 'destination' => $_GET['q']);  
    erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query); 
  }
}

/**
* Adds all projects global context links
*/
function _erpal_projects_helper_projects_global_links(&$data, $router_item) {
    
  $has_node = isset($router_item['map'][1]->data) && is_object($router_item['map'][1]->data) ? $router_item['map'][1]->data : false;
  
  if (!$has_node)
    $has_node = isset($router_item['map'][1]) && is_object($router_item['map'][1]) ? $router_item['map'][1] : false;
  
  if (!$has_node) {
    erpal_make_local_tab($data, t('Active timetrackings'), 'projects/timetrackings/tmp');
    erpal_make_local_tab($data, t('Timetrackings'), 'projects/timetrackings');  
    erpal_make_local_tab($data, t('Fixed price items'), 'projects/pricing/fixed');  
  }
}

/**
* Add all tasks list links
*/
function _erpal_projects_helper_tasks_links(&$data, $project_node, $router_item=false) {
  
  $query = array('field_project_ref' => $project_node->nid, 'destination' => $_GET['q']);
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
* Add all timetracking links
*/
function _erpal_projects_helper_timetracking_links(&$data, $timetracking_node) {
  
  erpal_make_action($data, t('Edit this timetracking'), 'node/'.$timetracking_node->nid.'/edit');
  
  //get the subject to show link to all the subjects timetrackings
  $subject_nid = $timetracking_node->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
  erpal_make_local_tab($data, t('Timetrackings'), 'node/'.$subject_nid.'/timetrackings', array(), false); 
}

/**
* Add all task links
*/
function _erpal_projects_helper_task_links(&$data, $task_node) {  
  
  erpal_make_action($data, t('Edit this task'), 'node/'.$task_node->nid.'/edit');
  
  $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id']; 
  $query = array('field_parent' => $task_node->nid, 'field_project_ref' => $project_nid);  
  erpal_make_action($data, t('Create a subtask'), 'node/add/erpal-task', $query);
    
  
  erpal_make_action($data, t('Print'), 'projects/project/task/'.$task_node->nid.'/print'); 
   
  $edit_form = arg(2) == 'edit';
  erpal_make_local_tab($data, t('Tasks'), 'node/'.$project_nid.'/tasks', array(), $edit_form);     
  
  if (user_access('use quick timetracking')) {
    $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($task_node->nid, t('Start timetracking'), t('Stop timetracking'));
    $data['actions']['output'][] = array(
      '#markup' => '<li>'.$timetracking_button.'</li>',
    );    
  }
  
  $query = array('field_timetracking_subject' => $task_node->nid, 'destination' => $_GET['q']);  
  erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query); 
}

/**
* Add all project links
*/
function _erpal_projects_helper_ticket_links(&$data, $ticket_node) {
    
  erpal_make_action($data, t('Edit this ticket'), 'node/'.$ticket_node->nid.'/edit');
   
  $project_nid = $ticket_node->field_project_ref[LANGUAGE_NONE][0]['target_id']; 
  $query = array('field_parent' => $ticket_node->nid, 'field_project_ref' => $project_nid, 'field_is_ticket' => 1);  
  erpal_make_action($data, t('Create a subticket'), 'node/add/erpal-task', $query);
  
  erpal_make_action($data, t('Print'), 'projects/project/task/'.$ticket_node->nid.'/print'); 
   
  erpal_make_local_tab($data, t('Tickets'), 'node/'.$project_nid.'/tickets');    
   
  if (user_access('use quick timetracking')) {
    $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($ticket_node->nid, t('Start timetracking'), t('Stop timetracking'));
    $data['actions']['output'][] = array(
      '#markup' => '<li>'.$timetracking_button.'</li>',
    );    
  }
  
  $query = array('field_timetracking_subject' => $ticket_node->nid, 'destination' => $_GET['q']);  
  erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query);
}

