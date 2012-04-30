<?php

/*
 * @author Sebastian Kauschke, Bright Solutions GmbH
 */

Class BsSyncMlProfile {

  private $pid = null;
  private $name = null;
  public $data = array();

  public function __construct($name=null, $data=null) {

    if ($name) {
      $this->name = $name;
    }
    if (isset($data)) {
      $this->data = $data;
    }
  }

  /*
   * Saves the object into the database
   */

  public function save() {

    if ($this->pid) {
      $res = $this->updateDb();      
    } elseif (!$this->pid) {
      $res = $this->insertIntoDb();      
    }
    else
      return false;
    
    return $res;
  }

  /*
   * Updates the object in the database
   */

  private function updateDb() {
    
    if(!$this->checkNameExists($this->name)) {
      db_update("bs_syncml_profiles")
            ->fields(array(
                'name' => $this->name,
                'data' => serialize($this->data),
            ))
            ->condition('pid', $this->pid)
            ->execute();
      return true;
    }
    return false;
  }

  /*
   * Inserts a new Line in the Database
   */

  private function insertIntoDb() {
    
     if(!$this->checkNameExists($this->name)) {
    $pid = db_insert("bs_syncml_profiles")
                    ->fields(array(
                        'name' => $this->name,
                        'data' => serialize($this->data),
                    ))->execute();
    $this->pid = $pid['pid'];
    return $this->pid;
     }
     return false;
  }
  
  private function checkNameExists($name) {
    $profiles = db_select('bs_syncml_profiles', 'p')
              ->fields('p')
              ->condition("name", $name, "=")            
              ->execute()
              ->fetchAssoc();
    if($profiles['pid']) return true;
    return false;
  }

  /*
   * Loads a profile from Database via the pid or machine name
   */

  public function load($profile) {

    $result = null;
    if ("" . intval($profile) == $profile) {
      $profiles = db_select('bs_syncml_profiles', 'p')
              ->fields('p')
              ->condition("pid", $profile, "=")
              ->execute()
              ->fetchAssoc();
      if (isset($profiles['pid']))
        $result = $profiles;
    }
    elseif (is_string($profile)) {
      $profiles = db_select('bs_syncml_profiles', 'p')
              ->fields('p')
              ->condition("name", $profile, "=")
              ->execute()
              ->fetchAssoc();
      if (is_array($profiles))
        $result = array_shift($profiles);
    }

    if ($result) {
      $this->pid = $result['pid'];
      $this->name = $result['name'];
      if (isset($result['data']))
        $this->data = unserialize($result['data']);
    }
  }

  public function getData() {
    return $this->data;
  }

  public function setData($data) {
    $this->data = $data;
  }

}

/*
 * Retrieve all Sync Profiles
 * 
 * @param $full: Load the complete profile object or just return machinename and id
 * @return Array of Sync Profiles 
 */

function bs_syncml_profile_getall($full=false) {

  $request = db_select('bs_syncml_profiles', 'p')
          ->fields('p')
          ->execute();
  
  while($prof = $request->fetchAssoc()) $profiles[] = $prof;

  return $profiles;
}