<?php

/**
 * @file 
 * erpal_docs_access class
 * applies accesss grants of parent entity to child per each user
 */
class erpal_docs_access {

  public $uid;
  public $user_action;
  public $user_parent;
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

  const AUL_PRIO = 0;
  const AUL_MODULE = 'erpal_docs_access';

  function __construct($uid, $nid, $node_type, $action, $parent, $user_action = NULL, $user_parent = NULL, $node = NULL) {
    $this->uid = $uid;
    $this->user_action = $user_action;
    $this->user_parent = $user_parent;
    $this->nid = $nid;
    $this->node_type = $node_type;
    $this->action = $action;
    $this->parent = $parent;

    if (!$node) {
      $this->node = node_load($nid);
    }
    else {
      $this->node = $node;
    }

    // create aul operations
    foreach ($this->operations as $op) {
      $aul_name = $op . '_aul';
      $this->{$aul_name} = $this->init_aul($op);
    }
  }

  /**
   * Initialises the AULs of a docs and returns their IDs in an array
   * @param type $op
   * @param type $delete
   *   optional parameter for recreation
   * @return type
   */
  function init_aul($op = NULL, $recreate = FALSE) {

    $aul_name = $this->get_aul_name($op);

    // get aul id or create new if doesn't exist
    $aul_id = aul_get_id_by_name(self::AUL_MODULE, $aul_name);
    // delete if it's needed
    if ($aul_id && $recreate) {
      aul_delete_aul($aul_id);
    }
    // create new if it doesn't exist or was deleted
    if (!$aul_id || $recreate) {
      $aul_id = aul_create_aul(self::AUL_MODULE, $aul_name);
    }

    return $aul_id;
  }

  /**
   * Returns the name of a AUL for a given operation
   * @param type $op
   * @return string
   */
  function get_aul_name($op) {
    // create aul name in format: $op_node
    $name = $op . '_uid_' . $this->uid;
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
    if (empty($settings)) {
      return FALSE;
    }

    // Reset the permissions cache.
    drupal_static_reset('node_access');

    // loop all needed fields in saved entitiy types and bundles
    foreach ($settings as $entity_type => $bundles) { // foreach 4
      foreach ($bundles as $bundle => $fields) { // foreach 3
        if (!is_array($fields)) {
          continue;
        }
        foreach ($fields as $field) { // foreach 2
          if (!$field) {
            continue;
          }

          // get all child entity parents
          if (!$parents = $this->get_parents($field, $bundle)) {
            continue;
          }

          // get access of all parent nodes
          foreach ($parents as $parent_id) { // foreach 1 (with break)
            if ($comment_parent_nid = $this->check_comment($entity_type, $parent_id)) {
              $entity_type = 'node';
              $parent_id = $comment_parent_nid;
            }

            // check access in saved values
            if (!isset($access_cache[$entity_type][$parent_id])) {
              
              // If user is removed from parent - remove grants.
              if ($this->user_action == 'removed' && $this->user_parent == $parent_id) {
                $access_cache[$entity_type][$parent_id] = array(
                  'view' => 0,
                  'update' => 0,
                  'delete' => 0,
                );
                continue;
              }
              
              // load parent entity
              $entity_loaded = entity_load($entity_type, array($parent_id));

              if (!is_array($entity_loaded)) {
                continue;
              }

              $parent_entity = array_shift($entity_loaded);
              if (!$parent_entity) {
                continue;
              }

              // check access of parent entity
              foreach ($this->operations as $op) {
                // check parent entity access
                if (!$access[$op]) {
                  if ($entity_access = entity_access($op, $entity_type, $parent_entity, $account)) {
                    $access[$op] = 1;
                  }
                }
              }
              // save entity access
              $access_cache[$entity_type][$parent_id] = $access;
            }
            // get saved access value
            else {
              $access = $this->array_or($access, $access_cache[$entity_type][$parent_id]);
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
    $this->add_aul($account->uid, $access);

    // rebuild child entity grants
    node_access_acquire_grants($this->node);
  }
  
  /**
   * Merge twp arrays with or condition.
   * 
   * @param array $array1
   *   Array number 1
   * @param array $array2
   *   Array number 2
   * 
   * @return array
   *   Merged array
   */
  function array_or(array $array1, array $array2) {
    
    if(!empty($array1)) {
      foreach ($array1 as $key => $value) {
        if(!empty($array2[$key])) {
          $array1[$key] = $value || $array2[$key];
        }
      }
    }
    if(!empty($array2)) {
      foreach ($array2 as $key => $value) {
        if(!isset($array1[$key])) {
          $array1[$key] = $value;
        }
      }
    }
    
    return $array1;
  }

  /**
   * Save AUL with rermissions. 
   * Provides also creation of AUL if one doesn't exist
   * @param array $access
   *   array of permissions. can contain view, update, delete items
   */
  function add_aul($uid, $access) {
    // check access of parent entity
    foreach ($access as $op => $value) {
      // check parent entity access
      if(isset($this->{$op . '_aul'})) {
        $aul_id = $this->{$op . '_aul'};
      }

      // check access value access
      if ($value && !empty($aul_id)) {
        $perm = array(
          'view' => 0,
          'update' => 0,
          'delete' => 0,
        );
        $perm[$op] = 1;
        // add user access
        aul_user_add_aul($uid, $aul_id, $perm['view'], $perm['update'], $perm['delete'], self::AUL_PRIO);
        aul_add_node($aul_id, $this->nid);
      }
      // remove user access
      else {
        aul_remove_node($aul_id, $this->nid);
      }
    }
  }

  function check_comment($entity_type, $cid) {
    if ($entity_type == 'comment' /* && $this->action == 'removed' */) {
      $query = db_select('comment', 'c');
      $query->fields('c', array('nid'));
      $query->condition('c.cid', $cid);
      $query->distinct();

      $nid = $query->execute()->fetchField();

      return $nid;
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

    $results = array();
    $table = 'field_data_' . $field_name;
    $field = $field_name . '_target_id';
    if (empty($results) && db_field_exists($table, $field)) {
      $query = db_select($table, 'f');
      $query->fields('f', array('entity_id'));
      // set offset of entity_id 
      if ($offset) {
        $query->condition('f.entity_id', $offset, '!=');
      }
      $query->condition('f.bundle', $bundle);
      $query->condition('f.' . $field, $target_id);
      $query->distinct();

      $references = $query->execute();
      $results = array();
      foreach ($references as $reference) {
        $results[$reference->entity_id] = $reference->entity_id;
      }
    }
    return $results;
  }

}
