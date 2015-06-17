<?php

/**
 * project team filter handler
 */
class erpal_projects_relations_handler_erpal_projects_relations_filter extends views_handler_filter {

  function query() {
    // get target node id
    if (!$id = _erpal_projects_relations_get_nid())
      return FALSE;

    // get project team
	$entity_type = arg(0);
    $users = _erpal_projects_relations_parent_team($id, $entity_type);
    $uids = array_keys($users);
    // filter users that belong to project team
    if (!empty($uids)) {
      $this->ensure_my_table();
      $alias = $this->table_alias;
      $this->query->add_where($alias, "$alias.uid", $uids, "IN");
    }
  }

}

/**
 * project team filter handler
 */
class erpal_projects_relations_handler_erpal_projects_relations_team_filter extends views_handler_filter_many_to_one {

  function query() {
    if (!empty($this->value)) {
      $uids = $this->value;
      $this->ensure_my_table();
      $alias = $this->table_alias;
      $this->query->add_where($alias, "$alias.field_task_assigned_users_target_id", $uids, "IN");
    }
  }

  /**
   * Subtasks checkbox. Provides show/hide choise
   */
  function value_form(&$form, &$form_state) {
    $options = array();
    
    // get target node id
    if ($pid = _erpal_projects_relations_get_pid()) {
      // get project team
      $users = _erpal_projects_relations_team($pid);
      foreach ($users as $uid => $user_value) {
        $options[$uid] = $user_value;
      }
    }
    $form['value'] = array(
      '#type' => 'select',
      '#title' => t('Users'),
      '#options' => $options,
      '#multiple' => TRUE,
    );
    return $form;
  }

}
