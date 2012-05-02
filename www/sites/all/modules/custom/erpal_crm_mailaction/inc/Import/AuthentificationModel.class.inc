<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * Provides functions mail sender an mail receiver authentification.
 */

namespace erpal_crm_mailaction;

class AuthentificationModel {
  
  /*
   * Checks whether one of the contact participants exists in the database.
   * @param array			$participants 	An array of mail-header values (from or to).
   * @return boolean									TRUE on success.
   */
  public function oneOftheParticipantsExists (array $participants) {
    
    $emailAddress = '';
    
    foreach ($participants as $participant) {
      $emailAddress = $participant->mailbox . '@' . $participant->host;
   
      if ($this->loadContactOfMailAddress ($emailAddress) !== FALSE) {
        return TRUE;
      }
    }
    
    return FALSE;
  }
  
  /*
   * Loads a contact node which has a specific mail address-.
   * @param 	string 	$email	The email address which you want to check.
   * @return 	boolean					TRUE on success.
   */

  public function loadContactOfMailAddress ($emailAddress) {
    
  	static $last_result = array ();
  	
  	if (isset ($last_result[$emailAddress])) {
  		return $last_result[$emailAddress];
  	}
  	
		$query = new \EntityFieldQuery;
		$query->entityCondition('entity_type', 'node')
		->entityCondition('bundle', 'erpal_contact')
		->fieldCondition('field_email', 'value', $emailAddress);
		 
		$records = $query->execute();
 
		if (empty ($records)) {
			return FALSE;
		}
    
		$last_result[$emailAddress] = array_shift ($records['node'])->nid;
		
		unset ($records);
		
    return $last_result[$emailAddress];
  }
  
  
}
