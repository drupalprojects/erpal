<?php

/**
 * Implements hook_token_info().
 */
function erpal_projects_helper_token_info() {
  $types['erpal_project_notifications'] = array(
    'name' => t("ERPAL project notification token"),
    'description' => t("Tokens for project notifications."),
    'needs-data' => 'erpal_task',
  );
  
  $types['erpal_project_url_get'] = array(
    'name' => t("ERPAL URL tokens"),
    'description' => t("Tokens for projects from the URL."),    
  );
  
  $types['erpal_task'] = array(
    'name' => t("ERPAL task token"),
    'description' => t("Tokens for tasks."),
    'needs-data' => 'erpal_task',
  );
  
  $types['erpal_project_budget'] = array(
    'name' => t("Erpal budget tokens"),
    'description' => t("Tokens for project budgets"),
    'needs-data' => 'erpal_budget',
  );

  $notify['content_url'] = array(
    'name' => t("Content URL"),
    'description' => t("The URL to the content that was updated"),
  );
  $notify['update_operation'] = array(
    'name' => t("Update operation"),
    'description' => t("A the operation performed on the node, like update or insert"),
  );
  $notify['content_label'] = array(
    'name' => t("Content label"),
    'description' => t("The label of the updated content"),
  );
  $notify['content_text'] = array(
    'name' => t("Content text"),
    'description' => t("The text of the updated content"),
  );
  $notify['project_title'] = array(
    'name' => t("Project title"),
    'description' => t("The title of the project"),
  );
  $notify['task_status'] = array(
    'name' => t("Status of task"),
    'description' => t("Status of the task"),
  );
    
  $project_url['project_ref_nid_url'] = array(
    'name' => t("The project nid"),
    'description' => t("The project nid as GET param in the url"),
  );  
  
  $task['title'] = array(
    'name' => t("Title"),
    'description' => t("Title of the task"),
  );
  
  $task['body'] = array(
    'name' => t("Body"),
    'description' => t("Body of the task"),
  );
  
  $task['nid'] = array(
    'name' => t("Nid"),
    'description' => t("Nid of the task"),
  );
  
  $task['status'] = array(
    'name' => t("Status"),
    'description' => t("Status of the task"),
  );
  
  
  //budget tokens
  $budget['budget_status'] = array(
    'name' => t("Budget status"),
    'description' => t("Status of a budget, low or empty"),
  );
  
  $budget['budget_node_title'] = array(
    'name' => t("Budget node title"),
    'description' => t("The title of the node where the budget is attached"),
  );
  
  $budget['budget_node_link'] = array(
    'name' => t("Budget node link"),
    'description' => t("The link to the node where the budget is attached"),
  );
  
  $budget['budget_project_title'] = array(
    'name' => t("Budget project title"),
    'description' => t("The title of the project where the budget is located"),
  );
  
  $budget['budget_project_link'] = array(
    'name' => t("Budget project link"),
    'description' => t("The link to the project where the budget is located"),
  );
  
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_project_notifications' => $notify,
      'erpal_project_url_get' => $project_url,
      'erpal_task' => $task,
      'erpal_project_budget' => $budget,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function erpal_projects_helper_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;  
  
  $replacements = array();
  
  if ($type == 'erpal_project_notifications') {
    $content_entity = isset($data['entity']) ? $data['entity'] : '';
    $op = isset($data['op']) ? $data['op'] : '';
    $entity_type = isset($data['entity_type']) ? $data['entity_type'] : false;
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'update_operation':
          $replacements[$original] = $op;
        break;
        case 'content_url':
          $uri = entity_uri($entity_type, $content_entity);
          $url = url($uri['path'], array('absolute' => true));
          $replacements[$original] = $url;
        break;
        case 'content_label':
          $label = entity_label($entity_type, $content_entity);          
          $replacements[$original] = $label;
        break;
        case 'project_title':
          
          if (isset($content_entity->cid) && $content_entity->cid)
            $subject_nid = $content_entity->nid;
          elseif (isset($content_entity->nid) && $content_entity->nid)
            $subject_nid = $content_entity->nid;
          else
            return; //no node found

          //get the node
          $base_data_node = erpal_lib_helper_node_base_data(array($subject_nid));
          $base_node = reset($base_data_node);   
          
          //get the project
          $project_node_title = '';
          if ($base_node->type == 'erpal_project') {
            $project_node_title = $base_node->title;
          } elseif ($base_node->type == 'erpal_task') {
            //get the project from the task
            $project_nid = _erpal_projects_helper_has_project($base_node->nid);            
            if ($project_nid) {
              $base_node_project = erpal_lib_helper_node_base_data(array($project_nid));
              $base_node_project = reset($base_node_project);
              $project_node_title = $base_node_project->title;
            }
          }

          $replacements[$original] = $project_node_title;
        break;
        case 'content_text':
          //check for node or comment body
          $text = '';
          if (isset($content_entity->comment_body[LANGUAGE_NONE][0]))
            $text = strip_tags($content_entity->comment_body[LANGUAGE_NONE][0]['value']);
          if (isset($content_entity->body[LANGUAGE_NONE][0]))
            $text = strip_tags($content_entity->body[LANGUAGE_NONE][0]['value']);
          if (isset($content_entity->body[LANGUAGE_NONE]['value']))
            $text = strip_tags($content_entity->body[LANGUAGE_NONE]['value']);
          
          $replacements[$original] = $text;
        break;
        case 'task_status':
          $task_node = false;
          if ($entity_type == 'comment') {            
            if (!empty($content_entity->node_type) && $content_entity->node_type == 'comment_node_erpal_task') {
              //load the node for the comment and notify for this node
              $task_node = node_load($content_entity->nid);
            } else if ($content_entity->type == 'erpal_task') {
              $task_node = $content_entity;
            }
          } elseif ($entity_type == 'node') {
            if ($content_entity->type == 'erpal_task')
              $task_node = $content_entity;
          } 
          
          $status_string = '';
          if ($task_node) {
            $status_term_id = isset($task_node->field_task_status_term[LANGUAGE_NONE][0]['tid']) ? $task_node->field_task_status_term[LANGUAGE_NONE][0]['tid'] : false;
            $status_string = $status_term_id ? taxonomy_term_load($status_term_id)->name : '';            
          }
            
          $replacements[$original] = $status_string;
        break;
      }
    }
  }
  elseif ($type == 'erpal_task') {
    $subject_node = isset($data['subject']) ? $data['subject'] : false;
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'title':
          $replacements[$original] = isset($subject_node->title) ? $subject_node->title : '';
        break;
        case 'body':
          $replacements[$original] = isset($subject_node->body[LANGUAGE_NONE][0]) ? $subject_node->body[LANGUAGE_NONE][0]['value'] : '';
        break;
        case 'nid':
          $replacements[$original] = isset($subject_node->nid) ? $subject_node->nid : false;
        case 'status':
          $status_term_id = isset($subject_node->field_task_status_term[LANGUAGE_NONE][0]['tid']) ? $subject_node->field_task_status_term[LANGUAGE_NONE][0]['tid'] : false;
          $status_string = $status_term_id ? taxonomy_term_load($status_term_id)->name : '';
          $replacements[$original] = $status_string;
        break;                  
      }
    }
  } elseif ($type == 'erpal_project_budget') {
    $budget = isset($data['budget']) ? $data['budget'] : false;  //task or project
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'budget_status':
          $replacements[$original] = isset($budget['status']) ? $budget['status'] : '';
        break; 
        case 'budget_node_title':  //node title where the budget is attached
          $replacements[$original] = isset($budget['budget_node']) ? $budget['budget_node']->title : '';
        break;
        case 'budget_node_link':  //node link where the budget is attached
          $replacements[$original] = isset($budget['budget_node']) ? l($budget['budget_node']->title, 'node/'.$budget['budget_node']->nid) : '';
        break;
        case 'budget_project_title':  //the project where the budget is located
          $replacements[$original] = isset($budget['budget_project']) ? $budget['budget_project']->title : '';
        break;
        case 'budget_project_link':  //the project where the budget is located
          $replacements[$original] = isset($budget['budget_project']) ? l($budget['budget_project']->title, 'node/'.$budget['budget_project']->nid) : '';
        break;        
      }
    }
  } elseif ($type == 'erpal_project_url_get') {    
    $project_nid = !empty($_GET['field_project_ref']) ? $_GET['field_project_ref'] : arg(6); //try to use a param directly form the URL's GET param, otherwise try if it is appended to the entityreference autocomplete path
    //ensure that this is project nid
    $project_nid = _erpal_projects_helper_has_project($project_nid);    
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'project_ref_nid_url':
          $replacements[$original] = $project_nid;
        break; 
      }
    }
  }

  return $replacements;
}
