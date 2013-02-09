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
define('ERPAL_CONTEXT_TIMETRACKING_ADD', 'timetracking_add');
define('ERPAL_CONTEXT_TIMETRACKING_EDIT', 'timetracking_edit');
define('ERPAL_CONTEXT_TICKET', 'ticket');
define('ERPAL_CONTEXT_NODE_TIMETRACKINGS', 'node_timetrackings');
define('ERPAL_CONTEXT_PROJECT_SUB_PATH', 'project_sub_path');
define('ERPAL_CONTEXT_BUDGET', 'budget');
define('ERPAL_CONTEXT_BUDGET_EDIT', 'budget_edit');


/**
* Implement hook_erpal_contexts definied in erpal_basic_helper module
*/
function erpal_projects_helper_erpal_contexts($router_item) {

  $path = $router_item['path'];
  $contexts = array();

  $node = _erpal_basic_helper_router_object(1, $router_item);
  
  //do we have node add form
  if (drupal_match_path($path, 'node/add/erpal-task*')) {
    $contexts[ERPAL_CONTEXT_TASK_ADD] = true;  
  } elseif (drupal_match_path($path, 'node/add/erpal-project*')) {
    $contexts[ERPAL_CONTEXT_PROJECT_ADD] = true;  
  } elseif (drupal_match_path($path, 'node/add/erpal-timetracking*')) {
    $contexts[ERPAL_CONTEXT_TIMETRACKING_ADD] = true;  
  }
  
  //do we have an edit form of a node?
  if ($path == 'node/%/edit') {
    if ($node->type == 'erpal_task')
      $contexts[ERPAL_CONTEXT_TASK_EDIT] = true;
    elseif ($node->type == 'erpal_project') 
      $contexts[ERPAL_CONTEXT_PROJECT_EDIT] = true;
    elseif ($node->type == 'erpal_timetracking') 
      $contexts[ERPAL_CONTEXT_TIMETRACKING_EDIT] = true;
  }
   
  //Edit form of a budget?
  if ($path == 'budget/%budget/edit') {
    $contexts[ERPAL_CONTEXT_BUDGET_EDIT] = true;
  }
   
  //CHECK PROJECT CONTEXT
  if (drupal_match_path($path, 'node/%*') ) {    
    if (!$node || !is_object($node))
      return $contexts;
    
    //check if we have a subpath like node/23/timetracking or something like this
    $is_project_context_node = false;
    if (arg(2) && arg(2) != 'edit') {
      switch ($node->type) {
        case 'erpal_project':  
        case 'erpal_task':
        case 'erpal_timetracking':
        $contexts[ERPAL_CONTEXT_PROJECT_SUB_PATH] = true;
        $is_project_context_node = true;
        break;
      }
    } else {
      switch ($node->type) {
        case 'erpal_project':  
          $is_project_context_node = true;
          $contexts[ERPAL_CONTEXT_PROJECT] = true;  
          break;
        case 'erpal_task':
          //task or ticket?
          $is_project_context_node = true;
          $is_ticket = _erpal_projects_helper_is_ticket($node);
          if ($is_ticket) {                                 
            $contexts[ERPAL_CONTEXT_TICKET] = true;  
          }        
          else {          
            $contexts[ERPAL_CONTEXT_TASK] = true;  
          }
          break;
        case 'erpal_timetracking':
          $is_project_context_node = true;
          $contexts[ERPAL_CONTEXT_TIMETRACKING] = true;  
          break;
      }
    }
    
    if ($is_project_context_node) {
      $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true;
    }
  }

  //budget view context?
  if (drupal_match_path($path, 'budget/%*') ) {
    $contexts[ERPAL_CONTEXT_BUDGET] = true;
    $contexts[ERPAL_CONTEXT_PROJECTS_GLOBAL] = true; 
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
  
  $project_add = _erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT_ADD, $router_item);
  $project_edit = _erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT_EDIT, $router_item);
  
  $timetracking_add = _erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMETRACKING_ADD, $router_item);
  $timetracking_edit = _erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMETRACKING_EDIT, $router_item);
  
  $budget_view = _erpal_basic_helper_has_context(ERPAL_CONTEXT_BUDGET, $router_item);
  $budget_edit = _erpal_basic_helper_has_context(ERPAL_CONTEXT_BUDGET_EDIT, $router_item);
  
  
  if ($task_add || $task_edit || $timetracking_add || $timetracking_edit || $project_add || $project_edit || $budget_view || $budget_edit)  {
    return 'projects/projects';
  }

}

/**
* Implements hook_dynamic_menu_items provided by erpal_basic_helper
* Returns all dynamic contextual menu items, @see erpal_basic_helper.module
*/
function erpal_projects_helper_dynamic_menu_items_alter(&$data, $router_item, $root_path) {

  $entity = _erpal_basic_helper_router_object(1, $router_item);
  $is_node_view = !isset($router_item['original_map'][2]) || $router_item['original_map'][2] == 'view'; 
  
  //projects list context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECTS, $router_item)) {    
    _erpal_projects_helper_projects_links($data);       
  } 
  
  //projects global context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECTS_GLOBAL, $router_item)) {  
    _erpal_projects_helper_projects_global_links($data, $entity);       
  } 
  
  //Node Timetracking Context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_NODE_TIMETRACKINGS, $router_item)) {
    _erpal_projects_helper_node_timetrackings_links($data, $entity); 
  }
  
  //project context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT, $router_item)) {    
    if ($router_item['path'] == 'node/%') {
      _erpal_projects_helper_project_links($data, $entity);  
      _erpal_project_helper_project_global_menu_tabs($data, $entity->nid, false);      
    }
  } 
  
  //Tasks context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TASKS, $router_item)) {    
    _erpal_projects_helper_tasks_links($data, $entity);       
  } 
  
  //Tickets context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TICKETS, $router_item)) {    
    _erpal_projects_helper_tickets_links($data, $entity);       
  } 
  
  //Task context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TASK, $router_item)) {        
    _erpal_projects_helper_task_links($data, $entity, $is_node_view); 
  } 
  
  //Timetracking context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMETRACKING, $router_item)) {
    _erpal_projects_helper_timetracking_links($data, $entity);       
  } 
  
  
  //Ticket context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TICKET, $router_item)) {    
    _erpal_projects_helper_ticket_links($data, $entity, $is_node_view);       
  }   
  
  //node add task context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TASK_ADD, $router_item)) {    
    _erpal_projects_helper_task_add_links($data);       
  } 
  
  //node edit task context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TASK_EDIT, $router_item)) {    
    _erpal_projects_helper_task_edit_links($data);       
  } 
  
  //node add project context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT_ADD, $router_item)) {    
    _erpal_projects_helper_project_add_links($data, $entity);       
  } 
  
  //node edit project context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT_EDIT, $router_item)) {    
    _erpal_projects_helper_project_edit_links($data);       
  } 
  
  //node add timetracking context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMETRACKING_ADD, $router_item)) {    
    _erpal_projects_helper_timetracking_add_links($data);       
  } 
  
  //node edit timetracking context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_TIMETRACKING_EDIT, $router_item)) {    
    _erpal_projects_helper_timetracking_edit_links($data, $entity);       
  } 
  
  //task, project, timetracking sub path
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_PROJECT_SUB_PATH, $router_item)) {    
    _erpal_projects_helper_project_subpath_links($data, $entity);       
  } 
  
  //budget view context
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_BUDGET, $router_item)) {    
    _erpal_projects_helper_project_budget_links($data, $entity);       
  }
  
  //budget edit context  
  if (_erpal_basic_helper_has_context(ERPAL_CONTEXT_BUDGET_EDIT, $router_item)) {    
    _erpal_projects_helper_project_budget_links($data, $entity);       
  }
  
  _erpal_projects_helper_hide_menu_links($data);
}

/**
* Hide view and edit links for entities provided by project feature
*/
function _erpal_projects_helper_hide_menu_links(&$data) {
  //allways remove the budget/%/edit link from local tasks
  foreach ($data['tabs'] as $delta=>$output) {
    foreach ($output['output'] as $inner_delta=>$a_output) {
      $path = $a_output['#link']['path'];
      if ($path == 'budget/%/edit') {
        unset($data['tabs'][$delta]['output'][$inner_delta]);
      }
     
      //and if this is the view button, rename it
      if ($path == 'budget/%' || $path == 'budget/%/view') {
        unset($data['tabs'][$delta]['output'][$inner_delta]);
      }
    }
  }
}

/**
* Shows links on budget context in a project
*/
function _erpal_projects_helper_project_budget_links(&$data, $budget) {
  //get the project of the entity the budget is assigned to
  $subject_node = _erpal_projects_helper_get_nodes_referencing_budget($budget->budget_id);
 
  $project_nid = _erpal_projects_helper_has_project($subject_node);

  $task_nid = false;
  $active_tabs = array();
  if ($subject_node->type == 'erpal_task') {
    $task_nid = $subject_node->nid;    
    $task_node = node_load($task_nid);
    $is_ticket = _erpal_projects_helper_is_ticket($subject_node);
    if ($is_ticket)
      $active_tabs = array('tickets');
    else
      $active_tabs = array('tasks');
  }
  
  _erpal_projects_helper_node_add_links_project_context($data, $project_nid, $task_nid, $active_tabs);
  
  //show edit action for budget
  $query = array('destination' => $_GET['q']);
  erpal_make_action($data, t('Edit this budget'), 'budget/'.$budget->budget_id.'/edit', $query);
}


/**
* Show all Project add links
*/
function _erpal_projects_helper_project_add_links(&$data, $node) {
  _erpal_projects_helper_projects_global_links($data, $node, array('project list'));
}

/**
* Functions displays the top navigation in timetracking edit form
*/
function _erpal_projects_helper_timetracking_edit_links(&$data, $timetracking_node) {

  $project_nid = _erpal_projects_helper_has_project($timetracking_node);
  $project_node = node_load($project_nid);
  $subject_nid = $timetracking_node->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
  _erpal_project_helper_project_global_menu_tabs($data, $project_nid, $subject_nid, array('timetrackings'));  
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
  _erpal_projects_helper_node_add_links_project_context($data, $project_nid, $task_nid, array('timetrackings'));  
}

/**
* Function displays the top navigation in project edit form
*/
function _erpal_projects_helper_project_edit_links(&$data) {
  $project_nid = arg(1);
  
  if (!$project_nid)
    return;
   
  _erpal_project_helper_project_global_menu_tabs($data, $project_nid, false, array('summary'));
}

/**
* Function displays the top navigation in task edit form
*/
function _erpal_projects_helper_task_edit_links(&$data) {
  $task_nid = arg(1);
  
  if (!$task_nid)
    return;
    
  $task_node = node_load($task_nid);
  //get the project nid
  $project_nid = _erpal_projects_helper_has_project($task_node);
  _erpal_projects_helper_task_links($data, $task_node, false);
  
  $is_ticket = _erpal_projects_helper_is_ticket($task_node);  
  $active_tabs = $is_ticket ? array('tickets') : array('tasks');
  
  _erpal_project_helper_project_global_menu_tabs($data, $project_nid, $task_node->nid, $active_tabs);
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
function _erpal_projects_helper_node_add_links_project_context(&$data, $project_nid, $task_nid=false, $active_tabs=array()) {
  
  $subject_is_ticket = false;
  $task_node = false;
  if ($task_nid) {
    $task_node = node_load($task_nid);
    $subject_is_ticket = isset($task_node->field_is_ticket[LANGUAGE_NONE][0]) ? $task_node->field_is_ticket[LANGUAGE_NONE][0]['value'] : false;
  }
  
  if (isset($_GET['field_is_ticket']) && $_GET['field_is_ticket'] || $subject_is_ticket) {
    $active_tabs = array('tickets');
  } else {
    if (!$active_tabs)
      $active_tabs = array('tasks');
  }
  
  _erpal_project_helper_project_global_menu_tabs($data, $project_nid, $task_nid, $active_tabs);
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
  //may be add links here. But no timetracking, because timetrackings need a task, not only a project
  //if this is a task node, add timetracking links here.
  $project_nid = $node->nid;
  if ($node->type == 'erpal_task') {
    $query = array('field_timetracking_subject' => $node->nid, 'destination' => $_GET['q']);  
    erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query);     
  }  
}

/**
* Adds all projects global context links
*/
function _erpal_projects_helper_projects_global_links(&$data, $node, $active_tabs=array()) {
  $has_node = $node;
  if (!$has_node) {
    $options = array('class' => array('projects'));
    erpal_make_local_tab($data, t('Project list'), 'projects/projects', array(), in_array('project list', $active_tabs),$options);
    erpal_make_local_tab($data, t('Active timetrackings'), 'projects/timetrackings/tmp', array(), in_array('active timetrackings', $active_tabs));
    erpal_make_local_tab($data, t('Timetrackings'), 'projects/timetrackings', array(), in_array('timetrackings', $active_tabs));  
    erpal_make_local_tab($data, t('Fixed price items'), 'projects/pricing/fixed', array(), in_array('fixed price items', $active_tabs));  
    erpal_make_local_tab($data, t('Time-Budgets'), 'projects/budgets', array(), in_array('time-budgets', $active_tabs)); 
  }
}

/**
* Add all tasks list links
*/
function _erpal_projects_helper_tasks_links(&$data, $project_node) {
  
  $query = array('field_project_ref' => $project_node->nid, 'destination' => $_GET['q']);
  erpal_make_action($data, t('Add a task'), 'node/add/erpal-task', $query);
}

/**
* Add all tickets list links
*/
function _erpal_projects_helper_tickets_links(&$data, $project_node) {
  
  $query = array('field_project_ref' => $project_node->nid, 'field_is_ticket' => 1, 'destination'=>$_GET['q']);
  erpal_make_action($data, t('Add a ticket'), 'node/add/erpal-task', $query);
}


/**
* Add all project links
*/
function _erpal_projects_helper_project_links(&$data, $project_node) {

  erpal_make_action($data, t('Edit this project'), 'node/'.$project_node->nid.'/edit'); 
}

/**
* Add all timetracking links
*/
function _erpal_projects_helper_timetracking_links(&$data, $timetracking_node) {
  
  erpal_make_action($data, t('Edit this timetracking'), 'node/'.$timetracking_node->nid.'/edit');
  $subject_nid = $timetracking_node->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
  $subject_node = node_load($subject_nid);
  $project_nid = $subject_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
  _erpal_project_helper_project_global_menu_tabs($data, $project_nid, $subject_nid, array('timetrackings'));  
}

/**
* Add all task links
*/
function _erpal_projects_helper_task_links(&$data, $task_node, $is_node_view=false) {  
  
  $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id']; 
  _erpal_project_helper_project_global_menu_tabs($data, $project_nid, $task_node->nid, array('tasks'));
  if ($is_node_view) {
    erpal_make_action($data, t('Edit this task'), 'node/'.$task_node->nid.'/edit');
    
    $query = array('field_parent' => $task_node->nid, 'field_project_ref' => $project_nid);  
    erpal_make_action($data, t('Create a subtask'), 'node/add/erpal-task', $query);     
    erpal_make_action($data, t('Print'), 'projects/project/task/'.$task_node->nid.'/print'); 
                
    if (user_access('use quick timetracking')) {
      $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($task_node->nid, t('Start timetracking'), t('Stop timetracking'));
      $data['actions']['output'][] = array(
        '#markup' => '<li>'.$timetracking_button.'</li>',
      );    
    }
    
    $query = array('field_timetracking_subject' => $task_node->nid, 'destination' => $_GET['q']);  
    erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query); 
  } 
}

/**
* Add all ticket links
*/
function _erpal_projects_helper_ticket_links(&$data, $ticket_node, $is_node_view=false) {
   
  $project_nid = $ticket_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];   
  
  _erpal_project_helper_project_global_menu_tabs($data, $project_nid, $ticket_node->nid, array('tickets'));
 
  if ($is_node_view) {
    erpal_make_action($data, t('Edit this ticket'), 'node/'.$ticket_node->nid.'/edit');
    $query = array('field_parent' => $ticket_node->nid, 'field_project_ref' => $project_nid, 'field_is_ticket' => 1);  
    erpal_make_action($data, t('Create a subticket'), 'node/add/erpal-task', $query);
    
    erpal_make_action($data, t('Print'), 'projects/project/task/'.$ticket_node->nid.'/print'); 
     
      
     
    if (user_access('use quick timetracking')) {
      $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($ticket_node->nid, t('Start timetracking'), t('Stop timetracking'));
      $data['actions']['output'][] = array(
        '#markup' => '<li>'.$timetracking_button.'</li>',
      );    
    }

    $query = array('field_timetracking_subject' => $ticket_node->nid, 'destination' => $_GET['q']);  
    erpal_make_action($data, t('Add a timetracking'), 'node/add/erpal-timetracking', $query);
  }
}

/**
* Returns the top tab navigation for task or ticket view / add / edit
*/
function _erpal_project_helper_project_global_menu_tabs(&$data, $project_nid, $current_nid=false, $active_tabs=array()) {

  static $processed = false;
  
  if ($processed)
    return; //we want no duplicate tabs if somebody calls this twice

  $processed = true;

  if (!$current_nid)
    $current_nid = $project_nid;

  $options = array('class' => array('projects'));
  erpal_make_local_tab($data, t('Summary'), 'node/'.$project_nid, array(), in_array('summary', $active_tabs), $options); 
  erpal_make_local_tab($data, t('Tasks'), 'node/'.$project_nid.'/tasks', array(), in_array('tasks', $active_tabs)); 
  erpal_make_local_tab($data, t('Tickets'), 'node/'.$project_nid.'/tickets', array(), in_array('tickets', $active_tabs)); 
  erpal_make_local_tab($data, t('Files'), 'node/'.$current_nid.'/files', array(), in_array('pricing', $active_tabs));
  erpal_make_local_tab($data, t('Calendar'), 'node/'.$current_nid.'/calendar', array(), in_array('calendar', $active_tabs));
  erpal_make_local_tab($data, t('Timetrackings'), 'node/'.$current_nid.'/timetracking', array(), in_array('timetrackings', $active_tabs));
  //erpal_make_local_tab($data, t('Pricing'), 'node/'.$current_nid.'/pricing', array(), in_array('pricing', $active_tabs));
}

/**
* Shows links on subpage of project, task or timetracking node
*/
function _erpal_projects_helper_project_subpath_links(&$data, $current_node, $active_tabs=array()) {
  //get the project node
  $project_nid = _erpal_projects_helper_has_project($current_node);
  if ($project_nid)
    _erpal_project_helper_project_global_menu_tabs($data, $project_nid, $current_node->nid, $active_tabs);
}