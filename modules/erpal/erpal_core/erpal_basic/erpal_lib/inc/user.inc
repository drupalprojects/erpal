<?php

/**
* @file contains helper functions dealing with users
*/

/**
* Helper function to get the base data of a uid ore many uids
* @param $uids a single uid or an array with uids
*/
function erpal_lib_helper_user_base_data($uids) {
  if (is_numeric($uids))
    $uids = array($uids);
  
  if (!count($uids))
    return array();  //no result if no node is given
  
  $query = db_select('users', 'u');
  $query
    ->fields('u')
    ->condition('u.uid', $uids);

  $result = $query->execute();
  
  $users = array();
  foreach ($result as $record) {
    $users[$record->uid] = $record;
  }  
  
  return $users;
}
