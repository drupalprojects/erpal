<?php

/**
 * Implements hook_token_info().
 */
function erpal_projects_helper_token_info() {
  $types['erpal_project_notifications'] = array(
    'name' => t("Erpal project notification token"),
    'description' => t("Tokens for project notifications."),
    'needs-data' => 'erpal_task',
  );
  
  $types['erpal_task'] = array(
    'name' => t("Erpal task token"),
    'description' => t("Tokens for tasks."),
    'needs-data' => 'erpal_task',
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
  
  $task['title'] = array(
    'name' => t("Title"),
    'description' => t("Title of the task"),
  );
  
  $task['nid'] = array(
    'name' => t("Nid"),
    'description' => t("Nid of the task"),
  );
  
  
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_project_notifications' => $notify,
      'erpal_task' => $task,
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
        case 'nid':
          $replacements[$original] = isset($subject_node->nid) ? $subject_node->nid : false;
        break;                  
      }
    }
  }

  return $replacements;
}
