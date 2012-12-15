<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * Provides functions mail sender an mail receiver authentification.
 */

namespace erpal_crm_mailaction\aggregating\database\models;

class ContactNodeModel {
  
  /*
   * Checks whether one of the contact participants exists in the database.
   * @param array			$emailAddress 	An email address.
   * @return boolean									TRUE on success.
   */
  public function isParticipantExisting ($emailAddress) {

    return ($this->loadContactIDOfMailAddress ($emailAddress) !== FALSE);
  }
  
  /*
   * Loads a contact node which has a specific mail address-.
   * @param 	string 	$email	The email address which you want to check.
   * @return 	mixed						The database ID of the contact on success. Otherwise FALSE.
   */

  public function loadContactIDOfMailAddress ($emailAddress) {
    
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
  
  /*
   * Creates a new unknown contact.
   * @param 	string   $senderMailAddress 	The IMAP 'to' object of the new unknown contact.
   * @return 	boolean					              TRUE on success.
   */
  public function createUnknownContact ($senderMailAddress) {
    
    $node = new \stdClass ();
    
    $node->type = 'erpal_contact';

    node_object_prepare($node);
    
    $node->field_contact_type[LANGUAGE_NONE][]['value']  = 'person';
    $node->field_email[LANGUAGE_NONE][]['value']         = $senderMailAddress;
    $node->field_lastname[LANGUAGE_NONE][]['value']      = t('New contact. Known from email conversation.');
    $node->title                                         = $node->field_lastname[LANGUAGE_NONE][0]['value'];
    $node->auto_nodetitle_applied                        = TRUE;
    
    node_save ($node);
    
    return isset ($node->nid);
  }
}
