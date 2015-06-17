<?php

/**
 * @file
 * Hooks provided by the Node module.
 */

/**
 * Alter users list that must be handled right after entity insert/update/delete 
 * for rebuilding access permissions on related child entities.
 * 
 * @param array $users
 *   Users list that must be handled
 * @param object $entity
 *   Inserted/updated/deleted entity
 * @param string $entity_type
 *   Entity type
 * @param string $bundle
 *   Entity bundle
 * @param string $action
 *   Depends on entity action. Can be 'insert', 'update', 'delete'
 */
function hook_erpal_docs_access_users(&$users, $entity, $entity_type, $bundle, $action) {
  if ($action == 'update') {
    if (!empty($entity) && $entity_type == 'node' && $bundle == 'basic_page') {
      $users = array(1, 2, 3);
    }
  }
}
