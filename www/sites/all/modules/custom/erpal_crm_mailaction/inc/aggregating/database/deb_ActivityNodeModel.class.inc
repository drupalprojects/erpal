<?php
/*
 * @author 		Marc Sven Kleinboehl
 * @created 	01/14/2012
 * @copyright	2012 © Bright Solutions GmbH 
 * 
 * Provides functions for loading, updating and inserting actitivy nodes.
 */

namespace erpal_crm_mailaction\aggregating;

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
   * @param		string	$title	The title of the node.
   * @return	boolean					TRUE on success.
   */
  public function isCustomerActivityAvailable ($nid, $title) {
 
    return db_query ('SELECT nid FROM {node} WHERE nid=:nid OR title=:title', array (
      ':nid'   => $nid,
      ':title' => $title
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
  public function addToCustomerActivity ($nid, $to, $from, $subject, $body, $attachments) {

    $contactModel = new ContactNodeModel ();
    $contactID    = $contactModel->loadContactOfMailAddress ($from->mailbox . '@' . $from->host);
    
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
      'field_contacts_ref' => array (
        LANGUAGE_NONE => array (
          0 => array (
            'target_id' => $contactID
          )
        )
      )
    ); 

    comment_submit($comment);
    comment_save($comment);
 
    if (! empty ($attachments)) {
      
      foreach ($attachments as $attachment) {
        $this->addFile ($comment->cid, $attachment, $subject, TRUE);
      }
    }
    
    
    return;
  }
  
  /* 
   * Adds a new unpublished activity for the mail.
   * @param		object	$to				The mail participants-object of the receiver.
   * @param		object	$from			The mail participants-object of the sender.
   * @param		string	$subject	The subject of the mail.
   * @param		string	$body			The body of the mail.
   */
  public function insertCustomerActivity ($to, $from, $subject, $body, $attachments) {
    
    module_load_include ('inc', 'erpal_crm_mailaction', 'includes/ContactNodeModel.class');
    
    $contactModel = new ContactNodeModel ();
    $contactID    = $contactModel->loadContactOfMailAddress ($from->mailbox . '@' . $from->host);
        
    $node           = new \stdClass ();
    $node->type     = 'erpal_crm_activity';

    node_object_prepare($node);
    
    $node->status                             = $this->published;
    $node->has_body                           = TRUE;
    $node->body[LANGUAGE_NONE][0]['value']    = $body;
    $node->body[LANGUAGE_NONE][0]['format']   = 'filtered_html';
    $node->title                              = check_plain ($subject);
    $node->language                           = LANGUAGE_NONE;
 
    //$node->field_activity_status[LANGUAGE_NONE][]['value'] = 1; // REQUEST
    //Update, da dieses Feld nun ein Term reference feld ist und es an den Terms ein Flag gibt, welcher Term der default Term ist.
    $field_info = field_info_field('field_activity_status_term');
    $vocabulary_name = $field_info['settings']['allowed_values'][0]['vocabulary'];
    $taxonomy = taxonomy_vocabulary_machine_name_load($vocabulary_name);
    $vid = $taxonomy->vid;
    $node->field_is_default_term[LANGUAGE_NONE][0]['value'] = _erpal_basic_helper_get_default_tid($vid);   
    
    if ($contact !== FALSE) {
      $node->field_contact_ref[LANGUAGE_NONE][]['target_id'] = $contactID;
    }
    
    node_save ($node);

    if (! empty ($attachments)) {
      
      foreach ($attachments as $attachment) {
        $this->addFile ($node->nid, $attachment, $subject);
      }
    }
    
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
  
  /*
   * Creates a single file node and creates a reference from a specific node to the new file node.
   * @param		integer		The database ID of the parent node.
   * @param		object		The file object.
   * @param		string		The source description.
   * @return	boolean		TRUE on success.
   */
  private function addFile ($parentID, $file, $sourceDescription, $parentIsComment = FALSE) {
    
    if (! $parentIsComment) {
      $parentObject = node_load ($parentID);
    }else{
      $parentObject = comment_load ($parentID);
    }
  
    if ($parentObject === FALSE) {
      return FALSE;
    }
    
    $node           = new \stdClass ();
    $node->type     = 'erpal_file';
    
    node_object_prepare($node);
    
    $node->status                             = (int)_erpal_crm_mailaction_get_settings (
                                                ERPAL_CRM_MAILACTION_CONFIG_GROUP_IMPORT_SETTINGS, 
                                                'publish_attachments', 
                                                FALSE);
    $node->has_body                           = TRUE;
    $node->title                              = check_plain ($file->filename);
    $node->language                           = LANGUAGE_NONE;
    $node->body[LANGUAGE_NONE][0]['value']    = check_plain ($sourceDescription);
    $node->body[LANGUAGE_NONE][0]['format']   = 'filtered_html';
    
    $node->field_docs_file[LANGUAGE_NONE][]   = array(
      'fid'				  => $file->fid,
      'display'     => 1,
      'description'	=> $sourceDescription
    );
    
    node_save ($node);
    
    if (! isset ($node->nid)) {
      return FALSE;
    }
    
    if (! $parentIsComment) {
    
    	$parentObject->field_asset_files[LANGUAGE_NONE][]['nid'] = array(
        'target_id' => $node->nid,
        'target_type' => 'node',
      );
    
      node_save ($parentObject);
    }else{ 
    
    	$parentObject->field_asset_files[LANGUAGE_NONE][]['nid'] = array(
        'target_id'   => $node->nid,
        'target_type' => 'node',
      );
      
      comment_save($parentObject);
    }

    
    return TRUE;
  }
}
