<?php

/**
 * Handles the table for waiting jobs.
 * Rows of the table:
 *  sid:int(11) = SyncID
 *  nid:int(11) = NID of the node to sync
 *  timestamp:int(11) = last update
 *  changed:int(11) = changed (0|1)
 *  data:longblob
 * 
 * @author serkan
 */
class BsSyncMlDataHandler {

  static private $tablename = 'bs_syncml_items';
  static private $tablealias = 'bssi';
  static private $where_in_limit = 100; //determine how many items should be in a 'WHERE xyz IN()'-Clause

  /**
   *  Wrapper for db_insert
   * @param String $data
   * @param int $nid
   * @return type 
   */
  static function create($data, $nid = null) {
    $fields = array(
        'nid' => isset($nid) ? $nid : 0,
        'timestamp' => time(),
        'changed' => 1,
        'data' => $data,
    );
    $query = db_insert(self::$tablename)->fields($fields);
    $result = $query->execute();
    return $result;
  }

  /**
   * GETTER METHODS 
   */
  
  /**
   *
   * @param type $sids
   * @return type 
   */
  static function get_items_by_sids($sids) {
    
    if(is_array($sids)) {
      return self::get_items_by_ids($sids, 'sid');
    }
    else {
      return self::get_item_by_id($sids, 'sid');
    }
    
  }
  
  static function get_items_by_nids($nids) {
    
    if(is_array($nids)) {
      return self::get_items_by_ids($nids,'nid');
    }
    else {
      return self::get_item_by_id($nids,'nid');
    }
  }
  /**   
   * Get a single item-array by SID or NID
   * @param type $id
   * @param string $key SID or NID
   * @return type 
   */
  static private function get_item_by_id($id,$key) {
    if($key != 'nid' && $key != 'sid') return FALSE;
    return db_select(self::$tablename, self::$tablealias)
                    ->fields(self::$tablealias)
                    ->condition($key, $id, '=')
                    ->execute()
                    ->fetchAssoc();
  }
  
  /**
   *  Get an Array of item-arrays
   * @param array $ids An array of SIDs/NIDs
   * @param string $key SID or NID
   * @return array[array] An array item-arrays 
   */
  static private function get_items_by_ids($ids,$key) {
    if($key != 'nid' && $key != 'sid') return FALSE;
    //Chunk the Array, walk throug the chunks, and get the results of each chunk.
    $sid_chunks = array_chunk($ids, self::$where_in_limit);    
    $return = array();
    foreach ($sid_chunks as $sid_chunk) {

      $result = db_select(self::$tablename, self::$tablealias)
              ->fields(self::$tablealias)
              ->condition($key, $sid_chunk, 'IN')
              ->execute();
      //Go through the resultset, save each record for returning
      while ($record = $result->fetchAssoc()) {
        $return[] = $record;
      }
    }

    return $return;
  }
  
  /**
   * Returns an array of changed items 
   * 
   * @params array $nids The nids to look for beeing changed  
   */
  static function get_changed_items($nids = array()) {
    
    
    $nid_chunks = array_chunk($nids,self::$where_in_limit);
    $return = array();
    foreach ($nid_chunks as $nid_chunk) {
      $result = db_select(self::$tablename, self::$tablealias)
              ->fields(self::$tablealias)
              ->condition('changed', 1, '=')
              ->condition('nid', $nid_chunk, 'IN')
              ->execute();

      while ($record = $result->fetchAssoc()) {
        $return[] = $record;
      }
    }
    
    return $return;
  }
  
  
  /**
   * END OF GETTERS 
   */
  
  
  
  /**
   * SETTER METHODS 
   */
  /**
   *  Set the changed-state
   * @param type $sid The sid of the record to change
   * @param type $status The state to set, default is 1
   * @return type returns the result of execute()
   */
  static function set_changed($sid,$status=1) {
    $query =  db_update(self::$tablename)    
                ->fields(array('changed'=>$status))
                ->condition('sid',$sid,'=');
    
    
    return $query->execute();
  }
  /**
   *  clear the changed-state (set it to 0)
   * @param type $sid The sid of the record to change
   * @return type returns the result of set_changed
   */
  static function clr_changed($sid) {
    return set_changed($sid,0);
  }
  
  /**
   *  Set data of an item
   * @param type $sid The sid of the item
   * @param type $data The data to set   
   */
  static function set_data($sid,$data) {
     $query = db_update(self::$tablename)
                ->fields(array('data'=>$data,'timestamp'=>time()))
                ->condition('sid',$sid,'=');
     
     return $query->execute();
  }
  
  /**
   *  Set the timestamp
   * @param type $sid The sid of the item
   * @param type $timestamp The timestamp so set, default is current time.
   * @return type 
   */  
  static function set_timestamp($sid,$timestamp=NULL) {
      if($timestamp === NULL) {
        $timestamp = time();
      }
      $query =  db_update(self::$tablename)
                  ->fields(array('timestamp'=>$timestamp))
                  ->condition('sid',$sid,'=');
      
      return $query->execute();
  }
  
  /**
   * END SETTER METHODS 
   */

  /**
   *  Delete item/s by sid
   * @param type $sid
   * @return type 
   */
  static function delete_by_sid($sid) {
    $query =  db_delete(self::$tablename)
                ->condition('sid',$sid,'=');
    
    return $query->execute();
  }
  
  static function delete_by_nid($nid) {
    $query =  db_delete(self::$tablename)
                ->condition('nid',$nid,'=');
    
    return $query->execute();
  }
  
}

