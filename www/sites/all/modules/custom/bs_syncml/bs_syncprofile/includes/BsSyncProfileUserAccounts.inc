<?php

/**
 * Handles the table user accounts per profile.
 * Creates and reads the Account Data Table entries
 * 
 * @author Sebastian Kauschke
 */
class BsSyncProfileUserAccounts {

  static private $tablename = 'bs_syncprofile_useraccounts';
  static private $tablealias = 'bspu';

  /**
   *  Writes an account
   * @param $uid  The user id
   * @param $profile The profile machine name
   * @param $enabled enabled 1 or 0
   * @param $account The Syncml Account name
   * @param $pass The Syncml accounts password
   * 
   * @return Success true/false
   */
  static function write($uid, $profile, $enabled, $account, $pass) {

     $fields = array(
        'uid'     => $uid,
        'profile' => $profile,
        'enabled' => $enabled, 
        'account' => $account,
        'pass'    => $pass,
    );
    
    $profile = self::read($uid, $profile);
    
    if(isset($profile['id'])) {
      self::update($profile['id'], $fields);
    }
    else {
      self::create($fields);
    }
  }
  
  
  /**
   *  Creates a new Item
   * @param array $params
   * @return type 
   */

  static private function create($data) {
    $fields = array(
        'uid'     => isset($data['uid'])      ? $data['uid']                : 0,
        'profile' => isset($data['profile'])  ? $data['profile']            : '',
        'enabled' => isset($data['enabled'])  ? $data['enabled']            : 0,
        'account' => isset($data['account'])  ? $data['account']            : '',
        'pass'    => isset($data['pass'])     ? $data['pass']               : '',
    );
    $result = db_insert(self::$tablename)->fields($fields);
    $result->execute();
    return $result;
  }
  
  /**
   * @param $id The Id of the Dataset
   * @param $data Keyed Array of the profile Data
   * 
   * @return Success true/false
   */
  static private function update($id, $data) {
    
    $fields = array(
        'id'      => $id,
        'uid'     => isset($data['uid'])      ? $data['uid']                : 0,
        'profile' => isset($data['profile'])  ? $data['profile']            : '',
        'enabled' => isset($data['enabled'])  ? ($data['enabled'] ? 1 : 0)  : 0,
        'account' => isset($data['account'])  ? $data['account']            : '',
        'pass'    => isset($data['pass'])     ? $data['pass']               : '',
    );
    
    $query =  db_update(self::$tablename)    
                ->fields($fields)
                ->condition('id', $id, '=');    
    return $query->execute();
  }
  
  
  /**
   * Reads a single item via the uid, profilename combination
   * @param int $uid the User id
   * @param string $profile the Profile name
   * @return array the Result array
   */
  static function read($uid, $profile) {
    
    return db_select(self::$tablename, self::$tablealias)
                    ->fields(self::$tablealias)
                    ->condition('uid', $uid, '=')
                    ->condition('profile', $profile, '=')
                    ->execute()
                    ->fetchAssoc();
  }
  
  /**
   * Returns all accounts of the uid
   * @param $uid The User Id
   * @return Array of Accounts
   */
  static function get_accounts_via_uid($uid) {
    
    $query = db_select(self::$tablename, self::$tablealias)
                    ->fields(self::$tablealias)
                    ->condition('uid', $uid, '=')
                    ->execute();
    
     // Fetch all results into an array:
    $results = array();
    while($result = $query->fetchAssoc()) $results[] = $result;
    return $results;
  }
  
  /**
   * Returns all user accounts of a profile
   * @param $profile Profile machine name
   * @return Array of Accounts
   */
  static function get_accounts_via_profile($profile) {
    
    $query = db_select(self::$tablename, self::$tablealias)
                    ->fields(self::$tablealias)
                    ->condition('profile', $profile, '=')
                    ->execute();    
    
    // Fetch all results into an array:
    $results = array();
    while($result = $query->fetchAssoc()) $results[] = $result;
    return $results;
  }
}