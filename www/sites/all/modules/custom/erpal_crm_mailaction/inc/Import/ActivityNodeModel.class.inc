<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * Provides functions for loading, updating and inserting actitivy nodes.
 */

namespace erpal_crm_mailaction;

class ActivityNodeModel {
	
  private $published;
  
  /*
   * Ctor.
   */
  public function __construct () {
    
    $this->published = TRUE;
    
    return;
  }
  
  /*
   * Checks whether an activity with a specific node ID exists.
   * @param 	integer	$nid		The database ID of a node.
   * @return	boolean					TRUE on success.
   */
  public function isCustomerActivityAvailable ($nid) {
 
    return db_query ('SELECT nid FROM {node} WHERE nid=:nid', array (
      ':nid' => $nid
    ))->fetchObject() !== FALSE;
  }
  
  /*
   * Adds a new comment to an existing activity.
   * @param 	integer	$nid			The database ID of a node.
   * @param		object	$to				The mail participants-object of the receiver.
   * @param		object	$from			The mail participants-object of the sender.
   * @param		string	$subject	The subject of the mail.
   * @param		string	$body			The body of the mail.
   */
  public function addToCustomerActivity ($nid, $to, $from, $subject, $body) {
    
    drupal_load ('module', 'comment');
    
    $comment = (object) array(
      'nid' => $nid,
      'cid' => 0,
      'pid' => 0,
      'uid' => 1,
      'mail' => $from->mailbox . '@' . $from->host,
      'is_anonymous' => FALSE,
      'homepage' => '',
      'status' => $this->published,
      'subject' => $subject,
      'language' => LANGUAGE_NONE,
      'comment_body' => array(
        LANGUAGE_NONE => array(
            0 => array (
                'value' => theme ('erpal_crm_mailaction_comment', array (
                  'from'	=> $from->mailbox . '@' . $from->host,
                	'to'    => $to->mailbox . '@' . $to->host,
                  'body'	=> $body
              )
            ),
            'format' => 'filtered_html'
          )
        )
      ),
    );
  
    comment_submit($comment);
    comment_save($comment);
    
    return;
  }
  
  /* 
   * Adds a new unpublished activity for the mail.
   * @param		object	$to				The mail participants-object of the receiver.
   * @param		object	$from			The mail participants-object of the sender.
   * @param		string	$subject	The subject of the mail.
   * @param		string	$body			The body of the mail.
   */
  public function insertCustomerActivity ($to, $from, $subject, $body) {
    
    module_load_include ('inc', 'erpal_crm_mailaction', 'includes/ContactModel.class');
    
    $auth     = new ContactModel ();
    $contact  = $auth->loadContactOfMailAddress ($from->mailbox . '@' . $from->host);
        
    $node           = new \stdClass ();
    $node->type     = 'erpal_crm_activity';

    node_object_prepare($node);
    
    $node->status                             = $this->published;
    $node->has_body                           = TRUE;
    $node->body[LANGUAGE_NONE][0]['value']    = $body;
    $node->body[LANGUAGE_NONE][0]['format']   = 'filtered_html';
    $node->title                              = check_plain ($subject);
 
    $node->field_activity_status[LANGUAGE_NONE][]['value'] = 1; // REQUEST
    
    if ($contact !== FALSE) {
      $node->field_contact_ref[LANGUAGE_NONE][]['nid'] = $contact;
    }
    
    node_save ($node);
    
    return TRUE;
  }
  
  /*
   * Set the published status of a new entry.
   * @param boolean $status	TRUE if the new entry has to be published. Otherwise FALSE.
   */
  public function published ($status) {
    
    $this->published = $status;
    
    return;
  } 
}
