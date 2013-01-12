<?php

/**
 * Handles the jobs for the synching process.
 * Rows of the table:
 *  jid:int(11) = Job ID
 *  uid:int(11) = User id that started the job
 *  timestamp:int(11) = start time
 *  complete:int(11) = complete (0|1)
 *  data:longblob
 * 
 * @author Sebastian
 */
class BsSyncJobHandler {

  static private $tablename = 'bs_syncml_jobs';
  static private $tablealias = 'bsj';

  /**
   * Creates a job with an array of sync ids and the user id
   * @param type $sids
   * @param type $uid 
   */
  static function createSyncJob($sids, $uid) {

    $sids = json_encode($sids);

    $fields = array(
        'uid' => $uid,
        'timestamp' => time(),
        'complete' => 0,
        'data' => $sids,
    );
    $result = db_insert(self::$tablename)
            ->fields($fields)
            ->execute();

    return $result;
  }

  /**
   * Process a job
   * @param type $jid 
   */
  static function processJob($jid) {

    // TODO
    
    $sids = array(1,2,3,4);
    
    return $sids;
  }

  /**
   * Returns the Job data without the SIDs
   * @param int $jid
   * @return object 
   */
  static function getJob($jid) {

    $result = db_select(self::$tablename, self::$tablealias)
            ->fields(self::$tablealias, array('jid', 'uid', 'timestamp', 'complete'))
            ->condition('jid', $jid)
            ->execute()
            ->fetch();

    return $result;
  }

  /**
   * Returns the job 
   * @param int $jid
   * @return array 
   */
  static function getSids($jid) {

    $result = db_select(self::$tablename, self::$tablealias)
            ->fields(self::$tablealias, array('data'))
            ->condition('jid', $jid)
            ->execute()
            ->fetch();
    if (isset($result->data))
      return json_decode($result->data);
    else
      return null;
  }

  /**
   * Removes a sync job via the job id
   * @param type $jid Job ID
   */
  static function removeSyncJob($jid) {

    db_delete(self::$tablename)
            ->condition('jid', $jid)
            ->execute();
  }

}