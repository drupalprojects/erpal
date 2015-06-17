<?php

/**
 * @file adds some query functions for tasks and other functions for erpal_task nodes
 */

/**
 * Callback for autocomplete path for tasks by project
 */
function _erpal_projects_helper_tasks_autocomplete($project_nid, $text) {
  $project_nid = arg(3) ? arg(3) : 0; //if it is not set, return all tasks

  $task_nids = _erpal_projects_helper_get_tasks_by_project($project_nid, $text, 20); //limit to only 20 rows

  $matches = _erpal_basic_helper_nids_for_form_select($task_nids);

  // return for JS
  drupal_json_output($matches);
}

/**
 * Access callback for validating access to task by project autocomplete path
 */
function _erpal_projects_helper_tasks_autocomplete_access() {
  return user_access('access tasks view');
}

/**
* Validate the creation of a task
*/
function _erpal_projects_helper_node_validate_task($node, $form, &$form_state) {
  //check that a user can only create a task, if he has permissions to view the task list and only can create a ticket, if he has permissions to view the ticket list.
  global $user;
  
  $project_nid = $node->field_project_ref[LANGUAGE_NONE][0]['target_id'] ? $node->field_project_ref[LANGUAGE_NONE][0]['target_id'] : false;
  if (!$project_nid)
    return;  //this should not happen as every task needs a project.
    
  $values = $form_state['values'];
  $project_node = node_load($project_nid);
  $type = $values['field_is_ticket'][LANGUAGE_NONE][0]['value'] ? 'tickets' : 'tasks';

  $has_access = _erpal_projects_helper_user_has_project_tab_access($type, $user, $project_node);  
  
  if (!$has_access) {
    form_set_error('field_is_ticket', t('Sorry, you are not allowed to create a !type', array('!type' => $type)));
  }
}

/**
 * Return tasks by project
 * @param $project_nid the nid of the project we want the tasks for
 * @param $like_title a substring the task title must contain
 * @return array with nids of tasks referencing the given project_nid
 */
function _erpal_projects_helper_get_tasks_by_project($project_nid, $like_title = false, $limit = false) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'erpal_task')
          ->propertyCondition('status', 1);

  if ($project_nid)
    $query->fieldCondition('field_project_ref', 'target_id', $project_nid);

  if ($like_title) {
    //add like condition
    $query->propertyCondition('title', '%' . $like_title . '%', 'LIKE');
  }

  if ($limit)
    $query->range(0, $limit); //limit rows, if set!

  $result = $query->execute();

  $task_nids = array();
  if (isset($result['node'])) {
    $task_nids = array_keys($result['node']);
  }

  return $task_nids;
}

/**
 * Checks if node is a ticket
 */
function _erpal_projects_helper_is_ticket($node) {
  if ($node->type != 'erpal_task')
    return false;

  $is_ticket = isset($node->field_is_ticket[LANGUAGE_NONE][0]['value']) ? $node->field_is_ticket[LANGUAGE_NONE][0]['value'] : false;

  return $is_ticket;
}

/**
 * Adds erpal context links on task view
 */
function _erpal_projects_helper_add_task_links(&$links, $node) {
  if (is_numeric($node))
    $node = node_load($node);

  if ($node->type != 'erpal_task')
    return;

  $is_ticket = _erpal_projects_helper_is_ticket($node);

  //back to list links
  if ($is_ticket) {
    //back to tickets
    $list_type = 'tickets';
    $list_label = t('ticket');
  } else {
    //back to tasks
    $list_type = 'tasks';
    $list_label = t('task');
  }

  $project_nid = $node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
  $back_to_list = l(
          t('Go to !type list', array('!type' => $list_label)), 'node/' . $project_nid . '/' . $list_type
  );
  $links[] = $back_to_list;

  //add subtask / Subticket link
  if (user_access('create erpal_task content')) {
    $project_nid = $node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
    $subtask_link = l(
            t('Create a sub!type', array('!type' => $list_label)), 'node/add/erpal-task', array(
        'query' => array(
            'field_parent' => $node->nid,
            'field_project_ref' => $project_nid,
            'is_ticket' => $is_ticket,
        ),
            )
    );
    $links[] = $subtask_link;
  }

  //quick timetracking
  if (user_access('use quick timetracking')) {
    $timetracking_button = _erpal_projects_helper_render_timetracking_button_field($node->nid);
    $links[] = $timetracking_button;
  }
}

/**
 * Link to add a Subticket
 */

/**
 * Return all tasks
 * @return array with nids of tasks referencing the given project_nid if set
 */
function _erpal_projects_helper_get_tasks($project_nid = false, $for_options = false, $ignore_permissions = false) {
  //@TODO my be add static cache for better performance on multiple calls
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'erpal_task')
          ->propertyCondition('status', 1);

  if ($ignore_permissions) {
    $query->addMetaData('account', user_load(1));
  }

  if ($project_nid) {
    $query->fieldCondition('field_project_ref', 'target_id', $project_nid);
  }

  $result = $query->execute();

  $task_nids = array();
  if (isset($result['node']) && count($result['node'])) {
    $task_nids = array_keys($result['node']);


    //now we have task nids, now execute a query to get nid, title pairs
    $result = db_select('node', 'n')
            ->fields('n', array('nid', 'title'))
            ->condition('nid', $task_nids, 'IN')
            ->orderBy('title', 'ASC')//ORDER BY created
            ->execute()
            ->fetchAll();
  }

  $ret = array();
  if ($for_options) {
    foreach ($result as $obj) {
      $ret[$obj->nid] = ($obj->title);
    }
  }
  else
    return $result;

  return $ret;
}

/**
 * Return all tasks of a project that have no parent at all or no parent of type erpal_task
 */
function _erpal_projects_helper_get_tasks_of_project_having_no_task_parent($project_node) {
  //@TODO reimplement withh dnymaic fields and db_select
  $res = db_query('SELECT n.nid FROM {node} n 
    LEFT JOIN {field_data_field_project_ref} project ON n.vid=project.revision_id
    LEFT JOIN {field_data_field_parent} parent ON n.vid=parent.revision_id
    LEFT JOIN {node} node_parent_type ON node_parent_type.nid=parent.field_parent_target_id
    WHERE project.field_project_ref_target_id=:project_nid AND
    ((node_parent_type.type <> :parent_node_type) OR parent.field_parent_target_id IS NULL)
  ', array(':project_nid' => $project_node->nid, ':parent_node_type' => 'erpal_task'))
          ->fetchAll();

  $nids = array();
  foreach ($res as $nid_obj) {
    $nids[] = $nid_obj->nid;
  }

  return $nids;
}

/**
 * Return all tasks of a project that have no parent at all, these are tasks at the top level in a project
 */
function _erpal_projects_helper_get_tasks_of_project_having_no_parent($project_node) {
  //@TODO reimplement withh dnymaic fields and db_select
  $res = db_query('SELECT n.nid FROM {node} n 
    LEFT JOIN {field_data_field_project_ref} project ON n.vid=project.revision_id
    LEFT JOIN {field_data_field_parent} parent ON n.vid=parent.revision_id
    LEFT JOIN {node} node_parent_type ON node_parent_type.vid=parent.revision_id
    WHERE project.field_project_ref_target_id=:project_nid AND
    parent.field_parent_target_id IS NULL', array(':project_nid' => $project_node->nid))
          ->fetchAll();

  $nids = array();
  foreach ($res as $nid_obj) {
    $nids[] = $nid_obj->nid;
  }

  return $nids;
}

/**
 * Presave function for tasks
 */
function erpal_projects_helper_node_presave_task($node) {
  _erpal_projects_helper_task_set_project($node);
  _erpal_projects_helper_field_automation($node);
  if (!empty($node->original)) {
    _erpal_projects_helper_subscribe_task_assigned_users($node);
  }

  //if the node is new and has no value in field_weight set, we preset it with the current timestamp of the node
  $current_weight = !empty($node->field_weight[LANGUAGE_NONE][0]['value']) ? $node->field_weight[LANGUAGE_NONE][0]['value'] : 0;
  if ($node->is_new || strlen($current_weight) > 10) {
    $time = time();
    $node->field_weight[LANGUAGE_NONE][0]['value'] = -1 * substr($time."", 0, strlen($time) -1);  //if we dont cut the first digit (from left) of the time, it gets to bug when multiplied with 1
  }
}


/**
 * subscribe users assigned to task 
 */
function _erpal_projects_helper_subscribe_task_assigned_users($node) {
  $assigned = $assigned_original = $assigned_users_original = $assigned_users = array();

  // get uids of assigned users
  $assigned_users = field_get_items('node', $node, 'field_task_assigned_users');
  if (!empty($assigned_users) && is_array($assigned_users)) {
    foreach ($assigned_users as $assigned_user) {
      $assigned[] = $assigned_user['target_id'];
    }
  }
  // get uids of original assigned users
  if (isset($node->original))
    $assigned_users_original = field_get_items('node', $node->original, 'field_task_assigned_users');

  if (!empty($assigned_users_original) && is_array($assigned_users_original)) {
    foreach ($assigned_users_original as $assigned_user_original) {
      $assigned_original[] = $assigned_user_original['target_id'];
    }
  }

  // find added users
  $updated_diff = array_diff($assigned, $assigned_original);
  // find deleted users
  $original_diff = array_diff($assigned_original, $assigned);

  // subscribe users to the erpal_task
  if (!empty($updated_diff)) {
    _erpal_projects_helper_loop_task_users($updated_diff, $node, 'flag');
  }

  // unsubscribe users from the erpal_task
  if (!empty($original_diff)) {
    if (isset($node->original)) {
      _erpal_projects_helper_loop_task_users($original_diff, $node->original, 'unflag');
    }
  }
}

/**
 * helper function
 * subscribe / unsubscribe users from the erpal_task
 */
function _erpal_projects_helper_loop_task_users($assigned_users, $node, $action) {
  global $user;
  
  foreach ($assigned_users as $assigned_user) {
    
    //don't send email to the current user that assigned the task
    if ($assigned_user == $user->uid)
      continue;
    
    if ($account = user_load($assigned_user)) {
      // subscribe/unsubscribe users
      _erpal_projects_helper_flag($node->type, $node->nid, $action, $account);
      // send notification email to assigned user
      if ($action == 'flag' && $node->type == 'erpal_task') {
        _erpal_projects_helper_user_assigned_email($account, $node, 'assign');
      }
    }
  }
}

/**
 * This functions switches the percent value of a task if status changes
 * @TODO do this with rules.
 */
function _erpal_projects_helper_task_percent_automation($task_node) {
  //if task status term changed, set the percent value of the term, if one is set with respect to the 
  //method chosen in field_progress_calc_method
  $field_name = 'field_task_status_term';
  $status_tid = isset($task_node->{$field_name}[LANGUAGE_NONE][0]['tid']) ? $task_node->{$field_name}[LANGUAGE_NONE][0]['tid'] : false;

  if ($status_tid) {
    $term = taxonomy_term_load($status_tid);
    $original_node = isset($task_node->original) ? $task_node->original : false; //check if status really changed!
    //if nothing changed on status field, we skipp all operation because percent won't change
    if ($original_node) {
      $old_status_id = isset($original_node->{$field_name}[LANGUAGE_NONE][0]['tid']) ? $original_node->{$field_name}[LANGUAGE_NONE][0]['tid'] : false;

      if ($old_status_id == $status_tid)
        return;
    }

    $current_percent = isset($task_node->field_progress_percent[LANGUAGE_NONE][0]['value']) ? $task_node->field_progress_percent[LANGUAGE_NONE][0]['value'] : false;
    $new_percent = isset($term->field_progress_percent[LANGUAGE_NONE][0]['value']) ? $term->field_progress_percent[LANGUAGE_NONE][0]['value'] : false;
    if ($new_percent) {
      //only do something if there is a percent value for this term
      $calc_method = isset($term->field_progress_calc_method[LANGUAGE_NONE][0]['value']) ? $term->field_progress_calc_method[LANGUAGE_NONE][0]['value'] : 'set_max';
      $old_percent = false;
      $next_percent = false;
      if ($original_node) {
        //if we have the old version of the node, get the old percent value
        $old_percent = isset($original_node->field_progress_percent[LANGUAGE_NONE][0]['value']) ? $original_node->field_progress_percent[LANGUAGE_NONE][0]['value'] : false;
      }

      if ($old_percent !== false) {

        //if user already changed percent status by his own, we don't change anythihng  
        if ($old_percent != $current_percent)
          return;

        if ($calc_method == 'set_min')
          $next_percent = min($old_percent, $new_percent);
        else
          $next_percent = max($old_percent, $new_percent);
      } else {
        //there is no old node so the percent value should be 0 otherwise the user changed manuelly
        $next_percent = $new_percent;
        if ($current_percent > 0)
          return;
      }

      //now set the new percent value
      $task_node->field_progress_percent[LANGUAGE_NONE][0]['value'] = $next_percent;
    }
  }
  else
    return false;
}

/**
 * Set some fields in dependency of other fields
 */
function _erpal_projects_helper_field_automation($task_node) {

  _erpal_projects_helper_task_percent_automation($task_node);
}

/**
 * Set the project according to the parents project
 */
function _erpal_projects_helper_task_set_project($task_node) {

  if (!isset($task_node->field_parent[LANGUAGE_NONE][0]['target_id']))
    return;

  $parent_nid = $task_node->field_parent[LANGUAGE_NONE][0]['target_id'];
  $parent_node = node_load($parent_nid);
  $project_nid = _erpal_projects_helper_has_project($parent_node);

  if ($project_nid) {
    $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'] = $project_nid;
  }
}

/**
 * returns the activity which is related to a task over its related project
 */
function _erpal_projects_helper_get_activity_by_task($task_node) {
  $activity_node = false;
  if (isset($task_node->field_project_ref[LANGUAGE_NONE][0])) {
    $project_nid = $task_node->field_project_ref[LANGUAGE_NONE][0]['target_id'];
    $project_node = node_load($project_nid);
  }

  $activity_node = _erpal_projects_helper_get_activity_by_project($project_node);

  return $activity_node;
}

/**
 * Prepopulate some fields on task edit / insert form
 */
function _erpal_projects_helper_task_edit_form_prepopulate(&$form) {
  //IS_TICKET
  $key = 'field_is_ticket';
  if (isset($_GET[$key])) {
    //prepopulate the ticket field
    $value = $_GET[$key] ? 1 : 0;
    $form['field_is_ticket'][LANGUAGE_NONE]['#default_value'] = $value;
    //now hide it
    $form['field_is_ticket'][LANGUAGE_NONE]['#type'] = 'value';
  }

  //PROJECT_REF
  $key = 'field_project_ref';
  if (isset($_GET[$key]) && $_GET[$key]) {
    //prepopulate the project_ref field

    $value = _erpal_basic_helper_autocomplete_string_from_nid($_GET[$key]);
    $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'] = $value;
    //now hide it
    $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
  }
}

/**
 * Alters the tasks form
 */
function _erpal_projects_helper_task_node_form_alter(&$form, &$form_state) {
  //only if node will be new created
  $nid = $form['nid']['#value'];
  if (!$nid) {
    //if parent is already set, hide the project field, but preset it so pricing information can be reloaded!
    if (isset($form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value'])) {
      if ($form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value']) {
        $parent_nid = $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value'];
        $parent_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($parent_nid);
        $parent_node = node_load($parent_nid);
        $project_nid = _erpal_projects_helper_has_project($parent_node);
        
        $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
        $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'] = _erpal_basic_helper_autocomplete_string_from_nid($project_nid);

        $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#required'] = false;  //will be automatically set @see _erpal_projects_helper_task_set_project in task.inc again
      }

      //parent is not required here and it is already set as default value
      $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
      $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#required'] = false; //@TODO: this could also be done by configuring the entityreference prepopulate for this behaviour
    }

    // Handle page title.
    $task_type = 'task';
    if (!empty($_GET['field_is_ticket'])) {
      $task_type = 'ticket';
    }
    
    // Check is task has parent task.
    if(!empty($parent_node->title)) {
      // Add task name to title.
      drupal_set_title(t("Create a sub$task_type of \"!title\"", array(
        '!title' => $parent_node->title,
      )));
    }
    
    // Add project name to page title.
    else
    if (!empty($_GET['field_project_ref'])) {
      // Get project node.
      if ($project = node_load($_GET['field_project_ref'])) {
        // Add project name to page title.
        drupal_set_title(t("Create a $task_type for \"!title\"", array(
          '!title' => $project->title,
        )));
      }
    }
    // Show simple title if we can't detect parent.
    else
    // If we create a task of with field_is_ticket set, change the title of the 
    // node add form.
    if (!empty($_GET['field_is_ticket'])) {
      drupal_set_title(t('Create a ticket'));
    } 
    else {
      drupal_set_title(t('Create a task'));
    }

    $parent_nid = isset($parent_nid) ? $parent_nid : false;

    _erpal_projects_helper_task_preset_deadline($form, $parent_nid);
  } else {
    //hide parent and project ref anyway!
    $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
    $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#type'] = 'value';
    $form['field_parent']['#access'] = FALSE;  //add this so if the node references a parent where the user has no access to, the validation will be skipped. Otherwise the validation error that the referenced entity is invalid (because of no view access) will prevent from saving the edit form.
    
    //rename the title for tasks and tickets.
    $node = $form['#node'];
    if (!empty($node->field_is_ticket[LANGUAGE_NONE][0]['value'])) {
      //a ticket
      drupal_set_title(t('Edit ticket !title', array('!title' => $node->title)));
    } else {
      //a task
      drupal_set_title(t('Edit task !title', array('!title' => $node->title)));
    }
  }
}

/**
 * Prepend task time fields validation
 */
function _erpal_projects_helper_task_add_time_validation(&$form, $form_state) {
  // prepend field_timetracking_duration element validation
  array_unshift($form['field_estimated_time'][LANGUAGE_NONE][0]['value']['#element_validate'], '_erpal_projects_helper_time_field_validate');
}

/**
 * If task has a parent (task or project) and this parent has a deadline set, we preset the deadline on the task. If there is no deadline, we dont preset any deadline
 */
function _erpal_projects_helper_task_preset_deadline(&$form, $parent_nid = false) {
  $parent_nid = isset($parent_nid) && $parent_nid ? $parent_nid : $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'];
  if (!is_numeric($parent_nid))
    $parent_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($parent_nid);
  if ($parent_nid) {
    $parent_node = node_load($parent_nid);

    $deadline = false;

    if ($parent_node != 'erpal_task' && $parent_node != 'erpal_project') {  //it may be also a book but a book has no deadline
      $project_nid = isset($form['field_project_ref'][LANGUAGE_NONE][0]['target_id']) ? $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'] : false;
      if ($project_nid) {
        $project_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($project_nid);
        $parent_node = node_load($project_nid);
      }
    }

    $deadline = _erpal_projects_helper_parent_deadline($parent_node);

    if ($deadline) {
      //now preselect in the form
      $form['field_date'][LANGUAGE_NONE][0]['#default_value']['value'] = $deadline;
    }
  }
}

/**
 * Searchs up in the tree until a deadline is found
 */
function _erpal_projects_helper_parent_deadline($node) {

  $deadline = isset($node->field_date[LANGUAGE_NONE][0]['value2']) &&
          $node->field_date[LANGUAGE_NONE][0]['value2'] ?
          $node->field_date[LANGUAGE_NONE][0]['value2'] : false;

  if ($deadline)
    return $deadline;

  if ($node->type == 'erpal_project' && !$deadline)
    return false;  //because a Project will not have a parent


    
//here we have no deadline, so get the parent and check its deadline.
  $parent_node = _erpal_project_task_parent($node);

  return _erpal_projects_helper_parent_deadline($parent_node);
}

/**
 * Implements hook_erpal_clone_node_alter to alter task node if cloned
 * @param $node is the new cloned node
 * @param $args[parent_nid] is the nid of the new parent_node of the cloned node
 * @param $args[options] some options given to the clone process
 */
function erpal_projects_helper_erpal_clone_node_alter($node, $args) {
  $parent_nid = $args['parent_nid'];
  $options = $args['options'];

  if ($node->type == 'erpal_task') {
    //ensure that the correct project is set to the task
    //even this is done in presave (@see erpal_projects_helper_node_presave_task) it is important to ensure, so we do it again here after cloning
    _erpal_projects_helper_task_set_project($node);

    //prepare other task node attributes according to option
    if ($options['reset_task_status']) {
      $vid = _erpal_basic_helper_term_field_get_vid('field_task_status_term');
      $default_tid = _erpal_basic_helper_get_default_tid($vid);
      $node->field_task_status_term[LANGUAGE_NONE][0]['tid'] = $default_tid;
      $node->field_progress_percent[LANGUAGE_NONE][0]['value'] = 0;
    }

    //anyway, delete the assigned user because this will be a ressource planing issue
    unset($node->field_task_assigned_users);
  }
}

/**
 * Implements hook_erpal_clone_node_postprocess_alter to add the new book to the given project
 */
function erpal_projects_helper_erpal_clone_node_postprocess_alter($node, $args) {
  $parent_nid = $args['parent_nid'];
  $options = $args['options'];

  if ($node->type == 'erpal_book') {
    //Link new book to selected project and delete all references to exported files of the new 
    //if tasks are cloned, they will be added to this project

    if ($options['project']) {
      $project_nid = $options['project'];
      $project_node = node_load($project_nid);
      $project_node->field_books_ref[LANGUAGE_NONE][]['target_id'] = $node->nid;
      node_save($project_node);
    }
  }
}

/**
 * function returns all tickets of the given nids array by only one query. Otherwise we have to load the complete node always which will kill the performance
 */
function _erpal_projects_get_tickets_from_tasks($task_nids) {

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
          ->propertyCondition('nid', $task_nids, 'IN')
          ->entityCondition('bundle', 'erpal_task')
          ->fieldCondition('field_is_ticket', 'value', 0, '>');

  $result = $query->execute();

  $ticket_nids = array();
  if (isset($result['node'])) {
    $ticket_nids = array_keys($result['node']);
  }

  return $ticket_nids;
}

/**
 * Returs true if panes in the right side bar of task view should be invisible
 */
function _erpal_projects_helper_hide_task_right_panes() {
  $task_tab_page = isset($_GET['qt-task_content_tabs']) && $_GET['qt-task_content_tabs'] ? $_GET['qt-task_content_tabs'] : false;
  $ticket_tab_page = isset($_GET['qt-ticket_content_tabs']) && $_GET['qt-ticket_content_tabs'] ? $_GET['qt-ticket_content_tabs'] : false;
  if ($task_tab_page == 3 || $task_tab_page == 2 || $task_tab_page == 1) {
    return true;
  }

  if ($ticket_tab_page == 3 || $ticket_tab_page == 2 || $ticket_tab_page == 1) {
    return true;
  }

  return false;
}

/**
 * Returns all parent tasks of a given task
 */
function _erpal_projects_helper_get_parent_tasks($task_node, $parent_nodes = array()) {

  if (!is_object($task_node))
    $task_node = node_load($task_node);

  $parent_nid = isset($task_node->field_parent[LANGUAGE_NONE][0]) ? $task_node->field_parent[LANGUAGE_NONE][0]['target_id'] : false;

  if (!$parent_nid)
    return $parent_nodes;

  $parent_node = node_load($parent_nid);
  $parent_nodes[] = $parent_node;

  $further_parent_nodes = _erpal_projects_helper_get_parent_tasks($parent_node);

  //get further parents
  $parent_nodes = array_merge($parent_nodes, $further_parent_nodes);

  return $parent_nodes;
}

/**
 * @return the parent node of the given task or project node. FALSE if no parent could be found
 * @param $node a erpal_task or erpal_project node to determine the parent
 */
function _erpal_project_task_parent($node) {

  if (is_numeric($node) && !is_object($node)) {
    $node = node_load($node);
  }
  
  // Check node type. Only task can have a parent.
  if ($node->type != 'erpal_task') {
    return FALSE;
  }

  //ok, this is a task
  //does it have a direct parent?
  $parent_nid = false;
  $project_nid = $node->field_project_ref[LANGUAGE_NONE][0]['target_id'];

  if (isset($node->field_parent[LANGUAGE_NONE][0]['target_id'])) {
    $parent_nid = $node->field_parent[LANGUAGE_NONE][0]['target_id'];
  } else {
    //if there is no direct parent, use the project as parent with its pricing information
    $parent_nid = $project_nid;
  }

  if ($parent_nid) {
    $parent_node = node_load($parent_nid);
    //if parent node is not a task or a project, use the referenced project
    if (empty($parent_node) ||  ($parent_node->type != 'erpal_task' && $parent_node->type != 'erpal_project')) {
      $parent_node = node_load($project_nid);
    }

    return $parent_node;
  }

  return false;
}

/**
 * Fallows the same logic as @see _erpal_project_task_parent but uses a task edit form with prepopulated project or if there is a
 * prepopulate paremter in the url (e.g. ?field_project_ref=1682)
 */
function _erpal_project_task_parent_from_form($form) {
  $nid = $form['nid']['#value'];

  $type = $form['type']['#value'];
  if ($type != 'erpal_task')
    return false; //only task have a parent


    
//ok, this is a task
  //does it have a direct parent?
  $parent_nid = false;
  $project_nid = isset($form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value']) ? $form['field_project_ref'][LANGUAGE_NONE][0]['target_id']['#default_value'] : false;

  if ($project_nid) {
    //get from autocomplete string
    $project_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($project_nid);
  } else {
    //may be get from URL
    $project_nid = isset($_GET['field_project_ref']) ? $_GET['field_project_ref'] : false;
  }

  if (!$project_nid)
    return false;

  $parent_nid = isset($form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value']) ? $form['field_parent'][LANGUAGE_NONE][0]['target_id']['#default_value'] : false;

  if (!$parent_nid) {
    //if there is no direct parent, use the project as parent with its pricing information
    $parent_nid = $project_nid;
  } else {
    //get from autocomplete
    $parent_nid = _erpal_basic_helper_get_nid_from_autocomplete_string($parent_nid);
  }

  if ($parent_nid) {
    $parent_node = node_load($parent_nid);
    //if parent node is not a task or a project, use the referenced project
    if ($parent_node->type != 'erpal_task' && $parent_node->type != 'erpal_project') {
      $parent_node = node_load($project_nid);
    }

    return $parent_node;
  }

  return false;
}