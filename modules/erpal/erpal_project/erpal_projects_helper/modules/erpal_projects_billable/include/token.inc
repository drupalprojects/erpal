<?php

/**
 * Implements hook_token_info().
 */
function erpal_projects_billable_token_info() {
  $types['erpal_projects_billable_subject'] = array(
    'name' => t("Erpal billable subject"),
    'description' => t("Tokens for subjects of billables."),
    'needs-data' => 'billable',
  );

  $subjects['project_subject'] = array(
    'name' => t("Billable project"),
    'description' => t("The project of the billables subject"),
  );
  $subjects['task_subject'] = array(
    'name' => t("Billable task"),
    'description' => t("The task of the billables subject"),
  );
  $subjects['timetracking_subject'] = array(
    'name' => t("Billable timetracking"),
    'description' => t("The timetracking of the billables subject"),
  );
  $subjects['service_category'] = array(
    'name' => t("Service category"),
    'description' => t("The service category of the pricing information of the subject"),
  );
  $subjects['expense_category'] = array(
    'name' => t("Expense category"),
    'description' => t("The expense category of the pricing information of the subject"),
  );
  
  
  return array(
    'types' => $types,
    'tokens' => array(
      'erpal_projects_billable_subject' => $subjects,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function erpal_projects_billable_tokens($type, $tokens, array $data = array(), array $options = array()) {
  global $user;  
  
  $replacements = array();
  
  if ($type == 'erpal_projects_billable_subject') {
    $subject_node = isset($data['subject']) ? $data['subject'] : '';
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'project_subject':
          $title = _erpal_projects_billable_get_billable_subject_title($subject_node, 'erpal_project');
          $replacements[$original] = $title;
        break;
        case 'timetracking_subject':
          $title = _erpal_projects_billable_get_billable_subject_title($subject_node, 'erpal_timetracking');
          $replacements[$original] = $title;
        break;
        case 'task_subject':
          $title = _erpal_projects_billable_get_billable_subject_title($subject_node, 'erpal_task');          
          $replacements[$original] = $title;
        break;
        case 'service_category':
          $service_category = isset($data['service_category']) ? $data['service_category'] : '';
          $replacements[$original] = $service_category;
        break;
        case 'expense_category':
          $expense_category = isset($data['expense_category']) ? $data['expense_category'] : '';
          $replacements[$original] = $expense_category;
        break;
          
      }
    }
  }

  return $replacements;
}

/**
* returns the subject of the billable. If the direct subject has not the required type we check in the tree if there is a type (project->task->timetracking). If we cannot find, we return false. If no required type is set, we return the title of the direct billable
*/
function _erpal_projects_billable_get_billable_subject_title($subject_node, $node_type=false) {
  
  if (!$node_type || $subject_node->type == $node_type)
    return $subject_node->title;
  
  //we want another node type, so try the chain from timetracking to project
  if (isset($subject_node->field_timetracking_subject[LANGUAGE_NONE][0])) {
    $subject_nid = $subject_node->field_timetracking_subject[LANGUAGE_NONE][0]['target_id'];
    $subject_node = node_load($subject_nid);

    if ($subject_node->type == $node_type)
      return $subject_node->title;
  }
  
  //try task...
  if (isset($subject_node->field_project_ref[LANGUAGE_NONE][0])) {
    $subject_nid = $subject_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
    $subject_node = node_load($subject_nid);
    if ($subject_node->type == $node_type)
      return $subject_node->title;
  }
  
  return '';
  
}