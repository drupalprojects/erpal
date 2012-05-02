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
      'is_anonymous' => TRUE,
      'homepage' => '',
      'status' => COMMENT_PUBLISHED,
      'subject' => $subject,
      'language' => LANGUAGE_NONE,
      'comment_body' => array(
        LANGUAGE_NONE => array(
            0 => array (
                'value' => theme ('erpal_crm_mailaction_comment', array (
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
   * Adds a new activity for the mail.
   * @param		object	$to				The mail participants-object of the receiver.
   * @param		object	$from			The mail participants-object of the sender.
   * @param		string	$subject	The subject of the mail.
   * @param		string	$body			The body of the mail.
   */
  public function insertCustomerActivity ($to, $from, $subject, $body) {
    
    module_load_include ('inc', 'erpal_crm_mailaction', 'includes/AuthentificationModel.class');
    $auth = new AuthentificationModel ();
    $contact = $auth->loadContactOfMailAddress ($from->mailbox . '@' . $from->host);
 
    if ($contact === FALSE) {
      return FALSE;
    }
        
    $node           = new \stdClass ();
    $node->type     = ERPAL_CRM_MAILACTION_DESTIONATION_CONTENT_TYPE;

    node_object_prepare($node);
    
    $node->status                             = TRUE;
    $node->has_body                           = TRUE;
    $node->body[LANGUAGE_NONE][]['value']     = $body;
    $node->title                              = $subject;
 
    $node->field_activity_status[LANGUAGE_NONE][]['value']   = 1; // REQUEST
    $node->field_contact_ref[LANGUAGE_NONE][]['nid']         = $contact;
    
    
    node_save ($node);
    
    return TRUE;
  }
} 