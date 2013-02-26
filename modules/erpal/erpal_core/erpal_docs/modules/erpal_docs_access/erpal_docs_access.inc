<?php

/**
 * @file 
 * erpal_docs_access class
 * applies accesss grants of parent entity to child per each user
 */
class erpal_docs_access {

  public $nid;
  public $node_type;
  public $action;
  public $parent;
  public $node;
  private $operations = array(
    'view',
    'update',
    'delete',
  );

  const ACL_PRIO = 0;
  const OPERATION = 'referenced';
  const ACL_TITLE = 'erpal_docs_access';

  function __construct($nid, $node_type, $action, $parent, $node = NULL) {
    $this->nid = $nid;
    $this->node_type = $node_type;
    $this->action = $action;
    $this->parent = $parent;

    if (!$node)
      $this->node = node_load($nid);
    else
      $this->node = $node;

    // create acl operations
    foreach ($this->operations as $op) {
      $acl_name = $op . '_acl';
      $this->{$acl_name} = $this->init_acl($op);
    }
  }

  /**
   * Initialises the ACLs of a docs and returns their IDs in an array
   * @param type $op
   * @param type $delete
   *   optional parameter for recreation
   * @return type
   */
  function init_acl($op = NULL, $recreate = FALSE) {

    $acl_name = $this->get_acl_name($this->nid, $op, $this->node_type);

    // get acl id or create new if doesn't exist
    $acl_id = acl_get_id_by_name(self::ACL_TITLE, $acl_name);
    // delete if it's needed
    if ($acl_id && $recreate)
      acl_delete_acl($acl_id);
    // create new if it doesn't exist or was deleted
    if (!$acl_id || $recreate)
      $acl_id = acl_create_new_acl(self::ACL_TITLE, $acl_name);

    return $acl_id;
  }

  /**
   * Returns the name of a ACL for a given node and a given Operation
   * @param type $nid
   * @param type $op
   * @param type $node_type
   * @return string
   */
  function get_acl_name($nid, $op, $node_type = FALSE) {
    if (!$op)
      $op = self::OPERATION;

    if (!$node_type)
      $node_type = $this->node_type;
    // create acl name in format: $op_$node_type_$nid;
    $name = $op . '_' . $node_type . '_' . $nid;
    return $name;
  }

  /**
   * build user permissions for child node
   * @param type $account
   * @param type $settings
   * @param type $access_cache
   */
  function build_user_permissions_for_node($account, $settings, &$access_cache) {
    // handle access
    $access = array(
      'view' => 0,
      'update' => 0,
      'delete' => 0,
    );
    if(empty($settings))
      return FALSE;
    
    // loop all needed fields in saved entitiy types and bundles
    foreach ($settings as $entity_type => $bundles) { // foreach 4
      foreach ($bundles as $bundle => $fields) { // foreach 3
        if (!is_array($fields))
          continue;
        foreach ($fields as $field) { // foreach 2
          if (!$field)
            continue;
          
          // get all child entity parents
          if (!$parents = $this->get_parents($field, $bundle))
            continue;

          // get access of all parent nodes
          foreach ($parents as $parent_nid) { // foreach 1 (with break)
            // check access in saved values
            if (!isset($access_cache[$entity_type][$parent_nid])) {
              // load parent entity
              if (!$parent_entity = array_shift(entity_load($entity_type, array($parent_nid))))
                continue;

              // check access of parent entity
              foreach ($this->operations as $op) {
                // check parent entity access
                if ($entity_access = entity_access($op, $entity_type, $parent_entity, $account)) {
                  $access[$op] = 1;
                }
              }
              // save entity access
              $access_cache[$entity_type][$parent_nid] = $access;
            }
            // get saved access value
            else {
              $access = $access_cache[$entity_type][$parent_nid];
            }
            // if there are all grants break the child_id iteration
            if (!empty($access['view']) && !empty($access['update']) && !empty($access['delete'])) {
              // break of the "$settings" foreach
              break 4; // break foreach 4
            }
          }
        }
      }
    }

    // apply entity access to user
    $this->add_acl($account->uid, $access);

    // rebuild child entity grants
    node_access_acquire_grants($this->node);
  }

  /**
   * Save ACL with rermissions. 
   * Provides also creation of ACL if one doesn't exist
   * @param array $access
   *   array of permissions. can contain view, update, delete items
   */
  function add_acl($uid, $access) {
    // check access of parent entity
    foreach ($access as $op => $value) {
      // check parent entity access
      $acl_id = $this->{$op . '_acl'};

      // check access value access
      if ($value) {
        $perm = array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        );
        $perm[$op] = 1;
        // add user access
        acl_node_add_acl($this->nid, $acl_id, $perm['view'], $perm['update'], $perm['delete'], self::ACL_PRIO);
        acl_add_user($acl_id, $uid);
      }
      // remove user access
      else {
        acl_remove_user($acl_id, $uid);
      }
    }
  }

  /**
   * Get all parent entities in field
   * @param type $target_id
   * @param type $field_name
   * @param type $bundle
   * @return type
   */
  function get_parents($field_name, $bundle) {
    $target_id = $this->nid;
    // set offset of entity_id for parrent if child was removed from parent
    $offset = FALSE;
    if ($this->action == 'removed') {
      $offset = $this->parent;
    }

    // @todo: static cache
    //$results = &drupal_static(__FUNCTION__);
    //if($reset)
    $results = array();
    $table = 'field_data_' . $field_name;
    $field =  $field_name . '_target_id';
    if (empty($results) && db_field_exists($table, $field)) {
      $query = db_select($table, 'f');
      $query->fields('f', array('entity_id'));
      // set offset of entity_id 
      if ($offset) {
        $query->condition('f.entity_id', $offset, '!=');
      }
      $query->condition('f.bundle', $bundle);
      $query->condition('f.' . $field, $target_id);
      // $query->condition('f.entity_type', 'node')
      $query->distinct();

      $references = $query->execute();
      $results = array();
      foreach ($references as $reference) {
        $results[$reference->entity_id] = $reference->entity_id;
      }
    }
    return $results;
  }

  /**
   * --------------
   * Deletes all ACLs and clears the lists where a node is manages
   * @param type $nid
   */
  static

  function clear_node_acl($nid) {
    //first, get all ACLs where the node is in
    $acls = array();
    $select = db_select('acl_node', 'an')
      ->fields('an', array('acl_id'))
      ->condition('an.nid', $nid);

    $result = $select->execute();
    //then delete the ACLs 
    while ($record = $result->fetchAssoc()) {
      acl_delete_acl($record['acl_id']);
    }
  }

  /**
   * Initialises the ACLs of a docs and returns their IDs in an array
   * @param type $op
   * @param type $delete
   *   optional parameter for recreation
   * @return type
   */
  function delete_acl($op = NULL) {
    if (!$op)
      $op = self::OPERATION;

    $acl_name = $this->get_acl_name($this->nid, $op, $this->node_type);

    // delete if it's needed
    if ($acl_id = acl_get_id_by_name(self::ACL_TITLE, $acl_name))
      acl_delete_acl($acl_id);
  }

}

