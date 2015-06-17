<?php
/**
 * Files model for CRUD operations
 */
class erpal_docs_helper_files {

  /**
   * Get files task and it's subtasks tree
   * @param int $nid
   *   nid of task
   */
  function task_children_get_files($nid) {
    $child_nids = _erpal_projects_helper_get_children($nid);
    $query = db_select('field_data_field_asset_files', 'f');
    $query->leftJoin('field_data_field_project_ref', 'p', 'p.entity_id = f.entity_id');
    $query->fields('f', array('field_asset_files_target_id'));
    $query->condition('f.entity_id', $child_nids, 'IN');
    $result = $query->execute();

    return $result;
  }

  /**
   * Get files of project and it's tasks tree
   * @param int $nid
   *   nid of project
   */
  function project_children_get_files($nid) {
    // Get files of project and it's child tasks
    $query = db_select('field_data_field_asset_files', 'f');
    $query->leftJoin('field_data_field_project_ref', 'p', 'p.entity_id = f.entity_id');
    $query->fields('f', array('field_asset_files_target_id'));
    $query->condition(
      db_or()
        ->condition('p.field_project_ref_target_id', $nid)
        ->condition('f.entity_id', $nid)
    );
    $result = $query->execute();

    return $result;
  }
  
  /**
   * Get direct files of entity
   * @param int $nid
   *   nid of project
   */
  function entity_get_files($eid){
    // Get files of project and it's child tasks
    $query = db_select('field_data_field_asset_files', 'f');
    $query->fields('f', array('field_asset_files_target_id'));
    $query->condition('f.entity_id', $eid);
    $result = $query->execute();

    return $result;
  }

}
