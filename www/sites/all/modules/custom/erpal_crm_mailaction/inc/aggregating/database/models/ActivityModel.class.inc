<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * Provides functions for loading, updating and inserting actitivy nodes.
 */

namespace erpal_crm_mailaction\aggregating\database;

class ActivityModel {
	
  private $published;
  
  /**
   * Ctor.
   */
  public function __construct () {
    
    $this->published = TRUE;
    
    return;
  }
  
  /**
   * Adds an activity, if not already exists.
   * 
   */
  //public function 
  
  /**
   * Checks whether an activity with a specific node ID exists.
   * 
   * @param 	integer	$nid		The database ID of a node.
   * @param		string	$title	The title of the node.
   * @return	boolean					TRUE on success.
   */
  public function isCustomerActivityAvailable ($nid, $title) {
 
    return db_query ('SELECT nid FROM {node} WHERE nid=:nid OR title=:title', array (
      ':nid'   => $nid,
      ':title' => $title
    ))->fetchObject() !== FALSE;
  }
  
  /**
   * Adds a new unpublished activity for the mail.
   * 
   * @param		object	$to				The mail participants-object of the receiver.
   * @param		object	$from			The mail participants-object of the sender.
   * @param		string	$subject	The subject of the mail.
   * @param		string	$body			The body of the mail.
   * @return  boolean           TRUE on success.
   */
  public function insertMail ($to, $from, $subject, $body, $attachments) {
    
    $contactModel     = new ContactNodeModel ();
    $fromContactID    = $contactModel->loadContactOfMailAddress ($from->mailbox . '@' . $from->host);
    $toContactID      = $contactModel->loadContactOfMailAddress ($to->mailbox . '@' . $to->host);
    
    unset ($contactModel);
    
    $mailEntityWrapperObject = new entity_wrappers\MailEntityWrapper (
      $fromContactID, 
      $toContactID, 
      $subject, 
      $body
    );
    
    $mailEntityWrapperObject->status          = $this->published;
    $mailEntityWrapperObject->has_body        = TRUE;
    $mailEntityWrapperObject->language        = LANGUAGE_NONE;

    if (! empty ($attachments)) {
      
      foreach ($attachments as $attachment) {
        $this->addFile ($node->nid, $attachment, $subject);
      }
    }

    if (! $mailEntityWrapperObject->save ()) {
      
      return FALSE;
    }
    
    $activityWrapperObject->createEntityReferenceFieldValue (
      $fieldName, 
      $id,
      $mode = self::CREATE_VALUE
    );
    
    return;
  }
  
  /**
   * Set the published status of a new entry.
   * 
   * @param boolean $status	TRUE if the new entry has to be published. Otherwise FALSE.
   */
  public function published ($status) {
    
    $this->published = $status;
    
    return;
  } 
  
  /**
   * Creates a single file node and creates a reference from a specific node to the new file node.
   * 
   * @param		MailEntityWrapper $parentObject	       The ActivityEntityWrapper parent object.
   * @param		object		        $fileObject          The drupal file object.
   * @param		string		        $sourceDescription   The source description.
   * @return	boolean	                               TRUE on success.
   */
  private function addFile ($parentObject, $fileObject, $sourceDescription) {
    
    $fileEntityWrapperObject = new entity_wrappers\FileEntityWrapper ($fileObject, $sourceDescription);
    if (! $fileEntityWrapperObject->save ()) {
      return FALSE;
    }
    
    $parentObject->addAttachment ($fileEntityWrapperObject);
    
    return TRUE;
  }
}
